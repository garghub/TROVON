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
static void F_7 ( struct V_14 * V_15 )
{
F_8 ( V_15 -> V_16 ) ;
F_9 ( V_15 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
F_11 ( V_15 -> V_16 ) ;
F_9 ( V_15 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_15 ) {
if ( V_17 -> V_15 -> V_18 )
V_17 -> V_15 -> V_18 ( V_17 -> V_15 ) ;
F_7 ( V_17 -> V_15 ) ;
}
F_13 ( & V_3 -> V_19 ) ;
if ( ! F_14 ( V_3 , V_20 ) ) {
F_15 ( V_21 L_1 , V_3 ) ;
return;
}
F_16 ( F_17 ( & V_3 -> V_22 ) ) ;
F_16 ( F_17 ( & V_3 -> V_23 ) ) ;
F_16 ( F_1 ( V_3 ) -> V_24 ) ;
}
void F_18 ( void )
__acquires( T_2 )
{
F_19 () ;
F_20 ( & T_2 ) ;
if ( F_17 ( & V_25 ) ) {
F_21 ( V_26 , V_27 ) ;
F_22 ( & V_28 , & V_26 ) ;
for (; ; ) {
F_23 ( V_29 ) ;
if ( F_17 ( & V_25 ) == 0 )
break;
F_24 ( & T_2 ) ;
F_25 () ;
F_20 ( & T_2 ) ;
}
F_26 ( V_30 ) ;
F_27 ( & V_28 , & V_26 ) ;
}
}
void F_28 ( void )
__releases( T_2 )
{
F_24 ( & T_2 ) ;
F_29 ( & V_28 ) ;
}
static inline void
F_30 ( void )
{
F_31 ( & T_2 ) ;
F_32 ( & V_25 ) ;
F_33 ( & T_2 ) ;
}
static inline void
F_34 ( void )
{
if ( F_35 ( & V_25 ) )
F_29 ( & V_28 ) ;
}
static struct V_2 * F_36 ( struct V_31 * V_31 , int V_32 , T_1 V_10 )
{
struct V_8 * V_9 = & V_33 [ V_32 ] . V_9 ;
struct V_7 * V_34 ;
struct V_2 * V_3 ;
struct V_35 * V_36 ;
F_31 ( & T_2 ) ;
V_34 = F_5 ( V_9 , V_10 ) ;
F_37 (sk, node, head) {
if ( F_38 ( F_39 ( V_3 ) , V_31 ) && ( F_1 ( V_3 ) -> V_10 == V_10 ) ) {
F_40 ( V_3 ) ;
goto V_37;
}
}
V_3 = NULL ;
V_37:
F_33 ( & T_2 ) ;
return V_3 ;
}
static struct V_7 * F_41 ( T_3 V_38 )
{
if ( V_38 <= V_39 )
return F_42 ( V_38 , V_40 ) ;
else
return (struct V_7 * )
F_43 ( V_40 | V_41 ,
F_44 ( V_38 ) ) ;
}
static void F_45 ( struct V_7 * V_11 , T_3 V_38 )
{
if ( V_38 <= V_39 )
F_9 ( V_11 ) ;
else
F_46 ( ( unsigned long ) V_11 , F_44 ( V_38 ) ) ;
}
static int F_47 ( struct V_8 * V_9 , int V_42 )
{
unsigned int V_43 , V_13 , V_44 ;
T_3 V_45 , V_38 ;
struct V_7 * V_46 , * V_11 ;
int V_47 ;
V_43 = V_13 = V_9 -> V_13 ;
V_45 = V_38 = ( V_13 + 1 ) * sizeof( * V_11 ) ;
V_44 = V_9 -> V_44 ;
if ( V_42 ) {
if ( ++ V_44 > V_9 -> V_48 )
return 0 ;
V_13 = V_13 * 2 + 1 ;
V_38 *= 2 ;
}
V_11 = F_41 ( V_38 ) ;
if ( ! V_11 )
return 0 ;
V_46 = V_9 -> V_11 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_44 = V_44 ;
F_48 ( & V_9 -> V_12 , sizeof( V_9 -> V_12 ) ) ;
for ( V_47 = 0 ; V_47 <= V_43 ; V_47 ++ ) {
struct V_2 * V_3 ;
struct V_35 * V_36 , * V_49 ;
F_49 (sk, node, tmp, &otable[i])
F_50 ( V_3 , F_5 ( V_9 , F_1 ( V_3 ) -> V_10 ) ) ;
}
F_45 ( V_46 , V_45 ) ;
V_9 -> V_50 = V_51 + 10 * 60 * V_52 ;
return 1 ;
}
static inline int F_51 ( struct V_8 * V_9 , int V_53 )
{
int V_54 = V_9 -> V_55 >> V_9 -> V_44 ;
if ( F_52 ( V_54 > 1 ) && F_47 ( V_9 , 1 ) )
return 1 ;
if ( F_52 ( V_53 > V_54 ) && F_53 ( V_51 , V_9 -> V_50 ) ) {
F_47 ( V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_54 ( struct V_2 * V_3 )
{
struct V_56 * V_57 = & V_33 [ V_3 -> V_58 ] ;
struct V_35 * V_36 ;
unsigned long V_13 ;
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < F_55 ( V_57 -> V_24 ) ; V_47 ++ ) {
V_13 = 0 ;
F_56 (sk, node, &tbl->mc_list) {
if ( V_47 < F_55 ( F_1 ( V_3 ) -> V_59 ) )
V_13 |= F_1 ( V_3 ) -> V_24 [ V_47 ] ;
}
V_57 -> V_60 -> V_61 [ V_47 ] = V_13 ;
}
}
static int F_57 ( struct V_2 * V_3 , struct V_31 * V_31 , T_1 V_10 )
{
struct V_8 * V_9 = & V_33 [ V_3 -> V_58 ] . V_9 ;
struct V_7 * V_34 ;
int V_62 = - V_63 ;
struct V_2 * V_64 ;
struct V_35 * V_36 ;
int V_53 ;
F_18 () ;
V_34 = F_5 ( V_9 , V_10 ) ;
V_53 = 0 ;
F_37 (osk, node, head) {
if ( F_38 ( F_39 ( V_64 ) , V_31 ) && ( F_1 ( V_64 ) -> V_10 == V_10 ) )
break;
V_53 ++ ;
}
if ( V_36 )
goto V_62;
V_62 = - V_65 ;
if ( F_1 ( V_3 ) -> V_10 )
goto V_62;
V_62 = - V_66 ;
if ( V_67 > 32 && F_52 ( V_9 -> V_55 >= V_68 ) )
goto V_62;
if ( V_53 && F_51 ( V_9 , V_53 ) )
V_34 = F_5 ( V_9 , V_10 ) ;
V_9 -> V_55 ++ ;
F_1 ( V_3 ) -> V_10 = V_10 ;
F_58 ( V_3 , V_34 ) ;
V_62 = 0 ;
V_62:
F_28 () ;
return V_62 ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_18 () ;
if ( F_60 ( V_3 ) )
V_33 [ V_3 -> V_58 ] . V_9 . V_55 -- ;
if ( F_1 ( V_3 ) -> V_69 )
F_61 ( V_3 ) ;
F_28 () ;
}
static int F_62 ( struct V_31 * V_31 , struct V_70 * V_2 ,
struct V_71 * V_72 , int V_32 )
{
struct V_2 * V_3 ;
struct V_1 * V_17 ;
V_2 -> V_73 = & V_74 ;
V_3 = F_63 ( V_31 , V_75 , V_76 , & V_77 ) ;
if ( ! V_3 )
return - V_66 ;
F_64 ( V_2 , V_3 ) ;
V_17 = F_1 ( V_3 ) ;
if ( V_72 ) {
V_17 -> V_72 = V_72 ;
} else {
V_17 -> V_72 = & V_17 -> V_78 ;
F_65 ( V_17 -> V_72 ) ;
}
F_66 ( & V_17 -> V_26 ) ;
V_3 -> V_79 = F_12 ;
V_3 -> V_58 = V_32 ;
return 0 ;
}
static int F_67 ( struct V_31 * V_31 , struct V_70 * V_2 , int V_32 ,
int V_80 )
{
struct V_81 * V_81 = NULL ;
struct V_71 * V_72 ;
struct V_1 * V_17 ;
void (* F_68)( int V_6 );
int V_62 = 0 ;
V_2 -> V_82 = V_83 ;
if ( V_2 -> type != V_84 && V_2 -> type != V_85 )
return - V_86 ;
if ( V_32 < 0 || V_32 >= V_87 )
return - V_88 ;
F_30 () ;
#ifdef F_69
if ( ! V_33 [ V_32 ] . V_89 ) {
F_34 () ;
F_70 ( L_2 , V_75 , V_32 ) ;
F_30 () ;
}
#endif
if ( V_33 [ V_32 ] . V_89 &&
F_71 ( V_33 [ V_32 ] . V_81 ) )
V_81 = V_33 [ V_32 ] . V_81 ;
else
V_62 = - V_88 ;
V_72 = V_33 [ V_32 ] . V_72 ;
F_68 = V_33 [ V_32 ] . F_68 ;
F_34 () ;
if ( V_62 < 0 )
goto V_90;
V_62 = F_62 ( V_31 , V_2 , V_72 , V_32 ) ;
if ( V_62 < 0 )
goto V_91;
F_72 () ;
F_73 ( V_31 , & V_77 , 1 ) ;
F_74 () ;
V_17 = F_1 ( V_2 -> V_3 ) ;
V_17 -> V_81 = V_81 ;
V_17 -> V_92 = F_68 ;
V_90:
return V_62 ;
V_91:
F_75 ( V_81 ) ;
goto V_90;
}
static int F_76 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 ;
if ( ! V_3 )
return 0 ;
F_59 ( V_3 ) ;
F_77 ( V_3 ) ;
V_17 = F_1 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_78 ( & V_17 -> V_26 ) ;
F_13 ( & V_3 -> V_93 ) ;
if ( V_17 -> V_10 ) {
struct V_94 V_95 = {
. V_31 = F_39 ( V_3 ) ,
. V_32 = V_3 -> V_58 ,
. V_10 = V_17 -> V_10 ,
} ;
F_79 ( & V_96 ,
V_97 , & V_95 ) ;
}
F_75 ( V_17 -> V_81 ) ;
F_18 () ;
if ( F_3 ( V_3 ) ) {
F_80 ( V_33 [ V_3 -> V_58 ] . V_89 == 0 ) ;
if ( -- V_33 [ V_3 -> V_58 ] . V_89 == 0 ) {
F_9 ( V_33 [ V_3 -> V_58 ] . V_60 ) ;
V_33 [ V_3 -> V_58 ] . V_81 = NULL ;
V_33 [ V_3 -> V_58 ] . V_89 = 0 ;
}
} else if ( V_17 -> V_69 ) {
F_54 ( V_3 ) ;
}
F_28 () ;
F_9 ( V_17 -> V_24 ) ;
V_17 -> V_24 = NULL ;
F_72 () ;
F_73 ( F_39 ( V_3 ) , & V_77 , - 1 ) ;
F_74 () ;
F_81 ( V_3 ) ;
return 0 ;
}
static int F_82 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_31 * V_31 = F_39 ( V_3 ) ;
struct V_8 * V_9 = & V_33 [ V_3 -> V_58 ] . V_9 ;
struct V_7 * V_34 ;
struct V_2 * V_64 ;
struct V_35 * V_36 ;
T_4 V_10 = F_83 ( V_27 ) ;
int V_62 ;
static T_4 V_98 = - 4097 ;
V_99:
F_84 () ;
F_18 () ;
V_34 = F_5 ( V_9 , V_10 ) ;
F_37 (osk, node, head) {
if ( ! F_38 ( F_39 ( V_64 ) , V_31 ) )
continue;
if ( F_1 ( V_64 ) -> V_10 == V_10 ) {
V_10 = V_98 -- ;
if ( V_98 > - 4097 )
V_98 = - 4097 ;
F_28 () ;
goto V_99;
}
}
F_28 () ;
V_62 = F_57 ( V_3 , V_31 , V_10 ) ;
if ( V_62 == - V_63 )
goto V_99;
if ( V_62 == - V_65 )
V_62 = 0 ;
return V_62 ;
}
static inline int F_85 ( const struct V_70 * V_2 , unsigned int V_100 )
{
return ( V_33 [ V_2 -> V_3 -> V_58 ] . V_101 & V_100 ) ||
F_86 ( V_102 ) ;
}
static void
F_87 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_69 && ! V_69 )
F_61 ( V_3 ) ;
else if ( ! V_17 -> V_69 && V_69 )
F_88 ( V_3 , & V_33 [ V_3 -> V_58 ] . V_103 ) ;
V_17 -> V_69 = V_69 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_24 ;
unsigned long * V_104 ;
int V_62 = 0 ;
F_18 () ;
V_24 = V_33 [ V_3 -> V_58 ] . V_24 ;
if ( ! V_33 [ V_3 -> V_58 ] . V_89 ) {
V_62 = - V_105 ;
goto V_106;
}
if ( V_17 -> V_59 >= V_24 )
goto V_106;
V_104 = F_90 ( V_17 -> V_24 , F_91 ( V_24 ) , V_40 ) ;
if ( V_104 == NULL ) {
V_62 = - V_66 ;
goto V_106;
}
memset ( ( char * ) V_104 + F_91 ( V_17 -> V_59 ) , 0 ,
F_91 ( V_24 ) - F_91 ( V_17 -> V_59 ) ) ;
V_17 -> V_24 = V_104 ;
V_17 -> V_59 = V_24 ;
V_106:
F_28 () ;
return V_62 ;
}
static int V_92 ( struct V_70 * V_2 , struct V_107 * V_108 ,
int V_109 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_31 * V_31 = F_39 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_110 * V_111 = (struct V_110 * ) V_108 ;
int V_62 ;
if ( V_111 -> V_112 != V_113 )
return - V_114 ;
if ( V_111 -> V_115 ) {
if ( ! F_85 ( V_2 , V_116 ) )
return - V_117 ;
V_62 = F_89 ( V_3 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_17 -> V_10 ) {
if ( V_111 -> V_118 != V_17 -> V_10 )
return - V_114 ;
} else {
V_62 = V_111 -> V_118 ?
F_57 ( V_3 , V_31 , V_111 -> V_118 ) :
F_82 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
if ( ! V_111 -> V_115 && ( V_17 -> V_24 == NULL || ! ( T_1 ) V_17 -> V_24 [ 0 ] ) )
return 0 ;
F_18 () ;
F_87 ( V_3 , V_17 -> V_69 +
F_92 ( V_111 -> V_115 ) -
F_92 ( V_17 -> V_24 [ 0 ] ) ) ;
V_17 -> V_24 [ 0 ] = ( V_17 -> V_24 [ 0 ] & ~ 0xffffffffUL ) | V_111 -> V_115 ;
F_54 ( V_3 ) ;
F_28 () ;
if ( V_17 -> V_92 && V_17 -> V_24 [ 0 ] ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_17 -> V_59 ; V_47 ++ ) {
if ( F_93 ( V_47 , V_17 -> V_24 ) )
V_17 -> V_92 ( V_47 ) ;
}
}
return 0 ;
}
static int F_94 ( struct V_70 * V_2 , struct V_107 * V_108 ,
int V_119 , int V_4 )
{
int V_62 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_110 * V_111 = (struct V_110 * ) V_108 ;
if ( V_119 < sizeof( V_108 -> V_120 ) )
return - V_114 ;
if ( V_108 -> V_120 == V_121 ) {
V_3 -> V_122 = V_123 ;
V_17 -> V_124 = 0 ;
V_17 -> V_125 = 0 ;
return 0 ;
}
if ( V_108 -> V_120 != V_113 )
return - V_114 ;
if ( V_111 -> V_115 && ! F_85 ( V_2 , V_126 ) )
return - V_117 ;
if ( ! V_17 -> V_10 )
V_62 = F_82 ( V_2 ) ;
if ( V_62 == 0 ) {
V_3 -> V_122 = V_127 ;
V_17 -> V_124 = V_111 -> V_118 ;
V_17 -> V_125 = F_95 ( V_111 -> V_115 ) ;
}
return V_62 ;
}
static int F_96 ( struct V_70 * V_2 , struct V_107 * V_108 ,
int * V_109 , int V_128 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_97 ( struct V_110 * , V_111 , V_108 ) ;
V_111 -> V_112 = V_113 ;
V_111 -> V_129 = 0 ;
* V_109 = sizeof( * V_111 ) ;
if ( V_128 ) {
V_111 -> V_118 = V_17 -> V_124 ;
V_111 -> V_115 = F_4 ( V_17 -> V_125 ) ;
} else {
V_111 -> V_118 = V_17 -> V_10 ;
V_111 -> V_115 = V_17 -> V_24 ? V_17 -> V_24 [ 0 ] : 0 ;
}
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! ( V_17 -> V_4 & V_130 ) ) {
if ( ! F_99 ( 0 , & F_1 ( V_3 ) -> V_82 ) ) {
V_3 -> V_131 = V_132 ;
V_3 -> V_133 ( V_3 ) ;
}
}
F_32 ( & V_3 -> V_134 ) ;
}
static struct V_2 * F_100 ( struct V_2 * V_135 , T_1 V_10 )
{
struct V_2 * V_2 ;
struct V_1 * V_17 ;
V_2 = F_36 ( F_39 ( V_135 ) , V_135 -> V_58 , V_10 ) ;
if ( ! V_2 )
return F_101 ( - V_136 ) ;
V_17 = F_1 ( V_2 ) ;
if ( V_2 -> V_122 == V_127 &&
V_17 -> V_124 != F_1 ( V_135 ) -> V_10 ) {
F_81 ( V_2 ) ;
return F_101 ( - V_136 ) ;
}
return V_2 ;
}
struct V_2 * F_102 ( struct V_137 * V_138 )
{
struct V_139 * V_139 = V_138 -> V_140 . V_141 -> V_142 ;
struct V_2 * V_2 ;
if ( ! F_103 ( V_139 -> V_143 ) )
return F_101 ( - V_144 ) ;
V_2 = F_104 ( V_139 ) -> V_3 ;
if ( V_2 -> V_145 != V_113 )
return F_101 ( - V_114 ) ;
F_40 ( V_2 ) ;
return V_2 ;
}
int F_105 ( struct V_2 * V_3 , struct V_146 * V_16 ,
long * V_147 , struct V_2 * V_135 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 ) ;
if ( F_17 ( & V_3 -> V_22 ) > V_3 -> V_148 ||
F_93 ( 0 , & V_17 -> V_82 ) ) {
F_21 ( V_26 , V_27 ) ;
if ( ! * V_147 ) {
if ( ! V_135 || F_3 ( V_135 ) )
F_98 ( V_3 ) ;
F_81 ( V_3 ) ;
F_8 ( V_16 ) ;
return - V_149 ;
}
F_26 ( V_150 ) ;
F_106 ( & V_17 -> V_26 , & V_26 ) ;
if ( ( F_17 ( & V_3 -> V_22 ) > V_3 -> V_148 ||
F_93 ( 0 , & V_17 -> V_82 ) ) &&
! F_14 ( V_3 , V_20 ) )
* V_147 = F_107 ( * V_147 ) ;
F_26 ( V_30 ) ;
F_27 ( & V_17 -> V_26 , & V_26 ) ;
F_81 ( V_3 ) ;
if ( F_108 ( V_27 ) ) {
F_8 ( V_16 ) ;
return F_109 ( * V_147 ) ;
}
return 1 ;
}
F_110 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_146 * V_16 )
{
int V_53 = V_16 -> V_53 ;
F_112 ( & V_3 -> V_19 , V_16 ) ;
V_3 -> V_151 ( V_3 , V_53 ) ;
return V_53 ;
}
int F_113 ( struct V_2 * V_3 , struct V_146 * V_16 )
{
int V_53 = F_111 ( V_3 , V_16 ) ;
F_81 ( V_3 ) ;
return V_53 ;
}
void F_114 ( struct V_2 * V_3 , struct V_146 * V_16 )
{
F_8 ( V_16 ) ;
F_81 ( V_3 ) ;
}
static struct V_146 * F_115 ( struct V_146 * V_16 , T_5 V_152 )
{
int V_153 ;
F_116 ( V_16 ) ;
V_153 = V_16 -> V_154 - V_16 -> V_155 ;
if ( V_153 * 2 < V_16 -> V_156 )
return V_16 ;
if ( F_117 ( V_16 ) ) {
struct V_146 * V_157 = F_118 ( V_16 , V_152 ) ;
if ( ! V_157 )
return V_16 ;
F_11 ( V_16 ) ;
V_16 = V_157 ;
}
if ( ! F_119 ( V_16 , 0 , - V_153 , V_152 ) )
V_16 -> V_156 -= V_153 ;
return V_16 ;
}
static void F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_121 ( & V_3 -> V_19 ) )
F_122 ( 0 , & V_17 -> V_82 ) ;
if ( ! F_93 ( 0 , & V_17 -> V_82 ) )
F_123 ( & V_17 -> V_26 ) ;
}
static int F_124 ( struct V_2 * V_3 , struct V_146 * V_16 )
{
int V_158 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_158 = - V_136 ;
if ( V_17 -> V_159 != NULL ) {
V_158 = V_16 -> V_53 ;
F_110 ( V_16 , V_3 ) ;
V_17 -> V_159 ( V_16 ) ;
F_11 ( V_16 ) ;
} else {
F_8 ( V_16 ) ;
}
F_81 ( V_3 ) ;
return V_158 ;
}
int F_125 ( struct V_2 * V_135 , struct V_146 * V_16 ,
T_1 V_10 , int V_160 )
{
struct V_2 * V_3 ;
int V_62 ;
long V_147 ;
V_16 = F_115 ( V_16 , F_126 () ) ;
V_147 = F_127 ( V_135 , V_160 ) ;
V_99:
V_3 = F_100 ( V_135 , V_10 ) ;
if ( F_128 ( V_3 ) ) {
F_8 ( V_16 ) ;
return F_129 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_124 ( V_3 , V_16 ) ;
if ( F_130 ( V_3 , V_16 ) ) {
V_62 = V_16 -> V_53 ;
F_8 ( V_16 ) ;
F_81 ( V_3 ) ;
return V_62 ;
}
V_62 = F_105 ( V_3 , V_16 , & V_147 , V_135 ) ;
if ( V_62 == 1 )
goto V_99;
if ( V_62 )
return V_62 ;
return F_113 ( V_3 , V_16 ) ;
}
int F_131 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_161 = 0 ;
struct V_60 * V_60 ;
F_80 ( ! F_3 ( V_3 ) ) ;
F_132 () ;
V_60 = F_133 ( V_33 [ V_3 -> V_58 ] . V_60 ) ;
if ( V_6 - 1 < V_33 [ V_3 -> V_58 ] . V_24 )
V_161 = F_93 ( V_6 - 1 , V_60 -> V_61 ) ;
F_134 () ;
return V_161 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_146 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_17 ( & V_3 -> V_22 ) <= V_3 -> V_148 &&
! F_93 ( 0 , & V_17 -> V_82 ) ) {
F_110 ( V_16 , V_3 ) ;
F_111 ( V_3 , V_16 ) ;
return F_17 ( & V_3 -> V_22 ) > ( V_3 -> V_148 >> 1 ) ;
}
return - 1 ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_162 * V_163 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_164 ;
if ( V_163 -> V_165 == V_3 )
goto V_90;
if ( V_17 -> V_10 == V_163 -> V_10 || V_163 -> V_6 - 1 >= V_17 -> V_59 ||
! F_93 ( V_163 -> V_6 - 1 , V_17 -> V_24 ) )
goto V_90;
if ( ! F_38 ( F_39 ( V_3 ) , V_163 -> V_31 ) )
goto V_90;
if ( V_163 -> V_166 ) {
F_98 ( V_3 ) ;
goto V_90;
}
F_40 ( V_3 ) ;
if ( V_163 -> V_167 == NULL ) {
if ( F_117 ( V_163 -> V_16 ) ) {
V_163 -> V_167 = F_118 ( V_163 -> V_16 , V_163 -> V_152 ) ;
} else {
V_163 -> V_167 = F_137 ( V_163 -> V_16 ) ;
F_116 ( V_163 -> V_167 ) ;
}
}
if ( V_163 -> V_167 == NULL ) {
F_98 ( V_3 ) ;
V_163 -> V_166 = 1 ;
if ( V_17 -> V_4 & V_168 )
V_163 -> V_169 = 1 ;
} else if ( V_163 -> V_170 && V_163 -> V_170 ( V_3 , V_163 -> V_167 , V_163 -> V_171 ) ) {
F_8 ( V_163 -> V_167 ) ;
V_163 -> V_167 = NULL ;
} else if ( F_130 ( V_3 , V_163 -> V_167 ) ) {
F_8 ( V_163 -> V_167 ) ;
V_163 -> V_167 = NULL ;
} else if ( ( V_164 = F_135 ( V_3 , V_163 -> V_167 ) ) < 0 ) {
F_98 ( V_3 ) ;
if ( V_17 -> V_4 & V_168 )
V_163 -> V_169 = 1 ;
} else {
V_163 -> V_172 |= V_164 ;
V_163 -> V_173 = 1 ;
V_163 -> V_167 = NULL ;
}
F_81 ( V_3 ) ;
V_90:
return 0 ;
}
int F_138 ( struct V_2 * V_135 , struct V_146 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_152 ,
int (* F_139)( struct V_2 * V_174 , struct V_146 * V_16 , void * V_175 ) ,
void * V_176 )
{
struct V_31 * V_31 = F_39 ( V_135 ) ;
struct V_162 V_177 ;
struct V_35 * V_36 ;
struct V_2 * V_3 ;
V_16 = F_115 ( V_16 , V_152 ) ;
V_177 . V_165 = V_135 ;
V_177 . V_31 = V_31 ;
V_177 . V_10 = V_10 ;
V_177 . V_6 = V_6 ;
V_177 . V_166 = 0 ;
V_177 . V_169 = 0 ;
V_177 . V_172 = 0 ;
V_177 . V_173 = 0 ;
V_177 . V_152 = V_152 ;
V_177 . V_16 = V_16 ;
V_177 . V_167 = NULL ;
V_177 . V_170 = F_139 ;
V_177 . V_171 = V_176 ;
F_30 () ;
F_56 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
F_136 ( V_3 , & V_177 ) ;
F_11 ( V_16 ) ;
F_34 () ;
if ( V_177 . V_169 ) {
F_8 ( V_177 . V_167 ) ;
return - V_132 ;
}
F_11 ( V_177 . V_167 ) ;
if ( V_177 . V_173 ) {
if ( V_177 . V_172 && ( V_152 & V_178 ) )
F_140 () ;
return 0 ;
}
return - V_179 ;
}
int F_141 ( struct V_2 * V_135 , struct V_146 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_152 )
{
return F_138 ( V_135 , V_16 , V_10 , V_6 , V_152 ,
NULL , NULL ) ;
}
static int F_142 ( struct V_2 * V_3 , struct V_180 * V_163 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_158 = 0 ;
if ( V_3 == V_163 -> V_165 )
goto V_90;
if ( ! F_38 ( F_39 ( V_3 ) , F_39 ( V_163 -> V_165 ) ) )
goto V_90;
if ( V_17 -> V_10 == V_163 -> V_10 || V_163 -> V_6 - 1 >= V_17 -> V_59 ||
! F_93 ( V_163 -> V_6 - 1 , V_17 -> V_24 ) )
goto V_90;
if ( V_163 -> V_181 == V_132 && V_17 -> V_4 & V_130 ) {
V_158 = 1 ;
goto V_90;
}
V_3 -> V_131 = V_163 -> V_181 ;
V_3 -> V_133 ( V_3 ) ;
V_90:
return V_158 ;
}
int F_143 ( struct V_2 * V_135 , T_1 V_10 , T_1 V_6 , int V_181 )
{
struct V_180 V_177 ;
struct V_35 * V_36 ;
struct V_2 * V_3 ;
int V_158 = 0 ;
V_177 . V_165 = V_135 ;
V_177 . V_10 = V_10 ;
V_177 . V_6 = V_6 ;
V_177 . V_181 = - V_181 ;
F_31 ( & T_2 ) ;
F_56 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
V_158 += F_142 ( V_3 , & V_177 ) ;
F_33 ( & T_2 ) ;
return V_158 ;
}
static void F_144 ( struct V_1 * V_17 ,
unsigned int V_6 ,
int V_182 )
{
int V_183 , V_184 = ! ! V_182 , V_69 ;
V_183 = F_93 ( V_6 - 1 , V_17 -> V_24 ) ;
V_69 = V_17 -> V_69 - V_183 + V_184 ;
if ( V_184 )
F_145 ( V_6 - 1 , V_17 -> V_24 ) ;
else
F_146 ( V_6 - 1 , V_17 -> V_24 ) ;
F_87 ( & V_17 -> V_3 , V_69 ) ;
F_54 ( & V_17 -> V_3 ) ;
}
static int F_147 ( struct V_70 * V_2 , int V_185 , int V_186 ,
char T_6 * V_187 , unsigned int V_188 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_164 = 0 ;
int V_62 ;
if ( V_185 != V_189 )
return - V_190 ;
if ( V_188 >= sizeof( int ) &&
F_148 ( V_164 , ( unsigned int T_6 * ) V_187 ) )
return - V_191 ;
switch ( V_186 ) {
case V_192 :
if ( V_164 )
V_17 -> V_4 |= V_193 ;
else
V_17 -> V_4 &= ~ V_193 ;
V_62 = 0 ;
break;
case V_194 :
case V_195 : {
if ( ! F_85 ( V_2 , V_116 ) )
return - V_117 ;
V_62 = F_89 ( V_3 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_164 || V_164 - 1 >= V_17 -> V_59 )
return - V_114 ;
F_18 () ;
F_144 ( V_17 , V_164 ,
V_186 == V_194 ) ;
F_28 () ;
if ( V_17 -> V_92 )
V_17 -> V_92 ( V_164 ) ;
V_62 = 0 ;
break;
}
case V_196 :
if ( V_164 )
V_17 -> V_4 |= V_168 ;
else
V_17 -> V_4 &= ~ V_168 ;
V_62 = 0 ;
break;
case V_197 :
if ( V_164 ) {
V_17 -> V_4 |= V_130 ;
F_122 ( 0 , & V_17 -> V_82 ) ;
F_123 ( & V_17 -> V_26 ) ;
} else {
V_17 -> V_4 &= ~ V_130 ;
}
V_62 = 0 ;
break;
default:
V_62 = - V_190 ;
}
return V_62 ;
}
static int F_149 ( struct V_70 * V_2 , int V_185 , int V_186 ,
char T_6 * V_187 , int T_6 * V_188 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_53 , V_164 , V_62 ;
if ( V_185 != V_189 )
return - V_190 ;
if ( F_148 ( V_53 , V_188 ) )
return - V_191 ;
if ( V_53 < 0 )
return - V_114 ;
switch ( V_186 ) {
case V_192 :
if ( V_53 < sizeof( int ) )
return - V_114 ;
V_53 = sizeof( int ) ;
V_164 = V_17 -> V_4 & V_193 ? 1 : 0 ;
if ( F_150 ( V_53 , V_188 ) ||
F_150 ( V_164 , V_187 ) )
return - V_191 ;
V_62 = 0 ;
break;
case V_196 :
if ( V_53 < sizeof( int ) )
return - V_114 ;
V_53 = sizeof( int ) ;
V_164 = V_17 -> V_4 & V_168 ? 1 : 0 ;
if ( F_150 ( V_53 , V_188 ) ||
F_150 ( V_164 , V_187 ) )
return - V_191 ;
V_62 = 0 ;
break;
case V_197 :
if ( V_53 < sizeof( int ) )
return - V_114 ;
V_53 = sizeof( int ) ;
V_164 = V_17 -> V_4 & V_130 ? 1 : 0 ;
if ( F_150 ( V_53 , V_188 ) ||
F_150 ( V_164 , V_187 ) )
return - V_191 ;
V_62 = 0 ;
break;
default:
V_62 = - V_190 ;
}
return V_62 ;
}
static void F_151 ( struct V_198 * V_199 , struct V_146 * V_16 )
{
struct V_200 V_177 ;
V_177 . V_6 = F_152 ( V_16 ) . V_125 ;
F_153 ( V_199 , V_189 , V_192 , sizeof( V_177 ) , & V_177 ) ;
}
static int F_154 ( struct V_201 * V_201 , struct V_70 * V_2 ,
struct V_198 * V_199 , T_3 V_53 )
{
struct V_202 * V_203 = F_155 ( V_201 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_110 * V_108 = V_199 -> V_204 ;
T_1 V_124 ;
T_1 V_125 ;
struct V_146 * V_16 ;
int V_62 ;
struct V_205 V_206 ;
if ( V_199 -> V_207 & V_208 )
return - V_209 ;
if ( NULL == V_203 -> V_206 )
V_203 -> V_206 = & V_206 ;
V_62 = F_156 ( V_2 , V_199 , V_203 -> V_206 , true ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_199 -> V_210 ) {
V_62 = - V_114 ;
if ( V_108 -> V_112 != V_113 )
goto V_90;
V_124 = V_108 -> V_118 ;
V_125 = F_95 ( V_108 -> V_115 ) ;
V_62 = - V_117 ;
if ( ( V_125 || V_124 ) &&
! F_85 ( V_2 , V_126 ) )
goto V_90;
} else {
V_124 = V_17 -> V_124 ;
V_125 = V_17 -> V_125 ;
}
if ( ! V_17 -> V_10 ) {
V_62 = F_82 ( V_2 ) ;
if ( V_62 )
goto V_90;
}
V_62 = - V_211 ;
if ( V_53 > V_3 -> V_212 - 32 )
goto V_90;
V_62 = - V_132 ;
V_16 = F_157 ( V_53 , V_76 ) ;
if ( V_16 == NULL )
goto V_90;
F_152 ( V_16 ) . V_10 = V_17 -> V_10 ;
F_152 ( V_16 ) . V_125 = V_125 ;
memcpy ( F_158 ( V_16 ) , & V_203 -> V_206 -> V_213 , sizeof( struct V_214 ) ) ;
V_62 = - V_191 ;
if ( F_159 ( F_160 ( V_16 , V_53 ) , V_199 -> V_215 , V_53 ) ) {
F_8 ( V_16 ) ;
goto V_90;
}
V_62 = F_161 ( V_3 , V_16 ) ;
if ( V_62 ) {
F_8 ( V_16 ) ;
goto V_90;
}
if ( V_125 ) {
F_32 ( & V_16 -> V_216 ) ;
F_141 ( V_3 , V_16 , V_124 , V_125 , V_76 ) ;
}
V_62 = F_125 ( V_3 , V_16 , V_124 , V_199 -> V_207 & V_217 ) ;
V_90:
F_162 ( V_203 -> V_206 ) ;
return V_62 ;
}
static int F_163 ( struct V_201 * V_201 , struct V_70 * V_2 ,
struct V_198 * V_199 , T_3 V_53 ,
int V_4 )
{
struct V_202 * V_203 = F_155 ( V_201 ) ;
struct V_205 V_206 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_218 = V_4 & V_217 ;
T_3 V_219 ;
struct V_146 * V_16 , * V_220 ;
int V_62 , V_158 ;
if ( V_4 & V_208 )
return - V_209 ;
V_219 = 0 ;
V_16 = F_164 ( V_3 , V_4 , V_218 , & V_62 ) ;
if ( V_16 == NULL )
goto V_90;
V_220 = V_16 ;
#ifdef F_165
if ( F_52 ( F_166 ( V_16 ) -> V_221 ) ) {
if ( V_4 & V_222 )
V_220 = F_166 ( V_16 ) -> V_221 ;
}
#endif
V_199 -> V_210 = 0 ;
V_219 = V_220 -> V_53 ;
if ( V_53 < V_219 ) {
V_199 -> V_207 |= V_223 ;
V_219 = V_53 ;
}
F_167 ( V_220 ) ;
V_62 = F_168 ( V_220 , 0 , V_199 -> V_215 , V_219 ) ;
if ( V_199 -> V_204 ) {
struct V_110 * V_108 = (struct V_110 * ) V_199 -> V_204 ;
V_108 -> V_112 = V_113 ;
V_108 -> V_129 = 0 ;
V_108 -> V_118 = F_152 ( V_16 ) . V_10 ;
V_108 -> V_115 = F_4 ( F_152 ( V_16 ) . V_125 ) ;
V_199 -> V_210 = sizeof( * V_108 ) ;
}
if ( V_17 -> V_4 & V_193 )
F_151 ( V_199 , V_16 ) ;
if ( NULL == V_203 -> V_206 ) {
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_203 -> V_206 = & V_206 ;
}
V_203 -> V_206 -> V_213 = * F_158 ( V_16 ) ;
if ( V_4 & V_223 )
V_219 = V_220 -> V_53 ;
F_169 ( V_3 , V_16 ) ;
if ( V_17 -> V_15 && F_17 ( & V_3 -> V_22 ) <= V_3 -> V_148 / 2 ) {
V_158 = F_170 ( V_3 ) ;
if ( V_158 ) {
V_3 -> V_131 = V_158 ;
V_3 -> V_133 ( V_3 ) ;
}
}
F_171 ( V_2 , V_199 , V_203 -> V_206 , V_4 ) ;
V_90:
F_120 ( V_3 ) ;
return V_62 ? : V_219 ;
}
static void F_172 ( struct V_2 * V_3 , int V_53 )
{
F_173 () ;
}
struct V_2 *
F_174 ( struct V_31 * V_31 , int V_224 ,
struct V_81 * V_81 ,
struct V_225 * V_226 )
{
struct V_70 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_60 * V_60 = NULL ;
struct V_71 * V_72 = V_226 ? V_226 -> V_72 : NULL ;
unsigned int V_24 ;
F_80 ( ! V_33 ) ;
if ( V_224 < 0 || V_224 >= V_87 )
return NULL ;
if ( F_175 ( V_75 , V_85 , V_224 , & V_2 ) )
return NULL ;
if ( F_62 ( & V_227 , V_2 , V_72 , V_224 ) < 0 )
goto V_228;
V_3 = V_2 -> V_3 ;
F_176 ( V_3 , V_31 ) ;
if ( ! V_226 || V_226 -> V_24 < 32 )
V_24 = 32 ;
else
V_24 = V_226 -> V_24 ;
V_60 = F_42 ( sizeof( * V_60 ) + F_91 ( V_24 ) , V_76 ) ;
if ( ! V_60 )
goto V_229;
V_3 -> V_151 = F_172 ;
if ( V_226 && V_226 -> V_230 )
F_1 ( V_3 ) -> V_159 = V_226 -> V_230 ;
if ( F_57 ( V_3 , V_31 , 0 ) )
goto V_229;
V_17 = F_1 ( V_3 ) ;
V_17 -> V_4 |= V_5 ;
F_18 () ;
if ( ! V_33 [ V_224 ] . V_89 ) {
V_33 [ V_224 ] . V_24 = V_24 ;
F_177 ( V_33 [ V_224 ] . V_60 , V_60 ) ;
V_33 [ V_224 ] . V_72 = V_72 ;
V_33 [ V_224 ] . V_81 = V_81 ;
V_33 [ V_224 ] . F_68 = V_226 ? V_226 -> F_68 : NULL ;
V_33 [ V_224 ] . V_89 = 1 ;
} else {
F_9 ( V_60 ) ;
V_33 [ V_224 ] . V_89 ++ ;
}
F_28 () ;
return V_3 ;
V_229:
F_9 ( V_60 ) ;
F_178 ( V_3 ) ;
return NULL ;
V_228:
F_179 ( V_2 ) ;
return NULL ;
}
void
F_178 ( struct V_2 * V_3 )
{
F_180 ( V_3 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned int V_24 )
{
struct V_60 * V_184 , * V_183 ;
struct V_56 * V_57 = & V_33 [ V_3 -> V_58 ] ;
if ( V_24 < 32 )
V_24 = 32 ;
if ( F_91 ( V_57 -> V_24 ) < F_91 ( V_24 ) ) {
V_184 = F_42 ( sizeof( * V_184 ) + F_91 ( V_24 ) , V_40 ) ;
if ( ! V_184 )
return - V_66 ;
V_183 = F_182 ( V_57 -> V_60 , 1 ) ;
memcpy ( V_184 -> V_61 , V_183 -> V_61 , F_91 ( V_57 -> V_24 ) ) ;
F_177 ( V_57 -> V_60 , V_184 ) ;
F_183 ( V_183 , V_231 ) ;
}
V_57 -> V_24 = V_24 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , unsigned int V_24 )
{
int V_62 ;
F_18 () ;
V_62 = F_181 ( V_3 , V_24 ) ;
F_28 () ;
return V_62 ;
}
void F_185 ( struct V_2 * V_232 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_35 * V_36 ;
struct V_56 * V_57 = & V_33 [ V_232 -> V_58 ] ;
F_56 (sk, node, &tbl->mc_list)
F_144 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_186 ( struct V_2 * V_232 , unsigned int V_6 )
{
F_18 () ;
F_185 ( V_232 , V_6 ) ;
F_28 () ;
}
void F_187 ( int V_32 , unsigned int V_4 )
{
if ( ( unsigned int ) V_32 < V_87 )
V_33 [ V_32 ] . V_101 = V_4 ;
}
struct V_233 *
F_188 ( struct V_146 * V_16 , T_1 V_10 , T_1 V_234 , int type , int V_53 , int V_4 )
{
struct V_233 * V_235 ;
int V_38 = F_189 ( V_53 ) ;
V_235 = (struct V_233 * ) F_160 ( V_16 , F_190 ( V_38 ) ) ;
V_235 -> V_236 = type ;
V_235 -> V_237 = V_38 ;
V_235 -> V_238 = V_4 ;
V_235 -> V_239 = V_10 ;
V_235 -> V_240 = V_234 ;
if ( ! F_191 ( V_38 ) || F_190 ( V_38 ) - V_38 != 0 )
memset ( F_192 ( V_235 ) + V_53 , 0 , F_190 ( V_38 ) - V_38 ) ;
return V_235 ;
}
static int F_170 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
struct V_146 * V_16 = NULL ;
struct V_233 * V_235 ;
int V_53 , V_62 = - V_132 ;
int V_241 ;
F_193 ( V_17 -> V_72 ) ;
V_15 = V_17 -> V_15 ;
if ( V_15 == NULL ) {
V_62 = - V_114 ;
goto V_242;
}
V_241 = F_194 ( int , V_15 -> V_243 , V_244 ) ;
V_16 = F_195 ( V_3 , V_241 , 0 , V_76 ) ;
if ( ! V_16 )
goto V_242;
V_53 = V_15 -> V_245 ( V_16 , V_15 ) ;
if ( V_53 > 0 ) {
F_196 ( V_17 -> V_72 ) ;
if ( F_130 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_111 ( V_3 , V_16 ) ;
return 0 ;
}
V_235 = F_197 ( V_16 , V_15 , V_246 , sizeof( V_53 ) , V_247 ) ;
if ( ! V_235 )
goto V_242;
F_198 ( V_15 , V_235 ) ;
memcpy ( F_199 ( V_235 ) , & V_53 , sizeof( V_53 ) ) ;
if ( F_130 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_111 ( V_3 , V_16 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 ) ;
V_17 -> V_15 = NULL ;
F_196 ( V_17 -> V_72 ) ;
F_10 ( V_15 ) ;
return 0 ;
V_242:
F_196 ( V_17 -> V_72 ) ;
F_8 ( V_16 ) ;
return V_62 ;
}
int F_200 ( struct V_2 * V_135 , struct V_146 * V_16 ,
const struct V_233 * V_235 ,
struct V_248 * V_249 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
int V_158 ;
V_15 = F_42 ( sizeof( * V_15 ) , V_76 ) ;
if ( V_15 == NULL )
return - V_132 ;
V_15 -> V_245 = V_249 -> V_245 ;
V_15 -> V_18 = V_249 -> V_18 ;
V_15 -> V_235 = V_235 ;
V_15 -> V_175 = V_249 -> V_175 ;
V_15 -> V_243 = V_249 -> V_243 ;
F_32 ( & V_16 -> V_216 ) ;
V_15 -> V_16 = V_16 ;
V_3 = F_36 ( F_39 ( V_135 ) , V_135 -> V_58 , F_152 ( V_16 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_7 ( V_15 ) ;
return - V_136 ;
}
V_17 = F_1 ( V_3 ) ;
F_193 ( V_17 -> V_72 ) ;
if ( V_17 -> V_15 ) {
F_196 ( V_17 -> V_72 ) ;
F_7 ( V_15 ) ;
F_81 ( V_3 ) ;
return - V_65 ;
}
V_17 -> V_15 = V_15 ;
F_196 ( V_17 -> V_72 ) ;
V_158 = F_170 ( V_3 ) ;
F_81 ( V_3 ) ;
if ( V_158 )
return V_158 ;
return - V_250 ;
}
void F_201 ( struct V_146 * V_251 , struct V_233 * V_235 , int V_62 )
{
struct V_146 * V_16 ;
struct V_233 * V_252 ;
struct V_253 * V_254 ;
T_3 V_255 = sizeof( * V_254 ) ;
if ( V_62 )
V_255 += V_237 ( V_235 ) ;
V_16 = F_202 ( V_255 , V_76 ) ;
if ( ! V_16 ) {
struct V_2 * V_3 ;
V_3 = F_36 ( F_39 ( V_251 -> V_3 ) ,
V_251 -> V_3 -> V_58 ,
F_152 ( V_251 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_131 = V_132 ;
V_3 -> V_133 ( V_3 ) ;
F_81 ( V_3 ) ;
}
return;
}
V_252 = F_188 ( V_16 , F_152 ( V_251 ) . V_10 , V_235 -> V_240 ,
V_256 , V_255 , 0 ) ;
V_254 = F_199 ( V_252 ) ;
V_254 -> error = V_62 ;
memcpy ( & V_254 -> V_199 , V_235 , V_62 ? V_235 -> V_237 : sizeof( * V_235 ) ) ;
F_125 ( V_251 -> V_3 , V_16 , F_152 ( V_251 ) . V_10 , V_217 ) ;
}
int F_203 ( struct V_146 * V_16 , int (* V_15)( struct V_146 * ,
struct V_233 * ) )
{
struct V_233 * V_235 ;
int V_62 ;
while ( V_16 -> V_53 >= F_204 ( 0 ) ) {
int V_257 ;
V_235 = F_205 ( V_16 ) ;
V_62 = 0 ;
if ( V_235 -> V_237 < V_258 || V_16 -> V_53 < V_235 -> V_237 )
return 0 ;
if ( ! ( V_235 -> V_238 & V_259 ) )
goto V_260;
if ( V_235 -> V_236 < V_261 )
goto V_260;
V_62 = V_15 ( V_16 , V_235 ) ;
if ( V_62 == - V_250 )
goto V_262;
V_260:
if ( V_235 -> V_238 & V_263 || V_62 )
F_201 ( V_16 , V_235 , V_62 ) ;
V_262:
V_257 = F_190 ( V_235 -> V_237 ) ;
if ( V_257 > V_16 -> V_53 )
V_257 = V_16 -> V_53 ;
F_206 ( V_16 , V_257 ) ;
}
return 0 ;
}
int F_207 ( struct V_2 * V_3 , struct V_146 * V_16 , T_1 V_10 ,
unsigned int V_6 , int V_264 , T_5 V_4 )
{
int V_62 = 0 ;
if ( V_6 ) {
int V_265 = 0 ;
if ( V_264 ) {
F_32 ( & V_16 -> V_216 ) ;
V_265 = V_10 ;
}
V_62 = F_208 ( V_3 , V_16 , V_265 , V_6 , V_4 ) ;
}
if ( V_264 ) {
int V_266 ;
V_266 = F_209 ( V_3 , V_16 , V_10 ) ;
if ( ! V_62 || V_62 == - V_179 )
V_62 = V_266 ;
}
return V_62 ;
}
static struct V_2 * F_210 ( struct V_267 * V_234 , T_7 V_268 )
{
struct V_269 * V_270 = V_234 -> V_271 ;
int V_47 , V_272 ;
struct V_2 * V_273 ;
struct V_35 * V_36 ;
T_7 V_274 = 0 ;
for ( V_47 = 0 ; V_47 < V_87 ; V_47 ++ ) {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
for ( V_272 = 0 ; V_272 <= V_9 -> V_13 ; V_272 ++ ) {
F_37 (s, node, &hash->table[j]) {
if ( F_39 ( V_273 ) != F_211 ( V_234 ) )
continue;
if ( V_274 == V_268 ) {
V_270 -> V_275 = V_47 ;
V_270 -> V_276 = V_272 ;
return V_273 ;
}
++ V_274 ;
}
}
}
return NULL ;
}
static void * F_212 ( struct V_267 * V_234 , T_7 * V_268 )
__acquires( T_2 )
{
F_31 ( & T_2 ) ;
return * V_268 ? F_210 ( V_234 , * V_268 - 1 ) : V_277 ;
}
static void * F_213 ( struct V_267 * V_234 , void * V_278 , T_7 * V_268 )
{
struct V_2 * V_273 ;
struct V_269 * V_270 ;
int V_47 , V_272 ;
++ * V_268 ;
if ( V_278 == V_277 )
return F_210 ( V_234 , 0 ) ;
V_270 = V_234 -> V_271 ;
V_273 = V_278 ;
do {
V_273 = F_214 ( V_273 ) ;
} while ( V_273 && F_39 ( V_273 ) != F_211 ( V_234 ) );
if ( V_273 )
return V_273 ;
V_47 = V_270 -> V_275 ;
V_272 = V_270 -> V_276 + 1 ;
do {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
for (; V_272 <= V_9 -> V_13 ; V_272 ++ ) {
V_273 = F_215 ( & V_9 -> V_11 [ V_272 ] ) ;
while ( V_273 && F_39 ( V_273 ) != F_211 ( V_234 ) )
V_273 = F_214 ( V_273 ) ;
if ( V_273 ) {
V_270 -> V_275 = V_47 ;
V_270 -> V_276 = V_272 ;
return V_273 ;
}
}
V_272 = 0 ;
} while ( ++ V_47 < V_87 );
return NULL ;
}
static void F_216 ( struct V_267 * V_234 , void * V_278 )
__releases( T_2 )
{
F_33 ( & T_2 ) ;
}
static int F_217 ( struct V_267 * V_234 , void * V_278 )
{
if ( V_278 == V_277 ) {
F_218 ( V_234 ,
L_3
L_4 ) ;
} else {
struct V_2 * V_273 = V_278 ;
struct V_1 * V_17 = F_1 ( V_273 ) ;
F_219 ( V_234 , L_5 ,
V_273 ,
V_273 -> V_58 ,
V_17 -> V_10 ,
V_17 -> V_24 ? ( T_1 ) V_17 -> V_24 [ 0 ] : 0 ,
F_220 ( V_273 ) ,
F_221 ( V_273 ) ,
V_17 -> V_15 ,
F_17 ( & V_273 -> V_279 ) ,
F_17 ( & V_273 -> V_134 ) ,
F_222 ( V_273 )
) ;
}
return 0 ;
}
static int F_223 ( struct V_139 * V_139 , struct V_137 * V_137 )
{
return F_224 ( V_139 , V_137 , & V_280 ,
sizeof( struct V_269 ) ) ;
}
int F_225 ( struct V_281 * V_282 )
{
return F_226 ( & V_96 , V_282 ) ;
}
int F_227 ( struct V_281 * V_282 )
{
return F_228 ( & V_96 , V_282 ) ;
}
static int T_8 F_229 ( struct V_31 * V_31 )
{
#ifdef F_230
if ( ! F_231 ( V_31 , L_6 , 0 , & V_283 ) )
return - V_66 ;
#endif
return 0 ;
}
static void T_9 F_232 ( struct V_31 * V_31 )
{
#ifdef F_230
F_233 ( V_31 , L_6 ) ;
#endif
}
static void T_10 F_234 ( void )
{
struct V_60 * V_60 ;
int V_24 = 32 ;
V_60 = F_42 ( sizeof( * V_60 ) + F_91 ( V_24 ) , V_76 ) ;
if ( ! V_60 )
F_235 ( L_7 ) ;
F_18 () ;
V_33 [ V_284 ] . V_24 = V_24 ;
F_177 ( V_33 [ V_284 ] . V_60 , V_60 ) ;
V_33 [ V_284 ] . V_81 = V_285 ;
V_33 [ V_284 ] . V_89 = 1 ;
V_33 [ V_284 ] . V_101 = V_126 ;
F_28 () ;
}
static int T_10 F_236 ( void )
{
struct V_146 * V_286 ;
int V_47 ;
unsigned long V_287 ;
unsigned int V_288 ;
int V_62 = F_237 ( & V_77 , 0 ) ;
if ( V_62 != 0 )
goto V_90;
F_238 ( sizeof( struct V_289 ) > sizeof( V_286 -> V_15 ) ) ;
V_33 = F_239 ( V_87 , sizeof( * V_33 ) , V_76 ) ;
if ( ! V_33 )
goto F_235;
if ( V_290 >= ( 128 * 1024 ) )
V_287 = V_290 >> ( 21 - V_291 ) ;
else
V_287 = V_290 >> ( 23 - V_291 ) ;
V_288 = F_240 ( V_287 ) - 1 + V_291 ;
V_287 = ( 1UL << V_288 ) / sizeof( struct V_7 ) ;
V_288 = F_240 ( F_241 ( V_287 , ( unsigned long ) V_68 ) ) - 1 ;
for ( V_47 = 0 ; V_47 < V_87 ; V_47 ++ ) {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
V_9 -> V_11 = F_41 ( 1 * sizeof( * V_9 -> V_11 ) ) ;
if ( ! V_9 -> V_11 ) {
while ( V_47 -- > 0 )
F_45 ( V_33 [ V_47 ] . V_9 . V_11 ,
1 * sizeof( * V_9 -> V_11 ) ) ;
F_9 ( V_33 ) ;
goto F_235;
}
V_9 -> V_48 = V_288 ;
V_9 -> V_44 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_50 = V_51 ;
}
F_234 () ;
F_242 ( & V_292 ) ;
F_243 ( & V_293 ) ;
F_244 () ;
V_90:
return V_62 ;
F_235:
F_235 ( L_8 ) ;
}
