static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( F_3 ( V_2 ) ^ V_3 , F_4 ( V_4 ) ) ;
}
static struct V_5 * F_5 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_8 )
{
struct V_5 * V_9 ;
F_6 (timer, head, t_hash) {
if ( ( V_9 -> V_10 == V_2 ) && ( V_9 -> V_11 == V_8 ) )
return V_9 ;
}
return NULL ;
}
static struct V_5 * F_7 ( T_1 V_8 )
{
struct V_1 * V_2 = V_12 -> signal ;
struct V_6 * V_7 = & V_4 [ F_1 ( V_2 , V_8 ) ] ;
return F_5 ( V_7 , V_2 , V_8 ) ;
}
static int F_8 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = V_12 -> signal ;
int V_13 = V_2 -> V_14 ;
struct V_6 * V_7 ;
int V_15 = - V_16 ;
do {
F_9 ( & V_17 ) ;
V_7 = & V_4 [ F_1 ( V_2 , V_2 -> V_14 ) ] ;
if ( ! F_5 ( V_7 , V_2 , V_2 -> V_14 ) ) {
F_10 ( & V_9 -> V_18 , V_7 ) ;
V_15 = V_2 -> V_14 ;
}
if ( ++ V_2 -> V_14 < 0 )
V_2 -> V_14 = 0 ;
if ( ( V_2 -> V_14 == V_13 ) && ( V_15 == - V_16 ) )
V_15 = - V_19 ;
F_11 ( & V_17 ) ;
} while ( V_15 == - V_16 );
return V_15 ;
}
static inline void F_12 ( struct V_5 * V_20 , unsigned long V_21 )
{
F_13 ( & V_20 -> V_22 , V_21 ) ;
}
static int F_14 ( T_2 V_23 , struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
return 0 ;
}
static int F_16 ( const T_2 V_23 ,
const struct V_24 * V_25 )
{
return F_17 ( V_25 , NULL ) ;
}
static int F_18 ( const T_2 V_23 ,
struct V_26 * V_27 )
{
return F_19 ( V_27 ) ;
}
static int F_20 ( T_2 V_23 , struct V_24 * V_25 )
{
F_21 ( V_25 ) ;
return 0 ;
}
static int F_22 ( T_2 V_23 , struct V_24 * V_25 )
{
F_23 ( V_25 ) ;
return 0 ;
}
static int F_24 ( T_2 V_23 , struct V_24 * V_25 )
{
* V_25 = F_25 () ;
return 0 ;
}
static int F_26 ( T_2 V_23 ,
struct V_24 * V_25 )
{
* V_25 = F_27 () ;
return 0 ;
}
static int F_28 ( const T_2 V_23 , struct V_24 * V_25 )
{
* V_25 = F_29 ( V_28 ) ;
return 0 ;
}
static int F_30 ( const T_2 V_23 , struct V_24 * V_25 )
{
F_31 ( V_25 ) ;
return 0 ;
}
static int F_32 ( T_2 V_23 , struct V_24 * V_25 )
{
F_33 ( V_25 ) ;
return 0 ;
}
static int F_34 ( T_2 V_23 , struct V_24 * V_25 )
{
V_25 -> V_29 = 0 ;
V_25 -> V_30 = V_31 ;
return 0 ;
}
static T_3 int F_35 ( void )
{
struct V_32 V_33 = {
. V_34 = F_34 ,
. V_35 = F_14 ,
. V_36 = F_16 ,
. V_37 = F_18 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = V_49 ,
} ;
struct V_32 V_50 = {
. V_34 = F_34 ,
. V_35 = F_20 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = V_49 ,
} ;
struct V_32 V_51 = {
. V_34 = F_34 ,
. V_35 = F_22 ,
} ;
struct V_32 V_52 = {
. V_34 = F_28 ,
. V_35 = F_24 ,
} ;
struct V_32 V_53 = {
. V_34 = F_28 ,
. V_35 = F_26 ,
} ;
struct V_32 V_54 = {
. V_34 = F_34 ,
. V_35 = F_32 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = V_49 ,
} ;
struct V_32 V_55 = {
. V_34 = F_34 ,
. V_35 = F_30 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = V_49 ,
} ;
F_36 ( V_56 , & V_33 ) ;
F_36 ( V_57 , & V_50 ) ;
F_36 ( V_58 , & V_51 ) ;
F_36 ( V_59 , & V_52 ) ;
F_36 ( V_60 , & V_53 ) ;
F_36 ( V_61 , & V_55 ) ;
F_36 ( V_62 , & V_54 ) ;
V_63 = F_37 ( L_1 ,
sizeof ( struct V_5 ) , 0 , V_64 ,
NULL ) ;
return 0 ;
}
static void F_38 ( struct V_5 * V_20 )
{
struct V_65 * V_9 = & V_20 -> V_66 . V_67 . V_9 ;
if ( V_20 -> V_66 . V_67 . V_68 . V_69 == 0 )
return;
V_20 -> V_70 += ( unsigned int ) F_39 ( V_9 ,
V_9 -> V_71 -> V_72 () ,
V_20 -> V_66 . V_67 . V_68 ) ;
V_20 -> V_73 = V_20 -> V_70 ;
V_20 -> V_70 = - 1 ;
++ V_20 -> V_74 ;
F_40 ( V_9 ) ;
}
void F_41 ( struct V_75 * V_76 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
V_20 = F_42 ( V_76 -> V_77 , & V_21 ) ;
if ( V_20 && V_20 -> V_74 == V_76 -> V_78 ) {
if ( V_20 -> V_79 < 0 )
F_43 ( V_20 ) ;
else
F_38 ( V_20 ) ;
V_76 -> V_80 += V_20 -> V_73 ;
}
if ( V_20 )
F_12 ( V_20 , V_21 ) ;
}
int F_44 ( struct V_5 * V_20 , int V_81 )
{
struct V_82 * V_83 ;
int V_84 , V_15 = - 1 ;
V_20 -> V_85 -> V_76 . V_78 = V_81 ;
F_45 () ;
V_83 = F_46 ( V_20 -> V_86 , V_87 ) ;
if ( V_83 ) {
V_84 = ! ( V_20 -> V_88 & V_89 ) ;
V_15 = F_47 ( V_20 -> V_85 , V_83 , V_84 ) ;
}
F_48 () ;
return V_15 > 0 ;
}
static enum F_40 F_49 ( struct V_65 * V_9 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
int V_81 = 0 ;
enum F_40 V_15 = V_90 ;
V_20 = F_50 ( V_9 , struct V_5 , V_66 . V_67 . V_9 ) ;
F_51 ( & V_20 -> V_22 , V_21 ) ;
if ( V_20 -> V_66 . V_67 . V_68 . V_69 != 0 )
V_81 = ++ V_20 -> V_74 ;
if ( F_44 ( V_20 , V_81 ) ) {
if ( V_20 -> V_66 . V_67 . V_68 . V_69 != 0 ) {
T_4 V_91 = F_52 ( V_9 ) ;
#ifdef F_53
{
T_4 V_92 = F_54 ( 0 , V_93 / V_94 ) ;
if ( V_20 -> V_66 . V_67 . V_68 . V_69 < V_92 . V_69 )
V_91 = F_55 ( V_91 , V_92 ) ;
}
#endif
V_20 -> V_70 += ( unsigned int )
F_39 ( V_9 , V_91 ,
V_20 -> V_66 . V_67 . V_68 ) ;
V_15 = V_95 ;
++ V_20 -> V_74 ;
}
}
F_12 ( V_20 , V_21 ) ;
return V_15 ;
}
static struct V_96 * F_56 ( T_5 * V_97 )
{
struct V_82 * V_98 = V_12 -> V_99 ;
if ( ( V_97 -> V_100 & V_89 ) &&
( ! ( V_98 = F_57 ( V_97 -> V_101 ) ) ||
! F_58 ( V_98 , V_12 ) ||
( V_97 -> V_100 & ~ V_89 ) != V_102 ) )
return NULL ;
if ( ( ( V_97 -> V_100 & ~ V_89 ) != V_103 ) &&
( ( V_97 -> V_104 <= 0 ) || ( V_97 -> V_104 > V_105 ) ) )
return NULL ;
return F_59 ( V_98 ) ;
}
void F_36 ( const T_2 V_106 ,
struct V_32 * V_107 )
{
if ( ( unsigned ) V_106 >= V_108 ) {
F_60 ( V_109 L_2 ,
V_106 ) ;
return;
}
if ( ! V_107 -> V_35 ) {
F_60 ( V_109 L_3 ,
V_106 ) ;
return;
}
if ( ! V_107 -> V_34 ) {
F_60 ( V_109 L_4 ,
V_106 ) ;
return;
}
V_110 [ V_106 ] = * V_107 ;
}
static struct V_5 * F_61 ( void )
{
struct V_5 * V_111 ;
V_111 = F_62 ( V_63 , V_112 ) ;
if ( ! V_111 )
return V_111 ;
if ( F_63 ( ! ( V_111 -> V_85 = F_64 () ) ) ) {
F_65 ( V_63 , V_111 ) ;
return NULL ;
}
memset ( & V_111 -> V_85 -> V_76 , 0 , sizeof( V_113 ) ) ;
return V_111 ;
}
static void F_66 ( struct V_114 * V_7 )
{
struct V_5 * V_111 = F_50 ( V_7 , struct V_5 , V_66 . V_115 ) ;
F_65 ( V_63 , V_111 ) ;
}
static void F_67 ( struct V_5 * V_111 , int V_116 )
{
if ( V_116 ) {
unsigned long V_21 ;
F_51 ( & V_17 , V_21 ) ;
F_68 ( & V_111 -> V_18 ) ;
F_13 ( & V_17 , V_21 ) ;
}
F_69 ( V_111 -> V_86 ) ;
F_70 ( V_111 -> V_85 ) ;
F_71 ( & V_111 -> V_66 . V_115 , F_66 ) ;
}
static struct V_32 * F_72 ( const T_2 V_8 )
{
if ( V_8 < 0 )
return ( V_8 & V_117 ) == V_118 ?
& V_119 : & V_120 ;
if ( V_8 >= V_108 || ! V_110 [ V_8 ] . V_34 )
return NULL ;
return & V_110 [ V_8 ] ;
}
static int V_43 ( struct V_5 * V_121 )
{
F_73 ( & V_121 -> V_66 . V_67 . V_9 , V_121 -> V_79 , 0 ) ;
return 0 ;
}
static struct V_5 * F_74 ( T_1 V_122 , unsigned long * V_21 )
{
struct V_5 * V_20 ;
if ( ( unsigned long long ) V_122 > V_123 )
return NULL ;
F_45 () ;
V_20 = F_7 ( V_122 ) ;
if ( V_20 ) {
F_51 ( & V_20 -> V_22 , * V_21 ) ;
if ( V_20 -> V_10 == V_12 -> signal ) {
F_48 () ;
return V_20 ;
}
F_13 ( & V_20 -> V_22 , * V_21 ) ;
}
F_48 () ;
return NULL ;
}
static void
V_47 ( struct V_5 * V_20 , struct V_124 * V_125 )
{
T_4 V_91 , V_126 , V_127 ;
struct V_65 * V_9 = & V_20 -> V_66 . V_67 . V_9 ;
memset ( V_125 , 0 , sizeof( struct V_124 ) ) ;
V_127 = V_20 -> V_66 . V_67 . V_68 ;
if ( V_127 . V_69 )
V_125 -> V_128 = F_29 ( V_127 ) ;
else if ( ! F_75 ( V_9 ) &&
( V_20 -> V_88 & ~ V_89 ) != V_103 )
return;
V_91 = V_9 -> V_71 -> V_72 () ;
if ( V_127 . V_69 && ( V_20 -> V_74 & V_129 ||
( V_20 -> V_88 & ~ V_89 ) == V_103 ) )
V_20 -> V_70 += ( unsigned int ) F_39 ( V_9 , V_91 , V_127 ) ;
V_126 = F_76 ( F_77 ( V_9 ) , V_91 ) ;
if ( V_126 . V_69 <= 0 ) {
if ( ( V_20 -> V_88 & ~ V_89 ) != V_103 )
V_125 -> V_130 . V_30 = 1 ;
} else
V_125 -> V_130 = F_29 ( V_126 ) ;
}
static int
V_45 ( struct V_5 * V_20 , int V_21 ,
struct V_124 * V_131 , struct V_124 * V_132 )
{
struct V_65 * V_9 = & V_20 -> V_66 . V_67 . V_9 ;
enum V_133 V_134 ;
if ( V_132 )
V_47 ( V_20 , V_132 ) ;
V_20 -> V_66 . V_67 . V_68 . V_69 = 0 ;
if ( F_78 ( V_9 ) < 0 )
return V_135 ;
V_20 -> V_74 = ( V_20 -> V_74 + 2 ) &
~ V_129 ;
V_20 -> V_73 = 0 ;
if ( ! V_131 -> V_130 . V_29 && ! V_131 -> V_130 . V_30 )
return 0 ;
V_134 = V_21 & V_136 ? V_137 : V_138 ;
F_73 ( & V_20 -> V_66 . V_67 . V_9 , V_20 -> V_79 , V_134 ) ;
V_20 -> V_66 . V_67 . V_9 . V_139 = F_49 ;
F_79 ( V_9 , F_80 ( V_131 -> V_130 ) ) ;
V_20 -> V_66 . V_67 . V_68 = F_80 ( V_131 -> V_128 ) ;
if ( ( ( V_20 -> V_88 & ~ V_89 ) == V_103 ) ) {
if ( V_134 == V_138 ) {
F_81 ( V_9 , V_9 -> V_71 -> V_72 () ) ;
}
return 0 ;
}
F_82 ( V_9 , V_134 ) ;
return 0 ;
}
static int V_49 ( struct V_5 * V_9 )
{
V_9 -> V_66 . V_67 . V_68 . V_69 = 0 ;
if ( F_78 ( & V_9 -> V_66 . V_67 . V_9 ) < 0 )
return V_135 ;
return 0 ;
}
static inline int F_83 ( struct V_5 * V_9 )
{
struct V_32 * V_140 = F_72 ( V_9 -> V_79 ) ;
if ( F_84 ( ! V_140 || ! V_140 -> V_48 ) )
return - V_141 ;
return V_140 -> V_48 ( V_9 ) ;
}
static void F_85 ( struct V_5 * V_9 )
{
unsigned long V_21 ;
V_142:
F_51 ( & V_9 -> V_22 , V_21 ) ;
if ( F_83 ( V_9 ) == V_135 ) {
F_12 ( V_9 , V_21 ) ;
goto V_142;
}
F_86 ( & V_9 -> V_143 ) ;
V_9 -> V_10 = NULL ;
F_12 ( V_9 , V_21 ) ;
F_67 ( V_9 , V_144 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_111 ;
while ( ! F_88 ( & V_2 -> V_145 ) ) {
V_111 = F_89 ( V_2 -> V_145 . V_146 , struct V_5 , V_143 ) ;
F_85 ( V_111 ) ;
}
}
static int V_39 ( const T_2 V_23 , int V_21 ,
struct V_24 * V_147 , struct V_24 T_6 * V_148 )
{
return F_90 ( V_147 , V_148 , V_21 & V_136 ?
V_137 : V_138 ,
V_23 ) ;
}
long F_91 ( struct V_149 * V_149 )
{
T_2 V_23 = V_149 -> V_150 . V_151 ;
struct V_32 * V_140 = F_72 ( V_23 ) ;
if ( F_84 ( ! V_140 || ! V_140 -> V_40 ) )
return - V_141 ;
return V_140 -> V_40 ( V_149 ) ;
}
