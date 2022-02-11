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
}
return V_32 ;
}
struct V_22 * F_19 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_22 * V_23 ;
if ( V_31 == 0 )
V_31 = V_41 ;
V_23 = F_20 ( V_21 , V_31 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_17 ( V_21 , V_31 ) ;
if ( V_23 )
F_14 ( V_21 , V_23 ) ;
return V_23 ;
}
struct V_22 * F_20 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_22 * V_23 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned int V_24 ;
if ( V_31 == 0 )
V_31 = V_41 ;
V_24 = V_31 & ( V_27 - 1 ) ;
F_21 () ;
V_43 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_22 (tb, node, head, tb6_hlist) {
if ( V_23 -> V_26 == V_31 ) {
F_23 () ;
return V_23 ;
}
}
F_23 () ;
return NULL ;
}
static void T_4 F_24 ( struct V_21 * V_21 )
{
F_14 ( V_21 , V_21 -> V_29 . V_46 ) ;
F_14 ( V_21 , V_21 -> V_29 . V_47 ) ;
}
struct V_22 * F_19 ( struct V_21 * V_21 , T_2 V_31 )
{
return F_20 ( V_21 , V_31 ) ;
}
struct V_22 * F_20 ( struct V_21 * V_21 , T_2 V_31 )
{
return V_21 -> V_29 . V_46 ;
}
struct V_48 * F_25 ( struct V_21 * V_21 , struct V_49 * V_50 ,
int V_51 , T_5 V_52 )
{
return (struct V_48 * ) V_52 ( V_21 , V_21 -> V_29 . V_46 , V_50 , V_51 ) ;
}
static void T_4 F_24 ( struct V_21 * V_21 )
{
F_14 ( V_21 , V_21 -> V_29 . V_46 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_17 * V_18 ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_54 ) {
V_53 = F_27 ( V_18 , V_2 -> args ) ;
if ( V_53 < 0 ) {
V_2 -> V_35 = V_18 ;
return 1 ;
}
F_28 ( V_53 == 0 ) ;
}
V_2 -> V_35 = NULL ;
return 0 ;
}
static void F_29 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = ( void * ) V_56 -> args [ 2 ] ;
if ( V_2 ) {
if ( V_56 -> args [ 4 ] ) {
V_56 -> args [ 4 ] = 0 ;
F_5 ( V_2 ) ;
}
V_56 -> args [ 2 ] = 0 ;
F_30 ( V_2 ) ;
}
V_56 -> V_57 = ( void * ) V_56 -> args [ 3 ] ;
V_56 -> args [ 1 ] = 3 ;
}
static int F_31 ( struct V_55 * V_56 )
{
F_29 ( V_56 ) ;
return V_56 -> V_57 ? V_56 -> V_57 ( V_56 ) : 0 ;
}
static int F_32 ( struct V_22 * V_32 , struct V_58 * V_59 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_53 ;
V_2 = ( void * ) V_56 -> args [ 2 ] ;
V_2 -> V_60 = & V_32 -> V_34 ;
if ( V_56 -> args [ 4 ] == 0 ) {
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
F_33 ( & V_32 -> V_25 ) ;
V_53 = F_34 ( V_2 ) ;
F_35 ( & V_32 -> V_25 ) ;
if ( V_53 > 0 ) {
V_56 -> args [ 4 ] = 1 ;
V_56 -> args [ 5 ] = V_2 -> V_60 -> V_63 ;
}
} else {
if ( V_56 -> args [ 5 ] != V_2 -> V_60 -> V_63 ) {
V_56 -> args [ 5 ] = V_2 -> V_60 -> V_63 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_45 = V_2 -> V_60 ;
V_2 -> V_62 = V_2 -> V_61 ;
} else
V_2 -> V_62 = 0 ;
F_33 ( & V_32 -> V_25 ) ;
V_53 = F_36 ( V_2 ) ;
F_35 ( & V_32 -> V_25 ) ;
if ( V_53 <= 0 ) {
F_5 ( V_2 ) ;
V_56 -> args [ 4 ] = 0 ;
}
}
return V_53 ;
}
static int F_37 ( struct V_58 * V_59 , struct V_55 * V_56 )
{
struct V_21 * V_21 = F_38 ( V_59 -> V_66 ) ;
unsigned int V_24 , V_67 ;
unsigned int V_68 = 0 , V_69 ;
struct V_70 V_71 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
int V_53 = 0 ;
V_67 = V_56 -> args [ 0 ] ;
V_69 = V_56 -> args [ 1 ] ;
V_2 = ( void * ) V_56 -> args [ 2 ] ;
if ( ! V_2 ) {
V_56 -> args [ 3 ] = ( long ) V_56 -> V_57 ;
V_56 -> V_57 = F_31 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_73 = F_26 ;
V_56 -> args [ 2 ] = ( long ) V_2 ;
}
V_71 . V_59 = V_59 ;
V_71 . V_56 = V_56 ;
V_71 . V_21 = V_21 ;
V_2 -> args = & V_71 ;
F_21 () ;
for ( V_24 = V_67 ; V_24 < V_27 ; V_24 ++ , V_69 = 0 ) {
V_68 = 0 ;
V_43 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_22 (tb, node, head, tb6_hlist) {
if ( V_68 < V_69 )
goto V_74;
V_53 = F_32 ( V_23 , V_59 , V_56 ) ;
if ( V_53 != 0 )
goto V_75;
V_74:
V_68 ++ ;
}
}
V_75:
F_23 () ;
V_56 -> args [ 1 ] = V_68 ;
V_56 -> args [ 0 ] = V_24 ;
V_53 = V_53 < 0 ? V_53 : V_59 -> V_76 ;
if ( V_53 <= 0 )
F_29 ( V_56 ) ;
return V_53 ;
}
static struct V_14 * F_39 ( struct V_14 * V_60 , void * V_11 ,
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
F_40 ( L_1 ) ;
V_15 = V_60 ;
do {
V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_41 ( & V_86 -> V_11 , V_11 , V_15 -> V_10 ) ) {
if ( ! V_80 ) {
if ( V_81 ) {
F_42 ( L_2
L_3 ) ;
return F_43 ( - V_91 ) ;
}
F_42 ( L_4
L_5 ) ;
}
goto V_92;
}
if ( V_78 == V_15 -> V_10 ) {
if ( ! ( V_15 -> V_37 & V_40 ) ) {
F_11 ( V_15 -> V_35 ) ;
V_15 -> V_35 = NULL ;
}
V_15 -> V_63 = V_89 ;
return V_15 ;
}
V_15 -> V_63 = V_89 ;
V_88 = F_8 ( V_11 , V_15 -> V_10 ) ;
V_84 = V_15 ;
V_15 = V_88 ? V_15 -> V_93 : V_15 -> V_94 ;
} while ( V_15 );
if ( ! V_80 ) {
if ( V_81 ) {
F_42 ( L_6 ) ;
return F_43 ( - V_91 ) ;
}
F_42 ( L_4
L_5 ) ;
}
V_83 = F_44 () ;
if ( ! V_83 )
return NULL ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_84 ;
V_83 -> V_63 = V_89 ;
if ( V_88 )
V_84 -> V_93 = V_83 ;
else
V_84 -> V_94 = V_83 ;
return V_83 ;
V_92:
V_84 = V_15 -> V_95 ;
V_87 = F_45 ( V_11 , & V_86 -> V_11 , V_77 ) ;
if ( V_78 > V_87 ) {
V_82 = F_44 () ;
V_83 = F_44 () ;
if ( ! V_82 || ! V_83 ) {
if ( V_82 )
F_9 ( V_82 ) ;
if ( V_83 )
F_9 ( V_83 ) ;
return NULL ;
}
V_82 -> V_10 = V_87 ;
V_82 -> V_95 = V_84 ;
V_82 -> V_35 = V_15 -> V_35 ;
F_46 ( & V_82 -> V_35 -> V_19 ) ;
V_82 -> V_63 = V_89 ;
if ( V_88 )
V_84 -> V_93 = V_82 ;
else
V_84 -> V_94 = V_82 ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_82 ;
V_15 -> V_95 = V_82 ;
V_83 -> V_63 = V_89 ;
if ( F_8 ( V_11 , V_87 ) ) {
V_82 -> V_93 = V_83 ;
V_82 -> V_94 = V_15 ;
} else {
V_82 -> V_94 = V_83 ;
V_82 -> V_93 = V_15 ;
}
} else {
V_83 = F_44 () ;
if ( ! V_83 )
return NULL ;
V_83 -> V_10 = V_78 ;
V_83 -> V_95 = V_84 ;
V_83 -> V_63 = V_89 ;
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
static int F_47 ( struct V_14 * V_15 , struct V_17 * V_18 ,
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
for ( V_98 = V_15 -> V_35 ; V_98 ; V_98 = V_98 -> V_20 . V_54 ) {
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
F_48 ( & V_98 -> V_112 ,
& V_18 -> V_112 ) ) {
if ( ! ( V_98 -> V_113 & V_114 ) )
return - V_109 ;
V_98 -> V_20 . V_115 = V_18 -> V_20 . V_115 ;
if ( ! ( V_18 -> V_113 & V_114 ) ) {
V_98 -> V_113 &= ~ V_114 ;
V_98 -> V_20 . V_115 = 0 ;
}
return - V_109 ;
}
}
if ( V_98 -> V_107 > V_18 -> V_107 )
break;
V_99 = & V_98 -> V_20 . V_54 ;
}
if ( V_99 == & V_15 -> V_35 )
V_15 -> V_116 = NULL ;
if ( ! V_100 ) {
if ( ! V_104 )
F_42 ( L_7 ) ;
V_104:
V_18 -> V_20 . V_54 = V_98 ;
* V_99 = V_18 ;
V_18 -> V_117 = V_15 ;
F_46 ( & V_18 -> V_19 ) ;
F_49 ( V_118 , V_18 , V_97 ) ;
V_97 -> V_119 -> V_29 . V_120 -> V_121 ++ ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_97 -> V_119 -> V_29 . V_120 -> V_122 ++ ;
V_15 -> V_37 |= V_40 ;
}
} else {
if ( ! V_106 ) {
if ( V_104 )
goto V_104;
F_42 ( L_8 ) ;
return - V_91 ;
}
* V_99 = V_18 ;
V_18 -> V_117 = V_15 ;
V_18 -> V_20 . V_54 = V_98 -> V_20 . V_54 ;
F_46 ( & V_18 -> V_19 ) ;
F_49 ( V_118 , V_18 , V_97 ) ;
F_11 ( V_98 ) ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_97 -> V_119 -> V_29 . V_120 -> V_122 ++ ;
V_15 -> V_37 |= V_40 ;
}
}
return 0 ;
}
static T_1 void F_50 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_51 ( & V_21 -> V_29 . V_123 ) &&
( V_18 -> V_113 & ( V_114 | V_124 ) ) )
F_52 ( & V_21 -> V_29 . V_123 ,
V_125 + V_21 -> V_29 . V_126 . V_127 ) ;
}
void F_53 ( struct V_21 * V_21 )
{
if ( ! F_51 ( & V_21 -> V_29 . V_123 ) )
F_52 ( & V_21 -> V_29 . V_123 ,
V_125 + V_21 -> V_29 . V_126 . V_127 ) ;
}
int F_54 ( struct V_14 * V_60 , struct V_17 * V_18 , struct V_96 * V_97 )
{
struct V_14 * V_15 , * V_84 = NULL ;
int V_128 = - V_72 ;
int V_80 = 1 ;
int V_81 = 0 ;
if ( V_97 -> V_101 ) {
if ( ! ( V_97 -> V_101 -> V_102 & V_105 ) )
V_80 = 0 ;
if ( V_97 -> V_101 -> V_102 & V_103 )
V_81 = 1 ;
}
if ( ! V_80 && ! V_81 )
F_42 ( L_9 ) ;
V_15 = F_39 ( V_60 , & V_18 -> V_129 . V_11 , sizeof( struct V_130 ) ,
V_18 -> V_129 . V_78 , F_55 ( struct V_17 , V_129 ) ,
V_80 , V_81 ) ;
if ( F_56 ( V_15 ) ) {
V_128 = F_57 ( V_15 ) ;
V_15 = NULL ;
}
if ( ! V_15 )
goto V_75;
V_84 = V_15 ;
#ifdef F_58
if ( V_18 -> V_131 . V_78 ) {
struct V_14 * V_132 ;
if ( ! V_15 -> V_133 ) {
struct V_14 * V_134 ;
V_134 = F_44 () ;
if ( ! V_134 )
goto V_135;
V_134 -> V_35 = V_97 -> V_119 -> V_29 . V_36 ;
F_46 ( & V_97 -> V_119 -> V_29 . V_36 -> V_19 ) ;
V_134 -> V_37 = V_38 ;
V_134 -> V_63 = F_7 () ;
V_132 = F_39 ( V_134 , & V_18 -> V_131 . V_11 ,
sizeof( struct V_130 ) , V_18 -> V_131 . V_78 ,
F_55 ( struct V_17 , V_131 ) ,
V_80 , V_81 ) ;
if ( ! V_132 ) {
F_9 ( V_134 ) ;
goto V_135;
}
V_134 -> V_95 = V_15 ;
V_15 -> V_133 = V_134 ;
} else {
V_132 = F_39 ( V_15 -> V_133 , & V_18 -> V_131 . V_11 ,
sizeof( struct V_130 ) , V_18 -> V_131 . V_78 ,
F_55 ( struct V_17 , V_131 ) ,
V_80 , V_81 ) ;
if ( F_56 ( V_132 ) ) {
V_128 = F_57 ( V_132 ) ;
V_132 = NULL ;
}
if ( ! V_132 )
goto V_135;
}
if ( ! V_15 -> V_35 ) {
V_15 -> V_35 = V_18 ;
F_46 ( & V_18 -> V_19 ) ;
}
V_15 = V_132 ;
}
#endif
V_128 = F_47 ( V_15 , V_18 , V_97 ) ;
if ( ! V_128 ) {
F_50 ( V_97 -> V_119 , V_18 ) ;
if ( ! ( V_18 -> V_113 & V_124 ) )
F_59 ( V_97 -> V_119 , V_84 , V_18 ) ;
}
V_75:
if ( V_128 ) {
#ifdef F_58
if ( V_84 != V_15 && V_84 -> V_35 == V_18 ) {
V_84 -> V_35 = NULL ;
F_60 ( & V_18 -> V_19 ) ;
}
if ( V_84 != V_15 && ! V_84 -> V_35 && ! ( V_84 -> V_37 & V_40 ) ) {
V_84 -> V_35 = F_61 ( V_97 -> V_119 , V_84 ) ;
#if V_136 >= 2
if ( ! V_84 -> V_35 ) {
F_28 ( V_84 -> V_35 == NULL ) ;
V_84 -> V_35 = V_97 -> V_119 -> V_29 . V_36 ;
}
#endif
F_46 ( & V_84 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_128 ;
#ifdef F_58
V_135:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_62 ( V_97 -> V_119 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_128 ;
#endif
}
static struct V_14 * F_63 ( struct V_14 * V_60 ,
struct V_137 * args )
{
struct V_14 * V_15 ;
T_3 V_88 ;
if ( F_64 ( args -> V_79 == 0 ) )
return NULL ;
V_15 = V_60 ;
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
if ( F_65 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 +
args -> V_79 ) ;
if ( F_41 ( & V_86 -> V_11 , args -> V_11 , V_86 -> V_78 ) ) {
#ifdef F_58
if ( V_15 -> V_133 )
V_15 = F_63 ( V_15 -> V_133 , args + 1 ) ;
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
struct V_14 * F_66 ( struct V_14 * V_60 , const struct V_130 * V_138 ,
const struct V_130 * V_139 )
{
struct V_14 * V_15 ;
struct V_137 args [] = {
{
. V_79 = F_55 ( struct V_17 , V_129 ) ,
. V_11 = V_138 ,
} ,
#ifdef F_58
{
. V_79 = F_55 ( struct V_17 , V_131 ) ,
. V_11 = V_139 ,
} ,
#endif
{
. V_79 = 0 ,
}
} ;
V_15 = F_63 ( V_60 , V_138 ? args : args + 1 ) ;
if ( ! V_15 || V_15 -> V_37 & V_39 )
V_15 = V_60 ;
return V_15 ;
}
static struct V_14 * F_67 ( struct V_14 * V_60 ,
const struct V_130 * V_11 ,
int V_78 , int V_79 )
{
struct V_14 * V_15 ;
for ( V_15 = V_60 ; V_15 ; ) {
struct V_85 * V_86 = (struct V_85 * ) ( ( V_90 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_41 ( & V_86 -> V_11 , V_11 , V_15 -> V_10 ) )
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
struct V_14 * F_68 ( struct V_14 * V_60 ,
const struct V_130 * V_138 , int V_140 ,
const struct V_130 * V_139 , int V_141 )
{
struct V_14 * V_15 ;
V_15 = F_67 ( V_60 , V_138 , V_140 ,
F_55 ( struct V_17 , V_129 ) ) ;
#ifdef F_58
if ( V_141 ) {
F_28 ( V_139 == NULL ) ;
if ( V_15 && V_15 -> V_133 )
V_15 = F_67 ( V_15 -> V_133 , V_139 , V_141 ,
F_55 ( struct V_17 , V_131 ) ) ;
}
#endif
if ( V_15 && V_15 -> V_37 & V_40 )
return V_15 ;
return NULL ;
}
static struct V_17 * F_61 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
if ( V_15 -> V_37 & V_38 )
return V_21 -> V_29 . V_36 ;
while ( V_15 ) {
if ( V_15 -> V_94 )
return V_15 -> V_94 -> V_35 ;
if ( V_15 -> V_93 )
return V_15 -> V_93 -> V_35 ;
V_15 = F_65 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_62 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_142 ;
int V_143 ;
struct V_14 * V_144 , * V_84 ;
struct V_1 * V_2 ;
int V_98 = 0 ;
for (; ; ) {
F_40 ( L_10 , V_15 -> V_10 , V_98 ) ;
V_98 ++ ;
F_28 ( V_15 -> V_37 & V_40 ) ;
F_28 ( V_15 -> V_37 & V_39 ) ;
F_28 ( V_15 -> V_35 != NULL ) ;
V_142 = 0 ;
V_144 = NULL ;
if ( V_15 -> V_93 ) V_144 = V_15 -> V_93 , V_142 |= 1 ;
if ( V_15 -> V_94 ) V_144 = V_15 -> V_94 , V_142 |= 2 ;
if ( V_142 == 3 || F_65 ( V_15 )
#ifdef F_58
|| ( V_142 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_61 ( V_21 , V_15 ) ;
#if V_136 >= 2
if ( ! V_15 -> V_35 ) {
F_28 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_46 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_95 ;
}
V_84 = V_15 -> V_95 ;
#ifdef F_58
if ( F_65 ( V_84 ) == V_15 ) {
F_28 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_65 ( V_84 ) = NULL ;
V_143 = V_145 ;
} else {
F_28 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_84 -> V_93 == V_15 ) V_84 -> V_93 = V_144 ;
else if ( V_84 -> V_94 == V_15 ) V_84 -> V_94 = V_144 ;
#if V_136 >= 2
else
F_28 ( 1 ) ;
#endif
if ( V_144 )
V_144 -> V_95 = V_84 ;
V_143 = V_146 ;
#ifdef F_58
}
#endif
F_69 ( & V_3 ) ;
F_70 (w) {
if ( ! V_144 ) {
if ( V_2 -> V_60 == V_15 ) {
V_2 -> V_60 = V_2 -> V_45 = NULL ;
F_40 ( L_11 , V_2 ) ;
} else if ( V_2 -> V_45 == V_15 ) {
F_40 ( L_12 , V_2 , V_2 -> V_64 , V_143 ) ;
V_2 -> V_45 = V_84 ;
V_2 -> V_64 = V_143 ;
}
} else {
if ( V_2 -> V_60 == V_15 ) {
V_2 -> V_60 = V_144 ;
F_40 ( L_13 , V_2 ) ;
}
if ( V_2 -> V_45 == V_15 ) {
V_2 -> V_45 = V_144 ;
if ( V_142 & 2 ) {
F_40 ( L_14 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_146 ? V_147 : V_65 ;
} else {
F_40 ( L_14 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_148 ? V_147 : V_65 ;
}
}
}
}
F_71 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_84 -> V_37 & V_40 || F_65 ( V_84 ) )
return V_84 ;
F_11 ( V_84 -> V_35 ) ;
V_84 -> V_35 = NULL ;
V_15 = V_84 ;
}
}
static void F_72 ( struct V_14 * V_15 , struct V_17 * * V_149 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_149 ;
struct V_21 * V_21 = V_97 -> V_119 ;
F_40 ( L_15 ) ;
* V_149 = V_18 -> V_20 . V_54 ;
V_18 -> V_117 = NULL ;
V_21 -> V_29 . V_120 -> V_121 -- ;
V_21 -> V_29 . V_120 -> V_150 ++ ;
if ( V_15 -> V_116 == V_18 )
V_15 -> V_116 = NULL ;
F_69 ( & V_3 ) ;
F_70 (w) {
if ( V_2 -> V_64 == V_148 && V_2 -> V_35 == V_18 ) {
F_40 ( L_16 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_54 ;
if ( ! V_2 -> V_35 )
V_2 -> V_64 = V_147 ;
}
}
F_71 ( & V_3 ) ;
V_18 -> V_20 . V_54 = NULL ;
if ( ! V_15 -> V_35 ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_120 -> V_122 -- ;
V_15 = F_62 ( V_21 , V_15 ) ;
}
if ( F_73 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_61 ( V_21 , V_15 ) ;
F_46 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_95 ;
}
F_74 ( F_73 ( & V_18 -> V_19 ) != 1 ) ;
}
F_49 ( V_151 , V_18 , V_97 ) ;
F_11 ( V_18 ) ;
}
int F_75 ( struct V_17 * V_18 , struct V_96 * V_97 )
{
struct V_21 * V_21 = V_97 -> V_119 ;
struct V_14 * V_15 = V_18 -> V_117 ;
struct V_17 * * V_149 ;
#if V_136 >= 2
if ( V_18 -> V_20 . V_152 > 0 ) {
F_28 ( V_15 != NULL ) ;
return - V_91 ;
}
#endif
if ( ! V_15 || V_18 == V_21 -> V_29 . V_36 )
return - V_91 ;
F_28 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_113 & V_124 ) ) {
struct V_14 * V_84 = V_15 ;
#ifdef F_58
if ( V_18 -> V_131 . V_78 ) {
while ( ! ( V_84 -> V_37 & V_38 ) )
V_84 = V_84 -> V_95 ;
V_84 = V_84 -> V_95 ;
}
#endif
F_59 ( V_97 -> V_119 , V_84 , V_18 ) ;
}
for ( V_149 = & V_15 -> V_35 ; * V_149 ; V_149 = & ( * V_149 ) -> V_20 . V_54 ) {
if ( * V_149 == V_18 ) {
F_72 ( V_15 , V_149 , V_97 ) ;
return 0 ;
}
}
return - V_91 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_84 ;
for (; ; ) {
V_15 = V_2 -> V_45 ;
if ( ! V_15 )
return 0 ;
if ( V_2 -> V_153 && V_15 != V_2 -> V_60 &&
V_15 -> V_37 & V_40 && V_2 -> V_64 < V_148 ) {
V_2 -> V_64 = V_148 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_64 ) {
#ifdef F_58
case V_154 :
if ( F_65 ( V_15 ) ) {
V_2 -> V_45 = F_65 ( V_15 ) ;
continue;
}
V_2 -> V_64 = V_145 ;
#endif
case V_145 :
if ( V_15 -> V_94 ) {
V_2 -> V_45 = V_15 -> V_94 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_146 ;
case V_146 :
if ( V_15 -> V_93 ) {
V_2 -> V_45 = V_15 -> V_93 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_148 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_148 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_128 ;
if ( V_2 -> V_61 < V_2 -> V_62 ) {
V_2 -> V_61 ++ ;
continue;
}
V_128 = V_2 -> V_73 ( V_2 ) ;
if ( V_128 )
return V_128 ;
V_2 -> V_61 ++ ;
continue;
}
V_2 -> V_64 = V_147 ;
case V_147 :
if ( V_15 == V_2 -> V_60 )
return 0 ;
V_84 = V_15 -> V_95 ;
V_2 -> V_45 = V_84 ;
#ifdef F_58
if ( F_65 ( V_84 ) == V_15 ) {
F_28 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_64 = V_145 ;
continue;
}
#endif
if ( V_84 -> V_94 == V_15 ) {
V_2 -> V_64 = V_146 ;
continue;
}
if ( V_84 -> V_93 == V_15 ) {
V_2 -> V_64 = V_148 ;
V_2 -> V_35 = V_2 -> V_45 -> V_35 ;
continue;
}
#if V_136 >= 2
F_28 ( 1 ) ;
#endif
}
}
}
static int F_34 ( struct V_1 * V_2 )
{
int V_53 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_45 = V_2 -> V_60 ;
F_1 ( V_2 ) ;
V_53 = F_36 ( V_2 ) ;
if ( V_53 <= 0 )
F_5 ( V_2 ) ;
return V_53 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_17 * V_18 ;
struct V_155 * V_156 = F_77 ( V_2 , struct V_155 , V_2 ) ;
struct V_96 V_97 = {
. V_119 = V_156 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_54 ) {
V_53 = V_156 -> V_73 ( V_18 , V_156 -> V_71 ) ;
if ( V_53 < 0 ) {
V_2 -> V_35 = V_18 ;
V_53 = F_75 ( V_18 , & V_97 ) ;
if ( V_53 ) {
#if V_136 >= 2
F_78 ( V_157 L_17 , V_18 , V_18 -> V_117 , V_53 ) ;
#endif
continue;
}
return 0 ;
}
F_28 ( V_53 != 0 ) ;
}
V_2 -> V_35 = V_18 ;
return 0 ;
}
static void F_79 ( struct V_21 * V_21 , struct V_14 * V_60 ,
int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_153 , void * V_71 )
{
struct V_155 V_156 ;
V_156 . V_2 . V_60 = V_60 ;
V_156 . V_2 . V_73 = F_76 ;
V_156 . V_2 . V_153 = V_153 ;
V_156 . V_2 . V_61 = 0 ;
V_156 . V_2 . V_62 = 0 ;
V_156 . V_73 = V_73 ;
V_156 . V_71 = V_71 ;
V_156 . V_21 = V_21 ;
F_34 ( & V_156 . V_2 ) ;
}
void F_80 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_153 , void * V_71 )
{
struct V_22 * V_32 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
unsigned int V_24 ;
F_21 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_43 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_22 (table, node, head, tb6_hlist) {
F_33 ( & V_32 -> V_25 ) ;
F_79 ( V_21 , & V_32 -> V_34 ,
V_73 , V_153 , V_71 ) ;
F_35 ( & V_32 -> V_25 ) ;
}
}
F_23 () ;
}
void F_81 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_153 , void * V_71 )
{
struct V_22 * V_32 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
unsigned int V_24 ;
F_21 () ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_43 = & V_21 -> V_29 . V_30 [ V_24 ] ;
F_22 (table, node, head, tb6_hlist) {
F_2 ( & V_32 -> V_25 ) ;
F_79 ( V_21 , & V_32 -> V_34 ,
V_73 , V_153 , V_71 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_23 () ;
}
static int F_82 ( struct V_17 * V_18 , void * V_71 )
{
if ( V_18 -> V_113 & V_124 ) {
F_40 ( L_18 , V_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_59 ( struct V_21 * V_21 , struct V_14 * V_15 ,
struct V_17 * V_18 )
{
F_79 ( V_21 , V_15 , F_82 , 1 , V_18 ) ;
}
static int F_83 ( struct V_17 * V_18 , void * V_71 )
{
unsigned long V_158 = V_125 ;
if ( V_18 -> V_113 & V_114 && V_18 -> V_20 . V_115 ) {
if ( F_84 ( V_158 , V_18 -> V_20 . V_115 ) ) {
F_40 ( L_19 , V_18 ) ;
return - 1 ;
}
V_159 . V_160 ++ ;
} else if ( V_18 -> V_113 & V_124 ) {
if ( F_73 ( & V_18 -> V_20 . V_161 ) == 0 &&
F_85 ( V_158 , V_18 -> V_20 . V_162 + V_159 . V_163 ) ) {
F_40 ( L_20 , V_18 ) ;
return - 1 ;
} else if ( ( V_18 -> V_113 & V_164 ) &&
( ! ( F_86 ( & V_18 -> V_20 ) -> V_51 & V_165 ) ) ) {
F_40 ( L_21 ,
V_18 ) ;
return - 1 ;
}
V_159 . V_160 ++ ;
}
return 0 ;
}
void F_87 ( unsigned long V_115 , struct V_21 * V_21 )
{
if ( V_115 != ~ 0UL ) {
F_88 ( & V_166 ) ;
V_159 . V_163 = V_115 ? ( int ) V_115 :
V_21 -> V_29 . V_126 . V_127 ;
} else {
if ( ! F_89 ( & V_166 ) ) {
F_52 ( & V_21 -> V_29 . V_123 , V_125 + V_167 ) ;
return;
}
V_159 . V_163 = V_21 -> V_29 . V_126 . V_127 ;
}
V_159 . V_160 = F_90 () ;
F_81 ( V_21 , F_83 , 0 , NULL ) ;
if ( V_159 . V_160 )
F_52 ( & V_21 -> V_29 . V_123 ,
F_91 ( V_125
+ V_21 -> V_29 . V_126 . V_127 ) ) ;
else
F_92 ( & V_21 -> V_29 . V_123 ) ;
F_93 ( & V_166 ) ;
}
static void F_94 ( unsigned long V_71 )
{
F_87 ( 0 , (struct V_21 * ) V_71 ) ;
}
static int T_4 F_95 ( struct V_21 * V_21 )
{
T_7 V_168 = sizeof( struct V_42 ) * V_27 ;
F_96 ( & V_21 -> V_29 . V_123 , F_94 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_120 = F_18 ( sizeof( * V_21 -> V_29 . V_120 ) , V_169 ) ;
if ( ! V_21 -> V_29 . V_120 )
goto V_170;
V_168 = F_97 ( T_7 , V_168 , V_171 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_168 , V_169 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_172;
V_21 -> V_29 . V_46 = F_18 ( sizeof( * V_21 -> V_29 . V_46 ) ,
V_169 ) ;
if ( ! V_21 -> V_29 . V_46 )
goto V_173;
V_21 -> V_29 . V_46 -> V_26 = V_41 ;
V_21 -> V_29 . V_46 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_46 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
#ifdef F_98
V_21 -> V_29 . V_47 = F_18 ( sizeof( * V_21 -> V_29 . V_47 ) ,
V_169 ) ;
if ( ! V_21 -> V_29 . V_47 )
goto V_174;
V_21 -> V_29 . V_47 -> V_26 = V_175 ;
V_21 -> V_29 . V_47 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_47 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
#endif
F_24 ( V_21 ) ;
return 0 ;
#ifdef F_98
V_174:
F_30 ( V_21 -> V_29 . V_46 ) ;
#endif
V_173:
F_30 ( V_21 -> V_29 . V_30 ) ;
V_172:
F_30 ( V_21 -> V_29 . V_120 ) ;
V_170:
return - V_72 ;
}
static void F_99 ( struct V_21 * V_21 )
{
F_100 ( V_21 , NULL ) ;
F_101 ( & V_21 -> V_29 . V_123 ) ;
#ifdef F_98
F_30 ( V_21 -> V_29 . V_47 ) ;
#endif
F_30 ( V_21 -> V_29 . V_46 ) ;
F_30 ( V_21 -> V_29 . V_30 ) ;
F_30 ( V_21 -> V_29 . V_120 ) ;
}
int T_8 F_102 ( void )
{
int V_176 = - V_72 ;
V_16 = F_103 ( L_22 ,
sizeof( struct V_14 ) ,
0 , V_177 ,
NULL ) ;
if ( ! V_16 )
goto V_75;
V_176 = F_104 ( & V_178 ) ;
if ( V_176 )
goto V_179;
V_176 = F_105 ( V_180 , V_181 , NULL , F_37 ,
NULL ) ;
if ( V_176 )
goto V_182;
V_75:
return V_176 ;
V_182:
F_106 ( & V_178 ) ;
V_179:
F_107 ( V_16 ) ;
goto V_75;
}
void F_108 ( void )
{
F_106 ( & V_178 ) ;
F_107 ( V_16 ) ;
}
