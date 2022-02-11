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
if ( V_22 -> V_60 & V_61 &&
V_22 -> V_23 . error == - V_62 ) {
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
int V_63 ;
struct V_21 * V_22 ;
for ( V_22 = V_3 -> V_43 ; V_22 ; V_22 = V_22 -> V_23 . V_64 ) {
V_63 = F_39 ( V_22 , V_3 -> args ) ;
if ( V_63 < 0 ) {
V_3 -> V_43 = V_22 ;
return 1 ;
}
}
V_3 -> V_43 = NULL ;
return 0 ;
}
static void F_40 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_41 ( V_66 -> V_67 -> V_68 ) ;
struct V_2 * V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( V_3 ) {
if ( V_66 -> args [ 4 ] ) {
V_66 -> args [ 4 ] = 0 ;
F_5 ( V_1 , V_3 ) ;
}
V_66 -> args [ 2 ] = 0 ;
F_42 ( V_3 ) ;
}
V_66 -> V_69 = ( void * ) V_66 -> args [ 3 ] ;
V_66 -> args [ 1 ] = 3 ;
}
static int F_43 ( struct V_65 * V_66 )
{
F_40 ( V_66 ) ;
return V_66 -> V_69 ? V_66 -> V_69 ( V_66 ) : 0 ;
}
static int F_44 ( struct V_32 * V_41 , struct V_70 * V_67 ,
struct V_65 * V_66 )
{
struct V_1 * V_1 = F_41 ( V_67 -> V_68 ) ;
struct V_2 * V_3 ;
int V_63 ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
V_3 -> V_71 = & V_41 -> V_42 ;
if ( V_66 -> args [ 4 ] == 0 ) {
V_3 -> V_72 = 0 ;
V_3 -> V_73 = 0 ;
F_45 ( & V_41 -> V_35 ) ;
V_63 = F_46 ( V_1 , V_3 ) ;
F_47 ( & V_41 -> V_35 ) ;
if ( V_63 > 0 ) {
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
F_45 ( & V_41 -> V_35 ) ;
V_63 = F_48 ( V_3 ) ;
F_47 ( & V_41 -> V_35 ) ;
if ( V_63 <= 0 ) {
F_5 ( V_1 , V_3 ) ;
V_66 -> args [ 4 ] = 0 ;
}
}
return V_63 ;
}
static int F_49 ( struct V_70 * V_67 , struct V_65 * V_66 )
{
struct V_1 * V_1 = F_41 ( V_67 -> V_68 ) ;
unsigned int V_34 , V_78 ;
unsigned int V_79 = 0 , V_80 ;
struct V_81 V_82 ;
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
int V_63 = 0 ;
V_78 = V_66 -> args [ 0 ] ;
V_80 = V_66 -> args [ 1 ] ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( ! V_3 ) {
V_66 -> args [ 3 ] = ( long ) V_66 -> V_69 ;
V_66 -> V_69 = F_43 ;
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
V_63 = F_44 ( V_33 , V_67 , V_66 ) ;
if ( V_63 != 0 )
goto V_86;
V_85:
V_79 ++ ;
}
}
V_86:
F_33 () ;
V_66 -> args [ 1 ] = V_79 ;
V_66 -> args [ 0 ] = V_34 ;
V_63 = V_63 < 0 ? V_63 : V_67 -> V_87 ;
if ( V_63 <= 0 )
F_40 ( V_66 ) ;
return V_63 ;
}
static struct V_17 * F_50 ( struct V_17 * V_71 ,
struct V_88 * V_14 , int V_89 ,
int V_90 , int V_91 ,
int V_92 , int V_93 )
{
struct V_17 * V_18 , * V_94 , * V_95 ;
struct V_17 * V_96 = NULL ;
struct V_97 * V_98 ;
int V_99 ;
T_1 V_100 = 0 ;
F_51 ( L_1 ) ;
V_18 = V_71 ;
do {
V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_52 ( & V_98 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_91 ) {
if ( V_92 ) {
F_53 ( L_2 ) ;
return F_54 ( - V_102 ) ;
}
F_53 ( L_3 ) ;
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
F_53 ( L_2 ) ;
return F_54 ( - V_102 ) ;
}
F_53 ( L_3 ) ;
}
V_95 = F_11 () ;
if ( ! V_95 )
return F_54 ( - V_83 ) ;
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
V_99 = F_55 ( V_14 , & V_98 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_89 > V_99 ) {
V_94 = F_11 () ;
V_95 = F_11 () ;
if ( ! V_94 || ! V_95 ) {
if ( V_94 )
F_13 ( V_94 ) ;
if ( V_95 )
F_13 ( V_95 ) ;
return F_54 ( - V_83 ) ;
}
V_94 -> V_13 = V_99 ;
V_94 -> V_106 = V_96 ;
V_94 -> V_43 = V_18 -> V_43 ;
F_56 ( & V_94 -> V_43 -> V_31 ) ;
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
return F_54 ( - V_83 ) ;
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
static bool F_57 ( struct V_21 * V_22 )
{
return ( V_22 -> V_60 & ( V_107 | V_108 | V_109 ) ) ==
V_107 ;
}
static void F_58 ( T_2 * V_110 , const struct V_111 * V_112 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
if ( F_59 ( V_113 , V_112 -> V_115 ) )
V_110 [ V_113 ] = V_112 -> V_116 [ V_113 ] ;
}
}
static int F_60 ( struct V_55 * V_23 , struct V_111 * V_112 )
{
if ( ! V_112 -> V_116 )
return 0 ;
if ( V_23 -> V_58 & V_117 ) {
T_2 * V_110 = F_61 ( V_23 ) ;
if ( F_62 ( ! V_110 ) )
return - V_83 ;
F_58 ( V_110 , V_112 ) ;
} else {
F_63 ( V_23 , V_112 -> V_116 , false ) ;
V_112 -> V_116 = NULL ;
}
return 0 ;
}
static void F_64 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_1 * V_1 )
{
if ( F_8 ( & V_22 -> V_31 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_45 & V_48 ) && V_18 -> V_43 == V_22 ) {
V_18 -> V_43 = F_65 ( V_1 , V_18 ) ;
F_56 ( & V_18 -> V_43 -> V_31 ) ;
F_21 ( V_22 ) ;
}
V_18 = V_18 -> V_106 ;
}
F_66 ( F_8 ( & V_22 -> V_31 ) != 1 ) ;
}
}
static int F_67 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_118 * V_119 , struct V_111 * V_112 )
{
struct V_21 * V_120 = NULL ;
struct V_21 * * V_121 ;
struct V_21 * * V_122 = NULL ;
int V_123 = ( V_119 -> V_124 &&
( V_119 -> V_124 -> V_125 & V_126 ) ) ;
int V_127 = ( ! V_119 -> V_124 ||
( V_119 -> V_124 -> V_125 & V_128 ) ) ;
int V_129 = 0 ;
bool V_130 = F_57 ( V_22 ) ;
T_5 V_131 = V_132 ;
int V_133 ;
V_121 = & V_18 -> V_43 ;
for ( V_120 = V_18 -> V_43 ; V_120 ; V_120 = V_120 -> V_23 . V_64 ) {
if ( V_120 -> V_134 == V_22 -> V_134 ) {
if ( V_119 -> V_124 &&
( V_119 -> V_124 -> V_125 & V_132 ) )
return - V_135 ;
V_131 &= ~ V_132 ;
if ( V_123 ) {
if ( V_130 == F_57 ( V_120 ) ) {
V_129 ++ ;
break;
}
if ( V_130 )
V_122 = V_122 ? : V_121 ;
goto V_136;
}
if ( V_120 -> V_23 . V_137 == V_22 -> V_23 . V_137 &&
V_120 -> V_138 == V_22 -> V_138 &&
F_68 ( & V_120 -> V_139 ,
& V_22 -> V_139 ) ) {
if ( V_22 -> V_140 )
V_22 -> V_140 = 0 ;
if ( ! ( V_120 -> V_60 & V_141 ) )
return - V_135 ;
if ( ! ( V_22 -> V_60 & V_141 ) )
F_69 ( V_120 ) ;
else
F_70 ( V_120 , V_22 -> V_23 . V_142 ) ;
V_120 -> V_143 = V_22 -> V_143 ;
return - V_135 ;
}
if ( V_130 &&
F_57 ( V_120 ) )
V_22 -> V_140 ++ ;
}
if ( V_120 -> V_134 > V_22 -> V_134 )
break;
V_136:
V_121 = & V_120 -> V_23 . V_64 ;
}
if ( V_122 && ! V_129 ) {
V_121 = V_122 ;
V_120 = * V_121 ;
V_129 ++ ;
}
if ( V_121 == & V_18 -> V_43 )
V_18 -> V_144 = NULL ;
if ( V_22 -> V_140 ) {
unsigned int V_140 ;
struct V_21 * V_145 , * V_146 ;
V_145 = V_18 -> V_43 ;
while ( V_145 ) {
if ( V_145 -> V_134 == V_22 -> V_134 &&
F_57 ( V_145 ) ) {
F_71 ( & V_22 -> V_147 ,
& V_145 -> V_147 ) ;
break;
}
V_145 = V_145 -> V_23 . V_64 ;
}
V_140 = 0 ;
F_72 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_145 -> V_140 ++ ;
F_66 ( V_145 -> V_140 != V_22 -> V_140 ) ;
V_140 ++ ;
}
F_66 ( V_140 != V_22 -> V_140 ) ;
}
if ( ! V_123 ) {
if ( ! V_127 )
F_53 ( L_3 ) ;
V_127:
V_131 |= V_128 ;
V_133 = F_60 ( & V_22 -> V_23 , V_112 ) ;
if ( V_133 )
return V_133 ;
V_22 -> V_23 . V_64 = V_120 ;
* V_121 = V_22 ;
V_22 -> V_148 = V_18 ;
F_56 ( & V_22 -> V_31 ) ;
F_73 ( V_149 , V_22 , V_119 , V_131 ) ;
V_119 -> V_150 -> V_4 . V_151 -> V_152 ++ ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_119 -> V_150 -> V_4 . V_151 -> V_153 ++ ;
V_18 -> V_45 |= V_48 ;
}
} else {
int V_154 ;
if ( ! V_129 ) {
if ( V_127 )
goto V_127;
F_53 ( L_4 ) ;
return - V_102 ;
}
V_133 = F_60 ( & V_22 -> V_23 , V_112 ) ;
if ( V_133 )
return V_133 ;
* V_121 = V_22 ;
V_22 -> V_148 = V_18 ;
V_22 -> V_23 . V_64 = V_120 -> V_23 . V_64 ;
F_56 ( & V_22 -> V_31 ) ;
F_73 ( V_149 , V_22 , V_119 , V_126 ) ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_119 -> V_150 -> V_4 . V_151 -> V_153 ++ ;
V_18 -> V_45 |= V_48 ;
}
V_154 = V_120 -> V_140 ;
F_64 ( V_120 , V_18 , V_119 -> V_150 ) ;
F_21 ( V_120 ) ;
if ( V_154 ) {
V_121 = & V_22 -> V_23 . V_64 ;
V_120 = * V_121 ;
while ( V_120 ) {
if ( F_57 ( V_120 ) ) {
* V_121 = V_120 -> V_23 . V_64 ;
F_64 ( V_120 , V_18 , V_119 -> V_150 ) ;
F_21 ( V_120 ) ;
V_154 -- ;
} else {
V_121 = & V_120 -> V_23 . V_64 ;
}
V_120 = * V_121 ;
}
F_74 ( V_154 != 0 ) ;
}
}
return 0 ;
}
static void F_75 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
if ( ! F_76 ( & V_1 -> V_4 . V_155 ) &&
( V_22 -> V_60 & ( V_141 | V_156 ) ) )
F_77 ( & V_1 -> V_4 . V_155 ,
V_157 + V_1 -> V_4 . V_158 . V_159 ) ;
}
void F_78 ( struct V_1 * V_1 )
{
if ( ! F_76 ( & V_1 -> V_4 . V_155 ) )
F_77 ( & V_1 -> V_4 . V_155 ,
V_157 + V_1 -> V_4 . V_158 . V_159 ) ;
}
int F_79 ( struct V_17 * V_71 , struct V_21 * V_22 ,
struct V_118 * V_119 , struct V_111 * V_112 )
{
struct V_17 * V_18 , * V_96 = NULL ;
int V_133 = - V_83 ;
int V_91 = 1 ;
int V_92 = 0 ;
int V_93 = F_7 ( V_119 -> V_150 ) ;
if ( F_80 ( ( V_22 -> V_23 . V_58 & V_160 ) &&
! F_8 ( & V_22 -> V_23 . V_161 ) ) )
return - V_162 ;
if ( V_119 -> V_124 ) {
if ( ! ( V_119 -> V_124 -> V_125 & V_128 ) )
V_91 = 0 ;
if ( V_119 -> V_124 -> V_125 & V_126 )
V_92 = 1 ;
}
if ( ! V_91 && ! V_92 )
F_53 ( L_5 ) ;
V_18 = F_50 ( V_71 , & V_22 -> V_163 . V_14 , V_22 -> V_163 . V_89 ,
F_81 ( struct V_21 , V_163 ) , V_91 ,
V_92 , V_93 ) ;
if ( F_82 ( V_18 ) ) {
V_133 = F_83 ( V_18 ) ;
V_18 = NULL ;
goto V_86;
}
V_96 = V_18 ;
#ifdef F_84
if ( V_22 -> V_164 . V_89 ) {
struct V_17 * V_165 ;
if ( ! V_18 -> V_166 ) {
struct V_17 * V_167 ;
V_167 = F_11 () ;
if ( ! V_167 )
goto V_168;
V_167 -> V_43 = V_119 -> V_150 -> V_4 . V_44 ;
F_56 ( & V_119 -> V_150 -> V_4 . V_44 -> V_31 ) ;
V_167 -> V_45 = V_46 ;
V_167 -> V_74 = V_93 ;
V_165 = F_50 ( V_167 , & V_22 -> V_164 . V_14 ,
V_22 -> V_164 . V_89 ,
F_81 ( struct V_21 , V_164 ) ,
V_91 , V_92 , V_93 ) ;
if ( F_82 ( V_165 ) ) {
F_13 ( V_167 ) ;
V_133 = F_83 ( V_165 ) ;
goto V_168;
}
V_167 -> V_106 = V_18 ;
V_18 -> V_166 = V_167 ;
} else {
V_165 = F_50 ( V_18 -> V_166 , & V_22 -> V_164 . V_14 ,
V_22 -> V_164 . V_89 ,
F_81 ( struct V_21 , V_164 ) ,
V_91 , V_92 , V_93 ) ;
if ( F_82 ( V_165 ) ) {
V_133 = F_83 ( V_165 ) ;
goto V_168;
}
}
if ( ! V_18 -> V_43 ) {
V_18 -> V_43 = V_22 ;
F_56 ( & V_22 -> V_31 ) ;
}
V_18 = V_165 ;
}
#endif
V_133 = F_67 ( V_18 , V_22 , V_119 , V_112 ) ;
if ( ! V_133 ) {
F_75 ( V_119 -> V_150 , V_22 ) ;
if ( ! ( V_22 -> V_60 & V_156 ) )
F_85 ( V_119 -> V_150 , V_96 ) ;
V_22 -> V_23 . V_58 &= ~ V_160 ;
}
V_86:
if ( V_133 ) {
#ifdef F_84
if ( V_96 != V_18 && V_96 -> V_43 == V_22 ) {
V_96 -> V_43 = NULL ;
F_86 ( & V_22 -> V_31 ) ;
}
if ( V_96 != V_18 && ! V_96 -> V_43 && ! ( V_96 -> V_45 & V_48 ) ) {
V_96 -> V_43 = F_65 ( V_119 -> V_150 , V_96 ) ;
#if V_169 >= 2
if ( ! V_96 -> V_43 ) {
F_74 ( V_96 -> V_43 == NULL ) ;
V_96 -> V_43 = V_119 -> V_150 -> V_4 . V_44 ;
}
#endif
F_56 ( & V_96 -> V_43 -> V_31 ) ;
}
#endif
if ( ! ( V_22 -> V_23 . V_58 & V_160 ) )
F_87 ( & V_22 -> V_23 ) ;
}
return V_133 ;
#ifdef F_84
V_168:
if ( V_18 && ! ( V_18 -> V_45 & ( V_48 | V_46 ) ) )
F_88 ( V_119 -> V_150 , V_18 ) ;
if ( ! ( V_22 -> V_23 . V_58 & V_160 ) )
F_87 ( & V_22 -> V_23 ) ;
return V_133 ;
#endif
}
static struct V_17 * F_89 ( struct V_17 * V_71 ,
struct V_170 * args )
{
struct V_17 * V_18 ;
T_1 V_100 ;
if ( F_62 ( args -> V_90 == 0 ) )
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
if ( F_90 ( V_18 ) || V_18 -> V_45 & V_48 ) {
struct V_97 * V_98 ;
V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 +
args -> V_90 ) ;
if ( F_52 ( & V_98 -> V_14 , args -> V_14 , V_98 -> V_89 ) ) {
#ifdef F_84
if ( V_18 -> V_166 ) {
struct V_17 * V_167 ;
V_167 = F_89 ( V_18 -> V_166 ,
args + 1 ) ;
if ( ! V_167 )
goto V_171;
V_18 = V_167 ;
}
#endif
if ( V_18 -> V_45 & V_48 )
return V_18 ;
}
}
#ifdef F_84
V_171:
#endif
if ( V_18 -> V_45 & V_46 )
break;
V_18 = V_18 -> V_106 ;
}
return NULL ;
}
struct V_17 * F_91 ( struct V_17 * V_71 , const struct V_88 * V_172 ,
const struct V_88 * V_173 )
{
struct V_17 * V_18 ;
struct V_170 args [] = {
{
. V_90 = F_81 ( struct V_21 , V_163 ) ,
. V_14 = V_172 ,
} ,
#ifdef F_84
{
. V_90 = F_81 ( struct V_21 , V_164 ) ,
. V_14 = V_173 ,
} ,
#endif
{
. V_90 = 0 ,
}
} ;
V_18 = F_89 ( V_71 , V_172 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_45 & V_47 )
V_18 = V_71 ;
return V_18 ;
}
static struct V_17 * F_92 ( struct V_17 * V_71 ,
const struct V_88 * V_14 ,
int V_89 , int V_90 )
{
struct V_17 * V_18 ;
for ( V_18 = V_71 ; V_18 ; ) {
struct V_97 * V_98 = (struct V_97 * ) ( ( V_101 * ) V_18 -> V_43 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_52 ( & V_98 -> V_14 , V_14 , V_18 -> V_13 ) )
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
struct V_17 * F_93 ( struct V_17 * V_71 ,
const struct V_88 * V_172 , int V_174 ,
const struct V_88 * V_173 , int V_175 )
{
struct V_17 * V_18 ;
V_18 = F_92 ( V_71 , V_172 , V_174 ,
F_81 ( struct V_21 , V_163 ) ) ;
#ifdef F_84
if ( V_175 ) {
F_74 ( V_173 == NULL ) ;
if ( V_18 && V_18 -> V_166 )
V_18 = F_92 ( V_18 -> V_166 , V_173 , V_175 ,
F_81 ( struct V_21 , V_164 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_45 & V_48 )
return V_18 ;
return NULL ;
}
static struct V_21 * F_65 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
if ( V_18 -> V_45 & V_46 )
return V_1 -> V_4 . V_44 ;
while ( V_18 ) {
if ( V_18 -> V_105 )
return V_18 -> V_105 -> V_43 ;
if ( V_18 -> V_104 )
return V_18 -> V_104 -> V_43 ;
V_18 = F_90 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_88 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
int V_176 ;
int V_177 ;
struct V_17 * V_178 , * V_96 ;
struct V_2 * V_3 ;
int V_120 = 0 ;
for (; ; ) {
F_51 ( L_6 , V_18 -> V_13 , V_120 ) ;
V_120 ++ ;
F_74 ( V_18 -> V_45 & V_48 ) ;
F_74 ( V_18 -> V_45 & V_47 ) ;
F_74 ( V_18 -> V_43 ) ;
V_176 = 0 ;
V_178 = NULL ;
if ( V_18 -> V_104 )
V_178 = V_18 -> V_104 , V_176 |= 1 ;
if ( V_18 -> V_105 )
V_178 = V_18 -> V_105 , V_176 |= 2 ;
if ( V_176 == 3 || F_90 ( V_18 )
#ifdef F_84
|| ( V_176 && V_18 -> V_45 & V_46 )
#endif
) {
V_18 -> V_43 = F_65 ( V_1 , V_18 ) ;
#if V_169 >= 2
if ( ! V_18 -> V_43 ) {
F_74 ( ! V_18 -> V_43 ) ;
V_18 -> V_43 = V_1 -> V_4 . V_44 ;
}
#endif
F_56 ( & V_18 -> V_43 -> V_31 ) ;
return V_18 -> V_106 ;
}
V_96 = V_18 -> V_106 ;
#ifdef F_84
if ( F_90 ( V_96 ) == V_18 ) {
F_74 ( ! ( V_18 -> V_45 & V_46 ) ) ;
F_90 ( V_96 ) = NULL ;
V_177 = V_179 ;
} else {
F_74 ( V_18 -> V_45 & V_46 ) ;
#endif
if ( V_96 -> V_104 == V_18 )
V_96 -> V_104 = V_178 ;
else if ( V_96 -> V_105 == V_18 )
V_96 -> V_105 = V_178 ;
#if V_169 >= 2
else
F_74 ( 1 ) ;
#endif
if ( V_178 )
V_178 -> V_106 = V_96 ;
V_177 = V_180 ;
#ifdef F_84
}
#endif
F_94 ( & V_1 -> V_4 . V_5 ) ;
F_95 (net, w) {
if ( ! V_178 ) {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_3 -> V_77 = NULL ;
F_51 ( L_7 , V_3 ) ;
} else if ( V_3 -> V_77 == V_18 ) {
F_51 ( L_8 , V_3 , V_3 -> V_75 , V_177 ) ;
V_3 -> V_77 = V_96 ;
V_3 -> V_75 = V_177 ;
}
} else {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_178 ;
F_51 ( L_9 , V_3 ) ;
}
if ( V_3 -> V_77 == V_18 ) {
V_3 -> V_77 = V_178 ;
if ( V_176 & 2 ) {
F_51 ( L_10 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_180 ? V_181 : V_76 ;
} else {
F_51 ( L_10 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_182 ? V_181 : V_76 ;
}
}
}
}
F_96 ( & V_1 -> V_4 . V_5 ) ;
F_13 ( V_18 ) ;
if ( V_96 -> V_45 & V_48 || F_90 ( V_96 ) )
return V_96 ;
F_21 ( V_96 -> V_43 ) ;
V_96 -> V_43 = NULL ;
V_18 = V_96 ;
}
}
static void F_97 ( struct V_17 * V_18 , struct V_21 * * V_183 ,
struct V_118 * V_119 )
{
struct V_2 * V_3 ;
struct V_21 * V_22 = * V_183 ;
struct V_1 * V_1 = V_119 -> V_150 ;
F_51 ( L_11 ) ;
* V_183 = V_22 -> V_23 . V_64 ;
V_22 -> V_148 = NULL ;
V_1 -> V_4 . V_151 -> V_152 -- ;
V_1 -> V_4 . V_151 -> V_184 ++ ;
if ( V_18 -> V_144 == V_22 )
V_18 -> V_144 = NULL ;
if ( V_22 -> V_140 ) {
struct V_21 * V_145 , * V_185 ;
F_72 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_145 -> V_140 -- ;
V_22 -> V_140 = 0 ;
F_98 ( & V_22 -> V_147 ) ;
}
F_94 ( & V_1 -> V_4 . V_5 ) ;
F_95 (net, w) {
if ( V_3 -> V_75 == V_182 && V_3 -> V_43 == V_22 ) {
F_51 ( L_12 , V_3 ) ;
V_3 -> V_43 = V_22 -> V_23 . V_64 ;
if ( ! V_3 -> V_43 )
V_3 -> V_75 = V_181 ;
}
}
F_96 ( & V_1 -> V_4 . V_5 ) ;
V_22 -> V_23 . V_64 = NULL ;
if ( ! V_18 -> V_43 ) {
V_18 -> V_45 &= ~ V_48 ;
V_1 -> V_4 . V_151 -> V_153 -- ;
V_18 = F_88 ( V_1 , V_18 ) ;
}
F_64 ( V_22 , V_18 , V_1 ) ;
F_73 ( V_186 , V_22 , V_119 , 0 ) ;
F_21 ( V_22 ) ;
}
int F_99 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_1 * V_1 = V_119 -> V_150 ;
struct V_17 * V_18 = V_22 -> V_148 ;
struct V_21 * * V_183 ;
#if V_169 >= 2
if ( V_22 -> V_23 . V_187 > 0 ) {
F_74 ( V_18 ) ;
return - V_102 ;
}
#endif
if ( ! V_18 || V_22 == V_1 -> V_4 . V_44 )
return - V_102 ;
F_74 ( ! ( V_18 -> V_45 & V_48 ) ) ;
if ( ! ( V_22 -> V_60 & V_156 ) ) {
struct V_17 * V_96 = V_18 ;
#ifdef F_84
if ( V_22 -> V_164 . V_89 ) {
while ( ! ( V_96 -> V_45 & V_46 ) )
V_96 = V_96 -> V_106 ;
V_96 = V_96 -> V_106 ;
}
#endif
F_85 ( V_119 -> V_150 , V_96 ) ;
}
for ( V_183 = & V_18 -> V_43 ; * V_183 ; V_183 = & ( * V_183 ) -> V_23 . V_64 ) {
if ( * V_183 == V_22 ) {
F_97 ( V_18 , V_183 , V_119 ) ;
return 0 ;
}
}
return - V_102 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_17 * V_18 , * V_96 ;
for (; ; ) {
V_18 = V_3 -> V_77 ;
if ( ! V_18 )
return 0 ;
if ( V_3 -> V_188 && V_18 != V_3 -> V_71 &&
V_18 -> V_45 & V_48 && V_3 -> V_75 < V_182 ) {
V_3 -> V_75 = V_182 ;
V_3 -> V_43 = V_18 -> V_43 ;
}
switch ( V_3 -> V_75 ) {
#ifdef F_84
case V_189 :
if ( F_90 ( V_18 ) ) {
V_3 -> V_77 = F_90 ( V_18 ) ;
continue;
}
V_3 -> V_75 = V_179 ;
#endif
case V_179 :
if ( V_18 -> V_105 ) {
V_3 -> V_77 = V_18 -> V_105 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_180 ;
case V_180 :
if ( V_18 -> V_104 ) {
V_3 -> V_77 = V_18 -> V_104 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_182 ;
V_3 -> V_43 = V_18 -> V_43 ;
case V_182 :
if ( V_3 -> V_43 && V_18 -> V_45 & V_48 ) {
int V_133 ;
if ( V_3 -> V_73 ) {
V_3 -> V_73 -- ;
goto V_73;
}
V_133 = V_3 -> V_84 ( V_3 ) ;
if ( V_133 )
return V_133 ;
V_3 -> V_72 ++ ;
continue;
}
V_73:
V_3 -> V_75 = V_181 ;
case V_181 :
if ( V_18 == V_3 -> V_71 )
return 0 ;
V_96 = V_18 -> V_106 ;
V_3 -> V_77 = V_96 ;
#ifdef F_84
if ( F_90 ( V_96 ) == V_18 ) {
F_74 ( ! ( V_18 -> V_45 & V_46 ) ) ;
V_3 -> V_75 = V_179 ;
continue;
}
#endif
if ( V_96 -> V_105 == V_18 ) {
V_3 -> V_75 = V_180 ;
continue;
}
if ( V_96 -> V_104 == V_18 ) {
V_3 -> V_75 = V_182 ;
V_3 -> V_43 = V_3 -> V_77 -> V_43 ;
continue;
}
#if V_169 >= 2
F_74 ( 1 ) ;
#endif
}
}
}
static int F_46 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_63 ;
V_3 -> V_75 = V_76 ;
V_3 -> V_77 = V_3 -> V_71 ;
F_1 ( V_1 , V_3 ) ;
V_63 = F_48 ( V_3 ) ;
if ( V_63 <= 0 )
F_5 ( V_1 , V_3 ) ;
return V_63 ;
}
static int F_100 ( struct V_2 * V_3 )
{
int V_63 ;
struct V_21 * V_22 ;
struct V_190 * V_191 = F_101 ( V_3 , struct V_190 , V_3 ) ;
struct V_118 V_119 = {
. V_150 = V_191 -> V_1 ,
} ;
if ( V_191 -> V_93 != V_192 &&
V_3 -> V_77 -> V_74 != V_191 -> V_93 )
V_3 -> V_77 -> V_74 = V_191 -> V_93 ;
if ( ! V_191 -> V_84 ) {
F_80 ( V_191 -> V_93 == V_192 ) ;
V_3 -> V_43 = NULL ;
return 0 ;
}
for ( V_22 = V_3 -> V_43 ; V_22 ; V_22 = V_22 -> V_23 . V_64 ) {
V_63 = V_191 -> V_84 ( V_22 , V_191 -> V_82 ) ;
if ( V_63 < 0 ) {
V_3 -> V_43 = V_22 ;
V_63 = F_99 ( V_22 , & V_119 ) ;
if ( V_63 ) {
#if V_169 >= 2
F_102 ( L_13 ,
V_193 , V_22 , V_22 -> V_148 , V_63 ) ;
#endif
continue;
}
return 0 ;
}
F_74 ( V_63 != 0 ) ;
}
V_3 -> V_43 = V_22 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_1 , struct V_17 * V_71 ,
int (* V_84)( struct V_21 * , void * V_82 ) ,
bool V_188 , int V_93 , void * V_82 )
{
struct V_190 V_191 ;
V_191 . V_3 . V_71 = V_71 ;
V_191 . V_3 . V_84 = F_100 ;
V_191 . V_3 . V_188 = V_188 ;
V_191 . V_3 . V_72 = 0 ;
V_191 . V_3 . V_73 = 0 ;
V_191 . V_84 = V_84 ;
V_191 . V_93 = V_93 ;
V_191 . V_82 = V_82 ;
V_191 . V_1 = V_1 ;
F_46 ( V_1 , & V_191 . V_3 ) ;
}
static void F_104 ( struct V_1 * V_1 ,
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
F_103 ( V_1 , & V_41 -> V_42 ,
V_84 , false , V_93 , V_82 ) ;
F_4 ( & V_41 -> V_35 ) ;
}
}
F_33 () ;
}
void F_105 ( struct V_1 * V_1 , int (* V_84)( struct V_21 * , void * ) ,
void * V_82 )
{
F_104 ( V_1 , V_84 , V_192 , V_82 ) ;
}
static int F_106 ( struct V_21 * V_22 , void * V_82 )
{
if ( V_22 -> V_60 & V_156 ) {
F_51 ( L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_85 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
F_103 ( V_1 , V_18 , F_106 , true ,
V_192 , NULL ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
int V_194 = F_7 ( V_1 ) ;
F_104 ( V_1 , NULL , V_194 , NULL ) ;
}
static int F_108 ( struct V_21 * V_22 , void * V_82 )
{
struct V_195 * V_196 = V_82 ;
unsigned long V_197 = V_157 ;
if ( V_22 -> V_60 & V_141 && V_22 -> V_23 . V_142 ) {
if ( F_109 ( V_197 , V_22 -> V_23 . V_142 ) ) {
F_51 ( L_15 , V_22 ) ;
return - 1 ;
}
V_196 -> V_198 ++ ;
} else if ( V_22 -> V_60 & V_156 ) {
if ( F_8 ( & V_22 -> V_23 . V_161 ) == 0 &&
F_110 ( V_197 , V_22 -> V_23 . V_199 + V_196 -> V_200 ) ) {
F_51 ( L_16 , V_22 ) ;
return - 1 ;
} else if ( V_22 -> V_60 & V_107 ) {
struct V_201 * V_202 ;
T_6 V_203 = 0 ;
V_202 = F_111 ( & V_22 -> V_23 , & V_22 -> V_139 ) ;
if ( V_202 ) {
V_203 = V_202 -> V_58 ;
F_112 ( V_202 ) ;
}
if ( ! ( V_203 & V_204 ) ) {
F_51 ( L_17 ,
V_22 ) ;
return - 1 ;
}
}
V_196 -> V_198 ++ ;
}
return 0 ;
}
void F_113 ( unsigned long V_142 , struct V_1 * V_1 , bool V_205 )
{
struct V_195 V_196 ;
unsigned long V_197 ;
if ( V_205 ) {
F_114 ( & V_1 -> V_4 . V_206 ) ;
} else if ( ! F_115 ( & V_1 -> V_4 . V_206 ) ) {
F_77 ( & V_1 -> V_4 . V_155 , V_157 + V_207 ) ;
return;
}
V_196 . V_200 = V_142 ? ( int ) V_142 :
V_1 -> V_4 . V_158 . V_159 ;
V_196 . V_198 = F_116 () ;
F_105 ( V_1 , F_108 , & V_196 ) ;
V_197 = V_157 ;
V_1 -> V_4 . V_208 = V_197 ;
if ( V_196 . V_198 )
F_77 ( & V_1 -> V_4 . V_155 ,
F_117 ( V_197
+ V_1 -> V_4 . V_158 . V_159 ) ) ;
else
F_118 ( & V_1 -> V_4 . V_155 ) ;
F_119 ( & V_1 -> V_4 . V_206 ) ;
}
static void F_120 ( unsigned long V_82 )
{
F_113 ( 0 , (struct V_1 * ) V_82 , true ) ;
}
static int T_3 F_121 ( struct V_1 * V_1 )
{
T_7 V_209 = sizeof( struct V_51 ) * V_37 ;
F_122 ( & V_1 -> V_4 . V_206 ) ;
F_24 ( & V_1 -> V_4 . V_5 ) ;
F_123 ( & V_1 -> V_4 . V_7 ) ;
F_124 ( & V_1 -> V_4 . V_155 , F_120 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 . V_151 = F_27 ( sizeof( * V_1 -> V_4 . V_151 ) , V_210 ) ;
if ( ! V_1 -> V_4 . V_151 )
goto V_211;
V_209 = F_125 ( T_7 , V_209 , V_212 ) ;
V_1 -> V_4 . V_39 = F_27 ( V_209 , V_210 ) ;
if ( ! V_1 -> V_4 . V_39 )
goto V_213;
V_1 -> V_4 . V_53 = F_27 ( sizeof( * V_1 -> V_4 . V_53 ) ,
V_210 ) ;
if ( ! V_1 -> V_4 . V_53 )
goto V_214;
V_1 -> V_4 . V_53 -> V_36 = V_50 ;
V_1 -> V_4 . V_53 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_53 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
#ifdef F_126
V_1 -> V_4 . V_54 = F_27 ( sizeof( * V_1 -> V_4 . V_54 ) ,
V_210 ) ;
if ( ! V_1 -> V_4 . V_54 )
goto V_215;
V_1 -> V_4 . V_54 -> V_36 = V_216 ;
V_1 -> V_4 . V_54 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_54 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
#endif
F_34 ( V_1 ) ;
return 0 ;
#ifdef F_126
V_215:
F_42 ( V_1 -> V_4 . V_53 ) ;
#endif
V_214:
F_42 ( V_1 -> V_4 . V_39 ) ;
V_213:
F_42 ( V_1 -> V_4 . V_151 ) ;
V_211:
return - V_83 ;
}
static void F_127 ( struct V_1 * V_1 )
{
F_128 ( V_1 , NULL ) ;
F_129 ( & V_1 -> V_4 . V_155 ) ;
#ifdef F_126
F_130 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
F_42 ( V_1 -> V_4 . V_54 ) ;
#endif
F_130 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
F_42 ( V_1 -> V_4 . V_53 ) ;
F_42 ( V_1 -> V_4 . V_39 ) ;
F_42 ( V_1 -> V_4 . V_151 ) ;
}
int T_8 F_131 ( void )
{
int V_217 = - V_83 ;
V_19 = F_132 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_218 ,
NULL ) ;
if ( ! V_19 )
goto V_86;
V_217 = F_133 ( & V_219 ) ;
if ( V_217 )
goto V_220;
V_217 = F_134 ( V_221 , V_222 , NULL , F_49 ,
NULL ) ;
if ( V_217 )
goto V_223;
V_224 = F_107 ;
V_86:
return V_217 ;
V_223:
F_135 ( & V_219 ) ;
V_220:
F_136 ( V_19 ) ;
goto V_86;
}
void F_137 ( void )
{
F_135 ( & V_219 ) ;
F_136 ( V_19 ) ;
}
static int F_138 ( struct V_225 * V_226 , void * V_227 )
{
struct V_21 * V_22 = V_227 ;
struct V_228 * V_120 = V_226 -> V_229 ;
F_139 ( V_226 , L_19 , & V_22 -> V_163 . V_14 , V_22 -> V_163 . V_89 ) ;
#ifdef F_84
F_139 ( V_226 , L_19 , & V_22 -> V_164 . V_14 , V_22 -> V_164 . V_89 ) ;
#else
F_140 ( V_226 , L_20 ) ;
#endif
if ( V_22 -> V_60 & V_107 )
F_139 ( V_226 , L_21 , & V_22 -> V_139 ) ;
else
F_140 ( V_226 , L_22 ) ;
F_139 ( V_226 , L_23 ,
V_22 -> V_134 , F_8 ( & V_22 -> V_23 . V_161 ) ,
V_22 -> V_23 . V_230 , V_22 -> V_60 ,
V_22 -> V_23 . V_137 ? V_22 -> V_23 . V_137 -> V_231 : L_24 ) ;
V_120 -> V_3 . V_43 = NULL ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_228 * V_120 = V_3 -> args ;
if ( ! V_120 -> V_73 )
return 1 ;
do {
V_120 -> V_3 . V_43 = V_120 -> V_3 . V_43 -> V_23 . V_64 ;
V_120 -> V_73 -- ;
if ( ! V_120 -> V_73 && V_120 -> V_3 . V_43 )
return 1 ;
} while ( V_120 -> V_3 . V_43 );
return 0 ;
}
static void F_142 ( struct V_228 * V_120 ,
struct V_1 * V_1 )
{
memset ( & V_120 -> V_3 , 0 , sizeof( V_120 -> V_3 ) ) ;
V_120 -> V_3 . V_84 = F_141 ;
V_120 -> V_3 . V_71 = & V_120 -> V_232 -> V_42 ;
V_120 -> V_3 . V_75 = V_76 ;
V_120 -> V_3 . V_77 = V_120 -> V_3 . V_71 ;
V_120 -> V_3 . args = V_120 ;
V_120 -> V_93 = V_120 -> V_3 . V_71 -> V_74 ;
F_123 ( & V_120 -> V_3 . V_6 ) ;
F_1 ( V_1 , & V_120 -> V_3 ) ;
}
static struct V_32 * F_143 ( struct V_32 * V_232 ,
struct V_1 * V_1 )
{
unsigned int V_34 ;
struct V_233 * V_77 ;
if ( V_232 ) {
V_34 = ( V_232 -> V_36 & ( V_37 - 1 ) ) + 1 ;
V_77 = F_144 ( F_145 ( & V_232 -> V_38 ) ) ;
} else {
V_34 = 0 ;
V_77 = NULL ;
}
while ( ! V_77 && V_34 < V_37 ) {
V_77 = F_144 (
F_146 ( & V_1 -> V_4 . V_39 [ V_34 ++ ] ) ) ;
}
return F_147 ( V_77 , struct V_32 , V_38 ) ;
}
static void F_148 ( struct V_228 * V_120 )
{
if ( V_120 -> V_93 != V_120 -> V_3 . V_71 -> V_74 ) {
V_120 -> V_93 = V_120 -> V_3 . V_71 -> V_74 ;
V_120 -> V_3 . V_75 = V_76 ;
V_120 -> V_3 . V_77 = V_120 -> V_3 . V_71 ;
F_74 ( V_120 -> V_3 . V_73 ) ;
V_120 -> V_3 . V_73 = V_120 -> V_3 . V_72 ;
}
}
static void * F_149 ( struct V_225 * V_226 , void * V_227 , T_9 * V_234 )
{
int V_235 ;
struct V_21 * V_236 ;
struct V_1 * V_1 = F_150 ( V_226 ) ;
struct V_228 * V_120 = V_226 -> V_229 ;
if ( ! V_227 )
goto V_237;
V_236 = ( (struct V_21 * ) V_227 ) -> V_23 . V_64 ;
if ( V_236 ) {
++ * V_234 ;
return V_236 ;
}
V_237:
F_148 ( V_120 ) ;
F_94 ( & V_120 -> V_232 -> V_35 ) ;
V_235 = F_48 ( & V_120 -> V_3 ) ;
F_96 ( & V_120 -> V_232 -> V_35 ) ;
if ( V_235 > 0 ) {
if ( V_227 )
++ * V_234 ;
return V_120 -> V_3 . V_43 ;
} else if ( V_235 < 0 ) {
F_5 ( V_1 , & V_120 -> V_3 ) ;
return NULL ;
}
F_5 ( V_1 , & V_120 -> V_3 ) ;
V_120 -> V_232 = F_143 ( V_120 -> V_232 , V_1 ) ;
if ( ! V_120 -> V_232 )
return NULL ;
F_142 ( V_120 , V_1 ) ;
goto V_237;
}
static void * F_151 ( struct V_225 * V_226 , T_9 * V_234 )
__acquires( T_10 )
{
struct V_1 * V_1 = F_150 ( V_226 ) ;
struct V_228 * V_120 = V_226 -> V_229 ;
F_152 () ;
V_120 -> V_232 = F_143 ( NULL , V_1 ) ;
V_120 -> V_73 = * V_234 ;
if ( V_120 -> V_232 ) {
F_142 ( V_120 , V_1 ) ;
return F_149 ( V_226 , NULL , V_234 ) ;
} else {
return NULL ;
}
}
static bool F_153 ( struct V_228 * V_120 )
{
struct V_2 * V_3 = & V_120 -> V_3 ;
return V_3 -> V_77 && ! ( V_3 -> V_75 == V_181 && V_3 -> V_77 == V_3 -> V_71 ) ;
}
static void F_154 ( struct V_225 * V_226 , void * V_227 )
__releases( T_10 )
{
struct V_1 * V_1 = F_150 ( V_226 ) ;
struct V_228 * V_120 = V_226 -> V_229 ;
if ( F_153 ( V_120 ) )
F_5 ( V_1 , & V_120 -> V_3 ) ;
F_155 () ;
}
int F_156 ( struct V_238 * V_238 , struct V_239 * V_239 )
{
return F_157 ( V_238 , V_239 , & V_240 ,
sizeof( struct V_228 ) ) ;
}
