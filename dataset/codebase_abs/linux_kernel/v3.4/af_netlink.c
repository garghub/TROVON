static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_4 & V_5 ;
}
static inline T_1 F_4 ( T_1 V_6 )
{
return V_6 ? 1 << ( V_6 - 1 ) : 0 ;
}
static inline struct V_7 * F_5 ( struct V_8 * V_9 , T_1 V_10 )
{
return & V_9 -> V_11 [ F_6 ( V_10 , V_9 -> V_12 ) & V_9 -> V_13 ] ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_15 ) {
if ( V_14 -> V_15 -> V_16 )
V_14 -> V_15 -> V_16 ( V_14 -> V_15 ) ;
F_8 ( V_14 -> V_15 ) ;
}
F_9 ( & V_3 -> V_17 ) ;
if ( ! F_10 ( V_3 , V_18 ) ) {
F_11 ( V_19 L_1 , V_3 ) ;
return;
}
F_12 ( F_13 ( & V_3 -> V_20 ) ) ;
F_12 ( F_13 ( & V_3 -> V_21 ) ) ;
F_12 ( F_1 ( V_3 ) -> V_22 ) ;
}
void F_14 ( void )
__acquires( T_2 )
{
F_15 () ;
F_16 ( & T_2 ) ;
if ( F_13 ( & V_23 ) ) {
F_17 ( V_24 , V_25 ) ;
F_18 ( & V_26 , & V_24 ) ;
for (; ; ) {
F_19 ( V_27 ) ;
if ( F_13 ( & V_23 ) == 0 )
break;
F_20 ( & T_2 ) ;
F_21 () ;
F_16 ( & T_2 ) ;
}
F_22 ( V_28 ) ;
F_23 ( & V_26 , & V_24 ) ;
}
}
void F_24 ( void )
__releases( T_2 )
{
F_20 ( & T_2 ) ;
F_25 ( & V_26 ) ;
}
static inline void
F_26 ( void )
{
F_27 ( & T_2 ) ;
F_28 ( & V_23 ) ;
F_29 ( & T_2 ) ;
}
static inline void
F_30 ( void )
{
if ( F_31 ( & V_23 ) )
F_25 ( & V_26 ) ;
}
static struct V_2 * F_32 ( struct V_29 * V_29 , int V_30 , T_1 V_10 )
{
struct V_8 * V_9 = & V_31 [ V_30 ] . V_9 ;
struct V_7 * V_32 ;
struct V_2 * V_3 ;
struct V_33 * V_34 ;
F_27 ( & T_2 ) ;
V_32 = F_5 ( V_9 , V_10 ) ;
F_33 (sk, node, head) {
if ( F_34 ( F_35 ( V_3 ) , V_29 ) && ( F_1 ( V_3 ) -> V_10 == V_10 ) ) {
F_36 ( V_3 ) ;
goto V_35;
}
}
V_3 = NULL ;
V_35:
F_29 ( & T_2 ) ;
return V_3 ;
}
static struct V_7 * F_37 ( T_3 V_36 )
{
if ( V_36 <= V_37 )
return F_38 ( V_36 , V_38 ) ;
else
return (struct V_7 * )
F_39 ( V_38 | V_39 ,
F_40 ( V_36 ) ) ;
}
static void F_41 ( struct V_7 * V_11 , T_3 V_36 )
{
if ( V_36 <= V_37 )
F_42 ( V_11 ) ;
else
F_43 ( ( unsigned long ) V_11 , F_40 ( V_36 ) ) ;
}
static int F_44 ( struct V_8 * V_9 , int V_40 )
{
unsigned int V_41 , V_13 , V_42 ;
T_3 V_43 , V_36 ;
struct V_7 * V_44 , * V_11 ;
int V_45 ;
V_41 = V_13 = V_9 -> V_13 ;
V_43 = V_36 = ( V_13 + 1 ) * sizeof( * V_11 ) ;
V_42 = V_9 -> V_42 ;
if ( V_40 ) {
if ( ++ V_42 > V_9 -> V_46 )
return 0 ;
V_13 = V_13 * 2 + 1 ;
V_36 *= 2 ;
}
V_11 = F_37 ( V_36 ) ;
if ( ! V_11 )
return 0 ;
V_44 = V_9 -> V_11 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_42 = V_42 ;
F_45 ( & V_9 -> V_12 , sizeof( V_9 -> V_12 ) ) ;
for ( V_45 = 0 ; V_45 <= V_41 ; V_45 ++ ) {
struct V_2 * V_3 ;
struct V_33 * V_34 , * V_47 ;
F_46 (sk, node, tmp, &otable[i])
F_47 ( V_3 , F_5 ( V_9 , F_1 ( V_3 ) -> V_10 ) ) ;
}
F_41 ( V_44 , V_43 ) ;
V_9 -> V_48 = V_49 + 10 * 60 * V_50 ;
return 1 ;
}
static inline int F_48 ( struct V_8 * V_9 , int V_51 )
{
int V_52 = V_9 -> V_53 >> V_9 -> V_42 ;
if ( F_49 ( V_52 > 1 ) && F_44 ( V_9 , 1 ) )
return 1 ;
if ( F_49 ( V_51 > V_52 ) && F_50 ( V_49 , V_9 -> V_48 ) ) {
F_44 ( V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_51 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = & V_31 [ V_3 -> V_56 ] ;
struct V_33 * V_34 ;
unsigned long V_13 ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < F_52 ( V_55 -> V_22 ) ; V_45 ++ ) {
V_13 = 0 ;
F_53 (sk, node, &tbl->mc_list) {
if ( V_45 < F_52 ( F_1 ( V_3 ) -> V_57 ) )
V_13 |= F_1 ( V_3 ) -> V_22 [ V_45 ] ;
}
V_55 -> V_58 -> V_59 [ V_45 ] = V_13 ;
}
}
static int F_54 ( struct V_2 * V_3 , struct V_29 * V_29 , T_1 V_10 )
{
struct V_8 * V_9 = & V_31 [ V_3 -> V_56 ] . V_9 ;
struct V_7 * V_32 ;
int V_60 = - V_61 ;
struct V_2 * V_62 ;
struct V_33 * V_34 ;
int V_51 ;
F_14 () ;
V_32 = F_5 ( V_9 , V_10 ) ;
V_51 = 0 ;
F_33 (osk, node, head) {
if ( F_34 ( F_35 ( V_62 ) , V_29 ) && ( F_1 ( V_62 ) -> V_10 == V_10 ) )
break;
V_51 ++ ;
}
if ( V_34 )
goto V_60;
V_60 = - V_63 ;
if ( F_1 ( V_3 ) -> V_10 )
goto V_60;
V_60 = - V_64 ;
if ( V_65 > 32 && F_49 ( V_9 -> V_53 >= V_66 ) )
goto V_60;
if ( V_51 && F_48 ( V_9 , V_51 ) )
V_32 = F_5 ( V_9 , V_10 ) ;
V_9 -> V_53 ++ ;
F_1 ( V_3 ) -> V_10 = V_10 ;
F_55 ( V_3 , V_32 ) ;
V_60 = 0 ;
V_60:
F_24 () ;
return V_60 ;
}
static void F_56 ( struct V_2 * V_3 )
{
F_14 () ;
if ( F_57 ( V_3 ) )
V_31 [ V_3 -> V_56 ] . V_9 . V_53 -- ;
if ( F_1 ( V_3 ) -> V_67 )
F_58 ( V_3 ) ;
F_24 () ;
}
static int F_59 ( struct V_29 * V_29 , struct V_68 * V_2 ,
struct V_69 * V_70 , int V_30 )
{
struct V_2 * V_3 ;
struct V_1 * V_14 ;
V_2 -> V_71 = & V_72 ;
V_3 = F_60 ( V_29 , V_73 , V_74 , & V_75 ) ;
if ( ! V_3 )
return - V_64 ;
F_61 ( V_2 , V_3 ) ;
V_14 = F_1 ( V_3 ) ;
if ( V_70 )
V_14 -> V_70 = V_70 ;
else {
V_14 -> V_70 = & V_14 -> V_76 ;
F_62 ( V_14 -> V_70 ) ;
}
F_63 ( & V_14 -> V_24 ) ;
V_3 -> V_77 = F_7 ;
V_3 -> V_56 = V_30 ;
return 0 ;
}
static int F_64 ( struct V_29 * V_29 , struct V_68 * V_2 , int V_30 ,
int V_78 )
{
struct V_79 * V_79 = NULL ;
struct V_69 * V_70 ;
struct V_1 * V_14 ;
int V_60 = 0 ;
V_2 -> V_80 = V_81 ;
if ( V_2 -> type != V_82 && V_2 -> type != V_83 )
return - V_84 ;
if ( V_30 < 0 || V_30 >= V_85 )
return - V_86 ;
F_26 () ;
#ifdef F_65
if ( ! V_31 [ V_30 ] . V_87 ) {
F_30 () ;
F_66 ( L_2 , V_73 , V_30 ) ;
F_26 () ;
}
#endif
if ( V_31 [ V_30 ] . V_87 &&
F_67 ( V_31 [ V_30 ] . V_79 ) )
V_79 = V_31 [ V_30 ] . V_79 ;
else
V_60 = - V_86 ;
V_70 = V_31 [ V_30 ] . V_70 ;
F_30 () ;
if ( V_60 < 0 )
goto V_88;
V_60 = F_59 ( V_29 , V_2 , V_70 , V_30 ) ;
if ( V_60 < 0 )
goto V_89;
F_68 () ;
F_69 ( V_29 , & V_75 , 1 ) ;
F_70 () ;
V_14 = F_1 ( V_2 -> V_3 ) ;
V_14 -> V_79 = V_79 ;
V_88:
return V_60 ;
V_89:
F_71 ( V_79 ) ;
goto V_88;
}
static int F_72 ( struct V_68 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_56 ( V_3 ) ;
F_73 ( V_3 ) ;
V_14 = F_1 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_74 ( & V_14 -> V_24 ) ;
F_9 ( & V_3 -> V_90 ) ;
if ( V_14 -> V_10 ) {
struct V_91 V_92 = {
. V_29 = F_35 ( V_3 ) ,
. V_30 = V_3 -> V_56 ,
. V_10 = V_14 -> V_10 ,
} ;
F_75 ( & V_93 ,
V_94 , & V_92 ) ;
}
F_71 ( V_14 -> V_79 ) ;
F_14 () ;
if ( F_3 ( V_3 ) ) {
F_76 ( V_31 [ V_3 -> V_56 ] . V_87 == 0 ) ;
if ( -- V_31 [ V_3 -> V_56 ] . V_87 == 0 ) {
F_42 ( V_31 [ V_3 -> V_56 ] . V_58 ) ;
V_31 [ V_3 -> V_56 ] . V_79 = NULL ;
V_31 [ V_3 -> V_56 ] . V_87 = 0 ;
}
} else if ( V_14 -> V_67 )
F_51 ( V_3 ) ;
F_24 () ;
F_42 ( V_14 -> V_22 ) ;
V_14 -> V_22 = NULL ;
F_68 () ;
F_69 ( F_35 ( V_3 ) , & V_75 , - 1 ) ;
F_70 () ;
F_77 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_68 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_29 * V_29 = F_35 ( V_3 ) ;
struct V_8 * V_9 = & V_31 [ V_3 -> V_56 ] . V_9 ;
struct V_7 * V_32 ;
struct V_2 * V_62 ;
struct V_33 * V_34 ;
T_4 V_10 = F_79 ( V_25 ) ;
int V_60 ;
static T_4 V_95 = - 4097 ;
V_96:
F_80 () ;
F_14 () ;
V_32 = F_5 ( V_9 , V_10 ) ;
F_33 (osk, node, head) {
if ( ! F_34 ( F_35 ( V_62 ) , V_29 ) )
continue;
if ( F_1 ( V_62 ) -> V_10 == V_10 ) {
V_10 = V_95 -- ;
if ( V_95 > - 4097 )
V_95 = - 4097 ;
F_24 () ;
goto V_96;
}
}
F_24 () ;
V_60 = F_54 ( V_3 , V_29 , V_10 ) ;
if ( V_60 == - V_61 )
goto V_96;
if ( V_60 == - V_63 )
V_60 = 0 ;
return V_60 ;
}
static inline int F_81 ( const struct V_68 * V_2 , unsigned int V_97 )
{
return ( V_31 [ V_2 -> V_3 -> V_56 ] . V_98 & V_97 ) ||
F_82 ( V_99 ) ;
}
static void
F_83 ( struct V_2 * V_3 , unsigned int V_67 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_67 && ! V_67 )
F_58 ( V_3 ) ;
else if ( ! V_14 -> V_67 && V_67 )
F_84 ( V_3 , & V_31 [ V_3 -> V_56 ] . V_100 ) ;
V_14 -> V_67 = V_67 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_22 ;
unsigned long * V_101 ;
int V_60 = 0 ;
F_14 () ;
V_22 = V_31 [ V_3 -> V_56 ] . V_22 ;
if ( ! V_31 [ V_3 -> V_56 ] . V_87 ) {
V_60 = - V_102 ;
goto V_103;
}
if ( V_14 -> V_57 >= V_22 )
goto V_103;
V_101 = F_86 ( V_14 -> V_22 , F_87 ( V_22 ) , V_38 ) ;
if ( V_101 == NULL ) {
V_60 = - V_64 ;
goto V_103;
}
memset ( ( char * ) V_101 + F_87 ( V_14 -> V_57 ) , 0 ,
F_87 ( V_22 ) - F_87 ( V_14 -> V_57 ) ) ;
V_14 -> V_22 = V_101 ;
V_14 -> V_57 = V_22 ;
V_103:
F_24 () ;
return V_60 ;
}
static int F_88 ( struct V_68 * V_2 , struct V_104 * V_105 ,
int V_106 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_29 * V_29 = F_35 ( V_3 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
int V_60 ;
if ( V_108 -> V_109 != V_110 )
return - V_111 ;
if ( V_108 -> V_112 ) {
if ( ! F_81 ( V_2 , V_113 ) )
return - V_114 ;
V_60 = F_85 ( V_3 ) ;
if ( V_60 )
return V_60 ;
}
if ( V_14 -> V_10 ) {
if ( V_108 -> V_115 != V_14 -> V_10 )
return - V_111 ;
} else {
V_60 = V_108 -> V_115 ?
F_54 ( V_3 , V_29 , V_108 -> V_115 ) :
F_78 ( V_2 ) ;
if ( V_60 )
return V_60 ;
}
if ( ! V_108 -> V_112 && ( V_14 -> V_22 == NULL || ! ( T_1 ) V_14 -> V_22 [ 0 ] ) )
return 0 ;
F_14 () ;
F_83 ( V_3 , V_14 -> V_67 +
F_89 ( V_108 -> V_112 ) -
F_89 ( V_14 -> V_22 [ 0 ] ) ) ;
V_14 -> V_22 [ 0 ] = ( V_14 -> V_22 [ 0 ] & ~ 0xffffffffUL ) | V_108 -> V_112 ;
F_51 ( V_3 ) ;
F_24 () ;
return 0 ;
}
static int F_90 ( struct V_68 * V_2 , struct V_104 * V_105 ,
int V_116 , int V_4 )
{
int V_60 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
if ( V_116 < sizeof( V_105 -> V_117 ) )
return - V_111 ;
if ( V_105 -> V_117 == V_118 ) {
V_3 -> V_119 = V_120 ;
V_14 -> V_121 = 0 ;
V_14 -> V_122 = 0 ;
return 0 ;
}
if ( V_105 -> V_117 != V_110 )
return - V_111 ;
if ( V_108 -> V_112 && ! F_81 ( V_2 , V_123 ) )
return - V_114 ;
if ( ! V_14 -> V_10 )
V_60 = F_78 ( V_2 ) ;
if ( V_60 == 0 ) {
V_3 -> V_119 = V_124 ;
V_14 -> V_121 = V_108 -> V_115 ;
V_14 -> V_122 = F_91 ( V_108 -> V_112 ) ;
}
return V_60 ;
}
static int F_92 ( struct V_68 * V_2 , struct V_104 * V_105 ,
int * V_106 , int V_125 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_93 ( struct V_107 * , V_108 , V_105 ) ;
V_108 -> V_109 = V_110 ;
V_108 -> V_126 = 0 ;
* V_106 = sizeof( * V_108 ) ;
if ( V_125 ) {
V_108 -> V_115 = V_14 -> V_121 ;
V_108 -> V_112 = F_4 ( V_14 -> V_122 ) ;
} else {
V_108 -> V_115 = V_14 -> V_10 ;
V_108 -> V_112 = V_14 -> V_22 ? V_14 -> V_22 [ 0 ] : 0 ;
}
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( ! ( V_14 -> V_4 & V_127 ) ) {
if ( ! F_95 ( 0 , & F_1 ( V_3 ) -> V_80 ) ) {
V_3 -> V_128 = V_129 ;
V_3 -> V_130 ( V_3 ) ;
}
}
F_28 ( & V_3 -> V_131 ) ;
}
static struct V_2 * F_96 ( struct V_2 * V_132 , T_1 V_10 )
{
struct V_2 * V_2 ;
struct V_1 * V_14 ;
V_2 = F_32 ( F_35 ( V_132 ) , V_132 -> V_56 , V_10 ) ;
if ( ! V_2 )
return F_97 ( - V_133 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_2 -> V_119 == V_124 &&
V_14 -> V_121 != F_1 ( V_132 ) -> V_10 ) {
F_77 ( V_2 ) ;
return F_97 ( - V_133 ) ;
}
return V_2 ;
}
struct V_2 * F_98 ( struct V_134 * V_135 )
{
struct V_136 * V_136 = V_135 -> V_137 . V_138 -> V_139 ;
struct V_2 * V_2 ;
if ( ! F_99 ( V_136 -> V_140 ) )
return F_97 ( - V_141 ) ;
V_2 = F_100 ( V_136 ) -> V_3 ;
if ( V_2 -> V_142 != V_110 )
return F_97 ( - V_111 ) ;
F_36 ( V_2 ) ;
return V_2 ;
}
int F_101 ( struct V_2 * V_3 , struct V_143 * V_144 ,
long * V_145 , struct V_2 * V_132 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( F_13 ( & V_3 -> V_20 ) > V_3 -> V_146 ||
F_102 ( 0 , & V_14 -> V_80 ) ) {
F_17 ( V_24 , V_25 ) ;
if ( ! * V_145 ) {
if ( ! V_132 || F_3 ( V_132 ) )
F_94 ( V_3 ) ;
F_77 ( V_3 ) ;
F_103 ( V_144 ) ;
return - V_147 ;
}
F_22 ( V_148 ) ;
F_104 ( & V_14 -> V_24 , & V_24 ) ;
if ( ( F_13 ( & V_3 -> V_20 ) > V_3 -> V_146 ||
F_102 ( 0 , & V_14 -> V_80 ) ) &&
! F_10 ( V_3 , V_18 ) )
* V_145 = F_105 ( * V_145 ) ;
F_22 ( V_28 ) ;
F_23 ( & V_14 -> V_24 , & V_24 ) ;
F_77 ( V_3 ) ;
if ( F_106 ( V_25 ) ) {
F_103 ( V_144 ) ;
return F_107 ( * V_145 ) ;
}
return 1 ;
}
F_108 ( V_144 , V_3 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
int V_51 = V_144 -> V_51 ;
F_110 ( & V_3 -> V_17 , V_144 ) ;
V_3 -> V_149 ( V_3 , V_51 ) ;
return V_51 ;
}
int F_111 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
int V_51 = F_109 ( V_3 , V_144 ) ;
F_77 ( V_3 ) ;
return V_51 ;
}
void F_112 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
F_103 ( V_144 ) ;
F_77 ( V_3 ) ;
}
static struct V_143 * F_113 ( struct V_143 * V_144 , T_5 V_150 )
{
int V_151 ;
F_114 ( V_144 ) ;
V_151 = V_144 -> V_152 - V_144 -> V_153 ;
if ( V_151 * 2 < V_144 -> V_154 )
return V_144 ;
if ( F_115 ( V_144 ) ) {
struct V_143 * V_155 = F_116 ( V_144 , V_150 ) ;
if ( ! V_155 )
return V_144 ;
F_103 ( V_144 ) ;
V_144 = V_155 ;
}
if ( ! F_117 ( V_144 , 0 , - V_151 , V_150 ) )
V_144 -> V_154 -= V_151 ;
return V_144 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_119 ( & V_3 -> V_17 ) )
F_120 ( 0 , & V_14 -> V_80 ) ;
if ( ! F_102 ( 0 , & V_14 -> V_80 ) )
F_121 ( & V_14 -> V_24 ) ;
}
static int F_122 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
int V_156 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_156 = - V_133 ;
if ( V_14 -> V_157 != NULL ) {
V_156 = V_144 -> V_51 ;
F_108 ( V_144 , V_3 ) ;
V_14 -> V_157 ( V_144 ) ;
}
F_103 ( V_144 ) ;
F_77 ( V_3 ) ;
return V_156 ;
}
int F_123 ( struct V_2 * V_132 , struct V_143 * V_144 ,
T_1 V_10 , int V_158 )
{
struct V_2 * V_3 ;
int V_60 ;
long V_145 ;
V_144 = F_113 ( V_144 , F_124 () ) ;
V_145 = F_125 ( V_132 , V_158 ) ;
V_96:
V_3 = F_96 ( V_132 , V_10 ) ;
if ( F_126 ( V_3 ) ) {
F_103 ( V_144 ) ;
return F_127 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_122 ( V_3 , V_144 ) ;
if ( F_128 ( V_3 , V_144 ) ) {
V_60 = V_144 -> V_51 ;
F_103 ( V_144 ) ;
F_77 ( V_3 ) ;
return V_60 ;
}
V_60 = F_101 ( V_3 , V_144 , & V_145 , V_132 ) ;
if ( V_60 == 1 )
goto V_96;
if ( V_60 )
return V_60 ;
return F_111 ( V_3 , V_144 ) ;
}
int F_129 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_159 = 0 ;
struct V_58 * V_58 ;
F_76 ( ! F_3 ( V_3 ) ) ;
F_130 () ;
V_58 = F_131 ( V_31 [ V_3 -> V_56 ] . V_58 ) ;
if ( V_6 - 1 < V_31 [ V_3 -> V_56 ] . V_22 )
V_159 = F_102 ( V_6 - 1 , V_58 -> V_59 ) ;
F_132 () ;
return V_159 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_13 ( & V_3 -> V_20 ) <= V_3 -> V_146 &&
! F_102 ( 0 , & V_14 -> V_80 ) ) {
F_108 ( V_144 , V_3 ) ;
F_109 ( V_3 , V_144 ) ;
return F_13 ( & V_3 -> V_20 ) > ( V_3 -> V_146 >> 1 ) ;
}
return - 1 ;
}
static int F_134 ( struct V_2 * V_3 ,
struct V_160 * V_161 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_162 ;
if ( V_161 -> V_163 == V_3 )
goto V_88;
if ( V_14 -> V_10 == V_161 -> V_10 || V_161 -> V_6 - 1 >= V_14 -> V_57 ||
! F_102 ( V_161 -> V_6 - 1 , V_14 -> V_22 ) )
goto V_88;
if ( ! F_34 ( F_35 ( V_3 ) , V_161 -> V_29 ) )
goto V_88;
if ( V_161 -> V_164 ) {
F_94 ( V_3 ) ;
goto V_88;
}
F_36 ( V_3 ) ;
if ( V_161 -> V_165 == NULL ) {
if ( F_115 ( V_161 -> V_144 ) ) {
V_161 -> V_165 = F_116 ( V_161 -> V_144 , V_161 -> V_150 ) ;
} else {
V_161 -> V_165 = F_135 ( V_161 -> V_144 ) ;
F_114 ( V_161 -> V_165 ) ;
}
}
if ( V_161 -> V_165 == NULL ) {
F_94 ( V_3 ) ;
V_161 -> V_164 = 1 ;
if ( V_14 -> V_4 & V_166 )
V_161 -> V_167 = 1 ;
} else if ( V_161 -> V_168 && V_161 -> V_168 ( V_3 , V_161 -> V_165 , V_161 -> V_169 ) ) {
F_103 ( V_161 -> V_165 ) ;
V_161 -> V_165 = NULL ;
} else if ( F_128 ( V_3 , V_161 -> V_165 ) ) {
F_103 ( V_161 -> V_165 ) ;
V_161 -> V_165 = NULL ;
} else if ( ( V_162 = F_133 ( V_3 , V_161 -> V_165 ) ) < 0 ) {
F_94 ( V_3 ) ;
if ( V_14 -> V_4 & V_166 )
V_161 -> V_167 = 1 ;
} else {
V_161 -> V_170 |= V_162 ;
V_161 -> V_171 = 1 ;
V_161 -> V_165 = NULL ;
}
F_77 ( V_3 ) ;
V_88:
return 0 ;
}
int F_136 ( struct V_2 * V_132 , struct V_143 * V_144 , T_1 V_10 ,
T_1 V_6 , T_5 V_150 ,
int (* F_137)( struct V_2 * V_172 , struct V_143 * V_144 , void * V_173 ) ,
void * V_174 )
{
struct V_29 * V_29 = F_35 ( V_132 ) ;
struct V_160 V_175 ;
struct V_33 * V_34 ;
struct V_2 * V_3 ;
V_144 = F_113 ( V_144 , V_150 ) ;
V_175 . V_163 = V_132 ;
V_175 . V_29 = V_29 ;
V_175 . V_10 = V_10 ;
V_175 . V_6 = V_6 ;
V_175 . V_164 = 0 ;
V_175 . V_167 = 0 ;
V_175 . V_170 = 0 ;
V_175 . V_171 = 0 ;
V_175 . V_150 = V_150 ;
V_175 . V_144 = V_144 ;
V_175 . V_165 = NULL ;
V_175 . V_168 = F_137 ;
V_175 . V_169 = V_174 ;
F_26 () ;
F_53 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
F_134 ( V_3 , & V_175 ) ;
F_138 ( V_144 ) ;
F_30 () ;
if ( V_175 . V_167 ) {
F_103 ( V_175 . V_165 ) ;
return - V_129 ;
} else
F_138 ( V_175 . V_165 ) ;
if ( V_175 . V_171 ) {
if ( V_175 . V_170 && ( V_150 & V_176 ) )
F_139 () ;
return 0 ;
}
return - V_177 ;
}
int F_140 ( struct V_2 * V_132 , struct V_143 * V_144 , T_1 V_10 ,
T_1 V_6 , T_5 V_150 )
{
return F_136 ( V_132 , V_144 , V_10 , V_6 , V_150 ,
NULL , NULL ) ;
}
static int F_141 ( struct V_2 * V_3 , struct V_178 * V_161 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_156 = 0 ;
if ( V_3 == V_161 -> V_163 )
goto V_88;
if ( ! F_34 ( F_35 ( V_3 ) , F_35 ( V_161 -> V_163 ) ) )
goto V_88;
if ( V_14 -> V_10 == V_161 -> V_10 || V_161 -> V_6 - 1 >= V_14 -> V_57 ||
! F_102 ( V_161 -> V_6 - 1 , V_14 -> V_22 ) )
goto V_88;
if ( V_161 -> V_179 == V_129 && V_14 -> V_4 & V_127 ) {
V_156 = 1 ;
goto V_88;
}
V_3 -> V_128 = V_161 -> V_179 ;
V_3 -> V_130 ( V_3 ) ;
V_88:
return V_156 ;
}
int F_142 ( struct V_2 * V_132 , T_1 V_10 , T_1 V_6 , int V_179 )
{
struct V_178 V_175 ;
struct V_33 * V_34 ;
struct V_2 * V_3 ;
int V_156 = 0 ;
V_175 . V_163 = V_132 ;
V_175 . V_10 = V_10 ;
V_175 . V_6 = V_6 ;
V_175 . V_179 = - V_179 ;
F_27 ( & T_2 ) ;
F_53 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
V_156 += F_141 ( V_3 , & V_175 ) ;
F_29 ( & T_2 ) ;
return V_156 ;
}
static void F_143 ( struct V_1 * V_14 ,
unsigned int V_6 ,
int V_180 )
{
int V_181 , V_182 = ! ! V_180 , V_67 ;
V_181 = F_102 ( V_6 - 1 , V_14 -> V_22 ) ;
V_67 = V_14 -> V_67 - V_181 + V_182 ;
if ( V_182 )
F_144 ( V_6 - 1 , V_14 -> V_22 ) ;
else
F_145 ( V_6 - 1 , V_14 -> V_22 ) ;
F_83 ( & V_14 -> V_3 , V_67 ) ;
F_51 ( & V_14 -> V_3 ) ;
}
static int F_146 ( struct V_68 * V_2 , int V_183 , int V_184 ,
char T_6 * V_185 , unsigned int V_186 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_162 = 0 ;
int V_60 ;
if ( V_183 != V_187 )
return - V_188 ;
if ( V_186 >= sizeof( int ) &&
F_147 ( V_162 , ( unsigned int T_6 * ) V_185 ) )
return - V_189 ;
switch ( V_184 ) {
case V_190 :
if ( V_162 )
V_14 -> V_4 |= V_191 ;
else
V_14 -> V_4 &= ~ V_191 ;
V_60 = 0 ;
break;
case V_192 :
case V_193 : {
if ( ! F_81 ( V_2 , V_113 ) )
return - V_114 ;
V_60 = F_85 ( V_3 ) ;
if ( V_60 )
return V_60 ;
if ( ! V_162 || V_162 - 1 >= V_14 -> V_57 )
return - V_111 ;
F_14 () ;
F_143 ( V_14 , V_162 ,
V_184 == V_192 ) ;
F_24 () ;
V_60 = 0 ;
break;
}
case V_194 :
if ( V_162 )
V_14 -> V_4 |= V_166 ;
else
V_14 -> V_4 &= ~ V_166 ;
V_60 = 0 ;
break;
case V_195 :
if ( V_162 ) {
V_14 -> V_4 |= V_127 ;
F_120 ( 0 , & V_14 -> V_80 ) ;
F_121 ( & V_14 -> V_24 ) ;
} else
V_14 -> V_4 &= ~ V_127 ;
V_60 = 0 ;
break;
default:
V_60 = - V_188 ;
}
return V_60 ;
}
static int F_148 ( struct V_68 * V_2 , int V_183 , int V_184 ,
char T_6 * V_185 , int T_6 * V_186 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_51 , V_162 , V_60 ;
if ( V_183 != V_187 )
return - V_188 ;
if ( F_147 ( V_51 , V_186 ) )
return - V_189 ;
if ( V_51 < 0 )
return - V_111 ;
switch ( V_184 ) {
case V_190 :
if ( V_51 < sizeof( int ) )
return - V_111 ;
V_51 = sizeof( int ) ;
V_162 = V_14 -> V_4 & V_191 ? 1 : 0 ;
if ( F_149 ( V_51 , V_186 ) ||
F_149 ( V_162 , V_185 ) )
return - V_189 ;
V_60 = 0 ;
break;
case V_194 :
if ( V_51 < sizeof( int ) )
return - V_111 ;
V_51 = sizeof( int ) ;
V_162 = V_14 -> V_4 & V_166 ? 1 : 0 ;
if ( F_149 ( V_51 , V_186 ) ||
F_149 ( V_162 , V_185 ) )
return - V_189 ;
V_60 = 0 ;
break;
case V_195 :
if ( V_51 < sizeof( int ) )
return - V_111 ;
V_51 = sizeof( int ) ;
V_162 = V_14 -> V_4 & V_127 ? 1 : 0 ;
if ( F_149 ( V_51 , V_186 ) ||
F_149 ( V_162 , V_185 ) )
return - V_189 ;
V_60 = 0 ;
break;
default:
V_60 = - V_188 ;
}
return V_60 ;
}
static void F_150 ( struct V_196 * V_197 , struct V_143 * V_144 )
{
struct V_198 V_175 ;
V_175 . V_6 = F_151 ( V_144 ) . V_122 ;
F_152 ( V_197 , V_187 , V_190 , sizeof( V_175 ) , & V_175 ) ;
}
static int F_153 ( struct V_199 * V_199 , struct V_68 * V_2 ,
struct V_196 * V_197 , T_3 V_51 )
{
struct V_200 * V_201 = F_154 ( V_199 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_107 * V_105 = V_197 -> V_202 ;
T_1 V_121 ;
T_1 V_122 ;
struct V_143 * V_144 ;
int V_60 ;
struct V_203 V_204 ;
if ( V_197 -> V_205 & V_206 )
return - V_207 ;
if ( NULL == V_201 -> V_204 )
V_201 -> V_204 = & V_204 ;
V_60 = F_155 ( V_2 , V_197 , V_201 -> V_204 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_197 -> V_208 ) {
V_60 = - V_111 ;
if ( V_105 -> V_109 != V_110 )
goto V_88;
V_121 = V_105 -> V_115 ;
V_122 = F_91 ( V_105 -> V_112 ) ;
V_60 = - V_114 ;
if ( V_122 && ! F_81 ( V_2 , V_123 ) )
goto V_88;
} else {
V_121 = V_14 -> V_121 ;
V_122 = V_14 -> V_122 ;
}
if ( ! V_14 -> V_10 ) {
V_60 = F_78 ( V_2 ) ;
if ( V_60 )
goto V_88;
}
V_60 = - V_209 ;
if ( V_51 > V_3 -> V_210 - 32 )
goto V_88;
V_60 = - V_129 ;
V_144 = F_156 ( V_51 , V_74 ) ;
if ( V_144 == NULL )
goto V_88;
F_151 ( V_144 ) . V_10 = V_14 -> V_10 ;
F_151 ( V_144 ) . V_122 = V_122 ;
memcpy ( F_157 ( V_144 ) , & V_201 -> V_204 -> V_211 , sizeof( struct V_212 ) ) ;
V_60 = - V_189 ;
if ( F_158 ( F_159 ( V_144 , V_51 ) , V_197 -> V_213 , V_51 ) ) {
F_103 ( V_144 ) ;
goto V_88;
}
V_60 = F_160 ( V_3 , V_144 ) ;
if ( V_60 ) {
F_103 ( V_144 ) ;
goto V_88;
}
if ( V_122 ) {
F_28 ( & V_144 -> V_214 ) ;
F_140 ( V_3 , V_144 , V_121 , V_122 , V_74 ) ;
}
V_60 = F_123 ( V_3 , V_144 , V_121 , V_197 -> V_205 & V_215 ) ;
V_88:
F_161 ( V_201 -> V_204 ) ;
return V_60 ;
}
static int F_162 ( struct V_199 * V_199 , struct V_68 * V_2 ,
struct V_196 * V_197 , T_3 V_51 ,
int V_4 )
{
struct V_200 * V_201 = F_154 ( V_199 ) ;
struct V_203 V_204 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_216 = V_4 & V_215 ;
T_3 V_217 ;
struct V_143 * V_144 , * V_218 ;
int V_60 , V_156 ;
if ( V_4 & V_206 )
return - V_207 ;
V_217 = 0 ;
V_144 = F_163 ( V_3 , V_4 , V_216 , & V_60 ) ;
if ( V_144 == NULL )
goto V_88;
V_218 = V_144 ;
#ifdef F_164
if ( F_49 ( F_165 ( V_144 ) -> V_219 ) ) {
if ( V_4 & V_220 )
V_218 = F_165 ( V_144 ) -> V_219 ;
}
#endif
V_197 -> V_208 = 0 ;
V_217 = V_218 -> V_51 ;
if ( V_51 < V_217 ) {
V_197 -> V_205 |= V_221 ;
V_217 = V_51 ;
}
F_166 ( V_218 ) ;
V_60 = F_167 ( V_218 , 0 , V_197 -> V_213 , V_217 ) ;
if ( V_197 -> V_202 ) {
struct V_107 * V_105 = (struct V_107 * ) V_197 -> V_202 ;
V_105 -> V_109 = V_110 ;
V_105 -> V_126 = 0 ;
V_105 -> V_115 = F_151 ( V_144 ) . V_10 ;
V_105 -> V_112 = F_4 ( F_151 ( V_144 ) . V_122 ) ;
V_197 -> V_208 = sizeof( * V_105 ) ;
}
if ( V_14 -> V_4 & V_191 )
F_150 ( V_197 , V_144 ) ;
if ( NULL == V_201 -> V_204 ) {
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_201 -> V_204 = & V_204 ;
}
V_201 -> V_204 -> V_211 = * F_157 ( V_144 ) ;
if ( V_4 & V_221 )
V_217 = V_218 -> V_51 ;
F_168 ( V_3 , V_144 ) ;
if ( V_14 -> V_15 && F_13 ( & V_3 -> V_20 ) <= V_3 -> V_146 / 2 ) {
V_156 = F_169 ( V_3 ) ;
if ( V_156 ) {
V_3 -> V_128 = V_156 ;
V_3 -> V_130 ( V_3 ) ;
}
}
F_170 ( V_2 , V_197 , V_201 -> V_204 , V_4 ) ;
V_88:
F_118 ( V_3 ) ;
return V_60 ? : V_217 ;
}
static void F_171 ( struct V_2 * V_3 , int V_51 )
{
F_172 () ;
}
struct V_2 *
F_173 ( struct V_29 * V_29 , int V_222 , unsigned int V_22 ,
void (* F_174)( struct V_143 * V_144 ) ,
struct V_69 * V_70 , struct V_79 * V_79 )
{
struct V_68 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_14 ;
struct V_58 * V_58 = NULL ;
F_76 ( ! V_31 ) ;
if ( V_222 < 0 || V_222 >= V_85 )
return NULL ;
if ( F_175 ( V_73 , V_83 , V_222 , & V_2 ) )
return NULL ;
if ( F_59 ( & V_223 , V_2 , V_70 , V_222 ) < 0 )
goto V_224;
V_3 = V_2 -> V_3 ;
F_176 ( V_3 , V_29 ) ;
if ( V_22 < 32 )
V_22 = 32 ;
V_58 = F_38 ( sizeof( * V_58 ) + F_87 ( V_22 ) , V_74 ) ;
if ( ! V_58 )
goto V_225;
V_3 -> V_149 = F_171 ;
if ( F_174 )
F_1 ( V_3 ) -> V_157 = F_174 ;
if ( F_54 ( V_3 , V_29 , 0 ) )
goto V_225;
V_14 = F_1 ( V_3 ) ;
V_14 -> V_4 |= V_5 ;
F_14 () ;
if ( ! V_31 [ V_222 ] . V_87 ) {
V_31 [ V_222 ] . V_22 = V_22 ;
F_177 ( V_31 [ V_222 ] . V_58 , V_58 ) ;
V_31 [ V_222 ] . V_70 = V_70 ;
V_31 [ V_222 ] . V_79 = V_79 ;
V_31 [ V_222 ] . V_87 = 1 ;
} else {
F_42 ( V_58 ) ;
V_31 [ V_222 ] . V_87 ++ ;
}
F_24 () ;
return V_3 ;
V_225:
F_42 ( V_58 ) ;
F_178 ( V_3 ) ;
return NULL ;
V_224:
F_179 ( V_2 ) ;
return NULL ;
}
void
F_178 ( struct V_2 * V_3 )
{
F_180 ( V_3 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned int V_22 )
{
struct V_58 * V_182 , * V_181 ;
struct V_54 * V_55 = & V_31 [ V_3 -> V_56 ] ;
if ( V_22 < 32 )
V_22 = 32 ;
if ( F_87 ( V_55 -> V_22 ) < F_87 ( V_22 ) ) {
V_182 = F_38 ( sizeof( * V_182 ) + F_87 ( V_22 ) , V_38 ) ;
if ( ! V_182 )
return - V_64 ;
V_181 = F_182 ( V_55 -> V_58 , 1 ) ;
memcpy ( V_182 -> V_59 , V_181 -> V_59 , F_87 ( V_55 -> V_22 ) ) ;
F_177 ( V_55 -> V_58 , V_182 ) ;
F_183 ( V_181 , V_226 ) ;
}
V_55 -> V_22 = V_22 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , unsigned int V_22 )
{
int V_60 ;
F_14 () ;
V_60 = F_181 ( V_3 , V_22 ) ;
F_24 () ;
return V_60 ;
}
void F_185 ( struct V_2 * V_227 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_33 * V_34 ;
struct V_54 * V_55 = & V_31 [ V_227 -> V_56 ] ;
F_53 (sk, node, &tbl->mc_list)
F_143 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_186 ( struct V_2 * V_227 , unsigned int V_6 )
{
F_14 () ;
F_185 ( V_227 , V_6 ) ;
F_24 () ;
}
void F_187 ( int V_30 , unsigned int V_4 )
{
if ( ( unsigned int ) V_30 < V_85 )
V_31 [ V_30 ] . V_98 = V_4 ;
}
static void F_8 ( struct V_228 * V_15 )
{
F_103 ( V_15 -> V_144 ) ;
F_42 ( V_15 ) ;
}
struct V_229 *
F_188 ( struct V_143 * V_144 , T_1 V_10 , T_1 V_230 , int type , int V_51 , int V_4 )
{
struct V_229 * V_231 ;
int V_36 = F_189 ( V_51 ) ;
V_231 = (struct V_229 * ) F_159 ( V_144 , F_190 ( V_36 ) ) ;
V_231 -> V_232 = type ;
V_231 -> V_233 = V_36 ;
V_231 -> V_234 = V_4 ;
V_231 -> V_235 = V_10 ;
V_231 -> V_236 = V_230 ;
if ( ! F_191 ( V_36 ) || F_190 ( V_36 ) - V_36 != 0 )
memset ( F_192 ( V_231 ) + V_51 , 0 , F_190 ( V_36 ) - V_36 ) ;
return V_231 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_228 * V_15 ;
struct V_143 * V_144 = NULL ;
struct V_229 * V_231 ;
int V_51 , V_60 = - V_129 ;
int V_237 ;
F_193 ( V_14 -> V_70 ) ;
V_15 = V_14 -> V_15 ;
if ( V_15 == NULL ) {
V_60 = - V_111 ;
goto V_238;
}
V_237 = F_194 ( int , V_15 -> V_239 , V_240 ) ;
V_144 = F_195 ( V_3 , V_237 , 0 , V_74 ) ;
if ( ! V_144 )
goto V_238;
V_51 = V_15 -> V_241 ( V_144 , V_15 ) ;
if ( V_51 > 0 ) {
F_196 ( V_14 -> V_70 ) ;
if ( F_128 ( V_3 , V_144 ) )
F_103 ( V_144 ) ;
else
F_109 ( V_3 , V_144 ) ;
return 0 ;
}
V_231 = F_197 ( V_144 , V_15 , V_242 , sizeof( V_51 ) , V_243 ) ;
if ( ! V_231 )
goto V_238;
F_198 ( V_15 , V_231 ) ;
memcpy ( F_199 ( V_231 ) , & V_51 , sizeof( V_51 ) ) ;
if ( F_128 ( V_3 , V_144 ) )
F_103 ( V_144 ) ;
else
F_109 ( V_3 , V_144 ) ;
if ( V_15 -> V_16 )
V_15 -> V_16 ( V_15 ) ;
V_14 -> V_15 = NULL ;
F_196 ( V_14 -> V_70 ) ;
F_8 ( V_15 ) ;
return 0 ;
V_238:
F_196 ( V_14 -> V_70 ) ;
F_103 ( V_144 ) ;
return V_60 ;
}
int F_200 ( struct V_2 * V_132 , struct V_143 * V_144 ,
const struct V_229 * V_231 ,
struct V_244 * V_245 )
{
struct V_228 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_14 ;
int V_156 ;
V_15 = F_38 ( sizeof( * V_15 ) , V_74 ) ;
if ( V_15 == NULL )
return - V_129 ;
V_15 -> V_241 = V_245 -> V_241 ;
V_15 -> V_16 = V_245 -> V_16 ;
V_15 -> V_231 = V_231 ;
V_15 -> V_173 = V_245 -> V_173 ;
V_15 -> V_239 = V_245 -> V_239 ;
F_28 ( & V_144 -> V_214 ) ;
V_15 -> V_144 = V_144 ;
V_3 = F_32 ( F_35 ( V_132 ) , V_132 -> V_56 , F_151 ( V_144 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_8 ( V_15 ) ;
return - V_133 ;
}
V_14 = F_1 ( V_3 ) ;
F_193 ( V_14 -> V_70 ) ;
if ( V_14 -> V_15 ) {
F_196 ( V_14 -> V_70 ) ;
F_8 ( V_15 ) ;
F_77 ( V_3 ) ;
return - V_63 ;
}
V_14 -> V_15 = V_15 ;
F_196 ( V_14 -> V_70 ) ;
V_156 = F_169 ( V_3 ) ;
F_77 ( V_3 ) ;
if ( V_156 )
return V_156 ;
return - V_246 ;
}
void F_201 ( struct V_143 * V_247 , struct V_229 * V_231 , int V_60 )
{
struct V_143 * V_144 ;
struct V_229 * V_248 ;
struct V_249 * V_250 ;
T_3 V_251 = sizeof( * V_250 ) ;
if ( V_60 )
V_251 += V_233 ( V_231 ) ;
V_144 = F_202 ( V_251 , V_74 ) ;
if ( ! V_144 ) {
struct V_2 * V_3 ;
V_3 = F_32 ( F_35 ( V_247 -> V_3 ) ,
V_247 -> V_3 -> V_56 ,
F_151 ( V_247 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_128 = V_129 ;
V_3 -> V_130 ( V_3 ) ;
F_77 ( V_3 ) ;
}
return;
}
V_248 = F_188 ( V_144 , F_151 ( V_247 ) . V_10 , V_231 -> V_236 ,
V_252 , V_251 , 0 ) ;
V_250 = F_199 ( V_248 ) ;
V_250 -> error = V_60 ;
memcpy ( & V_250 -> V_197 , V_231 , V_60 ? V_231 -> V_233 : sizeof( * V_231 ) ) ;
F_123 ( V_247 -> V_3 , V_144 , F_151 ( V_247 ) . V_10 , V_215 ) ;
}
int F_203 ( struct V_143 * V_144 , int (* V_15)( struct V_143 * ,
struct V_229 * ) )
{
struct V_229 * V_231 ;
int V_60 ;
while ( V_144 -> V_51 >= F_204 ( 0 ) ) {
int V_253 ;
V_231 = F_205 ( V_144 ) ;
V_60 = 0 ;
if ( V_231 -> V_233 < V_254 || V_144 -> V_51 < V_231 -> V_233 )
return 0 ;
if ( ! ( V_231 -> V_234 & V_255 ) )
goto V_256;
if ( V_231 -> V_232 < V_257 )
goto V_256;
V_60 = V_15 ( V_144 , V_231 ) ;
if ( V_60 == - V_246 )
goto V_258;
V_256:
if ( V_231 -> V_234 & V_259 || V_60 )
F_201 ( V_144 , V_231 , V_60 ) ;
V_258:
V_253 = F_190 ( V_231 -> V_233 ) ;
if ( V_253 > V_144 -> V_51 )
V_253 = V_144 -> V_51 ;
F_206 ( V_144 , V_253 ) ;
}
return 0 ;
}
int F_207 ( struct V_2 * V_3 , struct V_143 * V_144 , T_1 V_10 ,
unsigned int V_6 , int V_260 , T_5 V_4 )
{
int V_60 = 0 ;
if ( V_6 ) {
int V_261 = 0 ;
if ( V_260 ) {
F_28 ( & V_144 -> V_214 ) ;
V_261 = V_10 ;
}
V_60 = F_208 ( V_3 , V_144 , V_261 , V_6 , V_4 ) ;
}
if ( V_260 ) {
int V_262 ;
V_262 = F_209 ( V_3 , V_144 , V_10 ) ;
if ( ! V_60 || V_60 == - V_177 )
V_60 = V_262 ;
}
return V_60 ;
}
static struct V_2 * F_210 ( struct V_263 * V_230 , T_7 V_264 )
{
struct V_265 * V_266 = V_230 -> V_267 ;
int V_45 , V_268 ;
struct V_2 * V_269 ;
struct V_33 * V_34 ;
T_7 V_270 = 0 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_8 * V_9 = & V_31 [ V_45 ] . V_9 ;
for ( V_268 = 0 ; V_268 <= V_9 -> V_13 ; V_268 ++ ) {
F_33 (s, node, &hash->table[j]) {
if ( F_35 ( V_269 ) != F_211 ( V_230 ) )
continue;
if ( V_270 == V_264 ) {
V_266 -> V_271 = V_45 ;
V_266 -> V_272 = V_268 ;
return V_269 ;
}
++ V_270 ;
}
}
}
return NULL ;
}
static void * F_212 ( struct V_263 * V_230 , T_7 * V_264 )
__acquires( T_2 )
{
F_27 ( & T_2 ) ;
return * V_264 ? F_210 ( V_230 , * V_264 - 1 ) : V_273 ;
}
static void * F_213 ( struct V_263 * V_230 , void * V_274 , T_7 * V_264 )
{
struct V_2 * V_269 ;
struct V_265 * V_266 ;
int V_45 , V_268 ;
++ * V_264 ;
if ( V_274 == V_273 )
return F_210 ( V_230 , 0 ) ;
V_266 = V_230 -> V_267 ;
V_269 = V_274 ;
do {
V_269 = F_214 ( V_269 ) ;
} while ( V_269 && F_35 ( V_269 ) != F_211 ( V_230 ) );
if ( V_269 )
return V_269 ;
V_45 = V_266 -> V_271 ;
V_268 = V_266 -> V_272 + 1 ;
do {
struct V_8 * V_9 = & V_31 [ V_45 ] . V_9 ;
for (; V_268 <= V_9 -> V_13 ; V_268 ++ ) {
V_269 = F_215 ( & V_9 -> V_11 [ V_268 ] ) ;
while ( V_269 && F_35 ( V_269 ) != F_211 ( V_230 ) )
V_269 = F_214 ( V_269 ) ;
if ( V_269 ) {
V_266 -> V_271 = V_45 ;
V_266 -> V_272 = V_268 ;
return V_269 ;
}
}
V_268 = 0 ;
} while ( ++ V_45 < V_85 );
return NULL ;
}
static void F_216 ( struct V_263 * V_230 , void * V_274 )
__releases( T_2 )
{
F_29 ( & T_2 ) ;
}
static int F_217 ( struct V_263 * V_230 , void * V_274 )
{
if ( V_274 == V_273 )
F_218 ( V_230 ,
L_3
L_4 ) ;
else {
struct V_2 * V_269 = V_274 ;
struct V_1 * V_14 = F_1 ( V_269 ) ;
F_219 ( V_230 , L_5 ,
V_269 ,
V_269 -> V_56 ,
V_14 -> V_10 ,
V_14 -> V_22 ? ( T_1 ) V_14 -> V_22 [ 0 ] : 0 ,
F_220 ( V_269 ) ,
F_221 ( V_269 ) ,
V_14 -> V_15 ,
F_13 ( & V_269 -> V_275 ) ,
F_13 ( & V_269 -> V_131 ) ,
F_222 ( V_269 )
) ;
}
return 0 ;
}
static int F_223 ( struct V_136 * V_136 , struct V_134 * V_134 )
{
return F_224 ( V_136 , V_134 , & V_276 ,
sizeof( struct V_265 ) ) ;
}
int F_225 ( struct V_277 * V_278 )
{
return F_226 ( & V_93 , V_278 ) ;
}
int F_227 ( struct V_277 * V_278 )
{
return F_228 ( & V_93 , V_278 ) ;
}
static int T_8 F_229 ( struct V_29 * V_29 )
{
#ifdef F_230
if ( ! F_231 ( V_29 , L_6 , 0 , & V_279 ) )
return - V_64 ;
#endif
return 0 ;
}
static void T_9 F_232 ( struct V_29 * V_29 )
{
#ifdef F_230
F_233 ( V_29 , L_6 ) ;
#endif
}
static void T_10 F_234 ( void )
{
struct V_58 * V_58 ;
int V_22 = 32 ;
V_58 = F_38 ( sizeof( * V_58 ) + F_87 ( V_22 ) , V_74 ) ;
if ( ! V_58 )
F_235 ( L_7 ) ;
F_14 () ;
V_31 [ V_280 ] . V_22 = V_22 ;
F_177 ( V_31 [ V_280 ] . V_58 , V_58 ) ;
V_31 [ V_280 ] . V_79 = V_281 ;
V_31 [ V_280 ] . V_87 = 1 ;
F_24 () ;
}
static int T_10 F_236 ( void )
{
struct V_143 * V_282 ;
int V_45 ;
unsigned long V_283 ;
unsigned int V_284 ;
int V_60 = F_237 ( & V_75 , 0 ) ;
if ( V_60 != 0 )
goto V_88;
F_238 ( sizeof( struct V_285 ) > sizeof( V_282 -> V_15 ) ) ;
V_31 = F_239 ( V_85 , sizeof( * V_31 ) , V_74 ) ;
if ( ! V_31 )
goto F_235;
if ( V_286 >= ( 128 * 1024 ) )
V_283 = V_286 >> ( 21 - V_287 ) ;
else
V_283 = V_286 >> ( 23 - V_287 ) ;
V_284 = F_240 ( V_283 ) - 1 + V_287 ;
V_283 = ( 1UL << V_284 ) / sizeof( struct V_7 ) ;
V_284 = F_240 ( F_241 ( V_283 , ( unsigned long ) V_66 ) ) - 1 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_8 * V_9 = & V_31 [ V_45 ] . V_9 ;
V_9 -> V_11 = F_37 ( 1 * sizeof( * V_9 -> V_11 ) ) ;
if ( ! V_9 -> V_11 ) {
while ( V_45 -- > 0 )
F_41 ( V_31 [ V_45 ] . V_9 . V_11 ,
1 * sizeof( * V_9 -> V_11 ) ) ;
F_42 ( V_31 ) ;
goto F_235;
}
V_9 -> V_46 = V_284 ;
V_9 -> V_42 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_48 = V_49 ;
}
F_234 () ;
F_242 ( & V_288 ) ;
F_243 ( & V_289 ) ;
F_244 () ;
V_88:
return V_60 ;
F_235:
F_235 ( L_8 ) ;
}
