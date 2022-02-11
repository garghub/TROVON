static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static T_1 T_2 F_7 ( void )
{
T_2 V_6 = ++ V_7 ;
if ( ( V_8 ) V_6 <= 0 )
V_7 = V_6 = 1 ;
return V_6 ;
}
static T_1 T_3 F_8 ( const void * V_9 , int V_10 )
{
const T_3 * V_11 = V_9 ;
return ( V_12 T_3 ) ( 1 << ( ( ~ V_10 ^ V_13 ) & 0x1f ) ) &
V_11 [ V_10 >> 5 ] ;
}
static T_1 void F_9 ( struct V_14 * V_15 )
{
F_10 ( V_16 , V_15 ) ;
}
static T_1 void F_11 ( struct V_17 * V_18 )
{
if ( F_12 ( & V_18 -> V_19 ) )
F_13 ( & V_18 -> V_20 ) ;
}
static void F_14 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
unsigned int V_24 ;
F_15 ( & V_23 -> V_25 ) ;
V_24 = V_23 -> V_26 & ( V_27 - 1 ) ;
F_16 ( & V_23 -> V_28 , & V_21 -> V_29 . V_30 [ V_24 ] ) ;
}
static struct V_22 * F_17 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_22 * V_32 ;
V_32 = F_18 ( sizeof( * V_32 ) , V_33 ) ;
if ( V_32 ) {
V_32 -> V_26 = V_31 ;
V_32 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_32 -> V_34 . V_37 = V_38 | V_39 | V_40 ;
F_19 ( & V_32 -> V_41 ) ;
}
return V_32 ;
}
struct V_22 * F_20 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_22 * V_23 ;
if ( V_31 == 0 )
V_31 = V_42 ;
V_23 = F_21 ( V_21 , V_31 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_17 ( V_21 , V_31 ) ;
if ( V_23 )
F_14 ( V_21 , V_23 ) ;
return V_23 ;
}
struct V_22 * F_21 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_22 * V_23 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
if ( V_31 == 0 )
V_31 = V_42 ;
V_24 = V_31 & ( V_27 - 1 ) ;
F_22 () ;
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (tb, head, tb6_hlist) {
if ( V_23 -> V_26 == V_31 ) {
F_24 () ;
return V_23 ;
}
}
F_24 () ;
return NULL ;
}
static void T_4 F_25 ( struct V_21 * V_21 )
{
F_14 ( V_21 , V_21 -> V_29 . V_45 ) ;
F_14 ( V_21 , V_21 -> V_29 . V_46 ) ;
}
struct V_22 * F_20 ( struct V_21 * V_21 , T_2 V_31 )
{
return F_21 ( V_21 , V_31 ) ;
}
struct V_22 * F_21 ( struct V_21 * V_21 , T_2 V_31 )
{
return V_21 -> V_29 . V_45 ;
}
struct V_47 * F_26 ( struct V_21 * V_21 , struct V_48 * V_49 ,
int V_50 , T_5 V_51 )
{
return (struct V_47 * ) V_51 ( V_21 , V_21 -> V_29 . V_45 , V_49 , V_50 ) ;
}
static void T_4 F_25 ( struct V_21 * V_21 )
{
F_14 ( V_21 , V_21 -> V_29 . V_45 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_17 * V_18 ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_53 ) {
V_52 = F_28 ( V_18 , V_2 -> args ) ;
if ( V_52 < 0 ) {
V_2 -> V_35 = V_18 ;
return 1 ;
}
F_29 ( V_52 == 0 ) ;
}
V_2 -> V_35 = NULL ;
return 0 ;
}
static void F_30 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = ( void * ) V_55 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_55 -> args [ 4 ] ) {
V_55 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_55 -> args [ 2 ] = 0 ;
F_31 ( V_2 ) ;
}
V_55 -> V_56 = ( void * ) V_55 -> args [ 3 ] ;
V_55 -> args [ 1 ] = 3 ;
}
static int F_32 ( struct V_54 * V_55 )
{
F_30 ( V_55 ) ;
return V_55 -> V_56 ? V_55 -> V_56 ( V_55 ) : 0 ;
}
static int F_33 ( struct V_22 * V_32 , struct V_57 * V_58 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 ;
int V_52 ;
V_2 = ( void * ) V_55 -> args [ 2 ] ;
V_2 -> V_59 = & V_32 -> V_34 ;
if ( V_55 -> args [ 4 ] == 0 ) {
V_2 -> V_60 = 0 ;
V_2 -> V_61 = 0 ;
F_34 ( & V_32 -> V_25 ) ;
V_52 = F_35 ( V_2 ) ;
F_36 ( & V_32 -> V_25 ) ;
if ( V_52 > 0 ) {
V_55 -> args [ 4 ] = 1 ;
V_55 -> args [ 5 ] = V_2 -> V_59 -> V_62 ;
}
} else {
if ( V_55 -> args [ 5 ] != V_2 -> V_59 -> V_62 ) {
V_55 -> args [ 5 ] = V_2 -> V_59 -> V_62 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_2 -> V_59 ;
V_2 -> V_61 = V_2 -> V_60 ;
} else
V_2 -> V_61 = 0 ;
F_34 ( & V_32 -> V_25 ) ;
V_52 = F_37 ( V_2 ) ;
F_36 ( & V_32 -> V_25 ) ;
if ( V_52 <= 0 ) {
F_5 ( V_2 ) ;
V_55 -> args [ 4 ] = 0 ;
}
}
return V_52 ;
}
static int F_38 ( struct V_57 * V_58 , struct V_54 * V_55 )
{
struct V_21 * V_21 = F_39 ( V_58 -> V_66 ) ;
unsigned int V_24 , V_67 ;
unsigned int V_68 = 0 , V_69 ;
struct V_70 V_71 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_43 * V_44 ;
int V_52 = 0 ;
V_67 = V_55 -> args [ 0 ] ;
V_69 = V_55 -> args [ 1 ] ;
V_2 = ( void * ) V_55 -> args [ 2 ] ;
if ( ! V_2 ) {
V_55 -> args [ 3 ] = ( long ) V_55 -> V_56 ;
V_55 -> V_56 = F_32 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_73 = F_27 ;
V_55 -> args [ 2 ] = ( long ) V_2 ;
}
V_71 . V_58 = V_58 ;
V_71 . V_55 = V_55 ;
V_71 . V_21 = V_21 ;
V_2 -> args = & V_71 ;
F_22 () ;
for ( V_24 = V_67 ; V_24 < V_27 ; V_24 ++ , V_69 = 0 ) {
V_68 = 0 ;
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (tb, head, tb6_hlist) {
if ( V_68 < V_69 )
goto V_74;
V_52 = F_33 ( V_23 , V_58 , V_55 ) ;
if ( V_52 != 0 )
goto V_75;
V_74:
V_68 ++ ;
}
}
V_75:
F_24 () ;
V_55 -> args [ 1 ] = V_68 ;
V_55 -> args [ 0 ] = V_24 ;
V_52 = V_52 < 0 ? V_52 : V_58 -> V_76 ;
if ( V_52 <= 0 )
F_30 ( V_55 ) ;
return V_52 ;
}
static struct V_14 * F_40 ( struct V_14 * V_59 ,
struct V_77 * V_11 , int V_78 ,
int V_79 , int V_80 ,
int V_81 )
{
struct V_14 * V_15 , * V_82 , * V_83 ;
struct V_14 * V_84 = NULL ;
struct V_85 * V_86 ;
int V_87 ;
T_3 V_88 = 0 ;
T_6 V_89 = F_7 () ;
F_41 ( L_1 ) ;
V_15 = V_59 ;
do {
V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_42 ( & V_86 -> V_11 , V_11 , V_15 -> V_10 ) ) {
if ( ! V_80 ) {
if ( V_81 ) {
F_43 ( L_2 ) ;
return F_44 ( - V_91 ) ;
}
F_43 ( L_3 ) ;
}
goto V_92;
}
if ( V_78 == V_15 -> V_10 ) {
if ( ! ( V_15 -> V_37 & V_40 ) ) {
F_11 ( V_15 -> V_35 ) ;
V_15 -> V_35 = NULL ;
}
V_15 -> V_62 = V_89 ;
return V_15 ;
}
V_15 -> V_62 = V_89 ;
V_88 = F_8 ( V_11 , V_15 -> V_10 ) ;
V_84 = V_15 ;
V_15 = V_88 ? V_15 -> V_93 : V_15 -> V_94 ;
} while ( V_15 );
if ( ! V_80 ) {
if ( V_81 ) {
F_43 ( L_2 ) ;
return F_44 ( - V_91 ) ;
}
F_43 ( L_3 ) ;
}
V_83 = F_45 () ;
if ( ! V_83 )
return F_44 ( - V_72 ) ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_84 ;
V_83 -> V_62 = V_89 ;
if ( V_88 )
V_84 -> V_93 = V_83 ;
else
V_84 -> V_94 = V_83 ;
return V_83 ;
V_92:
V_84 = V_15 -> V_95 ;
V_87 = F_46 ( V_11 , & V_86 -> V_11 , sizeof( * V_11 ) ) ;
if ( V_78 > V_87 ) {
V_82 = F_45 () ;
V_83 = F_45 () ;
if ( ! V_82 || ! V_83 ) {
if ( V_82 )
F_9 ( V_82 ) ;
if ( V_83 )
F_9 ( V_83 ) ;
return F_44 ( - V_72 ) ;
}
V_82 -> V_10 = V_87 ;
V_82 -> V_95 = V_84 ;
V_82 -> V_35 = V_15 -> V_35 ;
F_47 ( & V_82 -> V_35 -> V_19 ) ;
V_82 -> V_62 = V_89 ;
if ( V_88 )
V_84 -> V_93 = V_82 ;
else
V_84 -> V_94 = V_82 ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_82 ;
V_15 -> V_95 = V_82 ;
V_83 -> V_62 = V_89 ;
if ( F_8 ( V_11 , V_87 ) ) {
V_82 -> V_93 = V_83 ;
V_82 -> V_94 = V_15 ;
} else {
V_82 -> V_94 = V_83 ;
V_82 -> V_93 = V_15 ;
}
} else {
V_83 = F_45 () ;
if ( ! V_83 )
return F_44 ( - V_72 ) ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_84 ;
V_83 -> V_62 = V_89 ;
if ( V_88 )
V_84 -> V_93 = V_83 ;
else
V_84 -> V_94 = V_83 ;
if ( F_8 ( & V_86 -> V_11 , V_78 ) )
V_83 -> V_93 = V_15 ;
else
V_83 -> V_94 = V_15 ;
V_15 -> V_95 = V_83 ;
}
return V_83 ;
}
static inline bool F_48 ( struct V_17 * V_18 )
{
return ( V_18 -> V_96 & ( V_97 | V_98 | V_99 ) ) ==
V_97 ;
}
static int F_49 ( struct V_47 * V_20 ,
struct V_100 * V_101 , int V_102 )
{
struct V_100 * V_103 ;
int V_104 ;
T_2 * V_105 ;
if ( V_20 -> V_50 & V_106 ) {
V_105 = F_50 ( V_20 ) ;
} else {
V_105 = F_18 ( sizeof( T_2 ) * V_107 , V_33 ) ;
if ( ! V_105 )
return - V_72 ;
F_51 ( V_20 , V_105 , 0 ) ;
}
F_52 (nla, mx, mx_len, remaining) {
int type = F_53 ( V_103 ) ;
if ( type ) {
if ( type > V_107 )
return - V_108 ;
V_105 [ type - 1 ] = F_54 ( V_103 ) ;
}
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 , struct V_17 * V_18 ,
struct V_109 * V_110 , struct V_100 * V_101 , int V_102 )
{
struct V_17 * V_111 = NULL ;
struct V_17 * * V_112 ;
int V_113 = ( V_110 -> V_114 &&
( V_110 -> V_114 -> V_115 & V_116 ) ) ;
int V_117 = ( ! V_110 -> V_114 ||
( V_110 -> V_114 -> V_115 & V_118 ) ) ;
int V_119 = 0 ;
bool V_120 = F_48 ( V_18 ) ;
int V_121 ;
V_112 = & V_15 -> V_35 ;
for ( V_111 = V_15 -> V_35 ; V_111 ; V_111 = V_111 -> V_20 . V_53 ) {
if ( V_111 -> V_122 == V_18 -> V_122 ) {
if ( V_110 -> V_114 &&
( V_110 -> V_114 -> V_115 & V_123 ) )
return - V_124 ;
if ( V_113 ) {
V_119 ++ ;
break;
}
if ( V_111 -> V_20 . V_125 == V_18 -> V_20 . V_125 &&
V_111 -> V_126 == V_18 -> V_126 &&
F_56 ( & V_111 -> V_127 ,
& V_18 -> V_127 ) ) {
if ( V_18 -> V_128 )
V_18 -> V_128 = 0 ;
if ( ! ( V_111 -> V_96 & V_129 ) )
return - V_124 ;
if ( ! ( V_18 -> V_96 & V_129 ) )
F_57 ( V_111 ) ;
else
F_58 ( V_111 , V_18 -> V_20 . V_130 ) ;
return - V_124 ;
}
if ( V_120 &&
F_48 ( V_111 ) )
V_18 -> V_128 ++ ;
}
if ( V_111 -> V_122 > V_18 -> V_122 )
break;
V_112 = & V_111 -> V_20 . V_53 ;
}
if ( V_112 == & V_15 -> V_35 )
V_15 -> V_131 = NULL ;
if ( V_18 -> V_128 ) {
unsigned int V_128 ;
struct V_17 * V_132 , * V_133 ;
V_132 = V_15 -> V_35 ;
while ( V_132 ) {
if ( V_132 -> V_122 == V_18 -> V_122 &&
F_48 ( V_132 ) ) {
F_59 ( & V_18 -> V_134 ,
& V_132 -> V_134 ) ;
break;
}
V_132 = V_132 -> V_20 . V_53 ;
}
V_128 = 0 ;
F_60 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_132 -> V_128 ++ ;
F_61 ( V_132 -> V_128 != V_18 -> V_128 ) ;
V_128 ++ ;
}
F_61 ( V_128 != V_18 -> V_128 ) ;
}
if ( ! V_113 ) {
if ( ! V_117 )
F_43 ( L_3 ) ;
V_117:
if ( V_101 ) {
V_121 = F_49 ( & V_18 -> V_20 , V_101 , V_102 ) ;
if ( V_121 )
return V_121 ;
}
V_18 -> V_20 . V_53 = V_111 ;
* V_112 = V_18 ;
V_18 -> V_135 = V_15 ;
F_47 ( & V_18 -> V_19 ) ;
F_62 ( V_136 , V_18 , V_110 ) ;
V_110 -> V_137 -> V_29 . V_138 -> V_139 ++ ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_110 -> V_137 -> V_29 . V_138 -> V_140 ++ ;
V_15 -> V_37 |= V_40 ;
}
} else {
if ( ! V_119 ) {
if ( V_117 )
goto V_117;
F_43 ( L_4 ) ;
return - V_91 ;
}
if ( V_101 ) {
V_121 = F_49 ( & V_18 -> V_20 , V_101 , V_102 ) ;
if ( V_121 )
return V_121 ;
}
* V_112 = V_18 ;
V_18 -> V_135 = V_15 ;
V_18 -> V_20 . V_53 = V_111 -> V_20 . V_53 ;
F_47 ( & V_18 -> V_19 ) ;
F_62 ( V_136 , V_18 , V_110 ) ;
F_11 ( V_111 ) ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_110 -> V_137 -> V_29 . V_138 -> V_140 ++ ;
V_15 -> V_37 |= V_40 ;
}
}
return 0 ;
}
static T_1 void F_63 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_64 ( & V_21 -> V_29 . V_141 ) &&
( V_18 -> V_96 & ( V_129 | V_142 ) ) )
F_65 ( & V_21 -> V_29 . V_141 ,
V_143 + V_21 -> V_29 . V_144 . V_145 ) ;
}
void F_66 ( struct V_21 * V_21 )
{
if ( ! F_64 ( & V_21 -> V_29 . V_141 ) )
F_65 ( & V_21 -> V_29 . V_141 ,
V_143 + V_21 -> V_29 . V_144 . V_145 ) ;
}
int F_67 ( struct V_14 * V_59 , struct V_17 * V_18 , struct V_109 * V_110 ,
struct V_100 * V_101 , int V_102 )
{
struct V_14 * V_15 , * V_84 = NULL ;
int V_121 = - V_72 ;
int V_80 = 1 ;
int V_81 = 0 ;
if ( V_110 -> V_114 ) {
if ( ! ( V_110 -> V_114 -> V_115 & V_118 ) )
V_80 = 0 ;
if ( V_110 -> V_114 -> V_115 & V_116 )
V_81 = 1 ;
}
if ( ! V_80 && ! V_81 )
F_43 ( L_5 ) ;
V_15 = F_40 ( V_59 , & V_18 -> V_146 . V_11 , V_18 -> V_146 . V_78 ,
F_68 ( struct V_17 , V_146 ) , V_80 ,
V_81 ) ;
if ( F_69 ( V_15 ) ) {
V_121 = F_70 ( V_15 ) ;
V_15 = NULL ;
goto V_75;
}
V_84 = V_15 ;
#ifdef F_71
if ( V_18 -> V_147 . V_78 ) {
struct V_14 * V_148 ;
if ( ! V_15 -> V_149 ) {
struct V_14 * V_150 ;
V_150 = F_45 () ;
if ( ! V_150 )
goto V_151;
V_150 -> V_35 = V_110 -> V_137 -> V_29 . V_36 ;
F_47 ( & V_110 -> V_137 -> V_29 . V_36 -> V_19 ) ;
V_150 -> V_37 = V_38 ;
V_150 -> V_62 = F_7 () ;
V_148 = F_40 ( V_150 , & V_18 -> V_147 . V_11 ,
V_18 -> V_147 . V_78 ,
F_68 ( struct V_17 , V_147 ) ,
V_80 , V_81 ) ;
if ( F_69 ( V_148 ) ) {
F_9 ( V_150 ) ;
V_121 = F_70 ( V_148 ) ;
goto V_151;
}
V_150 -> V_95 = V_15 ;
V_15 -> V_149 = V_150 ;
} else {
V_148 = F_40 ( V_15 -> V_149 , & V_18 -> V_147 . V_11 ,
V_18 -> V_147 . V_78 ,
F_68 ( struct V_17 , V_147 ) ,
V_80 , V_81 ) ;
if ( F_69 ( V_148 ) ) {
V_121 = F_70 ( V_148 ) ;
goto V_151;
}
}
if ( ! V_15 -> V_35 ) {
V_15 -> V_35 = V_18 ;
F_47 ( & V_18 -> V_19 ) ;
}
V_15 = V_148 ;
}
#endif
V_121 = F_55 ( V_15 , V_18 , V_110 , V_101 , V_102 ) ;
if ( ! V_121 ) {
F_63 ( V_110 -> V_137 , V_18 ) ;
if ( ! ( V_18 -> V_96 & V_142 ) )
F_72 ( V_110 -> V_137 , V_84 ) ;
}
V_75:
if ( V_121 ) {
#ifdef F_71
if ( V_84 != V_15 && V_84 -> V_35 == V_18 ) {
V_84 -> V_35 = NULL ;
F_73 ( & V_18 -> V_19 ) ;
}
if ( V_84 != V_15 && ! V_84 -> V_35 && ! ( V_84 -> V_37 & V_40 ) ) {
V_84 -> V_35 = F_74 ( V_110 -> V_137 , V_84 ) ;
#if V_152 >= 2
if ( ! V_84 -> V_35 ) {
F_29 ( V_84 -> V_35 == NULL ) ;
V_84 -> V_35 = V_110 -> V_137 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_84 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_121 ;
#ifdef F_71
V_151:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_75 ( V_110 -> V_137 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_121 ;
#endif
}
static struct V_14 * F_76 ( struct V_14 * V_59 ,
struct V_153 * args )
{
struct V_14 * V_15 ;
T_3 V_88 ;
if ( F_77 ( args -> V_79 == 0 ) )
return NULL ;
V_15 = V_59 ;
for (; ; ) {
struct V_14 * V_74 ;
V_88 = F_8 ( args -> V_11 , V_15 -> V_10 ) ;
V_74 = V_88 ? V_15 -> V_93 : V_15 -> V_94 ;
if ( V_74 ) {
V_15 = V_74 ;
continue;
}
break;
}
while ( V_15 ) {
if ( F_78 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 +
args -> V_79 ) ;
if ( F_42 ( & V_86 -> V_11 , args -> V_11 , V_86 -> V_78 ) ) {
#ifdef F_71
if ( V_15 -> V_149 ) {
struct V_14 * V_150 ;
V_150 = F_76 ( V_15 -> V_149 ,
args + 1 ) ;
if ( ! V_150 )
goto V_154;
V_15 = V_150 ;
}
#endif
if ( V_15 -> V_37 & V_40 )
return V_15 ;
}
}
#ifdef F_71
V_154:
#endif
if ( V_15 -> V_37 & V_38 )
break;
V_15 = V_15 -> V_95 ;
}
return NULL ;
}
struct V_14 * F_79 ( struct V_14 * V_59 , const struct V_77 * V_155 ,
const struct V_77 * V_156 )
{
struct V_14 * V_15 ;
struct V_153 args [] = {
{
. V_79 = F_68 ( struct V_17 , V_146 ) ,
. V_11 = V_155 ,
} ,
#ifdef F_71
{
. V_79 = F_68 ( struct V_17 , V_147 ) ,
. V_11 = V_156 ,
} ,
#endif
{
. V_79 = 0 ,
}
} ;
V_15 = F_76 ( V_59 , V_155 ? args : args + 1 ) ;
if ( ! V_15 || V_15 -> V_37 & V_39 )
V_15 = V_59 ;
return V_15 ;
}
static struct V_14 * F_80 ( struct V_14 * V_59 ,
const struct V_77 * V_11 ,
int V_78 , int V_79 )
{
struct V_14 * V_15 ;
for ( V_15 = V_59 ; V_15 ; ) {
struct V_85 * V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_42 ( & V_86 -> V_11 , V_11 , V_15 -> V_10 ) )
return NULL ;
if ( V_78 == V_15 -> V_10 )
return V_15 ;
if ( F_8 ( V_11 , V_15 -> V_10 ) )
V_15 = V_15 -> V_93 ;
else
V_15 = V_15 -> V_94 ;
}
return NULL ;
}
struct V_14 * F_81 ( struct V_14 * V_59 ,
const struct V_77 * V_155 , int V_157 ,
const struct V_77 * V_156 , int V_158 )
{
struct V_14 * V_15 ;
V_15 = F_80 ( V_59 , V_155 , V_157 ,
F_68 ( struct V_17 , V_146 ) ) ;
#ifdef F_71
if ( V_158 ) {
F_29 ( V_156 == NULL ) ;
if ( V_15 && V_15 -> V_149 )
V_15 = F_80 ( V_15 -> V_149 , V_156 , V_158 ,
F_68 ( struct V_17 , V_147 ) ) ;
}
#endif
if ( V_15 && V_15 -> V_37 & V_40 )
return V_15 ;
return NULL ;
}
static struct V_17 * F_74 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
if ( V_15 -> V_37 & V_38 )
return V_21 -> V_29 . V_36 ;
while ( V_15 ) {
if ( V_15 -> V_94 )
return V_15 -> V_94 -> V_35 ;
if ( V_15 -> V_93 )
return V_15 -> V_93 -> V_35 ;
V_15 = F_78 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_75 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_159 ;
int V_160 ;
struct V_14 * V_161 , * V_84 ;
struct V_1 * V_2 ;
int V_111 = 0 ;
for (; ; ) {
F_41 ( L_6 , V_15 -> V_10 , V_111 ) ;
V_111 ++ ;
F_29 ( V_15 -> V_37 & V_40 ) ;
F_29 ( V_15 -> V_37 & V_39 ) ;
F_29 ( V_15 -> V_35 != NULL ) ;
V_159 = 0 ;
V_161 = NULL ;
if ( V_15 -> V_93 )
V_161 = V_15 -> V_93 , V_159 |= 1 ;
if ( V_15 -> V_94 )
V_161 = V_15 -> V_94 , V_159 |= 2 ;
if ( V_159 == 3 || F_78 ( V_15 )
#ifdef F_71
|| ( V_159 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_74 ( V_21 , V_15 ) ;
#if V_152 >= 2
if ( ! V_15 -> V_35 ) {
F_29 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_95 ;
}
V_84 = V_15 -> V_95 ;
#ifdef F_71
if ( F_78 ( V_84 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_78 ( V_84 ) = NULL ;
V_160 = V_162 ;
} else {
F_29 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_84 -> V_93 == V_15 )
V_84 -> V_93 = V_161 ;
else if ( V_84 -> V_94 == V_15 )
V_84 -> V_94 = V_161 ;
#if V_152 >= 2
else
F_29 ( 1 ) ;
#endif
if ( V_161 )
V_161 -> V_95 = V_84 ;
V_160 = V_163 ;
#ifdef F_71
}
#endif
F_82 ( & V_3 ) ;
F_83 (w) {
if ( ! V_161 ) {
if ( V_2 -> V_59 == V_15 ) {
V_2 -> V_59 = V_2 -> V_65 = NULL ;
F_41 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_65 == V_15 ) {
F_41 ( L_8 , V_2 , V_2 -> V_63 , V_160 ) ;
V_2 -> V_65 = V_84 ;
V_2 -> V_63 = V_160 ;
}
} else {
if ( V_2 -> V_59 == V_15 ) {
V_2 -> V_59 = V_161 ;
F_41 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_65 == V_15 ) {
V_2 -> V_65 = V_161 ;
if ( V_159 & 2 ) {
F_41 ( L_10 , V_2 , V_2 -> V_63 ) ;
V_2 -> V_63 = V_2 -> V_63 >= V_163 ? V_164 : V_64 ;
} else {
F_41 ( L_10 , V_2 , V_2 -> V_63 ) ;
V_2 -> V_63 = V_2 -> V_63 >= V_165 ? V_164 : V_64 ;
}
}
}
}
F_84 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_84 -> V_37 & V_40 || F_78 ( V_84 ) )
return V_84 ;
F_11 ( V_84 -> V_35 ) ;
V_84 -> V_35 = NULL ;
V_15 = V_84 ;
}
}
static void F_85 ( struct V_14 * V_15 , struct V_17 * * V_166 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_166 ;
struct V_21 * V_21 = V_110 -> V_137 ;
F_41 ( L_11 ) ;
* V_166 = V_18 -> V_20 . V_53 ;
V_18 -> V_135 = NULL ;
V_21 -> V_29 . V_138 -> V_139 -- ;
V_21 -> V_29 . V_138 -> V_167 ++ ;
if ( V_15 -> V_131 == V_18 )
V_15 -> V_131 = NULL ;
if ( V_18 -> V_128 ) {
struct V_17 * V_132 , * V_168 ;
F_60 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_132 -> V_128 -- ;
V_18 -> V_128 = 0 ;
F_86 ( & V_18 -> V_134 ) ;
}
F_82 ( & V_3 ) ;
F_83 (w) {
if ( V_2 -> V_63 == V_165 && V_2 -> V_35 == V_18 ) {
F_41 ( L_12 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_53 ;
if ( ! V_2 -> V_35 )
V_2 -> V_63 = V_164 ;
}
}
F_84 ( & V_3 ) ;
V_18 -> V_20 . V_53 = NULL ;
if ( ! V_15 -> V_35 ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_138 -> V_140 -- ;
V_15 = F_75 ( V_21 , V_15 ) ;
}
if ( F_87 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_74 ( V_21 , V_15 ) ;
F_47 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_95 ;
}
F_61 ( F_87 ( & V_18 -> V_19 ) != 1 ) ;
}
F_62 ( V_169 , V_18 , V_110 ) ;
F_11 ( V_18 ) ;
}
int F_88 ( struct V_17 * V_18 , struct V_109 * V_110 )
{
struct V_21 * V_21 = V_110 -> V_137 ;
struct V_14 * V_15 = V_18 -> V_135 ;
struct V_17 * * V_166 ;
#if V_152 >= 2
if ( V_18 -> V_20 . V_170 > 0 ) {
F_29 ( V_15 != NULL ) ;
return - V_91 ;
}
#endif
if ( ! V_15 || V_18 == V_21 -> V_29 . V_36 )
return - V_91 ;
F_29 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_96 & V_142 ) ) {
struct V_14 * V_84 = V_15 ;
#ifdef F_71
if ( V_18 -> V_147 . V_78 ) {
while ( ! ( V_84 -> V_37 & V_38 ) )
V_84 = V_84 -> V_95 ;
V_84 = V_84 -> V_95 ;
}
#endif
F_72 ( V_110 -> V_137 , V_84 ) ;
}
for ( V_166 = & V_15 -> V_35 ; * V_166 ; V_166 = & ( * V_166 ) -> V_20 . V_53 ) {
if ( * V_166 == V_18 ) {
F_85 ( V_15 , V_166 , V_110 ) ;
return 0 ;
}
}
return - V_91 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_84 ;
for (; ; ) {
V_15 = V_2 -> V_65 ;
if ( ! V_15 )
return 0 ;
if ( V_2 -> V_171 && V_15 != V_2 -> V_59 &&
V_15 -> V_37 & V_40 && V_2 -> V_63 < V_165 ) {
V_2 -> V_63 = V_165 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_63 ) {
#ifdef F_71
case V_172 :
if ( F_78 ( V_15 ) ) {
V_2 -> V_65 = F_78 ( V_15 ) ;
continue;
}
V_2 -> V_63 = V_162 ;
#endif
case V_162 :
if ( V_15 -> V_94 ) {
V_2 -> V_65 = V_15 -> V_94 ;
V_2 -> V_63 = V_64 ;
continue;
}
V_2 -> V_63 = V_163 ;
case V_163 :
if ( V_15 -> V_93 ) {
V_2 -> V_65 = V_15 -> V_93 ;
V_2 -> V_63 = V_64 ;
continue;
}
V_2 -> V_63 = V_165 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_165 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_121 ;
if ( V_2 -> V_61 ) {
V_2 -> V_61 -- ;
goto V_61;
}
V_121 = V_2 -> V_73 ( V_2 ) ;
if ( V_121 )
return V_121 ;
V_2 -> V_60 ++ ;
continue;
}
V_61:
V_2 -> V_63 = V_164 ;
case V_164 :
if ( V_15 == V_2 -> V_59 )
return 0 ;
V_84 = V_15 -> V_95 ;
V_2 -> V_65 = V_84 ;
#ifdef F_71
if ( F_78 ( V_84 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_63 = V_162 ;
continue;
}
#endif
if ( V_84 -> V_94 == V_15 ) {
V_2 -> V_63 = V_163 ;
continue;
}
if ( V_84 -> V_93 == V_15 ) {
V_2 -> V_63 = V_165 ;
V_2 -> V_35 = V_2 -> V_65 -> V_35 ;
continue;
}
#if V_152 >= 2
F_29 ( 1 ) ;
#endif
}
}
}
static int F_35 ( struct V_1 * V_2 )
{
int V_52 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_2 -> V_59 ;
F_1 ( V_2 ) ;
V_52 = F_37 ( V_2 ) ;
if ( V_52 <= 0 )
F_5 ( V_2 ) ;
return V_52 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_17 * V_18 ;
struct V_173 * V_174 = F_90 ( V_2 , struct V_173 , V_2 ) ;
struct V_109 V_110 = {
. V_137 = V_174 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_53 ) {
V_52 = V_174 -> V_73 ( V_18 , V_174 -> V_71 ) ;
if ( V_52 < 0 ) {
V_2 -> V_35 = V_18 ;
V_52 = F_88 ( V_18 , & V_110 ) ;
if ( V_52 ) {
#if V_152 >= 2
F_91 ( L_13 ,
V_175 , V_18 , V_18 -> V_135 , V_52 ) ;
#endif
continue;
}
return 0 ;
}
F_29 ( V_52 != 0 ) ;
}
V_2 -> V_35 = V_18 ;
return 0 ;
}
static void F_92 ( struct V_21 * V_21 , struct V_14 * V_59 ,
int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_171 , void * V_71 )
{
struct V_173 V_174 ;
V_174 . V_2 . V_59 = V_59 ;
V_174 . V_2 . V_73 = F_89 ;
V_174 . V_2 . V_171 = V_171 ;
V_174 . V_2 . V_60 = 0 ;
V_174 . V_2 . V_61 = 0 ;
V_174 . V_73 = V_73 ;
V_174 . V_71 = V_71 ;
V_174 . V_21 = V_21 ;
F_35 ( & V_174 . V_2 ) ;
}
void F_93 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
void * V_71 )
{
struct V_22 * V_32 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
F_22 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (table, head, tb6_hlist) {
F_2 ( & V_32 -> V_25 ) ;
F_92 ( V_21 , & V_32 -> V_34 ,
V_73 , 0 , V_71 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
static int F_94 ( struct V_17 * V_18 , void * V_71 )
{
if ( V_18 -> V_96 & V_142 ) {
F_41 ( L_14 , V_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_72 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
F_92 ( V_21 , V_15 , F_94 , 1 , NULL ) ;
}
static int F_95 ( struct V_17 * V_18 , void * V_71 )
{
T_6 V_89 = * ( T_6 * ) V_71 ;
if ( V_18 -> V_135 &&
V_18 -> V_135 -> V_62 != V_89 )
V_18 -> V_135 -> V_62 = V_89 ;
return 0 ;
}
static void F_96 ( struct V_21 * V_21 )
{
T_6 V_176 = F_7 () ;
F_93 ( V_21 , F_95 , & V_176 ) ;
}
static int F_97 ( struct V_17 * V_18 , void * V_71 )
{
unsigned long V_177 = V_143 ;
if ( V_18 -> V_96 & V_129 && V_18 -> V_20 . V_130 ) {
if ( F_98 ( V_177 , V_18 -> V_20 . V_130 ) ) {
F_41 ( L_15 , V_18 ) ;
return - 1 ;
}
V_178 . V_179 ++ ;
} else if ( V_18 -> V_96 & V_142 ) {
if ( F_87 ( & V_18 -> V_20 . V_180 ) == 0 &&
F_99 ( V_177 , V_18 -> V_20 . V_181 + V_178 . V_182 ) ) {
F_41 ( L_16 , V_18 ) ;
return - 1 ;
} else if ( V_18 -> V_96 & V_97 ) {
struct V_183 * V_184 ;
T_7 V_185 = 0 ;
V_184 = F_100 ( & V_18 -> V_20 , & V_18 -> V_127 ) ;
if ( V_184 ) {
V_185 = V_184 -> V_50 ;
F_101 ( V_184 ) ;
}
if ( ! ( V_185 & V_186 ) ) {
F_41 ( L_17 ,
V_18 ) ;
return - 1 ;
}
}
V_178 . V_179 ++ ;
}
return 0 ;
}
void F_102 ( unsigned long V_130 , struct V_21 * V_21 , bool V_187 )
{
unsigned long V_177 ;
if ( V_187 ) {
F_103 ( & V_188 ) ;
} else if ( ! F_104 ( & V_188 ) ) {
F_65 ( & V_21 -> V_29 . V_141 , V_143 + V_189 ) ;
return;
}
V_178 . V_182 = V_130 ? ( int ) V_130 :
V_21 -> V_29 . V_144 . V_145 ;
V_178 . V_179 = F_105 () ;
F_93 ( V_21 , F_97 , NULL ) ;
V_177 = V_143 ;
V_21 -> V_29 . V_190 = V_177 ;
if ( V_178 . V_179 )
F_65 ( & V_21 -> V_29 . V_141 ,
F_106 ( V_177
+ V_21 -> V_29 . V_144 . V_145 ) ) ;
else
F_107 ( & V_21 -> V_29 . V_141 ) ;
F_108 ( & V_188 ) ;
}
static void F_109 ( unsigned long V_71 )
{
F_102 ( 0 , (struct V_21 * ) V_71 , true ) ;
}
static int T_4 F_110 ( struct V_21 * V_21 )
{
T_8 V_191 = sizeof( struct V_43 ) * V_27 ;
F_111 ( & V_21 -> V_29 . V_141 , F_109 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_138 = F_18 ( sizeof( * V_21 -> V_29 . V_138 ) , V_192 ) ;
if ( ! V_21 -> V_29 . V_138 )
goto V_193;
V_191 = F_112 ( T_8 , V_191 , V_194 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_191 , V_192 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_195;
V_21 -> V_29 . V_45 = F_18 ( sizeof( * V_21 -> V_29 . V_45 ) ,
V_192 ) ;
if ( ! V_21 -> V_29 . V_45 )
goto V_196;
V_21 -> V_29 . V_45 -> V_26 = V_42 ;
V_21 -> V_29 . V_45 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_45 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_45 -> V_41 ) ;
#ifdef F_113
V_21 -> V_29 . V_46 = F_18 ( sizeof( * V_21 -> V_29 . V_46 ) ,
V_192 ) ;
if ( ! V_21 -> V_29 . V_46 )
goto V_197;
V_21 -> V_29 . V_46 -> V_26 = V_198 ;
V_21 -> V_29 . V_46 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_46 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_46 -> V_41 ) ;
#endif
F_25 ( V_21 ) ;
return 0 ;
#ifdef F_113
V_197:
F_31 ( V_21 -> V_29 . V_45 ) ;
#endif
V_196:
F_31 ( V_21 -> V_29 . V_30 ) ;
V_195:
F_31 ( V_21 -> V_29 . V_138 ) ;
V_193:
return - V_72 ;
}
static void F_114 ( struct V_21 * V_21 )
{
F_115 ( V_21 , NULL ) ;
F_116 ( & V_21 -> V_29 . V_141 ) ;
#ifdef F_113
F_117 ( & V_21 -> V_29 . V_46 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_46 ) ;
#endif
F_117 ( & V_21 -> V_29 . V_45 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_45 ) ;
F_31 ( V_21 -> V_29 . V_30 ) ;
F_31 ( V_21 -> V_29 . V_138 ) ;
}
int T_9 F_118 ( void )
{
int V_199 = - V_72 ;
V_16 = F_119 ( L_18 ,
sizeof( struct V_14 ) ,
0 , V_200 ,
NULL ) ;
if ( ! V_16 )
goto V_75;
V_199 = F_120 ( & V_201 ) ;
if ( V_199 )
goto V_202;
V_199 = F_121 ( V_203 , V_204 , NULL , F_38 ,
NULL ) ;
if ( V_199 )
goto V_205;
V_206 = F_96 ;
V_75:
return V_199 ;
V_205:
F_122 ( & V_201 ) ;
V_202:
F_123 ( V_16 ) ;
goto V_75;
}
void F_124 ( void )
{
F_122 ( & V_201 ) ;
F_123 ( V_16 ) ;
}
static int F_125 ( struct V_207 * V_208 , void * V_209 )
{
struct V_17 * V_18 = V_209 ;
struct V_210 * V_111 = V_208 -> V_211 ;
F_126 ( V_208 , L_19 , & V_18 -> V_146 . V_11 , V_18 -> V_146 . V_78 ) ;
#ifdef F_71
F_126 ( V_208 , L_19 , & V_18 -> V_147 . V_11 , V_18 -> V_147 . V_78 ) ;
#else
F_127 ( V_208 , L_20 ) ;
#endif
if ( V_18 -> V_96 & V_97 )
F_126 ( V_208 , L_21 , & V_18 -> V_127 ) ;
else
F_127 ( V_208 , L_22 ) ;
F_126 ( V_208 , L_23 ,
V_18 -> V_122 , F_87 ( & V_18 -> V_20 . V_180 ) ,
V_18 -> V_20 . V_212 , V_18 -> V_96 ,
V_18 -> V_20 . V_125 ? V_18 -> V_20 . V_125 -> V_213 : L_24 ) ;
V_111 -> V_2 . V_35 = NULL ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_210 * V_111 = V_2 -> args ;
if ( ! V_111 -> V_61 )
return 1 ;
do {
V_111 -> V_2 . V_35 = V_111 -> V_2 . V_35 -> V_20 . V_53 ;
V_111 -> V_61 -- ;
if ( ! V_111 -> V_61 && V_111 -> V_2 . V_35 )
return 1 ;
} while ( V_111 -> V_2 . V_35 );
return 0 ;
}
static void F_129 ( struct V_210 * V_111 )
{
memset ( & V_111 -> V_2 , 0 , sizeof( V_111 -> V_2 ) ) ;
V_111 -> V_2 . V_73 = F_128 ;
V_111 -> V_2 . V_59 = & V_111 -> V_214 -> V_34 ;
V_111 -> V_2 . V_63 = V_64 ;
V_111 -> V_2 . V_65 = V_111 -> V_2 . V_59 ;
V_111 -> V_2 . args = V_111 ;
V_111 -> V_89 = V_111 -> V_2 . V_59 -> V_62 ;
F_130 ( & V_111 -> V_2 . V_4 ) ;
F_1 ( & V_111 -> V_2 ) ;
}
static struct V_22 * F_131 ( struct V_22 * V_214 ,
struct V_21 * V_21 )
{
unsigned int V_24 ;
struct V_215 * V_65 ;
if ( V_214 ) {
V_24 = ( V_214 -> V_26 & ( V_27 - 1 ) ) + 1 ;
V_65 = F_132 ( F_133 ( & V_214 -> V_28 ) ) ;
} else {
V_24 = 0 ;
V_65 = NULL ;
}
while ( ! V_65 && V_24 < V_27 ) {
V_65 = F_132 (
F_134 ( & V_21 -> V_29 . V_30 [ V_24 ++ ] ) ) ;
}
return F_135 ( V_65 , struct V_22 , V_28 ) ;
}
static void F_136 ( struct V_210 * V_111 )
{
if ( V_111 -> V_89 != V_111 -> V_2 . V_59 -> V_62 ) {
V_111 -> V_89 = V_111 -> V_2 . V_59 -> V_62 ;
V_111 -> V_2 . V_63 = V_64 ;
V_111 -> V_2 . V_65 = V_111 -> V_2 . V_59 ;
F_29 ( V_111 -> V_2 . V_61 ) ;
V_111 -> V_2 . V_61 = V_111 -> V_2 . V_60 ;
}
}
static void * F_137 ( struct V_207 * V_208 , void * V_209 , T_10 * V_216 )
{
int V_217 ;
struct V_17 * V_6 ;
struct V_21 * V_21 = F_138 ( V_208 ) ;
struct V_210 * V_111 = V_208 -> V_211 ;
if ( ! V_209 )
goto V_218;
V_6 = ( (struct V_17 * ) V_209 ) -> V_20 . V_53 ;
if ( V_6 ) {
++ * V_216 ;
return V_6 ;
}
V_218:
F_136 ( V_111 ) ;
F_82 ( & V_111 -> V_214 -> V_25 ) ;
V_217 = F_37 ( & V_111 -> V_2 ) ;
F_84 ( & V_111 -> V_214 -> V_25 ) ;
if ( V_217 > 0 ) {
if ( V_209 )
++ * V_216 ;
return V_111 -> V_2 . V_35 ;
} else if ( V_217 < 0 ) {
F_5 ( & V_111 -> V_2 ) ;
return NULL ;
}
F_5 ( & V_111 -> V_2 ) ;
V_111 -> V_214 = F_131 ( V_111 -> V_214 , V_21 ) ;
if ( ! V_111 -> V_214 )
return NULL ;
F_129 ( V_111 ) ;
goto V_218;
}
static void * F_139 ( struct V_207 * V_208 , T_10 * V_216 )
__acquires( T_11 )
{
struct V_21 * V_21 = F_138 ( V_208 ) ;
struct V_210 * V_111 = V_208 -> V_211 ;
F_140 () ;
V_111 -> V_214 = F_131 ( NULL , V_21 ) ;
V_111 -> V_61 = * V_216 ;
if ( V_111 -> V_214 ) {
F_129 ( V_111 ) ;
return F_137 ( V_208 , NULL , V_216 ) ;
} else {
return NULL ;
}
}
static bool F_141 ( struct V_210 * V_111 )
{
struct V_1 * V_2 = & V_111 -> V_2 ;
return V_2 -> V_65 && ! ( V_2 -> V_63 == V_164 && V_2 -> V_65 == V_2 -> V_59 ) ;
}
static void F_142 ( struct V_207 * V_208 , void * V_209 )
__releases( T_11 )
{
struct V_210 * V_111 = V_208 -> V_211 ;
if ( F_141 ( V_111 ) )
F_5 ( & V_111 -> V_2 ) ;
F_143 () ;
}
int F_144 ( struct V_219 * V_219 , struct V_220 * V_220 )
{
return F_145 ( V_219 , V_220 , & V_221 ,
sizeof( struct V_210 ) ) ;
}
