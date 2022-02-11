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
return NULL ;
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
return NULL ;
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
return NULL ;
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
if ( ! ( V_99 -> V_114 & V_115 ) )
return - V_110 ;
if ( ! ( V_18 -> V_114 & V_115 ) )
F_50 ( V_99 ) ;
else
F_51 ( V_99 , V_18 -> V_20 . V_116 ) ;
return - V_110 ;
}
}
if ( V_99 -> V_108 > V_18 -> V_108 )
break;
V_100 = & V_99 -> V_20 . V_55 ;
}
if ( V_100 == & V_15 -> V_35 )
V_15 -> V_117 = NULL ;
if ( ! V_101 ) {
if ( ! V_105 )
F_43 ( L_3 ) ;
V_105:
V_18 -> V_20 . V_55 = V_99 ;
* V_100 = V_18 ;
V_18 -> V_118 = V_15 ;
F_47 ( & V_18 -> V_19 ) ;
F_52 ( V_119 , V_18 , V_98 ) ;
V_98 -> V_120 -> V_29 . V_121 -> V_122 ++ ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_98 -> V_120 -> V_29 . V_121 -> V_123 ++ ;
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
V_18 -> V_118 = V_15 ;
V_18 -> V_20 . V_55 = V_99 -> V_20 . V_55 ;
F_47 ( & V_18 -> V_19 ) ;
F_52 ( V_119 , V_18 , V_98 ) ;
F_11 ( V_99 ) ;
if ( ! ( V_15 -> V_37 & V_40 ) ) {
V_98 -> V_120 -> V_29 . V_121 -> V_123 ++ ;
V_15 -> V_37 |= V_40 ;
}
}
return 0 ;
}
static T_1 void F_53 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_54 ( & V_21 -> V_29 . V_124 ) &&
( V_18 -> V_114 & ( V_115 | V_125 ) ) )
F_55 ( & V_21 -> V_29 . V_124 ,
V_126 + V_21 -> V_29 . V_127 . V_128 ) ;
}
void F_56 ( struct V_21 * V_21 )
{
if ( ! F_54 ( & V_21 -> V_29 . V_124 ) )
F_55 ( & V_21 -> V_29 . V_124 ,
V_126 + V_21 -> V_29 . V_127 . V_128 ) ;
}
int F_57 ( struct V_14 * V_61 , struct V_17 * V_18 , struct V_97 * V_98 )
{
struct V_14 * V_15 , * V_85 = NULL ;
int V_129 = - V_73 ;
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
V_15 = F_40 ( V_61 , & V_18 -> V_130 . V_11 , sizeof( struct V_131 ) ,
V_18 -> V_130 . V_79 , F_58 ( struct V_17 , V_130 ) ,
V_81 , V_82 ) ;
if ( F_59 ( V_15 ) ) {
V_129 = F_60 ( V_15 ) ;
V_15 = NULL ;
}
if ( ! V_15 )
goto V_76;
V_85 = V_15 ;
#ifdef F_61
if ( V_18 -> V_132 . V_79 ) {
struct V_14 * V_133 ;
if ( ! V_15 -> V_134 ) {
struct V_14 * V_135 ;
V_135 = F_45 () ;
if ( ! V_135 )
goto V_136;
V_135 -> V_35 = V_98 -> V_120 -> V_29 . V_36 ;
F_47 ( & V_98 -> V_120 -> V_29 . V_36 -> V_19 ) ;
V_135 -> V_37 = V_38 ;
V_135 -> V_64 = F_7 () ;
V_133 = F_40 ( V_135 , & V_18 -> V_132 . V_11 ,
sizeof( struct V_131 ) , V_18 -> V_132 . V_79 ,
F_58 ( struct V_17 , V_132 ) ,
V_81 , V_82 ) ;
if ( F_59 ( V_133 ) ) {
V_129 = F_60 ( V_133 ) ;
V_133 = NULL ;
}
if ( ! V_133 ) {
F_9 ( V_135 ) ;
goto V_136;
}
V_135 -> V_96 = V_15 ;
V_15 -> V_134 = V_135 ;
} else {
V_133 = F_40 ( V_15 -> V_134 , & V_18 -> V_132 . V_11 ,
sizeof( struct V_131 ) , V_18 -> V_132 . V_79 ,
F_58 ( struct V_17 , V_132 ) ,
V_81 , V_82 ) ;
if ( F_59 ( V_133 ) ) {
V_129 = F_60 ( V_133 ) ;
V_133 = NULL ;
}
if ( ! V_133 )
goto V_136;
}
if ( ! V_15 -> V_35 ) {
V_15 -> V_35 = V_18 ;
F_47 ( & V_18 -> V_19 ) ;
}
V_15 = V_133 ;
}
#endif
V_129 = F_48 ( V_15 , V_18 , V_98 ) ;
if ( ! V_129 ) {
F_53 ( V_98 -> V_120 , V_18 ) ;
if ( ! ( V_18 -> V_114 & V_125 ) )
F_62 ( V_98 -> V_120 , V_85 , V_18 ) ;
}
V_76:
if ( V_129 ) {
#ifdef F_61
if ( V_85 != V_15 && V_85 -> V_35 == V_18 ) {
V_85 -> V_35 = NULL ;
F_63 ( & V_18 -> V_19 ) ;
}
if ( V_85 != V_15 && ! V_85 -> V_35 && ! ( V_85 -> V_37 & V_40 ) ) {
V_85 -> V_35 = F_64 ( V_98 -> V_120 , V_85 ) ;
#if V_137 >= 2
if ( ! V_85 -> V_35 ) {
F_29 ( V_85 -> V_35 == NULL ) ;
V_85 -> V_35 = V_98 -> V_120 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_85 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_129 ;
#ifdef F_61
V_136:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_65 ( V_98 -> V_120 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_129 ;
#endif
}
static struct V_14 * F_66 ( struct V_14 * V_61 ,
struct V_138 * args )
{
struct V_14 * V_15 ;
T_3 V_89 ;
if ( F_67 ( args -> V_80 == 0 ) )
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
if ( F_68 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) ( ( V_91 * ) V_15 -> V_35 +
args -> V_80 ) ;
if ( F_42 ( & V_87 -> V_11 , args -> V_11 , V_87 -> V_79 ) ) {
#ifdef F_61
if ( V_15 -> V_134 )
V_15 = F_66 ( V_15 -> V_134 , args + 1 ) ;
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
struct V_14 * F_69 ( struct V_14 * V_61 , const struct V_131 * V_139 ,
const struct V_131 * V_140 )
{
struct V_14 * V_15 ;
struct V_138 args [] = {
{
. V_80 = F_58 ( struct V_17 , V_130 ) ,
. V_11 = V_139 ,
} ,
#ifdef F_61
{
. V_80 = F_58 ( struct V_17 , V_132 ) ,
. V_11 = V_140 ,
} ,
#endif
{
. V_80 = 0 ,
}
} ;
V_15 = F_66 ( V_61 , V_139 ? args : args + 1 ) ;
if ( ! V_15 || V_15 -> V_37 & V_39 )
V_15 = V_61 ;
return V_15 ;
}
static struct V_14 * F_70 ( struct V_14 * V_61 ,
const struct V_131 * V_11 ,
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
struct V_14 * F_71 ( struct V_14 * V_61 ,
const struct V_131 * V_139 , int V_141 ,
const struct V_131 * V_140 , int V_142 )
{
struct V_14 * V_15 ;
V_15 = F_70 ( V_61 , V_139 , V_141 ,
F_58 ( struct V_17 , V_130 ) ) ;
#ifdef F_61
if ( V_142 ) {
F_29 ( V_140 == NULL ) ;
if ( V_15 && V_15 -> V_134 )
V_15 = F_70 ( V_15 -> V_134 , V_140 , V_142 ,
F_58 ( struct V_17 , V_132 ) ) ;
}
#endif
if ( V_15 && V_15 -> V_37 & V_40 )
return V_15 ;
return NULL ;
}
static struct V_17 * F_64 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
if ( V_15 -> V_37 & V_38 )
return V_21 -> V_29 . V_36 ;
while ( V_15 ) {
if ( V_15 -> V_95 )
return V_15 -> V_95 -> V_35 ;
if ( V_15 -> V_94 )
return V_15 -> V_94 -> V_35 ;
V_15 = F_68 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_65 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_143 ;
int V_144 ;
struct V_14 * V_145 , * V_85 ;
struct V_1 * V_2 ;
int V_99 = 0 ;
for (; ; ) {
F_41 ( L_6 , V_15 -> V_10 , V_99 ) ;
V_99 ++ ;
F_29 ( V_15 -> V_37 & V_40 ) ;
F_29 ( V_15 -> V_37 & V_39 ) ;
F_29 ( V_15 -> V_35 != NULL ) ;
V_143 = 0 ;
V_145 = NULL ;
if ( V_15 -> V_94 ) V_145 = V_15 -> V_94 , V_143 |= 1 ;
if ( V_15 -> V_95 ) V_145 = V_15 -> V_95 , V_143 |= 2 ;
if ( V_143 == 3 || F_68 ( V_15 )
#ifdef F_61
|| ( V_143 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_64 ( V_21 , V_15 ) ;
#if V_137 >= 2
if ( ! V_15 -> V_35 ) {
F_29 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_47 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_96 ;
}
V_85 = V_15 -> V_96 ;
#ifdef F_61
if ( F_68 ( V_85 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_68 ( V_85 ) = NULL ;
V_144 = V_146 ;
} else {
F_29 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_85 -> V_94 == V_15 ) V_85 -> V_94 = V_145 ;
else if ( V_85 -> V_95 == V_15 ) V_85 -> V_95 = V_145 ;
#if V_137 >= 2
else
F_29 ( 1 ) ;
#endif
if ( V_145 )
V_145 -> V_96 = V_85 ;
V_144 = V_147 ;
#ifdef F_61
}
#endif
F_72 ( & V_3 ) ;
F_73 (w) {
if ( ! V_145 ) {
if ( V_2 -> V_61 == V_15 ) {
V_2 -> V_61 = V_2 -> V_46 = NULL ;
F_41 ( L_7 , V_2 ) ;
} else if ( V_2 -> V_46 == V_15 ) {
F_41 ( L_8 , V_2 , V_2 -> V_65 , V_144 ) ;
V_2 -> V_46 = V_85 ;
V_2 -> V_65 = V_144 ;
}
} else {
if ( V_2 -> V_61 == V_15 ) {
V_2 -> V_61 = V_145 ;
F_41 ( L_9 , V_2 ) ;
}
if ( V_2 -> V_46 == V_15 ) {
V_2 -> V_46 = V_145 ;
if ( V_143 & 2 ) {
F_41 ( L_10 , V_2 , V_2 -> V_65 ) ;
V_2 -> V_65 = V_2 -> V_65 >= V_147 ? V_148 : V_66 ;
} else {
F_41 ( L_10 , V_2 , V_2 -> V_65 ) ;
V_2 -> V_65 = V_2 -> V_65 >= V_149 ? V_148 : V_66 ;
}
}
}
}
F_74 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_85 -> V_37 & V_40 || F_68 ( V_85 ) )
return V_85 ;
F_11 ( V_85 -> V_35 ) ;
V_85 -> V_35 = NULL ;
V_15 = V_85 ;
}
}
static void F_75 ( struct V_14 * V_15 , struct V_17 * * V_150 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_150 ;
struct V_21 * V_21 = V_98 -> V_120 ;
F_41 ( L_11 ) ;
* V_150 = V_18 -> V_20 . V_55 ;
V_18 -> V_118 = NULL ;
V_21 -> V_29 . V_121 -> V_122 -- ;
V_21 -> V_29 . V_121 -> V_151 ++ ;
if ( V_15 -> V_117 == V_18 )
V_15 -> V_117 = NULL ;
F_72 ( & V_3 ) ;
F_73 (w) {
if ( V_2 -> V_65 == V_149 && V_2 -> V_35 == V_18 ) {
F_41 ( L_12 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_55 ;
if ( ! V_2 -> V_35 )
V_2 -> V_65 = V_148 ;
}
}
F_74 ( & V_3 ) ;
V_18 -> V_20 . V_55 = NULL ;
if ( ! V_15 -> V_35 ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_121 -> V_123 -- ;
V_15 = F_65 ( V_21 , V_15 ) ;
}
if ( F_76 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_64 ( V_21 , V_15 ) ;
F_47 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_96 ;
}
F_77 ( F_76 ( & V_18 -> V_19 ) != 1 ) ;
}
F_52 ( V_152 , V_18 , V_98 ) ;
F_11 ( V_18 ) ;
}
int F_78 ( struct V_17 * V_18 , struct V_97 * V_98 )
{
struct V_21 * V_21 = V_98 -> V_120 ;
struct V_14 * V_15 = V_18 -> V_118 ;
struct V_17 * * V_150 ;
#if V_137 >= 2
if ( V_18 -> V_20 . V_153 > 0 ) {
F_29 ( V_15 != NULL ) ;
return - V_92 ;
}
#endif
if ( ! V_15 || V_18 == V_21 -> V_29 . V_36 )
return - V_92 ;
F_29 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_114 & V_125 ) ) {
struct V_14 * V_85 = V_15 ;
#ifdef F_61
if ( V_18 -> V_132 . V_79 ) {
while ( ! ( V_85 -> V_37 & V_38 ) )
V_85 = V_85 -> V_96 ;
V_85 = V_85 -> V_96 ;
}
#endif
F_62 ( V_98 -> V_120 , V_85 , V_18 ) ;
}
for ( V_150 = & V_15 -> V_35 ; * V_150 ; V_150 = & ( * V_150 ) -> V_20 . V_55 ) {
if ( * V_150 == V_18 ) {
F_75 ( V_15 , V_150 , V_98 ) ;
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
if ( V_2 -> V_154 && V_15 != V_2 -> V_61 &&
V_15 -> V_37 & V_40 && V_2 -> V_65 < V_149 ) {
V_2 -> V_65 = V_149 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_65 ) {
#ifdef F_61
case V_155 :
if ( F_68 ( V_15 ) ) {
V_2 -> V_46 = F_68 ( V_15 ) ;
continue;
}
V_2 -> V_65 = V_146 ;
#endif
case V_146 :
if ( V_15 -> V_95 ) {
V_2 -> V_46 = V_15 -> V_95 ;
V_2 -> V_65 = V_66 ;
continue;
}
V_2 -> V_65 = V_147 ;
case V_147 :
if ( V_15 -> V_94 ) {
V_2 -> V_46 = V_15 -> V_94 ;
V_2 -> V_65 = V_66 ;
continue;
}
V_2 -> V_65 = V_149 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_149 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_129 ;
if ( V_2 -> V_63 ) {
V_2 -> V_63 -- ;
continue;
}
V_129 = V_2 -> V_74 ( V_2 ) ;
if ( V_129 )
return V_129 ;
V_2 -> V_62 ++ ;
continue;
}
V_2 -> V_65 = V_148 ;
case V_148 :
if ( V_15 == V_2 -> V_61 )
return 0 ;
V_85 = V_15 -> V_96 ;
V_2 -> V_46 = V_85 ;
#ifdef F_61
if ( F_68 ( V_85 ) == V_15 ) {
F_29 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_65 = V_146 ;
continue;
}
#endif
if ( V_85 -> V_95 == V_15 ) {
V_2 -> V_65 = V_147 ;
continue;
}
if ( V_85 -> V_94 == V_15 ) {
V_2 -> V_65 = V_149 ;
V_2 -> V_35 = V_2 -> V_46 -> V_35 ;
continue;
}
#if V_137 >= 2
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
static int F_79 ( struct V_1 * V_2 )
{
int V_54 ;
struct V_17 * V_18 ;
struct V_156 * V_157 = F_80 ( V_2 , struct V_156 , V_2 ) ;
struct V_97 V_98 = {
. V_120 = V_157 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_55 ) {
V_54 = V_157 -> V_74 ( V_18 , V_157 -> V_72 ) ;
if ( V_54 < 0 ) {
V_2 -> V_35 = V_18 ;
V_54 = F_78 ( V_18 , & V_98 ) ;
if ( V_54 ) {
#if V_137 >= 2
F_81 ( L_13 ,
V_158 , V_18 , V_18 -> V_118 , V_54 ) ;
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
static void F_82 ( struct V_21 * V_21 , struct V_14 * V_61 ,
int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_154 , void * V_72 )
{
struct V_156 V_157 ;
V_157 . V_2 . V_61 = V_61 ;
V_157 . V_2 . V_74 = F_79 ;
V_157 . V_2 . V_154 = V_154 ;
V_157 . V_2 . V_62 = 0 ;
V_157 . V_2 . V_63 = 0 ;
V_157 . V_74 = V_74 ;
V_157 . V_72 = V_72 ;
V_157 . V_21 = V_21 ;
F_35 ( & V_157 . V_2 ) ;
}
void F_83 ( struct V_21 * V_21 , int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_154 , void * V_72 )
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
F_82 ( V_21 , & V_32 -> V_34 ,
V_74 , V_154 , V_72 ) ;
F_36 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
void F_84 ( struct V_21 * V_21 , int (* V_74)( struct V_17 * , void * V_72 ) ,
int V_154 , void * V_72 )
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
F_82 ( V_21 , & V_32 -> V_34 ,
V_74 , V_154 , V_72 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_24 () ;
}
static int F_85 ( struct V_17 * V_18 , void * V_72 )
{
if ( V_18 -> V_114 & V_125 ) {
F_41 ( L_14 , V_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_62 ( struct V_21 * V_21 , struct V_14 * V_15 ,
struct V_17 * V_18 )
{
F_82 ( V_21 , V_15 , F_85 , 1 , V_18 ) ;
}
static int F_86 ( struct V_17 * V_18 , void * V_72 )
{
unsigned long V_159 = V_126 ;
if ( V_18 -> V_114 & V_115 && V_18 -> V_20 . V_116 ) {
if ( F_87 ( V_159 , V_18 -> V_20 . V_116 ) ) {
F_41 ( L_15 , V_18 ) ;
return - 1 ;
}
V_160 . V_161 ++ ;
} else if ( V_18 -> V_114 & V_125 ) {
if ( F_76 ( & V_18 -> V_20 . V_162 ) == 0 &&
F_88 ( V_159 , V_18 -> V_20 . V_163 + V_160 . V_164 ) ) {
F_41 ( L_16 , V_18 ) ;
return - 1 ;
} else if ( V_18 -> V_114 & V_165 ) {
struct V_166 * V_167 ;
T_7 V_168 = 0 ;
V_167 = F_89 ( & V_18 -> V_20 , & V_18 -> V_113 ) ;
if ( V_167 ) {
V_168 = V_167 -> V_52 ;
F_90 ( V_167 ) ;
}
if ( ! ( V_168 & V_169 ) ) {
F_41 ( L_17 ,
V_18 ) ;
return - 1 ;
}
}
V_160 . V_161 ++ ;
}
return 0 ;
}
void F_91 ( unsigned long V_116 , struct V_21 * V_21 )
{
if ( V_116 != ~ 0UL ) {
F_92 ( & V_170 ) ;
V_160 . V_164 = V_116 ? ( int ) V_116 :
V_21 -> V_29 . V_127 . V_128 ;
} else {
if ( ! F_93 ( & V_170 ) ) {
F_55 ( & V_21 -> V_29 . V_124 , V_126 + V_171 ) ;
return;
}
V_160 . V_164 = V_21 -> V_29 . V_127 . V_128 ;
}
V_160 . V_161 = F_94 () ;
F_84 ( V_21 , F_86 , 0 , NULL ) ;
if ( V_160 . V_161 )
F_55 ( & V_21 -> V_29 . V_124 ,
F_95 ( V_126
+ V_21 -> V_29 . V_127 . V_128 ) ) ;
else
F_96 ( & V_21 -> V_29 . V_124 ) ;
F_97 ( & V_170 ) ;
}
static void F_98 ( unsigned long V_72 )
{
F_91 ( 0 , (struct V_21 * ) V_72 ) ;
}
static int T_4 F_99 ( struct V_21 * V_21 )
{
T_8 V_172 = sizeof( struct V_43 ) * V_27 ;
F_100 ( & V_21 -> V_29 . V_124 , F_98 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_121 = F_18 ( sizeof( * V_21 -> V_29 . V_121 ) , V_173 ) ;
if ( ! V_21 -> V_29 . V_121 )
goto V_174;
V_172 = F_101 ( T_8 , V_172 , V_175 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_172 , V_173 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_176;
V_21 -> V_29 . V_47 = F_18 ( sizeof( * V_21 -> V_29 . V_47 ) ,
V_173 ) ;
if ( ! V_21 -> V_29 . V_47 )
goto V_177;
V_21 -> V_29 . V_47 -> V_26 = V_42 ;
V_21 -> V_29 . V_47 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_47 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_47 -> V_41 ) ;
#ifdef F_102
V_21 -> V_29 . V_48 = F_18 ( sizeof( * V_21 -> V_29 . V_48 ) ,
V_173 ) ;
if ( ! V_21 -> V_29 . V_48 )
goto V_178;
V_21 -> V_29 . V_48 -> V_26 = V_179 ;
V_21 -> V_29 . V_48 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_48 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
F_19 ( & V_21 -> V_29 . V_48 -> V_41 ) ;
#endif
F_25 ( V_21 ) ;
return 0 ;
#ifdef F_102
V_178:
F_31 ( V_21 -> V_29 . V_47 ) ;
#endif
V_177:
F_31 ( V_21 -> V_29 . V_30 ) ;
V_176:
F_31 ( V_21 -> V_29 . V_121 ) ;
V_174:
return - V_73 ;
}
static void F_103 ( struct V_21 * V_21 )
{
F_104 ( V_21 , NULL ) ;
F_105 ( & V_21 -> V_29 . V_124 ) ;
#ifdef F_102
F_106 ( & V_21 -> V_29 . V_48 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_48 ) ;
#endif
F_106 ( & V_21 -> V_29 . V_47 -> V_41 ) ;
F_31 ( V_21 -> V_29 . V_47 ) ;
F_31 ( V_21 -> V_29 . V_30 ) ;
F_31 ( V_21 -> V_29 . V_121 ) ;
}
int T_9 F_107 ( void )
{
int V_180 = - V_73 ;
V_16 = F_108 ( L_18 ,
sizeof( struct V_14 ) ,
0 , V_181 ,
NULL ) ;
if ( ! V_16 )
goto V_76;
V_180 = F_109 ( & V_182 ) ;
if ( V_180 )
goto V_183;
V_180 = F_110 ( V_184 , V_185 , NULL , F_38 ,
NULL ) ;
if ( V_180 )
goto V_186;
V_76:
return V_180 ;
V_186:
F_111 ( & V_182 ) ;
V_183:
F_112 ( V_16 ) ;
goto V_76;
}
void F_113 ( void )
{
F_111 ( & V_182 ) ;
F_112 ( V_16 ) ;
}
