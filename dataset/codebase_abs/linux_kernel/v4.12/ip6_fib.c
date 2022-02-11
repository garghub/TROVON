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
F_16 ( & V_22 -> V_23 . V_24 , V_25 ) ;
}
static void F_17 ( struct V_21 * V_26 )
{
int V_27 ;
if ( ! V_26 -> V_28 )
return;
F_18 (cpu) {
struct V_21 * * V_29 ;
struct V_21 * V_30 ;
V_29 = F_19 ( V_26 -> V_28 , V_27 ) ;
V_30 = * V_29 ;
if ( V_30 ) {
F_15 ( V_30 ) ;
* V_29 = NULL ;
}
}
F_20 ( V_26 -> V_28 ) ;
V_26 -> V_28 = NULL ;
}
static void F_21 ( struct V_21 * V_22 )
{
if ( F_22 ( & V_22 -> V_31 ) ) {
F_17 ( V_22 ) ;
F_15 ( V_22 ) ;
}
}
static void F_23 ( struct V_1 * V_1 , struct V_32 * V_33 )
{
unsigned int V_34 ;
F_24 ( & V_33 -> V_35 ) ;
V_34 = V_33 -> V_36 & ( V_37 - 1 ) ;
F_25 ( & V_33 -> V_38 , & V_1 -> V_4 . V_39 [ V_34 ] ) ;
}
static struct V_32 * F_26 ( struct V_1 * V_1 , T_2 V_40 )
{
struct V_32 * V_41 ;
V_41 = F_27 ( sizeof( * V_41 ) , V_20 ) ;
if ( V_41 ) {
V_41 -> V_36 = V_40 ;
V_41 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_41 -> V_42 . V_45 = V_46 | V_47 | V_48 ;
F_28 ( & V_41 -> V_49 ) ;
}
return V_41 ;
}
struct V_32 * F_29 ( struct V_1 * V_1 , T_2 V_40 )
{
struct V_32 * V_33 ;
if ( V_40 == 0 )
V_40 = V_50 ;
V_33 = F_30 ( V_1 , V_40 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_26 ( V_1 , V_40 ) ;
if ( V_33 )
F_23 ( V_1 , V_33 ) ;
return V_33 ;
}
struct V_32 * F_30 ( struct V_1 * V_1 , T_2 V_40 )
{
struct V_32 * V_33 ;
struct V_51 * V_52 ;
unsigned int V_34 ;
if ( V_40 == 0 )
V_40 = V_50 ;
V_34 = V_40 & ( V_37 - 1 ) ;
F_31 () ;
V_52 = & V_1 -> V_4 . V_39 [ V_34 ] ;
F_32 (tb, head, tb6_hlist) {
if ( V_33 -> V_36 == V_40 ) {
F_33 () ;
return V_33 ;
}
}
F_33 () ;
return NULL ;
}
static void T_3 F_34 ( struct V_1 * V_1 )
{
F_23 ( V_1 , V_1 -> V_4 . V_53 ) ;
F_23 ( V_1 , V_1 -> V_4 . V_54 ) ;
}
struct V_32 * F_29 ( struct V_1 * V_1 , T_2 V_40 )
{
return F_30 ( V_1 , V_40 ) ;
}
struct V_32 * F_30 ( struct V_1 * V_1 , T_2 V_40 )
{
return V_1 -> V_4 . V_53 ;
}
struct V_55 * F_35 ( struct V_1 * V_1 , struct V_56 * V_57 ,
int V_58 , T_4 V_59 )
{
struct V_21 * V_22 ;
V_22 = V_59 ( V_1 , V_1 -> V_4 . V_53 , V_57 , V_58 ) ;
if ( V_22 -> V_23 . error == - V_60 ) {
F_36 ( V_22 ) ;
V_22 = V_1 -> V_4 . V_44 ;
F_37 ( & V_22 -> V_23 ) ;
}
return & V_22 -> V_23 ;
}
static void T_3 F_34 ( struct V_1 * V_1 )
{
F_23 ( V_1 , V_1 -> V_4 . V_53 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
int V_61 ;
struct V_21 * V_22 ;
for ( V_22 = V_3 -> V_43 ; V_22 ; V_22 = V_22 -> V_23 . V_62 ) {
V_61 = F_39 ( V_22 , V_3 -> args ) ;
if ( V_61 < 0 ) {
V_3 -> V_43 = V_22 ;
return 1 ;
}
if ( V_22 -> V_63 )
V_22 = F_40 ( & V_22 -> V_64 ,
struct V_21 ,
V_64 ) ;
}
V_3 -> V_43 = NULL ;
return 0 ;
}
static void F_41 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_42 ( V_66 -> V_67 -> V_68 ) ;
struct V_2 * V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( V_3 ) {
if ( V_66 -> args [ 4 ] ) {
V_66 -> args [ 4 ] = 0 ;
F_5 ( V_1 , V_3 ) ;
}
V_66 -> args [ 2 ] = 0 ;
F_43 ( V_3 ) ;
}
V_66 -> V_69 = ( void * ) V_66 -> args [ 3 ] ;
V_66 -> args [ 1 ] = 3 ;
}
static int F_44 ( struct V_65 * V_66 )
{
F_41 ( V_66 ) ;
return V_66 -> V_69 ? V_66 -> V_69 ( V_66 ) : 0 ;
}
static int F_45 ( struct V_32 * V_41 , struct V_70 * V_67 ,
struct V_65 * V_66 )
{
struct V_1 * V_1 = F_42 ( V_67 -> V_68 ) ;
struct V_2 * V_3 ;
int V_61 ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
V_3 -> V_71 = & V_41 -> V_42 ;
if ( V_66 -> args [ 4 ] == 0 ) {
V_3 -> V_72 = 0 ;
V_3 -> V_73 = 0 ;
F_46 ( & V_41 -> V_35 ) ;
V_61 = F_47 ( V_1 , V_3 ) ;
F_48 ( & V_41 -> V_35 ) ;
if ( V_61 > 0 ) {
V_66 -> args [ 4 ] = 1 ;
V_66 -> args [ 5 ] = V_3 -> V_71 -> V_74 ;
}
} else {
if ( V_66 -> args [ 5 ] != V_3 -> V_71 -> V_74 ) {
V_66 -> args [ 5 ] = V_3 -> V_71 -> V_74 ;
V_3 -> V_75 = V_76 ;
V_3 -> V_77 = V_3 -> V_71 ;
V_3 -> V_73 = V_3 -> V_72 ;
} else
V_3 -> V_73 = 0 ;
F_46 ( & V_41 -> V_35 ) ;
V_61 = F_49 ( V_3 ) ;
F_48 ( & V_41 -> V_35 ) ;
if ( V_61 <= 0 ) {
F_5 ( V_1 , V_3 ) ;
V_66 -> args [ 4 ] = 0 ;
}
}
return V_61 ;
}
static int F_50 ( struct V_70 * V_67 , struct V_65 * V_66 )
{
struct V_1 * V_1 = F_42 ( V_67 -> V_68 ) ;
unsigned int V_34 , V_78 ;
unsigned int V_79 = 0 , V_80 ;
struct V_81 V_82 ;
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
int V_61 = 0 ;
V_78 = V_66 -> args [ 0 ] ;
V_80 = V_66 -> args [ 1 ] ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( ! V_3 ) {
V_66 -> args [ 3 ] = ( long ) V_66 -> V_69 ;
V_66 -> V_69 = F_44 ;
V_3 = F_27 ( sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_83 ;
V_3 -> V_84 = F_38 ;
V_66 -> args [ 2 ] = ( long ) V_3 ;
}
V_82 . V_67 = V_67 ;
V_82 . V_66 = V_66 ;
V_82 . V_1 = V_1 ;
V_3 -> args = & V_82 ;
F_31 () ;
for ( V_34 = V_78 ; V_34 < V_37 ; V_34 ++ , V_80 = 0 ) {
V_79 = 0 ;
V_52 = & V_1 -> V_4 . V_39 [ V_34 ] ;
F_32 (tb, head, tb6_hlist) {
if ( V_79 < V_80 )
goto V_85;
V_61 = F_45 ( V_33 , V_67 , V_66 ) ;
if ( V_61 != 0 )
goto V_86;
V_85:
V_79 ++ ;
}
}
V_86:
F_33 () ;
V_66 -> args [ 1 ] = V_79 ;
V_66 -> args [ 0 ] = V_34 ;
V_61 = V_61 < 0 ? V_61 : V_67 -> V_87 ;
if ( V_61 <= 0 )
F_41 ( V_66 ) ;
return V_61 ;
}
static struct V_17 * F_51 ( struct V_17 * V_71 ,
struct V_88 * V_14 , int V_89 ,
int V_90 , int V_91 ,
int V_92 , int V_93 )
{
struct V_17 * V_18 , * V_94 , * V_95 ;
struct V_17 * V_96 = NULL ;
struct V_97 * V_98 ;
int V_99 ;
T_1 V_100 = 0 ;
F_52 ( L_1 ) ;
V_18 = V_71 ;
do {
V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_53 ( & V_98 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_91 ) {
if ( V_92 ) {
F_54 ( L_2 ) ;
return F_55 ( - V_102 ) ;
}
F_54 ( L_3 ) ;
}
goto V_103;
}
if ( V_89 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_45 & V_48 ) ) {
F_21 ( V_18 -> V_43 ) ;
V_18 -> V_43 = NULL ;
}
V_18 -> V_74 = V_93 ;
return V_18 ;
}
V_18 -> V_74 = V_93 ;
V_100 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_96 = V_18 ;
V_18 = V_100 ? V_18 -> V_104 : V_18 -> V_105 ;
} while ( V_18 );
if ( ! V_91 ) {
if ( V_92 ) {
F_54 ( L_2 ) ;
return F_55 ( - V_102 ) ;
}
F_54 ( L_3 ) ;
}
V_95 = F_11 () ;
if ( ! V_95 )
return F_55 ( - V_83 ) ;
V_95 -> V_13 = V_89 ;
V_95 -> V_106 = V_96 ;
V_95 -> V_74 = V_93 ;
if ( V_100 )
V_96 -> V_104 = V_95 ;
else
V_96 -> V_105 = V_95 ;
return V_95 ;
V_103:
V_96 = V_18 -> V_106 ;
V_99 = F_56 ( V_14 , & V_98 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_89 > V_99 ) {
V_94 = F_11 () ;
V_95 = F_11 () ;
if ( ! V_94 || ! V_95 ) {
if ( V_94 )
F_13 ( V_94 ) ;
if ( V_95 )
F_13 ( V_95 ) ;
return F_55 ( - V_83 ) ;
}
V_94 -> V_13 = V_99 ;
V_94 -> V_106 = V_96 ;
V_94 -> V_43 = V_18 -> V_43 ;
F_57 ( & V_94 -> V_43 -> V_31 ) ;
V_94 -> V_74 = V_93 ;
if ( V_100 )
V_96 -> V_104 = V_94 ;
else
V_96 -> V_105 = V_94 ;
V_95 -> V_13 = V_89 ;
V_95 -> V_106 = V_94 ;
V_18 -> V_106 = V_94 ;
V_95 -> V_74 = V_93 ;
if ( F_10 ( V_14 , V_99 ) ) {
V_94 -> V_104 = V_95 ;
V_94 -> V_105 = V_18 ;
} else {
V_94 -> V_105 = V_95 ;
V_94 -> V_104 = V_18 ;
}
} else {
V_95 = F_11 () ;
if ( ! V_95 )
return F_55 ( - V_83 ) ;
V_95 -> V_13 = V_89 ;
V_95 -> V_106 = V_96 ;
V_95 -> V_74 = V_93 ;
if ( V_100 )
V_96 -> V_104 = V_95 ;
else
V_96 -> V_105 = V_95 ;
if ( F_10 ( & V_98 -> V_14 , V_89 ) )
V_95 -> V_104 = V_18 ;
else
V_95 -> V_105 = V_18 ;
V_18 -> V_106 = V_95 ;
}
return V_95 ;
}
static bool F_58 ( struct V_21 * V_22 )
{
return ( V_22 -> V_107 & ( V_108 | V_109 | V_110 ) ) ==
V_108 ;
}
static void F_59 ( T_2 * V_111 , const struct V_112 * V_113 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ ) {
if ( F_60 ( V_114 , V_113 -> V_116 ) )
V_111 [ V_114 ] = V_113 -> V_117 [ V_114 ] ;
}
}
static int F_61 ( struct V_55 * V_23 , struct V_112 * V_113 )
{
if ( ! V_113 -> V_117 )
return 0 ;
if ( V_23 -> V_58 & V_118 ) {
T_2 * V_111 = F_62 ( V_23 ) ;
if ( F_63 ( ! V_111 ) )
return - V_83 ;
F_59 ( V_111 , V_113 ) ;
} else {
F_64 ( V_23 , V_113 -> V_117 , false ) ;
V_113 -> V_117 = NULL ;
}
return 0 ;
}
static void F_65 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_1 * V_1 )
{
if ( F_8 ( & V_22 -> V_31 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_45 & V_48 ) && V_18 -> V_43 == V_22 ) {
V_18 -> V_43 = F_66 ( V_1 , V_18 ) ;
F_57 ( & V_18 -> V_43 -> V_31 ) ;
F_21 ( V_22 ) ;
}
V_18 = V_18 -> V_106 ;
}
F_67 ( F_8 ( & V_22 -> V_31 ) != 1 ) ;
}
}
static int F_68 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_119 * V_120 , struct V_112 * V_113 )
{
struct V_21 * V_121 = NULL ;
struct V_21 * * V_122 ;
struct V_21 * * V_123 = NULL ;
int V_124 = ( V_120 -> V_125 &&
( V_120 -> V_125 -> V_126 & V_127 ) ) ;
int V_128 = ( ! V_120 -> V_125 ||
( V_120 -> V_125 -> V_126 & V_129 ) ) ;
int V_130 = 0 ;
bool V_131 = F_58 ( V_22 ) ;
T_5 V_132 = V_133 ;
int V_134 ;
if ( V_120 -> V_125 && ( V_120 -> V_125 -> V_126 & V_135 ) )
V_132 |= V_135 ;
V_122 = & V_18 -> V_43 ;
for ( V_121 = V_18 -> V_43 ; V_121 ; V_121 = V_121 -> V_23 . V_62 ) {
if ( V_121 -> V_136 == V_22 -> V_136 ) {
if ( V_120 -> V_125 &&
( V_120 -> V_125 -> V_126 & V_133 ) )
return - V_137 ;
V_132 &= ~ V_133 ;
if ( V_124 ) {
if ( V_131 == F_58 ( V_121 ) ) {
V_130 ++ ;
break;
}
if ( V_131 )
V_123 = V_123 ? : V_122 ;
goto V_138;
}
if ( V_121 -> V_23 . V_139 == V_22 -> V_23 . V_139 &&
V_121 -> V_140 == V_22 -> V_140 &&
F_69 ( & V_121 -> V_141 ,
& V_22 -> V_141 ) ) {
if ( V_22 -> V_63 )
V_22 -> V_63 = 0 ;
if ( ! ( V_121 -> V_107 & V_142 ) )
return - V_137 ;
if ( ! ( V_22 -> V_107 & V_142 ) )
F_70 ( V_121 ) ;
else
F_71 ( V_121 , V_22 -> V_23 . V_143 ) ;
V_121 -> V_144 = V_22 -> V_144 ;
return - V_137 ;
}
if ( V_131 &&
F_58 ( V_121 ) )
V_22 -> V_63 ++ ;
}
if ( V_121 -> V_136 > V_22 -> V_136 )
break;
V_138:
V_122 = & V_121 -> V_23 . V_62 ;
}
if ( V_123 && ! V_130 ) {
V_122 = V_123 ;
V_121 = * V_122 ;
V_130 ++ ;
}
if ( V_122 == & V_18 -> V_43 )
V_18 -> V_145 = NULL ;
if ( V_22 -> V_63 ) {
unsigned int V_63 ;
struct V_21 * V_146 , * V_147 ;
V_146 = V_18 -> V_43 ;
while ( V_146 ) {
if ( V_146 -> V_136 == V_22 -> V_136 &&
F_58 ( V_146 ) ) {
F_72 ( & V_22 -> V_64 ,
& V_146 -> V_64 ) ;
break;
}
V_146 = V_146 -> V_23 . V_62 ;
}
V_63 = 0 ;
F_73 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_146 -> V_63 ++ ;
F_67 ( V_146 -> V_63 != V_22 -> V_63 ) ;
V_63 ++ ;
}
F_67 ( V_63 != V_22 -> V_63 ) ;
}
if ( ! V_124 ) {
if ( ! V_128 )
F_54 ( L_3 ) ;
V_128:
V_132 |= V_129 ;
V_134 = F_61 ( & V_22 -> V_23 , V_113 ) ;
if ( V_134 )
return V_134 ;
V_22 -> V_23 . V_62 = V_121 ;
* V_122 = V_22 ;
V_22 -> V_148 = V_18 ;
F_57 ( & V_22 -> V_31 ) ;
if ( ! V_120 -> V_149 )
F_74 ( V_150 , V_22 , V_120 , V_132 ) ;
V_120 -> V_151 -> V_4 . V_152 -> V_153 ++ ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_120 -> V_151 -> V_4 . V_152 -> V_154 ++ ;
V_18 -> V_45 |= V_48 ;
}
} else {
int V_155 ;
if ( ! V_130 ) {
if ( V_128 )
goto V_128;
F_54 ( L_4 ) ;
return - V_102 ;
}
V_134 = F_61 ( & V_22 -> V_23 , V_113 ) ;
if ( V_134 )
return V_134 ;
* V_122 = V_22 ;
V_22 -> V_148 = V_18 ;
V_22 -> V_23 . V_62 = V_121 -> V_23 . V_62 ;
F_57 ( & V_22 -> V_31 ) ;
if ( ! V_120 -> V_149 )
F_74 ( V_150 , V_22 , V_120 , V_127 ) ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_120 -> V_151 -> V_4 . V_152 -> V_154 ++ ;
V_18 -> V_45 |= V_48 ;
}
V_155 = V_121 -> V_63 ;
F_65 ( V_121 , V_18 , V_120 -> V_151 ) ;
F_21 ( V_121 ) ;
if ( V_155 ) {
V_122 = & V_22 -> V_23 . V_62 ;
V_121 = * V_122 ;
while ( V_121 ) {
if ( V_121 -> V_136 > V_22 -> V_136 )
break;
if ( F_58 ( V_121 ) ) {
* V_122 = V_121 -> V_23 . V_62 ;
F_65 ( V_121 , V_18 , V_120 -> V_151 ) ;
F_21 ( V_121 ) ;
V_155 -- ;
} else {
V_122 = & V_121 -> V_23 . V_62 ;
}
V_121 = * V_122 ;
}
F_75 ( V_155 != 0 ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
if ( ! F_77 ( & V_1 -> V_4 . V_156 ) &&
( V_22 -> V_107 & ( V_142 | V_157 ) ) )
F_78 ( & V_1 -> V_4 . V_156 ,
V_158 + V_1 -> V_4 . V_159 . V_160 ) ;
}
void F_79 ( struct V_1 * V_1 )
{
if ( ! F_77 ( & V_1 -> V_4 . V_156 ) )
F_78 ( & V_1 -> V_4 . V_156 ,
V_158 + V_1 -> V_4 . V_159 . V_160 ) ;
}
int F_80 ( struct V_17 * V_71 , struct V_21 * V_22 ,
struct V_119 * V_120 , struct V_112 * V_113 )
{
struct V_17 * V_18 , * V_96 = NULL ;
int V_134 = - V_83 ;
int V_91 = 1 ;
int V_92 = 0 ;
int V_93 = F_7 ( V_120 -> V_151 ) ;
if ( F_81 ( ( V_22 -> V_23 . V_58 & V_161 ) &&
! F_8 ( & V_22 -> V_23 . V_162 ) ) )
return - V_163 ;
if ( V_120 -> V_125 ) {
if ( ! ( V_120 -> V_125 -> V_126 & V_129 ) )
V_91 = 0 ;
if ( V_120 -> V_125 -> V_126 & V_127 )
V_92 = 1 ;
}
if ( ! V_91 && ! V_92 )
F_54 ( L_5 ) ;
V_18 = F_51 ( V_71 , & V_22 -> V_164 . V_14 , V_22 -> V_164 . V_89 ,
F_82 ( struct V_21 , V_164 ) , V_91 ,
V_92 , V_93 ) ;
if ( F_83 ( V_18 ) ) {
V_134 = F_84 ( V_18 ) ;
V_18 = NULL ;
goto V_86;
}
V_96 = V_18 ;
#ifdef F_85
if ( V_22 -> V_165 . V_89 ) {
struct V_17 * V_166 ;
if ( ! V_18 -> V_167 ) {
struct V_17 * V_168 ;
V_168 = F_11 () ;
if ( ! V_168 )
goto V_169;
V_168 -> V_43 = V_120 -> V_151 -> V_4 . V_44 ;
F_57 ( & V_120 -> V_151 -> V_4 . V_44 -> V_31 ) ;
V_168 -> V_45 = V_46 ;
V_168 -> V_74 = V_93 ;
V_166 = F_51 ( V_168 , & V_22 -> V_165 . V_14 ,
V_22 -> V_165 . V_89 ,
F_82 ( struct V_21 , V_165 ) ,
V_91 , V_92 , V_93 ) ;
if ( F_83 ( V_166 ) ) {
F_13 ( V_168 ) ;
V_134 = F_84 ( V_166 ) ;
goto V_169;
}
V_168 -> V_106 = V_18 ;
V_18 -> V_167 = V_168 ;
} else {
V_166 = F_51 ( V_18 -> V_167 , & V_22 -> V_165 . V_14 ,
V_22 -> V_165 . V_89 ,
F_82 ( struct V_21 , V_165 ) ,
V_91 , V_92 , V_93 ) ;
if ( F_83 ( V_166 ) ) {
V_134 = F_84 ( V_166 ) ;
goto V_169;
}
}
if ( ! V_18 -> V_43 ) {
V_18 -> V_43 = V_22 ;
F_57 ( & V_22 -> V_31 ) ;
}
V_18 = V_166 ;
}
#endif
V_134 = F_68 ( V_18 , V_22 , V_120 , V_113 ) ;
if ( ! V_134 ) {
F_76 ( V_120 -> V_151 , V_22 ) ;
if ( ! ( V_22 -> V_107 & V_157 ) )
F_86 ( V_120 -> V_151 , V_96 ) ;
V_22 -> V_23 . V_58 &= ~ V_161 ;
}
V_86:
if ( V_134 ) {
#ifdef F_85
if ( V_96 != V_18 && V_96 -> V_43 == V_22 ) {
V_96 -> V_43 = NULL ;
F_87 ( & V_22 -> V_31 ) ;
}
if ( V_96 != V_18 && ! V_96 -> V_43 && ! ( V_96 -> V_45 & V_48 ) ) {
V_96 -> V_43 = F_66 ( V_120 -> V_151 , V_96 ) ;
#if V_170 >= 2
if ( ! V_96 -> V_43 ) {
F_75 ( V_96 -> V_43 == NULL ) ;
V_96 -> V_43 = V_120 -> V_151 -> V_4 . V_44 ;
}
#endif
F_57 ( & V_96 -> V_43 -> V_31 ) ;
}
#endif
if ( ! ( V_22 -> V_23 . V_58 & V_161 ) )
F_88 ( & V_22 -> V_23 ) ;
}
return V_134 ;
#ifdef F_85
V_169:
if ( V_18 && ! ( V_18 -> V_45 & ( V_48 | V_46 ) ) )
F_89 ( V_120 -> V_151 , V_18 ) ;
if ( ! ( V_22 -> V_23 . V_58 & V_161 ) )
F_88 ( & V_22 -> V_23 ) ;
return V_134 ;
#endif
}
static struct V_17 * F_90 ( struct V_17 * V_71 ,
struct V_171 * args )
{
struct V_17 * V_18 ;
T_1 V_100 ;
if ( F_63 ( args -> V_90 == 0 ) )
return NULL ;
V_18 = V_71 ;
for (; ; ) {
struct V_17 * V_85 ;
V_100 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_85 = V_100 ? V_18 -> V_104 : V_18 -> V_105 ;
if ( V_85 ) {
V_18 = V_85 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_91 ( V_18 ) || V_18 -> V_45 & V_48 ) {
struct V_97 * V_98 ;
V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 +
args -> V_90 ) ;
if ( F_53 ( & V_98 -> V_14 , args -> V_14 , V_98 -> V_89 ) ) {
#ifdef F_85
if ( V_18 -> V_167 ) {
struct V_17 * V_168 ;
V_168 = F_90 ( V_18 -> V_167 ,
args + 1 ) ;
if ( ! V_168 )
goto V_172;
V_18 = V_168 ;
}
#endif
if ( V_18 -> V_45 & V_48 )
return V_18 ;
}
}
#ifdef F_85
V_172:
#endif
if ( V_18 -> V_45 & V_46 )
break;
V_18 = V_18 -> V_106 ;
}
return NULL ;
}
struct V_17 * F_92 ( struct V_17 * V_71 , const struct V_88 * V_173 ,
const struct V_88 * V_174 )
{
struct V_17 * V_18 ;
struct V_171 args [] = {
{
. V_90 = F_82 ( struct V_21 , V_164 ) ,
. V_14 = V_173 ,
} ,
#ifdef F_85
{
. V_90 = F_82 ( struct V_21 , V_165 ) ,
. V_14 = V_174 ,
} ,
#endif
{
. V_90 = 0 ,
}
} ;
V_18 = F_90 ( V_71 , V_173 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_45 & V_47 )
V_18 = V_71 ;
return V_18 ;
}
static struct V_17 * F_93 ( struct V_17 * V_71 ,
const struct V_88 * V_14 ,
int V_89 , int V_90 )
{
struct V_17 * V_18 ;
for ( V_18 = V_71 ; V_18 ; ) {
struct V_97 * V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_53 ( & V_98 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_89 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_104 ;
else
V_18 = V_18 -> V_105 ;
}
return NULL ;
}
struct V_17 * F_94 ( struct V_17 * V_71 ,
const struct V_88 * V_173 , int V_175 ,
const struct V_88 * V_174 , int V_176 )
{
struct V_17 * V_18 ;
V_18 = F_93 ( V_71 , V_173 , V_175 ,
F_82 ( struct V_21 , V_164 ) ) ;
#ifdef F_85
if ( V_176 ) {
F_75 ( V_174 == NULL ) ;
if ( V_18 && V_18 -> V_167 )
V_18 = F_93 ( V_18 -> V_167 , V_174 , V_176 ,
F_82 ( struct V_21 , V_165 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_45 & V_48 )
return V_18 ;
return NULL ;
}
static struct V_21 * F_66 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
if ( V_18 -> V_45 & V_46 )
return V_1 -> V_4 . V_44 ;
while ( V_18 ) {
if ( V_18 -> V_105 )
return V_18 -> V_105 -> V_43 ;
if ( V_18 -> V_104 )
return V_18 -> V_104 -> V_43 ;
V_18 = F_91 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_89 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
int V_177 ;
int V_178 ;
struct V_17 * V_179 , * V_96 ;
struct V_2 * V_3 ;
int V_121 = 0 ;
for (; ; ) {
F_52 ( L_6 , V_18 -> V_13 , V_121 ) ;
V_121 ++ ;
F_75 ( V_18 -> V_45 & V_48 ) ;
F_75 ( V_18 -> V_45 & V_47 ) ;
F_75 ( V_18 -> V_43 ) ;
V_177 = 0 ;
V_179 = NULL ;
if ( V_18 -> V_104 )
V_179 = V_18 -> V_104 , V_177 |= 1 ;
if ( V_18 -> V_105 )
V_179 = V_18 -> V_105 , V_177 |= 2 ;
if ( V_177 == 3 || F_91 ( V_18 )
#ifdef F_85
|| ( V_177 && V_18 -> V_45 & V_46 )
#endif
) {
V_18 -> V_43 = F_66 ( V_1 , V_18 ) ;
#if V_170 >= 2
if ( ! V_18 -> V_43 ) {
F_75 ( ! V_18 -> V_43 ) ;
V_18 -> V_43 = V_1 -> V_4 . V_44 ;
}
#endif
F_57 ( & V_18 -> V_43 -> V_31 ) ;
return V_18 -> V_106 ;
}
V_96 = V_18 -> V_106 ;
#ifdef F_85
if ( F_91 ( V_96 ) == V_18 ) {
F_75 ( ! ( V_18 -> V_45 & V_46 ) ) ;
F_91 ( V_96 ) = NULL ;
V_178 = V_180 ;
} else {
F_75 ( V_18 -> V_45 & V_46 ) ;
#endif
if ( V_96 -> V_104 == V_18 )
V_96 -> V_104 = V_179 ;
else if ( V_96 -> V_105 == V_18 )
V_96 -> V_105 = V_179 ;
#if V_170 >= 2
else
F_75 ( 1 ) ;
#endif
if ( V_179 )
V_179 -> V_106 = V_96 ;
V_178 = V_181 ;
#ifdef F_85
}
#endif
F_95 ( & V_1 -> V_4 . V_5 ) ;
F_96 (net, w) {
if ( ! V_179 ) {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_3 -> V_77 = NULL ;
F_52 ( L_7 , V_3 ) ;
} else if ( V_3 -> V_77 == V_18 ) {
F_52 ( L_8 , V_3 , V_3 -> V_75 , V_178 ) ;
V_3 -> V_77 = V_96 ;
V_3 -> V_75 = V_178 ;
}
} else {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_179 ;
F_52 ( L_9 , V_3 ) ;
}
if ( V_3 -> V_77 == V_18 ) {
V_3 -> V_77 = V_179 ;
if ( V_177 & 2 ) {
F_52 ( L_10 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_181 ? V_182 : V_76 ;
} else {
F_52 ( L_10 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_183 ? V_182 : V_76 ;
}
}
}
}
F_97 ( & V_1 -> V_4 . V_5 ) ;
F_13 ( V_18 ) ;
if ( V_96 -> V_45 & V_48 || F_91 ( V_96 ) )
return V_96 ;
F_21 ( V_96 -> V_43 ) ;
V_96 -> V_43 = NULL ;
V_18 = V_96 ;
}
}
static void F_98 ( struct V_17 * V_18 , struct V_21 * * V_184 ,
struct V_119 * V_120 )
{
struct V_2 * V_3 ;
struct V_21 * V_22 = * V_184 ;
struct V_1 * V_1 = V_120 -> V_151 ;
F_52 ( L_11 ) ;
* V_184 = V_22 -> V_23 . V_62 ;
V_22 -> V_148 = NULL ;
V_1 -> V_4 . V_152 -> V_153 -- ;
V_1 -> V_4 . V_152 -> V_185 ++ ;
if ( V_18 -> V_145 == V_22 )
V_18 -> V_145 = NULL ;
if ( V_22 -> V_63 ) {
struct V_21 * V_146 , * V_186 ;
F_73 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_146 -> V_63 -- ;
V_22 -> V_63 = 0 ;
F_99 ( & V_22 -> V_64 ) ;
}
F_95 ( & V_1 -> V_4 . V_5 ) ;
F_96 (net, w) {
if ( V_3 -> V_75 == V_183 && V_3 -> V_43 == V_22 ) {
F_52 ( L_12 , V_3 ) ;
V_3 -> V_43 = V_22 -> V_23 . V_62 ;
if ( ! V_3 -> V_43 )
V_3 -> V_75 = V_182 ;
}
}
F_97 ( & V_1 -> V_4 . V_5 ) ;
V_22 -> V_23 . V_62 = NULL ;
if ( ! V_18 -> V_43 ) {
V_18 -> V_45 &= ~ V_48 ;
V_1 -> V_4 . V_152 -> V_154 -- ;
V_18 = F_89 ( V_1 , V_18 ) ;
}
F_65 ( V_22 , V_18 , V_1 ) ;
if ( ! V_120 -> V_149 )
F_74 ( V_187 , V_22 , V_120 , 0 ) ;
F_21 ( V_22 ) ;
}
int F_100 ( struct V_21 * V_22 , struct V_119 * V_120 )
{
struct V_1 * V_1 = V_120 -> V_151 ;
struct V_17 * V_18 = V_22 -> V_148 ;
struct V_21 * * V_184 ;
#if V_170 >= 2
if ( V_22 -> V_23 . V_188 > 0 ) {
F_75 ( V_18 ) ;
return - V_102 ;
}
#endif
if ( ! V_18 || V_22 == V_1 -> V_4 . V_44 )
return - V_102 ;
F_75 ( ! ( V_18 -> V_45 & V_48 ) ) ;
if ( ! ( V_22 -> V_107 & V_157 ) ) {
struct V_17 * V_96 = V_18 ;
#ifdef F_85
if ( V_22 -> V_165 . V_89 ) {
while ( ! ( V_96 -> V_45 & V_46 ) )
V_96 = V_96 -> V_106 ;
V_96 = V_96 -> V_106 ;
}
#endif
F_86 ( V_120 -> V_151 , V_96 ) ;
}
for ( V_184 = & V_18 -> V_43 ; * V_184 ; V_184 = & ( * V_184 ) -> V_23 . V_62 ) {
if ( * V_184 == V_22 ) {
F_98 ( V_18 , V_184 , V_120 ) ;
return 0 ;
}
}
return - V_102 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_17 * V_18 , * V_96 ;
for (; ; ) {
V_18 = V_3 -> V_77 ;
if ( ! V_18 )
return 0 ;
if ( V_3 -> V_189 && V_18 != V_3 -> V_71 &&
V_18 -> V_45 & V_48 && V_3 -> V_75 < V_183 ) {
V_3 -> V_75 = V_183 ;
V_3 -> V_43 = V_18 -> V_43 ;
}
switch ( V_3 -> V_75 ) {
#ifdef F_85
case V_190 :
if ( F_91 ( V_18 ) ) {
V_3 -> V_77 = F_91 ( V_18 ) ;
continue;
}
V_3 -> V_75 = V_180 ;
#endif
case V_180 :
if ( V_18 -> V_105 ) {
V_3 -> V_77 = V_18 -> V_105 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_181 ;
case V_181 :
if ( V_18 -> V_104 ) {
V_3 -> V_77 = V_18 -> V_104 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_183 ;
V_3 -> V_43 = V_18 -> V_43 ;
case V_183 :
if ( V_3 -> V_43 && V_18 -> V_45 & V_48 ) {
int V_134 ;
if ( V_3 -> V_73 ) {
V_3 -> V_73 -- ;
goto V_73;
}
V_134 = V_3 -> V_84 ( V_3 ) ;
if ( V_134 )
return V_134 ;
V_3 -> V_72 ++ ;
continue;
}
V_73:
V_3 -> V_75 = V_182 ;
case V_182 :
if ( V_18 == V_3 -> V_71 )
return 0 ;
V_96 = V_18 -> V_106 ;
V_3 -> V_77 = V_96 ;
#ifdef F_85
if ( F_91 ( V_96 ) == V_18 ) {
F_75 ( ! ( V_18 -> V_45 & V_46 ) ) ;
V_3 -> V_75 = V_180 ;
continue;
}
#endif
if ( V_96 -> V_105 == V_18 ) {
V_3 -> V_75 = V_181 ;
continue;
}
if ( V_96 -> V_104 == V_18 ) {
V_3 -> V_75 = V_183 ;
V_3 -> V_43 = V_3 -> V_77 -> V_43 ;
continue;
}
#if V_170 >= 2
F_75 ( 1 ) ;
#endif
}
}
}
static int F_47 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_61 ;
V_3 -> V_75 = V_76 ;
V_3 -> V_77 = V_3 -> V_71 ;
F_1 ( V_1 , V_3 ) ;
V_61 = F_49 ( V_3 ) ;
if ( V_61 <= 0 )
F_5 ( V_1 , V_3 ) ;
return V_61 ;
}
static int F_101 ( struct V_2 * V_3 )
{
int V_61 ;
struct V_21 * V_22 ;
struct V_191 * V_192 = F_102 ( V_3 , struct V_191 , V_3 ) ;
struct V_119 V_120 = {
. V_151 = V_192 -> V_1 ,
} ;
if ( V_192 -> V_93 != V_193 &&
V_3 -> V_77 -> V_74 != V_192 -> V_93 )
V_3 -> V_77 -> V_74 = V_192 -> V_93 ;
if ( ! V_192 -> V_84 ) {
F_81 ( V_192 -> V_93 == V_193 ) ;
V_3 -> V_43 = NULL ;
return 0 ;
}
for ( V_22 = V_3 -> V_43 ; V_22 ; V_22 = V_22 -> V_23 . V_62 ) {
V_61 = V_192 -> V_84 ( V_22 , V_192 -> V_82 ) ;
if ( V_61 < 0 ) {
V_3 -> V_43 = V_22 ;
V_61 = F_100 ( V_22 , & V_120 ) ;
if ( V_61 ) {
#if V_170 >= 2
F_103 ( L_13 ,
V_194 , V_22 , V_22 -> V_148 , V_61 ) ;
#endif
continue;
}
return 0 ;
}
F_75 ( V_61 != 0 ) ;
}
V_3 -> V_43 = V_22 ;
return 0 ;
}
static void F_104 ( struct V_1 * V_1 , struct V_17 * V_71 ,
int (* V_84)( struct V_21 * , void * V_82 ) ,
bool V_189 , int V_93 , void * V_82 )
{
struct V_191 V_192 ;
V_192 . V_3 . V_71 = V_71 ;
V_192 . V_3 . V_84 = F_101 ;
V_192 . V_3 . V_189 = V_189 ;
V_192 . V_3 . V_72 = 0 ;
V_192 . V_3 . V_73 = 0 ;
V_192 . V_84 = V_84 ;
V_192 . V_93 = V_93 ;
V_192 . V_82 = V_82 ;
V_192 . V_1 = V_1 ;
F_47 ( V_1 , & V_192 . V_3 ) ;
}
static void F_105 ( struct V_1 * V_1 ,
int (* V_84)( struct V_21 * , void * ) ,
int V_93 , void * V_82 )
{
struct V_32 * V_41 ;
struct V_51 * V_52 ;
unsigned int V_34 ;
F_31 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
V_52 = & V_1 -> V_4 . V_39 [ V_34 ] ;
F_32 (table, head, tb6_hlist) {
F_2 ( & V_41 -> V_35 ) ;
F_104 ( V_1 , & V_41 -> V_42 ,
V_84 , false , V_93 , V_82 ) ;
F_4 ( & V_41 -> V_35 ) ;
}
}
F_33 () ;
}
void F_106 ( struct V_1 * V_1 , int (* V_84)( struct V_21 * , void * ) ,
void * V_82 )
{
F_105 ( V_1 , V_84 , V_193 , V_82 ) ;
}
static int F_107 ( struct V_21 * V_22 , void * V_82 )
{
if ( V_22 -> V_107 & V_157 ) {
F_52 ( L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_86 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
F_104 ( V_1 , V_18 , F_107 , true ,
V_193 , NULL ) ;
}
static void F_108 ( struct V_1 * V_1 )
{
int V_195 = F_7 ( V_1 ) ;
F_105 ( V_1 , NULL , V_195 , NULL ) ;
}
static int F_109 ( struct V_21 * V_22 , void * V_82 )
{
struct V_196 * V_197 = V_82 ;
unsigned long V_198 = V_158 ;
if ( V_22 -> V_107 & V_142 && V_22 -> V_23 . V_143 ) {
if ( F_110 ( V_198 , V_22 -> V_23 . V_143 ) ) {
F_52 ( L_15 , V_22 ) ;
return - 1 ;
}
V_197 -> V_199 ++ ;
} else if ( V_22 -> V_107 & V_157 ) {
if ( F_8 ( & V_22 -> V_23 . V_162 ) == 0 &&
F_111 ( V_198 , V_22 -> V_23 . V_200 + V_197 -> V_201 ) ) {
F_52 ( L_16 , V_22 ) ;
return - 1 ;
} else if ( V_22 -> V_107 & V_108 ) {
struct V_202 * V_203 ;
T_6 V_204 = 0 ;
V_203 = F_112 ( & V_22 -> V_23 , & V_22 -> V_141 ) ;
if ( V_203 ) {
V_204 = V_203 -> V_58 ;
F_113 ( V_203 ) ;
}
if ( ! ( V_204 & V_205 ) ) {
F_52 ( L_17 ,
V_22 ) ;
return - 1 ;
}
}
V_197 -> V_199 ++ ;
}
return 0 ;
}
void F_114 ( unsigned long V_143 , struct V_1 * V_1 , bool V_206 )
{
struct V_196 V_197 ;
unsigned long V_198 ;
if ( V_206 ) {
F_115 ( & V_1 -> V_4 . V_207 ) ;
} else if ( ! F_116 ( & V_1 -> V_4 . V_207 ) ) {
F_78 ( & V_1 -> V_4 . V_156 , V_158 + V_208 ) ;
return;
}
V_197 . V_201 = V_143 ? ( int ) V_143 :
V_1 -> V_4 . V_159 . V_160 ;
V_197 . V_199 = F_117 () ;
F_106 ( V_1 , F_109 , & V_197 ) ;
V_198 = V_158 ;
V_1 -> V_4 . V_209 = V_198 ;
if ( V_197 . V_199 )
F_78 ( & V_1 -> V_4 . V_156 ,
F_118 ( V_198
+ V_1 -> V_4 . V_159 . V_160 ) ) ;
else
F_119 ( & V_1 -> V_4 . V_156 ) ;
F_120 ( & V_1 -> V_4 . V_207 ) ;
}
static void F_121 ( unsigned long V_82 )
{
F_114 ( 0 , (struct V_1 * ) V_82 , true ) ;
}
static int T_3 F_122 ( struct V_1 * V_1 )
{
T_7 V_210 = sizeof( struct V_51 ) * V_37 ;
F_123 ( & V_1 -> V_4 . V_207 ) ;
F_24 ( & V_1 -> V_4 . V_5 ) ;
F_124 ( & V_1 -> V_4 . V_7 ) ;
F_125 ( & V_1 -> V_4 . V_156 , F_121 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 . V_152 = F_27 ( sizeof( * V_1 -> V_4 . V_152 ) , V_211 ) ;
if ( ! V_1 -> V_4 . V_152 )
goto V_212;
V_210 = F_126 ( T_7 , V_210 , V_213 ) ;
V_1 -> V_4 . V_39 = F_27 ( V_210 , V_211 ) ;
if ( ! V_1 -> V_4 . V_39 )
goto V_214;
V_1 -> V_4 . V_53 = F_27 ( sizeof( * V_1 -> V_4 . V_53 ) ,
V_211 ) ;
if ( ! V_1 -> V_4 . V_53 )
goto V_215;
V_1 -> V_4 . V_53 -> V_36 = V_50 ;
V_1 -> V_4 . V_53 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_53 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
#ifdef F_127
V_1 -> V_4 . V_54 = F_27 ( sizeof( * V_1 -> V_4 . V_54 ) ,
V_211 ) ;
if ( ! V_1 -> V_4 . V_54 )
goto V_216;
V_1 -> V_4 . V_54 -> V_36 = V_217 ;
V_1 -> V_4 . V_54 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_54 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
#endif
F_34 ( V_1 ) ;
return 0 ;
#ifdef F_127
V_216:
F_43 ( V_1 -> V_4 . V_53 ) ;
#endif
V_215:
F_43 ( V_1 -> V_4 . V_39 ) ;
V_214:
F_43 ( V_1 -> V_4 . V_152 ) ;
V_212:
return - V_83 ;
}
static void F_128 ( struct V_1 * V_1 )
{
F_129 ( V_1 , NULL ) ;
F_130 ( & V_1 -> V_4 . V_156 ) ;
#ifdef F_127
F_131 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
F_43 ( V_1 -> V_4 . V_54 ) ;
#endif
F_131 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
F_43 ( V_1 -> V_4 . V_53 ) ;
F_43 ( V_1 -> V_4 . V_39 ) ;
F_43 ( V_1 -> V_4 . V_152 ) ;
}
int T_8 F_132 ( void )
{
int V_218 = - V_83 ;
V_19 = F_133 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_219 ,
NULL ) ;
if ( ! V_19 )
goto V_86;
V_218 = F_134 ( & V_220 ) ;
if ( V_218 )
goto V_221;
V_218 = F_135 ( V_222 , V_223 , NULL , F_50 ,
NULL ) ;
if ( V_218 )
goto V_224;
V_225 = F_108 ;
V_86:
return V_218 ;
V_224:
F_136 ( & V_220 ) ;
V_221:
F_137 ( V_19 ) ;
goto V_86;
}
void F_138 ( void )
{
F_136 ( & V_220 ) ;
F_137 ( V_19 ) ;
}
static int F_139 ( struct V_226 * V_227 , void * V_228 )
{
struct V_21 * V_22 = V_228 ;
struct V_229 * V_121 = V_227 -> V_230 ;
F_140 ( V_227 , L_19 , & V_22 -> V_164 . V_14 , V_22 -> V_164 . V_89 ) ;
#ifdef F_85
F_140 ( V_227 , L_19 , & V_22 -> V_165 . V_14 , V_22 -> V_165 . V_89 ) ;
#else
F_141 ( V_227 , L_20 ) ;
#endif
if ( V_22 -> V_107 & V_108 )
F_140 ( V_227 , L_21 , & V_22 -> V_141 ) ;
else
F_141 ( V_227 , L_22 ) ;
F_140 ( V_227 , L_23 ,
V_22 -> V_136 , F_8 ( & V_22 -> V_23 . V_162 ) ,
V_22 -> V_23 . V_231 , V_22 -> V_107 ,
V_22 -> V_23 . V_139 ? V_22 -> V_23 . V_139 -> V_232 : L_24 ) ;
V_121 -> V_3 . V_43 = NULL ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_229 * V_121 = V_3 -> args ;
if ( ! V_121 -> V_73 )
return 1 ;
do {
V_121 -> V_3 . V_43 = V_121 -> V_3 . V_43 -> V_23 . V_62 ;
V_121 -> V_73 -- ;
if ( ! V_121 -> V_73 && V_121 -> V_3 . V_43 )
return 1 ;
} while ( V_121 -> V_3 . V_43 );
return 0 ;
}
static void F_143 ( struct V_229 * V_121 ,
struct V_1 * V_1 )
{
memset ( & V_121 -> V_3 , 0 , sizeof( V_121 -> V_3 ) ) ;
V_121 -> V_3 . V_84 = F_142 ;
V_121 -> V_3 . V_71 = & V_121 -> V_233 -> V_42 ;
V_121 -> V_3 . V_75 = V_76 ;
V_121 -> V_3 . V_77 = V_121 -> V_3 . V_71 ;
V_121 -> V_3 . args = V_121 ;
V_121 -> V_93 = V_121 -> V_3 . V_71 -> V_74 ;
F_124 ( & V_121 -> V_3 . V_6 ) ;
F_1 ( V_1 , & V_121 -> V_3 ) ;
}
static struct V_32 * F_144 ( struct V_32 * V_233 ,
struct V_1 * V_1 )
{
unsigned int V_34 ;
struct V_234 * V_77 ;
if ( V_233 ) {
V_34 = ( V_233 -> V_36 & ( V_37 - 1 ) ) + 1 ;
V_77 = F_145 ( F_146 ( & V_233 -> V_38 ) ) ;
} else {
V_34 = 0 ;
V_77 = NULL ;
}
while ( ! V_77 && V_34 < V_37 ) {
V_77 = F_145 (
F_147 ( & V_1 -> V_4 . V_39 [ V_34 ++ ] ) ) ;
}
return F_148 ( V_77 , struct V_32 , V_38 ) ;
}
static void F_149 ( struct V_229 * V_121 )
{
if ( V_121 -> V_93 != V_121 -> V_3 . V_71 -> V_74 ) {
V_121 -> V_93 = V_121 -> V_3 . V_71 -> V_74 ;
V_121 -> V_3 . V_75 = V_76 ;
V_121 -> V_3 . V_77 = V_121 -> V_3 . V_71 ;
F_75 ( V_121 -> V_3 . V_73 ) ;
V_121 -> V_3 . V_73 = V_121 -> V_3 . V_72 ;
}
}
static void * F_150 ( struct V_226 * V_227 , void * V_228 , T_9 * V_235 )
{
int V_236 ;
struct V_21 * V_237 ;
struct V_1 * V_1 = F_151 ( V_227 ) ;
struct V_229 * V_121 = V_227 -> V_230 ;
if ( ! V_228 )
goto V_238;
V_237 = ( (struct V_21 * ) V_228 ) -> V_23 . V_62 ;
if ( V_237 ) {
++ * V_235 ;
return V_237 ;
}
V_238:
F_149 ( V_121 ) ;
F_95 ( & V_121 -> V_233 -> V_35 ) ;
V_236 = F_49 ( & V_121 -> V_3 ) ;
F_97 ( & V_121 -> V_233 -> V_35 ) ;
if ( V_236 > 0 ) {
if ( V_228 )
++ * V_235 ;
return V_121 -> V_3 . V_43 ;
} else if ( V_236 < 0 ) {
F_5 ( V_1 , & V_121 -> V_3 ) ;
return NULL ;
}
F_5 ( V_1 , & V_121 -> V_3 ) ;
V_121 -> V_233 = F_144 ( V_121 -> V_233 , V_1 ) ;
if ( ! V_121 -> V_233 )
return NULL ;
F_143 ( V_121 , V_1 ) ;
goto V_238;
}
static void * F_152 ( struct V_226 * V_227 , T_9 * V_235 )
__acquires( T_10 )
{
struct V_1 * V_1 = F_151 ( V_227 ) ;
struct V_229 * V_121 = V_227 -> V_230 ;
F_153 () ;
V_121 -> V_233 = F_144 ( NULL , V_1 ) ;
V_121 -> V_73 = * V_235 ;
if ( V_121 -> V_233 ) {
F_143 ( V_121 , V_1 ) ;
return F_150 ( V_227 , NULL , V_235 ) ;
} else {
return NULL ;
}
}
static bool F_154 ( struct V_229 * V_121 )
{
struct V_2 * V_3 = & V_121 -> V_3 ;
return V_3 -> V_77 && ! ( V_3 -> V_75 == V_182 && V_3 -> V_77 == V_3 -> V_71 ) ;
}
static void F_155 ( struct V_226 * V_227 , void * V_228 )
__releases( T_10 )
{
struct V_1 * V_1 = F_151 ( V_227 ) ;
struct V_229 * V_121 = V_227 -> V_230 ;
if ( F_154 ( V_121 ) )
F_5 ( V_1 , & V_121 -> V_3 ) ;
F_156 () ;
}
int F_157 ( struct V_239 * V_239 , struct V_240 * V_240 )
{
return F_158 ( V_239 , V_240 , & V_241 ,
sizeof( struct V_229 ) ) ;
}
