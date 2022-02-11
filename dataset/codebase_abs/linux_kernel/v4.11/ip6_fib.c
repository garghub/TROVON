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
if ( V_22 -> V_65 )
V_22 = F_40 ( & V_22 -> V_66 ,
struct V_21 ,
V_66 ) ;
}
V_3 -> V_43 = NULL ;
return 0 ;
}
static void F_41 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_42 ( V_68 -> V_69 -> V_70 ) ;
struct V_2 * V_3 = ( void * ) V_68 -> args [ 2 ] ;
if ( V_3 ) {
if ( V_68 -> args [ 4 ] ) {
V_68 -> args [ 4 ] = 0 ;
F_5 ( V_1 , V_3 ) ;
}
V_68 -> args [ 2 ] = 0 ;
F_43 ( V_3 ) ;
}
V_68 -> V_71 = ( void * ) V_68 -> args [ 3 ] ;
V_68 -> args [ 1 ] = 3 ;
}
static int F_44 ( struct V_67 * V_68 )
{
F_41 ( V_68 ) ;
return V_68 -> V_71 ? V_68 -> V_71 ( V_68 ) : 0 ;
}
static int F_45 ( struct V_32 * V_41 , struct V_72 * V_69 ,
struct V_67 * V_68 )
{
struct V_1 * V_1 = F_42 ( V_69 -> V_70 ) ;
struct V_2 * V_3 ;
int V_63 ;
V_3 = ( void * ) V_68 -> args [ 2 ] ;
V_3 -> V_73 = & V_41 -> V_42 ;
if ( V_68 -> args [ 4 ] == 0 ) {
V_3 -> V_74 = 0 ;
V_3 -> V_75 = 0 ;
F_46 ( & V_41 -> V_35 ) ;
V_63 = F_47 ( V_1 , V_3 ) ;
F_48 ( & V_41 -> V_35 ) ;
if ( V_63 > 0 ) {
V_68 -> args [ 4 ] = 1 ;
V_68 -> args [ 5 ] = V_3 -> V_73 -> V_76 ;
}
} else {
if ( V_68 -> args [ 5 ] != V_3 -> V_73 -> V_76 ) {
V_68 -> args [ 5 ] = V_3 -> V_73 -> V_76 ;
V_3 -> V_77 = V_78 ;
V_3 -> V_79 = V_3 -> V_73 ;
V_3 -> V_75 = V_3 -> V_74 ;
} else
V_3 -> V_75 = 0 ;
F_46 ( & V_41 -> V_35 ) ;
V_63 = F_49 ( V_3 ) ;
F_48 ( & V_41 -> V_35 ) ;
if ( V_63 <= 0 ) {
F_5 ( V_1 , V_3 ) ;
V_68 -> args [ 4 ] = 0 ;
}
}
return V_63 ;
}
static int F_50 ( struct V_72 * V_69 , struct V_67 * V_68 )
{
struct V_1 * V_1 = F_42 ( V_69 -> V_70 ) ;
unsigned int V_34 , V_80 ;
unsigned int V_81 = 0 , V_82 ;
struct V_83 V_84 ;
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
int V_63 = 0 ;
V_80 = V_68 -> args [ 0 ] ;
V_82 = V_68 -> args [ 1 ] ;
V_3 = ( void * ) V_68 -> args [ 2 ] ;
if ( ! V_3 ) {
V_68 -> args [ 3 ] = ( long ) V_68 -> V_71 ;
V_68 -> V_71 = F_44 ;
V_3 = F_27 ( sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_85 ;
V_3 -> V_86 = F_38 ;
V_68 -> args [ 2 ] = ( long ) V_3 ;
}
V_84 . V_69 = V_69 ;
V_84 . V_68 = V_68 ;
V_84 . V_1 = V_1 ;
V_3 -> args = & V_84 ;
F_31 () ;
for ( V_34 = V_80 ; V_34 < V_37 ; V_34 ++ , V_82 = 0 ) {
V_81 = 0 ;
V_52 = & V_1 -> V_4 . V_39 [ V_34 ] ;
F_32 (tb, head, tb6_hlist) {
if ( V_81 < V_82 )
goto V_87;
V_63 = F_45 ( V_33 , V_69 , V_68 ) ;
if ( V_63 != 0 )
goto V_88;
V_87:
V_81 ++ ;
}
}
V_88:
F_33 () ;
V_68 -> args [ 1 ] = V_81 ;
V_68 -> args [ 0 ] = V_34 ;
V_63 = V_63 < 0 ? V_63 : V_69 -> V_89 ;
if ( V_63 <= 0 )
F_41 ( V_68 ) ;
return V_63 ;
}
static struct V_17 * F_51 ( struct V_17 * V_73 ,
struct V_90 * V_14 , int V_91 ,
int V_92 , int V_93 ,
int V_94 , int V_95 )
{
struct V_17 * V_18 , * V_96 , * V_97 ;
struct V_17 * V_98 = NULL ;
struct V_99 * V_100 ;
int V_101 ;
T_1 V_102 = 0 ;
F_52 ( L_1 ) ;
V_18 = V_73 ;
do {
V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_43 + V_92 ) ;
if ( V_91 < V_18 -> V_13 ||
! F_53 ( & V_100 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_93 ) {
if ( V_94 ) {
F_54 ( L_2 ) ;
return F_55 ( - V_104 ) ;
}
F_54 ( L_3 ) ;
}
goto V_105;
}
if ( V_91 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_45 & V_48 ) ) {
F_21 ( V_18 -> V_43 ) ;
V_18 -> V_43 = NULL ;
}
V_18 -> V_76 = V_95 ;
return V_18 ;
}
V_18 -> V_76 = V_95 ;
V_102 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_98 = V_18 ;
V_18 = V_102 ? V_18 -> V_106 : V_18 -> V_107 ;
} while ( V_18 );
if ( ! V_93 ) {
if ( V_94 ) {
F_54 ( L_2 ) ;
return F_55 ( - V_104 ) ;
}
F_54 ( L_3 ) ;
}
V_97 = F_11 () ;
if ( ! V_97 )
return F_55 ( - V_85 ) ;
V_97 -> V_13 = V_91 ;
V_97 -> V_108 = V_98 ;
V_97 -> V_76 = V_95 ;
if ( V_102 )
V_98 -> V_106 = V_97 ;
else
V_98 -> V_107 = V_97 ;
return V_97 ;
V_105:
V_98 = V_18 -> V_108 ;
V_101 = F_56 ( V_14 , & V_100 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_91 > V_101 ) {
V_96 = F_11 () ;
V_97 = F_11 () ;
if ( ! V_96 || ! V_97 ) {
if ( V_96 )
F_13 ( V_96 ) ;
if ( V_97 )
F_13 ( V_97 ) ;
return F_55 ( - V_85 ) ;
}
V_96 -> V_13 = V_101 ;
V_96 -> V_108 = V_98 ;
V_96 -> V_43 = V_18 -> V_43 ;
F_57 ( & V_96 -> V_43 -> V_31 ) ;
V_96 -> V_76 = V_95 ;
if ( V_102 )
V_98 -> V_106 = V_96 ;
else
V_98 -> V_107 = V_96 ;
V_97 -> V_13 = V_91 ;
V_97 -> V_108 = V_96 ;
V_18 -> V_108 = V_96 ;
V_97 -> V_76 = V_95 ;
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
return F_55 ( - V_85 ) ;
V_97 -> V_13 = V_91 ;
V_97 -> V_108 = V_98 ;
V_97 -> V_76 = V_95 ;
if ( V_102 )
V_98 -> V_106 = V_97 ;
else
V_98 -> V_107 = V_97 ;
if ( F_10 ( & V_100 -> V_14 , V_91 ) )
V_97 -> V_106 = V_18 ;
else
V_97 -> V_107 = V_18 ;
V_18 -> V_108 = V_97 ;
}
return V_97 ;
}
static bool F_58 ( struct V_21 * V_22 )
{
return ( V_22 -> V_60 & ( V_109 | V_110 | V_111 ) ) ==
V_109 ;
}
static void F_59 ( T_2 * V_112 , const struct V_113 * V_114 )
{
int V_115 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( F_60 ( V_115 , V_114 -> V_117 ) )
V_112 [ V_115 ] = V_114 -> V_118 [ V_115 ] ;
}
}
static int F_61 ( struct V_55 * V_23 , struct V_113 * V_114 )
{
if ( ! V_114 -> V_118 )
return 0 ;
if ( V_23 -> V_58 & V_119 ) {
T_2 * V_112 = F_62 ( V_23 ) ;
if ( F_63 ( ! V_112 ) )
return - V_85 ;
F_59 ( V_112 , V_114 ) ;
} else {
F_64 ( V_23 , V_114 -> V_118 , false ) ;
V_114 -> V_118 = NULL ;
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
V_18 = V_18 -> V_108 ;
}
F_67 ( F_8 ( & V_22 -> V_31 ) != 1 ) ;
}
}
static int F_68 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_120 * V_121 , struct V_113 * V_114 )
{
struct V_21 * V_122 = NULL ;
struct V_21 * * V_123 ;
struct V_21 * * V_124 = NULL ;
int V_125 = ( V_121 -> V_126 &&
( V_121 -> V_126 -> V_127 & V_128 ) ) ;
int V_129 = ( ! V_121 -> V_126 ||
( V_121 -> V_126 -> V_127 & V_130 ) ) ;
int V_131 = 0 ;
bool V_132 = F_58 ( V_22 ) ;
T_5 V_133 = V_134 ;
int V_135 ;
if ( V_121 -> V_126 && ( V_121 -> V_126 -> V_127 & V_136 ) )
V_133 |= V_136 ;
V_123 = & V_18 -> V_43 ;
for ( V_122 = V_18 -> V_43 ; V_122 ; V_122 = V_122 -> V_23 . V_64 ) {
if ( V_122 -> V_137 == V_22 -> V_137 ) {
if ( V_121 -> V_126 &&
( V_121 -> V_126 -> V_127 & V_134 ) )
return - V_138 ;
V_133 &= ~ V_134 ;
if ( V_125 ) {
if ( V_132 == F_58 ( V_122 ) ) {
V_131 ++ ;
break;
}
if ( V_132 )
V_124 = V_124 ? : V_123 ;
goto V_139;
}
if ( V_122 -> V_23 . V_140 == V_22 -> V_23 . V_140 &&
V_122 -> V_141 == V_22 -> V_141 &&
F_69 ( & V_122 -> V_142 ,
& V_22 -> V_142 ) ) {
if ( V_22 -> V_65 )
V_22 -> V_65 = 0 ;
if ( ! ( V_122 -> V_60 & V_143 ) )
return - V_138 ;
if ( ! ( V_22 -> V_60 & V_143 ) )
F_70 ( V_122 ) ;
else
F_71 ( V_122 , V_22 -> V_23 . V_144 ) ;
V_122 -> V_145 = V_22 -> V_145 ;
return - V_138 ;
}
if ( V_132 &&
F_58 ( V_122 ) )
V_22 -> V_65 ++ ;
}
if ( V_122 -> V_137 > V_22 -> V_137 )
break;
V_139:
V_123 = & V_122 -> V_23 . V_64 ;
}
if ( V_124 && ! V_131 ) {
V_123 = V_124 ;
V_122 = * V_123 ;
V_131 ++ ;
}
if ( V_123 == & V_18 -> V_43 )
V_18 -> V_146 = NULL ;
if ( V_22 -> V_65 ) {
unsigned int V_65 ;
struct V_21 * V_147 , * V_148 ;
V_147 = V_18 -> V_43 ;
while ( V_147 ) {
if ( V_147 -> V_137 == V_22 -> V_137 &&
F_58 ( V_147 ) ) {
F_72 ( & V_22 -> V_66 ,
& V_147 -> V_66 ) ;
break;
}
V_147 = V_147 -> V_23 . V_64 ;
}
V_65 = 0 ;
F_73 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_147 -> V_65 ++ ;
F_67 ( V_147 -> V_65 != V_22 -> V_65 ) ;
V_65 ++ ;
}
F_67 ( V_65 != V_22 -> V_65 ) ;
}
if ( ! V_125 ) {
if ( ! V_129 )
F_54 ( L_3 ) ;
V_129:
V_133 |= V_130 ;
V_135 = F_61 ( & V_22 -> V_23 , V_114 ) ;
if ( V_135 )
return V_135 ;
V_22 -> V_23 . V_64 = V_122 ;
* V_123 = V_22 ;
V_22 -> V_149 = V_18 ;
F_57 ( & V_22 -> V_31 ) ;
if ( ! V_121 -> V_150 )
F_74 ( V_151 , V_22 , V_121 , V_133 ) ;
V_121 -> V_152 -> V_4 . V_153 -> V_154 ++ ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_121 -> V_152 -> V_4 . V_153 -> V_155 ++ ;
V_18 -> V_45 |= V_48 ;
}
} else {
int V_156 ;
if ( ! V_131 ) {
if ( V_129 )
goto V_129;
F_54 ( L_4 ) ;
return - V_104 ;
}
V_135 = F_61 ( & V_22 -> V_23 , V_114 ) ;
if ( V_135 )
return V_135 ;
* V_123 = V_22 ;
V_22 -> V_149 = V_18 ;
V_22 -> V_23 . V_64 = V_122 -> V_23 . V_64 ;
F_57 ( & V_22 -> V_31 ) ;
if ( ! V_121 -> V_150 )
F_74 ( V_151 , V_22 , V_121 , V_128 ) ;
if ( ! ( V_18 -> V_45 & V_48 ) ) {
V_121 -> V_152 -> V_4 . V_153 -> V_155 ++ ;
V_18 -> V_45 |= V_48 ;
}
V_156 = V_122 -> V_65 ;
F_65 ( V_122 , V_18 , V_121 -> V_152 ) ;
F_21 ( V_122 ) ;
if ( V_156 ) {
V_123 = & V_22 -> V_23 . V_64 ;
V_122 = * V_123 ;
while ( V_122 ) {
if ( V_122 -> V_137 > V_22 -> V_137 )
break;
if ( F_58 ( V_122 ) ) {
* V_123 = V_122 -> V_23 . V_64 ;
F_65 ( V_122 , V_18 , V_121 -> V_152 ) ;
F_21 ( V_122 ) ;
V_156 -- ;
} else {
V_123 = & V_122 -> V_23 . V_64 ;
}
V_122 = * V_123 ;
}
F_75 ( V_156 != 0 ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
if ( ! F_77 ( & V_1 -> V_4 . V_157 ) &&
( V_22 -> V_60 & ( V_143 | V_158 ) ) )
F_78 ( & V_1 -> V_4 . V_157 ,
V_159 + V_1 -> V_4 . V_160 . V_161 ) ;
}
void F_79 ( struct V_1 * V_1 )
{
if ( ! F_77 ( & V_1 -> V_4 . V_157 ) )
F_78 ( & V_1 -> V_4 . V_157 ,
V_159 + V_1 -> V_4 . V_160 . V_161 ) ;
}
int F_80 ( struct V_17 * V_73 , struct V_21 * V_22 ,
struct V_120 * V_121 , struct V_113 * V_114 )
{
struct V_17 * V_18 , * V_98 = NULL ;
int V_135 = - V_85 ;
int V_93 = 1 ;
int V_94 = 0 ;
int V_95 = F_7 ( V_121 -> V_152 ) ;
if ( F_81 ( ( V_22 -> V_23 . V_58 & V_162 ) &&
! F_8 ( & V_22 -> V_23 . V_163 ) ) )
return - V_164 ;
if ( V_121 -> V_126 ) {
if ( ! ( V_121 -> V_126 -> V_127 & V_130 ) )
V_93 = 0 ;
if ( V_121 -> V_126 -> V_127 & V_128 )
V_94 = 1 ;
}
if ( ! V_93 && ! V_94 )
F_54 ( L_5 ) ;
V_18 = F_51 ( V_73 , & V_22 -> V_165 . V_14 , V_22 -> V_165 . V_91 ,
F_82 ( struct V_21 , V_165 ) , V_93 ,
V_94 , V_95 ) ;
if ( F_83 ( V_18 ) ) {
V_135 = F_84 ( V_18 ) ;
V_18 = NULL ;
goto V_88;
}
V_98 = V_18 ;
#ifdef F_85
if ( V_22 -> V_166 . V_91 ) {
struct V_17 * V_167 ;
if ( ! V_18 -> V_168 ) {
struct V_17 * V_169 ;
V_169 = F_11 () ;
if ( ! V_169 )
goto V_170;
V_169 -> V_43 = V_121 -> V_152 -> V_4 . V_44 ;
F_57 ( & V_121 -> V_152 -> V_4 . V_44 -> V_31 ) ;
V_169 -> V_45 = V_46 ;
V_169 -> V_76 = V_95 ;
V_167 = F_51 ( V_169 , & V_22 -> V_166 . V_14 ,
V_22 -> V_166 . V_91 ,
F_82 ( struct V_21 , V_166 ) ,
V_93 , V_94 , V_95 ) ;
if ( F_83 ( V_167 ) ) {
F_13 ( V_169 ) ;
V_135 = F_84 ( V_167 ) ;
goto V_170;
}
V_169 -> V_108 = V_18 ;
V_18 -> V_168 = V_169 ;
} else {
V_167 = F_51 ( V_18 -> V_168 , & V_22 -> V_166 . V_14 ,
V_22 -> V_166 . V_91 ,
F_82 ( struct V_21 , V_166 ) ,
V_93 , V_94 , V_95 ) ;
if ( F_83 ( V_167 ) ) {
V_135 = F_84 ( V_167 ) ;
goto V_170;
}
}
if ( ! V_18 -> V_43 ) {
V_18 -> V_43 = V_22 ;
F_57 ( & V_22 -> V_31 ) ;
}
V_18 = V_167 ;
}
#endif
V_135 = F_68 ( V_18 , V_22 , V_121 , V_114 ) ;
if ( ! V_135 ) {
F_76 ( V_121 -> V_152 , V_22 ) ;
if ( ! ( V_22 -> V_60 & V_158 ) )
F_86 ( V_121 -> V_152 , V_98 ) ;
V_22 -> V_23 . V_58 &= ~ V_162 ;
}
V_88:
if ( V_135 ) {
#ifdef F_85
if ( V_98 != V_18 && V_98 -> V_43 == V_22 ) {
V_98 -> V_43 = NULL ;
F_87 ( & V_22 -> V_31 ) ;
}
if ( V_98 != V_18 && ! V_98 -> V_43 && ! ( V_98 -> V_45 & V_48 ) ) {
V_98 -> V_43 = F_66 ( V_121 -> V_152 , V_98 ) ;
#if V_171 >= 2
if ( ! V_98 -> V_43 ) {
F_75 ( V_98 -> V_43 == NULL ) ;
V_98 -> V_43 = V_121 -> V_152 -> V_4 . V_44 ;
}
#endif
F_57 ( & V_98 -> V_43 -> V_31 ) ;
}
#endif
if ( ! ( V_22 -> V_23 . V_58 & V_162 ) )
F_88 ( & V_22 -> V_23 ) ;
}
return V_135 ;
#ifdef F_85
V_170:
if ( V_18 && ! ( V_18 -> V_45 & ( V_48 | V_46 ) ) )
F_89 ( V_121 -> V_152 , V_18 ) ;
if ( ! ( V_22 -> V_23 . V_58 & V_162 ) )
F_88 ( & V_22 -> V_23 ) ;
return V_135 ;
#endif
}
static struct V_17 * F_90 ( struct V_17 * V_73 ,
struct V_172 * args )
{
struct V_17 * V_18 ;
T_1 V_102 ;
if ( F_63 ( args -> V_92 == 0 ) )
return NULL ;
V_18 = V_73 ;
for (; ; ) {
struct V_17 * V_87 ;
V_102 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_87 = V_102 ? V_18 -> V_106 : V_18 -> V_107 ;
if ( V_87 ) {
V_18 = V_87 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_91 ( V_18 ) || V_18 -> V_45 & V_48 ) {
struct V_99 * V_100 ;
V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_43 +
args -> V_92 ) ;
if ( F_53 ( & V_100 -> V_14 , args -> V_14 , V_100 -> V_91 ) ) {
#ifdef F_85
if ( V_18 -> V_168 ) {
struct V_17 * V_169 ;
V_169 = F_90 ( V_18 -> V_168 ,
args + 1 ) ;
if ( ! V_169 )
goto V_173;
V_18 = V_169 ;
}
#endif
if ( V_18 -> V_45 & V_48 )
return V_18 ;
}
}
#ifdef F_85
V_173:
#endif
if ( V_18 -> V_45 & V_46 )
break;
V_18 = V_18 -> V_108 ;
}
return NULL ;
}
struct V_17 * F_92 ( struct V_17 * V_73 , const struct V_90 * V_174 ,
const struct V_90 * V_175 )
{
struct V_17 * V_18 ;
struct V_172 args [] = {
{
. V_92 = F_82 ( struct V_21 , V_165 ) ,
. V_14 = V_174 ,
} ,
#ifdef F_85
{
. V_92 = F_82 ( struct V_21 , V_166 ) ,
. V_14 = V_175 ,
} ,
#endif
{
. V_92 = 0 ,
}
} ;
V_18 = F_90 ( V_73 , V_174 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_45 & V_47 )
V_18 = V_73 ;
return V_18 ;
}
static struct V_17 * F_93 ( struct V_17 * V_73 ,
const struct V_90 * V_14 ,
int V_91 , int V_92 )
{
struct V_17 * V_18 ;
for ( V_18 = V_73 ; V_18 ; ) {
struct V_99 * V_100 = (struct V_99 * ) ( ( V_103 * ) V_18 -> V_43 + V_92 ) ;
if ( V_91 < V_18 -> V_13 ||
! F_53 ( & V_100 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_91 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_106 ;
else
V_18 = V_18 -> V_107 ;
}
return NULL ;
}
struct V_17 * F_94 ( struct V_17 * V_73 ,
const struct V_90 * V_174 , int V_176 ,
const struct V_90 * V_175 , int V_177 )
{
struct V_17 * V_18 ;
V_18 = F_93 ( V_73 , V_174 , V_176 ,
F_82 ( struct V_21 , V_165 ) ) ;
#ifdef F_85
if ( V_177 ) {
F_75 ( V_175 == NULL ) ;
if ( V_18 && V_18 -> V_168 )
V_18 = F_93 ( V_18 -> V_168 , V_175 , V_177 ,
F_82 ( struct V_21 , V_166 ) ) ;
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
if ( V_18 -> V_107 )
return V_18 -> V_107 -> V_43 ;
if ( V_18 -> V_106 )
return V_18 -> V_106 -> V_43 ;
V_18 = F_91 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_89 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
int V_178 ;
int V_179 ;
struct V_17 * V_180 , * V_98 ;
struct V_2 * V_3 ;
int V_122 = 0 ;
for (; ; ) {
F_52 ( L_6 , V_18 -> V_13 , V_122 ) ;
V_122 ++ ;
F_75 ( V_18 -> V_45 & V_48 ) ;
F_75 ( V_18 -> V_45 & V_47 ) ;
F_75 ( V_18 -> V_43 ) ;
V_178 = 0 ;
V_180 = NULL ;
if ( V_18 -> V_106 )
V_180 = V_18 -> V_106 , V_178 |= 1 ;
if ( V_18 -> V_107 )
V_180 = V_18 -> V_107 , V_178 |= 2 ;
if ( V_178 == 3 || F_91 ( V_18 )
#ifdef F_85
|| ( V_178 && V_18 -> V_45 & V_46 )
#endif
) {
V_18 -> V_43 = F_66 ( V_1 , V_18 ) ;
#if V_171 >= 2
if ( ! V_18 -> V_43 ) {
F_75 ( ! V_18 -> V_43 ) ;
V_18 -> V_43 = V_1 -> V_4 . V_44 ;
}
#endif
F_57 ( & V_18 -> V_43 -> V_31 ) ;
return V_18 -> V_108 ;
}
V_98 = V_18 -> V_108 ;
#ifdef F_85
if ( F_91 ( V_98 ) == V_18 ) {
F_75 ( ! ( V_18 -> V_45 & V_46 ) ) ;
F_91 ( V_98 ) = NULL ;
V_179 = V_181 ;
} else {
F_75 ( V_18 -> V_45 & V_46 ) ;
#endif
if ( V_98 -> V_106 == V_18 )
V_98 -> V_106 = V_180 ;
else if ( V_98 -> V_107 == V_18 )
V_98 -> V_107 = V_180 ;
#if V_171 >= 2
else
F_75 ( 1 ) ;
#endif
if ( V_180 )
V_180 -> V_108 = V_98 ;
V_179 = V_182 ;
#ifdef F_85
}
#endif
F_95 ( & V_1 -> V_4 . V_5 ) ;
F_96 (net, w) {
if ( ! V_180 ) {
if ( V_3 -> V_73 == V_18 ) {
V_3 -> V_73 = V_3 -> V_79 = NULL ;
F_52 ( L_7 , V_3 ) ;
} else if ( V_3 -> V_79 == V_18 ) {
F_52 ( L_8 , V_3 , V_3 -> V_77 , V_179 ) ;
V_3 -> V_79 = V_98 ;
V_3 -> V_77 = V_179 ;
}
} else {
if ( V_3 -> V_73 == V_18 ) {
V_3 -> V_73 = V_180 ;
F_52 ( L_9 , V_3 ) ;
}
if ( V_3 -> V_79 == V_18 ) {
V_3 -> V_79 = V_180 ;
if ( V_178 & 2 ) {
F_52 ( L_10 , V_3 , V_3 -> V_77 ) ;
V_3 -> V_77 = V_3 -> V_77 >= V_182 ? V_183 : V_78 ;
} else {
F_52 ( L_10 , V_3 , V_3 -> V_77 ) ;
V_3 -> V_77 = V_3 -> V_77 >= V_184 ? V_183 : V_78 ;
}
}
}
}
F_97 ( & V_1 -> V_4 . V_5 ) ;
F_13 ( V_18 ) ;
if ( V_98 -> V_45 & V_48 || F_91 ( V_98 ) )
return V_98 ;
F_21 ( V_98 -> V_43 ) ;
V_98 -> V_43 = NULL ;
V_18 = V_98 ;
}
}
static void F_98 ( struct V_17 * V_18 , struct V_21 * * V_185 ,
struct V_120 * V_121 )
{
struct V_2 * V_3 ;
struct V_21 * V_22 = * V_185 ;
struct V_1 * V_1 = V_121 -> V_152 ;
F_52 ( L_11 ) ;
* V_185 = V_22 -> V_23 . V_64 ;
V_22 -> V_149 = NULL ;
V_1 -> V_4 . V_153 -> V_154 -- ;
V_1 -> V_4 . V_153 -> V_186 ++ ;
if ( V_18 -> V_146 == V_22 )
V_18 -> V_146 = NULL ;
if ( V_22 -> V_65 ) {
struct V_21 * V_147 , * V_187 ;
F_73 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_147 -> V_65 -- ;
V_22 -> V_65 = 0 ;
F_99 ( & V_22 -> V_66 ) ;
}
F_95 ( & V_1 -> V_4 . V_5 ) ;
F_96 (net, w) {
if ( V_3 -> V_77 == V_184 && V_3 -> V_43 == V_22 ) {
F_52 ( L_12 , V_3 ) ;
V_3 -> V_43 = V_22 -> V_23 . V_64 ;
if ( ! V_3 -> V_43 )
V_3 -> V_77 = V_183 ;
}
}
F_97 ( & V_1 -> V_4 . V_5 ) ;
V_22 -> V_23 . V_64 = NULL ;
if ( ! V_18 -> V_43 ) {
V_18 -> V_45 &= ~ V_48 ;
V_1 -> V_4 . V_153 -> V_155 -- ;
V_18 = F_89 ( V_1 , V_18 ) ;
}
F_65 ( V_22 , V_18 , V_1 ) ;
if ( ! V_121 -> V_150 )
F_74 ( V_188 , V_22 , V_121 , 0 ) ;
F_21 ( V_22 ) ;
}
int F_100 ( struct V_21 * V_22 , struct V_120 * V_121 )
{
struct V_1 * V_1 = V_121 -> V_152 ;
struct V_17 * V_18 = V_22 -> V_149 ;
struct V_21 * * V_185 ;
#if V_171 >= 2
if ( V_22 -> V_23 . V_189 > 0 ) {
F_75 ( V_18 ) ;
return - V_104 ;
}
#endif
if ( ! V_18 || V_22 == V_1 -> V_4 . V_44 )
return - V_104 ;
F_75 ( ! ( V_18 -> V_45 & V_48 ) ) ;
if ( ! ( V_22 -> V_60 & V_158 ) ) {
struct V_17 * V_98 = V_18 ;
#ifdef F_85
if ( V_22 -> V_166 . V_91 ) {
while ( ! ( V_98 -> V_45 & V_46 ) )
V_98 = V_98 -> V_108 ;
V_98 = V_98 -> V_108 ;
}
#endif
F_86 ( V_121 -> V_152 , V_98 ) ;
}
for ( V_185 = & V_18 -> V_43 ; * V_185 ; V_185 = & ( * V_185 ) -> V_23 . V_64 ) {
if ( * V_185 == V_22 ) {
F_98 ( V_18 , V_185 , V_121 ) ;
return 0 ;
}
}
return - V_104 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_17 * V_18 , * V_98 ;
for (; ; ) {
V_18 = V_3 -> V_79 ;
if ( ! V_18 )
return 0 ;
if ( V_3 -> V_190 && V_18 != V_3 -> V_73 &&
V_18 -> V_45 & V_48 && V_3 -> V_77 < V_184 ) {
V_3 -> V_77 = V_184 ;
V_3 -> V_43 = V_18 -> V_43 ;
}
switch ( V_3 -> V_77 ) {
#ifdef F_85
case V_191 :
if ( F_91 ( V_18 ) ) {
V_3 -> V_79 = F_91 ( V_18 ) ;
continue;
}
V_3 -> V_77 = V_181 ;
#endif
case V_181 :
if ( V_18 -> V_107 ) {
V_3 -> V_79 = V_18 -> V_107 ;
V_3 -> V_77 = V_78 ;
continue;
}
V_3 -> V_77 = V_182 ;
case V_182 :
if ( V_18 -> V_106 ) {
V_3 -> V_79 = V_18 -> V_106 ;
V_3 -> V_77 = V_78 ;
continue;
}
V_3 -> V_77 = V_184 ;
V_3 -> V_43 = V_18 -> V_43 ;
case V_184 :
if ( V_3 -> V_43 && V_18 -> V_45 & V_48 ) {
int V_135 ;
if ( V_3 -> V_75 ) {
V_3 -> V_75 -- ;
goto V_75;
}
V_135 = V_3 -> V_86 ( V_3 ) ;
if ( V_135 )
return V_135 ;
V_3 -> V_74 ++ ;
continue;
}
V_75:
V_3 -> V_77 = V_183 ;
case V_183 :
if ( V_18 == V_3 -> V_73 )
return 0 ;
V_98 = V_18 -> V_108 ;
V_3 -> V_79 = V_98 ;
#ifdef F_85
if ( F_91 ( V_98 ) == V_18 ) {
F_75 ( ! ( V_18 -> V_45 & V_46 ) ) ;
V_3 -> V_77 = V_181 ;
continue;
}
#endif
if ( V_98 -> V_107 == V_18 ) {
V_3 -> V_77 = V_182 ;
continue;
}
if ( V_98 -> V_106 == V_18 ) {
V_3 -> V_77 = V_184 ;
V_3 -> V_43 = V_3 -> V_79 -> V_43 ;
continue;
}
#if V_171 >= 2
F_75 ( 1 ) ;
#endif
}
}
}
static int F_47 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_63 ;
V_3 -> V_77 = V_78 ;
V_3 -> V_79 = V_3 -> V_73 ;
F_1 ( V_1 , V_3 ) ;
V_63 = F_49 ( V_3 ) ;
if ( V_63 <= 0 )
F_5 ( V_1 , V_3 ) ;
return V_63 ;
}
static int F_101 ( struct V_2 * V_3 )
{
int V_63 ;
struct V_21 * V_22 ;
struct V_192 * V_193 = F_102 ( V_3 , struct V_192 , V_3 ) ;
struct V_120 V_121 = {
. V_152 = V_193 -> V_1 ,
} ;
if ( V_193 -> V_95 != V_194 &&
V_3 -> V_79 -> V_76 != V_193 -> V_95 )
V_3 -> V_79 -> V_76 = V_193 -> V_95 ;
if ( ! V_193 -> V_86 ) {
F_81 ( V_193 -> V_95 == V_194 ) ;
V_3 -> V_43 = NULL ;
return 0 ;
}
for ( V_22 = V_3 -> V_43 ; V_22 ; V_22 = V_22 -> V_23 . V_64 ) {
V_63 = V_193 -> V_86 ( V_22 , V_193 -> V_84 ) ;
if ( V_63 < 0 ) {
V_3 -> V_43 = V_22 ;
V_63 = F_100 ( V_22 , & V_121 ) ;
if ( V_63 ) {
#if V_171 >= 2
F_103 ( L_13 ,
V_195 , V_22 , V_22 -> V_149 , V_63 ) ;
#endif
continue;
}
return 0 ;
}
F_75 ( V_63 != 0 ) ;
}
V_3 -> V_43 = V_22 ;
return 0 ;
}
static void F_104 ( struct V_1 * V_1 , struct V_17 * V_73 ,
int (* V_86)( struct V_21 * , void * V_84 ) ,
bool V_190 , int V_95 , void * V_84 )
{
struct V_192 V_193 ;
V_193 . V_3 . V_73 = V_73 ;
V_193 . V_3 . V_86 = F_101 ;
V_193 . V_3 . V_190 = V_190 ;
V_193 . V_3 . V_74 = 0 ;
V_193 . V_3 . V_75 = 0 ;
V_193 . V_86 = V_86 ;
V_193 . V_95 = V_95 ;
V_193 . V_84 = V_84 ;
V_193 . V_1 = V_1 ;
F_47 ( V_1 , & V_193 . V_3 ) ;
}
static void F_105 ( struct V_1 * V_1 ,
int (* V_86)( struct V_21 * , void * ) ,
int V_95 , void * V_84 )
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
V_86 , false , V_95 , V_84 ) ;
F_4 ( & V_41 -> V_35 ) ;
}
}
F_33 () ;
}
void F_106 ( struct V_1 * V_1 , int (* V_86)( struct V_21 * , void * ) ,
void * V_84 )
{
F_105 ( V_1 , V_86 , V_194 , V_84 ) ;
}
static int F_107 ( struct V_21 * V_22 , void * V_84 )
{
if ( V_22 -> V_60 & V_158 ) {
F_52 ( L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_86 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
F_104 ( V_1 , V_18 , F_107 , true ,
V_194 , NULL ) ;
}
static void F_108 ( struct V_1 * V_1 )
{
int V_196 = F_7 ( V_1 ) ;
F_105 ( V_1 , NULL , V_196 , NULL ) ;
}
static int F_109 ( struct V_21 * V_22 , void * V_84 )
{
struct V_197 * V_198 = V_84 ;
unsigned long V_199 = V_159 ;
if ( V_22 -> V_60 & V_143 && V_22 -> V_23 . V_144 ) {
if ( F_110 ( V_199 , V_22 -> V_23 . V_144 ) ) {
F_52 ( L_15 , V_22 ) ;
return - 1 ;
}
V_198 -> V_200 ++ ;
} else if ( V_22 -> V_60 & V_158 ) {
if ( F_8 ( & V_22 -> V_23 . V_163 ) == 0 &&
F_111 ( V_199 , V_22 -> V_23 . V_201 + V_198 -> V_202 ) ) {
F_52 ( L_16 , V_22 ) ;
return - 1 ;
} else if ( V_22 -> V_60 & V_109 ) {
struct V_203 * V_204 ;
T_6 V_205 = 0 ;
V_204 = F_112 ( & V_22 -> V_23 , & V_22 -> V_142 ) ;
if ( V_204 ) {
V_205 = V_204 -> V_58 ;
F_113 ( V_204 ) ;
}
if ( ! ( V_205 & V_206 ) ) {
F_52 ( L_17 ,
V_22 ) ;
return - 1 ;
}
}
V_198 -> V_200 ++ ;
}
return 0 ;
}
void F_114 ( unsigned long V_144 , struct V_1 * V_1 , bool V_207 )
{
struct V_197 V_198 ;
unsigned long V_199 ;
if ( V_207 ) {
F_115 ( & V_1 -> V_4 . V_208 ) ;
} else if ( ! F_116 ( & V_1 -> V_4 . V_208 ) ) {
F_78 ( & V_1 -> V_4 . V_157 , V_159 + V_209 ) ;
return;
}
V_198 . V_202 = V_144 ? ( int ) V_144 :
V_1 -> V_4 . V_160 . V_161 ;
V_198 . V_200 = F_117 () ;
F_106 ( V_1 , F_109 , & V_198 ) ;
V_199 = V_159 ;
V_1 -> V_4 . V_210 = V_199 ;
if ( V_198 . V_200 )
F_78 ( & V_1 -> V_4 . V_157 ,
F_118 ( V_199
+ V_1 -> V_4 . V_160 . V_161 ) ) ;
else
F_119 ( & V_1 -> V_4 . V_157 ) ;
F_120 ( & V_1 -> V_4 . V_208 ) ;
}
static void F_121 ( unsigned long V_84 )
{
F_114 ( 0 , (struct V_1 * ) V_84 , true ) ;
}
static int T_3 F_122 ( struct V_1 * V_1 )
{
T_7 V_211 = sizeof( struct V_51 ) * V_37 ;
F_123 ( & V_1 -> V_4 . V_208 ) ;
F_24 ( & V_1 -> V_4 . V_5 ) ;
F_124 ( & V_1 -> V_4 . V_7 ) ;
F_125 ( & V_1 -> V_4 . V_157 , F_121 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 . V_153 = F_27 ( sizeof( * V_1 -> V_4 . V_153 ) , V_212 ) ;
if ( ! V_1 -> V_4 . V_153 )
goto V_213;
V_211 = F_126 ( T_7 , V_211 , V_214 ) ;
V_1 -> V_4 . V_39 = F_27 ( V_211 , V_212 ) ;
if ( ! V_1 -> V_4 . V_39 )
goto V_215;
V_1 -> V_4 . V_53 = F_27 ( sizeof( * V_1 -> V_4 . V_53 ) ,
V_212 ) ;
if ( ! V_1 -> V_4 . V_53 )
goto V_216;
V_1 -> V_4 . V_53 -> V_36 = V_50 ;
V_1 -> V_4 . V_53 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_53 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
#ifdef F_127
V_1 -> V_4 . V_54 = F_27 ( sizeof( * V_1 -> V_4 . V_54 ) ,
V_212 ) ;
if ( ! V_1 -> V_4 . V_54 )
goto V_217;
V_1 -> V_4 . V_54 -> V_36 = V_218 ;
V_1 -> V_4 . V_54 -> V_42 . V_43 = V_1 -> V_4 . V_44 ;
V_1 -> V_4 . V_54 -> V_42 . V_45 =
V_46 | V_47 | V_48 ;
F_28 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
#endif
F_34 ( V_1 ) ;
return 0 ;
#ifdef F_127
V_217:
F_43 ( V_1 -> V_4 . V_53 ) ;
#endif
V_216:
F_43 ( V_1 -> V_4 . V_39 ) ;
V_215:
F_43 ( V_1 -> V_4 . V_153 ) ;
V_213:
return - V_85 ;
}
static void F_128 ( struct V_1 * V_1 )
{
F_129 ( V_1 , NULL ) ;
F_130 ( & V_1 -> V_4 . V_157 ) ;
#ifdef F_127
F_131 ( & V_1 -> V_4 . V_54 -> V_49 ) ;
F_43 ( V_1 -> V_4 . V_54 ) ;
#endif
F_131 ( & V_1 -> V_4 . V_53 -> V_49 ) ;
F_43 ( V_1 -> V_4 . V_53 ) ;
F_43 ( V_1 -> V_4 . V_39 ) ;
F_43 ( V_1 -> V_4 . V_153 ) ;
}
int T_8 F_132 ( void )
{
int V_219 = - V_85 ;
V_19 = F_133 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_220 ,
NULL ) ;
if ( ! V_19 )
goto V_88;
V_219 = F_134 ( & V_221 ) ;
if ( V_219 )
goto V_222;
V_219 = F_135 ( V_223 , V_224 , NULL , F_50 ,
NULL ) ;
if ( V_219 )
goto V_225;
V_226 = F_108 ;
V_88:
return V_219 ;
V_225:
F_136 ( & V_221 ) ;
V_222:
F_137 ( V_19 ) ;
goto V_88;
}
void F_138 ( void )
{
F_136 ( & V_221 ) ;
F_137 ( V_19 ) ;
}
static int F_139 ( struct V_227 * V_228 , void * V_229 )
{
struct V_21 * V_22 = V_229 ;
struct V_230 * V_122 = V_228 -> V_231 ;
F_140 ( V_228 , L_19 , & V_22 -> V_165 . V_14 , V_22 -> V_165 . V_91 ) ;
#ifdef F_85
F_140 ( V_228 , L_19 , & V_22 -> V_166 . V_14 , V_22 -> V_166 . V_91 ) ;
#else
F_141 ( V_228 , L_20 ) ;
#endif
if ( V_22 -> V_60 & V_109 )
F_140 ( V_228 , L_21 , & V_22 -> V_142 ) ;
else
F_141 ( V_228 , L_22 ) ;
F_140 ( V_228 , L_23 ,
V_22 -> V_137 , F_8 ( & V_22 -> V_23 . V_163 ) ,
V_22 -> V_23 . V_232 , V_22 -> V_60 ,
V_22 -> V_23 . V_140 ? V_22 -> V_23 . V_140 -> V_233 : L_24 ) ;
V_122 -> V_3 . V_43 = NULL ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_230 * V_122 = V_3 -> args ;
if ( ! V_122 -> V_75 )
return 1 ;
do {
V_122 -> V_3 . V_43 = V_122 -> V_3 . V_43 -> V_23 . V_64 ;
V_122 -> V_75 -- ;
if ( ! V_122 -> V_75 && V_122 -> V_3 . V_43 )
return 1 ;
} while ( V_122 -> V_3 . V_43 );
return 0 ;
}
static void F_143 ( struct V_230 * V_122 ,
struct V_1 * V_1 )
{
memset ( & V_122 -> V_3 , 0 , sizeof( V_122 -> V_3 ) ) ;
V_122 -> V_3 . V_86 = F_142 ;
V_122 -> V_3 . V_73 = & V_122 -> V_234 -> V_42 ;
V_122 -> V_3 . V_77 = V_78 ;
V_122 -> V_3 . V_79 = V_122 -> V_3 . V_73 ;
V_122 -> V_3 . args = V_122 ;
V_122 -> V_95 = V_122 -> V_3 . V_73 -> V_76 ;
F_124 ( & V_122 -> V_3 . V_6 ) ;
F_1 ( V_1 , & V_122 -> V_3 ) ;
}
static struct V_32 * F_144 ( struct V_32 * V_234 ,
struct V_1 * V_1 )
{
unsigned int V_34 ;
struct V_235 * V_79 ;
if ( V_234 ) {
V_34 = ( V_234 -> V_36 & ( V_37 - 1 ) ) + 1 ;
V_79 = F_145 ( F_146 ( & V_234 -> V_38 ) ) ;
} else {
V_34 = 0 ;
V_79 = NULL ;
}
while ( ! V_79 && V_34 < V_37 ) {
V_79 = F_145 (
F_147 ( & V_1 -> V_4 . V_39 [ V_34 ++ ] ) ) ;
}
return F_148 ( V_79 , struct V_32 , V_38 ) ;
}
static void F_149 ( struct V_230 * V_122 )
{
if ( V_122 -> V_95 != V_122 -> V_3 . V_73 -> V_76 ) {
V_122 -> V_95 = V_122 -> V_3 . V_73 -> V_76 ;
V_122 -> V_3 . V_77 = V_78 ;
V_122 -> V_3 . V_79 = V_122 -> V_3 . V_73 ;
F_75 ( V_122 -> V_3 . V_75 ) ;
V_122 -> V_3 . V_75 = V_122 -> V_3 . V_74 ;
}
}
static void * F_150 ( struct V_227 * V_228 , void * V_229 , T_9 * V_236 )
{
int V_237 ;
struct V_21 * V_238 ;
struct V_1 * V_1 = F_151 ( V_228 ) ;
struct V_230 * V_122 = V_228 -> V_231 ;
if ( ! V_229 )
goto V_239;
V_238 = ( (struct V_21 * ) V_229 ) -> V_23 . V_64 ;
if ( V_238 ) {
++ * V_236 ;
return V_238 ;
}
V_239:
F_149 ( V_122 ) ;
F_95 ( & V_122 -> V_234 -> V_35 ) ;
V_237 = F_49 ( & V_122 -> V_3 ) ;
F_97 ( & V_122 -> V_234 -> V_35 ) ;
if ( V_237 > 0 ) {
if ( V_229 )
++ * V_236 ;
return V_122 -> V_3 . V_43 ;
} else if ( V_237 < 0 ) {
F_5 ( V_1 , & V_122 -> V_3 ) ;
return NULL ;
}
F_5 ( V_1 , & V_122 -> V_3 ) ;
V_122 -> V_234 = F_144 ( V_122 -> V_234 , V_1 ) ;
if ( ! V_122 -> V_234 )
return NULL ;
F_143 ( V_122 , V_1 ) ;
goto V_239;
}
static void * F_152 ( struct V_227 * V_228 , T_9 * V_236 )
__acquires( T_10 )
{
struct V_1 * V_1 = F_151 ( V_228 ) ;
struct V_230 * V_122 = V_228 -> V_231 ;
F_153 () ;
V_122 -> V_234 = F_144 ( NULL , V_1 ) ;
V_122 -> V_75 = * V_236 ;
if ( V_122 -> V_234 ) {
F_143 ( V_122 , V_1 ) ;
return F_150 ( V_228 , NULL , V_236 ) ;
} else {
return NULL ;
}
}
static bool F_154 ( struct V_230 * V_122 )
{
struct V_2 * V_3 = & V_122 -> V_3 ;
return V_3 -> V_79 && ! ( V_3 -> V_77 == V_183 && V_3 -> V_79 == V_3 -> V_73 ) ;
}
static void F_155 ( struct V_227 * V_228 , void * V_229 )
__releases( T_10 )
{
struct V_1 * V_1 = F_151 ( V_228 ) ;
struct V_230 * V_122 = V_228 -> V_231 ;
if ( F_154 ( V_122 ) )
F_5 ( V_1 , & V_122 -> V_3 ) ;
F_156 () ;
}
int F_157 ( struct V_240 * V_240 , struct V_241 * V_241 )
{
return F_158 ( V_240 , V_241 , & V_242 ,
sizeof( struct V_230 ) ) ;
}
