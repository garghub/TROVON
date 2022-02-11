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
struct V_45 * V_46 ;
unsigned int V_24 ;
if ( V_31 == 0 )
V_31 = V_42 ;
V_24 = V_31 & ( V_27 - 1 ) ;
F_22 () ;
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (tb, node, head, tb6_hlist) {
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
F_14 ( V_21 , V_21 -> V_29 . V_47 ) ;
F_14 ( V_21 , V_21 -> V_29 . V_48 ) ;
}
struct V_22 * F_20 ( struct V_21 * V_21 , T_2 V_31 )
{
return F_21 ( V_21 , V_31 ) ;
}
struct V_22 * F_21 ( struct V_21 * V_21 , T_2 V_31 )
{
return V_21 -> V_29 . V_47 ;
}
struct V_49 * F_26 ( struct V_21 * V_21 , struct V_50 * V_51 ,
int V_52 , T_5 V_53 )
{
return (struct V_49 * ) V_53 ( V_21 , V_21 -> V_29 . V_47 , V_51 , V_52 ) ;
}
static void T_4 F_25 ( struct V_21 * V_21 )
{
F_14 ( V_21 , V_21 -> V_29 . V_47 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_54 ;
struct V_17 * V_18 ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_55 ) {
V_54 = F_28 ( V_18 , V_2 -> args ) ;
if ( V_54 < 0 ) {
V_2 -> V_35 = V_18 ;
return 1 ;
}
F_29 ( V_54 == 0 ) ;
}
V_2 -> V_35 = NULL ;
return 0 ;
}
static void F_30 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = ( void * ) V_57 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_57 -> args [ 4 ] ) {
V_57 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_57 -> args [ 2 ] = 0 ;
F_31 ( V_2 ) ;
}
V_57 -> V_58 = ( void * ) V_57 -> args [ 3 ] ;
V_57 -> args [ 1 ] = 3 ;
}
static int F_32 ( struct V_56 * V_57 )
{
F_30 ( V_57 ) ;
return V_57 -> V_58 ? V_57 -> V_58 ( V_57 ) : 0 ;
}
static int F_33 ( struct V_22 * V_32 , struct V_59 * V_60 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 ;
int V_54 ;
V_2 = ( void * ) V_57 -> args [ 2 ] ;
V_2 -> V_61 = & V_32 -> V_34 ;
if ( V_57 -> args [ 4 ] == 0 ) {
V_2 -> V_62 = 0 ;
V_2 -> V_63 = 0 ;
F_34 ( & V_32 -> V_25 ) ;
V_54 = F_35 ( V_2 ) ;
F_36 ( & V_32 -> V_25 ) ;
if ( V_54 > 0 ) {
V_57 -> args [ 4 ] = 1 ;
V_57 -> args [ 5 ] = V_2 -> V_61 -> V_64 ;
}
} else {
if ( V_57 -> args [ 5 ] != V_2 -> V_61 -> V_64 ) {
V_57 -> args [ 5 ] = V_2 -> V_61 -> V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_46 = V_2 -> V_61 ;
V_2 -> V_63 = V_2 -> V_62 ;
} else
V_2 -> V_63 = 0 ;
F_34 ( & V_32 -> V_25 ) ;
V_54 = F_37 ( V_2 ) ;
F_36 ( & V_32 -> V_25 ) ;
if ( V_54 <= 0 ) {
F_5 ( V_2 ) ;
V_57 -> args [ 4 ] = 0 ;
}
}
return V_54 ;
}
static int F_38 ( struct V_59 * V_60 , struct V_56 * V_57 )
{
struct V_21 * V_21 = F_39 ( V_60 -> V_67 ) ;
unsigned int V_24 , V_68 ;
unsigned int V_69 = 0 , V_70 ;
struct V_71 V_72 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
int V_54 = 0 ;
V_68 = V_57 -> args [ 0 ] ;
V_70 = V_57 -> args [ 1 ] ;
V_2 = ( void * ) V_57 -> args [ 2 ] ;
if ( ! V_2 ) {
V_57 -> args [ 3 ] = ( long ) V_57 -> V_58 ;
V_57 -> V_58 = F_32 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_74 = F_27 ;
V_57 -> args [ 2 ] = ( long ) V_2 ;
}
V_72 . V_60 = V_60 ;
V_72 . V_57 = V_57 ;
V_72 . V_21 = V_21 ;
V_2 -> args = & V_72 ;
F_22 () ;
for ( V_24 = V_68 ; V_24 < V_27 ; V_24 ++ , V_70 = 0 ) {
V_69 = 0 ;
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (tb, node, head, tb6_hlist) {
if ( V_69 < V_70 )
goto V_75;
V_54 = F_33 ( V_23 , V_60 , V_57 ) ;
if ( V_54 != 0 )
goto V_76;
V_75:
V_69 ++ ;
}
}
V_76:
F_24 () ;
V_57 -> args [ 1 ] = V_69 ;
V_57 -> args [ 0 ] = V_24 ;
V_54 = V_54 < 0 ? V_54 : V_60 -> V_77 ;
if ( V_54 <= 0 )
F_30 ( V_57 ) ;
return V_54 ;
}
static struct V_14 * F_40 ( struct V_14 * V_61 , void * V_11 ,
int V_78 , int V_79 ,
int V_80 , int V_81 ,
int V_82 )
{
struct V_14 * V_15 , * V_83 , * V_84 ;
struct V_14 * V_85 = NULL ;
struct V_86 * V_87 ;
int V_88 ;
T_3 V_89 = 0 ;
T_6 V_90 = F_7 () ;
F_41 ( L_1 ) ;
V_15 = V_61 ;
do {
V_87 = (struct V_86 * ) ( ( V_91 * ) V_15 -> V_35 + V_80 ) ;
if ( V_79 < V_15 -> V_10 ||
! F_42 ( & V_87 -> V_11 , V_11 , V_15 -> V_10 ) ) {
if ( ! V_81 ) {
if ( V_82 ) {
F_43 ( L_2 ) ;
return F_44 ( - V_92 ) ;
}
F_43 ( L_3 ) ;
}
goto V_93;
}
if ( V_79 == V_15 -> V_10 ) {
if ( ! ( V_15 -> V_37 & V_40 ) ) {
F_11 ( V_15 -> V_35 ) ;
V_15 -> V_35 = NULL ;
}
V_15 -> V_64 = V_90 ;
return V_15 ;
}
V_15 -> V_64 = V_90 ;
V_89 = F_8 ( V_11 , V_15 -> V_10 ) ;
V_85 = V_15 ;
V_15 = V_89 ? V_15 -> V_94 : V_15 -> V_95 ;
} while ( V_15 );
if ( ! V_81 ) {
if ( V_82 ) {
F_43 ( L_2 ) ;
return F_44 ( - V_92 ) ;
}
F_43 ( L_3 ) ;
}
V_84 = F_45 () ;
if ( ! V_84 )
return F_44 ( - V_73 ) ;
V_84 -> V_10 = V_79 ;
V_84 -> V_96 = V_85 ;
V_84 -> V_64 = V_90 ;
if ( V_89 )
V_85 -> V_94 = V_84 ;
else
V_85 -> V_95 = V_84 ;
return V_84 ;
V_93:
V_85 = V_15 -> V_96 ;
V_88 = F_46 ( V_11 , & V_87 -> V_11 , V_78 ) ;
if ( V_79 > V_88 ) {
V_83 = F_45 () ;
V_84 = F_45 () ;
if ( ! V_83 || ! V_84 ) {
if ( V_83 )
F_9 ( V_83 ) ;
if ( V_84 )
F_9 ( V_84 ) ;
return F_44 ( - V_73 ) ;
}
V_83 -> V_10 = V_88 ;
V_83 -> V_96 = V_85 ;
V_83 -> V_35 = V_15 -> V_35 ;
F_47 ( & V_83 -> V_35 -> V_19 ) ;
V_83 -> V_64 = V_90 ;
if ( V_89 )
V_85 -> V_94 = V_83 ;
else
V_85 -> V_95 = V_83 ;
V_84 -> V_10 = V_79 ;
V_84 -> V_96 = V_83 ;
V_15 -> V_96 = V_83 ;
V_84 -> V_64 = V_90 ;
if ( F_8 ( V_11 , V_88 ) ) {
V_83 -> V_94 = V_84 ;
V_83 -> V_95 = V_15 ;
} else {
V_83 -> V_95 = V_84 ;
V_83 -> V_94 = V_15 ;
}
} else {
V_84 = F_45 () ;
if ( ! V_84 )
return F_44 ( - V_73 ) ;
V_84 -> V_10 = V_79 ;
V_84 -> V_96 = V_85 ;
V_84 -> V_64 = V_90 ;
if ( V_89 )
V_85 -> V_94 = V_84 ;
else
V_85 -> V_95 = V_84 ;
if ( F_8 ( & V_87 -> V_11 , V_79 ) )
V_84 -> V_94 = V_15 ;
else
V_84 -> V_95 = V_15 ;
V_15 -> V_96 = V_84 ;
}
return V_84 ;
}
static int F_48 ( struct V_14 * V_15 , struct V_17 * V_18 ,
struct V_97 * V_98 )
{
struct V_17 * V_99 = NULL ;
struct V_17 * * V_100 ;
int V_101 = ( V_98 -> V_102 &&
( V_98 -> V_102 -> V_103 & V_104 ) ) ;
int V_105 = ( ! V_98 -> V_102 ||
( V_98 -> V_102 -> V_103 & V_106 ) ) ;
int V_107 = 0 ;
V_100 = & V_15 -> V_35 ;
for ( V_99 = V_15 -> V_35 ; V_99 ; V_99 = V_99 -> V_20 . V_55 ) {
if ( V_99 -> V_108 == V_18 -> V_108 ) {
if ( V_98 -> V_102 &&
( V_98 -> V_102 -> V_103 & V_109 ) )
return - V_110 ;
if ( V_101 ) {
V_107 ++ ;
break;
}
if ( V_99 -> V_20 . V_111 == V_18 -> V_20 . V_111 &&
V_99 -> V_112 == V_18 -> V_112 &&
F_49 ( & V_99 -> V_113 ,
& V_18 -> V_113 ) ) {
if ( V_18 -> V_114 )
V_18 -> V_114 = 0 ;
if ( ! ( V_99 -> V_115 & V_116 ) )
return - V_110 ;
if ( ! ( V_18 -> V_115 & V_116 ) )
F_50 ( V_99 ) ;
else
F_51 ( V_99 , V_18 -> V_20 . V_117 ) ;
return - V_110 ;
}
if ( V_18 -> V_115 & V_118 &&
! ( V_18 -> V_115 & V_116 ) &&
! ( V_99 -> V_115 & V_116 ) )
V_18 -> V_114 ++ ;
}
if ( V_99 -> V_108 > V_18 -> V_108 )
break;
V_100 = & V_99 -> V_20 . V_55 ;
}
if ( V_100 == & V_15 -> V_35 )
V_15 -> V_119 = NULL ;
if ( V_18 -> V_114 ) {
unsigned int V_114 ;
struct V_17 * V_120 , * V_121 ;
V_120 = V_15 -> V_35 ;
while ( V_120 ) {
if ( V_120 -> V_108 == V_18 -> V_108 ) {
F_52 ( & V_18 -> V_122 ,
& V_120 -> V_122 ) ;
break;
}
V_120 = V_120 -> V_20 . V_55 ;
}
V_114 = 0 ;
F_53 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_120 -> V_114 ++ ;
F_54 ( V_120 -> V_114 != V_18 -> V_114 ) ;
V_114 ++ ;
}
F_54 ( V_114 != V_18 -> V_114 ) ;
}
if ( ! V_101 ) {
if ( ! V_105 )
F_43 ( L_3 ) ;
V_105:
V_18 -> V_20 . V_55 = V_99 ;
* V_100 = V_18 ;
V_18 -> V_123 = V_15 ;
F_47 ( & V_18 -> V_19 ) ;
F_55 ( V_124 , V_18 , V_98 ) ;
V_98 -> V_125 -> V_29 . V_126 -> V_127 ++ ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_98 -> V_125 -> V_29 . V_126 -> V_128 ++ ;
V_15 -> V_37 |= V_40 ;
}
} else {
if ( ! V_107 ) {
if ( V_105 )
goto V_105;
F_43 ( L_4 ) ;
return - V_92 ;
}
* V_100 = V_18 ;
V_18 -> V_123 = V_15 ;
V_18 -> V_20 . V_55 = V_99 -> V_20 . V_55 ;
F_47 ( & V_18 -> V_19 ) ;
F_55 ( V_124 , V_18 , V_98 ) ;
F_11 ( V_99 ) ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_98 -> V_125 -> V_29 . V_126 -> V_128 ++ ;
V_15 -> V_37 |= V_40 ;
}
}
return 0 ;
}
static T_1 void F_56 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_57 ( & V_21 -> V_29 . V_129 ) &&
( V_18 -> V_115 & ( V_116 | V_130 ) ) )
F_58 ( & V_21 -> V_29 . V_129 ,
V_131 + V_21 -> V_29 . V_132 . V_133 ) ;
}
void F_59 ( struct V_21 * V_21 )
{
if ( ! F_57 ( & V_21 -> V_29 . V_129 ) )
F_58 ( & V_21 -> V_29 . V_129 ,
V_131 + V_21 -> V_29 . V_132 . V_133 ) ;
}
int F_60 ( struct V_14 * V_61 , struct V_17 * V_18 , struct V_97 * V_98 )
{
struct V_14 * V_15 , * V_85 = NULL ;
int V_134 = - V_73 ;
int V_81 = 1 ;
int V_82 = 0 ;
if ( V_98 -> V_102 ) {
if ( ! ( V_98 -> V_102 -> V_103 & V_106 ) )
V_81 = 0 ;
if ( V_98 -> V_102 -> V_103 & V_104 )
V_82 = 1 ;
}
if ( ! V_81 && ! V_82 )
F_43 ( L_5 ) ;
V_15 = F_40 ( V_61 , & V_18 -> V_135 . V_11 , sizeof( struct V_136 ) ,
V_18 -> V_135 . V_79 , F_61 ( struct V_17 , V_135 ) ,
V_81 , V_82 ) ;
if ( F_62 ( V_15 ) ) {
V_134 = F_63 ( V_15 ) ;
goto V_76;
}
V_85 = V_15 ;
#ifdef F_64
if ( V_18 -> V_137 . V_79 ) {
struct V_14 * V_138 ;
if ( ! V_15 -> V_139 ) {
struct V_14 * V_140 ;
V_140 = F_45 () ;
if ( ! V_140 )
goto V_141;
V_140 -> V_35 = V_98 -> V_125 -> V_29 . V_36 ;
F_47 ( & V_98 -> V_125 -> V_29 . V_36 -> V_19 ) ;
V_140 -> V_37 = V_38 ;
V_140 -> V_64 = F_7 () ;
V_138 = F_40 ( V_140 , & V_18 -> V_137 . V_11 ,
sizeof( struct V_136 ) , V_18 -> V_137 . V_79 ,
F_61 ( struct V_17 , V_137 ) ,
V_81 , V_82 ) ;
if ( F_62 ( V_138 ) ) {
F_9 ( V_140 ) ;
V_134 = F_63 ( V_138 ) ;
goto V_141;
}
V_140 -> V_96 = V_15 ;
V_15 -> V_139 = V_140 ;
} else {
V_138 = F_40 ( V_15 -> V_139 , & V_18 -> V_137 . V_11 ,
sizeof( struct V_136 ) , V_18 -> V_137 . V_79 ,
F_61 ( struct V_17 , V_137 ) ,
V_81 , V_82 ) ;
if ( F_62 ( V_138 ) ) {
V_134 = F_63 ( V_138 ) ;
goto V_141;
}
}
if ( ! V_15 -> V_35 ) {
V_15 -> V_35 = V_18 ;
F_47 ( & V_18 -> V_19 ) ;
}
V_15 = V_138 ;
}
#endif
V_134 = F_48 ( V_15 , V_18 , V_98 ) ;
if ( ! V_134 ) {
F_56 ( V_98 -> V_125 , V_18 ) ;
if ( ! ( V_18 -> V_115 & V_130 ) )
F_65 ( V_98 -> V_125 , V_85 , V_18 ) ;
}
V_76:
if ( V_134 ) {
#ifdef F_64
if ( V_85 != V_15 && V_85 -> V_35 == V_18 ) {
V_85 -> V_35 = NULL ;
F_66 ( & V_18 -> V_19 ) ;
}
if ( V_85 != V_15 && ! V_85 -> V_35 && ! ( V_85 -> V_37 & V_40 ) ) {
V_85 -> V_35 = F_67 ( V_98 -> V_125 , V_85 ) ;
#if V_142 >= 2
if ( ! V_85 -> V_35 ) {
F_29 ( V_85 -> V_35 == NULL ) ;
V_85 -> V_35 = V_98 -> V_125 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_85 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_134 ;
#ifdef F_64
V_141:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_68 ( V_98 -> V_125 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_134 ;
#endif
}
static struct V_14 * F_69 ( struct V_14 * V_61 ,
struct V_143 * args )
{
struct V_14 * V_15 ;
T_3 V_89 ;
if ( F_70 ( args -> V_80 == 0 ) )
return NULL ;
V_15 = V_61 ;
for (; ; ) {
struct V_14 * V_75 ;
V_89 = F_8 ( args -> V_11 , V_15 -> V_10 ) ;
V_75 = V_89 ? V_15 -> V_94 : V_15 -> V_95 ;
if ( V_75 ) {
V_15 = V_75 ;
continue;
}
break;
}
while ( V_15 ) {
if ( F_71 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) ( ( V_91 * ) V_15 -> V_35 +
args -> V_80 ) ;
if ( F_42 ( & V_87 -> V_11 , args -> V_11 , V_87 -> V_79 ) ) {
#ifdef F_64
if ( V_15 -> V_139 )
V_15 = F_69 ( V_15 -> V_139 , args + 1 ) ;
#endif
if ( ! V_15 || V_15 -> V_37 & V_40 )
return V_15 ;
}
}
if ( V_15 -> V_37 & V_38 )
break;
V_15 = V_15 -> V_96 ;
}
return NULL ;
}
struct V_14 * F_72 ( struct V_14 * V_61 , const struct V_136 * V_144 ,
const struct V_136 * V_145 )
{
struct V_14 * V_15 ;
struct V_143 args [] = {
{
. V_80 = F_61 ( struct V_17 , V_135 ) ,
. V_11 = V_144 ,
} ,
#ifdef F_64
{
. V_80 = F_61 ( struct V_17 , V_137 ) ,
. V_11 = V_145 ,
} ,
#endif
{
. V_80 = 0 ,
}
} ;
V_15 = F_69 ( V_61 , V_144 ? args : args + 1 ) ;
if ( ! V_15 || V_15 -> V_37 & V_39 )
V_15 = V_61 ;
return V_15 ;
}
static struct V_14 * F_73 ( struct V_14 * V_61 ,
const struct V_136 * V_11 ,
int V_79 , int V_80 )
{
struct V_14 * V_15 ;
for ( V_15 = V_61 ; V_15 ; ) {
struct V_86 * V_87 = (struct V_86 * ) ( ( V_91 * ) V_15 -> V_35 + V_80 ) ;
if ( V_79 < V_15 -> V_10 ||
! F_42 ( & V_87 -> V_11 , V_11 , V_15 -> V_10 ) )
return NULL ;
if ( V_79 == V_15 -> V_10 )
return V_15 ;
if ( F_8 ( V_11 , V_15 -> V_10 ) )
V_15 = V_15 -> V_94 ;
else
V_15 = V_15 -> V_95 ;
}
return NULL ;
}
struct V_14 * F_74 ( struct V_14 * V_61 ,
const struct V_136 * V_144 , int V_146 ,
const struct V_136 * V_145 , int V_147 )
{
struct V_14 * V_15 ;
V_15 = F_73 ( V_61 , V_144 , V_146 ,
F_61 ( struct V_17 , V_135 ) ) ;
#ifdef F_64
if ( V_147 ) {
F_29 ( V_145 == NULL ) ;
if ( V_15 && V_15 -> V_139 )
V_15 = F_73 ( V_15 -> V_139 , V_145 , V_147 ,
F_61 ( struct V_17 , V_137 ) ) ;
}
#endif
if ( V_15 && V_15 -> V_37 & V_40 )
return V_15 ;
return NULL ;
}
static struct V_17 * F_67 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
if ( V_15 -> V_37 & V_38 )
return V_21 -> V_29 . V_36 ;
while ( V_15 ) {
if ( V_15 -> V_95 )
return V_15 -> V_95 -> V_35 ;
if ( V_15 -> V_94 )
return V_15 -> V_94 -> V_35 ;
V_15 = F_71 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_68 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_148 ;
int V_149 ;
struct V_14 * V_150 , * V_85 ;
struct V_1 * V_2 ;
int V_99 = 0 ;
for (; ; ) {
F_41 ( L_6 , V_15 -> V_10 , V_99 ) ;
V_99 ++ ;
F_29 ( V_15 -> V_37 & V_40 ) ;
F_29 ( V_15 -> V_37 & V_39 ) ;
F_29 ( V_15 -> V_35 != NULL ) ;
V_148 = 0 ;
V_150 = NULL ;
if ( V_15 -> V_94 ) V_150 = V_15 -> V_94 , V_148 |= 1 ;
if ( V_15 -> V_95 ) V_150 = V_15 -> V_95 , V_148 |= 2 ;
if ( V_148 == 3 || F_71 ( V_15 )
#ifdef F_64
|| ( V_148 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_67 ( V_21 , V_15 ) ;
#if V_142 >= 2
if ( ! V_15 -> V_35 ) {
F_29 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_96 ;
}
V_85 = V_15 -> V_96 ;
#ifdef F_64
if ( F_71 ( V_85 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_71 ( V_85 ) = NULL ;
V_149 = V_151 ;
} else {
F_29 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_85 -> V_94 == V_15 ) V_85 -> V_94 = V_150 ;
else if ( V_85 -> V_95 == V_15 ) V_85 -> V_95 = V_150 ;
#if V_142 >= 2
else
F_29 ( 1 ) ;
#endif
if ( V_150 )
V_150 -> V_96 = V_85 ;
V_149 = V_152 ;
#ifdef F_64
}
#endif
F_75 ( & V_3 ) ;
F_76 (w) {
if ( ! V_150 ) {
if ( V_2 -> V_61 == V_15 ) {
V_2 -> V_61 = V_2 -> V_46 = NULL ;
F_41 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_46 == V_15 ) {
F_41 ( L_8 , V_2 , V_2 -> V_65 , V_149 ) ;
V_2 -> V_46 = V_85 ;
V_2 -> V_65 = V_149 ;
}
} else {
if ( V_2 -> V_61 == V_15 ) {
V_2 -> V_61 = V_150 ;
F_41 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_46 == V_15 ) {
V_2 -> V_46 = V_150 ;
if ( V_148 & 2 ) {
F_41 ( L_10 , V_2 , V_2 -> V_65 ) ;
V_2 -> V_65 = V_2 -> V_65 >= V_152 ? V_153 : V_66 ;
} else {
F_41 ( L_10 , V_2 , V_2 -> V_65 ) ;
V_2 -> V_65 = V_2 -> V_65 >= V_154 ? V_153 : V_66 ;
}
}
}
}
F_77 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_85 -> V_37 & V_40 || F_71 ( V_85 ) )
return V_85 ;
F_11 ( V_85 -> V_35 ) ;
V_85 -> V_35 = NULL ;
V_15 = V_85 ;
}
}
static void F_78 ( struct V_14 * V_15 , struct V_17 * * V_155 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_155 ;
struct V_21 * V_21 = V_98 -> V_125 ;
F_41 ( L_11 ) ;
* V_155 = V_18 -> V_20 . V_55 ;
V_18 -> V_123 = NULL ;
V_21 -> V_29 . V_126 -> V_127 -- ;
V_21 -> V_29 . V_126 -> V_156 ++ ;
if ( V_15 -> V_119 == V_18 )
V_15 -> V_119 = NULL ;
if ( V_18 -> V_114 ) {
struct V_17 * V_120 , * V_157 ;
F_53 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_120 -> V_114 -- ;
V_18 -> V_114 = 0 ;
F_79 ( & V_18 -> V_122 ) ;
}
F_75 ( & V_3 ) ;
F_76 (w) {
if ( V_2 -> V_65 == V_154 && V_2 -> V_35 == V_18 ) {
F_41 ( L_12 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_55 ;
if ( ! V_2 -> V_35 )
V_2 -> V_65 = V_153 ;
}
}
F_77 ( & V_3 ) ;
V_18 -> V_20 . V_55 = NULL ;
if ( ! V_15 -> V_35 ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_126 -> V_128 -- ;
V_15 = F_68 ( V_21 , V_15 ) ;
}
if ( F_80 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_67 ( V_21 , V_15 ) ;
F_47 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_96 ;
}
F_54 ( F_80 ( & V_18 -> V_19 ) != 1 ) ;
}
F_55 ( V_158 , V_18 , V_98 ) ;
F_11 ( V_18 ) ;
}
int F_81 ( struct V_17 * V_18 , struct V_97 * V_98 )
{
struct V_21 * V_21 = V_98 -> V_125 ;
struct V_14 * V_15 = V_18 -> V_123 ;
struct V_17 * * V_155 ;
#if V_142 >= 2
if ( V_18 -> V_20 . V_159 > 0 ) {
F_29 ( V_15 != NULL ) ;
return - V_92 ;
}
#endif
if ( ! V_15 || V_18 == V_21 -> V_29 . V_36 )
return - V_92 ;
F_29 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_115 & V_130 ) ) {
struct V_14 * V_85 = V_15 ;
#ifdef F_64
if ( V_18 -> V_137 . V_79 ) {
while ( ! ( V_85 -> V_37 & V_38 ) )
V_85 = V_85 -> V_96 ;
V_85 = V_85 -> V_96 ;
}
#endif
F_65 ( V_98 -> V_125 , V_85 , V_18 ) ;
}
for ( V_155 = & V_15 -> V_35 ; * V_155 ; V_155 = & ( * V_155 ) -> V_20 . V_55 ) {
if ( * V_155 == V_18 ) {
F_78 ( V_15 , V_155 , V_98 ) ;
return 0 ;
}
}
return - V_92 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_85 ;
for (; ; ) {
V_15 = V_2 -> V_46 ;
if ( ! V_15 )
return 0 ;
if ( V_2 -> V_160 && V_15 != V_2 -> V_61 &&
V_15 -> V_37 & V_40 && V_2 -> V_65 < V_154 ) {
V_2 -> V_65 = V_154 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_65 ) {
#ifdef F_64
case V_161 :
if ( F_71 ( V_15 ) ) {
V_2 -> V_46 = F_71 ( V_15 ) ;
continue;
}
V_2 -> V_65 = V_151 ;
#endif
case V_151 :
if ( V_15 -> V_95 ) {
V_2 -> V_46 = V_15 -> V_95 ;
V_2 -> V_65 = V_66 ;
continue;
}
V_2 -> V_65 = V_152 ;
case V_152 :
if ( V_15 -> V_94 ) {
V_2 -> V_46 = V_15 -> V_94 ;
V_2 -> V_65 = V_66 ;
continue;
}
V_2 -> V_65 = V_154 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_154 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_134 ;
if ( V_2 -> V_63 ) {
V_2 -> V_63 -- ;
continue;
}
V_134 = V_2 -> V_74 ( V_2 ) ;
if ( V_134 )
return V_134 ;
V_2 -> V_62 ++ ;
continue;
}
V_2 -> V_65 = V_153 ;
case V_153 :
if ( V_15 == V_2 -> V_61 )
return 0 ;
V_85 = V_15 -> V_96 ;
V_2 -> V_46 = V_85 ;
#ifdef F_64
if ( F_71 ( V_85 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_65 = V_151 ;
continue;
}
#endif
if ( V_85 -> V_95 == V_15 ) {
V_2 -> V_65 = V_152 ;
continue;
}
if ( V_85 -> V_94 == V_15 ) {
V_2 -> V_65 = V_154 ;
V_2 -> V_35 = V_2 -> V_46 -> V_35 ;
continue;
}
#if V_142 >= 2
F_29 ( 1 ) ;
#endif
}
}
}
static int F_35 ( struct V_1 * V_2 )
{
int V_54 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_46 = V_2 -> V_61 ;
F_1 ( V_2 ) ;
V_54 = F_37 ( V_2 ) ;
if ( V_54 <= 0 )
F_5 ( V_2 ) ;
return V_54 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_54 ;
struct V_17 * V_18 ;
struct V_162 * V_163 = F_83 ( V_2 , struct V_162 , V_2 ) ;
struct V_97 V_98 = {
. V_125 = V_163 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_55 ) {
V_54 = V_163 -> V_74 ( V_18 , V_163 -> V_72 ) ;
if ( V_54 < 0 ) {
V_2 -> V_35 = V_18 ;
V_54 = F_81 ( V_18 , & V_98 ) ;
if ( V_54 ) {
#if V_142 >= 2
F_84 ( L_13 ,
V_164 , V_18 , V_18 -> V_123 , V_54 ) ;
#endif
continue;
}
return 0 ;
}
F_29 ( V_54 != 0 ) ;
}
V_2 -> V_35 = V_18 ;
return 0 ;
}
static void F_85 ( struct V_21 * V_21 , struct V_14 * V_61 ,
int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_160 , void * V_72 )
{
struct V_162 V_163 ;
V_163 . V_2 . V_61 = V_61 ;
V_163 . V_2 . V_74 = F_82 ;
V_163 . V_2 . V_160 = V_160 ;
V_163 . V_2 . V_62 = 0 ;
V_163 . V_2 . V_63 = 0 ;
V_163 . V_74 = V_74 ;
V_163 . V_72 = V_72 ;
V_163 . V_21 = V_21 ;
F_35 ( & V_163 . V_2 ) ;
}
void F_86 ( struct V_21 * V_21 , int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_160 , void * V_72 )
{
struct V_22 * V_32 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
F_22 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (table, node, head, tb6_hlist) {
F_34 ( & V_32 -> V_25 ) ;
F_85 ( V_21 , & V_32 -> V_34 ,
V_74 , V_160 , V_72 ) ;
F_36 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
void F_87 ( struct V_21 * V_21 , int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_160 , void * V_72 )
{
struct V_22 * V_32 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
F_22 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (table, node, head, tb6_hlist) {
F_2 ( & V_32 -> V_25 ) ;
F_85 ( V_21 , & V_32 -> V_34 ,
V_74 , V_160 , V_72 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
static int F_88 ( struct V_17 * V_18 , void * V_72 )
{
if ( V_18 -> V_115 & V_130 ) {
F_41 ( L_14 , V_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_65 ( struct V_21 * V_21 , struct V_14 * V_15 ,
struct V_17 * V_18 )
{
F_85 ( V_21 , V_15 , F_88 , 1 , V_18 ) ;
}
static int F_89 ( struct V_17 * V_18 , void * V_72 )
{
unsigned long V_165 = V_131 ;
if ( V_18 -> V_115 & V_116 && V_18 -> V_20 . V_117 ) {
if ( F_90 ( V_165 , V_18 -> V_20 . V_117 ) ) {
F_41 ( L_15 , V_18 ) ;
return - 1 ;
}
V_166 . V_167 ++ ;
} else if ( V_18 -> V_115 & V_130 ) {
if ( F_80 ( & V_18 -> V_20 . V_168 ) == 0 &&
F_91 ( V_165 , V_18 -> V_20 . V_169 + V_166 . V_170 ) ) {
F_41 ( L_16 , V_18 ) ;
return - 1 ;
} else if ( V_18 -> V_115 & V_118 ) {
struct V_171 * V_172 ;
T_7 V_173 = 0 ;
V_172 = F_92 ( & V_18 -> V_20 , & V_18 -> V_113 ) ;
if ( V_172 ) {
V_173 = V_172 -> V_52 ;
F_93 ( V_172 ) ;
}
if ( ! ( V_173 & V_174 ) ) {
F_41 ( L_17 ,
V_18 ) ;
return - 1 ;
}
}
V_166 . V_167 ++ ;
}
return 0 ;
}
void F_94 ( unsigned long V_117 , struct V_21 * V_21 )
{
if ( V_117 != ~ 0UL ) {
F_95 ( & V_175 ) ;
V_166 . V_170 = V_117 ? ( int ) V_117 :
V_21 -> V_29 . V_132 . V_133 ;
} else {
if ( ! F_96 ( & V_175 ) ) {
F_58 ( & V_21 -> V_29 . V_129 , V_131 + V_176 ) ;
return;
}
V_166 . V_170 = V_21 -> V_29 . V_132 . V_133 ;
}
V_166 . V_167 = F_97 () ;
F_87 ( V_21 , F_89 , 0 , NULL ) ;
if ( V_166 . V_167 )
F_58 ( & V_21 -> V_29 . V_129 ,
F_98 ( V_131
+ V_21 -> V_29 . V_132 . V_133 ) ) ;
else
F_99 ( & V_21 -> V_29 . V_129 ) ;
F_100 ( & V_175 ) ;
}
static void F_101 ( unsigned long V_72 )
{
F_94 ( 0 , (struct V_21 * ) V_72 ) ;
}
static int T_4 F_102 ( struct V_21 * V_21 )
{
T_8 V_177 = sizeof( struct V_43 ) * V_27 ;
F_103 ( & V_21 -> V_29 . V_129 , F_101 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_126 = F_18 ( sizeof( * V_21 -> V_29 . V_126 ) , V_178 ) ;
if ( ! V_21 -> V_29 . V_126 )
goto V_179;
V_177 = F_104 ( T_8 , V_177 , V_180 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_177 , V_178 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_181;
V_21 -> V_29 . V_47 = F_18 ( sizeof( * V_21 -> V_29 . V_47 ) ,
V_178 ) ;
if ( ! V_21 -> V_29 . V_47 )
goto V_182;
V_21 -> V_29 . V_47 -> V_26 = V_42 ;
V_21 -> V_29 . V_47 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_47 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_47 -> V_41 ) ;
#ifdef F_105
V_21 -> V_29 . V_48 = F_18 ( sizeof( * V_21 -> V_29 . V_48 ) ,
V_178 ) ;
if ( ! V_21 -> V_29 . V_48 )
goto V_183;
V_21 -> V_29 . V_48 -> V_26 = V_184 ;
V_21 -> V_29 . V_48 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_48 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_48 -> V_41 ) ;
#endif
F_25 ( V_21 ) ;
return 0 ;
#ifdef F_105
V_183:
F_31 ( V_21 -> V_29 . V_47 ) ;
#endif
V_182:
F_31 ( V_21 -> V_29 . V_30 ) ;
V_181:
F_31 ( V_21 -> V_29 . V_126 ) ;
V_179:
return - V_73 ;
}
static void F_106 ( struct V_21 * V_21 )
{
F_107 ( V_21 , NULL ) ;
F_108 ( & V_21 -> V_29 . V_129 ) ;
#ifdef F_105
F_109 ( & V_21 -> V_29 . V_48 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_48 ) ;
#endif
F_109 ( & V_21 -> V_29 . V_47 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_47 ) ;
F_31 ( V_21 -> V_29 . V_30 ) ;
F_31 ( V_21 -> V_29 . V_126 ) ;
}
int T_9 F_110 ( void )
{
int V_185 = - V_73 ;
V_16 = F_111 ( L_18 ,
sizeof( struct V_14 ) ,
0 , V_186 ,
NULL ) ;
if ( ! V_16 )
goto V_76;
V_185 = F_112 ( & V_187 ) ;
if ( V_185 )
goto V_188;
V_185 = F_113 ( V_189 , V_190 , NULL , F_38 ,
NULL ) ;
if ( V_185 )
goto V_191;
V_76:
return V_185 ;
V_191:
F_114 ( & V_187 ) ;
V_188:
F_115 ( V_16 ) ;
goto V_76;
}
void F_116 ( void )
{
F_114 ( & V_187 ) ;
F_115 ( V_16 ) ;
}
