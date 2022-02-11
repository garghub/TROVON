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
F_32 ( & T_2 ) ;
V_35 = F_5 ( V_9 , V_10 ) ;
F_38 (sk, head) {
if ( F_39 ( F_40 ( V_3 ) , V_32 ) && ( F_1 ( V_3 ) -> V_10 == V_10 ) ) {
F_41 ( V_3 ) ;
goto V_36;
}
}
V_3 = NULL ;
V_36:
F_34 ( & T_2 ) ;
return V_3 ;
}
static struct V_7 * F_42 ( T_3 V_37 )
{
if ( V_37 <= V_38 )
return F_43 ( V_37 , V_39 ) ;
else
return (struct V_7 * )
F_44 ( V_39 | V_40 ,
F_45 ( V_37 ) ) ;
}
static void F_46 ( struct V_7 * V_11 , T_3 V_37 )
{
if ( V_37 <= V_38 )
F_9 ( V_11 ) ;
else
F_47 ( ( unsigned long ) V_11 , F_45 ( V_37 ) ) ;
}
static int F_48 ( struct V_8 * V_9 , int V_41 )
{
unsigned int V_42 , V_13 , V_43 ;
T_3 V_44 , V_37 ;
struct V_7 * V_45 , * V_11 ;
int V_46 ;
V_42 = V_13 = V_9 -> V_13 ;
V_44 = V_37 = ( V_13 + 1 ) * sizeof( * V_11 ) ;
V_43 = V_9 -> V_43 ;
if ( V_41 ) {
if ( ++ V_43 > V_9 -> V_47 )
return 0 ;
V_13 = V_13 * 2 + 1 ;
V_37 *= 2 ;
}
V_11 = F_42 ( V_37 ) ;
if ( ! V_11 )
return 0 ;
V_45 = V_9 -> V_11 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_43 = V_43 ;
F_49 ( & V_9 -> V_12 , sizeof( V_9 -> V_12 ) ) ;
for ( V_46 = 0 ; V_46 <= V_42 ; V_46 ++ ) {
struct V_2 * V_3 ;
struct V_48 * V_49 ;
F_50 (sk, tmp, &otable[i])
F_51 ( V_3 , F_5 ( V_9 , F_1 ( V_3 ) -> V_10 ) ) ;
}
F_46 ( V_45 , V_44 ) ;
V_9 -> V_50 = V_51 + 10 * 60 * V_52 ;
return 1 ;
}
static inline int F_52 ( struct V_8 * V_9 , int V_53 )
{
int V_54 = V_9 -> V_55 >> V_9 -> V_43 ;
if ( F_53 ( V_54 > 1 ) && F_48 ( V_9 , 1 ) )
return 1 ;
if ( F_53 ( V_53 > V_54 ) && F_54 ( V_51 , V_9 -> V_50 ) ) {
F_48 ( V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_55 ( struct V_2 * V_3 )
{
struct V_56 * V_57 = & V_34 [ V_3 -> V_58 ] ;
unsigned long V_13 ;
unsigned int V_46 ;
struct V_59 * V_59 ;
V_59 = F_56 ( V_57 -> V_59 ) ;
if ( ! V_59 )
return;
for ( V_46 = 0 ; V_46 < F_57 ( V_57 -> V_25 ) ; V_46 ++ ) {
V_13 = 0 ;
F_58 (sk, &tbl->mc_list) {
if ( V_46 < F_57 ( F_1 ( V_3 ) -> V_60 ) )
V_13 |= F_1 ( V_3 ) -> V_25 [ V_46 ] ;
}
V_59 -> V_61 [ V_46 ] = V_13 ;
}
}
static int F_59 ( struct V_2 * V_3 , struct V_32 * V_32 , T_1 V_10 )
{
struct V_8 * V_9 = & V_34 [ V_3 -> V_58 ] . V_9 ;
struct V_7 * V_35 ;
int V_62 = - V_63 ;
struct V_2 * V_64 ;
int V_53 ;
F_19 () ;
V_35 = F_5 ( V_9 , V_10 ) ;
V_53 = 0 ;
F_38 (osk, head) {
if ( F_39 ( F_40 ( V_64 ) , V_32 ) && ( F_1 ( V_64 ) -> V_10 == V_10 ) )
break;
V_53 ++ ;
}
if ( V_64 )
goto V_62;
V_62 = - V_65 ;
if ( F_1 ( V_3 ) -> V_10 )
goto V_62;
V_62 = - V_66 ;
if ( V_67 > 32 && F_53 ( V_9 -> V_55 >= V_68 ) )
goto V_62;
if ( V_53 && F_52 ( V_9 , V_53 ) )
V_35 = F_5 ( V_9 , V_10 ) ;
V_9 -> V_55 ++ ;
F_1 ( V_3 ) -> V_10 = V_10 ;
F_60 ( V_3 , V_35 ) ;
V_62 = 0 ;
V_62:
F_29 () ;
return V_62 ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_19 () ;
if ( F_62 ( V_3 ) )
V_34 [ V_3 -> V_58 ] . V_9 . V_55 -- ;
if ( F_1 ( V_3 ) -> V_69 )
F_63 ( V_3 ) ;
F_29 () ;
}
static int F_64 ( struct V_32 * V_32 , struct V_70 * V_2 ,
struct V_71 * V_72 , int V_33 )
{
struct V_2 * V_3 ;
struct V_1 * V_17 ;
V_2 -> V_73 = & V_74 ;
V_3 = F_65 ( V_32 , V_75 , V_76 , & V_77 ) ;
if ( ! V_3 )
return - V_66 ;
F_66 ( V_2 , V_3 ) ;
V_17 = F_1 ( V_3 ) ;
if ( V_72 ) {
V_17 -> V_72 = V_72 ;
} else {
V_17 -> V_72 = & V_17 -> V_78 ;
F_67 ( V_17 -> V_72 ) ;
}
F_68 ( & V_17 -> V_27 ) ;
V_3 -> V_79 = F_12 ;
V_3 -> V_58 = V_33 ;
return 0 ;
}
static int F_69 ( struct V_32 * V_32 , struct V_70 * V_2 , int V_33 ,
int V_80 )
{
struct V_19 * V_19 = NULL ;
struct V_71 * V_72 ;
struct V_1 * V_17 ;
void (* F_70)( int V_6 );
int V_62 = 0 ;
V_2 -> V_81 = V_82 ;
if ( V_2 -> type != V_83 && V_2 -> type != V_84 )
return - V_85 ;
if ( V_33 < 0 || V_33 >= V_86 )
return - V_87 ;
F_31 () ;
#ifdef F_71
if ( ! V_34 [ V_33 ] . V_88 ) {
F_35 () ;
F_72 ( L_2 , V_75 , V_33 ) ;
F_31 () ;
}
#endif
if ( V_34 [ V_33 ] . V_88 &&
F_73 ( V_34 [ V_33 ] . V_19 ) )
V_19 = V_34 [ V_33 ] . V_19 ;
else
V_62 = - V_87 ;
V_72 = V_34 [ V_33 ] . V_72 ;
F_70 = V_34 [ V_33 ] . F_70 ;
F_35 () ;
if ( V_62 < 0 )
goto V_89;
V_62 = F_64 ( V_32 , V_2 , V_72 , V_33 ) ;
if ( V_62 < 0 )
goto V_90;
F_74 () ;
F_75 ( V_32 , & V_77 , 1 ) ;
F_76 () ;
V_17 = F_1 ( V_2 -> V_3 ) ;
V_17 -> V_19 = V_19 ;
V_17 -> V_91 = F_70 ;
V_89:
return V_62 ;
V_90:
F_13 ( V_19 ) ;
goto V_89;
}
static int F_77 ( struct V_70 * V_2 )
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
F_14 ( & V_3 -> V_92 ) ;
if ( V_17 -> V_10 ) {
struct V_93 V_94 = {
. V_32 = F_40 ( V_3 ) ,
. V_33 = V_3 -> V_58 ,
. V_10 = V_17 -> V_10 ,
} ;
F_80 ( & V_95 ,
V_96 , & V_94 ) ;
}
F_13 ( V_17 -> V_19 ) ;
F_19 () ;
if ( F_3 ( V_3 ) ) {
F_81 ( V_34 [ V_3 -> V_58 ] . V_88 == 0 ) ;
if ( -- V_34 [ V_3 -> V_58 ] . V_88 == 0 ) {
struct V_59 * V_97 ;
V_97 = F_56 ( V_34 [ V_3 -> V_58 ] . V_59 ) ;
F_82 ( V_34 [ V_3 -> V_58 ] . V_59 , NULL ) ;
F_83 ( V_97 , V_98 ) ;
V_34 [ V_3 -> V_58 ] . V_19 = NULL ;
V_34 [ V_3 -> V_58 ] . F_70 = NULL ;
V_34 [ V_3 -> V_58 ] . V_4 = 0 ;
V_34 [ V_3 -> V_58 ] . V_88 = 0 ;
}
} else if ( V_17 -> V_69 ) {
F_55 ( V_3 ) ;
}
F_29 () ;
F_9 ( V_17 -> V_25 ) ;
V_17 -> V_25 = NULL ;
F_74 () ;
F_75 ( F_40 ( V_3 ) , & V_77 , - 1 ) ;
F_76 () ;
F_84 ( V_3 ) ;
return 0 ;
}
static int F_85 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_32 * V_32 = F_40 ( V_3 ) ;
struct V_8 * V_9 = & V_34 [ V_3 -> V_58 ] . V_9 ;
struct V_7 * V_35 ;
struct V_2 * V_64 ;
T_4 V_10 = F_86 ( V_28 ) ;
int V_62 ;
static T_4 V_99 = - 4097 ;
V_100:
F_87 () ;
F_19 () ;
V_35 = F_5 ( V_9 , V_10 ) ;
F_38 (osk, head) {
if ( ! F_39 ( F_40 ( V_64 ) , V_32 ) )
continue;
if ( F_1 ( V_64 ) -> V_10 == V_10 ) {
V_10 = V_99 -- ;
if ( V_99 > - 4097 )
V_99 = - 4097 ;
F_29 () ;
goto V_100;
}
}
F_29 () ;
V_62 = F_59 ( V_3 , V_32 , V_10 ) ;
if ( V_62 == - V_63 )
goto V_100;
if ( V_62 == - V_65 )
V_62 = 0 ;
return V_62 ;
}
static inline int F_88 ( const struct V_70 * V_2 , unsigned int V_101 )
{
return ( V_34 [ V_2 -> V_3 -> V_58 ] . V_4 & V_101 ) ||
F_89 ( F_40 ( V_2 -> V_3 ) -> V_102 , V_103 ) ;
}
static void
F_90 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_17 -> V_69 && ! V_69 )
F_63 ( V_3 ) ;
else if ( ! V_17 -> V_69 && V_69 )
F_91 ( V_3 , & V_34 [ V_3 -> V_58 ] . V_104 ) ;
V_17 -> V_69 = V_69 ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_25 ;
unsigned long * V_105 ;
int V_62 = 0 ;
F_19 () ;
V_25 = V_34 [ V_3 -> V_58 ] . V_25 ;
if ( ! V_34 [ V_3 -> V_58 ] . V_88 ) {
V_62 = - V_106 ;
goto V_107;
}
if ( V_17 -> V_60 >= V_25 )
goto V_107;
V_105 = F_93 ( V_17 -> V_25 , F_94 ( V_25 ) , V_39 ) ;
if ( V_105 == NULL ) {
V_62 = - V_66 ;
goto V_107;
}
memset ( ( char * ) V_105 + F_94 ( V_17 -> V_60 ) , 0 ,
F_94 ( V_25 ) - F_94 ( V_17 -> V_60 ) ) ;
V_17 -> V_25 = V_105 ;
V_17 -> V_60 = V_25 ;
V_107:
F_29 () ;
return V_62 ;
}
static int V_91 ( struct V_70 * V_2 , struct V_108 * V_109 ,
int V_110 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_32 * V_32 = F_40 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
int V_62 ;
if ( V_110 < sizeof( struct V_111 ) )
return - V_113 ;
if ( V_112 -> V_114 != V_115 )
return - V_113 ;
if ( V_112 -> V_116 ) {
if ( ! F_88 ( V_2 , V_117 ) )
return - V_118 ;
V_62 = F_92 ( V_3 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_17 -> V_10 ) {
if ( V_112 -> V_119 != V_17 -> V_10 )
return - V_113 ;
} else {
V_62 = V_112 -> V_119 ?
F_59 ( V_3 , V_32 , V_112 -> V_119 ) :
F_85 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
if ( ! V_112 -> V_116 && ( V_17 -> V_25 == NULL || ! ( T_1 ) V_17 -> V_25 [ 0 ] ) )
return 0 ;
F_19 () ;
F_90 ( V_3 , V_17 -> V_69 +
F_95 ( V_112 -> V_116 ) -
F_95 ( V_17 -> V_25 [ 0 ] ) ) ;
V_17 -> V_25 [ 0 ] = ( V_17 -> V_25 [ 0 ] & ~ 0xffffffffUL ) | V_112 -> V_116 ;
F_55 ( V_3 ) ;
F_29 () ;
if ( V_17 -> V_91 && V_17 -> V_25 [ 0 ] ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_17 -> V_60 ; V_46 ++ ) {
if ( F_96 ( V_46 , V_17 -> V_25 ) )
V_17 -> V_91 ( V_46 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_70 * V_2 , struct V_108 * V_109 ,
int V_120 , int V_4 )
{
int V_62 = 0 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
if ( V_120 < sizeof( V_109 -> V_121 ) )
return - V_113 ;
if ( V_109 -> V_121 == V_122 ) {
V_3 -> V_123 = V_124 ;
V_17 -> V_125 = 0 ;
V_17 -> V_126 = 0 ;
return 0 ;
}
if ( V_109 -> V_121 != V_115 )
return - V_113 ;
if ( V_112 -> V_116 && ! F_88 ( V_2 , V_127 ) )
return - V_118 ;
if ( ! V_17 -> V_10 )
V_62 = F_85 ( V_2 ) ;
if ( V_62 == 0 ) {
V_3 -> V_123 = V_128 ;
V_17 -> V_125 = V_112 -> V_119 ;
V_17 -> V_126 = F_98 ( V_112 -> V_116 ) ;
}
return V_62 ;
}
static int F_99 ( struct V_70 * V_2 , struct V_108 * V_109 ,
int * V_110 , int V_129 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_100 ( struct V_111 * , V_112 , V_109 ) ;
V_112 -> V_114 = V_115 ;
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
if ( ! F_102 ( 0 , & F_1 ( V_3 ) -> V_81 ) ) {
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
V_2 = F_37 ( F_40 ( V_136 ) , V_136 -> V_58 , V_10 ) ;
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
struct V_140 * V_140 = F_106 ( V_139 ) ;
struct V_2 * V_2 ;
if ( ! F_107 ( V_140 -> V_141 ) )
return F_104 ( - V_142 ) ;
V_2 = F_108 ( V_140 ) -> V_3 ;
if ( V_2 -> V_143 != V_115 )
return F_104 ( - V_113 ) ;
F_41 ( V_2 ) ;
return V_2 ;
}
int F_109 ( struct V_2 * V_3 , struct V_144 * V_16 ,
long * V_145 , struct V_2 * V_136 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_146 ||
F_96 ( 0 , & V_17 -> V_81 ) ) {
F_22 ( V_27 , V_28 ) ;
if ( ! * V_145 ) {
if ( ! V_136 || F_3 ( V_136 ) )
F_101 ( V_3 ) ;
F_84 ( V_3 ) ;
F_8 ( V_16 ) ;
return - V_147 ;
}
F_27 ( V_148 ) ;
F_110 ( & V_17 -> V_27 , & V_27 ) ;
if ( ( F_18 ( & V_3 -> V_23 ) > V_3 -> V_146 ||
F_96 ( 0 , & V_17 -> V_81 ) ) &&
! F_15 ( V_3 , V_21 ) )
* V_145 = F_111 ( * V_145 ) ;
F_27 ( V_31 ) ;
F_28 ( & V_17 -> V_27 , & V_27 ) ;
F_84 ( V_3 ) ;
if ( F_112 ( V_28 ) ) {
F_8 ( V_16 ) ;
return F_113 ( * V_145 ) ;
}
return 1 ;
}
F_114 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , struct V_144 * V_16 )
{
int V_53 = V_16 -> V_53 ;
F_116 ( & V_3 -> V_20 , V_16 ) ;
V_3 -> V_149 ( V_3 , V_53 ) ;
return V_53 ;
}
int F_117 ( struct V_2 * V_3 , struct V_144 * V_16 )
{
int V_53 = F_115 ( V_3 , V_16 ) ;
F_84 ( V_3 ) ;
return V_53 ;
}
void F_118 ( struct V_2 * V_3 , struct V_144 * V_16 )
{
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
}
static struct V_144 * F_119 ( struct V_144 * V_16 , T_5 V_150 )
{
int V_151 ;
F_120 ( V_16 ) ;
V_151 = V_16 -> V_152 - V_16 -> V_153 ;
if ( V_151 * 2 < V_16 -> V_154 )
return V_16 ;
if ( F_121 ( V_16 ) ) {
struct V_144 * V_155 = F_122 ( V_16 , V_150 ) ;
if ( ! V_155 )
return V_16 ;
F_11 ( V_16 ) ;
V_16 = V_155 ;
}
if ( ! F_123 ( V_16 , 0 , - V_151 , V_150 ) )
V_16 -> V_154 -= V_151 ;
return V_16 ;
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_125 ( & V_3 -> V_20 ) )
F_126 ( 0 , & V_17 -> V_81 ) ;
if ( ! F_96 ( 0 , & V_17 -> V_81 ) )
F_127 ( & V_17 -> V_27 ) ;
}
static int F_128 ( struct V_2 * V_3 , struct V_144 * V_16 ,
struct V_2 * V_136 )
{
int V_156 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_156 = - V_137 ;
if ( V_17 -> V_157 != NULL ) {
V_156 = V_16 -> V_53 ;
F_114 ( V_16 , V_3 ) ;
F_129 ( V_16 ) . V_136 = V_136 ;
V_17 -> V_157 ( V_16 ) ;
F_11 ( V_16 ) ;
} else {
F_8 ( V_16 ) ;
}
F_84 ( V_3 ) ;
return V_156 ;
}
int F_130 ( struct V_2 * V_136 , struct V_144 * V_16 ,
T_1 V_10 , int V_158 )
{
struct V_2 * V_3 ;
int V_62 ;
long V_145 ;
V_16 = F_119 ( V_16 , F_131 () ) ;
V_145 = F_132 ( V_136 , V_158 ) ;
V_100:
V_3 = F_103 ( V_136 , V_10 ) ;
if ( F_133 ( V_3 ) ) {
F_8 ( V_16 ) ;
return F_134 ( V_3 ) ;
}
if ( F_3 ( V_3 ) )
return F_128 ( V_3 , V_16 , V_136 ) ;
if ( F_135 ( V_3 , V_16 ) ) {
V_62 = V_16 -> V_53 ;
F_8 ( V_16 ) ;
F_84 ( V_3 ) ;
return V_62 ;
}
V_62 = F_109 ( V_3 , V_16 , & V_145 , V_136 ) ;
if ( V_62 == 1 )
goto V_100;
if ( V_62 )
return V_62 ;
return F_117 ( V_3 , V_16 ) ;
}
int F_136 ( struct V_2 * V_3 , unsigned int V_6 )
{
int V_159 = 0 ;
struct V_59 * V_59 ;
F_81 ( ! F_3 ( V_3 ) ) ;
F_137 () ;
V_59 = F_138 ( V_34 [ V_3 -> V_58 ] . V_59 ) ;
if ( V_59 && V_6 - 1 < V_34 [ V_3 -> V_58 ] . V_25 )
V_159 = F_96 ( V_6 - 1 , V_59 -> V_61 ) ;
F_139 () ;
return V_159 ;
}
static int F_140 ( struct V_2 * V_3 , struct V_144 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( F_18 ( & V_3 -> V_23 ) <= V_3 -> V_146 &&
! F_96 ( 0 , & V_17 -> V_81 ) ) {
F_114 ( V_16 , V_3 ) ;
F_115 ( V_3 , V_16 ) ;
return F_18 ( & V_3 -> V_23 ) > ( V_3 -> V_146 >> 1 ) ;
}
return - 1 ;
}
static int F_141 ( struct V_2 * V_3 ,
struct V_160 * V_161 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_162 ;
if ( V_161 -> V_163 == V_3 )
goto V_89;
if ( V_17 -> V_10 == V_161 -> V_10 || V_161 -> V_6 - 1 >= V_17 -> V_60 ||
! F_96 ( V_161 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_89;
if ( ! F_39 ( F_40 ( V_3 ) , V_161 -> V_32 ) )
goto V_89;
if ( V_161 -> V_164 ) {
F_101 ( V_3 ) ;
goto V_89;
}
F_41 ( V_3 ) ;
if ( V_161 -> V_165 == NULL ) {
if ( F_121 ( V_161 -> V_16 ) ) {
V_161 -> V_165 = F_122 ( V_161 -> V_16 , V_161 -> V_150 ) ;
} else {
V_161 -> V_165 = F_142 ( V_161 -> V_16 ) ;
F_120 ( V_161 -> V_165 ) ;
}
}
if ( V_161 -> V_165 == NULL ) {
F_101 ( V_3 ) ;
V_161 -> V_164 = 1 ;
if ( V_17 -> V_4 & V_166 )
V_161 -> V_167 = 1 ;
} else if ( V_161 -> V_168 && V_161 -> V_168 ( V_3 , V_161 -> V_165 , V_161 -> V_169 ) ) {
F_8 ( V_161 -> V_165 ) ;
V_161 -> V_165 = NULL ;
} else if ( F_135 ( V_3 , V_161 -> V_165 ) ) {
F_8 ( V_161 -> V_165 ) ;
V_161 -> V_165 = NULL ;
} else if ( ( V_162 = F_140 ( V_3 , V_161 -> V_165 ) ) < 0 ) {
F_101 ( V_3 ) ;
if ( V_17 -> V_4 & V_166 )
V_161 -> V_167 = 1 ;
} else {
V_161 -> V_170 |= V_162 ;
V_161 -> V_171 = 1 ;
V_161 -> V_165 = NULL ;
}
F_84 ( V_3 ) ;
V_89:
return 0 ;
}
int F_143 ( struct V_2 * V_136 , struct V_144 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_150 ,
int (* F_144)( struct V_2 * V_172 , struct V_144 * V_16 , void * V_173 ) ,
void * V_174 )
{
struct V_32 * V_32 = F_40 ( V_136 ) ;
struct V_160 V_175 ;
struct V_2 * V_3 ;
V_16 = F_119 ( V_16 , V_150 ) ;
V_175 . V_163 = V_136 ;
V_175 . V_32 = V_32 ;
V_175 . V_10 = V_10 ;
V_175 . V_6 = V_6 ;
V_175 . V_164 = 0 ;
V_175 . V_167 = 0 ;
V_175 . V_170 = 0 ;
V_175 . V_171 = 0 ;
V_175 . V_150 = V_150 ;
V_175 . V_16 = V_16 ;
V_175 . V_165 = NULL ;
V_175 . V_168 = F_144 ;
V_175 . V_169 = V_174 ;
F_31 () ;
F_58 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_141 ( V_3 , & V_175 ) ;
F_11 ( V_16 ) ;
F_35 () ;
if ( V_175 . V_167 ) {
F_8 ( V_175 . V_165 ) ;
return - V_133 ;
}
F_11 ( V_175 . V_165 ) ;
if ( V_175 . V_171 ) {
if ( V_175 . V_170 && ( V_150 & V_176 ) )
F_145 () ;
return 0 ;
}
return - V_177 ;
}
int F_146 ( struct V_2 * V_136 , struct V_144 * V_16 , T_1 V_10 ,
T_1 V_6 , T_5 V_150 )
{
return F_143 ( V_136 , V_16 , V_10 , V_6 , V_150 ,
NULL , NULL ) ;
}
static int F_147 ( struct V_2 * V_3 , struct V_178 * V_161 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_156 = 0 ;
if ( V_3 == V_161 -> V_163 )
goto V_89;
if ( ! F_39 ( F_40 ( V_3 ) , F_40 ( V_161 -> V_163 ) ) )
goto V_89;
if ( V_17 -> V_10 == V_161 -> V_10 || V_161 -> V_6 - 1 >= V_17 -> V_60 ||
! F_96 ( V_161 -> V_6 - 1 , V_17 -> V_25 ) )
goto V_89;
if ( V_161 -> V_179 == V_133 && V_17 -> V_4 & V_131 ) {
V_156 = 1 ;
goto V_89;
}
V_3 -> V_132 = V_161 -> V_179 ;
V_3 -> V_134 ( V_3 ) ;
V_89:
return V_156 ;
}
int F_148 ( struct V_2 * V_136 , T_1 V_10 , T_1 V_6 , int V_179 )
{
struct V_178 V_175 ;
struct V_2 * V_3 ;
int V_156 = 0 ;
V_175 . V_163 = V_136 ;
V_175 . V_10 = V_10 ;
V_175 . V_6 = V_6 ;
V_175 . V_179 = - V_179 ;
F_32 ( & T_2 ) ;
F_58 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_156 += F_147 ( V_3 , & V_175 ) ;
F_34 ( & T_2 ) ;
return V_156 ;
}
static void F_149 ( struct V_1 * V_17 ,
unsigned int V_6 ,
int V_180 )
{
int V_97 , V_181 = ! ! V_180 , V_69 ;
V_97 = F_96 ( V_6 - 1 , V_17 -> V_25 ) ;
V_69 = V_17 -> V_69 - V_97 + V_181 ;
if ( V_181 )
F_150 ( V_6 - 1 , V_17 -> V_25 ) ;
else
F_151 ( V_6 - 1 , V_17 -> V_25 ) ;
F_90 ( & V_17 -> V_3 , V_69 ) ;
F_55 ( & V_17 -> V_3 ) ;
}
static int F_152 ( struct V_70 * V_2 , int V_182 , int V_183 ,
char T_6 * V_184 , unsigned int V_185 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned int V_162 = 0 ;
int V_62 ;
if ( V_182 != V_186 )
return - V_187 ;
if ( V_185 >= sizeof( int ) &&
F_153 ( V_162 , ( unsigned int T_6 * ) V_184 ) )
return - V_188 ;
switch ( V_183 ) {
case V_189 :
if ( V_162 )
V_17 -> V_4 |= V_190 ;
else
V_17 -> V_4 &= ~ V_190 ;
V_62 = 0 ;
break;
case V_191 :
case V_192 : {
if ( ! F_88 ( V_2 , V_117 ) )
return - V_118 ;
V_62 = F_92 ( V_3 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_162 || V_162 - 1 >= V_17 -> V_60 )
return - V_113 ;
F_19 () ;
F_149 ( V_17 , V_162 ,
V_183 == V_191 ) ;
F_29 () ;
if ( V_17 -> V_91 )
V_17 -> V_91 ( V_162 ) ;
V_62 = 0 ;
break;
}
case V_193 :
if ( V_162 )
V_17 -> V_4 |= V_166 ;
else
V_17 -> V_4 &= ~ V_166 ;
V_62 = 0 ;
break;
case V_194 :
if ( V_162 ) {
V_17 -> V_4 |= V_131 ;
F_126 ( 0 , & V_17 -> V_81 ) ;
F_127 ( & V_17 -> V_27 ) ;
} else {
V_17 -> V_4 &= ~ V_131 ;
}
V_62 = 0 ;
break;
default:
V_62 = - V_187 ;
}
return V_62 ;
}
static int F_154 ( struct V_70 * V_2 , int V_182 , int V_183 ,
char T_6 * V_184 , int T_6 * V_185 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_53 , V_162 , V_62 ;
if ( V_182 != V_186 )
return - V_187 ;
if ( F_153 ( V_53 , V_185 ) )
return - V_188 ;
if ( V_53 < 0 )
return - V_113 ;
switch ( V_183 ) {
case V_189 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_162 = V_17 -> V_4 & V_190 ? 1 : 0 ;
if ( F_155 ( V_53 , V_185 ) ||
F_155 ( V_162 , V_184 ) )
return - V_188 ;
V_62 = 0 ;
break;
case V_193 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_162 = V_17 -> V_4 & V_166 ? 1 : 0 ;
if ( F_155 ( V_53 , V_185 ) ||
F_155 ( V_162 , V_184 ) )
return - V_188 ;
V_62 = 0 ;
break;
case V_194 :
if ( V_53 < sizeof( int ) )
return - V_113 ;
V_53 = sizeof( int ) ;
V_162 = V_17 -> V_4 & V_131 ? 1 : 0 ;
if ( F_155 ( V_53 , V_185 ) ||
F_155 ( V_162 , V_184 ) )
return - V_188 ;
V_62 = 0 ;
break;
default:
V_62 = - V_187 ;
}
return V_62 ;
}
static void F_156 ( struct V_195 * V_196 , struct V_144 * V_16 )
{
struct V_197 V_175 ;
V_175 . V_6 = F_129 ( V_16 ) . V_126 ;
F_157 ( V_196 , V_186 , V_189 , sizeof( V_175 ) , & V_175 ) ;
}
static int F_158 ( struct V_198 * V_198 , struct V_70 * V_2 ,
struct V_195 * V_196 , T_3 V_53 )
{
struct V_199 * V_200 = F_159 ( V_198 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_111 * V_109 = V_196 -> V_201 ;
T_1 V_125 ;
T_1 V_126 ;
struct V_144 * V_16 ;
int V_62 ;
struct V_202 V_203 ;
if ( V_196 -> V_204 & V_205 )
return - V_206 ;
if ( NULL == V_200 -> V_203 )
V_200 -> V_203 = & V_203 ;
V_62 = F_160 ( V_2 , V_196 , V_200 -> V_203 , true ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_196 -> V_207 ) {
V_62 = - V_113 ;
if ( V_109 -> V_114 != V_115 )
goto V_89;
V_125 = V_109 -> V_119 ;
V_126 = F_98 ( V_109 -> V_116 ) ;
V_62 = - V_118 ;
if ( ( V_126 || V_125 ) &&
! F_88 ( V_2 , V_127 ) )
goto V_89;
} else {
V_125 = V_17 -> V_125 ;
V_126 = V_17 -> V_126 ;
}
if ( ! V_17 -> V_10 ) {
V_62 = F_85 ( V_2 ) ;
if ( V_62 )
goto V_89;
}
V_62 = - V_208 ;
if ( V_53 > V_3 -> V_209 - 32 )
goto V_89;
V_62 = - V_133 ;
V_16 = F_161 ( V_53 , V_76 ) ;
if ( V_16 == NULL )
goto V_89;
F_129 ( V_16 ) . V_10 = V_17 -> V_10 ;
F_129 ( V_16 ) . V_126 = V_126 ;
F_129 ( V_16 ) . V_210 = V_200 -> V_203 -> V_210 ;
V_62 = - V_188 ;
if ( F_162 ( F_163 ( V_16 , V_53 ) , V_196 -> V_211 , V_53 ) ) {
F_8 ( V_16 ) ;
goto V_89;
}
V_62 = F_164 ( V_3 , V_16 ) ;
if ( V_62 ) {
F_8 ( V_16 ) ;
goto V_89;
}
if ( V_126 ) {
F_33 ( & V_16 -> V_212 ) ;
F_146 ( V_3 , V_16 , V_125 , V_126 , V_76 ) ;
}
V_62 = F_130 ( V_3 , V_16 , V_125 , V_196 -> V_204 & V_213 ) ;
V_89:
F_165 ( V_200 -> V_203 ) ;
return V_62 ;
}
static int F_166 ( struct V_198 * V_198 , struct V_70 * V_2 ,
struct V_195 * V_196 , T_3 V_53 ,
int V_4 )
{
struct V_199 * V_200 = F_159 ( V_198 ) ;
struct V_202 V_203 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_214 = V_4 & V_213 ;
T_3 V_215 ;
struct V_144 * V_16 , * V_216 ;
int V_62 , V_156 ;
if ( V_4 & V_205 )
return - V_206 ;
V_215 = 0 ;
V_16 = F_167 ( V_3 , V_4 , V_214 , & V_62 ) ;
if ( V_16 == NULL )
goto V_89;
V_216 = V_16 ;
#ifdef F_168
if ( F_53 ( F_169 ( V_16 ) -> V_217 ) ) {
if ( V_4 & V_218 )
V_216 = F_169 ( V_16 ) -> V_217 ;
}
#endif
V_196 -> V_207 = 0 ;
V_215 = V_216 -> V_53 ;
if ( V_53 < V_215 ) {
V_196 -> V_204 |= V_219 ;
V_215 = V_53 ;
}
F_170 ( V_216 ) ;
V_62 = F_171 ( V_216 , 0 , V_196 -> V_211 , V_215 ) ;
if ( V_196 -> V_201 ) {
struct V_111 * V_109 = (struct V_111 * ) V_196 -> V_201 ;
V_109 -> V_114 = V_115 ;
V_109 -> V_130 = 0 ;
V_109 -> V_119 = F_129 ( V_16 ) . V_10 ;
V_109 -> V_116 = F_4 ( F_129 ( V_16 ) . V_126 ) ;
V_196 -> V_207 = sizeof( * V_109 ) ;
}
if ( V_17 -> V_4 & V_190 )
F_156 ( V_196 , V_16 ) ;
if ( NULL == V_200 -> V_203 ) {
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_200 -> V_203 = & V_203 ;
}
V_200 -> V_203 -> V_210 = * F_172 ( V_16 ) ;
if ( V_4 & V_219 )
V_215 = V_216 -> V_53 ;
F_173 ( V_3 , V_16 ) ;
if ( V_17 -> V_15 && F_18 ( & V_3 -> V_23 ) <= V_3 -> V_146 / 2 ) {
V_156 = F_174 ( V_3 ) ;
if ( V_156 ) {
V_3 -> V_132 = V_156 ;
V_3 -> V_134 ( V_3 ) ;
}
}
F_175 ( V_2 , V_196 , V_200 -> V_203 , V_4 ) ;
V_89:
F_124 ( V_3 ) ;
return V_62 ? : V_215 ;
}
static void F_176 ( struct V_2 * V_3 , int V_53 )
{
F_177 () ;
}
struct V_2 *
F_178 ( struct V_32 * V_32 , int V_220 , struct V_19 * V_19 ,
struct V_221 * V_222 )
{
struct V_70 * V_2 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_59 * V_59 = NULL ;
struct V_71 * V_72 = V_222 ? V_222 -> V_72 : NULL ;
unsigned int V_25 ;
F_81 ( ! V_34 ) ;
if ( V_220 < 0 || V_220 >= V_86 )
return NULL ;
if ( F_179 ( V_75 , V_84 , V_220 , & V_2 ) )
return NULL ;
if ( F_64 ( & V_223 , V_2 , V_72 , V_220 ) < 0 )
goto V_224;
V_3 = V_2 -> V_3 ;
F_180 ( V_3 , V_32 ) ;
if ( ! V_222 || V_222 -> V_25 < 32 )
V_25 = 32 ;
else
V_25 = V_222 -> V_25 ;
V_59 = F_43 ( sizeof( * V_59 ) + F_94 ( V_25 ) , V_76 ) ;
if ( ! V_59 )
goto V_225;
V_3 -> V_149 = F_176 ;
if ( V_222 && V_222 -> V_226 )
F_1 ( V_3 ) -> V_157 = V_222 -> V_226 ;
if ( F_59 ( V_3 , V_32 , 0 ) )
goto V_225;
V_17 = F_1 ( V_3 ) ;
V_17 -> V_4 |= V_5 ;
F_19 () ;
if ( ! V_34 [ V_220 ] . V_88 ) {
V_34 [ V_220 ] . V_25 = V_25 ;
F_181 ( V_34 [ V_220 ] . V_59 , V_59 ) ;
V_34 [ V_220 ] . V_72 = V_72 ;
V_34 [ V_220 ] . V_19 = V_19 ;
if ( V_222 ) {
V_34 [ V_220 ] . F_70 = V_222 -> F_70 ;
V_34 [ V_220 ] . V_4 = V_222 -> V_4 ;
}
V_34 [ V_220 ] . V_88 = 1 ;
} else {
F_9 ( V_59 ) ;
V_34 [ V_220 ] . V_88 ++ ;
}
F_29 () ;
return V_3 ;
V_225:
F_9 ( V_59 ) ;
F_182 ( V_3 ) ;
return NULL ;
V_224:
F_183 ( V_2 ) ;
return NULL ;
}
void
F_182 ( struct V_2 * V_3 )
{
F_184 ( V_3 ) ;
}
int F_185 ( struct V_2 * V_3 , unsigned int V_25 )
{
struct V_59 * V_181 , * V_97 ;
struct V_56 * V_57 = & V_34 [ V_3 -> V_58 ] ;
if ( V_25 < 32 )
V_25 = 32 ;
if ( F_94 ( V_57 -> V_25 ) < F_94 ( V_25 ) ) {
V_181 = F_43 ( sizeof( * V_181 ) + F_94 ( V_25 ) , V_39 ) ;
if ( ! V_181 )
return - V_66 ;
V_97 = F_56 ( V_57 -> V_59 ) ;
memcpy ( V_181 -> V_61 , V_97 -> V_61 , F_94 ( V_57 -> V_25 ) ) ;
F_181 ( V_57 -> V_59 , V_181 ) ;
F_83 ( V_97 , V_98 ) ;
}
V_57 -> V_25 = V_25 ;
return 0 ;
}
int F_186 ( struct V_2 * V_3 , unsigned int V_25 )
{
int V_62 ;
F_19 () ;
V_62 = F_185 ( V_3 , V_25 ) ;
F_29 () ;
return V_62 ;
}
void F_187 ( struct V_2 * V_227 , unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_56 * V_57 = & V_34 [ V_227 -> V_58 ] ;
F_58 (sk, &tbl->mc_list)
F_149 ( F_1 ( V_3 ) , V_6 , 0 ) ;
}
void F_188 ( struct V_2 * V_227 , unsigned int V_6 )
{
F_19 () ;
F_187 ( V_227 , V_6 ) ;
F_29 () ;
}
struct V_228 *
F_189 ( struct V_144 * V_16 , T_1 V_10 , T_1 V_229 , int type , int V_53 , int V_4 )
{
struct V_228 * V_230 ;
int V_37 = F_190 ( V_53 ) ;
V_230 = (struct V_228 * ) F_163 ( V_16 , F_191 ( V_37 ) ) ;
V_230 -> V_231 = type ;
V_230 -> V_232 = V_37 ;
V_230 -> V_233 = V_4 ;
V_230 -> V_234 = V_10 ;
V_230 -> V_235 = V_229 ;
if ( ! F_192 ( V_37 ) || F_191 ( V_37 ) - V_37 != 0 )
memset ( F_193 ( V_230 ) + V_53 , 0 , F_191 ( V_37 ) - V_37 ) ;
return V_230 ;
}
static int F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
struct V_144 * V_16 = NULL ;
struct V_228 * V_230 ;
int V_53 , V_62 = - V_133 ;
int V_236 ;
F_194 ( V_17 -> V_72 ) ;
V_15 = V_17 -> V_15 ;
if ( V_15 == NULL ) {
V_62 = - V_113 ;
goto V_237;
}
V_236 = F_195 ( int , V_15 -> V_238 , V_239 ) ;
V_16 = F_196 ( V_3 , V_236 , 0 , V_76 ) ;
if ( ! V_16 )
goto V_237;
V_53 = V_15 -> V_240 ( V_16 , V_15 ) ;
if ( V_53 > 0 ) {
F_197 ( V_17 -> V_72 ) ;
if ( F_135 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_115 ( V_3 , V_16 ) ;
return 0 ;
}
V_230 = F_198 ( V_16 , V_15 , V_241 , sizeof( V_53 ) , V_242 ) ;
if ( ! V_230 )
goto V_237;
F_199 ( V_15 , V_230 ) ;
memcpy ( F_200 ( V_230 ) , & V_53 , sizeof( V_53 ) ) ;
if ( F_135 ( V_3 , V_16 ) )
F_8 ( V_16 ) ;
else
F_115 ( V_3 , V_16 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 ) ;
V_17 -> V_15 = NULL ;
F_197 ( V_17 -> V_72 ) ;
F_13 ( V_15 -> V_19 ) ;
F_10 ( V_15 ) ;
return 0 ;
V_237:
F_197 ( V_17 -> V_72 ) ;
F_8 ( V_16 ) ;
return V_62 ;
}
int F_201 ( struct V_2 * V_136 , struct V_144 * V_16 ,
const struct V_228 * V_230 ,
struct V_243 * V_244 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
int V_156 ;
V_15 = F_43 ( sizeof( * V_15 ) , V_76 ) ;
if ( V_15 == NULL )
return - V_133 ;
V_15 -> V_240 = V_244 -> V_240 ;
V_15 -> V_18 = V_244 -> V_18 ;
V_15 -> V_230 = V_230 ;
V_15 -> V_173 = V_244 -> V_173 ;
V_15 -> V_19 = V_244 -> V_19 ;
V_15 -> V_238 = V_244 -> V_238 ;
F_33 ( & V_16 -> V_212 ) ;
V_15 -> V_16 = V_16 ;
V_3 = F_37 ( F_40 ( V_136 ) , V_136 -> V_58 , F_129 ( V_16 ) . V_10 ) ;
if ( V_3 == NULL ) {
F_7 ( V_15 ) ;
return - V_137 ;
}
V_17 = F_1 ( V_3 ) ;
F_194 ( V_17 -> V_72 ) ;
if ( V_17 -> V_15 ) {
F_197 ( V_17 -> V_72 ) ;
F_7 ( V_15 ) ;
V_156 = - V_65 ;
goto V_89;
}
if ( ! F_73 ( V_15 -> V_19 ) ) {
F_197 ( V_17 -> V_72 ) ;
F_7 ( V_15 ) ;
V_156 = - V_87 ;
goto V_89;
}
V_17 -> V_15 = V_15 ;
F_197 ( V_17 -> V_72 ) ;
V_156 = F_174 ( V_3 ) ;
V_89:
F_84 ( V_3 ) ;
if ( V_156 )
return V_156 ;
return - V_245 ;
}
void F_202 ( struct V_144 * V_246 , struct V_228 * V_230 , int V_62 )
{
struct V_144 * V_16 ;
struct V_228 * V_247 ;
struct V_248 * V_249 ;
T_3 V_250 = sizeof( * V_249 ) ;
if ( V_62 )
V_250 += V_232 ( V_230 ) ;
V_16 = F_203 ( V_250 , V_76 ) ;
if ( ! V_16 ) {
struct V_2 * V_3 ;
V_3 = F_37 ( F_40 ( V_246 -> V_3 ) ,
V_246 -> V_3 -> V_58 ,
F_129 ( V_246 ) . V_10 ) ;
if ( V_3 ) {
V_3 -> V_132 = V_133 ;
V_3 -> V_134 ( V_3 ) ;
F_84 ( V_3 ) ;
}
return;
}
V_247 = F_189 ( V_16 , F_129 ( V_246 ) . V_10 , V_230 -> V_235 ,
V_251 , V_250 , 0 ) ;
V_249 = F_200 ( V_247 ) ;
V_249 -> error = V_62 ;
memcpy ( & V_249 -> V_196 , V_230 , V_62 ? V_230 -> V_232 : sizeof( * V_230 ) ) ;
F_130 ( V_246 -> V_3 , V_16 , F_129 ( V_246 ) . V_10 , V_213 ) ;
}
int F_204 ( struct V_144 * V_16 , int (* V_15)( struct V_144 * ,
struct V_228 * ) )
{
struct V_228 * V_230 ;
int V_62 ;
while ( V_16 -> V_53 >= F_205 ( 0 ) ) {
int V_252 ;
V_230 = F_206 ( V_16 ) ;
V_62 = 0 ;
if ( V_230 -> V_232 < V_253 || V_16 -> V_53 < V_230 -> V_232 )
return 0 ;
if ( ! ( V_230 -> V_233 & V_254 ) )
goto V_255;
if ( V_230 -> V_231 < V_256 )
goto V_255;
V_62 = V_15 ( V_16 , V_230 ) ;
if ( V_62 == - V_245 )
goto V_257;
V_255:
if ( V_230 -> V_233 & V_258 || V_62 )
F_202 ( V_16 , V_230 , V_62 ) ;
V_257:
V_252 = F_191 ( V_230 -> V_232 ) ;
if ( V_252 > V_16 -> V_53 )
V_252 = V_16 -> V_53 ;
F_207 ( V_16 , V_252 ) ;
}
return 0 ;
}
int F_208 ( struct V_2 * V_3 , struct V_144 * V_16 , T_1 V_10 ,
unsigned int V_6 , int V_259 , T_5 V_4 )
{
int V_62 = 0 ;
if ( V_6 ) {
int V_260 = 0 ;
if ( V_259 ) {
F_33 ( & V_16 -> V_212 ) ;
V_260 = V_10 ;
}
V_62 = F_209 ( V_3 , V_16 , V_260 , V_6 , V_4 ) ;
}
if ( V_259 ) {
int V_261 ;
V_261 = F_210 ( V_3 , V_16 , V_10 ) ;
if ( ! V_62 || V_62 == - V_177 )
V_62 = V_261 ;
}
return V_62 ;
}
static struct V_2 * F_211 ( struct V_262 * V_229 , T_7 V_263 )
{
struct V_264 * V_265 = V_229 -> V_266 ;
int V_46 , V_267 ;
struct V_2 * V_268 ;
T_7 V_269 = 0 ;
for ( V_46 = 0 ; V_46 < V_86 ; V_46 ++ ) {
struct V_8 * V_9 = & V_34 [ V_46 ] . V_9 ;
for ( V_267 = 0 ; V_267 <= V_9 -> V_13 ; V_267 ++ ) {
F_38 (s, &hash->table[j]) {
if ( F_40 ( V_268 ) != F_212 ( V_229 ) )
continue;
if ( V_269 == V_263 ) {
V_265 -> V_270 = V_46 ;
V_265 -> V_271 = V_267 ;
return V_268 ;
}
++ V_269 ;
}
}
}
return NULL ;
}
static void * F_213 ( struct V_262 * V_229 , T_7 * V_263 )
__acquires( T_2 )
{
F_32 ( & T_2 ) ;
return * V_263 ? F_211 ( V_229 , * V_263 - 1 ) : V_272 ;
}
static void * F_214 ( struct V_262 * V_229 , void * V_273 , T_7 * V_263 )
{
struct V_2 * V_268 ;
struct V_264 * V_265 ;
int V_46 , V_267 ;
++ * V_263 ;
if ( V_273 == V_272 )
return F_211 ( V_229 , 0 ) ;
V_265 = V_229 -> V_266 ;
V_268 = V_273 ;
do {
V_268 = F_215 ( V_268 ) ;
} while ( V_268 && F_40 ( V_268 ) != F_212 ( V_229 ) );
if ( V_268 )
return V_268 ;
V_46 = V_265 -> V_270 ;
V_267 = V_265 -> V_271 + 1 ;
do {
struct V_8 * V_9 = & V_34 [ V_46 ] . V_9 ;
for (; V_267 <= V_9 -> V_13 ; V_267 ++ ) {
V_268 = F_216 ( & V_9 -> V_11 [ V_267 ] ) ;
while ( V_268 && F_40 ( V_268 ) != F_212 ( V_229 ) )
V_268 = F_215 ( V_268 ) ;
if ( V_268 ) {
V_265 -> V_270 = V_46 ;
V_265 -> V_271 = V_267 ;
return V_268 ;
}
}
V_267 = 0 ;
} while ( ++ V_46 < V_86 );
return NULL ;
}
static void F_217 ( struct V_262 * V_229 , void * V_273 )
__releases( T_2 )
{
F_34 ( & T_2 ) ;
}
static int F_218 ( struct V_262 * V_229 , void * V_273 )
{
if ( V_273 == V_272 ) {
F_219 ( V_229 ,
L_3
L_4 ) ;
} else {
struct V_2 * V_268 = V_273 ;
struct V_1 * V_17 = F_1 ( V_268 ) ;
F_220 ( V_229 , L_5 ,
V_268 ,
V_268 -> V_58 ,
V_17 -> V_10 ,
V_17 -> V_25 ? ( T_1 ) V_17 -> V_25 [ 0 ] : 0 ,
F_221 ( V_268 ) ,
F_222 ( V_268 ) ,
V_17 -> V_15 ,
F_18 ( & V_268 -> V_274 ) ,
F_18 ( & V_268 -> V_135 ) ,
F_223 ( V_268 )
) ;
}
return 0 ;
}
static int F_224 ( struct V_140 * V_140 , struct V_138 * V_138 )
{
return F_225 ( V_140 , V_138 , & V_275 ,
sizeof( struct V_264 ) ) ;
}
int F_226 ( struct V_276 * V_277 )
{
return F_227 ( & V_95 , V_277 ) ;
}
int F_228 ( struct V_276 * V_277 )
{
return F_229 ( & V_95 , V_277 ) ;
}
static int T_8 F_230 ( struct V_32 * V_32 )
{
#ifdef F_231
if ( ! F_232 ( L_6 , 0 , V_32 -> V_278 , & V_279 ) )
return - V_66 ;
#endif
return 0 ;
}
static void T_9 F_233 ( struct V_32 * V_32 )
{
#ifdef F_231
F_234 ( L_6 , V_32 -> V_278 ) ;
#endif
}
static void T_10 F_235 ( void )
{
struct V_59 * V_59 ;
int V_25 = 32 ;
V_59 = F_43 ( sizeof( * V_59 ) + F_94 ( V_25 ) , V_76 ) ;
if ( ! V_59 )
F_236 ( L_7 ) ;
F_19 () ;
V_34 [ V_280 ] . V_25 = V_25 ;
F_181 ( V_34 [ V_280 ] . V_59 , V_59 ) ;
V_34 [ V_280 ] . V_19 = V_281 ;
V_34 [ V_280 ] . V_88 = 1 ;
V_34 [ V_280 ] . V_4 = V_127 ;
F_29 () ;
}
static int T_10 F_237 ( void )
{
int V_46 ;
unsigned long V_282 ;
unsigned int V_283 ;
int V_62 = F_238 ( & V_77 , 0 ) ;
if ( V_62 != 0 )
goto V_89;
F_239 ( sizeof( struct V_284 ) > F_240 ( struct V_144 , V_15 ) ) ;
V_34 = F_241 ( V_86 , sizeof( * V_34 ) , V_76 ) ;
if ( ! V_34 )
goto F_236;
if ( V_285 >= ( 128 * 1024 ) )
V_282 = V_285 >> ( 21 - V_286 ) ;
else
V_282 = V_285 >> ( 23 - V_286 ) ;
V_283 = F_242 ( V_282 ) - 1 + V_286 ;
V_282 = ( 1UL << V_283 ) / sizeof( struct V_7 ) ;
V_283 = F_242 ( F_243 ( V_282 , ( unsigned long ) V_68 ) ) - 1 ;
for ( V_46 = 0 ; V_46 < V_86 ; V_46 ++ ) {
struct V_8 * V_9 = & V_34 [ V_46 ] . V_9 ;
V_9 -> V_11 = F_42 ( 1 * sizeof( * V_9 -> V_11 ) ) ;
if ( ! V_9 -> V_11 ) {
while ( V_46 -- > 0 )
F_46 ( V_34 [ V_46 ] . V_9 . V_11 ,
1 * sizeof( * V_9 -> V_11 ) ) ;
F_9 ( V_34 ) ;
goto F_236;
}
V_9 -> V_47 = V_283 ;
V_9 -> V_43 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_50 = V_51 ;
}
F_235 () ;
F_244 ( & V_287 ) ;
F_245 ( & V_288 ) ;
F_246 () ;
V_89:
return V_62 ;
F_236:
F_236 ( L_8 ) ;
}
