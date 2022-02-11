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
static struct V_14 * F_40 ( struct V_14 * V_59 , void * V_11 ,
int V_77 , int V_78 ,
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
V_87 = F_46 ( V_11 , & V_86 -> V_11 , V_77 ) ;
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
static int F_48 ( struct V_14 * V_15 , struct V_17 * V_18 ,
struct V_96 * V_97 )
{
struct V_17 * V_98 = NULL ;
struct V_17 * * V_99 ;
int V_100 = ( V_97 -> V_101 &&
( V_97 -> V_101 -> V_102 & V_103 ) ) ;
int V_104 = ( ! V_97 -> V_101 ||
( V_97 -> V_101 -> V_102 & V_105 ) ) ;
int V_106 = 0 ;
V_99 = & V_15 -> V_35 ;
for ( V_98 = V_15 -> V_35 ; V_98 ; V_98 = V_98 -> V_20 . V_53 ) {
if ( V_98 -> V_107 == V_18 -> V_107 ) {
if ( V_97 -> V_101 &&
( V_97 -> V_101 -> V_102 & V_108 ) )
return - V_109 ;
if ( V_100 ) {
V_106 ++ ;
break;
}
if ( V_98 -> V_20 . V_110 == V_18 -> V_20 . V_110 &&
V_98 -> V_111 == V_18 -> V_111 &&
F_49 ( & V_98 -> V_112 ,
& V_18 -> V_112 ) ) {
if ( V_18 -> V_113 )
V_18 -> V_113 = 0 ;
if ( ! ( V_98 -> V_114 & V_115 ) )
return - V_109 ;
if ( ! ( V_18 -> V_114 & V_115 ) )
F_50 ( V_98 ) ;
else
F_51 ( V_98 , V_18 -> V_20 . V_116 ) ;
return - V_109 ;
}
if ( V_18 -> V_114 & V_117 &&
! ( V_18 -> V_114 & V_115 ) &&
! ( V_98 -> V_114 & V_115 ) )
V_18 -> V_113 ++ ;
}
if ( V_98 -> V_107 > V_18 -> V_107 )
break;
V_99 = & V_98 -> V_20 . V_53 ;
}
if ( V_99 == & V_15 -> V_35 )
V_15 -> V_118 = NULL ;
if ( V_18 -> V_113 ) {
unsigned int V_113 ;
struct V_17 * V_119 , * V_120 ;
V_119 = V_15 -> V_35 ;
while ( V_119 ) {
if ( V_119 -> V_107 == V_18 -> V_107 ) {
F_52 ( & V_18 -> V_121 ,
& V_119 -> V_121 ) ;
break;
}
V_119 = V_119 -> V_20 . V_53 ;
}
V_113 = 0 ;
F_53 (sibling, temp_sibling,
&rt->rt6i_siblings, rt6i_siblings) {
V_119 -> V_113 ++ ;
F_54 ( V_119 -> V_113 != V_18 -> V_113 ) ;
V_113 ++ ;
}
F_54 ( V_113 != V_18 -> V_113 ) ;
}
if ( ! V_100 ) {
if ( ! V_104 )
F_43 ( L_3 ) ;
V_104:
V_18 -> V_20 . V_53 = V_98 ;
* V_99 = V_18 ;
V_18 -> V_122 = V_15 ;
F_47 ( & V_18 -> V_19 ) ;
F_55 ( V_123 , V_18 , V_97 ) ;
V_97 -> V_124 -> V_29 . V_125 -> V_126 ++ ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_97 -> V_124 -> V_29 . V_125 -> V_127 ++ ;
V_15 -> V_37 |= V_40 ;
}
} else {
if ( ! V_106 ) {
if ( V_104 )
goto V_104;
F_43 ( L_4 ) ;
return - V_91 ;
}
* V_99 = V_18 ;
V_18 -> V_122 = V_15 ;
V_18 -> V_20 . V_53 = V_98 -> V_20 . V_53 ;
F_47 ( & V_18 -> V_19 ) ;
F_55 ( V_123 , V_18 , V_97 ) ;
F_11 ( V_98 ) ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_97 -> V_124 -> V_29 . V_125 -> V_127 ++ ;
V_15 -> V_37 |= V_40 ;
}
}
return 0 ;
}
static T_1 void F_56 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_57 ( & V_21 -> V_29 . V_128 ) &&
( V_18 -> V_114 & ( V_115 | V_129 ) ) )
F_58 ( & V_21 -> V_29 . V_128 ,
V_130 + V_21 -> V_29 . V_131 . V_132 ) ;
}
void F_59 ( struct V_21 * V_21 )
{
if ( ! F_57 ( & V_21 -> V_29 . V_128 ) )
F_58 ( & V_21 -> V_29 . V_128 ,
V_130 + V_21 -> V_29 . V_131 . V_132 ) ;
}
int F_60 ( struct V_14 * V_59 , struct V_17 * V_18 , struct V_96 * V_97 )
{
struct V_14 * V_15 , * V_84 = NULL ;
int V_133 = - V_72 ;
int V_80 = 1 ;
int V_81 = 0 ;
if ( V_97 -> V_101 ) {
if ( ! ( V_97 -> V_101 -> V_102 & V_105 ) )
V_80 = 0 ;
if ( V_97 -> V_101 -> V_102 & V_103 )
V_81 = 1 ;
}
if ( ! V_80 && ! V_81 )
F_43 ( L_5 ) ;
V_15 = F_40 ( V_59 , & V_18 -> V_134 . V_11 , sizeof( struct V_135 ) ,
V_18 -> V_134 . V_78 , F_61 ( struct V_17 , V_134 ) ,
V_80 , V_81 ) ;
if ( F_62 ( V_15 ) ) {
V_133 = F_63 ( V_15 ) ;
goto V_75;
}
V_84 = V_15 ;
#ifdef F_64
if ( V_18 -> V_136 . V_78 ) {
struct V_14 * V_137 ;
if ( ! V_15 -> V_138 ) {
struct V_14 * V_139 ;
V_139 = F_45 () ;
if ( ! V_139 )
goto V_140;
V_139 -> V_35 = V_97 -> V_124 -> V_29 . V_36 ;
F_47 ( & V_97 -> V_124 -> V_29 . V_36 -> V_19 ) ;
V_139 -> V_37 = V_38 ;
V_139 -> V_62 = F_7 () ;
V_137 = F_40 ( V_139 , & V_18 -> V_136 . V_11 ,
sizeof( struct V_135 ) , V_18 -> V_136 . V_78 ,
F_61 ( struct V_17 , V_136 ) ,
V_80 , V_81 ) ;
if ( F_62 ( V_137 ) ) {
F_9 ( V_139 ) ;
V_133 = F_63 ( V_137 ) ;
goto V_140;
}
V_139 -> V_95 = V_15 ;
V_15 -> V_138 = V_139 ;
} else {
V_137 = F_40 ( V_15 -> V_138 , & V_18 -> V_136 . V_11 ,
sizeof( struct V_135 ) , V_18 -> V_136 . V_78 ,
F_61 ( struct V_17 , V_136 ) ,
V_80 , V_81 ) ;
if ( F_62 ( V_137 ) ) {
V_133 = F_63 ( V_137 ) ;
goto V_140;
}
}
if ( ! V_15 -> V_35 ) {
V_15 -> V_35 = V_18 ;
F_47 ( & V_18 -> V_19 ) ;
}
V_15 = V_137 ;
}
#endif
V_133 = F_48 ( V_15 , V_18 , V_97 ) ;
if ( ! V_133 ) {
F_56 ( V_97 -> V_124 , V_18 ) ;
if ( ! ( V_18 -> V_114 & V_129 ) )
F_65 ( V_97 -> V_124 , V_84 , V_18 ) ;
}
V_75:
if ( V_133 ) {
#ifdef F_64
if ( V_84 != V_15 && V_84 -> V_35 == V_18 ) {
V_84 -> V_35 = NULL ;
F_66 ( & V_18 -> V_19 ) ;
}
if ( V_84 != V_15 && ! V_84 -> V_35 && ! ( V_84 -> V_37 & V_40 ) ) {
V_84 -> V_35 = F_67 ( V_97 -> V_124 , V_84 ) ;
#if V_141 >= 2
if ( ! V_84 -> V_35 ) {
F_29 ( V_84 -> V_35 == NULL ) ;
V_84 -> V_35 = V_97 -> V_124 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_84 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_133 ;
#ifdef F_64
V_140:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_68 ( V_97 -> V_124 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_133 ;
#endif
}
static struct V_14 * F_69 ( struct V_14 * V_59 ,
struct V_142 * args )
{
struct V_14 * V_15 ;
T_3 V_88 ;
if ( F_70 ( args -> V_79 == 0 ) )
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
if ( F_71 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 +
args -> V_79 ) ;
if ( F_42 ( & V_86 -> V_11 , args -> V_11 , V_86 -> V_78 ) ) {
#ifdef F_64
if ( V_15 -> V_138 )
V_15 = F_69 ( V_15 -> V_138 , args + 1 ) ;
#endif
if ( ! V_15 || V_15 -> V_37 & V_40 )
return V_15 ;
}
}
if ( V_15 -> V_37 & V_38 )
break;
V_15 = V_15 -> V_95 ;
}
return NULL ;
}
struct V_14 * F_72 ( struct V_14 * V_59 , const struct V_135 * V_143 ,
const struct V_135 * V_144 )
{
struct V_14 * V_15 ;
struct V_142 args [] = {
{
. V_79 = F_61 ( struct V_17 , V_134 ) ,
. V_11 = V_143 ,
} ,
#ifdef F_64
{
. V_79 = F_61 ( struct V_17 , V_136 ) ,
. V_11 = V_144 ,
} ,
#endif
{
. V_79 = 0 ,
}
} ;
V_15 = F_69 ( V_59 , V_143 ? args : args + 1 ) ;
if ( ! V_15 || V_15 -> V_37 & V_39 )
V_15 = V_59 ;
return V_15 ;
}
static struct V_14 * F_73 ( struct V_14 * V_59 ,
const struct V_135 * V_11 ,
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
struct V_14 * F_74 ( struct V_14 * V_59 ,
const struct V_135 * V_143 , int V_145 ,
const struct V_135 * V_144 , int V_146 )
{
struct V_14 * V_15 ;
V_15 = F_73 ( V_59 , V_143 , V_145 ,
F_61 ( struct V_17 , V_134 ) ) ;
#ifdef F_64
if ( V_146 ) {
F_29 ( V_144 == NULL ) ;
if ( V_15 && V_15 -> V_138 )
V_15 = F_73 ( V_15 -> V_138 , V_144 , V_146 ,
F_61 ( struct V_17 , V_136 ) ) ;
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
if ( V_15 -> V_94 )
return V_15 -> V_94 -> V_35 ;
if ( V_15 -> V_93 )
return V_15 -> V_93 -> V_35 ;
V_15 = F_71 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_68 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_147 ;
int V_148 ;
struct V_14 * V_149 , * V_84 ;
struct V_1 * V_2 ;
int V_98 = 0 ;
for (; ; ) {
F_41 ( L_6 , V_15 -> V_10 , V_98 ) ;
V_98 ++ ;
F_29 ( V_15 -> V_37 & V_40 ) ;
F_29 ( V_15 -> V_37 & V_39 ) ;
F_29 ( V_15 -> V_35 != NULL ) ;
V_147 = 0 ;
V_149 = NULL ;
if ( V_15 -> V_93 ) V_149 = V_15 -> V_93 , V_147 |= 1 ;
if ( V_15 -> V_94 ) V_149 = V_15 -> V_94 , V_147 |= 2 ;
if ( V_147 == 3 || F_71 ( V_15 )
#ifdef F_64
|| ( V_147 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_67 ( V_21 , V_15 ) ;
#if V_141 >= 2
if ( ! V_15 -> V_35 ) {
F_29 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_95 ;
}
V_84 = V_15 -> V_95 ;
#ifdef F_64
if ( F_71 ( V_84 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_71 ( V_84 ) = NULL ;
V_148 = V_150 ;
} else {
F_29 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_84 -> V_93 == V_15 ) V_84 -> V_93 = V_149 ;
else if ( V_84 -> V_94 == V_15 ) V_84 -> V_94 = V_149 ;
#if V_141 >= 2
else
F_29 ( 1 ) ;
#endif
if ( V_149 )
V_149 -> V_95 = V_84 ;
V_148 = V_151 ;
#ifdef F_64
}
#endif
F_75 ( & V_3 ) ;
F_76 (w) {
if ( ! V_149 ) {
if ( V_2 -> V_59 == V_15 ) {
V_2 -> V_59 = V_2 -> V_65 = NULL ;
F_41 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_65 == V_15 ) {
F_41 ( L_8 , V_2 , V_2 -> V_63 , V_148 ) ;
V_2 -> V_65 = V_84 ;
V_2 -> V_63 = V_148 ;
}
} else {
if ( V_2 -> V_59 == V_15 ) {
V_2 -> V_59 = V_149 ;
F_41 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_65 == V_15 ) {
V_2 -> V_65 = V_149 ;
if ( V_147 & 2 ) {
F_41 ( L_10 , V_2 , V_2 -> V_63 ) ;
V_2 -> V_63 = V_2 -> V_63 >= V_151 ? V_152 : V_64 ;
} else {
F_41 ( L_10 , V_2 , V_2 -> V_63 ) ;
V_2 -> V_63 = V_2 -> V_63 >= V_153 ? V_152 : V_64 ;
}
}
}
}
F_77 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_84 -> V_37 & V_40 || F_71 ( V_84 ) )
return V_84 ;
F_11 ( V_84 -> V_35 ) ;
V_84 -> V_35 = NULL ;
V_15 = V_84 ;
}
}
static void F_78 ( struct V_14 * V_15 , struct V_17 * * V_154 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_154 ;
struct V_21 * V_21 = V_97 -> V_124 ;
F_41 ( L_11 ) ;
* V_154 = V_18 -> V_20 . V_53 ;
V_18 -> V_122 = NULL ;
V_21 -> V_29 . V_125 -> V_126 -- ;
V_21 -> V_29 . V_125 -> V_155 ++ ;
if ( V_15 -> V_118 == V_18 )
V_15 -> V_118 = NULL ;
if ( V_18 -> V_113 ) {
struct V_17 * V_119 , * V_156 ;
F_53 (sibling, next_sibling,
&rt->rt6i_siblings, rt6i_siblings)
V_119 -> V_113 -- ;
V_18 -> V_113 = 0 ;
F_79 ( & V_18 -> V_121 ) ;
}
F_75 ( & V_3 ) ;
F_76 (w) {
if ( V_2 -> V_63 == V_153 && V_2 -> V_35 == V_18 ) {
F_41 ( L_12 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_53 ;
if ( ! V_2 -> V_35 )
V_2 -> V_63 = V_152 ;
}
}
F_77 ( & V_3 ) ;
V_18 -> V_20 . V_53 = NULL ;
if ( ! V_15 -> V_35 ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_125 -> V_127 -- ;
V_15 = F_68 ( V_21 , V_15 ) ;
}
if ( F_80 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_67 ( V_21 , V_15 ) ;
F_47 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_95 ;
}
F_54 ( F_80 ( & V_18 -> V_19 ) != 1 ) ;
}
F_55 ( V_157 , V_18 , V_97 ) ;
F_11 ( V_18 ) ;
}
int F_81 ( struct V_17 * V_18 , struct V_96 * V_97 )
{
struct V_21 * V_21 = V_97 -> V_124 ;
struct V_14 * V_15 = V_18 -> V_122 ;
struct V_17 * * V_154 ;
#if V_141 >= 2
if ( V_18 -> V_20 . V_158 > 0 ) {
F_29 ( V_15 != NULL ) ;
return - V_91 ;
}
#endif
if ( ! V_15 || V_18 == V_21 -> V_29 . V_36 )
return - V_91 ;
F_29 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_114 & V_129 ) ) {
struct V_14 * V_84 = V_15 ;
#ifdef F_64
if ( V_18 -> V_136 . V_78 ) {
while ( ! ( V_84 -> V_37 & V_38 ) )
V_84 = V_84 -> V_95 ;
V_84 = V_84 -> V_95 ;
}
#endif
F_65 ( V_97 -> V_124 , V_84 , V_18 ) ;
}
for ( V_154 = & V_15 -> V_35 ; * V_154 ; V_154 = & ( * V_154 ) -> V_20 . V_53 ) {
if ( * V_154 == V_18 ) {
F_78 ( V_15 , V_154 , V_97 ) ;
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
if ( V_2 -> V_159 && V_15 != V_2 -> V_59 &&
V_15 -> V_37 & V_40 && V_2 -> V_63 < V_153 ) {
V_2 -> V_63 = V_153 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_63 ) {
#ifdef F_64
case V_160 :
if ( F_71 ( V_15 ) ) {
V_2 -> V_65 = F_71 ( V_15 ) ;
continue;
}
V_2 -> V_63 = V_150 ;
#endif
case V_150 :
if ( V_15 -> V_94 ) {
V_2 -> V_65 = V_15 -> V_94 ;
V_2 -> V_63 = V_64 ;
continue;
}
V_2 -> V_63 = V_151 ;
case V_151 :
if ( V_15 -> V_93 ) {
V_2 -> V_65 = V_15 -> V_93 ;
V_2 -> V_63 = V_64 ;
continue;
}
V_2 -> V_63 = V_153 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_153 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_133 ;
if ( V_2 -> V_61 ) {
V_2 -> V_61 -- ;
continue;
}
V_133 = V_2 -> V_73 ( V_2 ) ;
if ( V_133 )
return V_133 ;
V_2 -> V_60 ++ ;
continue;
}
V_2 -> V_63 = V_152 ;
case V_152 :
if ( V_15 == V_2 -> V_59 )
return 0 ;
V_84 = V_15 -> V_95 ;
V_2 -> V_65 = V_84 ;
#ifdef F_64
if ( F_71 ( V_84 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_63 = V_150 ;
continue;
}
#endif
if ( V_84 -> V_94 == V_15 ) {
V_2 -> V_63 = V_151 ;
continue;
}
if ( V_84 -> V_93 == V_15 ) {
V_2 -> V_63 = V_153 ;
V_2 -> V_35 = V_2 -> V_65 -> V_35 ;
continue;
}
#if V_141 >= 2
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
static int F_82 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_17 * V_18 ;
struct V_161 * V_162 = F_83 ( V_2 , struct V_161 , V_2 ) ;
struct V_96 V_97 = {
. V_124 = V_162 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_53 ) {
V_52 = V_162 -> V_73 ( V_18 , V_162 -> V_71 ) ;
if ( V_52 < 0 ) {
V_2 -> V_35 = V_18 ;
V_52 = F_81 ( V_18 , & V_97 ) ;
if ( V_52 ) {
#if V_141 >= 2
F_84 ( L_13 ,
V_163 , V_18 , V_18 -> V_122 , V_52 ) ;
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
static void F_85 ( struct V_21 * V_21 , struct V_14 * V_59 ,
int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_159 , void * V_71 )
{
struct V_161 V_162 ;
V_162 . V_2 . V_59 = V_59 ;
V_162 . V_2 . V_73 = F_82 ;
V_162 . V_2 . V_159 = V_159 ;
V_162 . V_2 . V_60 = 0 ;
V_162 . V_2 . V_61 = 0 ;
V_162 . V_73 = V_73 ;
V_162 . V_71 = V_71 ;
V_162 . V_21 = V_21 ;
F_35 ( & V_162 . V_2 ) ;
}
void F_86 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_159 , void * V_71 )
{
struct V_22 * V_32 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
F_22 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (table, head, tb6_hlist) {
F_34 ( & V_32 -> V_25 ) ;
F_85 ( V_21 , & V_32 -> V_34 ,
V_73 , V_159 , V_71 ) ;
F_36 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
void F_87 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_159 , void * V_71 )
{
struct V_22 * V_32 ;
struct V_43 * V_44 ;
unsigned int V_24 ;
F_22 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_44 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_23 (table, head, tb6_hlist) {
F_2 ( & V_32 -> V_25 ) ;
F_85 ( V_21 , & V_32 -> V_34 ,
V_73 , V_159 , V_71 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
static int F_88 ( struct V_17 * V_18 , void * V_71 )
{
if ( V_18 -> V_114 & V_129 ) {
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
static int F_89 ( struct V_17 * V_18 , void * V_71 )
{
unsigned long V_164 = V_130 ;
if ( V_18 -> V_114 & V_115 && V_18 -> V_20 . V_116 ) {
if ( F_90 ( V_164 , V_18 -> V_20 . V_116 ) ) {
F_41 ( L_15 , V_18 ) ;
return - 1 ;
}
V_165 . V_166 ++ ;
} else if ( V_18 -> V_114 & V_129 ) {
if ( F_80 ( & V_18 -> V_20 . V_167 ) == 0 &&
F_91 ( V_164 , V_18 -> V_20 . V_168 + V_165 . V_169 ) ) {
F_41 ( L_16 , V_18 ) ;
return - 1 ;
} else if ( V_18 -> V_114 & V_117 ) {
struct V_170 * V_171 ;
T_7 V_172 = 0 ;
V_171 = F_92 ( & V_18 -> V_20 , & V_18 -> V_112 ) ;
if ( V_171 ) {
V_172 = V_171 -> V_50 ;
F_93 ( V_171 ) ;
}
if ( ! ( V_172 & V_173 ) ) {
F_41 ( L_17 ,
V_18 ) ;
return - 1 ;
}
}
V_165 . V_166 ++ ;
}
return 0 ;
}
void F_94 ( unsigned long V_116 , struct V_21 * V_21 )
{
if ( V_116 != ~ 0UL ) {
F_95 ( & V_174 ) ;
V_165 . V_169 = V_116 ? ( int ) V_116 :
V_21 -> V_29 . V_131 . V_132 ;
} else {
if ( ! F_96 ( & V_174 ) ) {
F_58 ( & V_21 -> V_29 . V_128 , V_130 + V_175 ) ;
return;
}
V_165 . V_169 = V_21 -> V_29 . V_131 . V_132 ;
}
V_165 . V_166 = F_97 () ;
F_87 ( V_21 , F_89 , 0 , NULL ) ;
if ( V_165 . V_166 )
F_58 ( & V_21 -> V_29 . V_128 ,
F_98 ( V_130
+ V_21 -> V_29 . V_131 . V_132 ) ) ;
else
F_99 ( & V_21 -> V_29 . V_128 ) ;
F_100 ( & V_174 ) ;
}
static void F_101 ( unsigned long V_71 )
{
F_94 ( 0 , (struct V_21 * ) V_71 ) ;
}
static int T_4 F_102 ( struct V_21 * V_21 )
{
T_8 V_176 = sizeof( struct V_43 ) * V_27 ;
F_103 ( & V_21 -> V_29 . V_128 , F_101 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_125 = F_18 ( sizeof( * V_21 -> V_29 . V_125 ) , V_177 ) ;
if ( ! V_21 -> V_29 . V_125 )
goto V_178;
V_176 = F_104 ( T_8 , V_176 , V_179 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_176 , V_177 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_180;
V_21 -> V_29 . V_45 = F_18 ( sizeof( * V_21 -> V_29 . V_45 ) ,
V_177 ) ;
if ( ! V_21 -> V_29 . V_45 )
goto V_181;
V_21 -> V_29 . V_45 -> V_26 = V_42 ;
V_21 -> V_29 . V_45 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_45 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_45 -> V_41 ) ;
#ifdef F_105
V_21 -> V_29 . V_46 = F_18 ( sizeof( * V_21 -> V_29 . V_46 ) ,
V_177 ) ;
if ( ! V_21 -> V_29 . V_46 )
goto V_182;
V_21 -> V_29 . V_46 -> V_26 = V_183 ;
V_21 -> V_29 . V_46 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_46 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_46 -> V_41 ) ;
#endif
F_25 ( V_21 ) ;
return 0 ;
#ifdef F_105
V_182:
F_31 ( V_21 -> V_29 . V_45 ) ;
#endif
V_181:
F_31 ( V_21 -> V_29 . V_30 ) ;
V_180:
F_31 ( V_21 -> V_29 . V_125 ) ;
V_178:
return - V_72 ;
}
static void F_106 ( struct V_21 * V_21 )
{
F_107 ( V_21 , NULL ) ;
F_108 ( & V_21 -> V_29 . V_128 ) ;
#ifdef F_105
F_109 ( & V_21 -> V_29 . V_46 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_46 ) ;
#endif
F_109 ( & V_21 -> V_29 . V_45 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_45 ) ;
F_31 ( V_21 -> V_29 . V_30 ) ;
F_31 ( V_21 -> V_29 . V_125 ) ;
}
int T_9 F_110 ( void )
{
int V_184 = - V_72 ;
V_16 = F_111 ( L_18 ,
sizeof( struct V_14 ) ,
0 , V_185 ,
NULL ) ;
if ( ! V_16 )
goto V_75;
V_184 = F_112 ( & V_186 ) ;
if ( V_184 )
goto V_187;
V_184 = F_113 ( V_188 , V_189 , NULL , F_38 ,
NULL ) ;
if ( V_184 )
goto V_190;
V_75:
return V_184 ;
V_190:
F_114 ( & V_186 ) ;
V_187:
F_115 ( V_16 ) ;
goto V_75;
}
void F_116 ( void )
{
F_114 ( & V_186 ) ;
F_115 ( V_16 ) ;
}
