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
F_33 ( V_53 == 0 ) ;
}
V_2 -> V_36 = NULL ;
return 0 ;
}
static void F_34 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = ( void * ) V_56 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_56 -> args [ 4 ] ) {
V_56 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_56 -> args [ 2 ] = 0 ;
F_35 ( V_2 ) ;
}
V_56 -> V_57 = ( void * ) V_56 -> args [ 3 ] ;
V_56 -> args [ 1 ] = 3 ;
}
static int F_36 ( struct V_55 * V_56 )
{
F_34 ( V_56 ) ;
return V_56 -> V_57 ? V_56 -> V_57 ( V_56 ) : 0 ;
}
static int F_37 ( struct V_25 * V_34 , struct V_58 * V_59 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_53 ;
V_2 = ( void * ) V_56 -> args [ 2 ] ;
V_2 -> V_60 = & V_34 -> V_35 ;
if ( V_56 -> args [ 4 ] == 0 ) {
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
F_38 ( & V_34 -> V_28 ) ;
V_53 = F_39 ( V_2 ) ;
F_40 ( & V_34 -> V_28 ) ;
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
F_38 ( & V_34 -> V_28 ) ;
V_53 = F_41 ( V_2 ) ;
F_40 ( & V_34 -> V_28 ) ;
if ( V_53 <= 0 ) {
F_5 ( V_2 ) ;
V_56 -> args [ 4 ] = 0 ;
}
}
return V_53 ;
}
static int F_42 ( struct V_58 * V_59 , struct V_55 * V_56 )
{
struct V_6 * V_6 = F_43 ( V_59 -> V_67 ) ;
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
V_56 -> V_57 = F_36 ;
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
V_53 = F_37 ( V_26 , V_59 , V_56 ) ;
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
F_34 ( V_56 ) ;
return V_53 ;
}
static struct V_17 * F_44 ( struct V_17 * V_60 ,
struct V_78 * V_14 , int V_79 ,
int V_80 , int V_81 ,
int V_82 , int V_83 )
{
struct V_17 * V_18 , * V_84 , * V_85 ;
struct V_17 * V_86 = NULL ;
struct V_87 * V_88 ;
int V_89 ;
T_1 V_90 = 0 ;
F_45 ( L_1 ) ;
V_18 = V_60 ;
do {
V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 + V_80 ) ;
if ( V_79 < V_18 -> V_13 ||
! F_46 ( & V_88 -> V_14 , V_14 , V_18 -> V_13 ) ) {
if ( ! V_81 ) {
if ( V_82 ) {
F_47 ( L_2 ) ;
return F_48 ( - V_92 ) ;
}
F_47 ( L_3 ) ;
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
F_47 ( L_2 ) ;
return F_48 ( - V_92 ) ;
}
F_47 ( L_3 ) ;
}
V_85 = F_11 () ;
if ( ! V_85 )
return F_48 ( - V_73 ) ;
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
V_89 = F_49 ( V_14 , & V_88 -> V_14 , sizeof( * V_14 ) ) ;
if ( V_79 > V_89 ) {
V_84 = F_11 () ;
V_85 = F_11 () ;
if ( ! V_84 || ! V_85 ) {
if ( V_84 )
F_13 ( V_84 ) ;
if ( V_85 )
F_13 ( V_85 ) ;
return F_48 ( - V_73 ) ;
}
V_84 -> V_13 = V_89 ;
V_84 -> V_96 = V_86 ;
V_84 -> V_36 = V_18 -> V_36 ;
F_50 ( & V_84 -> V_36 -> V_23 ) ;
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
return F_48 ( - V_73 ) ;
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
static bool F_51 ( struct V_21 * V_22 )
{
return ( V_22 -> V_97 & ( V_98 | V_99 | V_100 ) ) ==
V_98 ;
}
static int F_52 ( struct V_48 * V_24 ,
struct V_101 * V_102 , int V_103 )
{
struct V_101 * V_104 ;
int V_105 ;
T_2 * V_106 ;
if ( V_24 -> V_51 & V_107 ) {
V_106 = F_53 ( V_24 ) ;
} else {
V_106 = F_22 ( sizeof( T_2 ) * V_108 , V_20 ) ;
if ( ! V_106 )
return - V_73 ;
F_54 ( V_24 , V_106 , 0 ) ;
}
F_55 (nla, mx, mx_len, remaining) {
int type = F_56 ( V_104 ) ;
if ( type ) {
if ( type > V_108 )
return - V_109 ;
V_106 [ type - 1 ] = F_57 ( V_104 ) ;
}
}
return 0 ;
}
static void F_58 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_6 * V_6 )
{
if ( F_8 ( & V_22 -> V_23 ) != 1 ) {
while ( V_18 ) {
if ( ! ( V_18 -> V_38 & V_41 ) && V_18 -> V_36 == V_22 ) {
V_18 -> V_36 = F_59 ( V_6 , V_18 ) ;
F_50 ( & V_18 -> V_36 -> V_23 ) ;
F_15 ( V_22 ) ;
}
V_18 = V_18 -> V_96 ;
}
F_60 ( F_8 ( & V_22 -> V_23 ) != 1 ) ;
}
}
static int F_61 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_110 * V_111 , struct V_101 * V_102 , int V_103 )
{
struct V_21 * V_112 = NULL ;
struct V_21 * * V_113 ;
int V_114 = ( V_111 -> V_115 &&
( V_111 -> V_115 -> V_116 & V_117 ) ) ;
int V_118 = ( ! V_111 -> V_115 ||
( V_111 -> V_115 -> V_116 & V_119 ) ) ;
int V_120 = 0 ;
bool V_121 = F_51 ( V_22 ) ;
int V_122 ;
V_113 = & V_18 -> V_36 ;
for ( V_112 = V_18 -> V_36 ; V_112 ; V_112 = V_112 -> V_24 . V_54 ) {
if ( V_112 -> V_123 == V_22 -> V_123 ) {
if ( V_111 -> V_115 &&
( V_111 -> V_115 -> V_116 & V_124 ) )
return - V_125 ;
if ( V_114 ) {
V_120 ++ ;
break;
}
if ( V_112 -> V_24 . V_126 == V_22 -> V_24 . V_126 &&
V_112 -> V_127 == V_22 -> V_127 &&
F_62 ( & V_112 -> V_128 ,
& V_22 -> V_128 ) ) {
if ( V_22 -> V_129 )
V_22 -> V_129 = 0 ;
if ( ! ( V_112 -> V_97 & V_130 ) )
return - V_125 ;
if ( ! ( V_22 -> V_97 & V_130 ) )
F_63 ( V_112 ) ;
else
F_64 ( V_112 , V_22 -> V_24 . V_131 ) ;
return - V_125 ;
}
if ( V_121 &&
F_51 ( V_112 ) )
V_22 -> V_129 ++ ;
}
if ( V_112 -> V_123 > V_22 -> V_123 )
break;
V_113 = & V_112 -> V_24 . V_54 ;
}
if ( V_113 == & V_18 -> V_36 )
V_18 -> V_132 = NULL ;
if ( V_22 -> V_129 ) {
unsigned int V_129 ;
struct V_21 * V_133 , * V_134 ;
V_133 = V_18 -> V_36 ;
while ( V_133 ) {
if ( V_133 -> V_123 == V_22 -> V_123 &&
F_51 ( V_133 ) ) {
F_65 ( & V_22 -> V_135 ,
& V_133 -> V_135 ) ;
break;
}
V_133 = V_133 -> V_24 . V_54 ;
}
V_129 = 0 ;
F_66 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_133 -> V_129 ++ ;
F_60 ( V_133 -> V_129 != V_22 -> V_129 ) ;
V_129 ++ ;
}
F_60 ( V_129 != V_22 -> V_129 ) ;
}
if ( ! V_114 ) {
if ( ! V_118 )
F_47 ( L_3 ) ;
V_118:
if ( V_102 ) {
V_122 = F_52 ( & V_22 -> V_24 , V_102 , V_103 ) ;
if ( V_122 )
return V_122 ;
}
V_22 -> V_24 . V_54 = V_112 ;
* V_113 = V_22 ;
V_22 -> V_136 = V_18 ;
F_50 ( & V_22 -> V_23 ) ;
F_67 ( V_137 , V_22 , V_111 ) ;
V_111 -> V_138 -> V_9 . V_139 -> V_140 ++ ;
if ( ! ( V_18 -> V_38 & V_41 ) ) {
V_111 -> V_138 -> V_9 . V_139 -> V_141 ++ ;
V_18 -> V_38 |= V_41 ;
}
} else {
if ( ! V_120 ) {
if ( V_118 )
goto V_118;
F_47 ( L_4 ) ;
return - V_92 ;
}
if ( V_102 ) {
V_122 = F_52 ( & V_22 -> V_24 , V_102 , V_103 ) ;
if ( V_122 )
return V_122 ;
}
* V_113 = V_22 ;
V_22 -> V_136 = V_18 ;
V_22 -> V_24 . V_54 = V_112 -> V_24 . V_54 ;
F_50 ( & V_22 -> V_23 ) ;
F_67 ( V_137 , V_22 , V_111 ) ;
if ( ! ( V_18 -> V_38 & V_41 ) ) {
V_111 -> V_138 -> V_9 . V_139 -> V_141 ++ ;
V_18 -> V_38 |= V_41 ;
}
F_58 ( V_112 , V_18 , V_111 -> V_138 ) ;
F_15 ( V_112 ) ;
}
return 0 ;
}
static void F_68 ( struct V_6 * V_6 , struct V_21 * V_22 )
{
if ( ! F_69 ( & V_6 -> V_9 . V_142 ) &&
( V_22 -> V_97 & ( V_130 | V_143 ) ) )
F_70 ( & V_6 -> V_9 . V_142 ,
V_144 + V_6 -> V_9 . V_145 . V_146 ) ;
}
void F_71 ( struct V_6 * V_6 )
{
if ( ! F_69 ( & V_6 -> V_9 . V_142 ) )
F_70 ( & V_6 -> V_9 . V_142 ,
V_144 + V_6 -> V_9 . V_145 . V_146 ) ;
}
int F_72 ( struct V_17 * V_60 , struct V_21 * V_22 , struct V_110 * V_111 ,
struct V_101 * V_102 , int V_103 )
{
struct V_17 * V_18 , * V_86 = NULL ;
int V_122 = - V_73 ;
int V_81 = 1 ;
int V_82 = 0 ;
int V_83 = F_7 ( V_111 -> V_138 ) ;
if ( V_111 -> V_115 ) {
if ( ! ( V_111 -> V_115 -> V_116 & V_119 ) )
V_81 = 0 ;
if ( V_111 -> V_115 -> V_116 & V_117 )
V_82 = 1 ;
}
if ( ! V_81 && ! V_82 )
F_47 ( L_5 ) ;
V_18 = F_44 ( V_60 , & V_22 -> V_147 . V_14 , V_22 -> V_147 . V_79 ,
F_73 ( struct V_21 , V_147 ) , V_81 ,
V_82 , V_83 ) ;
if ( F_74 ( V_18 ) ) {
V_122 = F_75 ( V_18 ) ;
V_18 = NULL ;
goto V_76;
}
V_86 = V_18 ;
#ifdef F_76
if ( V_22 -> V_148 . V_79 ) {
struct V_17 * V_149 ;
if ( ! V_18 -> V_150 ) {
struct V_17 * V_151 ;
V_151 = F_11 () ;
if ( ! V_151 )
goto V_152;
V_151 -> V_36 = V_111 -> V_138 -> V_9 . V_37 ;
F_50 ( & V_111 -> V_138 -> V_9 . V_37 -> V_23 ) ;
V_151 -> V_38 = V_39 ;
V_151 -> V_63 = V_83 ;
V_149 = F_44 ( V_151 , & V_22 -> V_148 . V_14 ,
V_22 -> V_148 . V_79 ,
F_73 ( struct V_21 , V_148 ) ,
V_81 , V_82 , V_83 ) ;
if ( F_74 ( V_149 ) ) {
F_13 ( V_151 ) ;
V_122 = F_75 ( V_149 ) ;
goto V_152;
}
V_151 -> V_96 = V_18 ;
V_18 -> V_150 = V_151 ;
} else {
V_149 = F_44 ( V_18 -> V_150 , & V_22 -> V_148 . V_14 ,
V_22 -> V_148 . V_79 ,
F_73 ( struct V_21 , V_148 ) ,
V_81 , V_82 , V_83 ) ;
if ( F_74 ( V_149 ) ) {
V_122 = F_75 ( V_149 ) ;
goto V_152;
}
}
if ( ! V_18 -> V_36 ) {
V_18 -> V_36 = V_22 ;
F_50 ( & V_22 -> V_23 ) ;
}
V_18 = V_149 ;
}
#endif
V_122 = F_61 ( V_18 , V_22 , V_111 , V_102 , V_103 ) ;
if ( ! V_122 ) {
F_68 ( V_111 -> V_138 , V_22 ) ;
if ( ! ( V_22 -> V_97 & V_143 ) )
F_77 ( V_111 -> V_138 , V_86 ) ;
}
V_76:
if ( V_122 ) {
#ifdef F_76
if ( V_86 != V_18 && V_86 -> V_36 == V_22 ) {
V_86 -> V_36 = NULL ;
F_78 ( & V_22 -> V_23 ) ;
}
if ( V_86 != V_18 && ! V_86 -> V_36 && ! ( V_86 -> V_38 & V_41 ) ) {
V_86 -> V_36 = F_59 ( V_111 -> V_138 , V_86 ) ;
#if V_153 >= 2
if ( ! V_86 -> V_36 ) {
F_33 ( V_86 -> V_36 == NULL ) ;
V_86 -> V_36 = V_111 -> V_138 -> V_9 . V_37 ;
}
#endif
F_50 ( & V_86 -> V_36 -> V_23 ) ;
}
#endif
F_17 ( & V_22 -> V_24 ) ;
}
return V_122 ;
#ifdef F_76
V_152:
if ( V_18 && ! ( V_18 -> V_38 & ( V_41 | V_39 ) ) )
F_79 ( V_111 -> V_138 , V_18 ) ;
F_17 ( & V_22 -> V_24 ) ;
return V_122 ;
#endif
}
static struct V_17 * F_80 ( struct V_17 * V_60 ,
struct V_154 * args )
{
struct V_17 * V_18 ;
T_1 V_90 ;
if ( F_81 ( args -> V_80 == 0 ) )
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
if ( F_82 ( V_18 ) || V_18 -> V_38 & V_41 ) {
struct V_87 * V_88 ;
V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 +
args -> V_80 ) ;
if ( F_46 ( & V_88 -> V_14 , args -> V_14 , V_88 -> V_79 ) ) {
#ifdef F_76
if ( V_18 -> V_150 ) {
struct V_17 * V_151 ;
V_151 = F_80 ( V_18 -> V_150 ,
args + 1 ) ;
if ( ! V_151 )
goto V_155;
V_18 = V_151 ;
}
#endif
if ( V_18 -> V_38 & V_41 )
return V_18 ;
}
}
#ifdef F_76
V_155:
#endif
if ( V_18 -> V_38 & V_39 )
break;
V_18 = V_18 -> V_96 ;
}
return NULL ;
}
struct V_17 * F_83 ( struct V_17 * V_60 , const struct V_78 * V_156 ,
const struct V_78 * V_157 )
{
struct V_17 * V_18 ;
struct V_154 args [] = {
{
. V_80 = F_73 ( struct V_21 , V_147 ) ,
. V_14 = V_156 ,
} ,
#ifdef F_76
{
. V_80 = F_73 ( struct V_21 , V_148 ) ,
. V_14 = V_157 ,
} ,
#endif
{
. V_80 = 0 ,
}
} ;
V_18 = F_80 ( V_60 , V_156 ? args : args + 1 ) ;
if ( ! V_18 || V_18 -> V_38 & V_40 )
V_18 = V_60 ;
return V_18 ;
}
static struct V_17 * F_84 ( struct V_17 * V_60 ,
const struct V_78 * V_14 ,
int V_79 , int V_80 )
{
struct V_17 * V_18 ;
for ( V_18 = V_60 ; V_18 ; ) {
struct V_87 * V_88 = (struct V_87 * ) ( ( V_91 * ) V_18 -> V_36 + V_80 ) ;
if ( V_79 < V_18 -> V_13 ||
! F_46 ( & V_88 -> V_14 , V_14 , V_18 -> V_13 ) )
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
struct V_17 * F_85 ( struct V_17 * V_60 ,
const struct V_78 * V_156 , int V_158 ,
const struct V_78 * V_157 , int V_159 )
{
struct V_17 * V_18 ;
V_18 = F_84 ( V_60 , V_156 , V_158 ,
F_73 ( struct V_21 , V_147 ) ) ;
#ifdef F_76
if ( V_159 ) {
F_33 ( V_157 == NULL ) ;
if ( V_18 && V_18 -> V_150 )
V_18 = F_84 ( V_18 -> V_150 , V_157 , V_159 ,
F_73 ( struct V_21 , V_148 ) ) ;
}
#endif
if ( V_18 && V_18 -> V_38 & V_41 )
return V_18 ;
return NULL ;
}
static struct V_21 * F_59 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
if ( V_18 -> V_38 & V_39 )
return V_6 -> V_9 . V_37 ;
while ( V_18 ) {
if ( V_18 -> V_95 )
return V_18 -> V_95 -> V_36 ;
if ( V_18 -> V_94 )
return V_18 -> V_94 -> V_36 ;
V_18 = F_82 ( V_18 ) ;
}
return NULL ;
}
static struct V_17 * F_79 ( struct V_6 * V_6 ,
struct V_17 * V_18 )
{
int V_160 ;
int V_161 ;
struct V_17 * V_162 , * V_86 ;
struct V_1 * V_2 ;
int V_112 = 0 ;
for (; ; ) {
F_45 ( L_6 , V_18 -> V_13 , V_112 ) ;
V_112 ++ ;
F_33 ( V_18 -> V_38 & V_41 ) ;
F_33 ( V_18 -> V_38 & V_40 ) ;
F_33 ( V_18 -> V_36 != NULL ) ;
V_160 = 0 ;
V_162 = NULL ;
if ( V_18 -> V_94 )
V_162 = V_18 -> V_94 , V_160 |= 1 ;
if ( V_18 -> V_95 )
V_162 = V_18 -> V_95 , V_160 |= 2 ;
if ( V_160 == 3 || F_82 ( V_18 )
#ifdef F_76
|| ( V_160 && V_18 -> V_38 & V_39 )
#endif
) {
V_18 -> V_36 = F_59 ( V_6 , V_18 ) ;
#if V_153 >= 2
if ( ! V_18 -> V_36 ) {
F_33 ( ! V_18 -> V_36 ) ;
V_18 -> V_36 = V_6 -> V_9 . V_37 ;
}
#endif
F_50 ( & V_18 -> V_36 -> V_23 ) ;
return V_18 -> V_96 ;
}
V_86 = V_18 -> V_96 ;
#ifdef F_76
if ( F_82 ( V_86 ) == V_18 ) {
F_33 ( ! ( V_18 -> V_38 & V_39 ) ) ;
F_82 ( V_86 ) = NULL ;
V_161 = V_163 ;
} else {
F_33 ( V_18 -> V_38 & V_39 ) ;
#endif
if ( V_86 -> V_94 == V_18 )
V_86 -> V_94 = V_162 ;
else if ( V_86 -> V_95 == V_18 )
V_86 -> V_95 = V_162 ;
#if V_153 >= 2
else
F_33 ( 1 ) ;
#endif
if ( V_162 )
V_162 -> V_96 = V_86 ;
V_161 = V_164 ;
#ifdef F_76
}
#endif
F_86 ( & V_3 ) ;
F_87 (w) {
if ( ! V_162 ) {
if ( V_2 -> V_60 == V_18 ) {
V_2 -> V_60 = V_2 -> V_66 = NULL ;
F_45 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_66 == V_18 ) {
F_45 ( L_8 , V_2 , V_2 -> V_64 , V_161 ) ;
V_2 -> V_66 = V_86 ;
V_2 -> V_64 = V_161 ;
}
} else {
if ( V_2 -> V_60 == V_18 ) {
V_2 -> V_60 = V_162 ;
F_45 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_66 == V_18 ) {
V_2 -> V_66 = V_162 ;
if ( V_160 & 2 ) {
F_45 ( L_10 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_164 ? V_165 : V_65 ;
} else {
F_45 ( L_10 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_166 ? V_165 : V_65 ;
}
}
}
}
F_88 ( & V_3 ) ;
F_13 ( V_18 ) ;
if ( V_86 -> V_38 & V_41 || F_82 ( V_86 ) )
return V_86 ;
F_15 ( V_86 -> V_36 ) ;
V_86 -> V_36 = NULL ;
V_18 = V_86 ;
}
}
static void F_89 ( struct V_17 * V_18 , struct V_21 * * V_167 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = * V_167 ;
struct V_6 * V_6 = V_111 -> V_138 ;
F_45 ( L_11 ) ;
* V_167 = V_22 -> V_24 . V_54 ;
V_22 -> V_136 = NULL ;
V_6 -> V_9 . V_139 -> V_140 -- ;
V_6 -> V_9 . V_139 -> V_168 ++ ;
if ( V_18 -> V_132 == V_22 )
V_18 -> V_132 = NULL ;
if ( V_22 -> V_129 ) {
struct V_21 * V_133 , * V_169 ;
F_66 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_133 -> V_129 -- ;
V_22 -> V_129 = 0 ;
F_90 ( & V_22 -> V_135 ) ;
}
F_86 ( & V_3 ) ;
F_87 (w) {
if ( V_2 -> V_64 == V_166 && V_2 -> V_36 == V_22 ) {
F_45 ( L_12 , V_2 ) ;
V_2 -> V_36 = V_22 -> V_24 . V_54 ;
if ( ! V_2 -> V_36 )
V_2 -> V_64 = V_165 ;
}
}
F_88 ( & V_3 ) ;
V_22 -> V_24 . V_54 = NULL ;
if ( ! V_18 -> V_36 ) {
V_18 -> V_38 &= ~ V_41 ;
V_6 -> V_9 . V_139 -> V_141 -- ;
V_18 = F_79 ( V_6 , V_18 ) ;
}
F_58 ( V_22 , V_18 , V_6 ) ;
F_67 ( V_170 , V_22 , V_111 ) ;
F_15 ( V_22 ) ;
}
int F_91 ( struct V_21 * V_22 , struct V_110 * V_111 )
{
struct V_6 * V_6 = V_111 -> V_138 ;
struct V_17 * V_18 = V_22 -> V_136 ;
struct V_21 * * V_167 ;
#if V_153 >= 2
if ( V_22 -> V_24 . V_171 > 0 ) {
F_33 ( V_18 != NULL ) ;
return - V_92 ;
}
#endif
if ( ! V_18 || V_22 == V_6 -> V_9 . V_37 )
return - V_92 ;
F_33 ( ! ( V_18 -> V_38 & V_41 ) ) ;
if ( ! ( V_22 -> V_97 & V_143 ) ) {
struct V_17 * V_86 = V_18 ;
#ifdef F_76
if ( V_22 -> V_148 . V_79 ) {
while ( ! ( V_86 -> V_38 & V_39 ) )
V_86 = V_86 -> V_96 ;
V_86 = V_86 -> V_96 ;
}
#endif
F_77 ( V_111 -> V_138 , V_86 ) ;
}
for ( V_167 = & V_18 -> V_36 ; * V_167 ; V_167 = & ( * V_167 ) -> V_24 . V_54 ) {
if ( * V_167 == V_22 ) {
F_89 ( V_18 , V_167 , V_111 ) ;
return 0 ;
}
}
return - V_92 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_17 * V_18 , * V_86 ;
for (; ; ) {
V_18 = V_2 -> V_66 ;
if ( ! V_18 )
return 0 ;
if ( V_2 -> V_172 && V_18 != V_2 -> V_60 &&
V_18 -> V_38 & V_41 && V_2 -> V_64 < V_166 ) {
V_2 -> V_64 = V_166 ;
V_2 -> V_36 = V_18 -> V_36 ;
}
switch ( V_2 -> V_64 ) {
#ifdef F_76
case V_173 :
if ( F_82 ( V_18 ) ) {
V_2 -> V_66 = F_82 ( V_18 ) ;
continue;
}
V_2 -> V_64 = V_163 ;
#endif
case V_163 :
if ( V_18 -> V_95 ) {
V_2 -> V_66 = V_18 -> V_95 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_164 ;
case V_164 :
if ( V_18 -> V_94 ) {
V_2 -> V_66 = V_18 -> V_94 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_166 ;
V_2 -> V_36 = V_18 -> V_36 ;
case V_166 :
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
V_2 -> V_64 = V_165 ;
case V_165 :
if ( V_18 == V_2 -> V_60 )
return 0 ;
V_86 = V_18 -> V_96 ;
V_2 -> V_66 = V_86 ;
#ifdef F_76
if ( F_82 ( V_86 ) == V_18 ) {
F_33 ( ! ( V_18 -> V_38 & V_39 ) ) ;
V_2 -> V_64 = V_163 ;
continue;
}
#endif
if ( V_86 -> V_95 == V_18 ) {
V_2 -> V_64 = V_164 ;
continue;
}
if ( V_86 -> V_94 == V_18 ) {
V_2 -> V_64 = V_166 ;
V_2 -> V_36 = V_2 -> V_66 -> V_36 ;
continue;
}
#if V_153 >= 2
F_33 ( 1 ) ;
#endif
}
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_53 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_2 -> V_60 ;
F_1 ( V_2 ) ;
V_53 = F_41 ( V_2 ) ;
if ( V_53 <= 0 )
F_5 ( V_2 ) ;
return V_53 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_21 * V_22 ;
struct V_174 * V_175 = F_93 ( V_2 , struct V_174 , V_2 ) ;
struct V_110 V_111 = {
. V_138 = V_175 -> V_6 ,
} ;
if ( V_175 -> V_83 != V_176 &&
V_2 -> V_66 -> V_63 != V_175 -> V_83 )
V_2 -> V_66 -> V_63 = V_175 -> V_83 ;
if ( ! V_175 -> V_74 ) {
F_94 ( V_175 -> V_83 == V_176 ) ;
V_2 -> V_36 = NULL ;
return 0 ;
}
for ( V_22 = V_2 -> V_36 ; V_22 ; V_22 = V_22 -> V_24 . V_54 ) {
V_53 = V_175 -> V_74 ( V_22 , V_175 -> V_72 ) ;
if ( V_53 < 0 ) {
V_2 -> V_36 = V_22 ;
V_53 = F_91 ( V_22 , & V_111 ) ;
if ( V_53 ) {
#if V_153 >= 2
F_95 ( L_13 ,
V_177 , V_22 , V_22 -> V_136 , V_53 ) ;
#endif
continue;
}
return 0 ;
}
F_33 ( V_53 != 0 ) ;
}
V_2 -> V_36 = V_22 ;
return 0 ;
}
static void F_96 ( struct V_6 * V_6 , struct V_17 * V_60 ,
int (* V_74)( struct V_21 * , void * V_72 ) ,
bool V_172 , int V_83 , void * V_72 )
{
struct V_174 V_175 ;
V_175 . V_2 . V_60 = V_60 ;
V_175 . V_2 . V_74 = F_92 ;
V_175 . V_2 . V_172 = V_172 ;
V_175 . V_2 . V_61 = 0 ;
V_175 . V_2 . V_62 = 0 ;
V_175 . V_74 = V_74 ;
V_175 . V_83 = V_83 ;
V_175 . V_72 = V_72 ;
V_175 . V_6 = V_6 ;
F_39 ( & V_175 . V_2 ) ;
}
static void F_97 ( struct V_6 * V_6 ,
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
F_96 ( V_6 , & V_34 -> V_35 ,
V_74 , false , V_83 , V_72 ) ;
F_4 ( & V_34 -> V_28 ) ;
}
}
F_28 () ;
}
void F_98 ( struct V_6 * V_6 , int (* V_74)( struct V_21 * , void * ) ,
void * V_72 )
{
F_97 ( V_6 , V_74 , V_176 , V_72 ) ;
}
static int F_99 ( struct V_21 * V_22 , void * V_72 )
{
if ( V_22 -> V_97 & V_143 ) {
F_45 ( L_14 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static void F_77 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
F_96 ( V_6 , V_18 , F_99 , true ,
V_176 , NULL ) ;
}
static void F_100 ( struct V_6 * V_6 )
{
int V_178 = F_7 ( V_6 ) ;
F_97 ( V_6 , NULL , V_178 , NULL ) ;
}
static int F_101 ( struct V_21 * V_22 , void * V_72 )
{
unsigned long V_179 = V_144 ;
if ( V_22 -> V_97 & V_130 && V_22 -> V_24 . V_131 ) {
if ( F_102 ( V_179 , V_22 -> V_24 . V_131 ) ) {
F_45 ( L_15 , V_22 ) ;
return - 1 ;
}
V_180 . V_181 ++ ;
} else if ( V_22 -> V_97 & V_143 ) {
if ( F_8 ( & V_22 -> V_24 . V_182 ) == 0 &&
F_103 ( V_179 , V_22 -> V_24 . V_183 + V_180 . V_184 ) ) {
F_45 ( L_16 , V_22 ) ;
return - 1 ;
} else if ( V_22 -> V_97 & V_98 ) {
struct V_185 * V_186 ;
T_5 V_187 = 0 ;
V_186 = F_104 ( & V_22 -> V_24 , & V_22 -> V_128 ) ;
if ( V_186 ) {
V_187 = V_186 -> V_51 ;
F_105 ( V_186 ) ;
}
if ( ! ( V_187 & V_188 ) ) {
F_45 ( L_17 ,
V_22 ) ;
return - 1 ;
}
}
V_180 . V_181 ++ ;
}
return 0 ;
}
void F_106 ( unsigned long V_131 , struct V_6 * V_6 , bool V_189 )
{
unsigned long V_179 ;
if ( V_189 ) {
F_107 ( & V_190 ) ;
} else if ( ! F_108 ( & V_190 ) ) {
F_70 ( & V_6 -> V_9 . V_142 , V_144 + V_191 ) ;
return;
}
V_180 . V_184 = V_131 ? ( int ) V_131 :
V_6 -> V_9 . V_145 . V_146 ;
V_180 . V_181 = F_109 () ;
F_98 ( V_6 , F_101 , NULL ) ;
V_179 = V_144 ;
V_6 -> V_9 . V_192 = V_179 ;
if ( V_180 . V_181 )
F_70 ( & V_6 -> V_9 . V_142 ,
F_110 ( V_179
+ V_6 -> V_9 . V_145 . V_146 ) ) ;
else
F_111 ( & V_6 -> V_9 . V_142 ) ;
F_112 ( & V_190 ) ;
}
static void F_113 ( unsigned long V_72 )
{
F_106 ( 0 , (struct V_6 * ) V_72 , true ) ;
}
static int T_3 F_114 ( struct V_6 * V_6 )
{
T_6 V_193 = sizeof( struct V_44 ) * V_30 ;
F_115 ( & V_6 -> V_9 . V_142 , F_113 , ( unsigned long ) V_6 ) ;
V_6 -> V_9 . V_139 = F_22 ( sizeof( * V_6 -> V_9 . V_139 ) , V_194 ) ;
if ( ! V_6 -> V_9 . V_139 )
goto V_195;
V_193 = F_116 ( T_6 , V_193 , V_196 ) ;
V_6 -> V_9 . V_32 = F_22 ( V_193 , V_194 ) ;
if ( ! V_6 -> V_9 . V_32 )
goto V_197;
V_6 -> V_9 . V_46 = F_22 ( sizeof( * V_6 -> V_9 . V_46 ) ,
V_194 ) ;
if ( ! V_6 -> V_9 . V_46 )
goto V_198;
V_6 -> V_9 . V_46 -> V_29 = V_43 ;
V_6 -> V_9 . V_46 -> V_35 . V_36 = V_6 -> V_9 . V_37 ;
V_6 -> V_9 . V_46 -> V_35 . V_38 =
V_39 | V_40 | V_41 ;
F_23 ( & V_6 -> V_9 . V_46 -> V_42 ) ;
#ifdef F_117
V_6 -> V_9 . V_47 = F_22 ( sizeof( * V_6 -> V_9 . V_47 ) ,
V_194 ) ;
if ( ! V_6 -> V_9 . V_47 )
goto V_199;
V_6 -> V_9 . V_47 -> V_29 = V_200 ;
V_6 -> V_9 . V_47 -> V_35 . V_36 = V_6 -> V_9 . V_37 ;
V_6 -> V_9 . V_47 -> V_35 . V_38 =
V_39 | V_40 | V_41 ;
F_23 ( & V_6 -> V_9 . V_47 -> V_42 ) ;
#endif
F_29 ( V_6 ) ;
return 0 ;
#ifdef F_117
V_199:
F_35 ( V_6 -> V_9 . V_46 ) ;
#endif
V_198:
F_35 ( V_6 -> V_9 . V_32 ) ;
V_197:
F_35 ( V_6 -> V_9 . V_139 ) ;
V_195:
return - V_73 ;
}
static void F_118 ( struct V_6 * V_6 )
{
F_119 ( V_6 , NULL ) ;
F_120 ( & V_6 -> V_9 . V_142 ) ;
#ifdef F_117
F_121 ( & V_6 -> V_9 . V_47 -> V_42 ) ;
F_35 ( V_6 -> V_9 . V_47 ) ;
#endif
F_121 ( & V_6 -> V_9 . V_46 -> V_42 ) ;
F_35 ( V_6 -> V_9 . V_46 ) ;
F_35 ( V_6 -> V_9 . V_32 ) ;
F_35 ( V_6 -> V_9 . V_139 ) ;
}
int T_7 F_122 ( void )
{
int V_201 = - V_73 ;
V_19 = F_123 ( L_18 ,
sizeof( struct V_17 ) ,
0 , V_202 ,
NULL ) ;
if ( ! V_19 )
goto V_76;
V_201 = F_124 ( & V_203 ) ;
if ( V_201 )
goto V_204;
V_201 = F_125 ( V_205 , V_206 , NULL , F_42 ,
NULL ) ;
if ( V_201 )
goto V_207;
V_208 = F_100 ;
V_76:
return V_201 ;
V_207:
F_126 ( & V_203 ) ;
V_204:
F_127 ( V_19 ) ;
goto V_76;
}
void F_128 ( void )
{
F_126 ( & V_203 ) ;
F_127 ( V_19 ) ;
}
static int F_129 ( struct V_209 * V_210 , void * V_211 )
{
struct V_21 * V_22 = V_211 ;
struct V_212 * V_112 = V_210 -> V_213 ;
F_130 ( V_210 , L_19 , & V_22 -> V_147 . V_14 , V_22 -> V_147 . V_79 ) ;
#ifdef F_76
F_130 ( V_210 , L_19 , & V_22 -> V_148 . V_14 , V_22 -> V_148 . V_79 ) ;
#else
F_131 ( V_210 , L_20 ) ;
#endif
if ( V_22 -> V_97 & V_98 )
F_130 ( V_210 , L_21 , & V_22 -> V_128 ) ;
else
F_131 ( V_210 , L_22 ) ;
F_130 ( V_210 , L_23 ,
V_22 -> V_123 , F_8 ( & V_22 -> V_24 . V_182 ) ,
V_22 -> V_24 . V_214 , V_22 -> V_97 ,
V_22 -> V_24 . V_126 ? V_22 -> V_24 . V_126 -> V_215 : L_24 ) ;
V_112 -> V_2 . V_36 = NULL ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_212 * V_112 = V_2 -> args ;
if ( ! V_112 -> V_62 )
return 1 ;
do {
V_112 -> V_2 . V_36 = V_112 -> V_2 . V_36 -> V_24 . V_54 ;
V_112 -> V_62 -- ;
if ( ! V_112 -> V_62 && V_112 -> V_2 . V_36 )
return 1 ;
} while ( V_112 -> V_2 . V_36 );
return 0 ;
}
static void F_133 ( struct V_212 * V_112 )
{
memset ( & V_112 -> V_2 , 0 , sizeof( V_112 -> V_2 ) ) ;
V_112 -> V_2 . V_74 = F_132 ;
V_112 -> V_2 . V_60 = & V_112 -> V_216 -> V_35 ;
V_112 -> V_2 . V_64 = V_65 ;
V_112 -> V_2 . V_66 = V_112 -> V_2 . V_60 ;
V_112 -> V_2 . args = V_112 ;
V_112 -> V_83 = V_112 -> V_2 . V_60 -> V_63 ;
F_134 ( & V_112 -> V_2 . V_4 ) ;
F_1 ( & V_112 -> V_2 ) ;
}
static struct V_25 * F_135 ( struct V_25 * V_216 ,
struct V_6 * V_6 )
{
unsigned int V_27 ;
struct V_217 * V_66 ;
if ( V_216 ) {
V_27 = ( V_216 -> V_29 & ( V_30 - 1 ) ) + 1 ;
V_66 = F_136 ( F_137 ( & V_216 -> V_31 ) ) ;
} else {
V_27 = 0 ;
V_66 = NULL ;
}
while ( ! V_66 && V_27 < V_30 ) {
V_66 = F_136 (
F_138 ( & V_6 -> V_9 . V_32 [ V_27 ++ ] ) ) ;
}
return F_139 ( V_66 , struct V_25 , V_31 ) ;
}
static void F_140 ( struct V_212 * V_112 )
{
if ( V_112 -> V_83 != V_112 -> V_2 . V_60 -> V_63 ) {
V_112 -> V_83 = V_112 -> V_2 . V_60 -> V_63 ;
V_112 -> V_2 . V_64 = V_65 ;
V_112 -> V_2 . V_66 = V_112 -> V_2 . V_60 ;
F_33 ( V_112 -> V_2 . V_62 ) ;
V_112 -> V_2 . V_62 = V_112 -> V_2 . V_61 ;
}
}
static void * F_141 ( struct V_209 * V_210 , void * V_211 , T_8 * V_218 )
{
int V_219 ;
struct V_21 * V_220 ;
struct V_6 * V_6 = F_142 ( V_210 ) ;
struct V_212 * V_112 = V_210 -> V_213 ;
if ( ! V_211 )
goto V_221;
V_220 = ( (struct V_21 * ) V_211 ) -> V_24 . V_54 ;
if ( V_220 ) {
++ * V_218 ;
return V_220 ;
}
V_221:
F_140 ( V_112 ) ;
F_86 ( & V_112 -> V_216 -> V_28 ) ;
V_219 = F_41 ( & V_112 -> V_2 ) ;
F_88 ( & V_112 -> V_216 -> V_28 ) ;
if ( V_219 > 0 ) {
if ( V_211 )
++ * V_218 ;
return V_112 -> V_2 . V_36 ;
} else if ( V_219 < 0 ) {
F_5 ( & V_112 -> V_2 ) ;
return NULL ;
}
F_5 ( & V_112 -> V_2 ) ;
V_112 -> V_216 = F_135 ( V_112 -> V_216 , V_6 ) ;
if ( ! V_112 -> V_216 )
return NULL ;
F_133 ( V_112 ) ;
goto V_221;
}
static void * F_143 ( struct V_209 * V_210 , T_8 * V_218 )
__acquires( T_9 )
{
struct V_6 * V_6 = F_142 ( V_210 ) ;
struct V_212 * V_112 = V_210 -> V_213 ;
F_144 () ;
V_112 -> V_216 = F_135 ( NULL , V_6 ) ;
V_112 -> V_62 = * V_218 ;
if ( V_112 -> V_216 ) {
F_133 ( V_112 ) ;
return F_141 ( V_210 , NULL , V_218 ) ;
} else {
return NULL ;
}
}
static bool F_145 ( struct V_212 * V_112 )
{
struct V_1 * V_2 = & V_112 -> V_2 ;
return V_2 -> V_66 && ! ( V_2 -> V_64 == V_165 && V_2 -> V_66 == V_2 -> V_60 ) ;
}
static void F_146 ( struct V_209 * V_210 , void * V_211 )
__releases( T_9 )
{
struct V_212 * V_112 = V_210 -> V_213 ;
if ( F_145 ( V_112 ) )
F_5 ( & V_112 -> V_2 ) ;
F_147 () ;
}
int F_148 ( struct V_222 * V_222 , struct V_223 * V_223 )
{
return F_149 ( V_222 , V_223 , & V_224 ,
sizeof( struct V_212 ) ) ;
}
