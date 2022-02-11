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
if ( F_16 ( & V_22 -> V_23 ) )
F_17 ( & V_22 -> V_24 ) ;
}
static void F_18 ( struct V_6 * V_6 , struct V_25 * V_26 )
{
unsigned int V_27 ;
F_19 ( & V_26 -> V_28 ) ;
V_27 = V_26 -> V_29 & ( V_30 - 1 ) ;
F_20 ( & V_26 -> V_31 , & V_6 -> V_9 . V_32 [ V_27 ] ) ;
}
static struct V_25 * F_21 ( struct V_6 * V_6 , T_2 V_33 )
{
struct V_25 * V_34 ;
V_34 = F_22 ( sizeof( * V_34 ) , V_20 ) ;
if ( V_34 ) {
V_34 -> V_29 = V_33 ;
V_34 -> V_35 . V_36 = V_6 -> V_9 . V_37 ;
V_34 -> V_35 . V_38 = V_39 | V_40 | V_41 ;
F_23 ( & V_34 -> V_42 ) ;
}
return V_34 ;
}
struct V_25 * F_24 ( struct V_6 * V_6 , T_2 V_33 )
{
struct V_25 * V_26 ;
if ( V_33 == 0 )
V_33 = V_43 ;
V_26 = F_25 ( V_6 , V_33 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_21 ( V_6 , V_33 ) ;
if ( V_26 )
F_18 ( V_6 , V_26 ) ;
return V_26 ;
}
struct V_25 * F_25 ( struct V_6 * V_6 , T_2 V_33 )
{
struct V_25 * V_26 ;
struct V_44 * V_45 ;
unsigned int V_27 ;
if ( V_33 == 0 )
V_33 = V_43 ;
V_27 = V_33 & ( V_30 - 1 ) ;
F_26 () ;
V_45 = & V_6 -> V_9 . V_32 [ V_27 ] ;
F_27 (tb, head, tb6_hlist) {
if ( V_26 -> V_29 == V_33 ) {
F_28 () ;
return V_26 ;
}
}
F_28 () ;
return NULL ;
}
static void T_3 F_29 ( struct V_6 * V_6 )
{
F_18 ( V_6 , V_6 -> V_9 . V_46 ) ;
F_18 ( V_6 , V_6 -> V_9 . V_47 ) ;
}
struct V_25 * F_24 ( struct V_6 * V_6 , T_2 V_33 )
{
return F_25 ( V_6 , V_33 ) ;
}
struct V_25 * F_25 ( struct V_6 * V_6 , T_2 V_33 )
{
return V_6 -> V_9 . V_46 ;
}
struct V_48 * F_30 ( struct V_6 * V_6 , struct V_49 * V_50 ,
int V_51 , T_4 V_52 )
{
return (struct V_48 * ) V_52 ( V_6 , V_6 -> V_9 . V_46 , V_50 , V_51 ) ;
}
static void T_3 F_29 ( struct V_6 * V_6 )
{
F_18 ( V_6 , V_6 -> V_9 . V_46 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_21 * V_22 ;
for ( V_22 = V_2 -> V_36 ; V_22 ; V_22 = V_22 -> V_24 . V_54 ) {
V_53 = F_32 ( V_22 , V_2 -> args ) ;
if ( V_53 < 0 ) {
V_2 -> V_36 = V_22 ;
return 1 ;
}
}
V_2 -> V_36 = NULL ;
return 0 ;
}
static void F_33 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = ( void * ) V_56 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_56 -> args [ 4 ] ) {
V_56 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_56 -> args [ 2 ] = 0 ;
F_34 ( V_2 ) ;
}
V_56 -> V_57 = ( void * ) V_56 -> args [ 3 ] ;
V_56 -> args [ 1 ] = 3 ;
}
static int F_35 ( struct V_55 * V_56 )
{
F_33 ( V_56 ) ;
return V_56 -> V_57 ? V_56 -> V_57 ( V_56 ) : 0 ;
}
static int F_36 ( struct V_25 * V_34 , struct V_58 * V_59 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_53 ;
V_2 = ( void * ) V_56 -> args [ 2 ] ;
V_2 -> V_60 = & V_34 -> V_35 ;
if ( V_56 -> args [ 4 ] == 0 ) {
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
F_37 ( & V_34 -> V_28 ) ;
V_53 = F_38 ( V_2 ) ;
F_39 ( & V_34 -> V_28 ) ;
if ( V_53 > 0 ) {
V_56 -> args [ 4 ] = 1 ;
V_56 -> args [ 5 ] = V_2 -> V_60 -> V_63 ;
}
} else {
if ( V_56 -> args [ 5 ] != V_2 -> V_60 -> V_63 ) {
V_56 -> args [ 5 ] = V_2 -> V_60 -> V_63 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_2 -> V_60 ;
V_2 -> V_62 = V_2 -> V_61 ;
} else
V_2 -> V_62 = 0 ;
F_37 ( & V_34 -> V_28 ) ;
V_53 = F_40 ( V_2 ) ;
F_39 ( & V_34 -> V_28 ) ;
if ( V_53 <= 0 ) {
F_5 ( V_2 ) ;
V_56 -> args [ 4 ] = 0 ;
}
}
return V_53 ;
}
static int F_41 ( struct V_58 * V_59 , struct V_55 * V_56 )
{
struct V_6 * V_6 = F_42 ( V_59 -> V_67 ) ;
unsigned int V_27 , V_68 ;
unsigned int V_69 = 0 , V_70 ;
struct V_71 V_72 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_44 * V_45 ;
int V_53 = 0 ;
V_68 = V_56 -> args [ 0 ] ;
V_70 = V_56 -> args [ 1 ] ;
V_2 = ( void * ) V_56 -> args [ 2 ] ;
if ( ! V_2 ) {
V_56 -> args [ 3 ] = ( long ) V_56 -> V_57 ;
V_56 -> V_57 = F_35 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_74 = F_31 ;
V_56 -> args [ 2 ] = ( long ) V_2 ;
}
V_72 . V_59 = V_59 ;
V_72 . V_56 = V_56 ;
V_72 . V_6 = V_6 ;
V_2 -> args = & V_72 ;
F_26 () ;
for ( V_27 = V_68 ; V_27 < V_30 ; V_27 ++ , V_70 = 0 ) {
V_69 = 0 ;
V_45 = & V_6 -> V_9 . V_32 [ V_27 ] ;
F_27 (tb, head, tb6_hlist) {
if ( V_69 < V_70 )
goto V_75;
V_53 = F_36 ( V_26 , V_59 , V_56 ) ;
if ( V_53 != 0 )
goto V_76;
V_75:
V_69 ++ ;
}
}
V_76:
F_28 () ;
V_56 -> args [ 1 ] = V_69 ;
V_56 -> args [ 0 ] = V_27 ;
V_53 = V_53 < 0 ? V_53 : V_59 -> V_77 ;
if ( V_53 <= 0 )
F_33 ( V_56 ) ;
return V_53 ;
}
static struct V_17 * F_43 ( struct V_17 * V_60 ,
struct V_78 * V_14 , int V_79 ,
int V_80 , int V_81 ,
int V_82 , int V_83 )
{
struct V_17 * V_18 , * V_84 , * V_85 ;
struct V_17 * V_86 = NULL ;
struct V_87 * V_88 ;
int V_89 ;
T_1 V_90 = 0 ;
F_44 ( L_1 ) ;
V_18 = V_60 ;
do {
V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 + V_80 ) ;
if ( V_79 < V_18 -> V_13 ||
! F_45 ( & V_88 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_81 ) {
if ( V_82 ) {
F_46 ( L_2 ) ;
return F_47 ( - V_92 ) ;
}
F_46 ( L_3 ) ;
}
goto V_93;
}
if ( V_79 == V_18 -> V_13 ) {
if ( ! ( V_18 -> V_38 & V_41 ) ) {
F_15 ( V_18 -> V_36 ) ;
V_18 -> V_36 = NULL ;
}
V_18 -> V_63 = V_83 ;
return V_18 ;
}
V_18 -> V_63 = V_83 ;
V_90 = F_10 ( V_14 , V_18 -> V_13 ) ;
V_86 = V_18 ;
V_18 = V_90 ? V_18 -> V_94 : V_18 -> V_95 ;
} while ( V_18 );
if ( ! V_81 ) {
if ( V_82 ) {
F_46 ( L_2 ) ;
return F_47 ( - V_92 ) ;
}
F_46 ( L_3 ) ;
}
V_85 = F_11 () ;
if ( ! V_85 )
return F_47 ( - V_73 ) ;
V_85 -> V_13 = V_79 ;
V_85 -> V_96 = V_86 ;
V_85 -> V_63 = V_83 ;
if ( V_90 )
V_86 -> V_94 = V_85 ;
else
V_86 -> V_95 = V_85 ;
return V_85 ;
V_93:
V_86 = V_18 -> V_96 ;
V_89 = F_48 ( V_14 , & V_88 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_79 > V_89 ) {
V_84 = F_11 () ;
V_85 = F_11 () ;
if ( ! V_84 || ! V_85 ) {
if ( V_84 )
F_13 ( V_84 ) ;
if ( V_85 )
F_13 ( V_85 ) ;
return F_47 ( - V_73 ) ;
}
V_84 -> V_13 = V_89 ;
V_84 -> V_96 = V_86 ;
V_84 -> V_36 = V_18 -> V_36 ;
F_49 ( & V_84 -> V_36 -> V_23 ) ;
V_84 -> V_63 = V_83 ;
if ( V_90 )
V_86 -> V_94 = V_84 ;
else
V_86 -> V_95 = V_84 ;
V_85 -> V_13 = V_79 ;
V_85 -> V_96 = V_84 ;
V_18 -> V_96 = V_84 ;
V_85 -> V_63 = V_83 ;
if ( F_10 ( V_14 , V_89 ) ) {
V_84 -> V_94 = V_85 ;
V_84 -> V_95 = V_18 ;
} else {
V_84 -> V_95 = V_85 ;
V_84 -> V_94 = V_18 ;
}
} else {
V_85 = F_11 () ;
if ( ! V_85 )
return F_47 ( - V_73 ) ;
V_85 -> V_13 = V_79 ;
V_85 -> V_96 = V_86 ;
V_85 -> V_63 = V_83 ;
if ( V_90 )
V_86 -> V_94 = V_85 ;
else
V_86 -> V_95 = V_85 ;
if ( F_10 ( & V_88 -> V_14 , V_79 ) )
V_85 -> V_94 = V_18 ;
else
V_85 -> V_95 = V_18 ;
V_18 -> V_96 = V_85 ;
}
return V_85 ;
}
static bool F_50 ( struct V_21 * V_22 )
{
return ( V_22 -> V_97 & ( V_98 | V_99 | V_100 ) ) ==
V_98 ;
}
static void F_51 ( T_2 * V_101 , const struct V_102 * V_103 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ ) {
if ( F_52 ( V_104 , V_103 -> V_106 ) )
V_101 [ V_104 ] = V_103 -> V_107 [ V_104 ] ;
}
}
static int F_53 ( struct V_48 * V_24 , struct V_102 * V_103 )
{
if ( ! V_103 -> V_107 )
return 0 ;
if ( V_24 -> V_51 & V_108 ) {
T_2 * V_101 = F_54 ( V_24 ) ;
if ( F_55 ( ! V_101 ) )
return - V_73 ;
F_51 ( V_101 , V_103 ) ;
} else {
F_56 ( V_24 , V_103 -> V_107 , false ) ;
V_103 -> V_107 = NULL ;
}
return 0 ;
}
static void F_57 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_6 * V_6 )
{
if ( F_8 ( & V_22 -> V_23 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_38 & V_41 ) && V_18 -> V_36 == V_22 ) {
V_18 -> V_36 = F_58 ( V_6 , V_18 ) ;
F_49 ( & V_18 -> V_36 -> V_23 ) ;
F_15 ( V_22 ) ;
}
V_18 = V_18 -> V_96 ;
}
F_59 ( F_8 ( & V_22 -> V_23 ) != 1 ) ;
}
}
static int F_60 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_109 * V_110 , struct V_102 * V_103 )
{
struct V_21 * V_111 = NULL ;
struct V_21 * * V_112 ;
struct V_21 * * V_113 = NULL ;
int V_114 = ( V_110 -> V_115 &&
( V_110 -> V_115 -> V_116 & V_117 ) ) ;
int V_118 = ( ! V_110 -> V_115 ||
( V_110 -> V_115 -> V_116 & V_119 ) ) ;
int V_120 = 0 ;
bool V_121 = F_50 ( V_22 ) ;
int V_122 ;
V_112 = & V_18 -> V_36 ;
for ( V_111 = V_18 -> V_36 ; V_111 ; V_111 = V_111 -> V_24 . V_54 ) {
if ( V_111 -> V_123 == V_22 -> V_123 ) {
if ( V_110 -> V_115 &&
( V_110 -> V_115 -> V_116 & V_124 ) )
return - V_125 ;
if ( V_114 ) {
if ( V_121 == F_50 ( V_111 ) ) {
V_120 ++ ;
break;
}
if ( V_121 )
V_113 = V_113 ? : V_112 ;
goto V_126;
}
if ( V_111 -> V_24 . V_127 == V_22 -> V_24 . V_127 &&
V_111 -> V_128 == V_22 -> V_128 &&
F_61 ( & V_111 -> V_129 ,
& V_22 -> V_129 ) ) {
if ( V_22 -> V_130 )
V_22 -> V_130 = 0 ;
if ( ! ( V_111 -> V_97 & V_131 ) )
return - V_125 ;
if ( ! ( V_22 -> V_97 & V_131 ) )
F_62 ( V_111 ) ;
else
F_63 ( V_111 , V_22 -> V_24 . V_132 ) ;
return - V_125 ;
}
if ( V_121 &&
F_50 ( V_111 ) )
V_22 -> V_130 ++ ;
}
if ( V_111 -> V_123 > V_22 -> V_123 )
break;
V_126:
V_112 = & V_111 -> V_24 . V_54 ;
}
if ( V_113 && ! V_120 ) {
V_112 = V_113 ;
V_111 = * V_112 ;
V_120 ++ ;
}
if ( V_112 == & V_18 -> V_36 )
V_18 -> V_133 = NULL ;
if ( V_22 -> V_130 ) {
unsigned int V_130 ;
struct V_21 * V_134 , * V_135 ;
V_134 = V_18 -> V_36 ;
while ( V_134 ) {
if ( V_134 -> V_123 == V_22 -> V_123 &&
F_50 ( V_134 ) ) {
F_64 ( & V_22 -> V_136 ,
& V_134 -> V_136 ) ;
break;
}
V_134 = V_134 -> V_24 . V_54 ;
}
V_130 = 0 ;
F_65 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_134 -> V_130 ++ ;
F_59 ( V_134 -> V_130 != V_22 -> V_130 ) ;
V_130 ++ ;
}
F_59 ( V_130 != V_22 -> V_130 ) ;
}
if ( ! V_114 ) {
if ( ! V_118 )
F_46 ( L_3 ) ;
V_118:
V_122 = F_53 ( & V_22 -> V_24 , V_103 ) ;
if ( V_122 )
return V_122 ;
V_22 -> V_24 . V_54 = V_111 ;
* V_112 = V_22 ;
V_22 -> V_137 = V_18 ;
F_49 ( & V_22 -> V_23 ) ;
F_66 ( V_138 , V_22 , V_110 ) ;
V_110 -> V_139 -> V_9 . V_140 -> V_141 ++ ;
if ( ! ( V_18 -> V_38 & V_41 ) ) {
V_110 -> V_139 -> V_9 . V_140 -> V_142 ++ ;
V_18 -> V_38 |= V_41 ;
}
} else {
int V_143 ;
if ( ! V_120 ) {
if ( V_118 )
goto V_118;
F_46 ( L_4 ) ;
return - V_92 ;
}
V_122 = F_53 ( & V_22 -> V_24 , V_103 ) ;
if ( V_122 )
return V_122 ;
* V_112 = V_22 ;
V_22 -> V_137 = V_18 ;
V_22 -> V_24 . V_54 = V_111 -> V_24 . V_54 ;
F_49 ( & V_22 -> V_23 ) ;
F_66 ( V_138 , V_22 , V_110 ) ;
if ( ! ( V_18 -> V_38 & V_41 ) ) {
V_110 -> V_139 -> V_9 . V_140 -> V_142 ++ ;
V_18 -> V_38 |= V_41 ;
}
V_143 = V_111 -> V_130 ;
F_57 ( V_111 , V_18 , V_110 -> V_139 ) ;
F_15 ( V_111 ) ;
if ( V_143 ) {
V_112 = & V_22 -> V_24 . V_54 ;
V_111 = * V_112 ;
while ( V_111 ) {
if ( F_50 ( V_111 ) ) {
* V_112 = V_111 -> V_24 . V_54 ;
F_57 ( V_111 , V_18 , V_110 -> V_139 ) ;
F_15 ( V_111 ) ;
V_143 -- ;
} else {
V_112 = & V_111 -> V_24 . V_54 ;
}
V_111 = * V_112 ;
}
F_67 ( V_143 != 0 ) ;
}
}
return 0 ;
}
static void F_68 ( struct V_6 * V_6 , struct V_21 * V_22 )
{
if ( ! F_69 ( & V_6 -> V_9 . V_144 ) &&
( V_22 -> V_97 & ( V_131 | V_145 ) ) )
F_70 ( & V_6 -> V_9 . V_144 ,
V_146 + V_6 -> V_9 . V_147 . V_148 ) ;
}
void F_71 ( struct V_6 * V_6 )
{
if ( ! F_69 ( & V_6 -> V_9 . V_144 ) )
F_70 ( & V_6 -> V_9 . V_144 ,
V_146 + V_6 -> V_9 . V_147 . V_148 ) ;
}
int F_72 ( struct V_17 * V_60 , struct V_21 * V_22 ,
struct V_109 * V_110 , struct V_102 * V_103 )
{
struct V_17 * V_18 , * V_86 = NULL ;
int V_122 = - V_73 ;
int V_81 = 1 ;
int V_82 = 0 ;
int V_83 = F_7 ( V_110 -> V_139 ) ;
if ( V_110 -> V_115 ) {
if ( ! ( V_110 -> V_115 -> V_116 & V_119 ) )
V_81 = 0 ;
if ( V_110 -> V_115 -> V_116 & V_117 )
V_82 = 1 ;
}
if ( ! V_81 && ! V_82 )
F_46 ( L_5 ) ;
V_18 = F_43 ( V_60 , & V_22 -> V_149 . V_14 , V_22 -> V_149 . V_79 ,
F_73 ( struct V_21 , V_149 ) , V_81 ,
V_82 , V_83 ) ;
if ( F_74 ( V_18 ) ) {
V_122 = F_75 ( V_18 ) ;
V_18 = NULL ;
goto V_76;
}
V_86 = V_18 ;
#ifdef F_76
if ( V_22 -> V_150 . V_79 ) {
struct V_17 * V_151 ;
if ( ! V_18 -> V_152 ) {
struct V_17 * V_153 ;
V_153 = F_11 () ;
if ( ! V_153 )
goto V_154;
V_153 -> V_36 = V_110 -> V_139 -> V_9 . V_37 ;
F_49 ( & V_110 -> V_139 -> V_9 . V_37 -> V_23 ) ;
V_153 -> V_38 = V_39 ;
V_153 -> V_63 = V_83 ;
V_151 = F_43 ( V_153 , & V_22 -> V_150 . V_14 ,
V_22 -> V_150 . V_79 ,
F_73 ( struct V_21 , V_150 ) ,
V_81 , V_82 , V_83 ) ;
if ( F_74 ( V_151 ) ) {
F_13 ( V_153 ) ;
V_122 = F_75 ( V_151 ) ;
goto V_154;
}
V_153 -> V_96 = V_18 ;
V_18 -> V_152 = V_153 ;
} else {
V_151 = F_43 ( V_18 -> V_152 , & V_22 -> V_150 . V_14 ,
V_22 -> V_150 . V_79 ,
F_73 ( struct V_21 , V_150 ) ,
V_81 , V_82 , V_83 ) ;
if ( F_74 ( V_151 ) ) {
V_122 = F_75 ( V_151 ) ;
goto V_154;
}
}
if ( ! V_18 -> V_36 ) {
V_18 -> V_36 = V_22 ;
F_49 ( & V_22 -> V_23 ) ;
}
V_18 = V_151 ;
}
#endif
V_122 = F_60 ( V_18 , V_22 , V_110 , V_103 ) ;
if ( ! V_122 ) {
F_68 ( V_110 -> V_139 , V_22 ) ;
if ( ! ( V_22 -> V_97 & V_145 ) )
F_77 ( V_110 -> V_139 , V_86 ) ;
}
V_76:
if ( V_122 ) {
#ifdef F_76
if ( V_86 != V_18 && V_86 -> V_36 == V_22 ) {
V_86 -> V_36 = NULL ;
F_78 ( & V_22 -> V_23 ) ;
}
if ( V_86 != V_18 && ! V_86 -> V_36 && ! ( V_86 -> V_38 & V_41 ) ) {
V_86 -> V_36 = F_58 ( V_110 -> V_139 , V_86 ) ;
#if V_155 >= 2
if ( ! V_86 -> V_36 ) {
F_67 ( V_86 -> V_36 == NULL ) ;
V_86 -> V_36 = V_110 -> V_139 -> V_9 . V_37 ;
}
#endif
F_49 ( & V_86 -> V_36 -> V_23 ) ;
}
#endif
F_17 ( & V_22 -> V_24 ) ;
}
return V_122 ;
#ifdef F_76
V_154:
if ( V_18 && ! ( V_18 -> V_38 & ( V_41 | V_39 ) ) )
F_79 ( V_110 -> V_139 , V_18 ) ;
F_17 ( & V_22 -> V_24 ) ;
return V_122 ;
#endif
}
static struct V_17 * F_80 ( struct V_17 * V_60 ,
struct V_156 * args )
{
struct V_17 * V_18 ;
T_1 V_90 ;
if ( F_55 ( args -> V_80 == 0 ) )
return NULL ;
V_18 = V_60 ;
for (; ; ) {
struct V_17 * V_75 ;
V_90 = F_10 ( args -> V_14 , V_18 -> V_13 ) ;
V_75 = V_90 ? V_18 -> V_94 : V_18 -> V_95 ;
if ( V_75 ) {
V_18 = V_75 ;
continue;
}
break;
}
while ( V_18 ) {
if ( F_81 ( V_18 ) || V_18 -> V_38 & V_41 ) {
struct V_87 * V_88 ;
V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 +
args -> V_80 ) ;
if ( F_45 ( & V_88 -> V_14 , args -> V_14 , V_88 -> V_79 ) ) {
#ifdef F_76
if ( V_18 -> V_152 ) {
struct V_17 * V_153 ;
V_153 = F_80 ( V_18 -> V_152 ,
args + 1 ) ;
if ( ! V_153 )
goto V_157;
V_18 = V_153 ;
}
#endif
if ( V_18 -> V_38 & V_41 )
return V_18 ;
}
}
#ifdef F_76
V_157:
#endif
if ( V_18 -> V_38 & V_39 )
break;
V_18 = V_18 -> V_96 ;
}
return NULL ;
}
struct V_17 * F_82 ( struct V_17 * V_60 , const struct V_78 * V_158 ,
const struct V_78 * V_159 )
{
struct V_17 * V_18 ;
struct V_156 args [] = {
{
. V_80 = F_73 ( struct V_21 , V_149 ) ,
. V_14 = V_158 ,
} ,
#ifdef F_76
{
. V_80 = F_73 ( struct V_21 , V_150 ) ,
. V_14 = V_159 ,
} ,
#endif
{
. V_80 = 0 ,
}
} ;
V_18 = F_80 ( V_60 , V_158 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_38 & V_40 )
V_18 = V_60 ;
return V_18 ;
}
static struct V_17 * F_83 ( struct V_17 * V_60 ,
const struct V_78 * V_14 ,
int V_79 , int V_80 )
{
struct V_17 * V_18 ;
for ( V_18 = V_60 ; V_18 ; ) {
struct V_87 * V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 + V_80 ) ;
if ( V_79 < V_18 -> V_13 ||
! F_45 ( & V_88 -> V_14 , V_14 , V_18 -> V_13 ) )
return NULL ;
if ( V_79 == V_18 -> V_13 )
return V_18 ;
if ( F_10 ( V_14 , V_18 -> V_13 ) )
V_18 = V_18 -> V_94 ;
else
V_18 = V_18 -> V_95 ;
}
return NULL ;
}
struct V_17 * F_84 ( struct V_17 * V_60 ,
const struct V_78 * V_158 , int V_160 ,
const struct V_78 * V_159 , int V_161 )
{
struct V_17 * V_18 ;
V_18 = F_83 ( V_60 , V_158 , V_160 ,
F_73 ( struct V_21 , V_149 ) ) ;
#ifdef F_76
if ( V_161 ) {
F_67 ( V_159 == NULL ) ;
if ( V_18 && V_18 -> V_152 )
V_18 = F_83 ( V_18 -> V_152 , V_159 , V_161 ,
F_73 ( struct V_21 , V_150 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_38 & V_41 )
return V_18 ;
return NULL ;
}
static struct V_21 * F_58 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
if ( V_18 -> V_38 & V_39 )
return V_6 -> V_9 . V_37 ;
while ( V_18 ) {
if ( V_18 -> V_95 )
return V_18 -> V_95 -> V_36 ;
if ( V_18 -> V_94 )
return V_18 -> V_94 -> V_36 ;
V_18 = F_81 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_79 ( struct V_6 * V_6 ,
struct V_17 * V_18 )
{
int V_162 ;
int V_163 ;
struct V_17 * V_164 , * V_86 ;
struct V_1 * V_2 ;
int V_111 = 0 ;
for (; ; ) {
F_44 ( L_6 , V_18 -> V_13 , V_111 ) ;
V_111 ++ ;
F_67 ( V_18 -> V_38 & V_41 ) ;
F_67 ( V_18 -> V_38 & V_40 ) ;
F_67 ( V_18 -> V_36 ) ;
V_162 = 0 ;
V_164 = NULL ;
if ( V_18 -> V_94 )
V_164 = V_18 -> V_94 , V_162 |= 1 ;
if ( V_18 -> V_95 )
V_164 = V_18 -> V_95 , V_162 |= 2 ;
if ( V_162 == 3 || F_81 ( V_18 )
#ifdef F_76
|| ( V_162 && V_18 -> V_38 & V_39 )
#endif
) {
V_18 -> V_36 = F_58 ( V_6 , V_18 ) ;
#if V_155 >= 2
if ( ! V_18 -> V_36 ) {
F_67 ( ! V_18 -> V_36 ) ;
V_18 -> V_36 = V_6 -> V_9 . V_37 ;
}
#endif
F_49 ( & V_18 -> V_36 -> V_23 ) ;
return V_18 -> V_96 ;
}
V_86 = V_18 -> V_96 ;
#ifdef F_76
if ( F_81 ( V_86 ) == V_18 ) {
F_67 ( ! ( V_18 -> V_38 & V_39 ) ) ;
F_81 ( V_86 ) = NULL ;
V_163 = V_165 ;
} else {
F_67 ( V_18 -> V_38 & V_39 ) ;
#endif
if ( V_86 -> V_94 == V_18 )
V_86 -> V_94 = V_164 ;
else if ( V_86 -> V_95 == V_18 )
V_86 -> V_95 = V_164 ;
#if V_155 >= 2
else
F_67 ( 1 ) ;
#endif
if ( V_164 )
V_164 -> V_96 = V_86 ;
V_163 = V_166 ;
#ifdef F_76
}
#endif
F_85 ( & V_3 ) ;
F_86 (w) {
if ( ! V_164 ) {
if ( V_2 -> V_60 == V_18 ) {
V_2 -> V_60 = V_2 -> V_66 = NULL ;
F_44 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_66 == V_18 ) {
F_44 ( L_8 , V_2 , V_2 -> V_64 , V_163 ) ;
V_2 -> V_66 = V_86 ;
V_2 -> V_64 = V_163 ;
}
} else {
if ( V_2 -> V_60 == V_18 ) {
V_2 -> V_60 = V_164 ;
F_44 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_66 == V_18 ) {
V_2 -> V_66 = V_164 ;
if ( V_162 & 2 ) {
F_44 ( L_10 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_166 ? V_167 : V_65 ;
} else {
F_44 ( L_10 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_168 ? V_167 : V_65 ;
}
}
}
}
F_87 ( & V_3 ) ;
F_13 ( V_18 ) ;
if ( V_86 -> V_38 & V_41 || F_81 ( V_86 ) )
return V_86 ;
F_15 ( V_86 -> V_36 ) ;
V_86 -> V_36 = NULL ;
V_18 = V_86 ;
}
}
static void F_88 ( struct V_17 * V_18 , struct V_21 * * V_169 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = * V_169 ;
struct V_6 * V_6 = V_110 -> V_139 ;
F_44 ( L_11 ) ;
* V_169 = V_22 -> V_24 . V_54 ;
V_22 -> V_137 = NULL ;
V_6 -> V_9 . V_140 -> V_141 -- ;
V_6 -> V_9 . V_140 -> V_170 ++ ;
if ( V_18 -> V_133 == V_22 )
V_18 -> V_133 = NULL ;
if ( V_22 -> V_130 ) {
struct V_21 * V_134 , * V_171 ;
F_65 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_134 -> V_130 -- ;
V_22 -> V_130 = 0 ;
F_89 ( & V_22 -> V_136 ) ;
}
F_85 ( & V_3 ) ;
F_86 (w) {
if ( V_2 -> V_64 == V_168 && V_2 -> V_36 == V_22 ) {
F_44 ( L_12 , V_2 ) ;
V_2 -> V_36 = V_22 -> V_24 . V_54 ;
if ( ! V_2 -> V_36 )
V_2 -> V_64 = V_167 ;
}
}
F_87 ( & V_3 ) ;
V_22 -> V_24 . V_54 = NULL ;
if ( ! V_18 -> V_36 ) {
V_18 -> V_38 &= ~ V_41 ;
V_6 -> V_9 . V_140 -> V_142 -- ;
V_18 = F_79 ( V_6 , V_18 ) ;
}
F_57 ( V_22 , V_18 , V_6 ) ;
F_66 ( V_172 , V_22 , V_110 ) ;
F_15 ( V_22 ) ;
}
int F_90 ( struct V_21 * V_22 , struct V_109 * V_110 )
{
struct V_6 * V_6 = V_110 -> V_139 ;
struct V_17 * V_18 = V_22 -> V_137 ;
struct V_21 * * V_169 ;
#if V_155 >= 2
if ( V_22 -> V_24 . V_173 > 0 ) {
F_67 ( V_18 ) ;
return - V_92 ;
}
#endif
if ( ! V_18 || V_22 == V_6 -> V_9 . V_37 )
return - V_92 ;
F_67 ( ! ( V_18 -> V_38 & V_41 ) ) ;
if ( ! ( V_22 -> V_97 & V_145 ) ) {
struct V_17 * V_86 = V_18 ;
#ifdef F_76
if ( V_22 -> V_150 . V_79 ) {
while ( ! ( V_86 -> V_38 & V_39 ) )
V_86 = V_86 -> V_96 ;
V_86 = V_86 -> V_96 ;
}
#endif
F_77 ( V_110 -> V_139 , V_86 ) ;
}
for ( V_169 = & V_18 -> V_36 ; * V_169 ; V_169 = & ( * V_169 ) -> V_24 . V_54 ) {
if ( * V_169 == V_22 ) {
F_88 ( V_18 , V_169 , V_110 ) ;
return 0 ;
}
}
return - V_92 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_17 * V_18 , * V_86 ;
for (; ; ) {
V_18 = V_2 -> V_66 ;
if ( ! V_18 )
return 0 ;
if ( V_2 -> V_174 && V_18 != V_2 -> V_60 &&
V_18 -> V_38 & V_41 && V_2 -> V_64 < V_168 ) {
V_2 -> V_64 = V_168 ;
V_2 -> V_36 = V_18 -> V_36 ;
}
switch ( V_2 -> V_64 ) {
#ifdef F_76
case V_175 :
if ( F_81 ( V_18 ) ) {
V_2 -> V_66 = F_81 ( V_18 ) ;
continue;
}
V_2 -> V_64 = V_165 ;
#endif
case V_165 :
if ( V_18 -> V_95 ) {
V_2 -> V_66 = V_18 -> V_95 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_166 ;
case V_166 :
if ( V_18 -> V_94 ) {
V_2 -> V_66 = V_18 -> V_94 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_168 ;
V_2 -> V_36 = V_18 -> V_36 ;
case V_168 :
if ( V_2 -> V_36 && V_18 -> V_38 & V_41 ) {
int V_122 ;
if ( V_2 -> V_62 ) {
V_2 -> V_62 -- ;
goto V_62;
}
V_122 = V_2 -> V_74 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_61 ++ ;
continue;
}
V_62:
V_2 -> V_64 = V_167 ;
case V_167 :
if ( V_18 == V_2 -> V_60 )
return 0 ;
V_86 = V_18 -> V_96 ;
V_2 -> V_66 = V_86 ;
#ifdef F_76
if ( F_81 ( V_86 ) == V_18 ) {
F_67 ( ! ( V_18 -> V_38 & V_39 ) ) ;
V_2 -> V_64 = V_165 ;
continue;
}
#endif
if ( V_86 -> V_95 == V_18 ) {
V_2 -> V_64 = V_166 ;
continue;
}
if ( V_86 -> V_94 == V_18 ) {
V_2 -> V_64 = V_168 ;
V_2 -> V_36 = V_2 -> V_66 -> V_36 ;
continue;
}
#if V_155 >= 2
F_67 ( 1 ) ;
#endif
}
}
}
static int F_38 ( struct V_1 * V_2 )
{
int V_53 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_2 -> V_60 ;
F_1 ( V_2 ) ;
V_53 = F_40 ( V_2 ) ;
if ( V_53 <= 0 )
F_5 ( V_2 ) ;
return V_53 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_21 * V_22 ;
struct V_176 * V_177 = F_92 ( V_2 , struct V_176 , V_2 ) ;
struct V_109 V_110 = {
. V_139 = V_177 -> V_6 ,
} ;
if ( V_177 -> V_83 != V_178 &&
V_2 -> V_66 -> V_63 != V_177 -> V_83 )
V_2 -> V_66 -> V_63 = V_177 -> V_83 ;
if ( ! V_177 -> V_74 ) {
F_93 ( V_177 -> V_83 == V_178 ) ;
V_2 -> V_36 = NULL ;
return 0 ;
}
for ( V_22 = V_2 -> V_36 ; V_22 ; V_22 = V_22 -> V_24 . V_54 ) {
V_53 = V_177 -> V_74 ( V_22 , V_177 -> V_72 ) ;
if ( V_53 < 0 ) {
V_2 -> V_36 = V_22 ;
V_53 = F_90 ( V_22 , & V_110 ) ;
if ( V_53 ) {
#if V_155 >= 2
F_94 ( L_13 ,
V_179 , V_22 , V_22 -> V_137 , V_53 ) ;
#endif
continue;
}
return 0 ;
}
F_67 ( V_53 != 0 ) ;
}
V_2 -> V_36 = V_22 ;
return 0 ;
}
static void F_95 ( struct V_6 * V_6 , struct V_17 * V_60 ,
int (* V_74)( struct V_21 * , void * V_72 ) ,
bool V_174 , int V_83 , void * V_72 )
{
struct V_176 V_177 ;
V_177 . V_2 . V_60 = V_60 ;
V_177 . V_2 . V_74 = F_91 ;
V_177 . V_2 . V_174 = V_174 ;
V_177 . V_2 . V_61 = 0 ;
V_177 . V_2 . V_62 = 0 ;
V_177 . V_74 = V_74 ;
V_177 . V_83 = V_83 ;
V_177 . V_72 = V_72 ;
V_177 . V_6 = V_6 ;
F_38 ( & V_177 . V_2 ) ;
}
static void F_96 ( struct V_6 * V_6 ,
int (* V_74)( struct V_21 * , void * ) ,
int V_83 , void * V_72 )
{
struct V_25 * V_34 ;
struct V_44 * V_45 ;
unsigned int V_27 ;
F_26 () ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
V_45 = & V_6 -> V_9 . V_32 [ V_27 ] ;
F_27 (table, head, tb6_hlist) {
F_2 ( & V_34 -> V_28 ) ;
F_95 ( V_6 , & V_34 -> V_35 ,
V_74 , false , V_83 , V_72 ) ;
F_4 ( & V_34 -> V_28 ) ;
}
}
F_28 () ;
}
void F_97 ( struct V_6 * V_6 , int (* V_74)( struct V_21 * , void * ) ,
void * V_72 )
{
F_96 ( V_6 , V_74 , V_178 , V_72 ) ;
}
static int F_98 ( struct V_21 * V_22 , void * V_72 )
{
if ( V_22 -> V_97 & V_145 ) {
F_44 ( L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_77 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
F_95 ( V_6 , V_18 , F_98 , true ,
V_178 , NULL ) ;
}
static void F_99 ( struct V_6 * V_6 )
{
int V_180 = F_7 ( V_6 ) ;
F_96 ( V_6 , NULL , V_180 , NULL ) ;
}
static int F_100 ( struct V_21 * V_22 , void * V_72 )
{
unsigned long V_181 = V_146 ;
if ( V_22 -> V_97 & V_131 && V_22 -> V_24 . V_132 ) {
if ( F_101 ( V_181 , V_22 -> V_24 . V_132 ) ) {
F_44 ( L_15 , V_22 ) ;
return - 1 ;
}
V_182 . V_183 ++ ;
} else if ( V_22 -> V_97 & V_145 ) {
if ( F_8 ( & V_22 -> V_24 . V_184 ) == 0 &&
F_102 ( V_181 , V_22 -> V_24 . V_185 + V_182 . V_186 ) ) {
F_44 ( L_16 , V_22 ) ;
return - 1 ;
} else if ( V_22 -> V_97 & V_98 ) {
struct V_187 * V_188 ;
T_5 V_189 = 0 ;
V_188 = F_103 ( & V_22 -> V_24 , & V_22 -> V_129 ) ;
if ( V_188 ) {
V_189 = V_188 -> V_51 ;
F_104 ( V_188 ) ;
}
if ( ! ( V_189 & V_190 ) ) {
F_44 ( L_17 ,
V_22 ) ;
return - 1 ;
}
}
V_182 . V_183 ++ ;
}
return 0 ;
}
void F_105 ( unsigned long V_132 , struct V_6 * V_6 , bool V_191 )
{
unsigned long V_181 ;
if ( V_191 ) {
F_106 ( & V_192 ) ;
} else if ( ! F_107 ( & V_192 ) ) {
F_70 ( & V_6 -> V_9 . V_144 , V_146 + V_193 ) ;
return;
}
V_182 . V_186 = V_132 ? ( int ) V_132 :
V_6 -> V_9 . V_147 . V_148 ;
V_182 . V_183 = F_108 () ;
F_97 ( V_6 , F_100 , NULL ) ;
V_181 = V_146 ;
V_6 -> V_9 . V_194 = V_181 ;
if ( V_182 . V_183 )
F_70 ( & V_6 -> V_9 . V_144 ,
F_109 ( V_181
+ V_6 -> V_9 . V_147 . V_148 ) ) ;
else
F_110 ( & V_6 -> V_9 . V_144 ) ;
F_111 ( & V_192 ) ;
}
static void F_112 ( unsigned long V_72 )
{
F_105 ( 0 , (struct V_6 * ) V_72 , true ) ;
}
static int T_3 F_113 ( struct V_6 * V_6 )
{
T_6 V_195 = sizeof( struct V_44 ) * V_30 ;
F_114 ( & V_6 -> V_9 . V_144 , F_112 , ( unsigned long ) V_6 ) ;
V_6 -> V_9 . V_140 = F_22 ( sizeof( * V_6 -> V_9 . V_140 ) , V_196 ) ;
if ( ! V_6 -> V_9 . V_140 )
goto V_197;
V_195 = F_115 ( T_6 , V_195 , V_198 ) ;
V_6 -> V_9 . V_32 = F_22 ( V_195 , V_196 ) ;
if ( ! V_6 -> V_9 . V_32 )
goto V_199;
V_6 -> V_9 . V_46 = F_22 ( sizeof( * V_6 -> V_9 . V_46 ) ,
V_196 ) ;
if ( ! V_6 -> V_9 . V_46 )
goto V_200;
V_6 -> V_9 . V_46 -> V_29 = V_43 ;
V_6 -> V_9 . V_46 -> V_35 . V_36 = V_6 -> V_9 . V_37 ;
V_6 -> V_9 . V_46 -> V_35 . V_38 =
V_39 | V_40 | V_41 ;
F_23 ( & V_6 -> V_9 . V_46 -> V_42 ) ;
#ifdef F_116
V_6 -> V_9 . V_47 = F_22 ( sizeof( * V_6 -> V_9 . V_47 ) ,
V_196 ) ;
if ( ! V_6 -> V_9 . V_47 )
goto V_201;
V_6 -> V_9 . V_47 -> V_29 = V_202 ;
V_6 -> V_9 . V_47 -> V_35 . V_36 = V_6 -> V_9 . V_37 ;
V_6 -> V_9 . V_47 -> V_35 . V_38 =
V_39 | V_40 | V_41 ;
F_23 ( & V_6 -> V_9 . V_47 -> V_42 ) ;
#endif
F_29 ( V_6 ) ;
return 0 ;
#ifdef F_116
V_201:
F_34 ( V_6 -> V_9 . V_46 ) ;
#endif
V_200:
F_34 ( V_6 -> V_9 . V_32 ) ;
V_199:
F_34 ( V_6 -> V_9 . V_140 ) ;
V_197:
return - V_73 ;
}
static void F_117 ( struct V_6 * V_6 )
{
F_118 ( V_6 , NULL ) ;
F_119 ( & V_6 -> V_9 . V_144 ) ;
#ifdef F_116
F_120 ( & V_6 -> V_9 . V_47 -> V_42 ) ;
F_34 ( V_6 -> V_9 . V_47 ) ;
#endif
F_120 ( & V_6 -> V_9 . V_46 -> V_42 ) ;
F_34 ( V_6 -> V_9 . V_46 ) ;
F_34 ( V_6 -> V_9 . V_32 ) ;
F_34 ( V_6 -> V_9 . V_140 ) ;
}
int T_7 F_121 ( void )
{
int V_203 = - V_73 ;
V_19 = F_122 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_204 ,
NULL ) ;
if ( ! V_19 )
goto V_76;
V_203 = F_123 ( & V_205 ) ;
if ( V_203 )
goto V_206;
V_203 = F_124 ( V_207 , V_208 , NULL , F_41 ,
NULL ) ;
if ( V_203 )
goto V_209;
V_210 = F_99 ;
V_76:
return V_203 ;
V_209:
F_125 ( & V_205 ) ;
V_206:
F_126 ( V_19 ) ;
goto V_76;
}
void F_127 ( void )
{
F_125 ( & V_205 ) ;
F_126 ( V_19 ) ;
}
static int F_128 ( struct V_211 * V_212 , void * V_213 )
{
struct V_21 * V_22 = V_213 ;
struct V_214 * V_111 = V_212 -> V_215 ;
F_129 ( V_212 , L_19 , & V_22 -> V_149 . V_14 , V_22 -> V_149 . V_79 ) ;
#ifdef F_76
F_129 ( V_212 , L_19 , & V_22 -> V_150 . V_14 , V_22 -> V_150 . V_79 ) ;
#else
F_130 ( V_212 , L_20 ) ;
#endif
if ( V_22 -> V_97 & V_98 )
F_129 ( V_212 , L_21 , & V_22 -> V_129 ) ;
else
F_130 ( V_212 , L_22 ) ;
F_129 ( V_212 , L_23 ,
V_22 -> V_123 , F_8 ( & V_22 -> V_24 . V_184 ) ,
V_22 -> V_24 . V_216 , V_22 -> V_97 ,
V_22 -> V_24 . V_127 ? V_22 -> V_24 . V_127 -> V_217 : L_24 ) ;
V_111 -> V_2 . V_36 = NULL ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_214 * V_111 = V_2 -> args ;
if ( ! V_111 -> V_62 )
return 1 ;
do {
V_111 -> V_2 . V_36 = V_111 -> V_2 . V_36 -> V_24 . V_54 ;
V_111 -> V_62 -- ;
if ( ! V_111 -> V_62 && V_111 -> V_2 . V_36 )
return 1 ;
} while ( V_111 -> V_2 . V_36 );
return 0 ;
}
static void F_132 ( struct V_214 * V_111 )
{
memset ( & V_111 -> V_2 , 0 , sizeof( V_111 -> V_2 ) ) ;
V_111 -> V_2 . V_74 = F_131 ;
V_111 -> V_2 . V_60 = & V_111 -> V_218 -> V_35 ;
V_111 -> V_2 . V_64 = V_65 ;
V_111 -> V_2 . V_66 = V_111 -> V_2 . V_60 ;
V_111 -> V_2 . args = V_111 ;
V_111 -> V_83 = V_111 -> V_2 . V_60 -> V_63 ;
F_133 ( & V_111 -> V_2 . V_4 ) ;
F_1 ( & V_111 -> V_2 ) ;
}
static struct V_25 * F_134 ( struct V_25 * V_218 ,
struct V_6 * V_6 )
{
unsigned int V_27 ;
struct V_219 * V_66 ;
if ( V_218 ) {
V_27 = ( V_218 -> V_29 & ( V_30 - 1 ) ) + 1 ;
V_66 = F_135 ( F_136 ( & V_218 -> V_31 ) ) ;
} else {
V_27 = 0 ;
V_66 = NULL ;
}
while ( ! V_66 && V_27 < V_30 ) {
V_66 = F_135 (
F_137 ( & V_6 -> V_9 . V_32 [ V_27 ++ ] ) ) ;
}
return F_138 ( V_66 , struct V_25 , V_31 ) ;
}
static void F_139 ( struct V_214 * V_111 )
{
if ( V_111 -> V_83 != V_111 -> V_2 . V_60 -> V_63 ) {
V_111 -> V_83 = V_111 -> V_2 . V_60 -> V_63 ;
V_111 -> V_2 . V_64 = V_65 ;
V_111 -> V_2 . V_66 = V_111 -> V_2 . V_60 ;
F_67 ( V_111 -> V_2 . V_62 ) ;
V_111 -> V_2 . V_62 = V_111 -> V_2 . V_61 ;
}
}
static void * F_140 ( struct V_211 * V_212 , void * V_213 , T_8 * V_220 )
{
int V_221 ;
struct V_21 * V_222 ;
struct V_6 * V_6 = F_141 ( V_212 ) ;
struct V_214 * V_111 = V_212 -> V_215 ;
if ( ! V_213 )
goto V_223;
V_222 = ( (struct V_21 * ) V_213 ) -> V_24 . V_54 ;
if ( V_222 ) {
++ * V_220 ;
return V_222 ;
}
V_223:
F_139 ( V_111 ) ;
F_85 ( & V_111 -> V_218 -> V_28 ) ;
V_221 = F_40 ( & V_111 -> V_2 ) ;
F_87 ( & V_111 -> V_218 -> V_28 ) ;
if ( V_221 > 0 ) {
if ( V_213 )
++ * V_220 ;
return V_111 -> V_2 . V_36 ;
} else if ( V_221 < 0 ) {
F_5 ( & V_111 -> V_2 ) ;
return NULL ;
}
F_5 ( & V_111 -> V_2 ) ;
V_111 -> V_218 = F_134 ( V_111 -> V_218 , V_6 ) ;
if ( ! V_111 -> V_218 )
return NULL ;
F_132 ( V_111 ) ;
goto V_223;
}
static void * F_142 ( struct V_211 * V_212 , T_8 * V_220 )
__acquires( T_9 )
{
struct V_6 * V_6 = F_141 ( V_212 ) ;
struct V_214 * V_111 = V_212 -> V_215 ;
F_143 () ;
V_111 -> V_218 = F_134 ( NULL , V_6 ) ;
V_111 -> V_62 = * V_220 ;
if ( V_111 -> V_218 ) {
F_132 ( V_111 ) ;
return F_140 ( V_212 , NULL , V_220 ) ;
} else {
return NULL ;
}
}
static bool F_144 ( struct V_214 * V_111 )
{
struct V_1 * V_2 = & V_111 -> V_2 ;
return V_2 -> V_66 && ! ( V_2 -> V_64 == V_167 && V_2 -> V_66 == V_2 -> V_60 ) ;
}
static void F_145 ( struct V_211 * V_212 , void * V_213 )
__releases( T_9 )
{
struct V_214 * V_111 = V_212 -> V_215 ;
if ( F_144 ( V_111 ) )
F_5 ( & V_111 -> V_2 ) ;
F_146 () ;
}
int F_147 ( struct V_224 * V_224 , struct V_225 * V_225 )
{
return F_148 ( V_224 , V_225 , & V_226 ,
sizeof( struct V_214 ) ) ;
}
