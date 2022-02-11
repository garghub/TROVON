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
static void F_19 ( struct V_24 * V_25 )
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
static void F_25 ( struct V_24 * V_31 )
{
if ( F_26 ( & V_31 -> V_32 ) ) {
F_19 ( V_31 ) ;
F_22 ( & V_31 -> V_30 ) ;
F_23 ( & V_31 -> V_30 ) ;
}
}
static void F_27 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
unsigned int V_35 ;
F_28 ( & V_34 -> V_36 ) ;
V_35 = V_34 -> V_37 & ( V_38 - 1 ) ;
F_29 ( & V_34 -> V_39 , & V_1 -> V_4 . V_40 [ V_35 ] ) ;
}
static struct V_33 * F_30 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_33 * V_42 ;
V_42 = F_31 ( sizeof( * V_42 ) , V_20 ) ;
if ( V_42 ) {
V_42 -> V_37 = V_41 ;
V_42 -> V_43 . V_44 = V_1 -> V_4 . V_45 ;
V_42 -> V_43 . V_46 = V_47 | V_48 | V_49 ;
F_32 ( & V_42 -> V_50 ) ;
}
return V_42 ;
}
struct V_33 * F_33 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_33 * V_34 ;
if ( V_41 == 0 )
V_41 = V_51 ;
V_34 = F_34 ( V_1 , V_41 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_1 , V_41 ) ;
if ( V_34 )
F_27 ( V_1 , V_34 ) ;
return V_34 ;
}
struct V_33 * F_34 ( struct V_1 * V_1 , T_2 V_41 )
{
struct V_33 * V_34 ;
struct V_52 * V_22 ;
unsigned int V_35 ;
if ( V_41 == 0 )
V_41 = V_51 ;
V_35 = V_41 & ( V_38 - 1 ) ;
F_35 () ;
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_36 (tb, head, tb6_hlist) {
if ( V_34 -> V_37 == V_41 ) {
F_37 () ;
return V_34 ;
}
}
F_37 () ;
return NULL ;
}
static void T_3 F_38 ( struct V_1 * V_1 )
{
F_27 ( V_1 , V_1 -> V_4 . V_53 ) ;
F_27 ( V_1 , V_1 -> V_4 . V_54 ) ;
}
struct V_33 * F_33 ( struct V_1 * V_1 , T_2 V_41 )
{
return F_34 ( V_1 , V_41 ) ;
}
struct V_33 * F_34 ( struct V_1 * V_1 , T_2 V_41 )
{
return V_1 -> V_4 . V_53 ;
}
struct V_55 * F_39 ( struct V_1 * V_1 , struct V_56 * V_57 ,
int V_58 , T_4 V_59 )
{
struct V_24 * V_31 ;
V_31 = V_59 ( V_1 , V_1 -> V_4 . V_53 , V_57 , V_58 ) ;
if ( V_31 -> V_30 . error == - V_60 ) {
F_40 ( V_31 ) ;
V_31 = V_1 -> V_4 . V_45 ;
F_41 ( & V_31 -> V_30 ) ;
}
return & V_31 -> V_30 ;
}
static void T_3 F_38 ( struct V_1 * V_1 )
{
F_27 ( V_1 , V_1 -> V_4 . V_53 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
int V_61 ;
struct V_24 * V_31 ;
for ( V_31 = V_3 -> V_44 ; V_31 ; V_31 = V_31 -> V_30 . V_62 ) {
V_61 = F_43 ( V_31 , V_3 -> args ) ;
if ( V_61 < 0 ) {
V_3 -> V_44 = V_31 ;
return 1 ;
}
if ( V_31 -> V_63 )
V_31 = F_44 ( & V_31 -> V_64 ,
struct V_24 ,
V_64 ) ;
}
V_3 -> V_44 = NULL ;
return 0 ;
}
static void F_45 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_46 ( V_66 -> V_67 -> V_68 ) ;
struct V_2 * V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( V_3 ) {
if ( V_66 -> args [ 4 ] ) {
V_66 -> args [ 4 ] = 0 ;
F_5 ( V_1 , V_3 ) ;
}
V_66 -> args [ 2 ] = 0 ;
F_47 ( V_3 ) ;
}
V_66 -> V_69 = ( void * ) V_66 -> args [ 3 ] ;
V_66 -> args [ 1 ] = 3 ;
}
static int F_48 ( struct V_65 * V_66 )
{
F_45 ( V_66 ) ;
return V_66 -> V_69 ? V_66 -> V_69 ( V_66 ) : 0 ;
}
static int F_49 ( struct V_33 * V_42 , struct V_70 * V_67 ,
struct V_65 * V_66 )
{
struct V_1 * V_1 = F_46 ( V_67 -> V_68 ) ;
struct V_2 * V_3 ;
int V_61 ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
V_3 -> V_71 = & V_42 -> V_43 ;
if ( V_66 -> args [ 4 ] == 0 ) {
V_3 -> V_72 = 0 ;
V_3 -> V_73 = 0 ;
F_50 ( & V_42 -> V_36 ) ;
V_61 = F_51 ( V_1 , V_3 ) ;
F_52 ( & V_42 -> V_36 ) ;
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
F_50 ( & V_42 -> V_36 ) ;
V_61 = F_53 ( V_3 ) ;
F_52 ( & V_42 -> V_36 ) ;
if ( V_61 <= 0 ) {
F_5 ( V_1 , V_3 ) ;
V_66 -> args [ 4 ] = 0 ;
}
}
return V_61 ;
}
static int F_54 ( struct V_70 * V_67 , struct V_65 * V_66 )
{
struct V_1 * V_1 = F_46 ( V_67 -> V_68 ) ;
unsigned int V_35 , V_78 ;
unsigned int V_79 = 0 , V_80 ;
struct V_81 V_82 ;
struct V_2 * V_3 ;
struct V_33 * V_34 ;
struct V_52 * V_22 ;
int V_61 = 0 ;
V_78 = V_66 -> args [ 0 ] ;
V_80 = V_66 -> args [ 1 ] ;
V_3 = ( void * ) V_66 -> args [ 2 ] ;
if ( ! V_3 ) {
V_66 -> args [ 3 ] = ( long ) V_66 -> V_69 ;
V_66 -> V_69 = F_48 ;
V_3 = F_31 ( sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_83 ;
V_3 -> V_84 = F_42 ;
V_66 -> args [ 2 ] = ( long ) V_3 ;
}
V_82 . V_67 = V_67 ;
V_82 . V_66 = V_66 ;
V_82 . V_1 = V_1 ;
V_3 -> args = & V_82 ;
F_35 () ;
for ( V_35 = V_78 ; V_35 < V_38 ; V_35 ++ , V_80 = 0 ) {
V_79 = 0 ;
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_36 (tb, head, tb6_hlist) {
if ( V_79 < V_80 )
goto V_85;
V_61 = F_49 ( V_34 , V_67 , V_66 ) ;
if ( V_61 != 0 )
goto V_86;
V_85:
V_79 ++ ;
}
}
V_86:
F_37 () ;
V_66 -> args [ 1 ] = V_79 ;
V_66 -> args [ 0 ] = V_35 ;
V_61 = V_61 < 0 ? V_61 : V_67 -> V_87 ;
if ( V_61 <= 0 )
F_45 ( V_66 ) ;
return V_61 ;
}
static struct V_17 * F_55 ( struct V_17 * V_71 ,
struct V_88 * V_14 , int V_89 ,
int V_90 , int V_91 ,
int V_92 , int V_93 ,
struct V_94 * V_95 )
{
struct V_17 * V_18 , * V_96 , * V_97 ;
struct V_17 * V_98 = NULL ;
struct V_99 * V_100 ;
int V_101 ;
T_1 V_102 = 0 ;
F_56 ( L_1 ) ;
V_18 = V_71 ;
do {
V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_44 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_57 ( & V_100 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_91 ) {
if ( V_92 ) {
F_58 ( V_95 ,
L_2 ) ;
F_59 ( L_3 ) ;
return F_60 ( - V_104 ) ;
}
F_59 ( L_4 ) ;
}
goto V_105;
}
if ( V_89 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_46 & V_49 ) ) {
F_25 ( V_18 -> V_44 ) ;
V_18 -> V_44 = NULL ;
}
V_18 -> V_74 = V_93 ;
return V_18 ;
}
V_18 -> V_74 = V_93 ;
V_102 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_98 = V_18 ;
V_18 = V_102 ? V_18 -> V_106 : V_18 -> V_107 ;
} while ( V_18 );
if ( ! V_91 ) {
if ( V_92 ) {
F_58 ( V_95 ,
L_2 ) ;
F_59 ( L_3 ) ;
return F_60 ( - V_104 ) ;
}
F_59 ( L_4 ) ;
}
V_97 = F_11 () ;
if ( ! V_97 )
return F_60 ( - V_83 ) ;
V_97 -> V_13 = V_89 ;
V_97 -> V_108 = V_98 ;
V_97 -> V_74 = V_93 ;
if ( V_102 )
V_98 -> V_106 = V_97 ;
else
V_98 -> V_107 = V_97 ;
return V_97 ;
V_105:
V_98 = V_18 -> V_108 ;
V_101 = F_61 ( V_14 , & V_100 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_89 > V_101 ) {
V_96 = F_11 () ;
V_97 = F_11 () ;
if ( ! V_96 || ! V_97 ) {
if ( V_96 )
F_13 ( V_96 ) ;
if ( V_97 )
F_13 ( V_97 ) ;
return F_60 ( - V_83 ) ;
}
V_96 -> V_13 = V_101 ;
V_96 -> V_108 = V_98 ;
V_96 -> V_44 = V_18 -> V_44 ;
F_62 ( & V_96 -> V_44 -> V_32 ) ;
V_96 -> V_74 = V_93 ;
if ( V_102 )
V_98 -> V_106 = V_96 ;
else
V_98 -> V_107 = V_96 ;
V_97 -> V_13 = V_89 ;
V_97 -> V_108 = V_96 ;
V_18 -> V_108 = V_96 ;
V_97 -> V_74 = V_93 ;
if ( F_10 ( V_14 , V_101 ) ) {
V_96 -> V_106 = V_97 ;
V_96 -> V_107 = V_18 ;
} else {
V_96 -> V_107 = V_97 ;
V_96 -> V_106 = V_18 ;
}
} else {
V_97 = F_11 () ;
if ( ! V_97 )
return F_60 ( - V_83 ) ;
V_97 -> V_13 = V_89 ;
V_97 -> V_108 = V_98 ;
V_97 -> V_74 = V_93 ;
if ( V_102 )
V_98 -> V_106 = V_97 ;
else
V_98 -> V_107 = V_97 ;
if ( F_10 ( & V_100 -> V_14 , V_89 ) )
V_97 -> V_106 = V_18 ;
else
V_97 -> V_107 = V_18 ;
V_18 -> V_108 = V_97 ;
}
return V_97 ;
}
static bool F_63 ( struct V_24 * V_31 )
{
return ( V_31 -> V_109 & ( V_110 | V_111 | V_112 ) ) ==
V_110 ;
}
static void F_64 ( T_2 * V_113 , const struct V_114 * V_115 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
if ( F_65 ( V_116 , V_115 -> V_118 ) )
V_113 [ V_116 ] = V_115 -> V_119 [ V_116 ] ;
}
}
static int F_66 ( struct V_55 * V_30 , struct V_114 * V_115 )
{
if ( ! V_115 -> V_119 )
return 0 ;
if ( V_30 -> V_58 & V_120 ) {
T_2 * V_113 = F_67 ( V_30 ) ;
if ( F_68 ( ! V_113 ) )
return - V_83 ;
F_64 ( V_113 , V_115 ) ;
} else {
F_69 ( V_30 , V_115 -> V_119 , false ) ;
V_115 -> V_119 = NULL ;
}
return 0 ;
}
static void F_70 ( struct V_24 * V_31 , struct V_17 * V_18 ,
struct V_1 * V_1 )
{
if ( F_8 ( & V_31 -> V_32 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_46 & V_49 ) && V_18 -> V_44 == V_31 ) {
V_18 -> V_44 = F_71 ( V_1 , V_18 ) ;
F_62 ( & V_18 -> V_44 -> V_32 ) ;
F_25 ( V_31 ) ;
}
V_18 = V_18 -> V_108 ;
}
F_72 ( F_8 ( & V_31 -> V_32 ) != 1 ) ;
}
}
static int F_73 ( struct V_17 * V_18 , struct V_24 * V_31 ,
struct V_121 * V_122 , struct V_114 * V_115 )
{
struct V_24 * V_123 = NULL ;
struct V_24 * * V_124 ;
struct V_24 * * V_125 = NULL ;
int V_126 = ( V_122 -> V_127 &&
( V_122 -> V_127 -> V_128 & V_129 ) ) ;
int V_130 = ( ! V_122 -> V_127 ||
( V_122 -> V_127 -> V_128 & V_131 ) ) ;
int V_132 = 0 ;
bool V_133 = F_63 ( V_31 ) ;
T_5 V_134 = V_135 ;
int V_136 ;
if ( V_122 -> V_127 && ( V_122 -> V_127 -> V_128 & V_137 ) )
V_134 |= V_137 ;
V_124 = & V_18 -> V_44 ;
for ( V_123 = V_18 -> V_44 ; V_123 ; V_123 = V_123 -> V_30 . V_62 ) {
if ( V_123 -> V_138 == V_31 -> V_138 ) {
if ( V_122 -> V_127 &&
( V_122 -> V_127 -> V_128 & V_135 ) )
return - V_139 ;
V_134 &= ~ V_135 ;
if ( V_126 ) {
if ( V_133 == F_63 ( V_123 ) ) {
V_132 ++ ;
break;
}
if ( V_133 )
V_125 = V_125 ? : V_124 ;
goto V_140;
}
if ( F_74 ( V_123 , V_31 ) ) {
if ( V_31 -> V_63 )
V_31 -> V_63 = 0 ;
if ( ! ( V_123 -> V_109 & V_141 ) )
return - V_139 ;
if ( ! ( V_31 -> V_109 & V_141 ) )
F_75 ( V_123 ) ;
else
F_76 ( V_123 , V_31 -> V_30 . V_142 ) ;
V_123 -> V_143 = V_31 -> V_143 ;
return - V_139 ;
}
if ( V_133 &&
F_63 ( V_123 ) )
V_31 -> V_63 ++ ;
}
if ( V_123 -> V_138 > V_31 -> V_138 )
break;
V_140:
V_124 = & V_123 -> V_30 . V_62 ;
}
if ( V_125 && ! V_132 ) {
V_124 = V_125 ;
V_123 = * V_124 ;
V_132 ++ ;
}
if ( V_124 == & V_18 -> V_44 )
V_18 -> V_144 = NULL ;
if ( V_31 -> V_63 ) {
unsigned int V_63 ;
struct V_24 * V_145 , * V_146 ;
V_145 = V_18 -> V_44 ;
while ( V_145 ) {
if ( V_145 -> V_138 == V_31 -> V_138 &&
F_63 ( V_145 ) ) {
F_77 ( & V_31 -> V_64 ,
& V_145 -> V_64 ) ;
break;
}
V_145 = V_145 -> V_30 . V_62 ;
}
V_63 = 0 ;
F_78 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_145 -> V_63 ++ ;
F_72 ( V_145 -> V_63 != V_31 -> V_63 ) ;
V_63 ++ ;
}
F_72 ( V_63 != V_31 -> V_63 ) ;
}
if ( ! V_126 ) {
if ( ! V_130 )
F_59 ( L_4 ) ;
V_130:
V_134 |= V_131 ;
V_136 = F_66 ( & V_31 -> V_30 , V_115 ) ;
if ( V_136 )
return V_136 ;
V_31 -> V_30 . V_62 = V_123 ;
* V_124 = V_31 ;
F_79 ( V_31 -> V_147 , V_18 ) ;
F_62 ( & V_31 -> V_32 ) ;
if ( ! V_122 -> V_148 )
F_80 ( V_149 , V_31 , V_122 , V_134 ) ;
V_122 -> V_150 -> V_4 . V_151 -> V_152 ++ ;
if ( ! ( V_18 -> V_46 & V_49 ) ) {
V_122 -> V_150 -> V_4 . V_151 -> V_153 ++ ;
V_18 -> V_46 |= V_49 ;
}
} else {
int V_154 ;
if ( ! V_132 ) {
if ( V_130 )
goto V_130;
F_59 ( L_5 ) ;
return - V_104 ;
}
V_136 = F_66 ( & V_31 -> V_30 , V_115 ) ;
if ( V_136 )
return V_136 ;
* V_124 = V_31 ;
F_79 ( V_31 -> V_147 , V_18 ) ;
V_31 -> V_30 . V_62 = V_123 -> V_30 . V_62 ;
F_62 ( & V_31 -> V_32 ) ;
if ( ! V_122 -> V_148 )
F_80 ( V_149 , V_31 , V_122 , V_129 ) ;
if ( ! ( V_18 -> V_46 & V_49 ) ) {
V_122 -> V_150 -> V_4 . V_151 -> V_153 ++ ;
V_18 -> V_46 |= V_49 ;
}
V_154 = V_123 -> V_63 ;
F_70 ( V_123 , V_18 , V_122 -> V_150 ) ;
if ( V_18 -> V_144 == V_123 )
V_18 -> V_144 = NULL ;
F_25 ( V_123 ) ;
if ( V_154 ) {
V_124 = & V_31 -> V_30 . V_62 ;
V_123 = * V_124 ;
while ( V_123 ) {
if ( V_123 -> V_138 > V_31 -> V_138 )
break;
if ( F_63 ( V_123 ) ) {
* V_124 = V_123 -> V_30 . V_62 ;
F_70 ( V_123 , V_18 , V_122 -> V_150 ) ;
if ( V_18 -> V_144 == V_123 )
V_18 -> V_144 = NULL ;
F_25 ( V_123 ) ;
V_154 -- ;
} else {
V_124 = & V_123 -> V_30 . V_62 ;
}
V_123 = * V_124 ;
}
F_81 ( V_154 != 0 ) ;
}
}
return 0 ;
}
static void F_82 ( struct V_1 * V_1 , struct V_24 * V_31 )
{
if ( ! F_83 ( & V_1 -> V_4 . V_155 ) &&
( V_31 -> V_109 & ( V_141 | V_156 ) ) )
F_84 ( & V_1 -> V_4 . V_155 ,
V_157 + V_1 -> V_4 . V_158 . V_159 ) ;
}
void F_85 ( struct V_1 * V_1 )
{
if ( ! F_83 ( & V_1 -> V_4 . V_155 ) )
F_84 ( & V_1 -> V_4 . V_155 ,
V_157 + V_1 -> V_4 . V_158 . V_159 ) ;
}
int F_86 ( struct V_17 * V_71 , struct V_24 * V_31 ,
struct V_121 * V_122 , struct V_114 * V_115 ,
struct V_94 * V_95 )
{
struct V_17 * V_18 , * V_98 = NULL ;
int V_136 = - V_83 ;
int V_91 = 1 ;
int V_92 = 0 ;
int V_93 = F_7 ( V_122 -> V_150 ) ;
if ( F_87 ( ! F_8 ( & V_31 -> V_30 . V_160 ) ) )
return - V_161 ;
if ( V_122 -> V_127 ) {
if ( ! ( V_122 -> V_127 -> V_128 & V_131 ) )
V_91 = 0 ;
if ( V_122 -> V_127 -> V_128 & V_129 )
V_92 = 1 ;
}
if ( ! V_91 && ! V_92 )
F_59 ( L_6 ) ;
V_18 = F_55 ( V_71 , & V_31 -> V_162 . V_14 , V_31 -> V_162 . V_89 ,
F_88 ( struct V_24 , V_162 ) , V_91 ,
V_92 , V_93 , V_95 ) ;
if ( F_89 ( V_18 ) ) {
V_136 = F_90 ( V_18 ) ;
V_18 = NULL ;
goto V_86;
}
V_98 = V_18 ;
#ifdef F_91
if ( V_31 -> V_163 . V_89 ) {
struct V_17 * V_164 ;
if ( ! V_18 -> V_165 ) {
struct V_17 * V_166 ;
V_166 = F_11 () ;
if ( ! V_166 )
goto V_167;
V_166 -> V_44 = V_122 -> V_150 -> V_4 . V_45 ;
F_62 ( & V_122 -> V_150 -> V_4 . V_45 -> V_32 ) ;
V_166 -> V_46 = V_47 ;
V_166 -> V_74 = V_93 ;
V_164 = F_55 ( V_166 , & V_31 -> V_163 . V_14 ,
V_31 -> V_163 . V_89 ,
F_88 ( struct V_24 , V_163 ) ,
V_91 , V_92 , V_93 ,
V_95 ) ;
if ( F_89 ( V_164 ) ) {
F_13 ( V_166 ) ;
V_136 = F_90 ( V_164 ) ;
goto V_167;
}
V_166 -> V_108 = V_18 ;
V_18 -> V_165 = V_166 ;
} else {
V_164 = F_55 ( V_18 -> V_165 , & V_31 -> V_163 . V_14 ,
V_31 -> V_163 . V_89 ,
F_88 ( struct V_24 , V_163 ) ,
V_91 , V_92 , V_93 ,
V_95 ) ;
if ( F_89 ( V_164 ) ) {
V_136 = F_90 ( V_164 ) ;
goto V_167;
}
}
if ( ! V_18 -> V_44 ) {
V_18 -> V_44 = V_31 ;
F_62 ( & V_31 -> V_32 ) ;
}
V_18 = V_164 ;
}
#endif
V_136 = F_73 ( V_18 , V_31 , V_122 , V_115 ) ;
if ( ! V_136 ) {
F_82 ( V_122 -> V_150 , V_31 ) ;
if ( ! ( V_31 -> V_109 & V_156 ) )
F_92 ( V_122 -> V_150 , V_98 ) ;
}
V_86:
if ( V_136 ) {
#ifdef F_91
if ( V_98 != V_18 && V_98 -> V_44 == V_31 ) {
V_98 -> V_44 = NULL ;
F_93 ( & V_31 -> V_32 ) ;
}
if ( V_98 != V_18 && ! V_98 -> V_44 && ! ( V_98 -> V_46 & V_49 ) ) {
V_98 -> V_44 = F_71 ( V_122 -> V_150 , V_98 ) ;
#if V_168 >= 2
if ( ! V_98 -> V_44 ) {
F_81 ( V_98 -> V_44 == NULL ) ;
V_98 -> V_44 = V_122 -> V_150 -> V_4 . V_45 ;
}
#endif
F_62 ( & V_98 -> V_44 -> V_32 ) ;
}
#endif
goto V_167;
}
return V_136 ;
V_167:
if ( V_18 && ! ( V_18 -> V_46 & ( V_49 | V_47 ) ) )
F_94 ( V_122 -> V_150 , V_18 ) ;
F_95 ( & V_31 -> V_30 ) ;
return V_136 ;
}
static struct V_17 * F_96 ( struct V_17 * V_71 ,
struct V_169 * args )
{
struct V_17 * V_18 ;
T_1 V_102 ;
if ( F_68 ( args -> V_90 == 0 ) )
return NULL ;
V_18 = V_71 ;
for (; ; ) {
struct V_17 * V_85 ;
V_102 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_85 = V_102 ? V_18 -> V_106 : V_18 -> V_107 ;
if ( V_85 ) {
V_18 = V_85 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_97 ( V_18 ) || V_18 -> V_46 & V_49 ) {
struct V_99 * V_100 ;
V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_44 +
args -> V_90 ) ;
if ( F_57 ( & V_100 -> V_14 , args -> V_14 , V_100 -> V_89 ) ) {
#ifdef F_91
if ( V_18 -> V_165 ) {
struct V_17 * V_166 ;
V_166 = F_96 ( V_18 -> V_165 ,
args + 1 ) ;
if ( ! V_166 )
goto V_170;
V_18 = V_166 ;
}
#endif
if ( V_18 -> V_46 & V_49 )
return V_18 ;
}
}
#ifdef F_91
V_170:
#endif
if ( V_18 -> V_46 & V_47 )
break;
V_18 = V_18 -> V_108 ;
}
return NULL ;
}
struct V_17 * F_98 ( struct V_17 * V_71 , const struct V_88 * V_171 ,
const struct V_88 * V_172 )
{
struct V_17 * V_18 ;
struct V_169 args [] = {
{
. V_90 = F_88 ( struct V_24 , V_162 ) ,
. V_14 = V_171 ,
} ,
#ifdef F_91
{
. V_90 = F_88 ( struct V_24 , V_163 ) ,
. V_14 = V_172 ,
} ,
#endif
{
. V_90 = 0 ,
}
} ;
V_18 = F_96 ( V_71 , V_171 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_46 & V_48 )
V_18 = V_71 ;
return V_18 ;
}
static struct V_17 * F_99 ( struct V_17 * V_71 ,
const struct V_88 * V_14 ,
int V_89 , int V_90 )
{
struct V_17 * V_18 ;
for ( V_18 = V_71 ; V_18 ; ) {
struct V_99 * V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_44 + V_90 ) ;
if ( V_89 < V_18 -> V_13 ||
! F_57 ( & V_100 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_89 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_106 ;
else
V_18 = V_18 -> V_107 ;
}
return NULL ;
}
struct V_17 * F_100 ( struct V_17 * V_71 ,
const struct V_88 * V_171 , int V_173 ,
const struct V_88 * V_172 , int V_174 )
{
struct V_17 * V_18 ;
V_18 = F_99 ( V_71 , V_171 , V_173 ,
F_88 ( struct V_24 , V_162 ) ) ;
#ifdef F_91
if ( V_174 ) {
F_81 ( V_172 == NULL ) ;
if ( V_18 && V_18 -> V_165 )
V_18 = F_99 ( V_18 -> V_165 , V_172 , V_174 ,
F_88 ( struct V_24 , V_163 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_46 & V_49 )
return V_18 ;
return NULL ;
}
static struct V_24 * F_71 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
if ( V_18 -> V_46 & V_47 )
return V_1 -> V_4 . V_45 ;
while ( V_18 ) {
if ( V_18 -> V_107 )
return V_18 -> V_107 -> V_44 ;
if ( V_18 -> V_106 )
return V_18 -> V_106 -> V_44 ;
V_18 = F_97 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_94 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
int V_175 ;
int V_176 ;
struct V_17 * V_177 , * V_98 ;
struct V_2 * V_3 ;
int V_123 = 0 ;
for (; ; ) {
F_56 ( L_7 , V_18 -> V_13 , V_123 ) ;
V_123 ++ ;
F_81 ( V_18 -> V_46 & V_49 ) ;
F_81 ( V_18 -> V_46 & V_48 ) ;
F_81 ( V_18 -> V_44 ) ;
V_175 = 0 ;
V_177 = NULL ;
if ( V_18 -> V_106 )
V_177 = V_18 -> V_106 , V_175 |= 1 ;
if ( V_18 -> V_107 )
V_177 = V_18 -> V_107 , V_175 |= 2 ;
if ( V_175 == 3 || F_97 ( V_18 )
#ifdef F_91
|| ( V_175 && V_18 -> V_46 & V_47 )
#endif
) {
V_18 -> V_44 = F_71 ( V_1 , V_18 ) ;
#if V_168 >= 2
if ( ! V_18 -> V_44 ) {
F_81 ( ! V_18 -> V_44 ) ;
V_18 -> V_44 = V_1 -> V_4 . V_45 ;
}
#endif
F_62 ( & V_18 -> V_44 -> V_32 ) ;
return V_18 -> V_108 ;
}
V_98 = V_18 -> V_108 ;
#ifdef F_91
if ( F_97 ( V_98 ) == V_18 ) {
F_81 ( ! ( V_18 -> V_46 & V_47 ) ) ;
F_97 ( V_98 ) = NULL ;
V_176 = V_178 ;
} else {
F_81 ( V_18 -> V_46 & V_47 ) ;
#endif
if ( V_98 -> V_106 == V_18 )
V_98 -> V_106 = V_177 ;
else if ( V_98 -> V_107 == V_18 )
V_98 -> V_107 = V_177 ;
#if V_168 >= 2
else
F_81 ( 1 ) ;
#endif
if ( V_177 )
V_177 -> V_108 = V_98 ;
V_176 = V_179 ;
#ifdef F_91
}
#endif
F_101 ( & V_1 -> V_4 . V_5 ) ;
F_102 (net, w) {
if ( ! V_177 ) {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_3 -> V_77 = NULL ;
F_56 ( L_8 , V_3 ) ;
} else if ( V_3 -> V_77 == V_18 ) {
F_56 ( L_9 , V_3 , V_3 -> V_75 , V_176 ) ;
V_3 -> V_77 = V_98 ;
V_3 -> V_75 = V_176 ;
}
} else {
if ( V_3 -> V_71 == V_18 ) {
V_3 -> V_71 = V_177 ;
F_56 ( L_10 , V_3 ) ;
}
if ( V_3 -> V_77 == V_18 ) {
V_3 -> V_77 = V_177 ;
if ( V_175 & 2 ) {
F_56 ( L_11 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_179 ? V_180 : V_76 ;
} else {
F_56 ( L_11 , V_3 , V_3 -> V_75 ) ;
V_3 -> V_75 = V_3 -> V_75 >= V_181 ? V_180 : V_76 ;
}
}
}
}
F_103 ( & V_1 -> V_4 . V_5 ) ;
F_17 ( V_18 ) ;
if ( V_98 -> V_46 & V_49 || F_97 ( V_98 ) )
return V_98 ;
F_25 ( V_98 -> V_44 ) ;
V_98 -> V_44 = NULL ;
V_18 = V_98 ;
}
}
static void F_104 ( struct V_17 * V_18 , struct V_24 * * V_182 ,
struct V_121 * V_122 )
{
struct V_2 * V_3 ;
struct V_24 * V_31 = * V_182 ;
struct V_1 * V_1 = V_122 -> V_150 ;
F_56 ( L_12 ) ;
* V_182 = V_31 -> V_30 . V_62 ;
V_31 -> V_147 = NULL ;
V_1 -> V_4 . V_151 -> V_152 -- ;
V_1 -> V_4 . V_151 -> V_183 ++ ;
if ( V_18 -> V_144 == V_31 )
V_18 -> V_144 = NULL ;
if ( V_31 -> V_63 ) {
struct V_24 * V_145 , * V_184 ;
F_78 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_145 -> V_63 -- ;
V_31 -> V_63 = 0 ;
F_105 ( & V_31 -> V_64 ) ;
}
F_101 ( & V_1 -> V_4 . V_5 ) ;
F_102 (net, w) {
if ( V_3 -> V_75 == V_181 && V_3 -> V_44 == V_31 ) {
F_56 ( L_13 , V_3 ) ;
V_3 -> V_44 = V_31 -> V_30 . V_62 ;
if ( ! V_3 -> V_44 )
V_3 -> V_75 = V_180 ;
}
}
F_103 ( & V_1 -> V_4 . V_5 ) ;
V_31 -> V_30 . V_62 = NULL ;
if ( ! V_18 -> V_44 ) {
V_18 -> V_46 &= ~ V_49 ;
V_1 -> V_4 . V_151 -> V_153 -- ;
V_18 = F_94 ( V_1 , V_18 ) ;
}
F_70 ( V_31 , V_18 , V_1 ) ;
if ( ! V_122 -> V_148 )
F_80 ( V_185 , V_31 , V_122 , 0 ) ;
F_25 ( V_31 ) ;
}
int F_106 ( struct V_24 * V_31 , struct V_121 * V_122 )
{
struct V_17 * V_18 = F_107 ( V_31 -> V_147 ,
F_108 ( & V_31 -> V_186 -> V_36 ) ) ;
struct V_1 * V_1 = V_122 -> V_150 ;
struct V_24 * * V_182 ;
#if V_168 >= 2
if ( V_31 -> V_30 . V_187 > 0 ) {
F_81 ( V_18 ) ;
return - V_104 ;
}
#endif
if ( ! V_18 || V_31 == V_1 -> V_4 . V_45 )
return - V_104 ;
F_81 ( ! ( V_18 -> V_46 & V_49 ) ) ;
if ( ! ( V_31 -> V_109 & V_156 ) ) {
struct V_17 * V_98 = V_18 ;
#ifdef F_91
if ( V_31 -> V_163 . V_89 ) {
while ( ! ( V_98 -> V_46 & V_47 ) )
V_98 = V_98 -> V_108 ;
V_98 = V_98 -> V_108 ;
}
#endif
F_92 ( V_122 -> V_150 , V_98 ) ;
}
for ( V_182 = & V_18 -> V_44 ; * V_182 ; V_182 = & ( * V_182 ) -> V_30 . V_62 ) {
if ( * V_182 == V_31 ) {
F_104 ( V_18 , V_182 , V_122 ) ;
return 0 ;
}
}
return - V_104 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_17 * V_18 , * V_98 ;
for (; ; ) {
V_18 = V_3 -> V_77 ;
if ( ! V_18 )
return 0 ;
if ( V_3 -> V_188 && V_18 != V_3 -> V_71 &&
V_18 -> V_46 & V_49 && V_3 -> V_75 < V_181 ) {
V_3 -> V_75 = V_181 ;
V_3 -> V_44 = V_18 -> V_44 ;
}
switch ( V_3 -> V_75 ) {
#ifdef F_91
case V_189 :
if ( F_97 ( V_18 ) ) {
V_3 -> V_77 = F_97 ( V_18 ) ;
continue;
}
V_3 -> V_75 = V_178 ;
#endif
case V_178 :
if ( V_18 -> V_107 ) {
V_3 -> V_77 = V_18 -> V_107 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_179 ;
case V_179 :
if ( V_18 -> V_106 ) {
V_3 -> V_77 = V_18 -> V_106 ;
V_3 -> V_75 = V_76 ;
continue;
}
V_3 -> V_75 = V_181 ;
V_3 -> V_44 = V_18 -> V_44 ;
case V_181 :
if ( V_3 -> V_44 && V_18 -> V_46 & V_49 ) {
int V_136 ;
if ( V_3 -> V_73 ) {
V_3 -> V_73 -- ;
goto V_73;
}
V_136 = V_3 -> V_84 ( V_3 ) ;
if ( V_136 )
return V_136 ;
V_3 -> V_72 ++ ;
continue;
}
V_73:
V_3 -> V_75 = V_180 ;
case V_180 :
if ( V_18 == V_3 -> V_71 )
return 0 ;
V_98 = V_18 -> V_108 ;
V_3 -> V_77 = V_98 ;
#ifdef F_91
if ( F_97 ( V_98 ) == V_18 ) {
F_81 ( ! ( V_18 -> V_46 & V_47 ) ) ;
V_3 -> V_75 = V_178 ;
continue;
}
#endif
if ( V_98 -> V_107 == V_18 ) {
V_3 -> V_75 = V_179 ;
continue;
}
if ( V_98 -> V_106 == V_18 ) {
V_3 -> V_75 = V_181 ;
V_3 -> V_44 = V_3 -> V_77 -> V_44 ;
continue;
}
#if V_168 >= 2
F_81 ( 1 ) ;
#endif
}
}
}
static int F_51 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_61 ;
V_3 -> V_75 = V_76 ;
V_3 -> V_77 = V_3 -> V_71 ;
F_1 ( V_1 , V_3 ) ;
V_61 = F_53 ( V_3 ) ;
if ( V_61 <= 0 )
F_5 ( V_1 , V_3 ) ;
return V_61 ;
}
static int F_109 ( struct V_2 * V_3 )
{
int V_61 ;
struct V_24 * V_31 ;
struct V_190 * V_191 = F_16 ( V_3 , struct V_190 , V_3 ) ;
struct V_121 V_122 = {
. V_150 = V_191 -> V_1 ,
} ;
if ( V_191 -> V_93 != V_192 &&
V_3 -> V_77 -> V_74 != V_191 -> V_93 )
V_3 -> V_77 -> V_74 = V_191 -> V_93 ;
if ( ! V_191 -> V_84 ) {
F_87 ( V_191 -> V_93 == V_192 ) ;
V_3 -> V_44 = NULL ;
return 0 ;
}
for ( V_31 = V_3 -> V_44 ; V_31 ; V_31 = V_31 -> V_30 . V_62 ) {
V_61 = V_191 -> V_84 ( V_31 , V_191 -> V_82 ) ;
if ( V_61 < 0 ) {
V_3 -> V_44 = V_31 ;
V_61 = F_106 ( V_31 , & V_122 ) ;
if ( V_61 ) {
#if V_168 >= 2
F_110 ( L_14 ,
V_193 , V_31 ,
F_111 ( V_31 -> V_147 ) ,
V_61 ) ;
#endif
continue;
}
return 0 ;
}
F_81 ( V_61 != 0 ) ;
}
V_3 -> V_44 = V_31 ;
return 0 ;
}
static void F_112 ( struct V_1 * V_1 , struct V_17 * V_71 ,
int (* V_84)( struct V_24 * , void * V_82 ) ,
bool V_188 , int V_93 , void * V_82 )
{
struct V_190 V_191 ;
V_191 . V_3 . V_71 = V_71 ;
V_191 . V_3 . V_84 = F_109 ;
V_191 . V_3 . V_188 = V_188 ;
V_191 . V_3 . V_72 = 0 ;
V_191 . V_3 . V_73 = 0 ;
V_191 . V_84 = V_84 ;
V_191 . V_93 = V_93 ;
V_191 . V_82 = V_82 ;
V_191 . V_1 = V_1 ;
F_51 ( V_1 , & V_191 . V_3 ) ;
}
static void F_113 ( struct V_1 * V_1 ,
int (* V_84)( struct V_24 * , void * ) ,
int V_93 , void * V_82 )
{
struct V_33 * V_42 ;
struct V_52 * V_22 ;
unsigned int V_35 ;
F_35 () ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_22 = & V_1 -> V_4 . V_40 [ V_35 ] ;
F_36 (table, head, tb6_hlist) {
F_2 ( & V_42 -> V_36 ) ;
F_112 ( V_1 , & V_42 -> V_43 ,
V_84 , false , V_93 , V_82 ) ;
F_4 ( & V_42 -> V_36 ) ;
}
}
F_37 () ;
}
void F_114 ( struct V_1 * V_1 , int (* V_84)( struct V_24 * , void * ) ,
void * V_82 )
{
F_113 ( V_1 , V_84 , V_192 , V_82 ) ;
}
static int F_115 ( struct V_24 * V_31 , void * V_82 )
{
if ( V_31 -> V_109 & V_156 ) {
F_56 ( L_15 , V_31 ) ;
return - 1 ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
F_112 ( V_1 , V_18 , F_115 , true ,
V_192 , NULL ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
int V_194 = F_7 ( V_1 ) ;
F_113 ( V_1 , NULL , V_194 , NULL ) ;
}
static int F_117 ( struct V_24 * V_31 , void * V_82 )
{
struct V_195 * V_196 = V_82 ;
unsigned long V_197 = V_157 ;
if ( V_31 -> V_109 & V_141 && V_31 -> V_30 . V_142 ) {
if ( F_118 ( V_197 , V_31 -> V_30 . V_142 ) ) {
F_56 ( L_16 , V_31 ) ;
return - 1 ;
}
V_196 -> V_198 ++ ;
} else if ( V_31 -> V_109 & V_156 ) {
if ( F_119 ( V_197 , V_31 -> V_30 . V_199 + V_196 -> V_200 ) )
V_31 -> V_30 . V_187 = V_201 ;
if ( F_8 ( & V_31 -> V_30 . V_160 ) == 1 &&
V_31 -> V_30 . V_187 == V_201 ) {
F_56 ( L_17 , V_31 ) ;
return - 1 ;
} else if ( V_31 -> V_109 & V_110 ) {
struct V_202 * V_203 ;
T_6 V_204 = 0 ;
V_203 = F_120 ( & V_31 -> V_30 , & V_31 -> V_205 ) ;
if ( V_203 ) {
V_204 = V_203 -> V_58 ;
F_121 ( V_203 ) ;
}
if ( ! ( V_204 & V_206 ) ) {
F_56 ( L_18 ,
V_31 ) ;
return - 1 ;
}
}
V_196 -> V_198 ++ ;
}
return 0 ;
}
void F_122 ( unsigned long V_142 , struct V_1 * V_1 , bool V_207 )
{
struct V_195 V_196 ;
unsigned long V_197 ;
if ( V_207 ) {
F_123 ( & V_1 -> V_4 . V_208 ) ;
} else if ( ! F_124 ( & V_1 -> V_4 . V_208 ) ) {
F_84 ( & V_1 -> V_4 . V_155 , V_157 + V_209 ) ;
return;
}
V_196 . V_200 = V_142 ? ( int ) V_142 :
V_1 -> V_4 . V_158 . V_159 ;
V_196 . V_198 = 0 ;
F_114 ( V_1 , F_117 , & V_196 ) ;
V_197 = V_157 ;
V_1 -> V_4 . V_210 = V_197 ;
if ( V_196 . V_198 )
F_84 ( & V_1 -> V_4 . V_155 ,
F_125 ( V_197
+ V_1 -> V_4 . V_158 . V_159 ) ) ;
else
F_126 ( & V_1 -> V_4 . V_155 ) ;
F_127 ( & V_1 -> V_4 . V_208 ) ;
}
static void F_128 ( unsigned long V_82 )
{
F_122 ( 0 , (struct V_1 * ) V_82 , true ) ;
}
static int T_3 F_129 ( struct V_1 * V_1 )
{
T_7 V_211 = sizeof( struct V_52 ) * V_38 ;
F_130 ( & V_1 -> V_4 . V_208 ) ;
F_28 ( & V_1 -> V_4 . V_5 ) ;
F_131 ( & V_1 -> V_4 . V_7 ) ;
F_132 ( & V_1 -> V_4 . V_155 , F_128 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 . V_151 = F_31 ( sizeof( * V_1 -> V_4 . V_151 ) , V_212 ) ;
if ( ! V_1 -> V_4 . V_151 )
goto V_213;
V_211 = F_133 ( T_7 , V_211 , V_214 ) ;
V_1 -> V_4 . V_40 = F_31 ( V_211 , V_212 ) ;
if ( ! V_1 -> V_4 . V_40 )
goto V_215;
V_1 -> V_4 . V_53 = F_31 ( sizeof( * V_1 -> V_4 . V_53 ) ,
V_212 ) ;
if ( ! V_1 -> V_4 . V_53 )
goto V_216;
V_1 -> V_4 . V_53 -> V_37 = V_51 ;
V_1 -> V_4 . V_53 -> V_43 . V_44 = V_1 -> V_4 . V_45 ;
V_1 -> V_4 . V_53 -> V_43 . V_46 =
V_47 | V_48 | V_49 ;
F_32 ( & V_1 -> V_4 . V_53 -> V_50 ) ;
#ifdef F_134
V_1 -> V_4 . V_54 = F_31 ( sizeof( * V_1 -> V_4 . V_54 ) ,
V_212 ) ;
if ( ! V_1 -> V_4 . V_54 )
goto V_217;
V_1 -> V_4 . V_54 -> V_37 = V_218 ;
V_1 -> V_4 . V_54 -> V_43 . V_44 = V_1 -> V_4 . V_45 ;
V_1 -> V_4 . V_54 -> V_43 . V_46 =
V_47 | V_48 | V_49 ;
F_32 ( & V_1 -> V_4 . V_54 -> V_50 ) ;
#endif
F_38 ( V_1 ) ;
return 0 ;
#ifdef F_134
V_217:
F_47 ( V_1 -> V_4 . V_53 ) ;
#endif
V_216:
F_47 ( V_1 -> V_4 . V_40 ) ;
V_215:
F_47 ( V_1 -> V_4 . V_151 ) ;
V_213:
return - V_83 ;
}
static void F_135 ( struct V_1 * V_1 )
{
F_136 ( V_1 , NULL ) ;
F_137 ( & V_1 -> V_4 . V_155 ) ;
#ifdef F_134
F_138 ( & V_1 -> V_4 . V_54 -> V_50 ) ;
F_47 ( V_1 -> V_4 . V_54 ) ;
#endif
F_138 ( & V_1 -> V_4 . V_53 -> V_50 ) ;
F_47 ( V_1 -> V_4 . V_53 ) ;
F_47 ( V_1 -> V_4 . V_40 ) ;
F_47 ( V_1 -> V_4 . V_151 ) ;
}
int T_8 F_139 ( void )
{
int V_219 = - V_83 ;
V_19 = F_140 ( L_19 ,
sizeof( struct V_17 ) ,
0 , V_220 ,
NULL ) ;
if ( ! V_19 )
goto V_86;
V_219 = F_141 ( & V_221 ) ;
if ( V_219 )
goto V_222;
V_219 = F_142 ( V_223 , V_224 , NULL , F_54 ,
NULL ) ;
if ( V_219 )
goto V_225;
V_226 = F_116 ;
V_86:
return V_219 ;
V_225:
F_143 ( & V_221 ) ;
V_222:
F_144 ( V_19 ) ;
goto V_86;
}
void F_145 ( void )
{
F_143 ( & V_221 ) ;
F_144 ( V_19 ) ;
}
static int F_146 ( struct V_227 * V_228 , void * V_229 )
{
struct V_24 * V_31 = V_229 ;
struct V_230 * V_123 = V_228 -> V_231 ;
F_147 ( V_228 , L_20 , & V_31 -> V_162 . V_14 , V_31 -> V_162 . V_89 ) ;
#ifdef F_91
F_147 ( V_228 , L_20 , & V_31 -> V_163 . V_14 , V_31 -> V_163 . V_89 ) ;
#else
F_148 ( V_228 , L_21 ) ;
#endif
if ( V_31 -> V_109 & V_110 )
F_147 ( V_228 , L_22 , & V_31 -> V_205 ) ;
else
F_148 ( V_228 , L_23 ) ;
F_147 ( V_228 , L_24 ,
V_31 -> V_138 , F_8 ( & V_31 -> V_30 . V_160 ) ,
V_31 -> V_30 . V_232 , V_31 -> V_109 ,
V_31 -> V_30 . V_233 ? V_31 -> V_30 . V_233 -> V_234 : L_25 ) ;
V_123 -> V_3 . V_44 = NULL ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_230 * V_123 = V_3 -> args ;
if ( ! V_123 -> V_73 )
return 1 ;
do {
V_123 -> V_3 . V_44 = V_123 -> V_3 . V_44 -> V_30 . V_62 ;
V_123 -> V_73 -- ;
if ( ! V_123 -> V_73 && V_123 -> V_3 . V_44 )
return 1 ;
} while ( V_123 -> V_3 . V_44 );
return 0 ;
}
static void F_150 ( struct V_230 * V_123 ,
struct V_1 * V_1 )
{
memset ( & V_123 -> V_3 , 0 , sizeof( V_123 -> V_3 ) ) ;
V_123 -> V_3 . V_84 = F_149 ;
V_123 -> V_3 . V_71 = & V_123 -> V_235 -> V_43 ;
V_123 -> V_3 . V_75 = V_76 ;
V_123 -> V_3 . V_77 = V_123 -> V_3 . V_71 ;
V_123 -> V_3 . args = V_123 ;
V_123 -> V_93 = V_123 -> V_3 . V_71 -> V_74 ;
F_131 ( & V_123 -> V_3 . V_6 ) ;
F_1 ( V_1 , & V_123 -> V_3 ) ;
}
static struct V_33 * F_151 ( struct V_33 * V_235 ,
struct V_1 * V_1 )
{
unsigned int V_35 ;
struct V_236 * V_77 ;
if ( V_235 ) {
V_35 = ( V_235 -> V_37 & ( V_38 - 1 ) ) + 1 ;
V_77 = F_152 ( F_153 ( & V_235 -> V_39 ) ) ;
} else {
V_35 = 0 ;
V_77 = NULL ;
}
while ( ! V_77 && V_35 < V_38 ) {
V_77 = F_152 (
F_154 ( & V_1 -> V_4 . V_40 [ V_35 ++ ] ) ) ;
}
return F_155 ( V_77 , struct V_33 , V_39 ) ;
}
static void F_156 ( struct V_230 * V_123 )
{
if ( V_123 -> V_93 != V_123 -> V_3 . V_71 -> V_74 ) {
V_123 -> V_93 = V_123 -> V_3 . V_71 -> V_74 ;
V_123 -> V_3 . V_75 = V_76 ;
V_123 -> V_3 . V_77 = V_123 -> V_3 . V_71 ;
F_81 ( V_123 -> V_3 . V_73 ) ;
V_123 -> V_3 . V_73 = V_123 -> V_3 . V_72 ;
}
}
static void * F_157 ( struct V_227 * V_228 , void * V_229 , T_9 * V_237 )
{
int V_238 ;
struct V_24 * V_239 ;
struct V_1 * V_1 = F_158 ( V_228 ) ;
struct V_230 * V_123 = V_228 -> V_231 ;
if ( ! V_229 )
goto V_240;
V_239 = ( (struct V_24 * ) V_229 ) -> V_30 . V_62 ;
if ( V_239 ) {
++ * V_237 ;
return V_239 ;
}
V_240:
F_156 ( V_123 ) ;
F_101 ( & V_123 -> V_235 -> V_36 ) ;
V_238 = F_53 ( & V_123 -> V_3 ) ;
F_103 ( & V_123 -> V_235 -> V_36 ) ;
if ( V_238 > 0 ) {
if ( V_229 )
++ * V_237 ;
return V_123 -> V_3 . V_44 ;
} else if ( V_238 < 0 ) {
F_5 ( V_1 , & V_123 -> V_3 ) ;
return NULL ;
}
F_5 ( V_1 , & V_123 -> V_3 ) ;
V_123 -> V_235 = F_151 ( V_123 -> V_235 , V_1 ) ;
if ( ! V_123 -> V_235 )
return NULL ;
F_150 ( V_123 , V_1 ) ;
goto V_240;
}
static void * F_159 ( struct V_227 * V_228 , T_9 * V_237 )
__acquires( T_10 )
{
struct V_1 * V_1 = F_158 ( V_228 ) ;
struct V_230 * V_123 = V_228 -> V_231 ;
F_160 () ;
V_123 -> V_235 = F_151 ( NULL , V_1 ) ;
V_123 -> V_73 = * V_237 ;
if ( V_123 -> V_235 ) {
F_150 ( V_123 , V_1 ) ;
return F_157 ( V_228 , NULL , V_237 ) ;
} else {
return NULL ;
}
}
static bool F_161 ( struct V_230 * V_123 )
{
struct V_2 * V_3 = & V_123 -> V_3 ;
return V_3 -> V_77 && ! ( V_3 -> V_75 == V_180 && V_3 -> V_77 == V_3 -> V_71 ) ;
}
static void F_162 ( struct V_227 * V_228 , void * V_229 )
__releases( T_10 )
{
struct V_1 * V_1 = F_158 ( V_228 ) ;
struct V_230 * V_123 = V_228 -> V_231 ;
if ( F_161 ( V_123 ) )
F_5 ( V_1 , & V_123 -> V_3 ) ;
F_163 () ;
}
int F_164 ( struct V_241 * V_241 , struct V_242 * V_242 )
{
return F_165 ( V_241 , V_242 , & V_243 ,
sizeof( struct V_230 ) ) ;
}
