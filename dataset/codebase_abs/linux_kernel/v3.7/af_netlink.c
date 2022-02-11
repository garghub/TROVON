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
F_13 ( V_17 -> V_15 -> V_19 ) ;
F_7 ( V_17 -> V_15 ) ;
}
F_14 ( & V_3 -> V_20 ) ;
if ( ! F_15 ( V_3 , V_21 ) ) {
F_16 ( V_22 L_1 , V_3 ) ;
return;
}
F_17 ( F_18 ( & V_3 -> V_23 ) ) ;
F_17 ( F_18 ( & V_3 -> V_24 ) ) ;
F_17 ( F_1 ( V_3 ) -> V_25 ) ;
}
void F_19 ( void )
__acquires( T_2 )
{
F_20 () ;
F_21 ( & T_2 ) ;
if ( F_18 ( & V_26 ) ) {
F_22 ( V_27 , V_28 ) ;
F_23 ( & V_29 , & V_27 ) ;
for (; ; ) {
F_24 ( V_30 ) ;
if ( F_18 ( & V_26 ) == 0 )
break;
F_25 ( & T_2 ) ;
F_26 () ;
F_21 ( & T_2 ) ;
}
F_27 ( V_31 ) ;
F_28 ( & V_29 , & V_27 ) ;
}
}
void F_29 ( void )
__releases( T_2 )
{
F_25 ( & T_2 ) ;
F_30 ( & V_29 ) ;
}
static inline void
F_31 ( void )
{
F_32 ( & T_2 ) ;
F_33 ( & V_26 ) ;
F_34 ( & T_2 ) ;
}
static inline void
F_35 ( void )
{
if ( F_36 ( & V_26 ) )
F_30 ( & V_29 ) ;
}
static struct V_2 * F_37 ( struct V_32 * V_32 , int V_33 , T_1 V_10 )
{
struct V_8 * V_9 = & V_34 [ V_33 ] . V_9 ;
struct V_7 * V_35 ;
struct V_2 * V_3 ;
struct V_36 * V_37 ;
F_32 ( & T_2 ) ;
V_35 = F_5 ( V_9 , V_10 ) ;
F_38 (sk, node, head) {
if ( F_39 ( F_40 ( V_3 ) , V_32 ) && ( F_1 ( V_3 ) -> V_10 == V_10 ) ) {
F_41 ( V_3 ) ;
goto V_38;
}
}
V_3 = NULL ;
V_38:
F_34 ( & T_2 ) ;
return V_3 ;
}
static struct V_7 * F_42 ( T_3 V_39 )
{
if ( V_39 <= V_40 )
return F_43 ( V_39 , V_41 ) ;
else
return (struct V_7 * )
F_44 ( V_41 | V_42 ,
F_45 ( V_39 ) ) ;
}
static void F_46 ( struct V_7 * V_11 , T_3 V_39 )
{
if ( V_39 <= V_40 )
F_9 ( V_11 ) ;
else
F_47 ( ( unsigned long ) V_11 , F_45 ( V_39 ) ) ;
}
static int F_48 ( struct V_8 * V_9 , int V_43 )
{
unsigned int V_44 , V_13 , V_45 ;
T_3 V_46 , V_39 ;
struct V_7 * V_47 , * V_11 ;
int V_48 ;
V_44 = V_13 = V_9 -> V_13 ;
V_46 = V_39 = ( V_13 + 1 ) * sizeof( * V_11 ) ;
V_45 = V_9 -> V_45 ;
if ( V_43 ) {
if ( ++ V_45 > V_9 -> V_49 )
return 0 ;
V_13 = V_13 * 2 + 1 ;
V_39 *= 2 ;
}
V_11 = F_42 ( V_39 ) ;
if ( ! V_11 )
return 0 ;
V_47 = V_9 -> V_11 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_45 = V_45 ;
F_49 ( & V_9 -> V_12 , sizeof( V_9 -> V_12 ) ) ;
for ( V_48 = 0 ; V_48 <= V_44 ; V_48 ++ ) {
struct V_2 * V_3 ;
struct V_36 * V_37 , * V_50 ;
F_50 (sk, node, tmp, &otable[i])
F_51 ( V_3 , F_5 ( V_9 , F_1 ( V_3 ) -> V_10 ) ) ;
}
F_46 ( V_47 , V_46 ) ;
V_9 -> V_51 = V_52 + 10 * 60 * V_53 ;
return 1 ;
}
static inline int F_52 ( struct V_8 * V_9 , int V_54 )
{
int V_55 = V_9 -> V_56 >> V_9 -> V_45 ;
if ( F_53 ( V_55 > 1 ) && F_48 ( V_9 , 1 ) )
return 1 ;
if ( F_53 ( V_54 > V_55 ) && F_54 ( V_52 , V_9 -> V_51 ) ) {
F_48 ( V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_55 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = & V_34 [ V_3 -> V_59 ] ;
struct V_36 * V_37 ;
unsigned long V_13 ;
unsigned int V_48 ;
struct V_60 * V_60 ;
V_60 = F_56 ( V_58 -> V_60 ) ;
if ( ! V_60 )
return;
for ( V_48 = 0 ; V_48 < F_57 ( V_58 -> V_25 ) ; V_48 ++ ) {
V_13 = 0 ;
F_58 (sk, node, &tbl->mc_list) {
if ( V_48 < F_57 ( F_1 ( V_3 ) -> V_61 ) )
V_13 |= F_1 ( V_3 ) -> V_25 [ V_48 ] ;
}
V_60 -> V_62 [ V_48 ] = V_13 ;
}
}
static int F_59 ( struct V_2 * V_3 , struct V_32 * V_32 , T_1 V_10 )
{
struct V_8 * V_9 = & V_34 [ V_3 -> V_59 ] . V_9 ;
struct V_7 * V_35 ;
int V_63 = - V_64 ;
struct V_2 * V_65 ;
struct V_36 * V_37 ;
int V_54 ;
F_19 () ;
V_35 = F_5 ( V_9 , V_10 ) ;
V_54 = 0 ;
F_38 (osk, node, head) {
if ( F_39 ( F_40 ( V_65 ) , V_32 ) && ( F_1 ( V_65 ) -> V_10 == V_10 ) )
break;
V_54 ++ ;
}
if ( V_37 )
goto V_63;
V_63 = - V_66 ;
if ( F_1 ( V_3 ) -> V_10 )
goto V_63;
V_63 = - V_67 ;
if ( V_68 > 32 && F_53 ( V_9 -> V_56 >= V_69 ) )
goto V_63;
if ( V_54 && F_52 ( V_9 , V_54 ) )
V_35 = F_5 ( V_9 , V_10 ) ;
V_9 -> V_56 ++ ;
F_1 ( V_3 ) -> V_10 = V_10 ;
F_60 ( V_3 , V_35 ) ;
V_63 = 0 ;
V_63:
F_29 () ;
return V_63 ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_19 () ;
if ( F_62 ( V_3 ) )
V_34 [ V_3 -> V_59 ] . V_9 . V_56 -- ;
if ( F_1 ( V_3 ) -> V_70 )
F_63 ( V_3 ) ;
F_29 () ;
}
static int F_64 ( struct V_32 * V_32 , struct V_71 * V_2 ,
struct V_72 * V_73 , int V_33 )
{
struct V_2 * V_3 ;
struct V_1 * V_17 ;
V_2 -> V_74 = & V_75 ;
V_3 = F_65 ( V_32 , V_76 , V_77 , & V_78 ) ;
if ( ! V_3 )
return - V_67 ;
F_66 ( V_2 , V_3 ) ;
V_17 = F_1 ( V_3 ) ;
if ( V_73 ) {
V_17 -> V_73 = V_73 ;
} else {
V_17 -> V_73 = & V_17 -> V_79 ;
F_67 ( V_17 -> V_73 ) ;
}
F_68 ( & V_17 -> V_27 ) ;
V_3 -> V_80 = F_12 ;
V_3 -> V_59 = V_33 ;
return 0 ;
}
static int F_69 ( struct V_32 * V_32 , struct V_71 * V_2 , int V_33 ,
int V_81 )
{
struct V_19 * V_19 = NULL ;
struct V_72 * V_73 ;
struct V_1 * V_17 ;
void (* F_70)( int V_6 );
int V_63 = 0 ;
V_2 -> V_82 = V_83 ;
if ( V_2 -> type != V_84 && V_2 -> type != V_85 )
return - V_86 ;
if ( V_33 < 0 || V_33 >= V_87 )
return - V_88 ;
F_31 () ;
#ifdef F_71
if ( ! V_34 [ V_33 ] . V_89 ) {
F_35 () ;
F_72 ( L_2 , V_76 , V_33 ) ;
F_31 () ;
}
#endif
if ( V_34 [ V_33 ] . V_89 &&
F_73 ( V_34 [ V_33 ] . V_19 ) )
V_19 = V_34 [ V_33 ] . V_19 ;
else
V_63 = - V_88 ;
V_73 = V_34 [ V_33 ] . V_73 ;
F_70 = V_34 [ V_33 ] . F_70 ;
F_35 () ;
if ( V_63 < 0 )
goto V_90;
V_63 = F_64 ( V_32 , V_2 , V_73 , V_33 ) ;
if ( V_63 < 0 )
goto V_91;
F_74 () ;
F_75 ( V_32 , & V_78 , 1 ) ;
F_76 () ;
V_17 = F_1 ( V_2 -> V_3 ) ;
V_17 -> V_19 = V_19 ;
V_17 -> V_92 = F_70 ;
V_90:
return V_63 ;
V_91:
F_13 ( V_19 ) ;
goto V_90;
}
static int F_77 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 ;
if ( ! V_3 )
return 0 ;
F_61 ( V_3 ) ;
F_78 ( V_3 ) ;
V_17 = F_1 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_79 ( & V_17 -> V_27 ) ;
F_14 ( & V_3 -> V_93 ) ;
if ( V_17 -> V_10 ) {
struct V_94 V_95 = {
. V_32 = F_40 ( V_3 ) ,
. V_33 = V_3 -> V_59 ,
. V_10 = V_17 -> V_10 ,
} ;
F_80 ( & V_96 ,
V_97 , & V_95 ) ;
}
F_13 ( V_17 -> V_19 ) ;
F_19 () ;
if ( F_3 ( V_3 ) ) {
F_81 ( V_34 [ V_3 -> V_59 ] . V_89 == 0 ) ;
if ( -- V_34 [ V_3 -> V_59 ] . V_89 == 0 ) {
struct V_60 * V_98 ;
V_98 = F_56 ( V_34 [ V_3 -> V_59 ] . V_60 ) ;
F_82 ( V_34 [ V_3 -> V_59 ] . V_60 , NULL ) ;
F_83 ( V_98 , V_99 ) ;
V_34 [ V_3 -> V_59 ] . V_19 = NULL ;
V_34 [ V_3 -> V_59 ] . F_70 = NULL ;
V_34 [ V_3 -> V_59 ] . V_4 = 0 ;
V_34 [ V_3 -> V_59 ] . V_89 = 0 ;
}
} else if ( V_17 -> V_70 ) {
F_55 ( V_3 ) ;
}
F_29 () ;
F_9 ( V_17 -> V_25 ) ;
V_17 -> V_25 = NULL ;
F_74 () ;
F_75 ( F_40 ( V_3 ) , & V_78 , - 1 ) ;
F_76 () ;
F_84 ( V_3 ) ;
return 0 ;
}
static int F_85 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_32 * V_32 = F_40 ( V_3 ) ;
struct V_8 * V_9 = & V_34 [ V_3 -> V_59 ] . V_9 ;
struct V_7 * V_35 ;
struct V_2 * V_65 ;
struct V_36 * V_37 ;
T_4 V_10 = F_86 ( V_28 ) ;
int V_63 ;
static T_4 V_100 = - 4097 ;
V_101:
F_87 () ;
F_19 () ;
V_35 = F_5 ( V_9 , V_10 ) ;
F_38 (osk, node, head) {
if ( ! F_39 ( F_40 ( V_65 ) , V_32 ) )
continue;
if ( F_1 ( V_65 ) -> V_10 == V_10 ) {
V_10 = V_100 -- ;
if ( V_100 > - 4097 )
V_100 = - 4097 ;
F_29 () ;
goto V_101;
}
}
F_29 () ;
V_63 = F_59 ( V_3 , V_32 , V_10 ) ;
if ( V_63 == - V_64 )
goto V_101;
if ( V_63 == - V_66 )
V_63 = 0 ;
return V_63 ;
}
static inline int F_88 ( const struct V_71 * V_2 , unsigned int V_102 )
{
return ( V_34 [ V_2 -> V_3 -> V_59 ] . V_4 & V_102 ) ||
F_89 ( V_103 ) ;
}
static void
F_90 ( struct V_2 * V_3 , unsigned int V_70 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_70 && ! V_70 )
F_63 ( V_3 ) ;
else if ( ! V_17 -> V_70 && V_70 )
F_91 ( V_3 , & V_34 [ V_3 -> V_59 ] . V_104 ) ;
V_17 -> V_70 = V_70 ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_25 ;
unsigned long * V_105 ;
int V_63 = 0 ;
F_19 () ;
V_25 = V_34 [ V_3 -> V_59 ] . V_25 ;
if ( ! V_34 [ V_3 -> V_59 ] . V_89 ) {
V_63 = - V_106 ;
goto V_107;
}
if ( V_17 -> V_61 >= V_25 )
goto V_107;
V_105 = F_93 ( V_17 -> V_25 , F_94 ( V_25 ) , V_41 ) ;
if ( V_105 == NULL ) {
V_63 = - V_67 ;
goto V_107;
}
memset ( ( char * ) V_105 + F_94 ( V_17 -> V_61 ) , 0 ,
F_94 ( V_25 ) - F_94 ( V_17 -> V_61 ) ) ;
V_17 -> V_25 = V_105 ;
V_17 -> V_61 = V_25 ;
V_107:
F_29 () ;
return V_63 ;
}
static int V_92 ( struct V_71 * V_2 , struct V_108 * V_109 ,
int V_110 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_32 * V_32 = F_40 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
int V_63 ;
if ( V_112 -> V_113 != V_114 )
return - V_115 ;
if ( V_112 -> V_116 ) {
if ( ! F_88 ( V_2 , V_117 ) )
return - V_118 ;
V_63 = F_92 ( V_3 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_17 -> V_10 ) {
if ( V_112 -> V_119 != V_17 -> V_10 )
return - V_115 ;
} else {
V_63 = V_112 -> V_119 ?
F_59 ( V_3 , V_32 , V_112 -> V_119 ) :
F_85 ( V_2 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_112 -> V_116 && ( V_17 -> V_25 == NULL || ! ( T_1 ) V_17 -> V_25 [ 0 ] ) )
return 0 ;
F_19 () ;
F_90 ( V_3 , V_17 -> V_70 +
F_95 ( V_112 -> V_116 ) -
F_95 ( V_17 -> V_25 [ 0 ] ) ) ;
V_17 -> V_25 [ 0 ] = ( V_17 -> V_25 [ 0 ] & ~ 0xffffffffUL ) | V_112 -> V_116 ;
F_55 ( V_3 ) ;
F_29 () ;
if ( V_17 -> V_92 && V_17 -> V_25 [ 0 ] ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_17 -> V_61 ; V_48 ++ ) {
if ( F_96 ( V_48 , V_17 -> V_25 ) )
V_17 -> V_92 ( V_48 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_71 * V_2 , struct V_108 * V_109 ,
int V_120 , int V_4 )
{
int V_63 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
if ( V_120 < sizeof( V_109 -> V_121 ) )
return - V_115 ;
if ( V_109 -> V_121 == V_122 ) {
V_3 -> V_123 = V_124 ;
V_17 -> V_125 = 0 ;
V_17 -> V_126 = 0 ;
return 0 ;
}
if ( V_109 -> V_121 != V_114 )
return - V_115 ;
if ( V_112 -> V_116 && ! F_88 ( V_2 , V_127 ) )
return - V_118 ;
if ( ! V_17 -> V_10 )
V_63 = F_85 ( V_2 ) ;
if ( V_63 == 0 ) {
V_3 -> V_123 = V_128 ;
V_17 -> V_125 = V_112 -> V_119 ;
V_17 -> V_126 = F_98 ( V_112 -> V_116 ) ;
}
return V_63 ;
}
static int F_99 ( struct V_71 * V_2 , struct V_108 * V_109 ,
int * V_110 , int V_129 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_100 ( struct V_111 * , V_112 , V_109 ) ;
V_112 -> V_113 = V_114 ;
V_112 -> V_130 = 0 ;
* V_110 = sizeof( * V_112 ) ;
if ( V_129 ) {
V_112 -> V_119 = V_17 -> V_125 ;
V_112 -> V_116 = F_4 ( V_17 -> V_126 ) ;
} else {
V_112 -> V_119 = V_17 -> V_10 ;
V_112 -> V_116 = V_17 -> V_25 ? V_17 -> V_25 [ 0 ] : 0 ;
}
return 0 ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! ( V_17 -> V_4 & V_131 ) ) {
if ( ! F_102 ( 0 , & F_1 ( V_3 ) -> V_82 ) ) {
V_3 -> V_132 = V_133 ;
V_3 -> V_134 ( V_3 ) ;
}
}
F_33 ( & V_3 -> V_135 ) ;
}
static struct V_2 * F_103 ( struct V_2 * V_136 , T_1 V_10 )
{
struct V_2 * V_2 ;
struct V_1 * V_17 ;
V_2 = F_37 ( F_40 ( V_136 ) , V_136 -> V_59 , V_10 ) ;
if ( ! V_2 )
return F_104 ( - V_137 ) ;
V_17 = F_1 ( V_2 ) ;
if ( V_2 -> V_123 == V_128 &&
V_17 -> V_125 != F_1 ( V_136 ) -> V_10 ) {
F_84 ( V_2 ) ;
return F_104 ( - V_137 ) ;
}
return V_2 ;
}
struct V_2 * F_105 ( struct V_138 * V_139 )
{
struct V_140 * V_140 = V_139 -> V_141 . V_142 -> V_143 ;
struct V_2 * V_2 ;
if ( ! F_106 ( V_140 -> V_144 ) )
return F_104 ( - V_145 ) ;
V_2 = F_107 ( V_140 ) -> V_3 ;
if ( V_2 -> V_146 != V_114 )
return F_104 ( - V_115 ) ;
F_41 ( V_2 ) ;
return V_2 ;
}
int F_108 ( struct V_2 * V_3 , struct V_147 * V_16 ,
long * V_148 , struct V_2 * V_136 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_149 ||
F_96 ( 0 , & V_17 -> V_82 ) ) {
F_22 ( V_27 , V_28 ) ;
if ( ! * V_148 ) {
if ( ! V_136 || F_3 ( V_136 ) )
F_101 ( V_3 ) ;
F_84 ( V_3 ) ;
F_8 ( V_16 ) ;
return - V_150 ;
}
F_27 ( V_151 ) ;
F_109 ( & V_17 -> V_27 , & V_27 ) ;
if ( ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_149 ||
F_96 ( 0 , & V_17 -> V_82 ) ) &&
! F_15 ( V_3 , V_21 ) )
* V_148 = F_110 ( * V_148 ) ;
F_27 ( V_31 ) ;
F_28 ( & V_17 -> V_27 , & V_27 ) ;
F_84 ( V_3 ) ;
if ( F_111 ( V_28 ) ) {
F_8 ( V_16 ) ;
return F_112 ( * V_148 ) ;
}
return 1 ;
}
F_113 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , struct V_147 * V_16 )
{
int V_54 = V_16 -> V_54 ;
F_115 ( & V_3 -> V_20 , V_16 ) ;
V_3 -> V_152 ( V_3 , V_54 ) ;
return V_54 ;
}
int F_116 ( struct V_2 * V_3 , struct V_147 * V_16 )
{
int V_54 = F_114 ( V_3 , V_16 ) ;
F_84 ( V_3 ) ;
return V_54 ;
}
void F_117 ( struct V_2 * V_3 , struct V_147 * V_16 )
{
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
}
static struct V_147 * F_118 ( struct V_147 * V_16 , T_5 V_153 )
{
int V_154 ;
F_119 ( V_16 ) ;
V_154 = V_16 -> V_155 - V_16 -> V_156 ;
if ( V_154 * 2 < V_16 -> V_157 )
return V_16 ;
if ( F_120 ( V_16 ) ) {
struct V_147 * V_158 = F_121 ( V_16 , V_153 ) ;
if ( ! V_158 )
return V_16 ;
F_11 ( V_16 ) ;
V_16 = V_158 ;
}
if ( ! F_122 ( V_16 , 0 , - V_154 , V_153 ) )
V_16 -> V_157 -= V_154 ;
return V_16 ;
}
static void F_123 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_124 ( & V_3 -> V_20 ) )
F_125 ( 0 , & V_17 -> V_82 ) ;
if ( ! F_96 ( 0 , & V_17 -> V_82 ) )
F_126 ( & V_17 -> V_27 ) ;
}
static int F_127 ( struct V_2 * V_3 , struct V_147 * V_16 ,
struct V_2 * V_136 )
{
int V_159 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_159 = - V_137 ;
if ( V_17 -> V_160 != NULL ) {
V_159 = V_16 -> V_54 ;
F_113 ( V_16 , V_3 ) ;
F_128 ( V_16 ) . V_136 = V_136 ;
V_17 -> V_160 ( V_16 ) ;
F_11 ( V_16 ) ;
} else {
F_8 ( V_16 ) ;
}
F_84 ( V_3 ) ;
return V_159 ;
}
int F_129 ( struct V_2 * V_136 , struct V_147 * V_16 ,
T_1 V_10 , int V_161 )
{
struct V_2 * V_3 ;
int V_63 ;
long V_148 ;
V_16 = F_118 ( V_16 , F_130 () ) ;
V_148 = F_131 ( V_136 , V_161 ) ;
V_101:
V_3 = F_103 ( V_136 , V_10 ) ;
if ( F_132 ( V_3 ) ) {
F_8 ( V_16 ) ;
return F_133 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_127 ( V_3 , V_16 , V_136 ) ;
if ( F_134 ( V_3 , V_16 ) ) {
V_63 = V_16 -> V_54 ;
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
return V_63 ;
}
V_63 = F_108 ( V_3 , V_16 , & V_148 , V_136 ) ;
if ( V_63 == 1 )
goto V_101;
if ( V_63 )
return V_63 ;
return F_116 ( V_3 , V_16 ) ;
}
int F_135 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_162 = 0 ;
struct V_60 * V_60 ;
F_81 ( ! F_3 ( V_3 ) ) ;
F_136 () ;
V_60 = F_137 ( V_34 [ V_3 -> V_59 ] . V_60 ) ;
if ( V_60 && V_6 - 1 < V_34 [ V_3 -> V_59 ] . V_25 )
V_162 = F_96 ( V_6 - 1 , V_60 -> V_62 ) ;
F_138 () ;
return V_162 ;
}
static int F_139 ( struct V_2 * V_3 , struct V_147 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) <= V_3 -> V_149 &&
! F_96 ( 0 , & V_17 -> V_82 ) ) {
F_113 ( V_16 , V_3 ) ;
F_114 ( V_3 , V_16 ) ;
return F_18 ( & V_3 -> V_23 ) > ( V_3 -> V_149 >> 1 ) ;
}
return - 1 ;
}
static int F_140 ( struct V_2 * V_3 ,
struct V_163 * V_164 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_165 ;
if ( V_164 -> V_166 == V_3 )
goto V_90;
if ( V_17 -> V_10 == V_164 -> V_10 || V_164 -> V_6 - 1 >= V_17 -> V_61 ||
! F_96 ( V_164 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_90;
if ( ! F_39 ( F_40 ( V_3 ) , V_164 -> V_32 ) )
goto V_90;
if ( V_164 -> V_167 ) {
F_101 ( V_3 ) ;
goto V_90;
}
F_41 ( V_3 ) ;
if ( V_164 -> V_168 == NULL ) {
if ( F_120 ( V_164 -> V_16 ) ) {
V_164 -> V_168 = F_121 ( V_164 -> V_16 , V_164 -> V_153 ) ;
} else {
V_164 -> V_168 = F_141 ( V_164 -> V_16 ) ;
F_119 ( V_164 -> V_168 ) ;
}
}
if ( V_164 -> V_168 == NULL ) {
F_101 ( V_3 ) ;
V_164 -> V_167 = 1 ;
if ( V_17 -> V_4 & V_169 )
V_164 -> V_170 = 1 ;
} else if ( V_164 -> V_171 && V_164 -> V_171 ( V_3 , V_164 -> V_168 , V_164 -> V_172 ) ) {
F_8 ( V_164 -> V_168 ) ;
V_164 -> V_168 = NULL ;
} else if ( F_134 ( V_3 , V_164 -> V_168 ) ) {
F_8 ( V_164 -> V_168 ) ;
V_164 -> V_168 = NULL ;
} else if ( ( V_165 = F_139 ( V_3 , V_164 -> V_168 ) ) < 0 ) {
F_101 ( V_3 ) ;
if ( V_17 -> V_4 & V_169 )
V_164 -> V_170 = 1 ;
} else {
V_164 -> V_173 |= V_165 ;
V_164 -> V_174 = 1 ;
V_164 -> V_168 = NULL ;
}
F_84 ( V_3 ) ;
V_90:
return 0 ;
}
int F_142 ( struct V_2 * V_136 , struct V_147 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_153 ,
int (* F_143)( struct V_2 * V_175 , struct V_147 * V_16 , void * V_176 ) ,
void * V_177 )
{
struct V_32 * V_32 = F_40 ( V_136 ) ;
struct V_163 V_178 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
V_16 = F_118 ( V_16 , V_153 ) ;
V_178 . V_166 = V_136 ;
V_178 . V_32 = V_32 ;
V_178 . V_10 = V_10 ;
V_178 . V_6 = V_6 ;
V_178 . V_167 = 0 ;
V_178 . V_170 = 0 ;
V_178 . V_173 = 0 ;
V_178 . V_174 = 0 ;
V_178 . V_153 = V_153 ;
V_178 . V_16 = V_16 ;
V_178 . V_168 = NULL ;
V_178 . V_171 = F_143 ;
V_178 . V_172 = V_177 ;
F_31 () ;
F_58 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
F_140 ( V_3 , & V_178 ) ;
F_11 ( V_16 ) ;
F_35 () ;
if ( V_178 . V_170 ) {
F_8 ( V_178 . V_168 ) ;
return - V_133 ;
}
F_11 ( V_178 . V_168 ) ;
if ( V_178 . V_174 ) {
if ( V_178 . V_173 && ( V_153 & V_179 ) )
F_144 () ;
return 0 ;
}
return - V_180 ;
}
int F_145 ( struct V_2 * V_136 , struct V_147 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_153 )
{
return F_142 ( V_136 , V_16 , V_10 , V_6 , V_153 ,
NULL , NULL ) ;
}
static int F_146 ( struct V_2 * V_3 , struct V_181 * V_164 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_159 = 0 ;
if ( V_3 == V_164 -> V_166 )
goto V_90;
if ( ! F_39 ( F_40 ( V_3 ) , F_40 ( V_164 -> V_166 ) ) )
goto V_90;
if ( V_17 -> V_10 == V_164 -> V_10 || V_164 -> V_6 - 1 >= V_17 -> V_61 ||
! F_96 ( V_164 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_90;
if ( V_164 -> V_182 == V_133 && V_17 -> V_4 & V_131 ) {
V_159 = 1 ;
goto V_90;
}
V_3 -> V_132 = V_164 -> V_182 ;
V_3 -> V_134 ( V_3 ) ;
V_90:
return V_159 ;
}
int F_147 ( struct V_2 * V_136 , T_1 V_10 , T_1 V_6 , int V_182 )
{
struct V_181 V_178 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
int V_159 = 0 ;
V_178 . V_166 = V_136 ;
V_178 . V_10 = V_10 ;
V_178 . V_6 = V_6 ;
V_178 . V_182 = - V_182 ;
F_32 ( & T_2 ) ;
F_58 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
V_159 += F_146 ( V_3 , & V_178 ) ;
F_34 ( & T_2 ) ;
return V_159 ;
}
static void F_148 ( struct V_1 * V_17 ,
unsigned int V_6 ,
int V_183 )
{
int V_98 , V_184 = ! ! V_183 , V_70 ;
V_98 = F_96 ( V_6 - 1 , V_17 -> V_25 ) ;
V_70 = V_17 -> V_70 - V_98 + V_184 ;
if ( V_184 )
F_149 ( V_6 - 1 , V_17 -> V_25 ) ;
else
F_150 ( V_6 - 1 , V_17 -> V_25 ) ;
F_90 ( & V_17 -> V_3 , V_70 ) ;
F_55 ( & V_17 -> V_3 ) ;
}
static int F_151 ( struct V_71 * V_2 , int V_185 , int V_186 ,
char T_6 * V_187 , unsigned int V_188 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_165 = 0 ;
int V_63 ;
if ( V_185 != V_189 )
return - V_190 ;
if ( V_188 >= sizeof( int ) &&
F_152 ( V_165 , ( unsigned int T_6 * ) V_187 ) )
return - V_191 ;
switch ( V_186 ) {
case V_192 :
if ( V_165 )
V_17 -> V_4 |= V_193 ;
else
V_17 -> V_4 &= ~ V_193 ;
V_63 = 0 ;
break;
case V_194 :
case V_195 : {
if ( ! F_88 ( V_2 , V_117 ) )
return - V_118 ;
V_63 = F_92 ( V_3 ) ;
if ( V_63 )
return V_63 ;
if ( ! V_165 || V_165 - 1 >= V_17 -> V_61 )
return - V_115 ;
F_19 () ;
F_148 ( V_17 , V_165 ,
V_186 == V_194 ) ;
F_29 () ;
if ( V_17 -> V_92 )
V_17 -> V_92 ( V_165 ) ;
V_63 = 0 ;
break;
}
case V_196 :
if ( V_165 )
V_17 -> V_4 |= V_169 ;
else
V_17 -> V_4 &= ~ V_169 ;
V_63 = 0 ;
break;
case V_197 :
if ( V_165 ) {
V_17 -> V_4 |= V_131 ;
F_125 ( 0 , & V_17 -> V_82 ) ;
F_126 ( & V_17 -> V_27 ) ;
} else {
V_17 -> V_4 &= ~ V_131 ;
}
V_63 = 0 ;
break;
default:
V_63 = - V_190 ;
}
return V_63 ;
}
static int F_153 ( struct V_71 * V_2 , int V_185 , int V_186 ,
char T_6 * V_187 , int T_6 * V_188 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_54 , V_165 , V_63 ;
if ( V_185 != V_189 )
return - V_190 ;
if ( F_152 ( V_54 , V_188 ) )
return - V_191 ;
if ( V_54 < 0 )
return - V_115 ;
switch ( V_186 ) {
case V_192 :
if ( V_54 < sizeof( int ) )
return - V_115 ;
V_54 = sizeof( int ) ;
V_165 = V_17 -> V_4 & V_193 ? 1 : 0 ;
if ( F_154 ( V_54 , V_188 ) ||
F_154 ( V_165 , V_187 ) )
return - V_191 ;
V_63 = 0 ;
break;
case V_196 :
if ( V_54 < sizeof( int ) )
return - V_115 ;
V_54 = sizeof( int ) ;
V_165 = V_17 -> V_4 & V_169 ? 1 : 0 ;
if ( F_154 ( V_54 , V_188 ) ||
F_154 ( V_165 , V_187 ) )
return - V_191 ;
V_63 = 0 ;
break;
case V_197 :
if ( V_54 < sizeof( int ) )
return - V_115 ;
V_54 = sizeof( int ) ;
V_165 = V_17 -> V_4 & V_131 ? 1 : 0 ;
if ( F_154 ( V_54 , V_188 ) ||
F_154 ( V_165 , V_187 ) )
return - V_191 ;
V_63 = 0 ;
break;
default:
V_63 = - V_190 ;
}
return V_63 ;
}
static void F_155 ( struct V_198 * V_199 , struct V_147 * V_16 )
{
struct V_200 V_178 ;
V_178 . V_6 = F_128 ( V_16 ) . V_126 ;
F_156 ( V_199 , V_189 , V_192 , sizeof( V_178 ) , & V_178 ) ;
}
static int F_157 ( struct V_201 * V_201 , struct V_71 * V_2 ,
struct V_198 * V_199 , T_3 V_54 )
{
struct V_202 * V_203 = F_158 ( V_201 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_109 = V_199 -> V_204 ;
T_1 V_125 ;
T_1 V_126 ;
struct V_147 * V_16 ;
int V_63 ;
struct V_205 V_206 ;
if ( V_199 -> V_207 & V_208 )
return - V_209 ;
if ( NULL == V_203 -> V_206 )
V_203 -> V_206 = & V_206 ;
V_63 = F_159 ( V_2 , V_199 , V_203 -> V_206 , true ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_199 -> V_210 ) {
V_63 = - V_115 ;
if ( V_109 -> V_113 != V_114 )
goto V_90;
V_125 = V_109 -> V_119 ;
V_126 = F_98 ( V_109 -> V_116 ) ;
V_63 = - V_118 ;
if ( ( V_126 || V_125 ) &&
! F_88 ( V_2 , V_127 ) )
goto V_90;
} else {
V_125 = V_17 -> V_125 ;
V_126 = V_17 -> V_126 ;
}
if ( ! V_17 -> V_10 ) {
V_63 = F_85 ( V_2 ) ;
if ( V_63 )
goto V_90;
}
V_63 = - V_211 ;
if ( V_54 > V_3 -> V_212 - 32 )
goto V_90;
V_63 = - V_133 ;
V_16 = F_160 ( V_54 , V_77 ) ;
if ( V_16 == NULL )
goto V_90;
F_128 ( V_16 ) . V_10 = V_17 -> V_10 ;
F_128 ( V_16 ) . V_126 = V_126 ;
F_128 ( V_16 ) . V_213 = V_203 -> V_206 -> V_213 ;
V_63 = - V_191 ;
if ( F_161 ( F_162 ( V_16 , V_54 ) , V_199 -> V_214 , V_54 ) ) {
F_8 ( V_16 ) ;
goto V_90;
}
V_63 = F_163 ( V_3 , V_16 ) ;
if ( V_63 ) {
F_8 ( V_16 ) ;
goto V_90;
}
if ( V_126 ) {
F_33 ( & V_16 -> V_215 ) ;
F_145 ( V_3 , V_16 , V_125 , V_126 , V_77 ) ;
}
V_63 = F_129 ( V_3 , V_16 , V_125 , V_199 -> V_207 & V_216 ) ;
V_90:
F_164 ( V_203 -> V_206 ) ;
return V_63 ;
}
static int F_165 ( struct V_201 * V_201 , struct V_71 * V_2 ,
struct V_198 * V_199 , T_3 V_54 ,
int V_4 )
{
struct V_202 * V_203 = F_158 ( V_201 ) ;
struct V_205 V_206 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_217 = V_4 & V_216 ;
T_3 V_218 ;
struct V_147 * V_16 , * V_219 ;
int V_63 , V_159 ;
if ( V_4 & V_208 )
return - V_209 ;
V_218 = 0 ;
V_16 = F_166 ( V_3 , V_4 , V_217 , & V_63 ) ;
if ( V_16 == NULL )
goto V_90;
V_219 = V_16 ;
#ifdef F_167
if ( F_53 ( F_168 ( V_16 ) -> V_220 ) ) {
if ( V_4 & V_221 )
V_219 = F_168 ( V_16 ) -> V_220 ;
}
#endif
V_199 -> V_210 = 0 ;
V_218 = V_219 -> V_54 ;
if ( V_54 < V_218 ) {
V_199 -> V_207 |= V_222 ;
V_218 = V_54 ;
}
F_169 ( V_219 ) ;
V_63 = F_170 ( V_219 , 0 , V_199 -> V_214 , V_218 ) ;
if ( V_199 -> V_204 ) {
struct V_111 * V_109 = (struct V_111 * ) V_199 -> V_204 ;
V_109 -> V_113 = V_114 ;
V_109 -> V_130 = 0 ;
V_109 -> V_119 = F_128 ( V_16 ) . V_10 ;
V_109 -> V_116 = F_4 ( F_128 ( V_16 ) . V_126 ) ;
V_199 -> V_210 = sizeof( * V_109 ) ;
}
if ( V_17 -> V_4 & V_193 )
F_155 ( V_199 , V_16 ) ;
if ( NULL == V_203 -> V_206 ) {
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_203 -> V_206 = & V_206 ;
}
V_203 -> V_206 -> V_213 = * F_171 ( V_16 ) ;
if ( V_4 & V_222 )
V_218 = V_219 -> V_54 ;
F_172 ( V_3 , V_16 ) ;
if ( V_17 -> V_15 && F_18 ( & V_3 -> V_23 ) <= V_3 -> V_149 / 2 ) {
V_159 = F_173 ( V_3 ) ;
if ( V_159 ) {
V_3 -> V_132 = V_159 ;
V_3 -> V_134 ( V_3 ) ;
}
}
F_174 ( V_2 , V_199 , V_203 -> V_206 , V_4 ) ;
V_90:
F_123 ( V_3 ) ;
return V_63 ? : V_218 ;
}
static void F_175 ( struct V_2 * V_3 , int V_54 )
{
F_176 () ;
}
struct V_2 *
F_177 ( struct V_32 * V_32 , int V_223 , struct V_19 * V_19 ,
struct V_224 * V_225 )
{
struct V_71 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_60 * V_60 = NULL ;
struct V_72 * V_73 = V_225 ? V_225 -> V_73 : NULL ;
unsigned int V_25 ;
F_81 ( ! V_34 ) ;
if ( V_223 < 0 || V_223 >= V_87 )
return NULL ;
if ( F_178 ( V_76 , V_85 , V_223 , & V_2 ) )
return NULL ;
if ( F_64 ( & V_226 , V_2 , V_73 , V_223 ) < 0 )
goto V_227;
V_3 = V_2 -> V_3 ;
F_179 ( V_3 , V_32 ) ;
if ( ! V_225 || V_225 -> V_25 < 32 )
V_25 = 32 ;
else
V_25 = V_225 -> V_25 ;
V_60 = F_43 ( sizeof( * V_60 ) + F_94 ( V_25 ) , V_77 ) ;
if ( ! V_60 )
goto V_228;
V_3 -> V_152 = F_175 ;
if ( V_225 && V_225 -> V_229 )
F_1 ( V_3 ) -> V_160 = V_225 -> V_229 ;
if ( F_59 ( V_3 , V_32 , 0 ) )
goto V_228;
V_17 = F_1 ( V_3 ) ;
V_17 -> V_4 |= V_5 ;
F_19 () ;
if ( ! V_34 [ V_223 ] . V_89 ) {
V_34 [ V_223 ] . V_25 = V_25 ;
F_180 ( V_34 [ V_223 ] . V_60 , V_60 ) ;
V_34 [ V_223 ] . V_73 = V_73 ;
V_34 [ V_223 ] . V_19 = V_19 ;
if ( V_225 ) {
V_34 [ V_223 ] . F_70 = V_225 -> F_70 ;
V_34 [ V_223 ] . V_4 = V_225 -> V_4 ;
}
V_34 [ V_223 ] . V_89 = 1 ;
} else {
F_9 ( V_60 ) ;
V_34 [ V_223 ] . V_89 ++ ;
}
F_29 () ;
return V_3 ;
V_228:
F_9 ( V_60 ) ;
F_181 ( V_3 ) ;
return NULL ;
V_227:
F_182 ( V_2 ) ;
return NULL ;
}
void
F_181 ( struct V_2 * V_3 )
{
F_183 ( V_3 ) ;
}
int F_184 ( struct V_2 * V_3 , unsigned int V_25 )
{
struct V_60 * V_184 , * V_98 ;
struct V_57 * V_58 = & V_34 [ V_3 -> V_59 ] ;
if ( V_25 < 32 )
V_25 = 32 ;
if ( F_94 ( V_58 -> V_25 ) < F_94 ( V_25 ) ) {
V_184 = F_43 ( sizeof( * V_184 ) + F_94 ( V_25 ) , V_41 ) ;
if ( ! V_184 )
return - V_67 ;
V_98 = F_56 ( V_58 -> V_60 ) ;
memcpy ( V_184 -> V_62 , V_98 -> V_62 , F_94 ( V_58 -> V_25 ) ) ;
F_180 ( V_58 -> V_60 , V_184 ) ;
F_83 ( V_98 , V_99 ) ;
}
V_58 -> V_25 = V_25 ;
return 0 ;
}
int F_185 ( struct V_2 * V_3 , unsigned int V_25 )
{
int V_63 ;
F_19 () ;
V_63 = F_184 ( V_3 , V_25 ) ;
F_29 () ;
return V_63 ;
}
void F_186 ( struct V_2 * V_230 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_36 * V_37 ;
struct V_57 * V_58 = & V_34 [ V_230 -> V_59 ] ;
F_58 (sk, node, &tbl->mc_list)
F_148 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_187 ( struct V_2 * V_230 , unsigned int V_6 )
{
F_19 () ;
F_186 ( V_230 , V_6 ) ;
F_29 () ;
}
struct V_231 *
F_188 ( struct V_147 * V_16 , T_1 V_10 , T_1 V_232 , int type , int V_54 , int V_4 )
{
struct V_231 * V_233 ;
int V_39 = F_189 ( V_54 ) ;
V_233 = (struct V_231 * ) F_162 ( V_16 , F_190 ( V_39 ) ) ;
V_233 -> V_234 = type ;
V_233 -> V_235 = V_39 ;
V_233 -> V_236 = V_4 ;
V_233 -> V_237 = V_10 ;
V_233 -> V_238 = V_232 ;
if ( ! F_191 ( V_39 ) || F_190 ( V_39 ) - V_39 != 0 )
memset ( F_192 ( V_233 ) + V_54 , 0 , F_190 ( V_39 ) - V_39 ) ;
return V_233 ;
}
static int F_173 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
struct V_147 * V_16 = NULL ;
struct V_231 * V_233 ;
int V_54 , V_63 = - V_133 ;
int V_239 ;
F_193 ( V_17 -> V_73 ) ;
V_15 = V_17 -> V_15 ;
if ( V_15 == NULL ) {
V_63 = - V_115 ;
goto V_240;
}
V_239 = F_194 ( int , V_15 -> V_241 , V_242 ) ;
V_16 = F_195 ( V_3 , V_239 , 0 , V_77 ) ;
if ( ! V_16 )
goto V_240;
V_54 = V_15 -> V_243 ( V_16 , V_15 ) ;
if ( V_54 > 0 ) {
F_196 ( V_17 -> V_73 ) ;
if ( F_134 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_114 ( V_3 , V_16 ) ;
return 0 ;
}
V_233 = F_197 ( V_16 , V_15 , V_244 , sizeof( V_54 ) , V_245 ) ;
if ( ! V_233 )
goto V_240;
F_198 ( V_15 , V_233 ) ;
memcpy ( F_199 ( V_233 ) , & V_54 , sizeof( V_54 ) ) ;
if ( F_134 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_114 ( V_3 , V_16 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 ) ;
V_17 -> V_15 = NULL ;
F_196 ( V_17 -> V_73 ) ;
F_13 ( V_15 -> V_19 ) ;
F_10 ( V_15 ) ;
return 0 ;
V_240:
F_196 ( V_17 -> V_73 ) ;
F_8 ( V_16 ) ;
return V_63 ;
}
int F_200 ( struct V_2 * V_136 , struct V_147 * V_16 ,
const struct V_231 * V_233 ,
struct V_246 * V_247 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
int V_159 ;
V_15 = F_43 ( sizeof( * V_15 ) , V_77 ) ;
if ( V_15 == NULL )
return - V_133 ;
V_15 -> V_243 = V_247 -> V_243 ;
V_15 -> V_18 = V_247 -> V_18 ;
V_15 -> V_233 = V_233 ;
V_15 -> V_176 = V_247 -> V_176 ;
V_15 -> V_19 = V_247 -> V_19 ;
V_15 -> V_241 = V_247 -> V_241 ;
F_33 ( & V_16 -> V_215 ) ;
V_15 -> V_16 = V_16 ;
V_3 = F_37 ( F_40 ( V_136 ) , V_136 -> V_59 , F_128 ( V_16 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_7 ( V_15 ) ;
return - V_137 ;
}
V_17 = F_1 ( V_3 ) ;
F_193 ( V_17 -> V_73 ) ;
if ( V_17 -> V_15 ) {
F_196 ( V_17 -> V_73 ) ;
F_7 ( V_15 ) ;
V_159 = - V_66 ;
goto V_90;
}
if ( ! F_73 ( V_15 -> V_19 ) ) {
F_196 ( V_17 -> V_73 ) ;
F_7 ( V_15 ) ;
V_159 = - V_88 ;
goto V_90;
}
V_17 -> V_15 = V_15 ;
F_196 ( V_17 -> V_73 ) ;
V_159 = F_173 ( V_3 ) ;
V_90:
F_84 ( V_3 ) ;
if ( V_159 )
return V_159 ;
return - V_248 ;
}
void F_201 ( struct V_147 * V_249 , struct V_231 * V_233 , int V_63 )
{
struct V_147 * V_16 ;
struct V_231 * V_250 ;
struct V_251 * V_252 ;
T_3 V_253 = sizeof( * V_252 ) ;
if ( V_63 )
V_253 += V_235 ( V_233 ) ;
V_16 = F_202 ( V_253 , V_77 ) ;
if ( ! V_16 ) {
struct V_2 * V_3 ;
V_3 = F_37 ( F_40 ( V_249 -> V_3 ) ,
V_249 -> V_3 -> V_59 ,
F_128 ( V_249 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_132 = V_133 ;
V_3 -> V_134 ( V_3 ) ;
F_84 ( V_3 ) ;
}
return;
}
V_250 = F_188 ( V_16 , F_128 ( V_249 ) . V_10 , V_233 -> V_238 ,
V_254 , V_253 , 0 ) ;
V_252 = F_199 ( V_250 ) ;
V_252 -> error = V_63 ;
memcpy ( & V_252 -> V_199 , V_233 , V_63 ? V_233 -> V_235 : sizeof( * V_233 ) ) ;
F_129 ( V_249 -> V_3 , V_16 , F_128 ( V_249 ) . V_10 , V_216 ) ;
}
int F_203 ( struct V_147 * V_16 , int (* V_15)( struct V_147 * ,
struct V_231 * ) )
{
struct V_231 * V_233 ;
int V_63 ;
while ( V_16 -> V_54 >= F_204 ( 0 ) ) {
int V_255 ;
V_233 = F_205 ( V_16 ) ;
V_63 = 0 ;
if ( V_233 -> V_235 < V_256 || V_16 -> V_54 < V_233 -> V_235 )
return 0 ;
if ( ! ( V_233 -> V_236 & V_257 ) )
goto V_258;
if ( V_233 -> V_234 < V_259 )
goto V_258;
V_63 = V_15 ( V_16 , V_233 ) ;
if ( V_63 == - V_248 )
goto V_260;
V_258:
if ( V_233 -> V_236 & V_261 || V_63 )
F_201 ( V_16 , V_233 , V_63 ) ;
V_260:
V_255 = F_190 ( V_233 -> V_235 ) ;
if ( V_255 > V_16 -> V_54 )
V_255 = V_16 -> V_54 ;
F_206 ( V_16 , V_255 ) ;
}
return 0 ;
}
int F_207 ( struct V_2 * V_3 , struct V_147 * V_16 , T_1 V_10 ,
unsigned int V_6 , int V_262 , T_5 V_4 )
{
int V_63 = 0 ;
if ( V_6 ) {
int V_263 = 0 ;
if ( V_262 ) {
F_33 ( & V_16 -> V_215 ) ;
V_263 = V_10 ;
}
V_63 = F_208 ( V_3 , V_16 , V_263 , V_6 , V_4 ) ;
}
if ( V_262 ) {
int V_264 ;
V_264 = F_209 ( V_3 , V_16 , V_10 ) ;
if ( ! V_63 || V_63 == - V_180 )
V_63 = V_264 ;
}
return V_63 ;
}
static struct V_2 * F_210 ( struct V_265 * V_232 , T_7 V_266 )
{
struct V_267 * V_268 = V_232 -> V_269 ;
int V_48 , V_270 ;
struct V_2 * V_271 ;
struct V_36 * V_37 ;
T_7 V_272 = 0 ;
for ( V_48 = 0 ; V_48 < V_87 ; V_48 ++ ) {
struct V_8 * V_9 = & V_34 [ V_48 ] . V_9 ;
for ( V_270 = 0 ; V_270 <= V_9 -> V_13 ; V_270 ++ ) {
F_38 (s, node, &hash->table[j]) {
if ( F_40 ( V_271 ) != F_211 ( V_232 ) )
continue;
if ( V_272 == V_266 ) {
V_268 -> V_273 = V_48 ;
V_268 -> V_274 = V_270 ;
return V_271 ;
}
++ V_272 ;
}
}
}
return NULL ;
}
static void * F_212 ( struct V_265 * V_232 , T_7 * V_266 )
__acquires( T_2 )
{
F_32 ( & T_2 ) ;
return * V_266 ? F_210 ( V_232 , * V_266 - 1 ) : V_275 ;
}
static void * F_213 ( struct V_265 * V_232 , void * V_276 , T_7 * V_266 )
{
struct V_2 * V_271 ;
struct V_267 * V_268 ;
int V_48 , V_270 ;
++ * V_266 ;
if ( V_276 == V_275 )
return F_210 ( V_232 , 0 ) ;
V_268 = V_232 -> V_269 ;
V_271 = V_276 ;
do {
V_271 = F_214 ( V_271 ) ;
} while ( V_271 && F_40 ( V_271 ) != F_211 ( V_232 ) );
if ( V_271 )
return V_271 ;
V_48 = V_268 -> V_273 ;
V_270 = V_268 -> V_274 + 1 ;
do {
struct V_8 * V_9 = & V_34 [ V_48 ] . V_9 ;
for (; V_270 <= V_9 -> V_13 ; V_270 ++ ) {
V_271 = F_215 ( & V_9 -> V_11 [ V_270 ] ) ;
while ( V_271 && F_40 ( V_271 ) != F_211 ( V_232 ) )
V_271 = F_214 ( V_271 ) ;
if ( V_271 ) {
V_268 -> V_273 = V_48 ;
V_268 -> V_274 = V_270 ;
return V_271 ;
}
}
V_270 = 0 ;
} while ( ++ V_48 < V_87 );
return NULL ;
}
static void F_216 ( struct V_265 * V_232 , void * V_276 )
__releases( T_2 )
{
F_34 ( & T_2 ) ;
}
static int F_217 ( struct V_265 * V_232 , void * V_276 )
{
if ( V_276 == V_275 ) {
F_218 ( V_232 ,
L_3
L_4 ) ;
} else {
struct V_2 * V_271 = V_276 ;
struct V_1 * V_17 = F_1 ( V_271 ) ;
F_219 ( V_232 , L_5 ,
V_271 ,
V_271 -> V_59 ,
V_17 -> V_10 ,
V_17 -> V_25 ? ( T_1 ) V_17 -> V_25 [ 0 ] : 0 ,
F_220 ( V_271 ) ,
F_221 ( V_271 ) ,
V_17 -> V_15 ,
F_18 ( & V_271 -> V_277 ) ,
F_18 ( & V_271 -> V_135 ) ,
F_222 ( V_271 )
) ;
}
return 0 ;
}
static int F_223 ( struct V_140 * V_140 , struct V_138 * V_138 )
{
return F_224 ( V_140 , V_138 , & V_278 ,
sizeof( struct V_267 ) ) ;
}
int F_225 ( struct V_279 * V_280 )
{
return F_226 ( & V_96 , V_280 ) ;
}
int F_227 ( struct V_279 * V_280 )
{
return F_228 ( & V_96 , V_280 ) ;
}
static int T_8 F_229 ( struct V_32 * V_32 )
{
#ifdef F_230
if ( ! F_231 ( V_32 , L_6 , 0 , & V_281 ) )
return - V_67 ;
#endif
return 0 ;
}
static void T_9 F_232 ( struct V_32 * V_32 )
{
#ifdef F_230
F_233 ( V_32 , L_6 ) ;
#endif
}
static void T_10 F_234 ( void )
{
struct V_60 * V_60 ;
int V_25 = 32 ;
V_60 = F_43 ( sizeof( * V_60 ) + F_94 ( V_25 ) , V_77 ) ;
if ( ! V_60 )
F_235 ( L_7 ) ;
F_19 () ;
V_34 [ V_282 ] . V_25 = V_25 ;
F_180 ( V_34 [ V_282 ] . V_60 , V_60 ) ;
V_34 [ V_282 ] . V_19 = V_283 ;
V_34 [ V_282 ] . V_89 = 1 ;
V_34 [ V_282 ] . V_4 = V_127 ;
F_29 () ;
}
static int T_10 F_236 ( void )
{
struct V_147 * V_284 ;
int V_48 ;
unsigned long V_285 ;
unsigned int V_286 ;
int V_63 = F_237 ( & V_78 , 0 ) ;
if ( V_63 != 0 )
goto V_90;
F_238 ( sizeof( struct V_287 ) > sizeof( V_284 -> V_15 ) ) ;
V_34 = F_239 ( V_87 , sizeof( * V_34 ) , V_77 ) ;
if ( ! V_34 )
goto F_235;
if ( V_288 >= ( 128 * 1024 ) )
V_285 = V_288 >> ( 21 - V_289 ) ;
else
V_285 = V_288 >> ( 23 - V_289 ) ;
V_286 = F_240 ( V_285 ) - 1 + V_289 ;
V_285 = ( 1UL << V_286 ) / sizeof( struct V_7 ) ;
V_286 = F_240 ( F_241 ( V_285 , ( unsigned long ) V_69 ) ) - 1 ;
for ( V_48 = 0 ; V_48 < V_87 ; V_48 ++ ) {
struct V_8 * V_9 = & V_34 [ V_48 ] . V_9 ;
V_9 -> V_11 = F_42 ( 1 * sizeof( * V_9 -> V_11 ) ) ;
if ( ! V_9 -> V_11 ) {
while ( V_48 -- > 0 )
F_46 ( V_34 [ V_48 ] . V_9 . V_11 ,
1 * sizeof( * V_9 -> V_11 ) ) ;
F_9 ( V_34 ) ;
goto F_235;
}
V_9 -> V_49 = V_286 ;
V_9 -> V_45 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_51 = V_52 ;
}
F_234 () ;
F_242 ( & V_290 ) ;
F_243 ( & V_291 ) ;
F_244 () ;
V_90:
return V_63 ;
F_235:
F_235 ( L_8 ) ;
}
