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
if ( V_32 != NULL ) {
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
if ( V_23 != NULL )
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
if ( V_2 == NULL ) {
V_56 -> args [ 3 ] = ( long ) V_56 -> V_57 ;
V_56 -> V_57 = F_31 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( V_2 == NULL )
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
int V_79 )
{
struct V_14 * V_15 , * V_80 , * V_81 ;
struct V_14 * V_82 = NULL ;
struct V_83 * V_84 ;
int V_85 ;
T_3 V_86 = 0 ;
T_6 V_87 = F_7 () ;
F_40 ( L_1 ) ;
V_15 = V_60 ;
do {
V_84 = (struct V_83 * ) ( ( V_88 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_41 ( & V_84 -> V_11 , V_11 , V_15 -> V_10 ) )
goto V_89;
if ( V_78 == V_15 -> V_10 ) {
if ( ( V_15 -> V_37 & V_40 ) == 0 ) {
F_11 ( V_15 -> V_35 ) ;
V_15 -> V_35 = NULL ;
}
V_15 -> V_63 = V_87 ;
return V_15 ;
}
V_15 -> V_63 = V_87 ;
V_86 = F_8 ( V_11 , V_15 -> V_10 ) ;
V_82 = V_15 ;
V_15 = V_86 ? V_15 -> V_90 : V_15 -> V_91 ;
} while ( V_15 );
V_81 = F_42 () ;
if ( V_81 == NULL )
return NULL ;
V_81 -> V_10 = V_78 ;
V_81 -> V_92 = V_82 ;
V_81 -> V_63 = V_87 ;
if ( V_86 )
V_82 -> V_90 = V_81 ;
else
V_82 -> V_91 = V_81 ;
return V_81 ;
V_89:
V_82 = V_15 -> V_92 ;
V_85 = F_43 ( V_11 , & V_84 -> V_11 , V_77 ) ;
if ( V_78 > V_85 ) {
V_80 = F_42 () ;
V_81 = F_42 () ;
if ( V_80 == NULL || V_81 == NULL ) {
if ( V_80 )
F_9 ( V_80 ) ;
if ( V_81 )
F_9 ( V_81 ) ;
return NULL ;
}
V_80 -> V_10 = V_85 ;
V_80 -> V_92 = V_82 ;
V_80 -> V_35 = V_15 -> V_35 ;
F_44 ( & V_80 -> V_35 -> V_19 ) ;
V_80 -> V_63 = V_87 ;
if ( V_86 )
V_82 -> V_90 = V_80 ;
else
V_82 -> V_91 = V_80 ;
V_81 -> V_10 = V_78 ;
V_81 -> V_92 = V_80 ;
V_15 -> V_92 = V_80 ;
V_81 -> V_63 = V_87 ;
if ( F_8 ( V_11 , V_85 ) ) {
V_80 -> V_90 = V_81 ;
V_80 -> V_91 = V_15 ;
} else {
V_80 -> V_91 = V_81 ;
V_80 -> V_90 = V_15 ;
}
} else {
V_81 = F_42 () ;
if ( V_81 == NULL )
return NULL ;
V_81 -> V_10 = V_78 ;
V_81 -> V_92 = V_82 ;
V_81 -> V_63 = V_87 ;
if ( V_86 )
V_82 -> V_90 = V_81 ;
else
V_82 -> V_91 = V_81 ;
if ( F_8 ( & V_84 -> V_11 , V_78 ) )
V_81 -> V_90 = V_15 ;
else
V_81 -> V_91 = V_15 ;
V_15 -> V_92 = V_81 ;
}
return V_81 ;
}
static int F_45 ( struct V_14 * V_15 , struct V_17 * V_18 ,
struct V_93 * V_94 )
{
struct V_17 * V_95 = NULL ;
struct V_17 * * V_96 ;
V_96 = & V_15 -> V_35 ;
for ( V_95 = V_15 -> V_35 ; V_95 ; V_95 = V_95 -> V_20 . V_54 ) {
if ( V_95 -> V_97 == V_18 -> V_97 ) {
if ( V_95 -> V_98 == V_18 -> V_98 &&
V_95 -> V_99 == V_18 -> V_99 &&
F_46 ( & V_95 -> V_100 ,
& V_18 -> V_100 ) ) {
if ( ! ( V_95 -> V_101 & V_102 ) )
return - V_103 ;
V_95 -> V_104 = V_18 -> V_104 ;
if ( ! ( V_18 -> V_101 & V_102 ) ) {
V_95 -> V_101 &= ~ V_102 ;
V_95 -> V_104 = 0 ;
}
return - V_103 ;
}
}
if ( V_95 -> V_97 > V_18 -> V_97 )
break;
V_96 = & V_95 -> V_20 . V_54 ;
}
if ( V_96 == & V_15 -> V_35 )
V_15 -> V_105 = NULL ;
V_18 -> V_20 . V_54 = V_95 ;
* V_96 = V_18 ;
V_18 -> V_106 = V_15 ;
F_44 ( & V_18 -> V_19 ) ;
F_47 ( V_107 , V_18 , V_94 ) ;
V_94 -> V_108 -> V_29 . V_109 -> V_110 ++ ;
if ( ( V_15 -> V_37 & V_40 ) == 0 ) {
V_94 -> V_108 -> V_29 . V_109 -> V_111 ++ ;
V_15 -> V_37 |= V_40 ;
}
return 0 ;
}
static T_1 void F_48 ( struct V_21 * V_21 , struct V_17 * V_18 )
{
if ( ! F_49 ( & V_21 -> V_29 . V_112 ) &&
( V_18 -> V_101 & ( V_102 | V_113 ) ) )
F_50 ( & V_21 -> V_29 . V_112 ,
V_114 + V_21 -> V_29 . V_115 . V_116 ) ;
}
void F_51 ( struct V_21 * V_21 )
{
if ( ! F_49 ( & V_21 -> V_29 . V_112 ) )
F_50 ( & V_21 -> V_29 . V_112 ,
V_114 + V_21 -> V_29 . V_115 . V_116 ) ;
}
int F_52 ( struct V_14 * V_60 , struct V_17 * V_18 , struct V_93 * V_94 )
{
struct V_14 * V_15 , * V_82 = NULL ;
int V_117 = - V_72 ;
V_15 = F_39 ( V_60 , & V_18 -> V_118 . V_11 , sizeof( struct V_119 ) ,
V_18 -> V_118 . V_78 , F_53 ( struct V_17 , V_118 ) ) ;
if ( V_15 == NULL )
goto V_75;
V_82 = V_15 ;
#ifdef F_54
if ( V_18 -> V_120 . V_78 ) {
struct V_14 * V_121 ;
if ( V_15 -> V_122 == NULL ) {
struct V_14 * V_123 ;
V_123 = F_42 () ;
if ( V_123 == NULL )
goto V_124;
V_123 -> V_35 = V_94 -> V_108 -> V_29 . V_36 ;
F_44 ( & V_94 -> V_108 -> V_29 . V_36 -> V_19 ) ;
V_123 -> V_37 = V_38 ;
V_123 -> V_63 = F_7 () ;
V_121 = F_39 ( V_123 , & V_18 -> V_120 . V_11 ,
sizeof( struct V_119 ) , V_18 -> V_120 . V_78 ,
F_53 ( struct V_17 , V_120 ) ) ;
if ( V_121 == NULL ) {
F_9 ( V_123 ) ;
goto V_124;
}
V_123 -> V_92 = V_15 ;
V_15 -> V_122 = V_123 ;
} else {
V_121 = F_39 ( V_15 -> V_122 , & V_18 -> V_120 . V_11 ,
sizeof( struct V_119 ) , V_18 -> V_120 . V_78 ,
F_53 ( struct V_17 , V_120 ) ) ;
if ( V_121 == NULL )
goto V_124;
}
if ( V_15 -> V_35 == NULL ) {
V_15 -> V_35 = V_18 ;
F_44 ( & V_18 -> V_19 ) ;
}
V_15 = V_121 ;
}
#endif
V_117 = F_45 ( V_15 , V_18 , V_94 ) ;
if ( V_117 == 0 ) {
F_48 ( V_94 -> V_108 , V_18 ) ;
if ( ! ( V_18 -> V_101 & V_113 ) )
F_55 ( V_94 -> V_108 , V_82 , V_18 ) ;
}
V_75:
if ( V_117 ) {
#ifdef F_54
if ( V_82 != V_15 && V_82 -> V_35 == V_18 ) {
V_82 -> V_35 = NULL ;
F_56 ( & V_18 -> V_19 ) ;
}
if ( V_82 != V_15 && ! V_82 -> V_35 && ! ( V_82 -> V_37 & V_40 ) ) {
V_82 -> V_35 = F_57 ( V_94 -> V_108 , V_82 ) ;
#if V_125 >= 2
if ( ! V_82 -> V_35 ) {
F_28 ( V_82 -> V_35 == NULL ) ;
V_82 -> V_35 = V_94 -> V_108 -> V_29 . V_36 ;
}
#endif
F_44 ( & V_82 -> V_35 -> V_19 ) ;
}
#endif
F_13 ( & V_18 -> V_20 ) ;
}
return V_117 ;
#ifdef F_54
V_124:
if ( V_15 && ! ( V_15 -> V_37 & ( V_40 | V_38 ) ) )
F_58 ( V_94 -> V_108 , V_15 ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_117 ;
#endif
}
static struct V_14 * F_59 ( struct V_14 * V_60 ,
struct V_126 * args )
{
struct V_14 * V_15 ;
T_3 V_86 ;
if ( F_60 ( args -> V_79 == 0 ) )
return NULL ;
V_15 = V_60 ;
for (; ; ) {
struct V_14 * V_74 ;
V_86 = F_8 ( args -> V_11 , V_15 -> V_10 ) ;
V_74 = V_86 ? V_15 -> V_90 : V_15 -> V_91 ;
if ( V_74 ) {
V_15 = V_74 ;
continue;
}
break;
}
while( V_15 ) {
if ( F_61 ( V_15 ) || V_15 -> V_37 & V_40 ) {
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) ( ( V_88 * ) V_15 -> V_35 +
args -> V_79 ) ;
if ( F_41 ( & V_84 -> V_11 , args -> V_11 , V_84 -> V_78 ) ) {
#ifdef F_54
if ( V_15 -> V_122 )
V_15 = F_59 ( V_15 -> V_122 , args + 1 ) ;
#endif
if ( ! V_15 || V_15 -> V_37 & V_40 )
return V_15 ;
}
}
if ( V_15 -> V_37 & V_38 )
break;
V_15 = V_15 -> V_92 ;
}
return NULL ;
}
struct V_14 * F_62 ( struct V_14 * V_60 , const struct V_119 * V_127 ,
const struct V_119 * V_128 )
{
struct V_14 * V_15 ;
struct V_126 args [] = {
{
. V_79 = F_53 ( struct V_17 , V_118 ) ,
. V_11 = V_127 ,
} ,
#ifdef F_54
{
. V_79 = F_53 ( struct V_17 , V_120 ) ,
. V_11 = V_128 ,
} ,
#endif
{
. V_79 = 0 ,
}
} ;
V_15 = F_59 ( V_60 , V_127 ? args : args + 1 ) ;
if ( V_15 == NULL || V_15 -> V_37 & V_39 )
V_15 = V_60 ;
return V_15 ;
}
static struct V_14 * F_63 ( struct V_14 * V_60 ,
const struct V_119 * V_11 ,
int V_78 , int V_79 )
{
struct V_14 * V_15 ;
for ( V_15 = V_60 ; V_15 ; ) {
struct V_83 * V_84 = (struct V_83 * ) ( ( V_88 * ) V_15 -> V_35 + V_79 ) ;
if ( V_78 < V_15 -> V_10 ||
! F_41 ( & V_84 -> V_11 , V_11 , V_15 -> V_10 ) )
return NULL ;
if ( V_78 == V_15 -> V_10 )
return V_15 ;
if ( F_8 ( V_11 , V_15 -> V_10 ) )
V_15 = V_15 -> V_90 ;
else
V_15 = V_15 -> V_91 ;
}
return NULL ;
}
struct V_14 * F_64 ( struct V_14 * V_60 ,
const struct V_119 * V_127 , int V_129 ,
const struct V_119 * V_128 , int V_130 )
{
struct V_14 * V_15 ;
V_15 = F_63 ( V_60 , V_127 , V_129 ,
F_53 ( struct V_17 , V_118 ) ) ;
#ifdef F_54
if ( V_130 ) {
F_28 ( V_128 == NULL ) ;
if ( V_15 && V_15 -> V_122 )
V_15 = F_63 ( V_15 -> V_122 , V_128 , V_130 ,
F_53 ( struct V_17 , V_120 ) ) ;
}
#endif
if ( V_15 && V_15 -> V_37 & V_40 )
return V_15 ;
return NULL ;
}
static struct V_17 * F_57 ( struct V_21 * V_21 , struct V_14 * V_15 )
{
if ( V_15 -> V_37 & V_38 )
return V_21 -> V_29 . V_36 ;
while( V_15 ) {
if( V_15 -> V_91 )
return V_15 -> V_91 -> V_35 ;
if( V_15 -> V_90 )
return V_15 -> V_90 -> V_35 ;
V_15 = F_61 ( V_15 ) ;
}
return NULL ;
}
static struct V_14 * F_58 ( struct V_21 * V_21 ,
struct V_14 * V_15 )
{
int V_131 ;
int V_132 ;
struct V_14 * V_133 , * V_82 ;
struct V_1 * V_2 ;
int V_95 = 0 ;
for (; ; ) {
F_40 ( L_2 , V_15 -> V_10 , V_95 ) ;
V_95 ++ ;
F_28 ( V_15 -> V_37 & V_40 ) ;
F_28 ( V_15 -> V_37 & V_39 ) ;
F_28 ( V_15 -> V_35 != NULL ) ;
V_131 = 0 ;
V_133 = NULL ;
if ( V_15 -> V_90 ) V_133 = V_15 -> V_90 , V_131 |= 1 ;
if ( V_15 -> V_91 ) V_133 = V_15 -> V_91 , V_131 |= 2 ;
if ( V_131 == 3 || F_61 ( V_15 )
#ifdef F_54
|| ( V_131 && V_15 -> V_37 & V_38 )
#endif
) {
V_15 -> V_35 = F_57 ( V_21 , V_15 ) ;
#if V_125 >= 2
if ( V_15 -> V_35 == NULL ) {
F_28 ( ! V_15 -> V_35 ) ;
V_15 -> V_35 = V_21 -> V_29 . V_36 ;
}
#endif
F_44 ( & V_15 -> V_35 -> V_19 ) ;
return V_15 -> V_92 ;
}
V_82 = V_15 -> V_92 ;
#ifdef F_54
if ( F_61 ( V_82 ) == V_15 ) {
F_28 ( ! ( V_15 -> V_37 & V_38 ) ) ;
F_61 ( V_82 ) = NULL ;
V_132 = V_134 ;
} else {
F_28 ( V_15 -> V_37 & V_38 ) ;
#endif
if ( V_82 -> V_90 == V_15 ) V_82 -> V_90 = V_133 ;
else if ( V_82 -> V_91 == V_15 ) V_82 -> V_91 = V_133 ;
#if V_125 >= 2
else
F_28 ( 1 ) ;
#endif
if ( V_133 )
V_133 -> V_92 = V_82 ;
V_132 = V_135 ;
#ifdef F_54
}
#endif
F_65 ( & V_3 ) ;
F_66 (w) {
if ( V_133 == NULL ) {
if ( V_2 -> V_60 == V_15 ) {
V_2 -> V_60 = V_2 -> V_45 = NULL ;
F_40 ( L_3 , V_2 ) ;
} else if ( V_2 -> V_45 == V_15 ) {
F_40 ( L_4 , V_2 , V_2 -> V_64 , V_132 ) ;
V_2 -> V_45 = V_82 ;
V_2 -> V_64 = V_132 ;
}
} else {
if ( V_2 -> V_60 == V_15 ) {
V_2 -> V_60 = V_133 ;
F_40 ( L_5 , V_2 ) ;
}
if ( V_2 -> V_45 == V_15 ) {
V_2 -> V_45 = V_133 ;
if ( V_131 & 2 ) {
F_40 ( L_6 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_135 ? V_136 : V_65 ;
} else {
F_40 ( L_6 , V_2 , V_2 -> V_64 ) ;
V_2 -> V_64 = V_2 -> V_64 >= V_137 ? V_136 : V_65 ;
}
}
}
}
F_67 ( & V_3 ) ;
F_9 ( V_15 ) ;
if ( V_82 -> V_37 & V_40 || F_61 ( V_82 ) )
return V_82 ;
F_11 ( V_82 -> V_35 ) ;
V_82 -> V_35 = NULL ;
V_15 = V_82 ;
}
}
static void F_68 ( struct V_14 * V_15 , struct V_17 * * V_138 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = * V_138 ;
struct V_21 * V_21 = V_94 -> V_108 ;
F_40 ( L_7 ) ;
* V_138 = V_18 -> V_20 . V_54 ;
V_18 -> V_106 = NULL ;
V_21 -> V_29 . V_109 -> V_110 -- ;
V_21 -> V_29 . V_109 -> V_139 ++ ;
if ( V_15 -> V_105 == V_18 )
V_15 -> V_105 = NULL ;
F_65 ( & V_3 ) ;
F_66 (w) {
if ( V_2 -> V_64 == V_137 && V_2 -> V_35 == V_18 ) {
F_40 ( L_8 , V_2 ) ;
V_2 -> V_35 = V_18 -> V_20 . V_54 ;
if ( V_2 -> V_35 == NULL )
V_2 -> V_64 = V_136 ;
}
}
F_67 ( & V_3 ) ;
V_18 -> V_20 . V_54 = NULL ;
if ( V_15 -> V_35 == NULL ) {
V_15 -> V_37 &= ~ V_40 ;
V_21 -> V_29 . V_109 -> V_111 -- ;
V_15 = F_58 ( V_21 , V_15 ) ;
}
if ( F_69 ( & V_18 -> V_19 ) != 1 ) {
while ( V_15 ) {
if ( ! ( V_15 -> V_37 & V_40 ) && V_15 -> V_35 == V_18 ) {
V_15 -> V_35 = F_57 ( V_21 , V_15 ) ;
F_44 ( & V_15 -> V_35 -> V_19 ) ;
F_11 ( V_18 ) ;
}
V_15 = V_15 -> V_92 ;
}
F_70 ( F_69 ( & V_18 -> V_19 ) != 1 ) ;
}
F_47 ( V_140 , V_18 , V_94 ) ;
F_11 ( V_18 ) ;
}
int F_71 ( struct V_17 * V_18 , struct V_93 * V_94 )
{
struct V_21 * V_21 = V_94 -> V_108 ;
struct V_14 * V_15 = V_18 -> V_106 ;
struct V_17 * * V_138 ;
#if V_125 >= 2
if ( V_18 -> V_20 . V_141 > 0 ) {
F_28 ( V_15 != NULL ) ;
return - V_142 ;
}
#endif
if ( V_15 == NULL || V_18 == V_21 -> V_29 . V_36 )
return - V_142 ;
F_28 ( ! ( V_15 -> V_37 & V_40 ) ) ;
if ( ! ( V_18 -> V_101 & V_113 ) ) {
struct V_14 * V_82 = V_15 ;
#ifdef F_54
if ( V_18 -> V_120 . V_78 ) {
while ( ! ( V_82 -> V_37 & V_38 ) )
V_82 = V_82 -> V_92 ;
V_82 = V_82 -> V_92 ;
}
#endif
F_55 ( V_94 -> V_108 , V_82 , V_18 ) ;
}
for ( V_138 = & V_15 -> V_35 ; * V_138 ; V_138 = & ( * V_138 ) -> V_20 . V_54 ) {
if ( * V_138 == V_18 ) {
F_68 ( V_15 , V_138 , V_94 ) ;
return 0 ;
}
}
return - V_142 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_82 ;
for (; ; ) {
V_15 = V_2 -> V_45 ;
if ( V_15 == NULL )
return 0 ;
if ( V_2 -> V_143 && V_15 != V_2 -> V_60 &&
V_15 -> V_37 & V_40 && V_2 -> V_64 < V_137 ) {
V_2 -> V_64 = V_137 ;
V_2 -> V_35 = V_15 -> V_35 ;
}
switch ( V_2 -> V_64 ) {
#ifdef F_54
case V_144 :
if ( F_61 ( V_15 ) ) {
V_2 -> V_45 = F_61 ( V_15 ) ;
continue;
}
V_2 -> V_64 = V_134 ;
#endif
case V_134 :
if ( V_15 -> V_91 ) {
V_2 -> V_45 = V_15 -> V_91 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_135 ;
case V_135 :
if ( V_15 -> V_90 ) {
V_2 -> V_45 = V_15 -> V_90 ;
V_2 -> V_64 = V_65 ;
continue;
}
V_2 -> V_64 = V_137 ;
V_2 -> V_35 = V_15 -> V_35 ;
case V_137 :
if ( V_2 -> V_35 && V_15 -> V_37 & V_40 ) {
int V_117 ;
if ( V_2 -> V_61 < V_2 -> V_62 ) {
V_2 -> V_61 ++ ;
continue;
}
V_117 = V_2 -> V_73 ( V_2 ) ;
if ( V_117 )
return V_117 ;
V_2 -> V_61 ++ ;
continue;
}
V_2 -> V_64 = V_136 ;
case V_136 :
if ( V_15 == V_2 -> V_60 )
return 0 ;
V_82 = V_15 -> V_92 ;
V_2 -> V_45 = V_82 ;
#ifdef F_54
if ( F_61 ( V_82 ) == V_15 ) {
F_28 ( ! ( V_15 -> V_37 & V_38 ) ) ;
V_2 -> V_64 = V_134 ;
continue;
}
#endif
if ( V_82 -> V_91 == V_15 ) {
V_2 -> V_64 = V_135 ;
continue;
}
if ( V_82 -> V_90 == V_15 ) {
V_2 -> V_64 = V_137 ;
V_2 -> V_35 = V_2 -> V_45 -> V_35 ;
continue;
}
#if V_125 >= 2
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
static int F_72 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_17 * V_18 ;
struct V_145 * V_146 = F_73 ( V_2 , struct V_145 , V_2 ) ;
struct V_93 V_94 = {
. V_108 = V_146 -> V_21 ,
} ;
for ( V_18 = V_2 -> V_35 ; V_18 ; V_18 = V_18 -> V_20 . V_54 ) {
V_53 = V_146 -> V_73 ( V_18 , V_146 -> V_71 ) ;
if ( V_53 < 0 ) {
V_2 -> V_35 = V_18 ;
V_53 = F_71 ( V_18 , & V_94 ) ;
if ( V_53 ) {
#if V_125 >= 2
F_74 ( V_147 L_9 , V_18 , V_18 -> V_106 , V_53 ) ;
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
static void F_75 ( struct V_21 * V_21 , struct V_14 * V_60 ,
int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_143 , void * V_71 )
{
struct V_145 V_146 ;
V_146 . V_2 . V_60 = V_60 ;
V_146 . V_2 . V_73 = F_72 ;
V_146 . V_2 . V_143 = V_143 ;
V_146 . V_2 . V_61 = 0 ;
V_146 . V_2 . V_62 = 0 ;
V_146 . V_73 = V_73 ;
V_146 . V_71 = V_71 ;
V_146 . V_21 = V_21 ;
F_34 ( & V_146 . V_2 ) ;
}
void F_76 ( struct V_21 * V_21 , int (* V_73)( struct V_17 * , void * V_71 ) ,
int V_143 , void * V_71 )
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
F_75 ( V_21 , & V_32 -> V_34 ,
V_73 , V_143 , V_71 ) ;
F_4 ( & V_32 -> V_25 ) ;
}
}
F_23 () ;
}
static int F_77 ( struct V_17 * V_18 , void * V_71 )
{
if ( V_18 -> V_101 & V_113 ) {
F_40 ( L_10 , V_18 ) ;
return - 1 ;
}
return 0 ;
}
static void F_55 ( struct V_21 * V_21 , struct V_14 * V_15 ,
struct V_17 * V_18 )
{
F_75 ( V_21 , V_15 , F_77 , 1 , V_18 ) ;
}
static int F_78 ( struct V_17 * V_18 , void * V_71 )
{
unsigned long V_148 = V_114 ;
if ( V_18 -> V_101 & V_102 && V_18 -> V_104 ) {
if ( F_79 ( V_148 , V_18 -> V_104 ) ) {
F_40 ( L_11 , V_18 ) ;
return - 1 ;
}
V_149 . V_150 ++ ;
} else if ( V_18 -> V_101 & V_113 ) {
if ( F_69 ( & V_18 -> V_20 . V_151 ) == 0 &&
F_80 ( V_148 , V_18 -> V_20 . V_152 + V_149 . V_153 ) ) {
F_40 ( L_12 , V_18 ) ;
return - 1 ;
} else if ( ( V_18 -> V_101 & V_154 ) &&
( ! ( V_18 -> V_155 -> V_51 & V_156 ) ) ) {
F_40 ( L_13 ,
V_18 ) ;
return - 1 ;
}
V_149 . V_150 ++ ;
}
return 0 ;
}
void F_81 ( unsigned long V_157 , struct V_21 * V_21 )
{
if ( V_157 != ~ 0UL ) {
F_82 ( & V_158 ) ;
V_149 . V_153 = V_157 ? ( int ) V_157 :
V_21 -> V_29 . V_115 . V_116 ;
} else {
if ( ! F_83 ( & V_158 ) ) {
F_50 ( & V_21 -> V_29 . V_112 , V_114 + V_159 ) ;
return;
}
V_149 . V_153 = V_21 -> V_29 . V_115 . V_116 ;
}
V_149 . V_150 = F_84 () ;
F_76 ( V_21 , F_78 , 0 , NULL ) ;
if ( V_149 . V_150 )
F_50 ( & V_21 -> V_29 . V_112 ,
F_85 ( V_114
+ V_21 -> V_29 . V_115 . V_116 ) ) ;
else
F_86 ( & V_21 -> V_29 . V_112 ) ;
F_87 ( & V_158 ) ;
}
static void F_88 ( unsigned long V_71 )
{
F_81 ( 0 , (struct V_21 * ) V_71 ) ;
}
static int T_4 F_89 ( struct V_21 * V_21 )
{
T_7 V_160 = sizeof( struct V_42 ) * V_27 ;
F_90 ( & V_21 -> V_29 . V_112 , F_88 , ( unsigned long ) V_21 ) ;
V_21 -> V_29 . V_109 = F_18 ( sizeof( * V_21 -> V_29 . V_109 ) , V_161 ) ;
if ( ! V_21 -> V_29 . V_109 )
goto V_162;
V_160 = F_91 ( T_7 , V_160 , V_163 ) ;
V_21 -> V_29 . V_30 = F_18 ( V_160 , V_161 ) ;
if ( ! V_21 -> V_29 . V_30 )
goto V_164;
V_21 -> V_29 . V_46 = F_18 ( sizeof( * V_21 -> V_29 . V_46 ) ,
V_161 ) ;
if ( ! V_21 -> V_29 . V_46 )
goto V_165;
V_21 -> V_29 . V_46 -> V_26 = V_41 ;
V_21 -> V_29 . V_46 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_46 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
#ifdef F_92
V_21 -> V_29 . V_47 = F_18 ( sizeof( * V_21 -> V_29 . V_47 ) ,
V_161 ) ;
if ( ! V_21 -> V_29 . V_47 )
goto V_166;
V_21 -> V_29 . V_47 -> V_26 = V_167 ;
V_21 -> V_29 . V_47 -> V_34 . V_35 = V_21 -> V_29 . V_36 ;
V_21 -> V_29 . V_47 -> V_34 . V_37 =
V_38 | V_39 | V_40 ;
#endif
F_24 ( V_21 ) ;
return 0 ;
#ifdef F_92
V_166:
F_30 ( V_21 -> V_29 . V_46 ) ;
#endif
V_165:
F_30 ( V_21 -> V_29 . V_30 ) ;
V_164:
F_30 ( V_21 -> V_29 . V_109 ) ;
V_162:
return - V_72 ;
}
static void F_93 ( struct V_21 * V_21 )
{
F_94 ( V_21 , NULL ) ;
F_95 ( & V_21 -> V_29 . V_112 ) ;
#ifdef F_92
F_30 ( V_21 -> V_29 . V_47 ) ;
#endif
F_30 ( V_21 -> V_29 . V_46 ) ;
F_30 ( V_21 -> V_29 . V_30 ) ;
F_30 ( V_21 -> V_29 . V_109 ) ;
}
int T_8 F_96 ( void )
{
int V_168 = - V_72 ;
V_16 = F_97 ( L_14 ,
sizeof( struct V_14 ) ,
0 , V_169 ,
NULL ) ;
if ( ! V_16 )
goto V_75;
V_168 = F_98 ( & V_170 ) ;
if ( V_168 )
goto V_171;
V_168 = F_99 ( V_172 , V_173 , NULL , F_37 ) ;
if ( V_168 )
goto V_174;
V_75:
return V_168 ;
V_174:
F_100 ( & V_170 ) ;
V_171:
F_101 ( V_16 ) ;
goto V_75;
}
void F_102 ( void )
{
F_100 ( & V_170 ) ;
F_101 ( V_16 ) ;
}
