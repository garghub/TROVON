static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_1 -> V_4 . V_5 ) ;
F_3 ( & V_3 -> V_6 , & V_1 -> V_4 . V_7 ) ;
F_4 ( & V_1 -> V_4 . V_5 ) ;
}
static void F_5 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_1 -> V_4 . V_5 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_4 ( & V_1 -> V_4 . V_5 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
int V_8 , V_9 ;
do {
V_9 = F_8 ( & V_1 -> V_4 . V_10 ) ;
V_8 = V_9 < V_11 ? V_9 + 1 : 1 ;
} while ( F_9 ( & V_1 -> V_4 . V_10 ,
V_9 , V_8 ) != V_9 );
return V_8 ;
}
static T_1 F_10 ( const void * V_12 , int V_13 )
{
const T_1 * V_14 = V_12 ;
return ( V_15 T_1 ) ( 1 << ( ( ~ V_13 ^ V_16 ) & 0x1f ) ) &
V_14 [ V_13 >> 5 ] ;
}
static struct V_17 * F_11 ( void )
{
struct V_17 * V_18 ;
V_18 = F_12 ( V_19 , V_20 ) ;
return V_18 ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_14 ( V_19 , V_18 ) ;
}
static void F_15 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_16 ( V_22 , struct V_17 , V_23 ) ;
F_14 ( V_19 , V_18 ) ;
}
static void F_17 ( struct V_17 * V_18 )
{
F_18 ( & V_18 -> V_23 , F_15 ) ;
}
void F_19 ( struct V_24 * V_25 )
{
int V_26 ;
if ( ! V_25 -> V_27 )
return;
F_20 (cpu) {
struct V_24 * * V_28 ;
struct V_24 * V_29 ;
V_28 = F_21 ( V_25 -> V_27 , V_26 ) ;
V_29 = * V_28 ;
if ( V_29 ) {
F_22 ( & V_29 -> V_30 ) ;
F_23 ( & V_29 -> V_30 ) ;
* V_28 = NULL ;
}
}
F_24 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
}
static void F_25 ( struct V_31 * V_32 )
{
F_26 ( & V_32 -> V_33 ) ;
F_27 ( V_32 ) ;
}
static void F_28 ( struct V_1 * V_1 , struct V_31 * V_34 )
{
unsigned int V_35 ;
F_29 ( & V_34 -> V_36 ) ;
V_35 = V_34 -> V_37 & ( V_38 - 1 ) ;
F_30 ( & V_34 -> V_39 , & V_1 -> V_4 . V_40 [ V_35 ] ) ;
}
static struct V_31 * F_31 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_31 * V_32 ;
V_32 = F_32 ( sizeof( * V_32 ) , V_20 ) ;
if ( V_32 ) {
V_32 -> V_37 = V_41 ;
V_32 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_32 -> V_42 . V_45 = V_46 | V_47 | V_48 ;
F_33 ( & V_32 -> V_33 ) ;
}
return V_32 ;
}
struct V_31 * F_34 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_31 * V_34 ;
if ( V_41 == 0 )
V_41 = V_49 ;
V_34 = F_35 ( V_1 , V_41 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_31 ( V_1 , V_41 ) ;
if ( V_34 )
F_28 ( V_1 , V_34 ) ;
return V_34 ;
}
struct V_31 * F_35 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_31 * V_34 ;
struct V_50 * V_22 ;
unsigned int V_35 ;
if ( V_41 == 0 )
V_41 = V_49 ;
V_35 = V_41 & ( V_38 - 1 ) ;
F_36 () ;
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_37 (tb, head, tb6_hlist) {
if ( V_34 -> V_37 == V_41 ) {
F_38 () ;
return V_34 ;
}
}
F_38 () ;
return NULL ;
}
static void T_3 F_39 ( struct V_1 * V_1 )
{
F_28 ( V_1 , V_1 -> V_4 . V_51 ) ;
F_28 ( V_1 , V_1 -> V_4 . V_52 ) ;
}
struct V_31 * F_34 ( struct V_1 * V_1 , T_2 V_41 )
{
return F_35 ( V_1 , V_41 ) ;
}
struct V_31 * F_35 ( struct V_1 * V_1 , T_2 V_41 )
{
return V_1 -> V_4 . V_51 ;
}
struct V_53 * F_40 ( struct V_1 * V_1 , struct V_54 * V_55 ,
int V_56 , T_4 V_57 )
{
struct V_24 * V_58 ;
V_58 = V_57 ( V_1 , V_1 -> V_4 . V_51 , V_55 , V_56 ) ;
if ( V_58 -> V_30 . error == - V_59 ) {
F_41 ( V_58 ) ;
V_58 = V_1 -> V_4 . V_44 ;
F_42 ( & V_58 -> V_30 ) ;
}
return & V_58 -> V_30 ;
}
static void T_3 F_39 ( struct V_1 * V_1 )
{
F_28 ( V_1 , V_1 -> V_4 . V_51 ) ;
}
unsigned int F_43 ( struct V_1 * V_1 )
{
unsigned int V_35 , V_60 = 0 ;
F_36 () ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
struct V_50 * V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
struct V_31 * V_34 ;
F_37 (tb, head, tb6_hlist) {
F_44 ( & V_34 -> V_36 ) ;
V_60 += V_34 -> V_60 ;
F_45 ( & V_34 -> V_36 ) ;
}
}
F_38 () ;
return V_60 ;
}
static int F_46 ( struct V_61 * V_62 , struct V_1 * V_1 ,
enum V_63 V_64 ,
struct V_24 * V_58 )
{
struct V_65 V_66 = {
. V_58 = V_58 ,
} ;
return F_47 ( V_62 , V_1 , V_64 , & V_66 . V_66 ) ;
}
static int F_48 ( struct V_1 * V_1 ,
enum V_63 V_64 ,
struct V_24 * V_58 )
{
struct V_65 V_66 = {
. V_58 = V_58 ,
} ;
V_58 -> V_67 -> V_60 ++ ;
return F_49 ( V_1 , V_64 , & V_66 . V_66 ) ;
}
static void F_50 ( struct V_24 * V_58 , struct V_68 * V_69 )
{
if ( V_58 == V_69 -> V_1 -> V_4 . V_44 )
return;
F_46 ( V_69 -> V_62 , V_69 -> V_1 , V_70 , V_58 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_24 * V_58 ;
for ( V_58 = V_3 -> V_43 ; V_58 ; V_58 = V_58 -> V_30 . V_71 )
F_50 ( V_58 , V_3 -> args ) ;
V_3 -> V_43 = NULL ;
return 0 ;
}
static void F_52 ( struct V_1 * V_1 , struct V_31 * V_34 ,
struct V_2 * V_3 )
{
V_3 -> V_72 = & V_34 -> V_42 ;
F_44 ( & V_34 -> V_36 ) ;
F_53 ( V_1 , V_3 ) ;
F_45 ( & V_34 -> V_36 ) ;
}
int F_54 ( struct V_1 * V_1 , struct V_61 * V_62 )
{
struct V_68 V_69 ;
struct V_2 * V_3 ;
unsigned int V_35 ;
V_3 = F_32 ( sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_73 ;
V_3 -> V_74 = F_51 ;
V_69 . V_1 = V_1 ;
V_69 . V_62 = V_62 ;
V_3 -> args = & V_69 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
struct V_50 * V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
struct V_31 * V_34 ;
F_37 (tb, head, tb6_hlist)
F_52 ( V_1 , V_34 , V_3 ) ;
}
F_27 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_24 * V_58 ;
for ( V_58 = V_3 -> V_43 ; V_58 ; V_58 = V_58 -> V_30 . V_71 ) {
V_75 = F_56 ( V_58 , V_3 -> args ) ;
if ( V_75 < 0 ) {
V_3 -> V_43 = V_58 ;
return 1 ;
}
if ( V_58 -> V_76 )
V_58 = F_57 ( & V_58 -> V_77 ,
struct V_24 ,
V_77 ) ;
}
V_3 -> V_43 = NULL ;
return 0 ;
}
static void F_58 ( struct V_78 * V_79 )
{
struct V_1 * V_1 = F_59 ( V_79 -> V_80 -> V_81 ) ;
struct V_2 * V_3 = ( void * ) V_79 -> args [ 2 ] ;
if ( V_3 ) {
if ( V_79 -> args [ 4 ] ) {
V_79 -> args [ 4 ] = 0 ;
F_5 ( V_1 , V_3 ) ;
}
V_79 -> args [ 2 ] = 0 ;
F_27 ( V_3 ) ;
}
V_79 -> V_82 = ( void * ) V_79 -> args [ 3 ] ;
V_79 -> args [ 1 ] = 3 ;
}
static int F_60 ( struct V_78 * V_79 )
{
F_58 ( V_79 ) ;
return V_79 -> V_82 ? V_79 -> V_82 ( V_79 ) : 0 ;
}
static int F_61 ( struct V_31 * V_32 , struct V_83 * V_80 ,
struct V_78 * V_79 )
{
struct V_1 * V_1 = F_59 ( V_80 -> V_81 ) ;
struct V_2 * V_3 ;
int V_75 ;
V_3 = ( void * ) V_79 -> args [ 2 ] ;
V_3 -> V_72 = & V_32 -> V_42 ;
if ( V_79 -> args [ 4 ] == 0 ) {
V_3 -> V_84 = 0 ;
V_3 -> V_85 = 0 ;
F_44 ( & V_32 -> V_36 ) ;
V_75 = F_53 ( V_1 , V_3 ) ;
F_45 ( & V_32 -> V_36 ) ;
if ( V_75 > 0 ) {
V_79 -> args [ 4 ] = 1 ;
V_79 -> args [ 5 ] = V_3 -> V_72 -> V_86 ;
}
} else {
if ( V_79 -> args [ 5 ] != V_3 -> V_72 -> V_86 ) {
V_79 -> args [ 5 ] = V_3 -> V_72 -> V_86 ;
V_3 -> V_87 = V_88 ;
V_3 -> V_89 = V_3 -> V_72 ;
V_3 -> V_85 = V_3 -> V_84 ;
} else
V_3 -> V_85 = 0 ;
F_44 ( & V_32 -> V_36 ) ;
V_75 = F_62 ( V_3 ) ;
F_45 ( & V_32 -> V_36 ) ;
if ( V_75 <= 0 ) {
F_5 ( V_1 , V_3 ) ;
V_79 -> args [ 4 ] = 0 ;
}
}
return V_75 ;
}
static int F_63 ( struct V_83 * V_80 , struct V_78 * V_79 )
{
struct V_1 * V_1 = F_59 ( V_80 -> V_81 ) ;
unsigned int V_35 , V_90 ;
unsigned int V_91 = 0 , V_92 ;
struct V_93 V_69 ;
struct V_2 * V_3 ;
struct V_31 * V_34 ;
struct V_50 * V_22 ;
int V_75 = 0 ;
V_90 = V_79 -> args [ 0 ] ;
V_92 = V_79 -> args [ 1 ] ;
V_3 = ( void * ) V_79 -> args [ 2 ] ;
if ( ! V_3 ) {
V_79 -> args [ 3 ] = ( long ) V_79 -> V_82 ;
V_79 -> V_82 = F_60 ;
V_3 = F_32 ( sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_73 ;
V_3 -> V_74 = F_55 ;
V_79 -> args [ 2 ] = ( long ) V_3 ;
}
V_69 . V_80 = V_80 ;
V_69 . V_79 = V_79 ;
V_69 . V_1 = V_1 ;
V_3 -> args = & V_69 ;
F_36 () ;
for ( V_35 = V_90 ; V_35 < V_38 ; V_35 ++ , V_92 = 0 ) {
V_91 = 0 ;
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_37 (tb, head, tb6_hlist) {
if ( V_91 < V_92 )
goto V_94;
V_75 = F_61 ( V_34 , V_80 , V_79 ) ;
if ( V_75 != 0 )
goto V_95;
V_94:
V_91 ++ ;
}
}
V_95:
F_38 () ;
V_79 -> args [ 1 ] = V_91 ;
V_79 -> args [ 0 ] = V_35 ;
V_75 = V_75 < 0 ? V_75 : V_80 -> V_96 ;
if ( V_75 <= 0 )
F_58 ( V_79 ) ;
return V_75 ;
}
static struct V_17 * F_64 ( struct V_17 * V_72 ,
struct V_97 * V_14 , int V_98 ,
int V_99 , int V_100 ,
int V_101 , int V_102 ,
struct V_103 * V_104 )
{
struct V_17 * V_18 , * V_105 , * V_106 ;
struct V_17 * V_107 = NULL ;
struct V_108 * V_109 ;
int V_110 ;
T_1 V_111 = 0 ;
F_65 ( L_1 ) ;
V_18 = V_72 ;
do {
V_109 = (struct V_108 * ) ( ( V_112 * ) V_18 -> V_43 + V_99 ) ;
if ( V_98 < V_18 -> V_13 ||
! F_66 ( & V_109 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_100 ) {
if ( V_101 ) {
F_67 ( V_104 ,
L_2 ) ;
F_68 ( L_3 ) ;
return F_69 ( - V_113 ) ;
}
F_68 ( L_4 ) ;
}
goto V_114;
}
if ( V_98 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_45 & V_48 ) ) {
F_70 ( V_18 -> V_43 ) ;
V_18 -> V_43 = NULL ;
}
V_18 -> V_86 = V_102 ;
return V_18 ;
}
V_18 -> V_86 = V_102 ;
V_111 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_107 = V_18 ;
V_18 = V_111 ? V_18 -> V_115 : V_18 -> V_116 ;
} while ( V_18 );
if ( ! V_100 ) {
if ( V_101 ) {
F_67 ( V_104 ,
L_2 ) ;
F_68 ( L_3 ) ;
return F_69 ( - V_113 ) ;
}
F_68 ( L_4 ) ;
}
V_106 = F_11 () ;
if ( ! V_106 )
return F_69 ( - V_73 ) ;
V_106 -> V_13 = V_98 ;
V_106 -> V_117 = V_107 ;
V_106 -> V_86 = V_102 ;
if ( V_111 )
V_107 -> V_115 = V_106 ;
else
V_107 -> V_116 = V_106 ;
return V_106 ;
V_114:
V_107 = V_18 -> V_117 ;
V_110 = F_71 ( V_14 , & V_109 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_98 > V_110 ) {
V_105 = F_11 () ;
V_106 = F_11 () ;
if ( ! V_105 || ! V_106 ) {
if ( V_105 )
F_13 ( V_105 ) ;
if ( V_106 )
F_13 ( V_106 ) ;
return F_69 ( - V_73 ) ;
}
V_105 -> V_13 = V_110 ;
V_105 -> V_117 = V_107 ;
V_105 -> V_43 = V_18 -> V_43 ;
F_72 ( & V_105 -> V_43 -> V_118 ) ;
V_105 -> V_86 = V_102 ;
if ( V_111 )
V_107 -> V_115 = V_105 ;
else
V_107 -> V_116 = V_105 ;
V_106 -> V_13 = V_98 ;
V_106 -> V_117 = V_105 ;
V_18 -> V_117 = V_105 ;
V_106 -> V_86 = V_102 ;
if ( F_10 ( V_14 , V_110 ) ) {
V_105 -> V_115 = V_106 ;
V_105 -> V_116 = V_18 ;
} else {
V_105 -> V_116 = V_106 ;
V_105 -> V_115 = V_18 ;
}
} else {
V_106 = F_11 () ;
if ( ! V_106 )
return F_69 ( - V_73 ) ;
V_106 -> V_13 = V_98 ;
V_106 -> V_117 = V_107 ;
V_106 -> V_86 = V_102 ;
if ( V_111 )
V_107 -> V_115 = V_106 ;
else
V_107 -> V_116 = V_106 ;
if ( F_10 ( & V_109 -> V_14 , V_98 ) )
V_106 -> V_115 = V_18 ;
else
V_106 -> V_116 = V_18 ;
V_18 -> V_117 = V_106 ;
}
return V_106 ;
}
static bool F_73 ( struct V_24 * V_58 )
{
return ( V_58 -> V_119 & ( V_120 | V_121 | V_122 ) ) ==
V_120 ;
}
static void F_74 ( T_2 * V_123 , const struct V_124 * V_125 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
if ( F_75 ( V_126 , V_125 -> V_128 ) )
V_123 [ V_126 ] = V_125 -> V_129 [ V_126 ] ;
}
}
static int F_76 ( struct V_53 * V_30 , struct V_124 * V_125 )
{
if ( ! V_125 -> V_129 )
return 0 ;
if ( V_30 -> V_56 & V_130 ) {
T_2 * V_123 = F_77 ( V_30 ) ;
if ( F_78 ( ! V_123 ) )
return - V_73 ;
F_74 ( V_123 , V_125 ) ;
} else {
F_79 ( V_30 , V_125 -> V_129 , false ) ;
V_125 -> V_129 = NULL ;
}
return 0 ;
}
static void F_80 ( struct V_24 * V_58 , struct V_17 * V_18 ,
struct V_1 * V_1 )
{
if ( F_8 ( & V_58 -> V_118 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_45 & V_48 ) && V_18 -> V_43 == V_58 ) {
V_18 -> V_43 = F_81 ( V_1 , V_18 ) ;
F_72 ( & V_18 -> V_43 -> V_118 ) ;
F_70 ( V_58 ) ;
}
V_18 = V_18 -> V_117 ;
}
}
}
static int F_82 ( struct V_17 * V_18 , struct V_24 * V_58 ,
struct V_131 * V_66 , struct V_124 * V_125 )
{
struct V_24 * V_132 = NULL ;
struct V_24 * * V_133 ;
struct V_24 * * V_134 = NULL ;
int V_135 = ( V_66 -> V_136 &&
( V_66 -> V_136 -> V_137 & V_138 ) ) ;
int V_139 = ( ! V_66 -> V_136 ||
( V_66 -> V_136 -> V_137 & V_140 ) ) ;
int V_141 = 0 ;
bool V_142 = F_73 ( V_58 ) ;
T_5 V_143 = V_144 ;
int V_145 ;
if ( V_66 -> V_136 && ( V_66 -> V_136 -> V_137 & V_146 ) )
V_143 |= V_146 ;
V_133 = & V_18 -> V_43 ;
for ( V_132 = V_18 -> V_43 ; V_132 ; V_132 = V_132 -> V_30 . V_71 ) {
if ( V_132 -> V_147 == V_58 -> V_147 ) {
if ( V_66 -> V_136 &&
( V_66 -> V_136 -> V_137 & V_144 ) )
return - V_148 ;
V_143 &= ~ V_144 ;
if ( V_135 ) {
if ( V_142 == F_73 ( V_132 ) ) {
V_141 ++ ;
break;
}
if ( V_142 )
V_134 = V_134 ? : V_133 ;
goto V_149;
}
if ( F_83 ( V_132 , V_58 ) ) {
if ( V_58 -> V_76 )
V_58 -> V_76 = 0 ;
if ( ! ( V_132 -> V_119 & V_150 ) )
return - V_148 ;
if ( ! ( V_58 -> V_119 & V_150 ) )
F_84 ( V_132 ) ;
else
F_85 ( V_132 , V_58 -> V_30 . V_151 ) ;
V_132 -> V_152 = V_58 -> V_152 ;
return - V_148 ;
}
if ( V_142 &&
F_73 ( V_132 ) )
V_58 -> V_76 ++ ;
}
if ( V_132 -> V_147 > V_58 -> V_147 )
break;
V_149:
V_133 = & V_132 -> V_30 . V_71 ;
}
if ( V_134 && ! V_141 ) {
V_133 = V_134 ;
V_132 = * V_133 ;
V_141 ++ ;
}
if ( V_133 == & V_18 -> V_43 )
V_18 -> V_153 = NULL ;
if ( V_58 -> V_76 ) {
unsigned int V_76 ;
struct V_24 * V_154 , * V_155 ;
V_154 = V_18 -> V_43 ;
while ( V_154 ) {
if ( V_154 -> V_147 == V_58 -> V_147 &&
F_73 ( V_154 ) ) {
F_86 ( & V_58 -> V_77 ,
& V_154 -> V_77 ) ;
break;
}
V_154 = V_154 -> V_30 . V_71 ;
}
V_76 = 0 ;
F_87 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_154 -> V_76 ++ ;
F_88 ( V_154 -> V_76 != V_58 -> V_76 ) ;
V_76 ++ ;
}
F_88 ( V_76 != V_58 -> V_76 ) ;
}
if ( ! V_135 ) {
if ( ! V_139 )
F_68 ( L_4 ) ;
V_139:
V_143 |= V_140 ;
V_145 = F_76 ( & V_58 -> V_30 , V_125 ) ;
if ( V_145 )
return V_145 ;
V_58 -> V_30 . V_71 = V_132 ;
* V_133 = V_58 ;
F_89 ( V_58 -> V_156 , V_18 ) ;
F_72 ( & V_58 -> V_118 ) ;
F_48 ( V_66 -> V_157 , V_70 ,
V_58 ) ;
if ( ! V_66 -> V_158 )
F_90 ( V_159 , V_58 , V_66 , V_143 ) ;
V_66 -> V_157 -> V_4 . V_160 -> V_161 ++ ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_66 -> V_157 -> V_4 . V_160 -> V_162 ++ ;
V_18 -> V_45 |= V_48 ;
}
} else {
int V_163 ;
if ( ! V_141 ) {
if ( V_139 )
goto V_139;
F_68 ( L_5 ) ;
return - V_113 ;
}
V_145 = F_76 ( & V_58 -> V_30 , V_125 ) ;
if ( V_145 )
return V_145 ;
* V_133 = V_58 ;
F_89 ( V_58 -> V_156 , V_18 ) ;
V_58 -> V_30 . V_71 = V_132 -> V_30 . V_71 ;
F_72 ( & V_58 -> V_118 ) ;
F_48 ( V_66 -> V_157 , V_164 ,
V_58 ) ;
if ( ! V_66 -> V_158 )
F_90 ( V_159 , V_58 , V_66 , V_138 ) ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_66 -> V_157 -> V_4 . V_160 -> V_162 ++ ;
V_18 -> V_45 |= V_48 ;
}
V_163 = V_132 -> V_76 ;
V_132 -> V_156 = NULL ;
F_80 ( V_132 , V_18 , V_66 -> V_157 ) ;
if ( V_18 -> V_153 == V_132 )
V_18 -> V_153 = NULL ;
F_70 ( V_132 ) ;
if ( V_163 ) {
V_133 = & V_58 -> V_30 . V_71 ;
V_132 = * V_133 ;
while ( V_132 ) {
if ( V_132 -> V_147 > V_58 -> V_147 )
break;
if ( F_73 ( V_132 ) ) {
* V_133 = V_132 -> V_30 . V_71 ;
V_132 -> V_156 = NULL ;
F_80 ( V_132 , V_18 , V_66 -> V_157 ) ;
if ( V_18 -> V_153 == V_132 )
V_18 -> V_153 = NULL ;
F_70 ( V_132 ) ;
V_163 -- ;
} else {
V_133 = & V_132 -> V_30 . V_71 ;
}
V_132 = * V_133 ;
}
F_91 ( V_163 != 0 ) ;
}
}
return 0 ;
}
static void F_92 ( struct V_1 * V_1 , struct V_24 * V_58 )
{
if ( ! F_93 ( & V_1 -> V_4 . V_165 ) &&
( V_58 -> V_119 & ( V_150 | V_166 ) ) )
F_94 ( & V_1 -> V_4 . V_165 ,
V_167 + V_1 -> V_4 . V_168 . V_169 ) ;
}
void F_95 ( struct V_1 * V_1 )
{
if ( ! F_93 ( & V_1 -> V_4 . V_165 ) )
F_94 ( & V_1 -> V_4 . V_165 ,
V_167 + V_1 -> V_4 . V_168 . V_169 ) ;
}
int F_96 ( struct V_17 * V_72 , struct V_24 * V_58 ,
struct V_131 * V_66 , struct V_124 * V_125 ,
struct V_103 * V_104 )
{
struct V_17 * V_18 , * V_107 = NULL ;
int V_145 = - V_73 ;
int V_100 = 1 ;
int V_101 = 0 ;
int V_102 = F_7 ( V_66 -> V_157 ) ;
if ( F_97 ( ! F_8 ( & V_58 -> V_30 . V_170 ) ) )
return - V_171 ;
if ( V_66 -> V_136 ) {
if ( ! ( V_66 -> V_136 -> V_137 & V_140 ) )
V_100 = 0 ;
if ( V_66 -> V_136 -> V_137 & V_138 )
V_101 = 1 ;
}
if ( ! V_100 && ! V_101 )
F_68 ( L_6 ) ;
V_18 = F_64 ( V_72 , & V_58 -> V_172 . V_14 , V_58 -> V_172 . V_98 ,
F_98 ( struct V_24 , V_172 ) , V_100 ,
V_101 , V_102 , V_104 ) ;
if ( F_99 ( V_18 ) ) {
V_145 = F_100 ( V_18 ) ;
V_18 = NULL ;
goto V_95;
}
V_107 = V_18 ;
#ifdef F_101
if ( V_58 -> V_173 . V_98 ) {
struct V_17 * V_174 ;
if ( ! V_18 -> V_175 ) {
struct V_17 * V_176 ;
V_176 = F_11 () ;
if ( ! V_176 )
goto V_177;
V_176 -> V_43 = V_66 -> V_157 -> V_4 . V_44 ;
F_72 ( & V_66 -> V_157 -> V_4 . V_44 -> V_118 ) ;
V_176 -> V_45 = V_46 ;
V_176 -> V_86 = V_102 ;
V_174 = F_64 ( V_176 , & V_58 -> V_173 . V_14 ,
V_58 -> V_173 . V_98 ,
F_98 ( struct V_24 , V_173 ) ,
V_100 , V_101 , V_102 ,
V_104 ) ;
if ( F_99 ( V_174 ) ) {
F_13 ( V_176 ) ;
V_145 = F_100 ( V_174 ) ;
goto V_177;
}
V_176 -> V_117 = V_18 ;
V_18 -> V_175 = V_176 ;
} else {
V_174 = F_64 ( V_18 -> V_175 , & V_58 -> V_173 . V_14 ,
V_58 -> V_173 . V_98 ,
F_98 ( struct V_24 , V_173 ) ,
V_100 , V_101 , V_102 ,
V_104 ) ;
if ( F_99 ( V_174 ) ) {
V_145 = F_100 ( V_174 ) ;
goto V_177;
}
}
if ( ! V_18 -> V_43 ) {
V_18 -> V_43 = V_58 ;
F_72 ( & V_58 -> V_118 ) ;
}
V_18 = V_174 ;
}
#endif
V_145 = F_82 ( V_18 , V_58 , V_66 , V_125 ) ;
if ( ! V_145 ) {
F_92 ( V_66 -> V_157 , V_58 ) ;
if ( ! ( V_58 -> V_119 & V_166 ) )
F_102 ( V_66 -> V_157 , V_107 ) ;
}
V_95:
if ( V_145 ) {
#ifdef F_101
if ( V_107 != V_18 && V_107 -> V_43 == V_58 ) {
V_107 -> V_43 = NULL ;
F_103 ( & V_58 -> V_118 ) ;
}
if ( V_107 != V_18 && ! V_107 -> V_43 && ! ( V_107 -> V_45 & V_48 ) ) {
V_107 -> V_43 = F_81 ( V_66 -> V_157 , V_107 ) ;
#if V_178 >= 2
if ( ! V_107 -> V_43 ) {
F_91 ( V_107 -> V_43 == NULL ) ;
V_107 -> V_43 = V_66 -> V_157 -> V_4 . V_44 ;
}
#endif
F_72 ( & V_107 -> V_43 -> V_118 ) ;
}
#endif
goto V_177;
}
return V_145 ;
V_177:
if ( V_18 && ! ( V_18 -> V_45 & ( V_48 | V_46 ) ) )
F_104 ( V_66 -> V_157 , V_18 ) ;
F_105 ( & V_58 -> V_30 ) ;
return V_145 ;
}
static struct V_17 * F_106 ( struct V_17 * V_72 ,
struct V_179 * args )
{
struct V_17 * V_18 ;
T_1 V_111 ;
if ( F_78 ( args -> V_99 == 0 ) )
return NULL ;
V_18 = V_72 ;
for (; ; ) {
struct V_17 * V_94 ;
V_111 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_94 = V_111 ? V_18 -> V_115 : V_18 -> V_116 ;
if ( V_94 ) {
V_18 = V_94 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_107 ( V_18 ) || V_18 -> V_45 & V_48 ) {
struct V_108 * V_109 ;
V_109 = (struct V_108 * ) ( ( V_112 * ) V_18 -> V_43 +
args -> V_99 ) ;
if ( F_66 ( & V_109 -> V_14 , args -> V_14 , V_109 -> V_98 ) ) {
#ifdef F_101
if ( V_18 -> V_175 ) {
struct V_17 * V_176 ;
V_176 = F_106 ( V_18 -> V_175 ,
args + 1 ) ;
if ( ! V_176 )
goto V_180;
V_18 = V_176 ;
}
#endif
if ( V_18 -> V_45 & V_48 )
return V_18 ;
}
}
#ifdef F_101
V_180:
#endif
if ( V_18 -> V_45 & V_46 )
break;
V_18 = V_18 -> V_117 ;
}
return NULL ;
}
struct V_17 * F_108 ( struct V_17 * V_72 , const struct V_97 * V_181 ,
const struct V_97 * V_182 )
{
struct V_17 * V_18 ;
struct V_179 args [] = {
{
. V_99 = F_98 ( struct V_24 , V_172 ) ,
. V_14 = V_181 ,
} ,
#ifdef F_101
{
. V_99 = F_98 ( struct V_24 , V_173 ) ,
. V_14 = V_182 ,
} ,
#endif
{
. V_99 = 0 ,
}
} ;
V_18 = F_106 ( V_72 , V_181 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_45 & V_47 )
V_18 = V_72 ;
return V_18 ;
}
static struct V_17 * F_109 ( struct V_17 * V_72 ,
const struct V_97 * V_14 ,
int V_98 , int V_99 )
{
struct V_17 * V_18 ;
for ( V_18 = V_72 ; V_18 ; ) {
struct V_108 * V_109 = (struct V_108 * ) ( ( V_112 * ) V_18 -> V_43 + V_99 ) ;
if ( V_98 < V_18 -> V_13 ||
! F_66 ( & V_109 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_98 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_115 ;
else
V_18 = V_18 -> V_116 ;
}
return NULL ;
}
struct V_17 * F_110 ( struct V_17 * V_72 ,
const struct V_97 * V_181 , int V_183 ,
const struct V_97 * V_182 , int V_184 )
{
struct V_17 * V_18 ;
V_18 = F_109 ( V_72 , V_181 , V_183 ,
F_98 ( struct V_24 , V_172 ) ) ;
#ifdef F_101
if ( V_184 ) {
F_91 ( V_182 == NULL ) ;
if ( V_18 && V_18 -> V_175 )
V_18 = F_109 ( V_18 -> V_175 , V_182 , V_184 ,
F_98 ( struct V_24 , V_173 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_45 & V_48 )
return V_18 ;
return NULL ;
}
static struct V_24 * F_81 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
if ( V_18 -> V_45 & V_46 )
return V_1 -> V_4 . V_44 ;
while ( V_18 ) {
if ( V_18 -> V_116 )
return V_18 -> V_116 -> V_43 ;
if ( V_18 -> V_115 )
return V_18 -> V_115 -> V_43 ;
V_18 = F_107 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_104 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
int V_185 ;
int V_186 ;
struct V_17 * V_187 , * V_107 ;
struct V_2 * V_3 ;
int V_132 = 0 ;
for (; ; ) {
F_65 ( L_7 , V_18 -> V_13 , V_132 ) ;
V_132 ++ ;
F_91 ( V_18 -> V_45 & V_48 ) ;
F_91 ( V_18 -> V_45 & V_47 ) ;
F_91 ( V_18 -> V_43 ) ;
V_185 = 0 ;
V_187 = NULL ;
if ( V_18 -> V_115 )
V_187 = V_18 -> V_115 , V_185 |= 1 ;
if ( V_18 -> V_116 )
V_187 = V_18 -> V_116 , V_185 |= 2 ;
if ( V_185 == 3 || F_107 ( V_18 )
#ifdef F_101
|| ( V_185 && V_18 -> V_45 & V_46 )
#endif
) {
V_18 -> V_43 = F_81 ( V_1 , V_18 ) ;
#if V_178 >= 2
if ( ! V_18 -> V_43 ) {
F_91 ( ! V_18 -> V_43 ) ;
V_18 -> V_43 = V_1 -> V_4 . V_44 ;
}
#endif
F_72 ( & V_18 -> V_43 -> V_118 ) ;
return V_18 -> V_117 ;
}
V_107 = V_18 -> V_117 ;
#ifdef F_101
if ( F_107 ( V_107 ) == V_18 ) {
F_91 ( ! ( V_18 -> V_45 & V_46 ) ) ;
F_107 ( V_107 ) = NULL ;
V_186 = V_188 ;
} else {
F_91 ( V_18 -> V_45 & V_46 ) ;
#endif
if ( V_107 -> V_115 == V_18 )
V_107 -> V_115 = V_187 ;
else if ( V_107 -> V_116 == V_18 )
V_107 -> V_116 = V_187 ;
#if V_178 >= 2
else
F_91 ( 1 ) ;
#endif
if ( V_187 )
V_187 -> V_117 = V_107 ;
V_186 = V_189 ;
#ifdef F_101
}
#endif
F_111 ( & V_1 -> V_4 . V_5 ) ;
F_112 (net, w) {
if ( ! V_187 ) {
if ( V_3 -> V_72 == V_18 ) {
V_3 -> V_72 = V_3 -> V_89 = NULL ;
F_65 ( L_8 , V_3 ) ;
} else if ( V_3 -> V_89 == V_18 ) {
F_65 ( L_9 , V_3 , V_3 -> V_87 , V_186 ) ;
V_3 -> V_89 = V_107 ;
V_3 -> V_87 = V_186 ;
}
} else {
if ( V_3 -> V_72 == V_18 ) {
V_3 -> V_72 = V_187 ;
F_65 ( L_10 , V_3 ) ;
}
if ( V_3 -> V_89 == V_18 ) {
V_3 -> V_89 = V_187 ;
if ( V_185 & 2 ) {
F_65 ( L_11 , V_3 , V_3 -> V_87 ) ;
V_3 -> V_87 = V_3 -> V_87 >= V_189 ? V_190 : V_88 ;
} else {
F_65 ( L_11 , V_3 , V_3 -> V_87 ) ;
V_3 -> V_87 = V_3 -> V_87 >= V_191 ? V_190 : V_88 ;
}
}
}
}
F_113 ( & V_1 -> V_4 . V_5 ) ;
F_17 ( V_18 ) ;
if ( V_107 -> V_45 & V_48 || F_107 ( V_107 ) )
return V_107 ;
F_70 ( V_107 -> V_43 ) ;
V_107 -> V_43 = NULL ;
V_18 = V_107 ;
}
}
static void F_114 ( struct V_17 * V_18 , struct V_24 * * V_192 ,
struct V_131 * V_66 )
{
struct V_2 * V_3 ;
struct V_24 * V_58 = * V_192 ;
struct V_1 * V_1 = V_66 -> V_157 ;
F_65 ( L_12 ) ;
* V_192 = V_58 -> V_30 . V_71 ;
V_58 -> V_156 = NULL ;
V_1 -> V_4 . V_160 -> V_161 -- ;
V_1 -> V_4 . V_160 -> V_193 ++ ;
if ( V_18 -> V_153 == V_58 )
V_18 -> V_153 = NULL ;
if ( V_58 -> V_76 ) {
struct V_24 * V_154 , * V_194 ;
F_87 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_154 -> V_76 -- ;
V_58 -> V_76 = 0 ;
F_115 ( & V_58 -> V_77 ) ;
}
F_111 ( & V_1 -> V_4 . V_5 ) ;
F_112 (net, w) {
if ( V_3 -> V_87 == V_191 && V_3 -> V_43 == V_58 ) {
F_65 ( L_13 , V_3 ) ;
V_3 -> V_43 = V_58 -> V_30 . V_71 ;
if ( ! V_3 -> V_43 )
V_3 -> V_87 = V_190 ;
}
}
F_113 ( & V_1 -> V_4 . V_5 ) ;
V_58 -> V_30 . V_71 = NULL ;
if ( ! V_18 -> V_43 ) {
V_18 -> V_45 &= ~ V_48 ;
V_1 -> V_4 . V_160 -> V_162 -- ;
V_18 = F_104 ( V_1 , V_18 ) ;
}
F_80 ( V_58 , V_18 , V_1 ) ;
F_48 ( V_1 , V_195 , V_58 ) ;
if ( ! V_66 -> V_158 )
F_90 ( V_196 , V_58 , V_66 , 0 ) ;
F_70 ( V_58 ) ;
}
int F_116 ( struct V_24 * V_58 , struct V_131 * V_66 )
{
struct V_17 * V_18 = F_117 ( V_58 -> V_156 ,
F_118 ( & V_58 -> V_67 -> V_36 ) ) ;
struct V_1 * V_1 = V_66 -> V_157 ;
struct V_24 * * V_192 ;
#if V_178 >= 2
if ( V_58 -> V_30 . V_197 > 0 ) {
F_91 ( V_18 ) ;
return - V_113 ;
}
#endif
if ( ! V_18 || V_58 == V_1 -> V_4 . V_44 )
return - V_113 ;
F_91 ( ! ( V_18 -> V_45 & V_48 ) ) ;
if ( ! ( V_58 -> V_119 & V_166 ) ) {
struct V_17 * V_107 = V_18 ;
#ifdef F_101
if ( V_58 -> V_173 . V_98 ) {
while ( ! ( V_107 -> V_45 & V_46 ) )
V_107 = V_107 -> V_117 ;
V_107 = V_107 -> V_117 ;
}
#endif
F_102 ( V_66 -> V_157 , V_107 ) ;
}
for ( V_192 = & V_18 -> V_43 ; * V_192 ; V_192 = & ( * V_192 ) -> V_30 . V_71 ) {
if ( * V_192 == V_58 ) {
F_114 ( V_18 , V_192 , V_66 ) ;
return 0 ;
}
}
return - V_113 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_17 * V_18 , * V_107 ;
for (; ; ) {
V_18 = V_3 -> V_89 ;
if ( ! V_18 )
return 0 ;
if ( V_3 -> V_198 && V_18 != V_3 -> V_72 &&
V_18 -> V_45 & V_48 && V_3 -> V_87 < V_191 ) {
V_3 -> V_87 = V_191 ;
V_3 -> V_43 = V_18 -> V_43 ;
}
switch ( V_3 -> V_87 ) {
#ifdef F_101
case V_199 :
if ( F_107 ( V_18 ) ) {
V_3 -> V_89 = F_107 ( V_18 ) ;
continue;
}
V_3 -> V_87 = V_188 ;
#endif
case V_188 :
if ( V_18 -> V_116 ) {
V_3 -> V_89 = V_18 -> V_116 ;
V_3 -> V_87 = V_88 ;
continue;
}
V_3 -> V_87 = V_189 ;
case V_189 :
if ( V_18 -> V_115 ) {
V_3 -> V_89 = V_18 -> V_115 ;
V_3 -> V_87 = V_88 ;
continue;
}
V_3 -> V_87 = V_191 ;
V_3 -> V_43 = V_18 -> V_43 ;
case V_191 :
if ( V_3 -> V_43 && V_18 -> V_45 & V_48 ) {
int V_145 ;
if ( V_3 -> V_85 ) {
V_3 -> V_85 -- ;
goto V_85;
}
V_145 = V_3 -> V_74 ( V_3 ) ;
if ( V_145 )
return V_145 ;
V_3 -> V_84 ++ ;
continue;
}
V_85:
V_3 -> V_87 = V_190 ;
case V_190 :
if ( V_18 == V_3 -> V_72 )
return 0 ;
V_107 = V_18 -> V_117 ;
V_3 -> V_89 = V_107 ;
#ifdef F_101
if ( F_107 ( V_107 ) == V_18 ) {
F_91 ( ! ( V_18 -> V_45 & V_46 ) ) ;
V_3 -> V_87 = V_188 ;
continue;
}
#endif
if ( V_107 -> V_116 == V_18 ) {
V_3 -> V_87 = V_189 ;
continue;
}
if ( V_107 -> V_115 == V_18 ) {
V_3 -> V_87 = V_191 ;
V_3 -> V_43 = V_3 -> V_89 -> V_43 ;
continue;
}
#if V_178 >= 2
F_91 ( 1 ) ;
#endif
}
}
}
static int F_53 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_75 ;
V_3 -> V_87 = V_88 ;
V_3 -> V_89 = V_3 -> V_72 ;
F_1 ( V_1 , V_3 ) ;
V_75 = F_62 ( V_3 ) ;
if ( V_75 <= 0 )
F_5 ( V_1 , V_3 ) ;
return V_75 ;
}
static int F_119 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_24 * V_58 ;
struct V_200 * V_201 = F_16 ( V_3 , struct V_200 , V_3 ) ;
struct V_131 V_66 = {
. V_157 = V_201 -> V_1 ,
} ;
if ( V_201 -> V_102 != V_202 &&
V_3 -> V_89 -> V_86 != V_201 -> V_102 )
V_3 -> V_89 -> V_86 = V_201 -> V_102 ;
if ( ! V_201 -> V_74 ) {
F_97 ( V_201 -> V_102 == V_202 ) ;
V_3 -> V_43 = NULL ;
return 0 ;
}
for ( V_58 = V_3 -> V_43 ; V_58 ; V_58 = V_58 -> V_30 . V_71 ) {
V_75 = V_201 -> V_74 ( V_58 , V_201 -> V_69 ) ;
if ( V_75 < 0 ) {
V_3 -> V_43 = V_58 ;
V_75 = F_116 ( V_58 , & V_66 ) ;
if ( V_75 ) {
#if V_178 >= 2
F_120 ( L_14 ,
V_203 , V_58 ,
F_121 ( V_58 -> V_156 ) ,
V_75 ) ;
#endif
continue;
}
return 0 ;
}
F_91 ( V_75 != 0 ) ;
}
V_3 -> V_43 = V_58 ;
return 0 ;
}
static void F_122 ( struct V_1 * V_1 , struct V_17 * V_72 ,
int (* V_74)( struct V_24 * , void * V_69 ) ,
bool V_198 , int V_102 , void * V_69 )
{
struct V_200 V_201 ;
V_201 . V_3 . V_72 = V_72 ;
V_201 . V_3 . V_74 = F_119 ;
V_201 . V_3 . V_198 = V_198 ;
V_201 . V_3 . V_84 = 0 ;
V_201 . V_3 . V_85 = 0 ;
V_201 . V_74 = V_74 ;
V_201 . V_102 = V_102 ;
V_201 . V_69 = V_69 ;
V_201 . V_1 = V_1 ;
F_53 ( V_1 , & V_201 . V_3 ) ;
}
static void F_123 ( struct V_1 * V_1 ,
int (* V_74)( struct V_24 * , void * ) ,
int V_102 , void * V_69 )
{
struct V_31 * V_32 ;
struct V_50 * V_22 ;
unsigned int V_35 ;
F_36 () ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_37 (table, head, tb6_hlist) {
F_2 ( & V_32 -> V_36 ) ;
F_122 ( V_1 , & V_32 -> V_42 ,
V_74 , false , V_102 , V_69 ) ;
F_4 ( & V_32 -> V_36 ) ;
}
}
F_38 () ;
}
void F_124 ( struct V_1 * V_1 , int (* V_74)( struct V_24 * , void * ) ,
void * V_69 )
{
F_123 ( V_1 , V_74 , V_202 , V_69 ) ;
}
static int F_125 ( struct V_24 * V_58 , void * V_69 )
{
if ( V_58 -> V_119 & V_166 ) {
F_65 ( L_15 , V_58 ) ;
return - 1 ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
F_122 ( V_1 , V_18 , F_125 , true ,
V_202 , NULL ) ;
}
static void F_126 ( struct V_1 * V_1 )
{
int V_204 = F_7 ( V_1 ) ;
F_123 ( V_1 , NULL , V_204 , NULL ) ;
}
static int F_127 ( struct V_24 * V_58 , void * V_69 )
{
struct V_205 * V_206 = V_69 ;
unsigned long V_207 = V_167 ;
if ( V_58 -> V_119 & V_150 && V_58 -> V_30 . V_151 ) {
if ( F_128 ( V_207 , V_58 -> V_30 . V_151 ) ) {
F_65 ( L_16 , V_58 ) ;
return - 1 ;
}
V_206 -> V_208 ++ ;
} else if ( V_58 -> V_119 & V_166 ) {
if ( F_129 ( V_207 , V_58 -> V_30 . V_209 + V_206 -> V_210 ) )
V_58 -> V_30 . V_197 = V_211 ;
if ( F_8 ( & V_58 -> V_30 . V_170 ) == 1 &&
V_58 -> V_30 . V_197 == V_211 ) {
F_65 ( L_17 , V_58 ) ;
return - 1 ;
} else if ( V_58 -> V_119 & V_120 ) {
struct V_212 * V_213 ;
T_6 V_214 = 0 ;
V_213 = F_130 ( & V_58 -> V_30 , & V_58 -> V_215 ) ;
if ( V_213 ) {
V_214 = V_213 -> V_56 ;
F_131 ( V_213 ) ;
}
if ( ! ( V_214 & V_216 ) ) {
F_65 ( L_18 ,
V_58 ) ;
return - 1 ;
}
}
V_206 -> V_208 ++ ;
}
return 0 ;
}
void F_132 ( unsigned long V_151 , struct V_1 * V_1 , bool V_217 )
{
struct V_205 V_206 ;
unsigned long V_207 ;
if ( V_217 ) {
F_133 ( & V_1 -> V_4 . V_218 ) ;
} else if ( ! F_134 ( & V_1 -> V_4 . V_218 ) ) {
F_94 ( & V_1 -> V_4 . V_165 , V_167 + V_219 ) ;
return;
}
V_206 . V_210 = V_151 ? ( int ) V_151 :
V_1 -> V_4 . V_168 . V_169 ;
V_206 . V_208 = 0 ;
F_124 ( V_1 , F_127 , & V_206 ) ;
V_207 = V_167 ;
V_1 -> V_4 . V_220 = V_207 ;
if ( V_206 . V_208 )
F_94 ( & V_1 -> V_4 . V_165 ,
F_135 ( V_207
+ V_1 -> V_4 . V_168 . V_169 ) ) ;
else
F_136 ( & V_1 -> V_4 . V_165 ) ;
F_137 ( & V_1 -> V_4 . V_218 ) ;
}
static void F_138 ( unsigned long V_69 )
{
F_132 ( 0 , (struct V_1 * ) V_69 , true ) ;
}
static int T_3 F_139 ( struct V_1 * V_1 )
{
T_7 V_221 = sizeof( struct V_50 ) * V_38 ;
int V_145 ;
V_145 = F_140 ( V_1 ) ;
if ( V_145 )
return V_145 ;
F_141 ( & V_1 -> V_4 . V_218 ) ;
F_29 ( & V_1 -> V_4 . V_5 ) ;
F_142 ( & V_1 -> V_4 . V_7 ) ;
F_143 ( & V_1 -> V_4 . V_165 , F_138 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 . V_160 = F_32 ( sizeof( * V_1 -> V_4 . V_160 ) , V_222 ) ;
if ( ! V_1 -> V_4 . V_160 )
goto V_223;
V_221 = F_144 ( T_7 , V_221 , V_224 ) ;
V_1 -> V_4 . V_40 = F_32 ( V_221 , V_222 ) ;
if ( ! V_1 -> V_4 . V_40 )
goto V_225;
V_1 -> V_4 . V_51 = F_32 ( sizeof( * V_1 -> V_4 . V_51 ) ,
V_222 ) ;
if ( ! V_1 -> V_4 . V_51 )
goto V_226;
V_1 -> V_4 . V_51 -> V_37 = V_49 ;
V_1 -> V_4 . V_51 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_51 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_33 ( & V_1 -> V_4 . V_51 -> V_33 ) ;
#ifdef F_145
V_1 -> V_4 . V_52 = F_32 ( sizeof( * V_1 -> V_4 . V_52 ) ,
V_222 ) ;
if ( ! V_1 -> V_4 . V_52 )
goto V_227;
V_1 -> V_4 . V_52 -> V_37 = V_228 ;
V_1 -> V_4 . V_52 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_52 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_33 ( & V_1 -> V_4 . V_52 -> V_33 ) ;
#endif
F_39 ( V_1 ) ;
return 0 ;
#ifdef F_145
V_227:
F_27 ( V_1 -> V_4 . V_51 ) ;
#endif
V_226:
F_27 ( V_1 -> V_4 . V_40 ) ;
V_225:
F_27 ( V_1 -> V_4 . V_160 ) ;
V_223:
F_146 ( V_1 ) ;
return - V_73 ;
}
static void F_147 ( struct V_1 * V_1 )
{
unsigned int V_126 ;
F_148 ( V_1 , NULL ) ;
F_149 ( & V_1 -> V_4 . V_165 ) ;
for ( V_126 = 0 ; V_126 < V_38 ; V_126 ++ ) {
struct V_50 * V_22 = & V_1 -> V_4 . V_40 [ V_126 ] ;
struct V_229 * V_230 ;
struct V_31 * V_34 ;
F_150 (tb, tmp, head, tb6_hlist) {
F_151 ( & V_34 -> V_39 ) ;
F_25 ( V_34 ) ;
}
}
F_27 ( V_1 -> V_4 . V_40 ) ;
F_27 ( V_1 -> V_4 . V_160 ) ;
F_146 ( V_1 ) ;
}
int T_8 F_152 ( void )
{
int V_231 = - V_73 ;
V_19 = F_153 ( L_19 ,
sizeof( struct V_17 ) ,
0 , V_232 ,
NULL ) ;
if ( ! V_19 )
goto V_95;
V_231 = F_154 ( & V_233 ) ;
if ( V_231 )
goto V_234;
V_231 = F_155 ( V_235 , V_236 , NULL , F_63 ,
0 ) ;
if ( V_231 )
goto V_237;
V_238 = F_126 ;
V_95:
return V_231 ;
V_237:
F_156 ( & V_233 ) ;
V_234:
F_157 ( V_19 ) ;
goto V_95;
}
void F_158 ( void )
{
F_156 ( & V_233 ) ;
F_157 ( V_19 ) ;
}
static int F_159 ( struct V_239 * V_240 , void * V_241 )
{
struct V_24 * V_58 = V_241 ;
struct V_242 * V_132 = V_240 -> V_243 ;
F_160 ( V_240 , L_20 , & V_58 -> V_172 . V_14 , V_58 -> V_172 . V_98 ) ;
#ifdef F_101
F_160 ( V_240 , L_20 , & V_58 -> V_173 . V_14 , V_58 -> V_173 . V_98 ) ;
#else
F_161 ( V_240 , L_21 ) ;
#endif
if ( V_58 -> V_119 & V_120 )
F_160 ( V_240 , L_22 , & V_58 -> V_215 ) ;
else
F_161 ( V_240 , L_23 ) ;
F_160 ( V_240 , L_24 ,
V_58 -> V_147 , F_8 ( & V_58 -> V_30 . V_170 ) ,
V_58 -> V_30 . V_244 , V_58 -> V_119 ,
V_58 -> V_30 . V_245 ? V_58 -> V_30 . V_245 -> V_246 : L_25 ) ;
V_132 -> V_3 . V_43 = NULL ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_242 * V_132 = V_3 -> args ;
if ( ! V_132 -> V_85 )
return 1 ;
do {
V_132 -> V_3 . V_43 = V_132 -> V_3 . V_43 -> V_30 . V_71 ;
V_132 -> V_85 -- ;
if ( ! V_132 -> V_85 && V_132 -> V_3 . V_43 )
return 1 ;
} while ( V_132 -> V_3 . V_43 );
return 0 ;
}
static void F_163 ( struct V_242 * V_132 ,
struct V_1 * V_1 )
{
memset ( & V_132 -> V_3 , 0 , sizeof( V_132 -> V_3 ) ) ;
V_132 -> V_3 . V_74 = F_162 ;
V_132 -> V_3 . V_72 = & V_132 -> V_247 -> V_42 ;
V_132 -> V_3 . V_87 = V_88 ;
V_132 -> V_3 . V_89 = V_132 -> V_3 . V_72 ;
V_132 -> V_3 . args = V_132 ;
V_132 -> V_102 = V_132 -> V_3 . V_72 -> V_86 ;
F_142 ( & V_132 -> V_3 . V_6 ) ;
F_1 ( V_1 , & V_132 -> V_3 ) ;
}
static struct V_31 * F_164 ( struct V_31 * V_247 ,
struct V_1 * V_1 )
{
unsigned int V_35 ;
struct V_229 * V_89 ;
if ( V_247 ) {
V_35 = ( V_247 -> V_37 & ( V_38 - 1 ) ) + 1 ;
V_89 = F_165 ( F_166 ( & V_247 -> V_39 ) ) ;
} else {
V_35 = 0 ;
V_89 = NULL ;
}
while ( ! V_89 && V_35 < V_38 ) {
V_89 = F_165 (
F_167 ( & V_1 -> V_4 . V_40 [ V_35 ++ ] ) ) ;
}
return F_168 ( V_89 , struct V_31 , V_39 ) ;
}
static void F_169 ( struct V_242 * V_132 )
{
if ( V_132 -> V_102 != V_132 -> V_3 . V_72 -> V_86 ) {
V_132 -> V_102 = V_132 -> V_3 . V_72 -> V_86 ;
V_132 -> V_3 . V_87 = V_88 ;
V_132 -> V_3 . V_89 = V_132 -> V_3 . V_72 ;
F_91 ( V_132 -> V_3 . V_85 ) ;
V_132 -> V_3 . V_85 = V_132 -> V_3 . V_84 ;
}
}
static void * F_170 ( struct V_239 * V_240 , void * V_241 , T_9 * V_248 )
{
int V_249 ;
struct V_24 * V_250 ;
struct V_1 * V_1 = F_171 ( V_240 ) ;
struct V_242 * V_132 = V_240 -> V_243 ;
if ( ! V_241 )
goto V_251;
V_250 = ( (struct V_24 * ) V_241 ) -> V_30 . V_71 ;
if ( V_250 ) {
++ * V_248 ;
return V_250 ;
}
V_251:
F_169 ( V_132 ) ;
F_111 ( & V_132 -> V_247 -> V_36 ) ;
V_249 = F_62 ( & V_132 -> V_3 ) ;
F_113 ( & V_132 -> V_247 -> V_36 ) ;
if ( V_249 > 0 ) {
if ( V_241 )
++ * V_248 ;
return V_132 -> V_3 . V_43 ;
} else if ( V_249 < 0 ) {
F_5 ( V_1 , & V_132 -> V_3 ) ;
return NULL ;
}
F_5 ( V_1 , & V_132 -> V_3 ) ;
V_132 -> V_247 = F_164 ( V_132 -> V_247 , V_1 ) ;
if ( ! V_132 -> V_247 )
return NULL ;
F_163 ( V_132 , V_1 ) ;
goto V_251;
}
static void * F_172 ( struct V_239 * V_240 , T_9 * V_248 )
__acquires( T_10 )
{
struct V_1 * V_1 = F_171 ( V_240 ) ;
struct V_242 * V_132 = V_240 -> V_243 ;
F_173 () ;
V_132 -> V_247 = F_164 ( NULL , V_1 ) ;
V_132 -> V_85 = * V_248 ;
if ( V_132 -> V_247 ) {
F_163 ( V_132 , V_1 ) ;
return F_170 ( V_240 , NULL , V_248 ) ;
} else {
return NULL ;
}
}
static bool F_174 ( struct V_242 * V_132 )
{
struct V_2 * V_3 = & V_132 -> V_3 ;
return V_3 -> V_89 && ! ( V_3 -> V_87 == V_190 && V_3 -> V_89 == V_3 -> V_72 ) ;
}
static void F_175 ( struct V_239 * V_240 , void * V_241 )
__releases( T_10 )
{
struct V_1 * V_1 = F_171 ( V_240 ) ;
struct V_242 * V_132 = V_240 -> V_243 ;
if ( F_174 ( V_132 ) )
F_5 ( V_1 , & V_132 -> V_3 ) ;
F_176 () ;
}
int F_177 ( struct V_252 * V_252 , struct V_253 * V_253 )
{
return F_178 ( V_252 , V_253 , & V_254 ,
sizeof( struct V_242 ) ) ;
}
