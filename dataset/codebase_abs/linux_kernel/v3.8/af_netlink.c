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
F_89 ( F_40 ( V_2 -> V_3 ) -> V_103 , V_104 ) ;
}
static void
F_90 ( struct V_2 * V_3 , unsigned int V_70 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_70 && ! V_70 )
F_63 ( V_3 ) ;
else if ( ! V_17 -> V_70 && V_70 )
F_91 ( V_3 , & V_34 [ V_3 -> V_59 ] . V_105 ) ;
V_17 -> V_70 = V_70 ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_25 ;
unsigned long * V_106 ;
int V_63 = 0 ;
F_19 () ;
V_25 = V_34 [ V_3 -> V_59 ] . V_25 ;
if ( ! V_34 [ V_3 -> V_59 ] . V_89 ) {
V_63 = - V_107 ;
goto V_108;
}
if ( V_17 -> V_61 >= V_25 )
goto V_108;
V_106 = F_93 ( V_17 -> V_25 , F_94 ( V_25 ) , V_41 ) ;
if ( V_106 == NULL ) {
V_63 = - V_67 ;
goto V_108;
}
memset ( ( char * ) V_106 + F_94 ( V_17 -> V_61 ) , 0 ,
F_94 ( V_25 ) - F_94 ( V_17 -> V_61 ) ) ;
V_17 -> V_25 = V_106 ;
V_17 -> V_61 = V_25 ;
V_108:
F_29 () ;
return V_63 ;
}
static int V_92 ( struct V_71 * V_2 , struct V_109 * V_110 ,
int V_111 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_32 * V_32 = F_40 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_112 * V_113 = (struct V_112 * ) V_110 ;
int V_63 ;
if ( V_111 < sizeof( struct V_112 ) )
return - V_114 ;
if ( V_113 -> V_115 != V_116 )
return - V_114 ;
if ( V_113 -> V_117 ) {
if ( ! F_88 ( V_2 , V_118 ) )
return - V_119 ;
V_63 = F_92 ( V_3 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_17 -> V_10 ) {
if ( V_113 -> V_120 != V_17 -> V_10 )
return - V_114 ;
} else {
V_63 = V_113 -> V_120 ?
F_59 ( V_3 , V_32 , V_113 -> V_120 ) :
F_85 ( V_2 ) ;
if ( V_63 )
return V_63 ;
}
if ( ! V_113 -> V_117 && ( V_17 -> V_25 == NULL || ! ( T_1 ) V_17 -> V_25 [ 0 ] ) )
return 0 ;
F_19 () ;
F_90 ( V_3 , V_17 -> V_70 +
F_95 ( V_113 -> V_117 ) -
F_95 ( V_17 -> V_25 [ 0 ] ) ) ;
V_17 -> V_25 [ 0 ] = ( V_17 -> V_25 [ 0 ] & ~ 0xffffffffUL ) | V_113 -> V_117 ;
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
static int F_97 ( struct V_71 * V_2 , struct V_109 * V_110 ,
int V_121 , int V_4 )
{
int V_63 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_112 * V_113 = (struct V_112 * ) V_110 ;
if ( V_121 < sizeof( V_110 -> V_122 ) )
return - V_114 ;
if ( V_110 -> V_122 == V_123 ) {
V_3 -> V_124 = V_125 ;
V_17 -> V_126 = 0 ;
V_17 -> V_127 = 0 ;
return 0 ;
}
if ( V_110 -> V_122 != V_116 )
return - V_114 ;
if ( V_113 -> V_117 && ! F_88 ( V_2 , V_128 ) )
return - V_119 ;
if ( ! V_17 -> V_10 )
V_63 = F_85 ( V_2 ) ;
if ( V_63 == 0 ) {
V_3 -> V_124 = V_129 ;
V_17 -> V_126 = V_113 -> V_120 ;
V_17 -> V_127 = F_98 ( V_113 -> V_117 ) ;
}
return V_63 ;
}
static int F_99 ( struct V_71 * V_2 , struct V_109 * V_110 ,
int * V_111 , int V_130 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_100 ( struct V_112 * , V_113 , V_110 ) ;
V_113 -> V_115 = V_116 ;
V_113 -> V_131 = 0 ;
* V_111 = sizeof( * V_113 ) ;
if ( V_130 ) {
V_113 -> V_120 = V_17 -> V_126 ;
V_113 -> V_117 = F_4 ( V_17 -> V_127 ) ;
} else {
V_113 -> V_120 = V_17 -> V_10 ;
V_113 -> V_117 = V_17 -> V_25 ? V_17 -> V_25 [ 0 ] : 0 ;
}
return 0 ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! ( V_17 -> V_4 & V_132 ) ) {
if ( ! F_102 ( 0 , & F_1 ( V_3 ) -> V_82 ) ) {
V_3 -> V_133 = V_134 ;
V_3 -> V_135 ( V_3 ) ;
}
}
F_33 ( & V_3 -> V_136 ) ;
}
static struct V_2 * F_103 ( struct V_2 * V_137 , T_1 V_10 )
{
struct V_2 * V_2 ;
struct V_1 * V_17 ;
V_2 = F_37 ( F_40 ( V_137 ) , V_137 -> V_59 , V_10 ) ;
if ( ! V_2 )
return F_104 ( - V_138 ) ;
V_17 = F_1 ( V_2 ) ;
if ( V_2 -> V_124 == V_129 &&
V_17 -> V_126 != F_1 ( V_137 ) -> V_10 ) {
F_84 ( V_2 ) ;
return F_104 ( - V_138 ) ;
}
return V_2 ;
}
struct V_2 * F_105 ( struct V_139 * V_140 )
{
struct V_141 * V_141 = V_140 -> V_142 . V_143 -> V_144 ;
struct V_2 * V_2 ;
if ( ! F_106 ( V_141 -> V_145 ) )
return F_104 ( - V_146 ) ;
V_2 = F_107 ( V_141 ) -> V_3 ;
if ( V_2 -> V_147 != V_116 )
return F_104 ( - V_114 ) ;
F_41 ( V_2 ) ;
return V_2 ;
}
int F_108 ( struct V_2 * V_3 , struct V_148 * V_16 ,
long * V_149 , struct V_2 * V_137 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_150 ||
F_96 ( 0 , & V_17 -> V_82 ) ) {
F_22 ( V_27 , V_28 ) ;
if ( ! * V_149 ) {
if ( ! V_137 || F_3 ( V_137 ) )
F_101 ( V_3 ) ;
F_84 ( V_3 ) ;
F_8 ( V_16 ) ;
return - V_151 ;
}
F_27 ( V_152 ) ;
F_109 ( & V_17 -> V_27 , & V_27 ) ;
if ( ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_150 ||
F_96 ( 0 , & V_17 -> V_82 ) ) &&
! F_15 ( V_3 , V_21 ) )
* V_149 = F_110 ( * V_149 ) ;
F_27 ( V_31 ) ;
F_28 ( & V_17 -> V_27 , & V_27 ) ;
F_84 ( V_3 ) ;
if ( F_111 ( V_28 ) ) {
F_8 ( V_16 ) ;
return F_112 ( * V_149 ) ;
}
return 1 ;
}
F_113 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , struct V_148 * V_16 )
{
int V_54 = V_16 -> V_54 ;
F_115 ( & V_3 -> V_20 , V_16 ) ;
V_3 -> V_153 ( V_3 , V_54 ) ;
return V_54 ;
}
int F_116 ( struct V_2 * V_3 , struct V_148 * V_16 )
{
int V_54 = F_114 ( V_3 , V_16 ) ;
F_84 ( V_3 ) ;
return V_54 ;
}
void F_117 ( struct V_2 * V_3 , struct V_148 * V_16 )
{
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
}
static struct V_148 * F_118 ( struct V_148 * V_16 , T_5 V_154 )
{
int V_155 ;
F_119 ( V_16 ) ;
V_155 = V_16 -> V_156 - V_16 -> V_157 ;
if ( V_155 * 2 < V_16 -> V_158 )
return V_16 ;
if ( F_120 ( V_16 ) ) {
struct V_148 * V_159 = F_121 ( V_16 , V_154 ) ;
if ( ! V_159 )
return V_16 ;
F_11 ( V_16 ) ;
V_16 = V_159 ;
}
if ( ! F_122 ( V_16 , 0 , - V_155 , V_154 ) )
V_16 -> V_158 -= V_155 ;
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
static int F_127 ( struct V_2 * V_3 , struct V_148 * V_16 ,
struct V_2 * V_137 )
{
int V_160 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_160 = - V_138 ;
if ( V_17 -> V_161 != NULL ) {
V_160 = V_16 -> V_54 ;
F_113 ( V_16 , V_3 ) ;
F_128 ( V_16 ) . V_137 = V_137 ;
V_17 -> V_161 ( V_16 ) ;
F_11 ( V_16 ) ;
} else {
F_8 ( V_16 ) ;
}
F_84 ( V_3 ) ;
return V_160 ;
}
int F_129 ( struct V_2 * V_137 , struct V_148 * V_16 ,
T_1 V_10 , int V_162 )
{
struct V_2 * V_3 ;
int V_63 ;
long V_149 ;
V_16 = F_118 ( V_16 , F_130 () ) ;
V_149 = F_131 ( V_137 , V_162 ) ;
V_101:
V_3 = F_103 ( V_137 , V_10 ) ;
if ( F_132 ( V_3 ) ) {
F_8 ( V_16 ) ;
return F_133 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_127 ( V_3 , V_16 , V_137 ) ;
if ( F_134 ( V_3 , V_16 ) ) {
V_63 = V_16 -> V_54 ;
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
return V_63 ;
}
V_63 = F_108 ( V_3 , V_16 , & V_149 , V_137 ) ;
if ( V_63 == 1 )
goto V_101;
if ( V_63 )
return V_63 ;
return F_116 ( V_3 , V_16 ) ;
}
int F_135 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_163 = 0 ;
struct V_60 * V_60 ;
F_81 ( ! F_3 ( V_3 ) ) ;
F_136 () ;
V_60 = F_137 ( V_34 [ V_3 -> V_59 ] . V_60 ) ;
if ( V_60 && V_6 - 1 < V_34 [ V_3 -> V_59 ] . V_25 )
V_163 = F_96 ( V_6 - 1 , V_60 -> V_62 ) ;
F_138 () ;
return V_163 ;
}
static int F_139 ( struct V_2 * V_3 , struct V_148 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) <= V_3 -> V_150 &&
! F_96 ( 0 , & V_17 -> V_82 ) ) {
F_113 ( V_16 , V_3 ) ;
F_114 ( V_3 , V_16 ) ;
return F_18 ( & V_3 -> V_23 ) > ( V_3 -> V_150 >> 1 ) ;
}
return - 1 ;
}
static int F_140 ( struct V_2 * V_3 ,
struct V_164 * V_165 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_166 ;
if ( V_165 -> V_167 == V_3 )
goto V_90;
if ( V_17 -> V_10 == V_165 -> V_10 || V_165 -> V_6 - 1 >= V_17 -> V_61 ||
! F_96 ( V_165 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_90;
if ( ! F_39 ( F_40 ( V_3 ) , V_165 -> V_32 ) )
goto V_90;
if ( V_165 -> V_168 ) {
F_101 ( V_3 ) ;
goto V_90;
}
F_41 ( V_3 ) ;
if ( V_165 -> V_169 == NULL ) {
if ( F_120 ( V_165 -> V_16 ) ) {
V_165 -> V_169 = F_121 ( V_165 -> V_16 , V_165 -> V_154 ) ;
} else {
V_165 -> V_169 = F_141 ( V_165 -> V_16 ) ;
F_119 ( V_165 -> V_169 ) ;
}
}
if ( V_165 -> V_169 == NULL ) {
F_101 ( V_3 ) ;
V_165 -> V_168 = 1 ;
if ( V_17 -> V_4 & V_170 )
V_165 -> V_171 = 1 ;
} else if ( V_165 -> V_172 && V_165 -> V_172 ( V_3 , V_165 -> V_169 , V_165 -> V_173 ) ) {
F_8 ( V_165 -> V_169 ) ;
V_165 -> V_169 = NULL ;
} else if ( F_134 ( V_3 , V_165 -> V_169 ) ) {
F_8 ( V_165 -> V_169 ) ;
V_165 -> V_169 = NULL ;
} else if ( ( V_166 = F_139 ( V_3 , V_165 -> V_169 ) ) < 0 ) {
F_101 ( V_3 ) ;
if ( V_17 -> V_4 & V_170 )
V_165 -> V_171 = 1 ;
} else {
V_165 -> V_174 |= V_166 ;
V_165 -> V_175 = 1 ;
V_165 -> V_169 = NULL ;
}
F_84 ( V_3 ) ;
V_90:
return 0 ;
}
int F_142 ( struct V_2 * V_137 , struct V_148 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_154 ,
int (* F_143)( struct V_2 * V_176 , struct V_148 * V_16 , void * V_177 ) ,
void * V_178 )
{
struct V_32 * V_32 = F_40 ( V_137 ) ;
struct V_164 V_179 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
V_16 = F_118 ( V_16 , V_154 ) ;
V_179 . V_167 = V_137 ;
V_179 . V_32 = V_32 ;
V_179 . V_10 = V_10 ;
V_179 . V_6 = V_6 ;
V_179 . V_168 = 0 ;
V_179 . V_171 = 0 ;
V_179 . V_174 = 0 ;
V_179 . V_175 = 0 ;
V_179 . V_154 = V_154 ;
V_179 . V_16 = V_16 ;
V_179 . V_169 = NULL ;
V_179 . V_172 = F_143 ;
V_179 . V_173 = V_178 ;
F_31 () ;
F_58 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
F_140 ( V_3 , & V_179 ) ;
F_11 ( V_16 ) ;
F_35 () ;
if ( V_179 . V_171 ) {
F_8 ( V_179 . V_169 ) ;
return - V_134 ;
}
F_11 ( V_179 . V_169 ) ;
if ( V_179 . V_175 ) {
if ( V_179 . V_174 && ( V_154 & V_180 ) )
F_144 () ;
return 0 ;
}
return - V_181 ;
}
int F_145 ( struct V_2 * V_137 , struct V_148 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_154 )
{
return F_142 ( V_137 , V_16 , V_10 , V_6 , V_154 ,
NULL , NULL ) ;
}
static int F_146 ( struct V_2 * V_3 , struct V_182 * V_165 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_160 = 0 ;
if ( V_3 == V_165 -> V_167 )
goto V_90;
if ( ! F_39 ( F_40 ( V_3 ) , F_40 ( V_165 -> V_167 ) ) )
goto V_90;
if ( V_17 -> V_10 == V_165 -> V_10 || V_165 -> V_6 - 1 >= V_17 -> V_61 ||
! F_96 ( V_165 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_90;
if ( V_165 -> V_183 == V_134 && V_17 -> V_4 & V_132 ) {
V_160 = 1 ;
goto V_90;
}
V_3 -> V_133 = V_165 -> V_183 ;
V_3 -> V_135 ( V_3 ) ;
V_90:
return V_160 ;
}
int F_147 ( struct V_2 * V_137 , T_1 V_10 , T_1 V_6 , int V_183 )
{
struct V_182 V_179 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
int V_160 = 0 ;
V_179 . V_167 = V_137 ;
V_179 . V_10 = V_10 ;
V_179 . V_6 = V_6 ;
V_179 . V_183 = - V_183 ;
F_32 ( & T_2 ) ;
F_58 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
V_160 += F_146 ( V_3 , & V_179 ) ;
F_34 ( & T_2 ) ;
return V_160 ;
}
static void F_148 ( struct V_1 * V_17 ,
unsigned int V_6 ,
int V_184 )
{
int V_98 , V_185 = ! ! V_184 , V_70 ;
V_98 = F_96 ( V_6 - 1 , V_17 -> V_25 ) ;
V_70 = V_17 -> V_70 - V_98 + V_185 ;
if ( V_185 )
F_149 ( V_6 - 1 , V_17 -> V_25 ) ;
else
F_150 ( V_6 - 1 , V_17 -> V_25 ) ;
F_90 ( & V_17 -> V_3 , V_70 ) ;
F_55 ( & V_17 -> V_3 ) ;
}
static int F_151 ( struct V_71 * V_2 , int V_186 , int V_187 ,
char T_6 * V_188 , unsigned int V_189 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_166 = 0 ;
int V_63 ;
if ( V_186 != V_190 )
return - V_191 ;
if ( V_189 >= sizeof( int ) &&
F_152 ( V_166 , ( unsigned int T_6 * ) V_188 ) )
return - V_192 ;
switch ( V_187 ) {
case V_193 :
if ( V_166 )
V_17 -> V_4 |= V_194 ;
else
V_17 -> V_4 &= ~ V_194 ;
V_63 = 0 ;
break;
case V_195 :
case V_196 : {
if ( ! F_88 ( V_2 , V_118 ) )
return - V_119 ;
V_63 = F_92 ( V_3 ) ;
if ( V_63 )
return V_63 ;
if ( ! V_166 || V_166 - 1 >= V_17 -> V_61 )
return - V_114 ;
F_19 () ;
F_148 ( V_17 , V_166 ,
V_187 == V_195 ) ;
F_29 () ;
if ( V_17 -> V_92 )
V_17 -> V_92 ( V_166 ) ;
V_63 = 0 ;
break;
}
case V_197 :
if ( V_166 )
V_17 -> V_4 |= V_170 ;
else
V_17 -> V_4 &= ~ V_170 ;
V_63 = 0 ;
break;
case V_198 :
if ( V_166 ) {
V_17 -> V_4 |= V_132 ;
F_125 ( 0 , & V_17 -> V_82 ) ;
F_126 ( & V_17 -> V_27 ) ;
} else {
V_17 -> V_4 &= ~ V_132 ;
}
V_63 = 0 ;
break;
default:
V_63 = - V_191 ;
}
return V_63 ;
}
static int F_153 ( struct V_71 * V_2 , int V_186 , int V_187 ,
char T_6 * V_188 , int T_6 * V_189 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_54 , V_166 , V_63 ;
if ( V_186 != V_190 )
return - V_191 ;
if ( F_152 ( V_54 , V_189 ) )
return - V_192 ;
if ( V_54 < 0 )
return - V_114 ;
switch ( V_187 ) {
case V_193 :
if ( V_54 < sizeof( int ) )
return - V_114 ;
V_54 = sizeof( int ) ;
V_166 = V_17 -> V_4 & V_194 ? 1 : 0 ;
if ( F_154 ( V_54 , V_189 ) ||
F_154 ( V_166 , V_188 ) )
return - V_192 ;
V_63 = 0 ;
break;
case V_197 :
if ( V_54 < sizeof( int ) )
return - V_114 ;
V_54 = sizeof( int ) ;
V_166 = V_17 -> V_4 & V_170 ? 1 : 0 ;
if ( F_154 ( V_54 , V_189 ) ||
F_154 ( V_166 , V_188 ) )
return - V_192 ;
V_63 = 0 ;
break;
case V_198 :
if ( V_54 < sizeof( int ) )
return - V_114 ;
V_54 = sizeof( int ) ;
V_166 = V_17 -> V_4 & V_132 ? 1 : 0 ;
if ( F_154 ( V_54 , V_189 ) ||
F_154 ( V_166 , V_188 ) )
return - V_192 ;
V_63 = 0 ;
break;
default:
V_63 = - V_191 ;
}
return V_63 ;
}
static void F_155 ( struct V_199 * V_200 , struct V_148 * V_16 )
{
struct V_201 V_179 ;
V_179 . V_6 = F_128 ( V_16 ) . V_127 ;
F_156 ( V_200 , V_190 , V_193 , sizeof( V_179 ) , & V_179 ) ;
}
static int F_157 ( struct V_202 * V_202 , struct V_71 * V_2 ,
struct V_199 * V_200 , T_3 V_54 )
{
struct V_203 * V_204 = F_158 ( V_202 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_112 * V_110 = V_200 -> V_205 ;
T_1 V_126 ;
T_1 V_127 ;
struct V_148 * V_16 ;
int V_63 ;
struct V_206 V_207 ;
if ( V_200 -> V_208 & V_209 )
return - V_210 ;
if ( NULL == V_204 -> V_207 )
V_204 -> V_207 = & V_207 ;
V_63 = F_159 ( V_2 , V_200 , V_204 -> V_207 , true ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_200 -> V_211 ) {
V_63 = - V_114 ;
if ( V_110 -> V_115 != V_116 )
goto V_90;
V_126 = V_110 -> V_120 ;
V_127 = F_98 ( V_110 -> V_117 ) ;
V_63 = - V_119 ;
if ( ( V_127 || V_126 ) &&
! F_88 ( V_2 , V_128 ) )
goto V_90;
} else {
V_126 = V_17 -> V_126 ;
V_127 = V_17 -> V_127 ;
}
if ( ! V_17 -> V_10 ) {
V_63 = F_85 ( V_2 ) ;
if ( V_63 )
goto V_90;
}
V_63 = - V_212 ;
if ( V_54 > V_3 -> V_213 - 32 )
goto V_90;
V_63 = - V_134 ;
V_16 = F_160 ( V_54 , V_77 ) ;
if ( V_16 == NULL )
goto V_90;
F_128 ( V_16 ) . V_10 = V_17 -> V_10 ;
F_128 ( V_16 ) . V_127 = V_127 ;
F_128 ( V_16 ) . V_214 = V_204 -> V_207 -> V_214 ;
V_63 = - V_192 ;
if ( F_161 ( F_162 ( V_16 , V_54 ) , V_200 -> V_215 , V_54 ) ) {
F_8 ( V_16 ) ;
goto V_90;
}
V_63 = F_163 ( V_3 , V_16 ) ;
if ( V_63 ) {
F_8 ( V_16 ) ;
goto V_90;
}
if ( V_127 ) {
F_33 ( & V_16 -> V_216 ) ;
F_145 ( V_3 , V_16 , V_126 , V_127 , V_77 ) ;
}
V_63 = F_129 ( V_3 , V_16 , V_126 , V_200 -> V_208 & V_217 ) ;
V_90:
F_164 ( V_204 -> V_207 ) ;
return V_63 ;
}
static int F_165 ( struct V_202 * V_202 , struct V_71 * V_2 ,
struct V_199 * V_200 , T_3 V_54 ,
int V_4 )
{
struct V_203 * V_204 = F_158 ( V_202 ) ;
struct V_206 V_207 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_218 = V_4 & V_217 ;
T_3 V_219 ;
struct V_148 * V_16 , * V_220 ;
int V_63 , V_160 ;
if ( V_4 & V_209 )
return - V_210 ;
V_219 = 0 ;
V_16 = F_166 ( V_3 , V_4 , V_218 , & V_63 ) ;
if ( V_16 == NULL )
goto V_90;
V_220 = V_16 ;
#ifdef F_167
if ( F_53 ( F_168 ( V_16 ) -> V_221 ) ) {
if ( V_4 & V_222 )
V_220 = F_168 ( V_16 ) -> V_221 ;
}
#endif
V_200 -> V_211 = 0 ;
V_219 = V_220 -> V_54 ;
if ( V_54 < V_219 ) {
V_200 -> V_208 |= V_223 ;
V_219 = V_54 ;
}
F_169 ( V_220 ) ;
V_63 = F_170 ( V_220 , 0 , V_200 -> V_215 , V_219 ) ;
if ( V_200 -> V_205 ) {
struct V_112 * V_110 = (struct V_112 * ) V_200 -> V_205 ;
V_110 -> V_115 = V_116 ;
V_110 -> V_131 = 0 ;
V_110 -> V_120 = F_128 ( V_16 ) . V_10 ;
V_110 -> V_117 = F_4 ( F_128 ( V_16 ) . V_127 ) ;
V_200 -> V_211 = sizeof( * V_110 ) ;
}
if ( V_17 -> V_4 & V_194 )
F_155 ( V_200 , V_16 ) ;
if ( NULL == V_204 -> V_207 ) {
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
V_204 -> V_207 = & V_207 ;
}
V_204 -> V_207 -> V_214 = * F_171 ( V_16 ) ;
if ( V_4 & V_223 )
V_219 = V_220 -> V_54 ;
F_172 ( V_3 , V_16 ) ;
if ( V_17 -> V_15 && F_18 ( & V_3 -> V_23 ) <= V_3 -> V_150 / 2 ) {
V_160 = F_173 ( V_3 ) ;
if ( V_160 ) {
V_3 -> V_133 = V_160 ;
V_3 -> V_135 ( V_3 ) ;
}
}
F_174 ( V_2 , V_200 , V_204 -> V_207 , V_4 ) ;
V_90:
F_123 ( V_3 ) ;
return V_63 ? : V_219 ;
}
static void F_175 ( struct V_2 * V_3 , int V_54 )
{
F_176 () ;
}
struct V_2 *
F_177 ( struct V_32 * V_32 , int V_224 , struct V_19 * V_19 ,
struct V_225 * V_226 )
{
struct V_71 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_60 * V_60 = NULL ;
struct V_72 * V_73 = V_226 ? V_226 -> V_73 : NULL ;
unsigned int V_25 ;
F_81 ( ! V_34 ) ;
if ( V_224 < 0 || V_224 >= V_87 )
return NULL ;
if ( F_178 ( V_76 , V_85 , V_224 , & V_2 ) )
return NULL ;
if ( F_64 ( & V_227 , V_2 , V_73 , V_224 ) < 0 )
goto V_228;
V_3 = V_2 -> V_3 ;
F_179 ( V_3 , V_32 ) ;
if ( ! V_226 || V_226 -> V_25 < 32 )
V_25 = 32 ;
else
V_25 = V_226 -> V_25 ;
V_60 = F_43 ( sizeof( * V_60 ) + F_94 ( V_25 ) , V_77 ) ;
if ( ! V_60 )
goto V_229;
V_3 -> V_153 = F_175 ;
if ( V_226 && V_226 -> V_230 )
F_1 ( V_3 ) -> V_161 = V_226 -> V_230 ;
if ( F_59 ( V_3 , V_32 , 0 ) )
goto V_229;
V_17 = F_1 ( V_3 ) ;
V_17 -> V_4 |= V_5 ;
F_19 () ;
if ( ! V_34 [ V_224 ] . V_89 ) {
V_34 [ V_224 ] . V_25 = V_25 ;
F_180 ( V_34 [ V_224 ] . V_60 , V_60 ) ;
V_34 [ V_224 ] . V_73 = V_73 ;
V_34 [ V_224 ] . V_19 = V_19 ;
if ( V_226 ) {
V_34 [ V_224 ] . F_70 = V_226 -> F_70 ;
V_34 [ V_224 ] . V_4 = V_226 -> V_4 ;
}
V_34 [ V_224 ] . V_89 = 1 ;
} else {
F_9 ( V_60 ) ;
V_34 [ V_224 ] . V_89 ++ ;
}
F_29 () ;
return V_3 ;
V_229:
F_9 ( V_60 ) ;
F_181 ( V_3 ) ;
return NULL ;
V_228:
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
struct V_60 * V_185 , * V_98 ;
struct V_57 * V_58 = & V_34 [ V_3 -> V_59 ] ;
if ( V_25 < 32 )
V_25 = 32 ;
if ( F_94 ( V_58 -> V_25 ) < F_94 ( V_25 ) ) {
V_185 = F_43 ( sizeof( * V_185 ) + F_94 ( V_25 ) , V_41 ) ;
if ( ! V_185 )
return - V_67 ;
V_98 = F_56 ( V_58 -> V_60 ) ;
memcpy ( V_185 -> V_62 , V_98 -> V_62 , F_94 ( V_58 -> V_25 ) ) ;
F_180 ( V_58 -> V_60 , V_185 ) ;
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
void F_186 ( struct V_2 * V_231 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_36 * V_37 ;
struct V_57 * V_58 = & V_34 [ V_231 -> V_59 ] ;
F_58 (sk, node, &tbl->mc_list)
F_148 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_187 ( struct V_2 * V_231 , unsigned int V_6 )
{
F_19 () ;
F_186 ( V_231 , V_6 ) ;
F_29 () ;
}
struct V_232 *
F_188 ( struct V_148 * V_16 , T_1 V_10 , T_1 V_233 , int type , int V_54 , int V_4 )
{
struct V_232 * V_234 ;
int V_39 = F_189 ( V_54 ) ;
V_234 = (struct V_232 * ) F_162 ( V_16 , F_190 ( V_39 ) ) ;
V_234 -> V_235 = type ;
V_234 -> V_236 = V_39 ;
V_234 -> V_237 = V_4 ;
V_234 -> V_238 = V_10 ;
V_234 -> V_239 = V_233 ;
if ( ! F_191 ( V_39 ) || F_190 ( V_39 ) - V_39 != 0 )
memset ( F_192 ( V_234 ) + V_54 , 0 , F_190 ( V_39 ) - V_39 ) ;
return V_234 ;
}
static int F_173 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
struct V_148 * V_16 = NULL ;
struct V_232 * V_234 ;
int V_54 , V_63 = - V_134 ;
int V_240 ;
F_193 ( V_17 -> V_73 ) ;
V_15 = V_17 -> V_15 ;
if ( V_15 == NULL ) {
V_63 = - V_114 ;
goto V_241;
}
V_240 = F_194 ( int , V_15 -> V_242 , V_243 ) ;
V_16 = F_195 ( V_3 , V_240 , 0 , V_77 ) ;
if ( ! V_16 )
goto V_241;
V_54 = V_15 -> V_244 ( V_16 , V_15 ) ;
if ( V_54 > 0 ) {
F_196 ( V_17 -> V_73 ) ;
if ( F_134 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_114 ( V_3 , V_16 ) ;
return 0 ;
}
V_234 = F_197 ( V_16 , V_15 , V_245 , sizeof( V_54 ) , V_246 ) ;
if ( ! V_234 )
goto V_241;
F_198 ( V_15 , V_234 ) ;
memcpy ( F_199 ( V_234 ) , & V_54 , sizeof( V_54 ) ) ;
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
V_241:
F_196 ( V_17 -> V_73 ) ;
F_8 ( V_16 ) ;
return V_63 ;
}
int F_200 ( struct V_2 * V_137 , struct V_148 * V_16 ,
const struct V_232 * V_234 ,
struct V_247 * V_248 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
int V_160 ;
V_15 = F_43 ( sizeof( * V_15 ) , V_77 ) ;
if ( V_15 == NULL )
return - V_134 ;
V_15 -> V_244 = V_248 -> V_244 ;
V_15 -> V_18 = V_248 -> V_18 ;
V_15 -> V_234 = V_234 ;
V_15 -> V_177 = V_248 -> V_177 ;
V_15 -> V_19 = V_248 -> V_19 ;
V_15 -> V_242 = V_248 -> V_242 ;
F_33 ( & V_16 -> V_216 ) ;
V_15 -> V_16 = V_16 ;
V_3 = F_37 ( F_40 ( V_137 ) , V_137 -> V_59 , F_128 ( V_16 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_7 ( V_15 ) ;
return - V_138 ;
}
V_17 = F_1 ( V_3 ) ;
F_193 ( V_17 -> V_73 ) ;
if ( V_17 -> V_15 ) {
F_196 ( V_17 -> V_73 ) ;
F_7 ( V_15 ) ;
V_160 = - V_66 ;
goto V_90;
}
if ( ! F_73 ( V_15 -> V_19 ) ) {
F_196 ( V_17 -> V_73 ) ;
F_7 ( V_15 ) ;
V_160 = - V_88 ;
goto V_90;
}
V_17 -> V_15 = V_15 ;
F_196 ( V_17 -> V_73 ) ;
V_160 = F_173 ( V_3 ) ;
V_90:
F_84 ( V_3 ) ;
if ( V_160 )
return V_160 ;
return - V_249 ;
}
void F_201 ( struct V_148 * V_250 , struct V_232 * V_234 , int V_63 )
{
struct V_148 * V_16 ;
struct V_232 * V_251 ;
struct V_252 * V_253 ;
T_3 V_254 = sizeof( * V_253 ) ;
if ( V_63 )
V_254 += V_236 ( V_234 ) ;
V_16 = F_202 ( V_254 , V_77 ) ;
if ( ! V_16 ) {
struct V_2 * V_3 ;
V_3 = F_37 ( F_40 ( V_250 -> V_3 ) ,
V_250 -> V_3 -> V_59 ,
F_128 ( V_250 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_133 = V_134 ;
V_3 -> V_135 ( V_3 ) ;
F_84 ( V_3 ) ;
}
return;
}
V_251 = F_188 ( V_16 , F_128 ( V_250 ) . V_10 , V_234 -> V_239 ,
V_255 , V_254 , 0 ) ;
V_253 = F_199 ( V_251 ) ;
V_253 -> error = V_63 ;
memcpy ( & V_253 -> V_200 , V_234 , V_63 ? V_234 -> V_236 : sizeof( * V_234 ) ) ;
F_129 ( V_250 -> V_3 , V_16 , F_128 ( V_250 ) . V_10 , V_217 ) ;
}
int F_203 ( struct V_148 * V_16 , int (* V_15)( struct V_148 * ,
struct V_232 * ) )
{
struct V_232 * V_234 ;
int V_63 ;
while ( V_16 -> V_54 >= F_204 ( 0 ) ) {
int V_256 ;
V_234 = F_205 ( V_16 ) ;
V_63 = 0 ;
if ( V_234 -> V_236 < V_257 || V_16 -> V_54 < V_234 -> V_236 )
return 0 ;
if ( ! ( V_234 -> V_237 & V_258 ) )
goto V_259;
if ( V_234 -> V_235 < V_260 )
goto V_259;
V_63 = V_15 ( V_16 , V_234 ) ;
if ( V_63 == - V_249 )
goto V_261;
V_259:
if ( V_234 -> V_237 & V_262 || V_63 )
F_201 ( V_16 , V_234 , V_63 ) ;
V_261:
V_256 = F_190 ( V_234 -> V_236 ) ;
if ( V_256 > V_16 -> V_54 )
V_256 = V_16 -> V_54 ;
F_206 ( V_16 , V_256 ) ;
}
return 0 ;
}
int F_207 ( struct V_2 * V_3 , struct V_148 * V_16 , T_1 V_10 ,
unsigned int V_6 , int V_263 , T_5 V_4 )
{
int V_63 = 0 ;
if ( V_6 ) {
int V_264 = 0 ;
if ( V_263 ) {
F_33 ( & V_16 -> V_216 ) ;
V_264 = V_10 ;
}
V_63 = F_208 ( V_3 , V_16 , V_264 , V_6 , V_4 ) ;
}
if ( V_263 ) {
int V_265 ;
V_265 = F_209 ( V_3 , V_16 , V_10 ) ;
if ( ! V_63 || V_63 == - V_181 )
V_63 = V_265 ;
}
return V_63 ;
}
static struct V_2 * F_210 ( struct V_266 * V_233 , T_7 V_267 )
{
struct V_268 * V_269 = V_233 -> V_270 ;
int V_48 , V_271 ;
struct V_2 * V_272 ;
struct V_36 * V_37 ;
T_7 V_273 = 0 ;
for ( V_48 = 0 ; V_48 < V_87 ; V_48 ++ ) {
struct V_8 * V_9 = & V_34 [ V_48 ] . V_9 ;
for ( V_271 = 0 ; V_271 <= V_9 -> V_13 ; V_271 ++ ) {
F_38 (s, node, &hash->table[j]) {
if ( F_40 ( V_272 ) != F_211 ( V_233 ) )
continue;
if ( V_273 == V_267 ) {
V_269 -> V_274 = V_48 ;
V_269 -> V_275 = V_271 ;
return V_272 ;
}
++ V_273 ;
}
}
}
return NULL ;
}
static void * F_212 ( struct V_266 * V_233 , T_7 * V_267 )
__acquires( T_2 )
{
F_32 ( & T_2 ) ;
return * V_267 ? F_210 ( V_233 , * V_267 - 1 ) : V_276 ;
}
static void * F_213 ( struct V_266 * V_233 , void * V_277 , T_7 * V_267 )
{
struct V_2 * V_272 ;
struct V_268 * V_269 ;
int V_48 , V_271 ;
++ * V_267 ;
if ( V_277 == V_276 )
return F_210 ( V_233 , 0 ) ;
V_269 = V_233 -> V_270 ;
V_272 = V_277 ;
do {
V_272 = F_214 ( V_272 ) ;
} while ( V_272 && F_40 ( V_272 ) != F_211 ( V_233 ) );
if ( V_272 )
return V_272 ;
V_48 = V_269 -> V_274 ;
V_271 = V_269 -> V_275 + 1 ;
do {
struct V_8 * V_9 = & V_34 [ V_48 ] . V_9 ;
for (; V_271 <= V_9 -> V_13 ; V_271 ++ ) {
V_272 = F_215 ( & V_9 -> V_11 [ V_271 ] ) ;
while ( V_272 && F_40 ( V_272 ) != F_211 ( V_233 ) )
V_272 = F_214 ( V_272 ) ;
if ( V_272 ) {
V_269 -> V_274 = V_48 ;
V_269 -> V_275 = V_271 ;
return V_272 ;
}
}
V_271 = 0 ;
} while ( ++ V_48 < V_87 );
return NULL ;
}
static void F_216 ( struct V_266 * V_233 , void * V_277 )
__releases( T_2 )
{
F_34 ( & T_2 ) ;
}
static int F_217 ( struct V_266 * V_233 , void * V_277 )
{
if ( V_277 == V_276 ) {
F_218 ( V_233 ,
L_3
L_4 ) ;
} else {
struct V_2 * V_272 = V_277 ;
struct V_1 * V_17 = F_1 ( V_272 ) ;
F_219 ( V_233 , L_5 ,
V_272 ,
V_272 -> V_59 ,
V_17 -> V_10 ,
V_17 -> V_25 ? ( T_1 ) V_17 -> V_25 [ 0 ] : 0 ,
F_220 ( V_272 ) ,
F_221 ( V_272 ) ,
V_17 -> V_15 ,
F_18 ( & V_272 -> V_278 ) ,
F_18 ( & V_272 -> V_136 ) ,
F_222 ( V_272 )
) ;
}
return 0 ;
}
static int F_223 ( struct V_141 * V_141 , struct V_139 * V_139 )
{
return F_224 ( V_141 , V_139 , & V_279 ,
sizeof( struct V_268 ) ) ;
}
int F_225 ( struct V_280 * V_281 )
{
return F_226 ( & V_96 , V_281 ) ;
}
int F_227 ( struct V_280 * V_281 )
{
return F_228 ( & V_96 , V_281 ) ;
}
static int T_8 F_229 ( struct V_32 * V_32 )
{
#ifdef F_230
if ( ! F_231 ( V_32 , L_6 , 0 , & V_282 ) )
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
V_34 [ V_283 ] . V_25 = V_25 ;
F_180 ( V_34 [ V_283 ] . V_60 , V_60 ) ;
V_34 [ V_283 ] . V_19 = V_284 ;
V_34 [ V_283 ] . V_89 = 1 ;
V_34 [ V_283 ] . V_4 = V_128 ;
F_29 () ;
}
static int T_10 F_236 ( void )
{
struct V_148 * V_285 ;
int V_48 ;
unsigned long V_286 ;
unsigned int V_287 ;
int V_63 = F_237 ( & V_78 , 0 ) ;
if ( V_63 != 0 )
goto V_90;
F_238 ( sizeof( struct V_288 ) > sizeof( V_285 -> V_15 ) ) ;
V_34 = F_239 ( V_87 , sizeof( * V_34 ) , V_77 ) ;
if ( ! V_34 )
goto F_235;
if ( V_289 >= ( 128 * 1024 ) )
V_286 = V_289 >> ( 21 - V_290 ) ;
else
V_286 = V_289 >> ( 23 - V_290 ) ;
V_287 = F_240 ( V_286 ) - 1 + V_290 ;
V_286 = ( 1UL << V_287 ) / sizeof( struct V_7 ) ;
V_287 = F_240 ( F_241 ( V_286 , ( unsigned long ) V_69 ) ) - 1 ;
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
V_9 -> V_49 = V_287 ;
V_9 -> V_45 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_51 = V_52 ;
}
F_234 () ;
F_242 ( & V_291 ) ;
F_243 ( & V_292 ) ;
F_244 () ;
V_90:
return V_63 ;
F_235:
F_235 ( L_8 ) ;
}
