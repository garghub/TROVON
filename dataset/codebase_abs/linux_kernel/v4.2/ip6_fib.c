static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static int F_7 ( struct V_6 * V_6 )
{
int V_7 , V_8 ;
do {
V_8 = F_8 ( & V_6 -> V_9 . V_10 ) ;
V_7 = V_8 < V_11 ? V_8 + 1 : 1 ;
} while ( F_9 ( & V_6 -> V_9 . V_10 ,
V_8 , V_7 ) != V_8 );
return V_7 ;
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
int V_23 ;
if ( ! V_22 -> V_24 )
return;
F_16 (cpu) {
struct V_21 * * V_25 ;
struct V_21 * V_26 ;
V_25 = F_17 ( V_22 -> V_24 , V_23 ) ;
V_26 = * V_25 ;
if ( V_26 ) {
F_18 ( & V_26 -> V_27 ) ;
* V_25 = NULL ;
}
}
V_22 -> V_24 = NULL ;
}
static void F_19 ( struct V_21 * V_28 )
{
if ( F_20 ( & V_28 -> V_29 ) ) {
F_15 ( V_28 ) ;
F_18 ( & V_28 -> V_27 ) ;
}
}
static void F_21 ( struct V_6 * V_6 , struct V_30 * V_31 )
{
unsigned int V_32 ;
F_22 ( & V_31 -> V_33 ) ;
V_32 = V_31 -> V_34 & ( V_35 - 1 ) ;
F_23 ( & V_31 -> V_36 , & V_6 -> V_9 . V_37 [ V_32 ] ) ;
}
static struct V_30 * F_24 ( struct V_6 * V_6 , T_2 V_38 )
{
struct V_30 * V_39 ;
V_39 = F_25 ( sizeof( * V_39 ) , V_20 ) ;
if ( V_39 ) {
V_39 -> V_34 = V_38 ;
V_39 -> V_40 . V_41 = V_6 -> V_9 . V_42 ;
V_39 -> V_40 . V_43 = V_44 | V_45 | V_46 ;
F_26 ( & V_39 -> V_47 ) ;
}
return V_39 ;
}
struct V_30 * F_27 ( struct V_6 * V_6 , T_2 V_38 )
{
struct V_30 * V_31 ;
if ( V_38 == 0 )
V_38 = V_48 ;
V_31 = F_28 ( V_6 , V_38 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_24 ( V_6 , V_38 ) ;
if ( V_31 )
F_21 ( V_6 , V_31 ) ;
return V_31 ;
}
struct V_30 * F_28 ( struct V_6 * V_6 , T_2 V_38 )
{
struct V_30 * V_31 ;
struct V_49 * V_50 ;
unsigned int V_32 ;
if ( V_38 == 0 )
V_38 = V_48 ;
V_32 = V_38 & ( V_35 - 1 ) ;
F_29 () ;
V_50 = & V_6 -> V_9 . V_37 [ V_32 ] ;
F_30 (tb, head, tb6_hlist) {
if ( V_31 -> V_34 == V_38 ) {
F_31 () ;
return V_31 ;
}
}
F_31 () ;
return NULL ;
}
static void T_3 F_32 ( struct V_6 * V_6 )
{
F_21 ( V_6 , V_6 -> V_9 . V_51 ) ;
F_21 ( V_6 , V_6 -> V_9 . V_52 ) ;
}
struct V_30 * F_27 ( struct V_6 * V_6 , T_2 V_38 )
{
return F_28 ( V_6 , V_38 ) ;
}
struct V_30 * F_28 ( struct V_6 * V_6 , T_2 V_38 )
{
return V_6 -> V_9 . V_51 ;
}
struct V_53 * F_33 ( struct V_6 * V_6 , struct V_54 * V_55 ,
int V_56 , T_4 V_57 )
{
return (struct V_53 * ) V_57 ( V_6 , V_6 -> V_9 . V_51 , V_55 , V_56 ) ;
}
static void T_3 F_32 ( struct V_6 * V_6 )
{
F_21 ( V_6 , V_6 -> V_9 . V_51 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_58 ;
struct V_21 * V_28 ;
for ( V_28 = V_2 -> V_41 ; V_28 ; V_28 = V_28 -> V_27 . V_59 ) {
V_58 = F_35 ( V_28 , V_2 -> args ) ;
if ( V_58 < 0 ) {
V_2 -> V_41 = V_28 ;
return 1 ;
}
}
V_2 -> V_41 = NULL ;
return 0 ;
}
static void F_36 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = ( void * ) V_61 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_61 -> args [ 4 ] ) {
V_61 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_61 -> args [ 2 ] = 0 ;
F_37 ( V_2 ) ;
}
V_61 -> V_62 = ( void * ) V_61 -> args [ 3 ] ;
V_61 -> args [ 1 ] = 3 ;
}
static int F_38 ( struct V_60 * V_61 )
{
F_36 ( V_61 ) ;
return V_61 -> V_62 ? V_61 -> V_62 ( V_61 ) : 0 ;
}
static int F_39 ( struct V_30 * V_39 , struct V_63 * V_64 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = ( void * ) V_61 -> args [ 2 ] ;
V_2 -> V_65 = & V_39 -> V_40 ;
if ( V_61 -> args [ 4 ] == 0 ) {
V_2 -> V_66 = 0 ;
V_2 -> V_67 = 0 ;
F_40 ( & V_39 -> V_33 ) ;
V_58 = F_41 ( V_2 ) ;
F_42 ( & V_39 -> V_33 ) ;
if ( V_58 > 0 ) {
V_61 -> args [ 4 ] = 1 ;
V_61 -> args [ 5 ] = V_2 -> V_65 -> V_68 ;
}
} else {
if ( V_61 -> args [ 5 ] != V_2 -> V_65 -> V_68 ) {
V_61 -> args [ 5 ] = V_2 -> V_65 -> V_68 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_71 = V_2 -> V_65 ;
V_2 -> V_67 = V_2 -> V_66 ;
} else
V_2 -> V_67 = 0 ;
F_40 ( & V_39 -> V_33 ) ;
V_58 = F_43 ( V_2 ) ;
F_42 ( & V_39 -> V_33 ) ;
if ( V_58 <= 0 ) {
F_5 ( V_2 ) ;
V_61 -> args [ 4 ] = 0 ;
}
}
return V_58 ;
}
static int F_44 ( struct V_63 * V_64 , struct V_60 * V_61 )
{
struct V_6 * V_6 = F_45 ( V_64 -> V_72 ) ;
unsigned int V_32 , V_73 ;
unsigned int V_74 = 0 , V_75 ;
struct V_76 V_77 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_49 * V_50 ;
int V_58 = 0 ;
V_73 = V_61 -> args [ 0 ] ;
V_75 = V_61 -> args [ 1 ] ;
V_2 = ( void * ) V_61 -> args [ 2 ] ;
if ( ! V_2 ) {
V_61 -> args [ 3 ] = ( long ) V_61 -> V_62 ;
V_61 -> V_62 = F_38 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_79 = F_34 ;
V_61 -> args [ 2 ] = ( long ) V_2 ;
}
V_77 . V_64 = V_64 ;
V_77 . V_61 = V_61 ;
V_77 . V_6 = V_6 ;
V_2 -> args = & V_77 ;
F_29 () ;
for ( V_32 = V_73 ; V_32 < V_35 ; V_32 ++ , V_75 = 0 ) {
V_74 = 0 ;
V_50 = & V_6 -> V_9 . V_37 [ V_32 ] ;
F_30 (tb, head, tb6_hlist) {
if ( V_74 < V_75 )
goto V_80;
V_58 = F_39 ( V_31 , V_64 , V_61 ) ;
if ( V_58 != 0 )
goto V_81;
V_80:
V_74 ++ ;
}
}
V_81:
F_31 () ;
V_61 -> args [ 1 ] = V_74 ;
V_61 -> args [ 0 ] = V_32 ;
V_58 = V_58 < 0 ? V_58 : V_64 -> V_82 ;
if ( V_58 <= 0 )
F_36 ( V_61 ) ;
return V_58 ;
}
static struct V_17 * F_46 ( struct V_17 * V_65 ,
struct V_83 * V_14 , int V_84 ,
int V_85 , int V_86 ,
int V_87 , int V_88 )
{
struct V_17 * V_18 , * V_89 , * V_90 ;
struct V_17 * V_91 = NULL ;
struct V_92 * V_93 ;
int V_94 ;
T_1 V_95 = 0 ;
F_47 ( L_1 ) ;
V_18 = V_65 ;
do {
V_93 = (struct V_92 * ) ( ( V_96 * ) V_18 -> V_41 + V_85 ) ;
if ( V_84 < V_18 -> V_13 ||
! F_48 ( & V_93 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_86 ) {
if ( V_87 ) {
F_49 ( L_2 ) ;
return F_50 ( - V_97 ) ;
}
F_49 ( L_3 ) ;
}
goto V_98;
}
if ( V_84 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_43 & V_46 ) ) {
F_19 ( V_18 -> V_41 ) ;
V_18 -> V_41 = NULL ;
}
V_18 -> V_68 = V_88 ;
return V_18 ;
}
V_18 -> V_68 = V_88 ;
V_95 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_91 = V_18 ;
V_18 = V_95 ? V_18 -> V_99 : V_18 -> V_100 ;
} while ( V_18 );
if ( ! V_86 ) {
if ( V_87 ) {
F_49 ( L_2 ) ;
return F_50 ( - V_97 ) ;
}
F_49 ( L_3 ) ;
}
V_90 = F_11 () ;
if ( ! V_90 )
return F_50 ( - V_78 ) ;
V_90 -> V_13 = V_84 ;
V_90 -> V_101 = V_91 ;
V_90 -> V_68 = V_88 ;
if ( V_95 )
V_91 -> V_99 = V_90 ;
else
V_91 -> V_100 = V_90 ;
return V_90 ;
V_98:
V_91 = V_18 -> V_101 ;
V_94 = F_51 ( V_14 , & V_93 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_84 > V_94 ) {
V_89 = F_11 () ;
V_90 = F_11 () ;
if ( ! V_89 || ! V_90 ) {
if ( V_89 )
F_13 ( V_89 ) ;
if ( V_90 )
F_13 ( V_90 ) ;
return F_50 ( - V_78 ) ;
}
V_89 -> V_13 = V_94 ;
V_89 -> V_101 = V_91 ;
V_89 -> V_41 = V_18 -> V_41 ;
F_52 ( & V_89 -> V_41 -> V_29 ) ;
V_89 -> V_68 = V_88 ;
if ( V_95 )
V_91 -> V_99 = V_89 ;
else
V_91 -> V_100 = V_89 ;
V_90 -> V_13 = V_84 ;
V_90 -> V_101 = V_89 ;
V_18 -> V_101 = V_89 ;
V_90 -> V_68 = V_88 ;
if ( F_10 ( V_14 , V_94 ) ) {
V_89 -> V_99 = V_90 ;
V_89 -> V_100 = V_18 ;
} else {
V_89 -> V_100 = V_90 ;
V_89 -> V_99 = V_18 ;
}
} else {
V_90 = F_11 () ;
if ( ! V_90 )
return F_50 ( - V_78 ) ;
V_90 -> V_13 = V_84 ;
V_90 -> V_101 = V_91 ;
V_90 -> V_68 = V_88 ;
if ( V_95 )
V_91 -> V_99 = V_90 ;
else
V_91 -> V_100 = V_90 ;
if ( F_10 ( & V_93 -> V_14 , V_84 ) )
V_90 -> V_99 = V_18 ;
else
V_90 -> V_100 = V_18 ;
V_18 -> V_101 = V_90 ;
}
return V_90 ;
}
static bool F_53 ( struct V_21 * V_28 )
{
return ( V_28 -> V_102 & ( V_103 | V_104 | V_105 ) ) ==
V_103 ;
}
static void F_54 ( T_2 * V_106 , const struct V_107 * V_108 )
{
int V_109 ;
for ( V_109 = 0 ; V_109 < V_110 ; V_109 ++ ) {
if ( F_55 ( V_109 , V_108 -> V_111 ) )
V_106 [ V_109 ] = V_108 -> V_112 [ V_109 ] ;
}
}
static int F_56 ( struct V_53 * V_27 , struct V_107 * V_108 )
{
if ( ! V_108 -> V_112 )
return 0 ;
if ( V_27 -> V_56 & V_113 ) {
T_2 * V_106 = F_57 ( V_27 ) ;
if ( F_58 ( ! V_106 ) )
return - V_78 ;
F_54 ( V_106 , V_108 ) ;
} else {
F_59 ( V_27 , V_108 -> V_112 , false ) ;
V_108 -> V_112 = NULL ;
}
return 0 ;
}
static void F_60 ( struct V_21 * V_28 , struct V_17 * V_18 ,
struct V_6 * V_6 )
{
if ( F_8 ( & V_28 -> V_29 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_43 & V_46 ) && V_18 -> V_41 == V_28 ) {
V_18 -> V_41 = F_61 ( V_6 , V_18 ) ;
F_52 ( & V_18 -> V_41 -> V_29 ) ;
F_19 ( V_28 ) ;
}
V_18 = V_18 -> V_101 ;
}
F_62 ( F_8 ( & V_28 -> V_29 ) != 1 ) ;
}
}
static int F_63 ( struct V_17 * V_18 , struct V_21 * V_28 ,
struct V_114 * V_115 , struct V_107 * V_108 )
{
struct V_21 * V_116 = NULL ;
struct V_21 * * V_117 ;
struct V_21 * * V_118 = NULL ;
int V_119 = ( V_115 -> V_120 &&
( V_115 -> V_120 -> V_121 & V_122 ) ) ;
int V_123 = ( ! V_115 -> V_120 ||
( V_115 -> V_120 -> V_121 & V_124 ) ) ;
int V_125 = 0 ;
bool V_126 = F_53 ( V_28 ) ;
int V_127 ;
V_117 = & V_18 -> V_41 ;
for ( V_116 = V_18 -> V_41 ; V_116 ; V_116 = V_116 -> V_27 . V_59 ) {
if ( V_116 -> V_128 == V_28 -> V_128 ) {
if ( V_115 -> V_120 &&
( V_115 -> V_120 -> V_121 & V_129 ) )
return - V_130 ;
if ( V_119 ) {
if ( V_126 == F_53 ( V_116 ) ) {
V_125 ++ ;
break;
}
if ( V_126 )
V_118 = V_118 ? : V_117 ;
goto V_131;
}
if ( V_116 -> V_27 . V_132 == V_28 -> V_27 . V_132 &&
V_116 -> V_133 == V_28 -> V_133 &&
F_64 ( & V_116 -> V_134 ,
& V_28 -> V_134 ) ) {
if ( V_28 -> V_135 )
V_28 -> V_135 = 0 ;
if ( ! ( V_116 -> V_102 & V_136 ) )
return - V_130 ;
if ( ! ( V_28 -> V_102 & V_136 ) )
F_65 ( V_116 ) ;
else
F_66 ( V_116 , V_28 -> V_27 . V_137 ) ;
V_116 -> V_138 = V_28 -> V_138 ;
return - V_130 ;
}
if ( V_126 &&
F_53 ( V_116 ) )
V_28 -> V_135 ++ ;
}
if ( V_116 -> V_128 > V_28 -> V_128 )
break;
V_131:
V_117 = & V_116 -> V_27 . V_59 ;
}
if ( V_118 && ! V_125 ) {
V_117 = V_118 ;
V_116 = * V_117 ;
V_125 ++ ;
}
if ( V_117 == & V_18 -> V_41 )
V_18 -> V_139 = NULL ;
if ( V_28 -> V_135 ) {
unsigned int V_135 ;
struct V_21 * V_140 , * V_141 ;
V_140 = V_18 -> V_41 ;
while ( V_140 ) {
if ( V_140 -> V_128 == V_28 -> V_128 &&
F_53 ( V_140 ) ) {
F_67 ( & V_28 -> V_142 ,
& V_140 -> V_142 ) ;
break;
}
V_140 = V_140 -> V_27 . V_59 ;
}
V_135 = 0 ;
F_68 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_140 -> V_135 ++ ;
F_62 ( V_140 -> V_135 != V_28 -> V_135 ) ;
V_135 ++ ;
}
F_62 ( V_135 != V_28 -> V_135 ) ;
}
if ( ! V_119 ) {
if ( ! V_123 )
F_49 ( L_3 ) ;
V_123:
V_127 = F_56 ( & V_28 -> V_27 , V_108 ) ;
if ( V_127 )
return V_127 ;
V_28 -> V_27 . V_59 = V_116 ;
* V_117 = V_28 ;
V_28 -> V_143 = V_18 ;
F_52 ( & V_28 -> V_29 ) ;
F_69 ( V_144 , V_28 , V_115 ) ;
V_115 -> V_145 -> V_9 . V_146 -> V_147 ++ ;
if ( ! ( V_18 -> V_43 & V_46 ) ) {
V_115 -> V_145 -> V_9 . V_146 -> V_148 ++ ;
V_18 -> V_43 |= V_46 ;
}
} else {
int V_149 ;
if ( ! V_125 ) {
if ( V_123 )
goto V_123;
F_49 ( L_4 ) ;
return - V_97 ;
}
V_127 = F_56 ( & V_28 -> V_27 , V_108 ) ;
if ( V_127 )
return V_127 ;
* V_117 = V_28 ;
V_28 -> V_143 = V_18 ;
V_28 -> V_27 . V_59 = V_116 -> V_27 . V_59 ;
F_52 ( & V_28 -> V_29 ) ;
F_69 ( V_144 , V_28 , V_115 ) ;
if ( ! ( V_18 -> V_43 & V_46 ) ) {
V_115 -> V_145 -> V_9 . V_146 -> V_148 ++ ;
V_18 -> V_43 |= V_46 ;
}
V_149 = V_116 -> V_135 ;
F_60 ( V_116 , V_18 , V_115 -> V_145 ) ;
F_19 ( V_116 ) ;
if ( V_149 ) {
V_117 = & V_28 -> V_27 . V_59 ;
V_116 = * V_117 ;
while ( V_116 ) {
if ( F_53 ( V_116 ) ) {
* V_117 = V_116 -> V_27 . V_59 ;
F_60 ( V_116 , V_18 , V_115 -> V_145 ) ;
F_19 ( V_116 ) ;
V_149 -- ;
} else {
V_117 = & V_116 -> V_27 . V_59 ;
}
V_116 = * V_117 ;
}
F_70 ( V_149 != 0 ) ;
}
}
return 0 ;
}
static void F_71 ( struct V_6 * V_6 , struct V_21 * V_28 )
{
if ( ! F_72 ( & V_6 -> V_9 . V_150 ) &&
( V_28 -> V_102 & ( V_136 | V_151 ) ) )
F_73 ( & V_6 -> V_9 . V_150 ,
V_152 + V_6 -> V_9 . V_153 . V_154 ) ;
}
void F_74 ( struct V_6 * V_6 )
{
if ( ! F_72 ( & V_6 -> V_9 . V_150 ) )
F_73 ( & V_6 -> V_9 . V_150 ,
V_152 + V_6 -> V_9 . V_153 . V_154 ) ;
}
int F_75 ( struct V_17 * V_65 , struct V_21 * V_28 ,
struct V_114 * V_115 , struct V_107 * V_108 )
{
struct V_17 * V_18 , * V_91 = NULL ;
int V_127 = - V_78 ;
int V_86 = 1 ;
int V_87 = 0 ;
int V_88 = F_7 ( V_115 -> V_145 ) ;
if ( V_115 -> V_120 ) {
if ( ! ( V_115 -> V_120 -> V_121 & V_124 ) )
V_86 = 0 ;
if ( V_115 -> V_120 -> V_121 & V_122 )
V_87 = 1 ;
}
if ( ! V_86 && ! V_87 )
F_49 ( L_5 ) ;
V_18 = F_46 ( V_65 , & V_28 -> V_155 . V_14 , V_28 -> V_155 . V_84 ,
F_76 ( struct V_21 , V_155 ) , V_86 ,
V_87 , V_88 ) ;
if ( F_77 ( V_18 ) ) {
V_127 = F_78 ( V_18 ) ;
V_18 = NULL ;
goto V_81;
}
V_91 = V_18 ;
#ifdef F_79
if ( V_28 -> V_156 . V_84 ) {
struct V_17 * V_157 ;
if ( ! V_18 -> V_158 ) {
struct V_17 * V_159 ;
V_159 = F_11 () ;
if ( ! V_159 )
goto V_160;
V_159 -> V_41 = V_115 -> V_145 -> V_9 . V_42 ;
F_52 ( & V_115 -> V_145 -> V_9 . V_42 -> V_29 ) ;
V_159 -> V_43 = V_44 ;
V_159 -> V_68 = V_88 ;
V_157 = F_46 ( V_159 , & V_28 -> V_156 . V_14 ,
V_28 -> V_156 . V_84 ,
F_76 ( struct V_21 , V_156 ) ,
V_86 , V_87 , V_88 ) ;
if ( F_77 ( V_157 ) ) {
F_13 ( V_159 ) ;
V_127 = F_78 ( V_157 ) ;
goto V_160;
}
V_159 -> V_101 = V_18 ;
V_18 -> V_158 = V_159 ;
} else {
V_157 = F_46 ( V_18 -> V_158 , & V_28 -> V_156 . V_14 ,
V_28 -> V_156 . V_84 ,
F_76 ( struct V_21 , V_156 ) ,
V_86 , V_87 , V_88 ) ;
if ( F_77 ( V_157 ) ) {
V_127 = F_78 ( V_157 ) ;
goto V_160;
}
}
if ( ! V_18 -> V_41 ) {
V_18 -> V_41 = V_28 ;
F_52 ( & V_28 -> V_29 ) ;
}
V_18 = V_157 ;
}
#endif
V_127 = F_63 ( V_18 , V_28 , V_115 , V_108 ) ;
if ( ! V_127 ) {
F_71 ( V_115 -> V_145 , V_28 ) ;
if ( ! ( V_28 -> V_102 & V_151 ) )
F_80 ( V_115 -> V_145 , V_91 ) ;
}
V_81:
if ( V_127 ) {
#ifdef F_79
if ( V_91 != V_18 && V_91 -> V_41 == V_28 ) {
V_91 -> V_41 = NULL ;
F_81 ( & V_28 -> V_29 ) ;
}
if ( V_91 != V_18 && ! V_91 -> V_41 && ! ( V_91 -> V_43 & V_46 ) ) {
V_91 -> V_41 = F_61 ( V_115 -> V_145 , V_91 ) ;
#if V_161 >= 2
if ( ! V_91 -> V_41 ) {
F_70 ( V_91 -> V_41 == NULL ) ;
V_91 -> V_41 = V_115 -> V_145 -> V_9 . V_42 ;
}
#endif
F_52 ( & V_91 -> V_41 -> V_29 ) ;
}
#endif
F_18 ( & V_28 -> V_27 ) ;
}
return V_127 ;
#ifdef F_79
V_160:
if ( V_18 && ! ( V_18 -> V_43 & ( V_46 | V_44 ) ) )
F_82 ( V_115 -> V_145 , V_18 ) ;
F_18 ( & V_28 -> V_27 ) ;
return V_127 ;
#endif
}
static struct V_17 * F_83 ( struct V_17 * V_65 ,
struct V_162 * args )
{
struct V_17 * V_18 ;
T_1 V_95 ;
if ( F_58 ( args -> V_85 == 0 ) )
return NULL ;
V_18 = V_65 ;
for (; ; ) {
struct V_17 * V_80 ;
V_95 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_80 = V_95 ? V_18 -> V_99 : V_18 -> V_100 ;
if ( V_80 ) {
V_18 = V_80 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_84 ( V_18 ) || V_18 -> V_43 & V_46 ) {
struct V_92 * V_93 ;
V_93 = (struct V_92 * ) ( ( V_96 * ) V_18 -> V_41 +
args -> V_85 ) ;
if ( F_48 ( & V_93 -> V_14 , args -> V_14 , V_93 -> V_84 ) ) {
#ifdef F_79
if ( V_18 -> V_158 ) {
struct V_17 * V_159 ;
V_159 = F_83 ( V_18 -> V_158 ,
args + 1 ) ;
if ( ! V_159 )
goto V_163;
V_18 = V_159 ;
}
#endif
if ( V_18 -> V_43 & V_46 )
return V_18 ;
}
}
#ifdef F_79
V_163:
#endif
if ( V_18 -> V_43 & V_44 )
break;
V_18 = V_18 -> V_101 ;
}
return NULL ;
}
struct V_17 * F_85 ( struct V_17 * V_65 , const struct V_83 * V_164 ,
const struct V_83 * V_165 )
{
struct V_17 * V_18 ;
struct V_162 args [] = {
{
. V_85 = F_76 ( struct V_21 , V_155 ) ,
. V_14 = V_164 ,
} ,
#ifdef F_79
{
. V_85 = F_76 ( struct V_21 , V_156 ) ,
. V_14 = V_165 ,
} ,
#endif
{
. V_85 = 0 ,
}
} ;
V_18 = F_83 ( V_65 , V_164 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_43 & V_45 )
V_18 = V_65 ;
return V_18 ;
}
static struct V_17 * F_86 ( struct V_17 * V_65 ,
const struct V_83 * V_14 ,
int V_84 , int V_85 )
{
struct V_17 * V_18 ;
for ( V_18 = V_65 ; V_18 ; ) {
struct V_92 * V_93 = (struct V_92 * ) ( ( V_96 * ) V_18 -> V_41 + V_85 ) ;
if ( V_84 < V_18 -> V_13 ||
! F_48 ( & V_93 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_84 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_99 ;
else
V_18 = V_18 -> V_100 ;
}
return NULL ;
}
struct V_17 * F_87 ( struct V_17 * V_65 ,
const struct V_83 * V_164 , int V_166 ,
const struct V_83 * V_165 , int V_167 )
{
struct V_17 * V_18 ;
V_18 = F_86 ( V_65 , V_164 , V_166 ,
F_76 ( struct V_21 , V_155 ) ) ;
#ifdef F_79
if ( V_167 ) {
F_70 ( V_165 == NULL ) ;
if ( V_18 && V_18 -> V_158 )
V_18 = F_86 ( V_18 -> V_158 , V_165 , V_167 ,
F_76 ( struct V_21 , V_156 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_43 & V_46 )
return V_18 ;
return NULL ;
}
static struct V_21 * F_61 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
if ( V_18 -> V_43 & V_44 )
return V_6 -> V_9 . V_42 ;
while ( V_18 ) {
if ( V_18 -> V_100 )
return V_18 -> V_100 -> V_41 ;
if ( V_18 -> V_99 )
return V_18 -> V_99 -> V_41 ;
V_18 = F_84 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_82 ( struct V_6 * V_6 ,
struct V_17 * V_18 )
{
int V_168 ;
int V_169 ;
struct V_17 * V_170 , * V_91 ;
struct V_1 * V_2 ;
int V_116 = 0 ;
for (; ; ) {
F_47 ( L_6 , V_18 -> V_13 , V_116 ) ;
V_116 ++ ;
F_70 ( V_18 -> V_43 & V_46 ) ;
F_70 ( V_18 -> V_43 & V_45 ) ;
F_70 ( V_18 -> V_41 ) ;
V_168 = 0 ;
V_170 = NULL ;
if ( V_18 -> V_99 )
V_170 = V_18 -> V_99 , V_168 |= 1 ;
if ( V_18 -> V_100 )
V_170 = V_18 -> V_100 , V_168 |= 2 ;
if ( V_168 == 3 || F_84 ( V_18 )
#ifdef F_79
|| ( V_168 && V_18 -> V_43 & V_44 )
#endif
) {
V_18 -> V_41 = F_61 ( V_6 , V_18 ) ;
#if V_161 >= 2
if ( ! V_18 -> V_41 ) {
F_70 ( ! V_18 -> V_41 ) ;
V_18 -> V_41 = V_6 -> V_9 . V_42 ;
}
#endif
F_52 ( & V_18 -> V_41 -> V_29 ) ;
return V_18 -> V_101 ;
}
V_91 = V_18 -> V_101 ;
#ifdef F_79
if ( F_84 ( V_91 ) == V_18 ) {
F_70 ( ! ( V_18 -> V_43 & V_44 ) ) ;
F_84 ( V_91 ) = NULL ;
V_169 = V_171 ;
} else {
F_70 ( V_18 -> V_43 & V_44 ) ;
#endif
if ( V_91 -> V_99 == V_18 )
V_91 -> V_99 = V_170 ;
else if ( V_91 -> V_100 == V_18 )
V_91 -> V_100 = V_170 ;
#if V_161 >= 2
else
F_70 ( 1 ) ;
#endif
if ( V_170 )
V_170 -> V_101 = V_91 ;
V_169 = V_172 ;
#ifdef F_79
}
#endif
F_88 ( & V_3 ) ;
F_89 (w) {
if ( ! V_170 ) {
if ( V_2 -> V_65 == V_18 ) {
V_2 -> V_65 = V_2 -> V_71 = NULL ;
F_47 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_71 == V_18 ) {
F_47 ( L_8 , V_2 , V_2 -> V_69 , V_169 ) ;
V_2 -> V_71 = V_91 ;
V_2 -> V_69 = V_169 ;
}
} else {
if ( V_2 -> V_65 == V_18 ) {
V_2 -> V_65 = V_170 ;
F_47 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_71 == V_18 ) {
V_2 -> V_71 = V_170 ;
if ( V_168 & 2 ) {
F_47 ( L_10 , V_2 , V_2 -> V_69 ) ;
V_2 -> V_69 = V_2 -> V_69 >= V_172 ? V_173 : V_70 ;
} else {
F_47 ( L_10 , V_2 , V_2 -> V_69 ) ;
V_2 -> V_69 = V_2 -> V_69 >= V_174 ? V_173 : V_70 ;
}
}
}
}
F_90 ( & V_3 ) ;
F_13 ( V_18 ) ;
if ( V_91 -> V_43 & V_46 || F_84 ( V_91 ) )
return V_91 ;
F_19 ( V_91 -> V_41 ) ;
V_91 -> V_41 = NULL ;
V_18 = V_91 ;
}
}
static void F_91 ( struct V_17 * V_18 , struct V_21 * * V_175 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 ;
struct V_21 * V_28 = * V_175 ;
struct V_6 * V_6 = V_115 -> V_145 ;
F_47 ( L_11 ) ;
* V_175 = V_28 -> V_27 . V_59 ;
V_28 -> V_143 = NULL ;
V_6 -> V_9 . V_146 -> V_147 -- ;
V_6 -> V_9 . V_146 -> V_176 ++ ;
if ( V_18 -> V_139 == V_28 )
V_18 -> V_139 = NULL ;
if ( V_28 -> V_135 ) {
struct V_21 * V_140 , * V_177 ;
F_68 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_140 -> V_135 -- ;
V_28 -> V_135 = 0 ;
F_92 ( & V_28 -> V_142 ) ;
}
F_88 ( & V_3 ) ;
F_89 (w) {
if ( V_2 -> V_69 == V_174 && V_2 -> V_41 == V_28 ) {
F_47 ( L_12 , V_2 ) ;
V_2 -> V_41 = V_28 -> V_27 . V_59 ;
if ( ! V_2 -> V_41 )
V_2 -> V_69 = V_173 ;
}
}
F_90 ( & V_3 ) ;
V_28 -> V_27 . V_59 = NULL ;
if ( ! V_18 -> V_41 ) {
V_18 -> V_43 &= ~ V_46 ;
V_6 -> V_9 . V_146 -> V_148 -- ;
V_18 = F_82 ( V_6 , V_18 ) ;
}
F_60 ( V_28 , V_18 , V_6 ) ;
F_69 ( V_178 , V_28 , V_115 ) ;
F_19 ( V_28 ) ;
}
int F_93 ( struct V_21 * V_28 , struct V_114 * V_115 )
{
struct V_6 * V_6 = V_115 -> V_145 ;
struct V_17 * V_18 = V_28 -> V_143 ;
struct V_21 * * V_175 ;
#if V_161 >= 2
if ( V_28 -> V_27 . V_179 > 0 ) {
F_70 ( V_18 ) ;
return - V_97 ;
}
#endif
if ( ! V_18 || V_28 == V_6 -> V_9 . V_42 )
return - V_97 ;
F_70 ( ! ( V_18 -> V_43 & V_46 ) ) ;
if ( ! ( V_28 -> V_102 & V_151 ) ) {
struct V_17 * V_91 = V_18 ;
#ifdef F_79
if ( V_28 -> V_156 . V_84 ) {
while ( ! ( V_91 -> V_43 & V_44 ) )
V_91 = V_91 -> V_101 ;
V_91 = V_91 -> V_101 ;
}
#endif
F_80 ( V_115 -> V_145 , V_91 ) ;
}
for ( V_175 = & V_18 -> V_41 ; * V_175 ; V_175 = & ( * V_175 ) -> V_27 . V_59 ) {
if ( * V_175 == V_28 ) {
F_91 ( V_18 , V_175 , V_115 ) ;
return 0 ;
}
}
return - V_97 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_17 * V_18 , * V_91 ;
for (; ; ) {
V_18 = V_2 -> V_71 ;
if ( ! V_18 )
return 0 ;
if ( V_2 -> V_180 && V_18 != V_2 -> V_65 &&
V_18 -> V_43 & V_46 && V_2 -> V_69 < V_174 ) {
V_2 -> V_69 = V_174 ;
V_2 -> V_41 = V_18 -> V_41 ;
}
switch ( V_2 -> V_69 ) {
#ifdef F_79
case V_181 :
if ( F_84 ( V_18 ) ) {
V_2 -> V_71 = F_84 ( V_18 ) ;
continue;
}
V_2 -> V_69 = V_171 ;
#endif
case V_171 :
if ( V_18 -> V_100 ) {
V_2 -> V_71 = V_18 -> V_100 ;
V_2 -> V_69 = V_70 ;
continue;
}
V_2 -> V_69 = V_172 ;
case V_172 :
if ( V_18 -> V_99 ) {
V_2 -> V_71 = V_18 -> V_99 ;
V_2 -> V_69 = V_70 ;
continue;
}
V_2 -> V_69 = V_174 ;
V_2 -> V_41 = V_18 -> V_41 ;
case V_174 :
if ( V_2 -> V_41 && V_18 -> V_43 & V_46 ) {
int V_127 ;
if ( V_2 -> V_67 ) {
V_2 -> V_67 -- ;
goto V_67;
}
V_127 = V_2 -> V_79 ( V_2 ) ;
if ( V_127 )
return V_127 ;
V_2 -> V_66 ++ ;
continue;
}
V_67:
V_2 -> V_69 = V_173 ;
case V_173 :
if ( V_18 == V_2 -> V_65 )
return 0 ;
V_91 = V_18 -> V_101 ;
V_2 -> V_71 = V_91 ;
#ifdef F_79
if ( F_84 ( V_91 ) == V_18 ) {
F_70 ( ! ( V_18 -> V_43 & V_44 ) ) ;
V_2 -> V_69 = V_171 ;
continue;
}
#endif
if ( V_91 -> V_100 == V_18 ) {
V_2 -> V_69 = V_172 ;
continue;
}
if ( V_91 -> V_99 == V_18 ) {
V_2 -> V_69 = V_174 ;
V_2 -> V_41 = V_2 -> V_71 -> V_41 ;
continue;
}
#if V_161 >= 2
F_70 ( 1 ) ;
#endif
}
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_58 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_71 = V_2 -> V_65 ;
F_1 ( V_2 ) ;
V_58 = F_43 ( V_2 ) ;
if ( V_58 <= 0 )
F_5 ( V_2 ) ;
return V_58 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_58 ;
struct V_21 * V_28 ;
struct V_182 * V_183 = F_95 ( V_2 , struct V_182 , V_2 ) ;
struct V_114 V_115 = {
. V_145 = V_183 -> V_6 ,
} ;
if ( V_183 -> V_88 != V_184 &&
V_2 -> V_71 -> V_68 != V_183 -> V_88 )
V_2 -> V_71 -> V_68 = V_183 -> V_88 ;
if ( ! V_183 -> V_79 ) {
F_96 ( V_183 -> V_88 == V_184 ) ;
V_2 -> V_41 = NULL ;
return 0 ;
}
for ( V_28 = V_2 -> V_41 ; V_28 ; V_28 = V_28 -> V_27 . V_59 ) {
V_58 = V_183 -> V_79 ( V_28 , V_183 -> V_77 ) ;
if ( V_58 < 0 ) {
V_2 -> V_41 = V_28 ;
V_58 = F_93 ( V_28 , & V_115 ) ;
if ( V_58 ) {
#if V_161 >= 2
F_97 ( L_13 ,
V_185 , V_28 , V_28 -> V_143 , V_58 ) ;
#endif
continue;
}
return 0 ;
}
F_70 ( V_58 != 0 ) ;
}
V_2 -> V_41 = V_28 ;
return 0 ;
}
static void F_98 ( struct V_6 * V_6 , struct V_17 * V_65 ,
int (* V_79)( struct V_21 * , void * V_77 ) ,
bool V_180 , int V_88 , void * V_77 )
{
struct V_182 V_183 ;
V_183 . V_2 . V_65 = V_65 ;
V_183 . V_2 . V_79 = F_94 ;
V_183 . V_2 . V_180 = V_180 ;
V_183 . V_2 . V_66 = 0 ;
V_183 . V_2 . V_67 = 0 ;
V_183 . V_79 = V_79 ;
V_183 . V_88 = V_88 ;
V_183 . V_77 = V_77 ;
V_183 . V_6 = V_6 ;
F_41 ( & V_183 . V_2 ) ;
}
static void F_99 ( struct V_6 * V_6 ,
int (* V_79)( struct V_21 * , void * ) ,
int V_88 , void * V_77 )
{
struct V_30 * V_39 ;
struct V_49 * V_50 ;
unsigned int V_32 ;
F_29 () ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
V_50 = & V_6 -> V_9 . V_37 [ V_32 ] ;
F_30 (table, head, tb6_hlist) {
F_2 ( & V_39 -> V_33 ) ;
F_98 ( V_6 , & V_39 -> V_40 ,
V_79 , false , V_88 , V_77 ) ;
F_4 ( & V_39 -> V_33 ) ;
}
}
F_31 () ;
}
void F_100 ( struct V_6 * V_6 , int (* V_79)( struct V_21 * , void * ) ,
void * V_77 )
{
F_99 ( V_6 , V_79 , V_184 , V_77 ) ;
}
static int F_101 ( struct V_21 * V_28 , void * V_77 )
{
if ( V_28 -> V_102 & V_151 ) {
F_47 ( L_14 , V_28 ) ;
return - 1 ;
}
return 0 ;
}
static void F_80 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
F_98 ( V_6 , V_18 , F_101 , true ,
V_184 , NULL ) ;
}
static void F_102 ( struct V_6 * V_6 )
{
int V_186 = F_7 ( V_6 ) ;
F_99 ( V_6 , NULL , V_186 , NULL ) ;
}
static int F_103 ( struct V_21 * V_28 , void * V_77 )
{
unsigned long V_187 = V_152 ;
if ( V_28 -> V_102 & V_136 && V_28 -> V_27 . V_137 ) {
if ( F_104 ( V_187 , V_28 -> V_27 . V_137 ) ) {
F_47 ( L_15 , V_28 ) ;
return - 1 ;
}
V_188 . V_189 ++ ;
} else if ( V_28 -> V_102 & V_151 ) {
if ( F_8 ( & V_28 -> V_27 . V_190 ) == 0 &&
F_105 ( V_187 , V_28 -> V_27 . V_191 + V_188 . V_192 ) ) {
F_47 ( L_16 , V_28 ) ;
return - 1 ;
} else if ( V_28 -> V_102 & V_103 ) {
struct V_193 * V_194 ;
T_5 V_195 = 0 ;
V_194 = F_106 ( & V_28 -> V_27 , & V_28 -> V_134 ) ;
if ( V_194 ) {
V_195 = V_194 -> V_56 ;
F_107 ( V_194 ) ;
}
if ( ! ( V_195 & V_196 ) ) {
F_47 ( L_17 ,
V_28 ) ;
return - 1 ;
}
}
V_188 . V_189 ++ ;
}
return 0 ;
}
void F_108 ( unsigned long V_137 , struct V_6 * V_6 , bool V_197 )
{
unsigned long V_187 ;
if ( V_197 ) {
F_109 ( & V_198 ) ;
} else if ( ! F_110 ( & V_198 ) ) {
F_73 ( & V_6 -> V_9 . V_150 , V_152 + V_199 ) ;
return;
}
V_188 . V_192 = V_137 ? ( int ) V_137 :
V_6 -> V_9 . V_153 . V_154 ;
V_188 . V_189 = F_111 () ;
F_100 ( V_6 , F_103 , NULL ) ;
V_187 = V_152 ;
V_6 -> V_9 . V_200 = V_187 ;
if ( V_188 . V_189 )
F_73 ( & V_6 -> V_9 . V_150 ,
F_112 ( V_187
+ V_6 -> V_9 . V_153 . V_154 ) ) ;
else
F_113 ( & V_6 -> V_9 . V_150 ) ;
F_114 ( & V_198 ) ;
}
static void F_115 ( unsigned long V_77 )
{
F_108 ( 0 , (struct V_6 * ) V_77 , true ) ;
}
static int T_3 F_116 ( struct V_6 * V_6 )
{
T_6 V_201 = sizeof( struct V_49 ) * V_35 ;
F_117 ( & V_6 -> V_9 . V_150 , F_115 , ( unsigned long ) V_6 ) ;
V_6 -> V_9 . V_146 = F_25 ( sizeof( * V_6 -> V_9 . V_146 ) , V_202 ) ;
if ( ! V_6 -> V_9 . V_146 )
goto V_203;
V_201 = F_118 ( T_6 , V_201 , V_204 ) ;
V_6 -> V_9 . V_37 = F_25 ( V_201 , V_202 ) ;
if ( ! V_6 -> V_9 . V_37 )
goto V_205;
V_6 -> V_9 . V_51 = F_25 ( sizeof( * V_6 -> V_9 . V_51 ) ,
V_202 ) ;
if ( ! V_6 -> V_9 . V_51 )
goto V_206;
V_6 -> V_9 . V_51 -> V_34 = V_48 ;
V_6 -> V_9 . V_51 -> V_40 . V_41 = V_6 -> V_9 . V_42 ;
V_6 -> V_9 . V_51 -> V_40 . V_43 =
V_44 | V_45 | V_46 ;
F_26 ( & V_6 -> V_9 . V_51 -> V_47 ) ;
#ifdef F_119
V_6 -> V_9 . V_52 = F_25 ( sizeof( * V_6 -> V_9 . V_52 ) ,
V_202 ) ;
if ( ! V_6 -> V_9 . V_52 )
goto V_207;
V_6 -> V_9 . V_52 -> V_34 = V_208 ;
V_6 -> V_9 . V_52 -> V_40 . V_41 = V_6 -> V_9 . V_42 ;
V_6 -> V_9 . V_52 -> V_40 . V_43 =
V_44 | V_45 | V_46 ;
F_26 ( & V_6 -> V_9 . V_52 -> V_47 ) ;
#endif
F_32 ( V_6 ) ;
return 0 ;
#ifdef F_119
V_207:
F_37 ( V_6 -> V_9 . V_51 ) ;
#endif
V_206:
F_37 ( V_6 -> V_9 . V_37 ) ;
V_205:
F_37 ( V_6 -> V_9 . V_146 ) ;
V_203:
return - V_78 ;
}
static void F_120 ( struct V_6 * V_6 )
{
F_121 ( V_6 , NULL ) ;
F_122 ( & V_6 -> V_9 . V_150 ) ;
#ifdef F_119
F_123 ( & V_6 -> V_9 . V_52 -> V_47 ) ;
F_37 ( V_6 -> V_9 . V_52 ) ;
#endif
F_123 ( & V_6 -> V_9 . V_51 -> V_47 ) ;
F_37 ( V_6 -> V_9 . V_51 ) ;
F_37 ( V_6 -> V_9 . V_37 ) ;
F_37 ( V_6 -> V_9 . V_146 ) ;
}
int T_7 F_124 ( void )
{
int V_209 = - V_78 ;
V_19 = F_125 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_210 ,
NULL ) ;
if ( ! V_19 )
goto V_81;
V_209 = F_126 ( & V_211 ) ;
if ( V_209 )
goto V_212;
V_209 = F_127 ( V_213 , V_214 , NULL , F_44 ,
NULL ) ;
if ( V_209 )
goto V_215;
V_216 = F_102 ;
V_81:
return V_209 ;
V_215:
F_128 ( & V_211 ) ;
V_212:
F_129 ( V_19 ) ;
goto V_81;
}
void F_130 ( void )
{
F_128 ( & V_211 ) ;
F_129 ( V_19 ) ;
}
static int F_131 ( struct V_217 * V_218 , void * V_219 )
{
struct V_21 * V_28 = V_219 ;
struct V_220 * V_116 = V_218 -> V_221 ;
F_132 ( V_218 , L_19 , & V_28 -> V_155 . V_14 , V_28 -> V_155 . V_84 ) ;
#ifdef F_79
F_132 ( V_218 , L_19 , & V_28 -> V_156 . V_14 , V_28 -> V_156 . V_84 ) ;
#else
F_133 ( V_218 , L_20 ) ;
#endif
if ( V_28 -> V_102 & V_103 )
F_132 ( V_218 , L_21 , & V_28 -> V_134 ) ;
else
F_133 ( V_218 , L_22 ) ;
F_132 ( V_218 , L_23 ,
V_28 -> V_128 , F_8 ( & V_28 -> V_27 . V_190 ) ,
V_28 -> V_27 . V_222 , V_28 -> V_102 ,
V_28 -> V_27 . V_132 ? V_28 -> V_27 . V_132 -> V_223 : L_24 ) ;
V_116 -> V_2 . V_41 = NULL ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_220 * V_116 = V_2 -> args ;
if ( ! V_116 -> V_67 )
return 1 ;
do {
V_116 -> V_2 . V_41 = V_116 -> V_2 . V_41 -> V_27 . V_59 ;
V_116 -> V_67 -- ;
if ( ! V_116 -> V_67 && V_116 -> V_2 . V_41 )
return 1 ;
} while ( V_116 -> V_2 . V_41 );
return 0 ;
}
static void F_135 ( struct V_220 * V_116 )
{
memset ( & V_116 -> V_2 , 0 , sizeof( V_116 -> V_2 ) ) ;
V_116 -> V_2 . V_79 = F_134 ;
V_116 -> V_2 . V_65 = & V_116 -> V_224 -> V_40 ;
V_116 -> V_2 . V_69 = V_70 ;
V_116 -> V_2 . V_71 = V_116 -> V_2 . V_65 ;
V_116 -> V_2 . args = V_116 ;
V_116 -> V_88 = V_116 -> V_2 . V_65 -> V_68 ;
F_136 ( & V_116 -> V_2 . V_4 ) ;
F_1 ( & V_116 -> V_2 ) ;
}
static struct V_30 * F_137 ( struct V_30 * V_224 ,
struct V_6 * V_6 )
{
unsigned int V_32 ;
struct V_225 * V_71 ;
if ( V_224 ) {
V_32 = ( V_224 -> V_34 & ( V_35 - 1 ) ) + 1 ;
V_71 = F_138 ( F_139 ( & V_224 -> V_36 ) ) ;
} else {
V_32 = 0 ;
V_71 = NULL ;
}
while ( ! V_71 && V_32 < V_35 ) {
V_71 = F_138 (
F_140 ( & V_6 -> V_9 . V_37 [ V_32 ++ ] ) ) ;
}
return F_141 ( V_71 , struct V_30 , V_36 ) ;
}
static void F_142 ( struct V_220 * V_116 )
{
if ( V_116 -> V_88 != V_116 -> V_2 . V_65 -> V_68 ) {
V_116 -> V_88 = V_116 -> V_2 . V_65 -> V_68 ;
V_116 -> V_2 . V_69 = V_70 ;
V_116 -> V_2 . V_71 = V_116 -> V_2 . V_65 ;
F_70 ( V_116 -> V_2 . V_67 ) ;
V_116 -> V_2 . V_67 = V_116 -> V_2 . V_66 ;
}
}
static void * F_143 ( struct V_217 * V_218 , void * V_219 , T_8 * V_226 )
{
int V_227 ;
struct V_21 * V_228 ;
struct V_6 * V_6 = F_144 ( V_218 ) ;
struct V_220 * V_116 = V_218 -> V_221 ;
if ( ! V_219 )
goto V_229;
V_228 = ( (struct V_21 * ) V_219 ) -> V_27 . V_59 ;
if ( V_228 ) {
++ * V_226 ;
return V_228 ;
}
V_229:
F_142 ( V_116 ) ;
F_88 ( & V_116 -> V_224 -> V_33 ) ;
V_227 = F_43 ( & V_116 -> V_2 ) ;
F_90 ( & V_116 -> V_224 -> V_33 ) ;
if ( V_227 > 0 ) {
if ( V_219 )
++ * V_226 ;
return V_116 -> V_2 . V_41 ;
} else if ( V_227 < 0 ) {
F_5 ( & V_116 -> V_2 ) ;
return NULL ;
}
F_5 ( & V_116 -> V_2 ) ;
V_116 -> V_224 = F_137 ( V_116 -> V_224 , V_6 ) ;
if ( ! V_116 -> V_224 )
return NULL ;
F_135 ( V_116 ) ;
goto V_229;
}
static void * F_145 ( struct V_217 * V_218 , T_8 * V_226 )
__acquires( T_9 )
{
struct V_6 * V_6 = F_144 ( V_218 ) ;
struct V_220 * V_116 = V_218 -> V_221 ;
F_146 () ;
V_116 -> V_224 = F_137 ( NULL , V_6 ) ;
V_116 -> V_67 = * V_226 ;
if ( V_116 -> V_224 ) {
F_135 ( V_116 ) ;
return F_143 ( V_218 , NULL , V_226 ) ;
} else {
return NULL ;
}
}
static bool F_147 ( struct V_220 * V_116 )
{
struct V_1 * V_2 = & V_116 -> V_2 ;
return V_2 -> V_71 && ! ( V_2 -> V_69 == V_173 && V_2 -> V_71 == V_2 -> V_65 ) ;
}
static void F_148 ( struct V_217 * V_218 , void * V_219 )
__releases( T_9 )
{
struct V_220 * V_116 = V_218 -> V_221 ;
if ( F_147 ( V_116 ) )
F_5 ( & V_116 -> V_2 ) ;
F_149 () ;
}
int F_150 ( struct V_230 * V_230 , struct V_231 * V_231 )
{
return F_151 ( V_230 , V_231 , & V_232 ,
sizeof( struct V_220 ) ) ;
}
