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
int V_62 = 0 ;
V_2 -> V_82 = V_83 ;
if ( V_2 -> type != V_84 && V_2 -> type != V_85 )
return - V_86 ;
if ( V_32 < 0 || V_32 >= V_87 )
return - V_88 ;
F_30 () ;
#ifdef F_68
if ( ! V_33 [ V_32 ] . V_89 ) {
F_34 () ;
F_69 ( L_2 , V_75 , V_32 ) ;
F_30 () ;
}
#endif
if ( V_33 [ V_32 ] . V_89 &&
F_70 ( V_33 [ V_32 ] . V_81 ) )
V_81 = V_33 [ V_32 ] . V_81 ;
else
V_62 = - V_88 ;
V_72 = V_33 [ V_32 ] . V_72 ;
F_34 () ;
if ( V_62 < 0 )
goto V_90;
V_62 = F_62 ( V_31 , V_2 , V_72 , V_32 ) ;
if ( V_62 < 0 )
goto V_91;
F_71 () ;
F_72 ( V_31 , & V_77 , 1 ) ;
F_73 () ;
V_17 = F_1 ( V_2 -> V_3 ) ;
V_17 -> V_81 = V_81 ;
V_90:
return V_62 ;
V_91:
F_74 ( V_81 ) ;
goto V_90;
}
static int F_75 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 ;
if ( ! V_3 )
return 0 ;
F_59 ( V_3 ) ;
F_76 ( V_3 ) ;
V_17 = F_1 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_77 ( & V_17 -> V_26 ) ;
F_13 ( & V_3 -> V_92 ) ;
if ( V_17 -> V_10 ) {
struct V_93 V_94 = {
. V_31 = F_39 ( V_3 ) ,
. V_32 = V_3 -> V_58 ,
. V_10 = V_17 -> V_10 ,
} ;
F_78 ( & V_95 ,
V_96 , & V_94 ) ;
}
F_74 ( V_17 -> V_81 ) ;
F_18 () ;
if ( F_3 ( V_3 ) ) {
F_79 ( V_33 [ V_3 -> V_58 ] . V_89 == 0 ) ;
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
F_71 () ;
F_72 ( F_39 ( V_3 ) , & V_77 , - 1 ) ;
F_73 () ;
F_80 ( V_3 ) ;
return 0 ;
}
static int F_81 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_31 * V_31 = F_39 ( V_3 ) ;
struct V_8 * V_9 = & V_33 [ V_3 -> V_58 ] . V_9 ;
struct V_7 * V_34 ;
struct V_2 * V_64 ;
struct V_35 * V_36 ;
T_4 V_10 = F_82 ( V_27 ) ;
int V_62 ;
static T_4 V_97 = - 4097 ;
V_98:
F_83 () ;
F_18 () ;
V_34 = F_5 ( V_9 , V_10 ) ;
F_37 (osk, node, head) {
if ( ! F_38 ( F_39 ( V_64 ) , V_31 ) )
continue;
if ( F_1 ( V_64 ) -> V_10 == V_10 ) {
V_10 = V_97 -- ;
if ( V_97 > - 4097 )
V_97 = - 4097 ;
F_28 () ;
goto V_98;
}
}
F_28 () ;
V_62 = F_57 ( V_3 , V_31 , V_10 ) ;
if ( V_62 == - V_63 )
goto V_98;
if ( V_62 == - V_65 )
V_62 = 0 ;
return V_62 ;
}
static inline int F_84 ( const struct V_70 * V_2 , unsigned int V_99 )
{
return ( V_33 [ V_2 -> V_3 -> V_58 ] . V_100 & V_99 ) ||
F_85 ( V_101 ) ;
}
static void
F_86 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_69 && ! V_69 )
F_61 ( V_3 ) ;
else if ( ! V_17 -> V_69 && V_69 )
F_87 ( V_3 , & V_33 [ V_3 -> V_58 ] . V_102 ) ;
V_17 -> V_69 = V_69 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_24 ;
unsigned long * V_103 ;
int V_62 = 0 ;
F_18 () ;
V_24 = V_33 [ V_3 -> V_58 ] . V_24 ;
if ( ! V_33 [ V_3 -> V_58 ] . V_89 ) {
V_62 = - V_104 ;
goto V_105;
}
if ( V_17 -> V_59 >= V_24 )
goto V_105;
V_103 = F_89 ( V_17 -> V_24 , F_90 ( V_24 ) , V_40 ) ;
if ( V_103 == NULL ) {
V_62 = - V_66 ;
goto V_105;
}
memset ( ( char * ) V_103 + F_90 ( V_17 -> V_59 ) , 0 ,
F_90 ( V_24 ) - F_90 ( V_17 -> V_59 ) ) ;
V_17 -> V_24 = V_103 ;
V_17 -> V_59 = V_24 ;
V_105:
F_28 () ;
return V_62 ;
}
static int F_91 ( struct V_70 * V_2 , struct V_106 * V_107 ,
int V_108 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_31 * V_31 = F_39 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_109 * V_110 = (struct V_109 * ) V_107 ;
int V_62 ;
if ( V_110 -> V_111 != V_112 )
return - V_113 ;
if ( V_110 -> V_114 ) {
if ( ! F_84 ( V_2 , V_115 ) )
return - V_116 ;
V_62 = F_88 ( V_3 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_17 -> V_10 ) {
if ( V_110 -> V_117 != V_17 -> V_10 )
return - V_113 ;
} else {
V_62 = V_110 -> V_117 ?
F_57 ( V_3 , V_31 , V_110 -> V_117 ) :
F_81 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
if ( ! V_110 -> V_114 && ( V_17 -> V_24 == NULL || ! ( T_1 ) V_17 -> V_24 [ 0 ] ) )
return 0 ;
F_18 () ;
F_86 ( V_3 , V_17 -> V_69 +
F_92 ( V_110 -> V_114 ) -
F_92 ( V_17 -> V_24 [ 0 ] ) ) ;
V_17 -> V_24 [ 0 ] = ( V_17 -> V_24 [ 0 ] & ~ 0xffffffffUL ) | V_110 -> V_114 ;
F_54 ( V_3 ) ;
F_28 () ;
return 0 ;
}
static int F_93 ( struct V_70 * V_2 , struct V_106 * V_107 ,
int V_118 , int V_4 )
{
int V_62 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_109 * V_110 = (struct V_109 * ) V_107 ;
if ( V_118 < sizeof( V_107 -> V_119 ) )
return - V_113 ;
if ( V_107 -> V_119 == V_120 ) {
V_3 -> V_121 = V_122 ;
V_17 -> V_123 = 0 ;
V_17 -> V_124 = 0 ;
return 0 ;
}
if ( V_107 -> V_119 != V_112 )
return - V_113 ;
if ( V_110 -> V_114 && ! F_84 ( V_2 , V_125 ) )
return - V_116 ;
if ( ! V_17 -> V_10 )
V_62 = F_81 ( V_2 ) ;
if ( V_62 == 0 ) {
V_3 -> V_121 = V_126 ;
V_17 -> V_123 = V_110 -> V_117 ;
V_17 -> V_124 = F_94 ( V_110 -> V_114 ) ;
}
return V_62 ;
}
static int F_95 ( struct V_70 * V_2 , struct V_106 * V_107 ,
int * V_108 , int V_127 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_96 ( struct V_109 * , V_110 , V_107 ) ;
V_110 -> V_111 = V_112 ;
V_110 -> V_128 = 0 ;
* V_108 = sizeof( * V_110 ) ;
if ( V_127 ) {
V_110 -> V_117 = V_17 -> V_123 ;
V_110 -> V_114 = F_4 ( V_17 -> V_124 ) ;
} else {
V_110 -> V_117 = V_17 -> V_10 ;
V_110 -> V_114 = V_17 -> V_24 ? V_17 -> V_24 [ 0 ] : 0 ;
}
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! ( V_17 -> V_4 & V_129 ) ) {
if ( ! F_98 ( 0 , & F_1 ( V_3 ) -> V_82 ) ) {
V_3 -> V_130 = V_131 ;
V_3 -> V_132 ( V_3 ) ;
}
}
F_32 ( & V_3 -> V_133 ) ;
}
static struct V_2 * F_99 ( struct V_2 * V_134 , T_1 V_10 )
{
struct V_2 * V_2 ;
struct V_1 * V_17 ;
V_2 = F_36 ( F_39 ( V_134 ) , V_134 -> V_58 , V_10 ) ;
if ( ! V_2 )
return F_100 ( - V_135 ) ;
V_17 = F_1 ( V_2 ) ;
if ( V_2 -> V_121 == V_126 &&
V_17 -> V_123 != F_1 ( V_134 ) -> V_10 ) {
F_80 ( V_2 ) ;
return F_100 ( - V_135 ) ;
}
return V_2 ;
}
struct V_2 * F_101 ( struct V_136 * V_137 )
{
struct V_138 * V_138 = V_137 -> V_139 . V_140 -> V_141 ;
struct V_2 * V_2 ;
if ( ! F_102 ( V_138 -> V_142 ) )
return F_100 ( - V_143 ) ;
V_2 = F_103 ( V_138 ) -> V_3 ;
if ( V_2 -> V_144 != V_112 )
return F_100 ( - V_113 ) ;
F_40 ( V_2 ) ;
return V_2 ;
}
int F_104 ( struct V_2 * V_3 , struct V_145 * V_16 ,
long * V_146 , struct V_2 * V_134 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 ) ;
if ( F_17 ( & V_3 -> V_22 ) > V_3 -> V_147 ||
F_105 ( 0 , & V_17 -> V_82 ) ) {
F_21 ( V_26 , V_27 ) ;
if ( ! * V_146 ) {
if ( ! V_134 || F_3 ( V_134 ) )
F_97 ( V_3 ) ;
F_80 ( V_3 ) ;
F_8 ( V_16 ) ;
return - V_148 ;
}
F_26 ( V_149 ) ;
F_106 ( & V_17 -> V_26 , & V_26 ) ;
if ( ( F_17 ( & V_3 -> V_22 ) > V_3 -> V_147 ||
F_105 ( 0 , & V_17 -> V_82 ) ) &&
! F_14 ( V_3 , V_20 ) )
* V_146 = F_107 ( * V_146 ) ;
F_26 ( V_30 ) ;
F_27 ( & V_17 -> V_26 , & V_26 ) ;
F_80 ( V_3 ) ;
if ( F_108 ( V_27 ) ) {
F_8 ( V_16 ) ;
return F_109 ( * V_146 ) ;
}
return 1 ;
}
F_110 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_145 * V_16 )
{
int V_53 = V_16 -> V_53 ;
F_112 ( & V_3 -> V_19 , V_16 ) ;
V_3 -> V_150 ( V_3 , V_53 ) ;
return V_53 ;
}
int F_113 ( struct V_2 * V_3 , struct V_145 * V_16 )
{
int V_53 = F_111 ( V_3 , V_16 ) ;
F_80 ( V_3 ) ;
return V_53 ;
}
void F_114 ( struct V_2 * V_3 , struct V_145 * V_16 )
{
F_8 ( V_16 ) ;
F_80 ( V_3 ) ;
}
static struct V_145 * F_115 ( struct V_145 * V_16 , T_5 V_151 )
{
int V_152 ;
F_116 ( V_16 ) ;
V_152 = V_16 -> V_153 - V_16 -> V_154 ;
if ( V_152 * 2 < V_16 -> V_155 )
return V_16 ;
if ( F_117 ( V_16 ) ) {
struct V_145 * V_156 = F_118 ( V_16 , V_151 ) ;
if ( ! V_156 )
return V_16 ;
F_11 ( V_16 ) ;
V_16 = V_156 ;
}
if ( ! F_119 ( V_16 , 0 , - V_152 , V_151 ) )
V_16 -> V_155 -= V_152 ;
return V_16 ;
}
static void F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_121 ( & V_3 -> V_19 ) )
F_122 ( 0 , & V_17 -> V_82 ) ;
if ( ! F_105 ( 0 , & V_17 -> V_82 ) )
F_123 ( & V_17 -> V_26 ) ;
}
static int F_124 ( struct V_2 * V_3 , struct V_145 * V_16 )
{
int V_157 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_157 = - V_135 ;
if ( V_17 -> V_158 != NULL ) {
V_157 = V_16 -> V_53 ;
F_110 ( V_16 , V_3 ) ;
V_17 -> V_158 ( V_16 ) ;
F_11 ( V_16 ) ;
} else {
F_8 ( V_16 ) ;
}
F_80 ( V_3 ) ;
return V_157 ;
}
int F_125 ( struct V_2 * V_134 , struct V_145 * V_16 ,
T_1 V_10 , int V_159 )
{
struct V_2 * V_3 ;
int V_62 ;
long V_146 ;
V_16 = F_115 ( V_16 , F_126 () ) ;
V_146 = F_127 ( V_134 , V_159 ) ;
V_98:
V_3 = F_99 ( V_134 , V_10 ) ;
if ( F_128 ( V_3 ) ) {
F_8 ( V_16 ) ;
return F_129 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_124 ( V_3 , V_16 ) ;
if ( F_130 ( V_3 , V_16 ) ) {
V_62 = V_16 -> V_53 ;
F_8 ( V_16 ) ;
F_80 ( V_3 ) ;
return V_62 ;
}
V_62 = F_104 ( V_3 , V_16 , & V_146 , V_134 ) ;
if ( V_62 == 1 )
goto V_98;
if ( V_62 )
return V_62 ;
return F_113 ( V_3 , V_16 ) ;
}
int F_131 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_160 = 0 ;
struct V_60 * V_60 ;
F_79 ( ! F_3 ( V_3 ) ) ;
F_132 () ;
V_60 = F_133 ( V_33 [ V_3 -> V_58 ] . V_60 ) ;
if ( V_6 - 1 < V_33 [ V_3 -> V_58 ] . V_24 )
V_160 = F_105 ( V_6 - 1 , V_60 -> V_61 ) ;
F_134 () ;
return V_160 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_145 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_17 ( & V_3 -> V_22 ) <= V_3 -> V_147 &&
! F_105 ( 0 , & V_17 -> V_82 ) ) {
F_110 ( V_16 , V_3 ) ;
F_111 ( V_3 , V_16 ) ;
return F_17 ( & V_3 -> V_22 ) > ( V_3 -> V_147 >> 1 ) ;
}
return - 1 ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_163 ;
if ( V_162 -> V_164 == V_3 )
goto V_90;
if ( V_17 -> V_10 == V_162 -> V_10 || V_162 -> V_6 - 1 >= V_17 -> V_59 ||
! F_105 ( V_162 -> V_6 - 1 , V_17 -> V_24 ) )
goto V_90;
if ( ! F_38 ( F_39 ( V_3 ) , V_162 -> V_31 ) )
goto V_90;
if ( V_162 -> V_165 ) {
F_97 ( V_3 ) ;
goto V_90;
}
F_40 ( V_3 ) ;
if ( V_162 -> V_166 == NULL ) {
if ( F_117 ( V_162 -> V_16 ) ) {
V_162 -> V_166 = F_118 ( V_162 -> V_16 , V_162 -> V_151 ) ;
} else {
V_162 -> V_166 = F_137 ( V_162 -> V_16 ) ;
F_116 ( V_162 -> V_166 ) ;
}
}
if ( V_162 -> V_166 == NULL ) {
F_97 ( V_3 ) ;
V_162 -> V_165 = 1 ;
if ( V_17 -> V_4 & V_167 )
V_162 -> V_168 = 1 ;
} else if ( V_162 -> V_169 && V_162 -> V_169 ( V_3 , V_162 -> V_166 , V_162 -> V_170 ) ) {
F_8 ( V_162 -> V_166 ) ;
V_162 -> V_166 = NULL ;
} else if ( F_130 ( V_3 , V_162 -> V_166 ) ) {
F_8 ( V_162 -> V_166 ) ;
V_162 -> V_166 = NULL ;
} else if ( ( V_163 = F_135 ( V_3 , V_162 -> V_166 ) ) < 0 ) {
F_97 ( V_3 ) ;
if ( V_17 -> V_4 & V_167 )
V_162 -> V_168 = 1 ;
} else {
V_162 -> V_171 |= V_163 ;
V_162 -> V_172 = 1 ;
V_162 -> V_166 = NULL ;
}
F_80 ( V_3 ) ;
V_90:
return 0 ;
}
int F_138 ( struct V_2 * V_134 , struct V_145 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_151 ,
int (* F_139)( struct V_2 * V_173 , struct V_145 * V_16 , void * V_174 ) ,
void * V_175 )
{
struct V_31 * V_31 = F_39 ( V_134 ) ;
struct V_161 V_176 ;
struct V_35 * V_36 ;
struct V_2 * V_3 ;
V_16 = F_115 ( V_16 , V_151 ) ;
V_176 . V_164 = V_134 ;
V_176 . V_31 = V_31 ;
V_176 . V_10 = V_10 ;
V_176 . V_6 = V_6 ;
V_176 . V_165 = 0 ;
V_176 . V_168 = 0 ;
V_176 . V_171 = 0 ;
V_176 . V_172 = 0 ;
V_176 . V_151 = V_151 ;
V_176 . V_16 = V_16 ;
V_176 . V_166 = NULL ;
V_176 . V_169 = F_139 ;
V_176 . V_170 = V_175 ;
F_30 () ;
F_56 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
F_136 ( V_3 , & V_176 ) ;
F_11 ( V_16 ) ;
F_34 () ;
if ( V_176 . V_168 ) {
F_8 ( V_176 . V_166 ) ;
return - V_131 ;
}
F_11 ( V_176 . V_166 ) ;
if ( V_176 . V_172 ) {
if ( V_176 . V_171 && ( V_151 & V_177 ) )
F_140 () ;
return 0 ;
}
return - V_178 ;
}
int F_141 ( struct V_2 * V_134 , struct V_145 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_151 )
{
return F_138 ( V_134 , V_16 , V_10 , V_6 , V_151 ,
NULL , NULL ) ;
}
static int F_142 ( struct V_2 * V_3 , struct V_179 * V_162 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_157 = 0 ;
if ( V_3 == V_162 -> V_164 )
goto V_90;
if ( ! F_38 ( F_39 ( V_3 ) , F_39 ( V_162 -> V_164 ) ) )
goto V_90;
if ( V_17 -> V_10 == V_162 -> V_10 || V_162 -> V_6 - 1 >= V_17 -> V_59 ||
! F_105 ( V_162 -> V_6 - 1 , V_17 -> V_24 ) )
goto V_90;
if ( V_162 -> V_180 == V_131 && V_17 -> V_4 & V_129 ) {
V_157 = 1 ;
goto V_90;
}
V_3 -> V_130 = V_162 -> V_180 ;
V_3 -> V_132 ( V_3 ) ;
V_90:
return V_157 ;
}
int F_143 ( struct V_2 * V_134 , T_1 V_10 , T_1 V_6 , int V_180 )
{
struct V_179 V_176 ;
struct V_35 * V_36 ;
struct V_2 * V_3 ;
int V_157 = 0 ;
V_176 . V_164 = V_134 ;
V_176 . V_10 = V_10 ;
V_176 . V_6 = V_6 ;
V_176 . V_180 = - V_180 ;
F_31 ( & T_2 ) ;
F_56 (sk, node, &nl_table[ssk->sk_protocol].mc_list)
V_157 += F_142 ( V_3 , & V_176 ) ;
F_33 ( & T_2 ) ;
return V_157 ;
}
static void F_144 ( struct V_1 * V_17 ,
unsigned int V_6 ,
int V_181 )
{
int V_182 , V_183 = ! ! V_181 , V_69 ;
V_182 = F_105 ( V_6 - 1 , V_17 -> V_24 ) ;
V_69 = V_17 -> V_69 - V_182 + V_183 ;
if ( V_183 )
F_145 ( V_6 - 1 , V_17 -> V_24 ) ;
else
F_146 ( V_6 - 1 , V_17 -> V_24 ) ;
F_86 ( & V_17 -> V_3 , V_69 ) ;
F_54 ( & V_17 -> V_3 ) ;
}
static int F_147 ( struct V_70 * V_2 , int V_184 , int V_185 ,
char T_6 * V_186 , unsigned int V_187 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_163 = 0 ;
int V_62 ;
if ( V_184 != V_188 )
return - V_189 ;
if ( V_187 >= sizeof( int ) &&
F_148 ( V_163 , ( unsigned int T_6 * ) V_186 ) )
return - V_190 ;
switch ( V_185 ) {
case V_191 :
if ( V_163 )
V_17 -> V_4 |= V_192 ;
else
V_17 -> V_4 &= ~ V_192 ;
V_62 = 0 ;
break;
case V_193 :
case V_194 : {
if ( ! F_84 ( V_2 , V_115 ) )
return - V_116 ;
V_62 = F_88 ( V_3 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_163 || V_163 - 1 >= V_17 -> V_59 )
return - V_113 ;
F_18 () ;
F_144 ( V_17 , V_163 ,
V_185 == V_193 ) ;
F_28 () ;
V_62 = 0 ;
break;
}
case V_195 :
if ( V_163 )
V_17 -> V_4 |= V_167 ;
else
V_17 -> V_4 &= ~ V_167 ;
V_62 = 0 ;
break;
case V_196 :
if ( V_163 ) {
V_17 -> V_4 |= V_129 ;
F_122 ( 0 , & V_17 -> V_82 ) ;
F_123 ( & V_17 -> V_26 ) ;
} else {
V_17 -> V_4 &= ~ V_129 ;
}
V_62 = 0 ;
break;
default:
V_62 = - V_189 ;
}
return V_62 ;
}
static int F_149 ( struct V_70 * V_2 , int V_184 , int V_185 ,
char T_6 * V_186 , int T_6 * V_187 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_53 , V_163 , V_62 ;
if ( V_184 != V_188 )
return - V_189 ;
if ( F_148 ( V_53 , V_187 ) )
return - V_190 ;
if ( V_53 < 0 )
return - V_113 ;
switch ( V_185 ) {
case V_191 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_163 = V_17 -> V_4 & V_192 ? 1 : 0 ;
if ( F_150 ( V_53 , V_187 ) ||
F_150 ( V_163 , V_186 ) )
return - V_190 ;
V_62 = 0 ;
break;
case V_195 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_163 = V_17 -> V_4 & V_167 ? 1 : 0 ;
if ( F_150 ( V_53 , V_187 ) ||
F_150 ( V_163 , V_186 ) )
return - V_190 ;
V_62 = 0 ;
break;
case V_196 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_163 = V_17 -> V_4 & V_129 ? 1 : 0 ;
if ( F_150 ( V_53 , V_187 ) ||
F_150 ( V_163 , V_186 ) )
return - V_190 ;
V_62 = 0 ;
break;
default:
V_62 = - V_189 ;
}
return V_62 ;
}
static void F_151 ( struct V_197 * V_198 , struct V_145 * V_16 )
{
struct V_199 V_176 ;
V_176 . V_6 = F_152 ( V_16 ) . V_124 ;
F_153 ( V_198 , V_188 , V_191 , sizeof( V_176 ) , & V_176 ) ;
}
static int F_154 ( struct V_200 * V_200 , struct V_70 * V_2 ,
struct V_197 * V_198 , T_3 V_53 )
{
struct V_201 * V_202 = F_155 ( V_200 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_109 * V_107 = V_198 -> V_203 ;
T_1 V_123 ;
T_1 V_124 ;
struct V_145 * V_16 ;
int V_62 ;
struct V_204 V_205 ;
if ( V_198 -> V_206 & V_207 )
return - V_208 ;
if ( NULL == V_202 -> V_205 )
V_202 -> V_205 = & V_205 ;
V_62 = F_156 ( V_2 , V_198 , V_202 -> V_205 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_198 -> V_209 ) {
V_62 = - V_113 ;
if ( V_107 -> V_111 != V_112 )
goto V_90;
V_123 = V_107 -> V_117 ;
V_124 = F_94 ( V_107 -> V_114 ) ;
V_62 = - V_116 ;
if ( V_124 && ! F_84 ( V_2 , V_125 ) )
goto V_90;
} else {
V_123 = V_17 -> V_123 ;
V_124 = V_17 -> V_124 ;
}
if ( ! V_17 -> V_10 ) {
V_62 = F_81 ( V_2 ) ;
if ( V_62 )
goto V_90;
}
V_62 = - V_210 ;
if ( V_53 > V_3 -> V_211 - 32 )
goto V_90;
V_62 = - V_131 ;
V_16 = F_157 ( V_53 , V_76 ) ;
if ( V_16 == NULL )
goto V_90;
F_152 ( V_16 ) . V_10 = V_17 -> V_10 ;
F_152 ( V_16 ) . V_124 = V_124 ;
memcpy ( F_158 ( V_16 ) , & V_202 -> V_205 -> V_212 , sizeof( struct V_213 ) ) ;
V_62 = - V_190 ;
if ( F_159 ( F_160 ( V_16 , V_53 ) , V_198 -> V_214 , V_53 ) ) {
F_8 ( V_16 ) ;
goto V_90;
}
V_62 = F_161 ( V_3 , V_16 ) ;
if ( V_62 ) {
F_8 ( V_16 ) ;
goto V_90;
}
if ( V_124 ) {
F_32 ( & V_16 -> V_215 ) ;
F_141 ( V_3 , V_16 , V_123 , V_124 , V_76 ) ;
}
V_62 = F_125 ( V_3 , V_16 , V_123 , V_198 -> V_206 & V_216 ) ;
V_90:
F_162 ( V_202 -> V_205 ) ;
return V_62 ;
}
static int F_163 ( struct V_200 * V_200 , struct V_70 * V_2 ,
struct V_197 * V_198 , T_3 V_53 ,
int V_4 )
{
struct V_201 * V_202 = F_155 ( V_200 ) ;
struct V_204 V_205 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_217 = V_4 & V_216 ;
T_3 V_218 ;
struct V_145 * V_16 , * V_219 ;
int V_62 , V_157 ;
if ( V_4 & V_207 )
return - V_208 ;
V_218 = 0 ;
V_16 = F_164 ( V_3 , V_4 , V_217 , & V_62 ) ;
if ( V_16 == NULL )
goto V_90;
V_219 = V_16 ;
#ifdef F_165
if ( F_52 ( F_166 ( V_16 ) -> V_220 ) ) {
if ( V_4 & V_221 )
V_219 = F_166 ( V_16 ) -> V_220 ;
}
#endif
V_198 -> V_209 = 0 ;
V_218 = V_219 -> V_53 ;
if ( V_53 < V_218 ) {
V_198 -> V_206 |= V_222 ;
V_218 = V_53 ;
}
F_167 ( V_219 ) ;
V_62 = F_168 ( V_219 , 0 , V_198 -> V_214 , V_218 ) ;
if ( V_198 -> V_203 ) {
struct V_109 * V_107 = (struct V_109 * ) V_198 -> V_203 ;
V_107 -> V_111 = V_112 ;
V_107 -> V_128 = 0 ;
V_107 -> V_117 = F_152 ( V_16 ) . V_10 ;
V_107 -> V_114 = F_4 ( F_152 ( V_16 ) . V_124 ) ;
V_198 -> V_209 = sizeof( * V_107 ) ;
}
if ( V_17 -> V_4 & V_192 )
F_151 ( V_198 , V_16 ) ;
if ( NULL == V_202 -> V_205 ) {
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_202 -> V_205 = & V_205 ;
}
V_202 -> V_205 -> V_212 = * F_158 ( V_16 ) ;
if ( V_4 & V_222 )
V_218 = V_219 -> V_53 ;
F_169 ( V_3 , V_16 ) ;
if ( V_17 -> V_15 && F_17 ( & V_3 -> V_22 ) <= V_3 -> V_147 / 2 ) {
V_157 = F_170 ( V_3 ) ;
if ( V_157 ) {
V_3 -> V_130 = V_157 ;
V_3 -> V_132 ( V_3 ) ;
}
}
F_171 ( V_2 , V_198 , V_202 -> V_205 , V_4 ) ;
V_90:
F_120 ( V_3 ) ;
return V_62 ? : V_218 ;
}
static void F_172 ( struct V_2 * V_3 , int V_53 )
{
F_173 () ;
}
struct V_2 *
F_174 ( struct V_31 * V_31 , int V_223 , unsigned int V_24 ,
void (* F_175)( struct V_145 * V_16 ) ,
struct V_71 * V_72 , struct V_81 * V_81 )
{
struct V_70 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_60 * V_60 = NULL ;
F_79 ( ! V_33 ) ;
if ( V_223 < 0 || V_223 >= V_87 )
return NULL ;
if ( F_176 ( V_75 , V_85 , V_223 , & V_2 ) )
return NULL ;
if ( F_62 ( & V_224 , V_2 , V_72 , V_223 ) < 0 )
goto V_225;
V_3 = V_2 -> V_3 ;
F_177 ( V_3 , V_31 ) ;
if ( V_24 < 32 )
V_24 = 32 ;
V_60 = F_42 ( sizeof( * V_60 ) + F_90 ( V_24 ) , V_76 ) ;
if ( ! V_60 )
goto V_226;
V_3 -> V_150 = F_172 ;
if ( F_175 )
F_1 ( V_3 ) -> V_158 = F_175 ;
if ( F_57 ( V_3 , V_31 , 0 ) )
goto V_226;
V_17 = F_1 ( V_3 ) ;
V_17 -> V_4 |= V_5 ;
F_18 () ;
if ( ! V_33 [ V_223 ] . V_89 ) {
V_33 [ V_223 ] . V_24 = V_24 ;
F_178 ( V_33 [ V_223 ] . V_60 , V_60 ) ;
V_33 [ V_223 ] . V_72 = V_72 ;
V_33 [ V_223 ] . V_81 = V_81 ;
V_33 [ V_223 ] . V_89 = 1 ;
} else {
F_9 ( V_60 ) ;
V_33 [ V_223 ] . V_89 ++ ;
}
F_28 () ;
return V_3 ;
V_226:
F_9 ( V_60 ) ;
F_179 ( V_3 ) ;
return NULL ;
V_225:
F_180 ( V_2 ) ;
return NULL ;
}
void
F_179 ( struct V_2 * V_3 )
{
F_181 ( V_3 ) ;
}
int F_182 ( struct V_2 * V_3 , unsigned int V_24 )
{
struct V_60 * V_183 , * V_182 ;
struct V_56 * V_57 = & V_33 [ V_3 -> V_58 ] ;
if ( V_24 < 32 )
V_24 = 32 ;
if ( F_90 ( V_57 -> V_24 ) < F_90 ( V_24 ) ) {
V_183 = F_42 ( sizeof( * V_183 ) + F_90 ( V_24 ) , V_40 ) ;
if ( ! V_183 )
return - V_66 ;
V_182 = F_183 ( V_57 -> V_60 , 1 ) ;
memcpy ( V_183 -> V_61 , V_182 -> V_61 , F_90 ( V_57 -> V_24 ) ) ;
F_178 ( V_57 -> V_60 , V_183 ) ;
F_184 ( V_182 , V_227 ) ;
}
V_57 -> V_24 = V_24 ;
return 0 ;
}
int F_185 ( struct V_2 * V_3 , unsigned int V_24 )
{
int V_62 ;
F_18 () ;
V_62 = F_182 ( V_3 , V_24 ) ;
F_28 () ;
return V_62 ;
}
void F_186 ( struct V_2 * V_228 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_35 * V_36 ;
struct V_56 * V_57 = & V_33 [ V_228 -> V_58 ] ;
F_56 (sk, node, &tbl->mc_list)
F_144 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_187 ( struct V_2 * V_228 , unsigned int V_6 )
{
F_18 () ;
F_186 ( V_228 , V_6 ) ;
F_28 () ;
}
void F_188 ( int V_32 , unsigned int V_4 )
{
if ( ( unsigned int ) V_32 < V_87 )
V_33 [ V_32 ] . V_100 = V_4 ;
}
struct V_229 *
F_189 ( struct V_145 * V_16 , T_1 V_10 , T_1 V_230 , int type , int V_53 , int V_4 )
{
struct V_229 * V_231 ;
int V_38 = F_190 ( V_53 ) ;
V_231 = (struct V_229 * ) F_160 ( V_16 , F_191 ( V_38 ) ) ;
V_231 -> V_232 = type ;
V_231 -> V_233 = V_38 ;
V_231 -> V_234 = V_4 ;
V_231 -> V_235 = V_10 ;
V_231 -> V_236 = V_230 ;
if ( ! F_192 ( V_38 ) || F_191 ( V_38 ) - V_38 != 0 )
memset ( F_193 ( V_231 ) + V_53 , 0 , F_191 ( V_38 ) - V_38 ) ;
return V_231 ;
}
static int F_170 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
struct V_145 * V_16 = NULL ;
struct V_229 * V_231 ;
int V_53 , V_62 = - V_131 ;
int V_237 ;
F_194 ( V_17 -> V_72 ) ;
V_15 = V_17 -> V_15 ;
if ( V_15 == NULL ) {
V_62 = - V_113 ;
goto V_238;
}
V_237 = F_195 ( int , V_15 -> V_239 , V_240 ) ;
V_16 = F_196 ( V_3 , V_237 , 0 , V_76 ) ;
if ( ! V_16 )
goto V_238;
V_53 = V_15 -> V_241 ( V_16 , V_15 ) ;
if ( V_53 > 0 ) {
F_197 ( V_17 -> V_72 ) ;
if ( F_130 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_111 ( V_3 , V_16 ) ;
return 0 ;
}
V_231 = F_198 ( V_16 , V_15 , V_242 , sizeof( V_53 ) , V_243 ) ;
if ( ! V_231 )
goto V_238;
F_199 ( V_15 , V_231 ) ;
memcpy ( F_200 ( V_231 ) , & V_53 , sizeof( V_53 ) ) ;
if ( F_130 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_111 ( V_3 , V_16 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 ) ;
V_17 -> V_15 = NULL ;
F_197 ( V_17 -> V_72 ) ;
F_10 ( V_15 ) ;
return 0 ;
V_238:
F_197 ( V_17 -> V_72 ) ;
F_8 ( V_16 ) ;
return V_62 ;
}
int F_201 ( struct V_2 * V_134 , struct V_145 * V_16 ,
const struct V_229 * V_231 ,
struct V_244 * V_245 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
int V_157 ;
V_15 = F_42 ( sizeof( * V_15 ) , V_76 ) ;
if ( V_15 == NULL )
return - V_131 ;
V_15 -> V_241 = V_245 -> V_241 ;
V_15 -> V_18 = V_245 -> V_18 ;
V_15 -> V_231 = V_231 ;
V_15 -> V_174 = V_245 -> V_174 ;
V_15 -> V_239 = V_245 -> V_239 ;
F_32 ( & V_16 -> V_215 ) ;
V_15 -> V_16 = V_16 ;
V_3 = F_36 ( F_39 ( V_134 ) , V_134 -> V_58 , F_152 ( V_16 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_7 ( V_15 ) ;
return - V_135 ;
}
V_17 = F_1 ( V_3 ) ;
F_194 ( V_17 -> V_72 ) ;
if ( V_17 -> V_15 ) {
F_197 ( V_17 -> V_72 ) ;
F_7 ( V_15 ) ;
F_80 ( V_3 ) ;
return - V_65 ;
}
V_17 -> V_15 = V_15 ;
F_197 ( V_17 -> V_72 ) ;
V_157 = F_170 ( V_3 ) ;
F_80 ( V_3 ) ;
if ( V_157 )
return V_157 ;
return - V_246 ;
}
void F_202 ( struct V_145 * V_247 , struct V_229 * V_231 , int V_62 )
{
struct V_145 * V_16 ;
struct V_229 * V_248 ;
struct V_249 * V_250 ;
T_3 V_251 = sizeof( * V_250 ) ;
if ( V_62 )
V_251 += V_233 ( V_231 ) ;
V_16 = F_203 ( V_251 , V_76 ) ;
if ( ! V_16 ) {
struct V_2 * V_3 ;
V_3 = F_36 ( F_39 ( V_247 -> V_3 ) ,
V_247 -> V_3 -> V_58 ,
F_152 ( V_247 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_130 = V_131 ;
V_3 -> V_132 ( V_3 ) ;
F_80 ( V_3 ) ;
}
return;
}
V_248 = F_189 ( V_16 , F_152 ( V_247 ) . V_10 , V_231 -> V_236 ,
V_252 , V_251 , 0 ) ;
V_250 = F_200 ( V_248 ) ;
V_250 -> error = V_62 ;
memcpy ( & V_250 -> V_198 , V_231 , V_62 ? V_231 -> V_233 : sizeof( * V_231 ) ) ;
F_125 ( V_247 -> V_3 , V_16 , F_152 ( V_247 ) . V_10 , V_216 ) ;
}
int F_204 ( struct V_145 * V_16 , int (* V_15)( struct V_145 * ,
struct V_229 * ) )
{
struct V_229 * V_231 ;
int V_62 ;
while ( V_16 -> V_53 >= F_205 ( 0 ) ) {
int V_253 ;
V_231 = F_206 ( V_16 ) ;
V_62 = 0 ;
if ( V_231 -> V_233 < V_254 || V_16 -> V_53 < V_231 -> V_233 )
return 0 ;
if ( ! ( V_231 -> V_234 & V_255 ) )
goto V_256;
if ( V_231 -> V_232 < V_257 )
goto V_256;
V_62 = V_15 ( V_16 , V_231 ) ;
if ( V_62 == - V_246 )
goto V_258;
V_256:
if ( V_231 -> V_234 & V_259 || V_62 )
F_202 ( V_16 , V_231 , V_62 ) ;
V_258:
V_253 = F_191 ( V_231 -> V_233 ) ;
if ( V_253 > V_16 -> V_53 )
V_253 = V_16 -> V_53 ;
F_207 ( V_16 , V_253 ) ;
}
return 0 ;
}
int F_208 ( struct V_2 * V_3 , struct V_145 * V_16 , T_1 V_10 ,
unsigned int V_6 , int V_260 , T_5 V_4 )
{
int V_62 = 0 ;
if ( V_6 ) {
int V_261 = 0 ;
if ( V_260 ) {
F_32 ( & V_16 -> V_215 ) ;
V_261 = V_10 ;
}
V_62 = F_209 ( V_3 , V_16 , V_261 , V_6 , V_4 ) ;
}
if ( V_260 ) {
int V_262 ;
V_262 = F_210 ( V_3 , V_16 , V_10 ) ;
if ( ! V_62 || V_62 == - V_178 )
V_62 = V_262 ;
}
return V_62 ;
}
static struct V_2 * F_211 ( struct V_263 * V_230 , T_7 V_264 )
{
struct V_265 * V_266 = V_230 -> V_267 ;
int V_47 , V_268 ;
struct V_2 * V_269 ;
struct V_35 * V_36 ;
T_7 V_270 = 0 ;
for ( V_47 = 0 ; V_47 < V_87 ; V_47 ++ ) {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
for ( V_268 = 0 ; V_268 <= V_9 -> V_13 ; V_268 ++ ) {
F_37 (s, node, &hash->table[j]) {
if ( F_39 ( V_269 ) != F_212 ( V_230 ) )
continue;
if ( V_270 == V_264 ) {
V_266 -> V_271 = V_47 ;
V_266 -> V_272 = V_268 ;
return V_269 ;
}
++ V_270 ;
}
}
}
return NULL ;
}
static void * F_213 ( struct V_263 * V_230 , T_7 * V_264 )
__acquires( T_2 )
{
F_31 ( & T_2 ) ;
return * V_264 ? F_211 ( V_230 , * V_264 - 1 ) : V_273 ;
}
static void * F_214 ( struct V_263 * V_230 , void * V_274 , T_7 * V_264 )
{
struct V_2 * V_269 ;
struct V_265 * V_266 ;
int V_47 , V_268 ;
++ * V_264 ;
if ( V_274 == V_273 )
return F_211 ( V_230 , 0 ) ;
V_266 = V_230 -> V_267 ;
V_269 = V_274 ;
do {
V_269 = F_215 ( V_269 ) ;
} while ( V_269 && F_39 ( V_269 ) != F_212 ( V_230 ) );
if ( V_269 )
return V_269 ;
V_47 = V_266 -> V_271 ;
V_268 = V_266 -> V_272 + 1 ;
do {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
for (; V_268 <= V_9 -> V_13 ; V_268 ++ ) {
V_269 = F_216 ( & V_9 -> V_11 [ V_268 ] ) ;
while ( V_269 && F_39 ( V_269 ) != F_212 ( V_230 ) )
V_269 = F_215 ( V_269 ) ;
if ( V_269 ) {
V_266 -> V_271 = V_47 ;
V_266 -> V_272 = V_268 ;
return V_269 ;
}
}
V_268 = 0 ;
} while ( ++ V_47 < V_87 );
return NULL ;
}
static void F_217 ( struct V_263 * V_230 , void * V_274 )
__releases( T_2 )
{
F_33 ( & T_2 ) ;
}
static int F_218 ( struct V_263 * V_230 , void * V_274 )
{
if ( V_274 == V_273 ) {
F_219 ( V_230 ,
L_3
L_4 ) ;
} else {
struct V_2 * V_269 = V_274 ;
struct V_1 * V_17 = F_1 ( V_269 ) ;
F_220 ( V_230 , L_5 ,
V_269 ,
V_269 -> V_58 ,
V_17 -> V_10 ,
V_17 -> V_24 ? ( T_1 ) V_17 -> V_24 [ 0 ] : 0 ,
F_221 ( V_269 ) ,
F_222 ( V_269 ) ,
V_17 -> V_15 ,
F_17 ( & V_269 -> V_275 ) ,
F_17 ( & V_269 -> V_133 ) ,
F_223 ( V_269 )
) ;
}
return 0 ;
}
static int F_224 ( struct V_138 * V_138 , struct V_136 * V_136 )
{
return F_225 ( V_138 , V_136 , & V_276 ,
sizeof( struct V_265 ) ) ;
}
int F_226 ( struct V_277 * V_278 )
{
return F_227 ( & V_95 , V_278 ) ;
}
int F_228 ( struct V_277 * V_278 )
{
return F_229 ( & V_95 , V_278 ) ;
}
static int T_8 F_230 ( struct V_31 * V_31 )
{
#ifdef F_231
if ( ! F_232 ( V_31 , L_6 , 0 , & V_279 ) )
return - V_66 ;
#endif
return 0 ;
}
static void T_9 F_233 ( struct V_31 * V_31 )
{
#ifdef F_231
F_234 ( V_31 , L_6 ) ;
#endif
}
static void T_10 F_235 ( void )
{
struct V_60 * V_60 ;
int V_24 = 32 ;
V_60 = F_42 ( sizeof( * V_60 ) + F_90 ( V_24 ) , V_76 ) ;
if ( ! V_60 )
F_236 ( L_7 ) ;
F_18 () ;
V_33 [ V_280 ] . V_24 = V_24 ;
F_178 ( V_33 [ V_280 ] . V_60 , V_60 ) ;
V_33 [ V_280 ] . V_81 = V_281 ;
V_33 [ V_280 ] . V_89 = 1 ;
F_28 () ;
}
static int T_10 F_237 ( void )
{
struct V_145 * V_282 ;
int V_47 ;
unsigned long V_283 ;
unsigned int V_284 ;
int V_62 = F_238 ( & V_77 , 0 ) ;
if ( V_62 != 0 )
goto V_90;
F_239 ( sizeof( struct V_285 ) > sizeof( V_282 -> V_15 ) ) ;
V_33 = F_240 ( V_87 , sizeof( * V_33 ) , V_76 ) ;
if ( ! V_33 )
goto F_236;
if ( V_286 >= ( 128 * 1024 ) )
V_283 = V_286 >> ( 21 - V_287 ) ;
else
V_283 = V_286 >> ( 23 - V_287 ) ;
V_284 = F_241 ( V_283 ) - 1 + V_287 ;
V_283 = ( 1UL << V_284 ) / sizeof( struct V_7 ) ;
V_284 = F_241 ( F_242 ( V_283 , ( unsigned long ) V_68 ) ) - 1 ;
for ( V_47 = 0 ; V_47 < V_87 ; V_47 ++ ) {
struct V_8 * V_9 = & V_33 [ V_47 ] . V_9 ;
V_9 -> V_11 = F_41 ( 1 * sizeof( * V_9 -> V_11 ) ) ;
if ( ! V_9 -> V_11 ) {
while ( V_47 -- > 0 )
F_45 ( V_33 [ V_47 ] . V_9 . V_11 ,
1 * sizeof( * V_9 -> V_11 ) ) ;
F_9 ( V_33 ) ;
goto F_236;
}
V_9 -> V_48 = V_284 ;
V_9 -> V_44 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_50 = V_51 ;
}
F_235 () ;
F_243 ( & V_288 ) ;
F_244 ( & V_289 ) ;
F_245 () ;
V_90:
return V_62 ;
F_236:
F_236 ( L_8 ) ;
}
