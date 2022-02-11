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
static T_3 int F_34 ( void )
{
struct V_29 V_30 = {
. V_31 = V_32 ,
. V_33 = F_14 ,
. V_34 = F_16 ,
. V_35 = F_18 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
} ;
struct V_29 V_48 = {
. V_31 = V_32 ,
. V_33 = F_20 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
} ;
struct V_29 V_49 = {
. V_31 = V_32 ,
. V_33 = F_22 ,
} ;
struct V_29 V_50 = {
. V_31 = F_28 ,
. V_33 = F_24 ,
} ;
struct V_29 V_51 = {
. V_31 = F_28 ,
. V_33 = F_26 ,
} ;
struct V_29 V_52 = {
. V_31 = V_32 ,
. V_33 = F_32 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
} ;
struct V_29 V_53 = {
. V_31 = V_32 ,
. V_33 = F_30 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
} ;
F_35 ( V_54 , & V_30 ) ;
F_35 ( V_55 , & V_48 ) ;
F_35 ( V_56 , & V_49 ) ;
F_35 ( V_57 , & V_50 ) ;
F_35 ( V_58 , & V_51 ) ;
F_35 ( V_59 , & V_53 ) ;
F_35 ( V_60 , & V_52 ) ;
V_61 = F_36 ( L_1 ,
sizeof ( struct V_5 ) , 0 , V_62 ,
NULL ) ;
return 0 ;
}
static void F_37 ( struct V_5 * V_20 )
{
struct V_63 * V_9 = & V_20 -> V_64 . V_65 . V_9 ;
if ( V_20 -> V_64 . V_65 . V_66 . V_67 == 0 )
return;
V_20 -> V_68 += ( unsigned int ) F_38 ( V_9 ,
V_9 -> V_69 -> V_70 () ,
V_20 -> V_64 . V_65 . V_66 ) ;
V_20 -> V_71 = V_20 -> V_68 ;
V_20 -> V_68 = - 1 ;
++ V_20 -> V_72 ;
F_39 ( V_9 ) ;
}
void F_40 ( struct V_73 * V_74 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
V_20 = F_41 ( V_74 -> V_75 , & V_21 ) ;
if ( V_20 && V_20 -> V_72 == V_74 -> V_76 ) {
if ( V_20 -> V_77 < 0 )
F_42 ( V_20 ) ;
else
F_37 ( V_20 ) ;
V_74 -> V_78 += V_20 -> V_71 ;
}
if ( V_20 )
F_12 ( V_20 , V_21 ) ;
}
int F_43 ( struct V_5 * V_20 , int V_79 )
{
struct V_80 * V_81 ;
int V_82 , V_15 = - 1 ;
V_20 -> V_83 -> V_74 . V_76 = V_79 ;
F_44 () ;
V_81 = F_45 ( V_20 -> V_84 , V_85 ) ;
if ( V_81 ) {
V_82 = ! ( V_20 -> V_86 & V_87 ) ;
V_15 = F_46 ( V_20 -> V_83 , V_81 , V_82 ) ;
}
F_47 () ;
return V_15 > 0 ;
}
static enum F_39 F_48 ( struct V_63 * V_9 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
int V_79 = 0 ;
enum F_39 V_15 = V_88 ;
V_20 = F_49 ( V_9 , struct V_5 , V_64 . V_65 . V_9 ) ;
F_50 ( & V_20 -> V_22 , V_21 ) ;
if ( V_20 -> V_64 . V_65 . V_66 . V_67 != 0 )
V_79 = ++ V_20 -> V_72 ;
if ( F_43 ( V_20 , V_79 ) ) {
if ( V_20 -> V_64 . V_65 . V_66 . V_67 != 0 ) {
T_4 V_89 = F_51 ( V_9 ) ;
#ifdef F_52
{
T_4 V_90 = F_53 ( 0 , V_91 / V_92 ) ;
if ( V_20 -> V_64 . V_65 . V_66 . V_67 < V_90 . V_67 )
V_89 = F_54 ( V_89 , V_90 ) ;
}
#endif
V_20 -> V_68 += ( unsigned int )
F_38 ( V_9 , V_89 ,
V_20 -> V_64 . V_65 . V_66 ) ;
V_15 = V_93 ;
++ V_20 -> V_72 ;
}
}
F_12 ( V_20 , V_21 ) ;
return V_15 ;
}
static struct V_94 * F_55 ( T_5 * V_95 )
{
struct V_80 * V_96 = V_12 -> V_97 ;
if ( ( V_95 -> V_98 & V_87 ) &&
( ! ( V_96 = F_56 ( V_95 -> V_99 ) ) ||
! F_57 ( V_96 , V_12 ) ||
( V_95 -> V_98 & ~ V_87 ) != V_100 ) )
return NULL ;
if ( ( ( V_95 -> V_98 & ~ V_87 ) != V_101 ) &&
( ( V_95 -> V_102 <= 0 ) || ( V_95 -> V_102 > V_103 ) ) )
return NULL ;
return F_58 ( V_96 ) ;
}
void F_35 ( const T_2 V_104 ,
struct V_29 * V_105 )
{
if ( ( unsigned ) V_104 >= V_106 ) {
F_59 ( V_107 L_2 ,
V_104 ) ;
return;
}
if ( ! V_105 -> V_33 ) {
F_59 ( V_107 L_3 ,
V_104 ) ;
return;
}
if ( ! V_105 -> V_31 ) {
F_59 ( V_107 L_4 ,
V_104 ) ;
return;
}
V_108 [ V_104 ] = * V_105 ;
}
static struct V_5 * F_60 ( void )
{
struct V_5 * V_109 ;
V_109 = F_61 ( V_61 , V_110 ) ;
if ( ! V_109 )
return V_109 ;
if ( F_62 ( ! ( V_109 -> V_83 = F_63 () ) ) ) {
F_64 ( V_61 , V_109 ) ;
return NULL ;
}
memset ( & V_109 -> V_83 -> V_74 , 0 , sizeof( V_111 ) ) ;
return V_109 ;
}
static void F_65 ( struct V_112 * V_7 )
{
struct V_5 * V_109 = F_49 ( V_7 , struct V_5 , V_64 . V_113 ) ;
F_64 ( V_61 , V_109 ) ;
}
static void F_66 ( struct V_5 * V_109 , int V_114 )
{
if ( V_114 ) {
unsigned long V_21 ;
F_50 ( & V_17 , V_21 ) ;
F_67 ( & V_109 -> V_18 ) ;
F_13 ( & V_17 , V_21 ) ;
}
F_68 ( V_109 -> V_84 ) ;
F_69 ( V_109 -> V_83 ) ;
F_70 ( & V_109 -> V_64 . V_113 , F_65 ) ;
}
static struct V_29 * F_71 ( const T_2 V_8 )
{
if ( V_8 < 0 )
return ( V_8 & V_115 ) == V_116 ?
& V_117 : & V_118 ;
if ( V_8 >= V_106 || ! V_108 [ V_8 ] . V_31 )
return NULL ;
return & V_108 [ V_8 ] ;
}
static int V_41 ( struct V_5 * V_119 )
{
F_72 ( & V_119 -> V_64 . V_65 . V_9 , V_119 -> V_77 , 0 ) ;
return 0 ;
}
static struct V_5 * F_73 ( T_1 V_120 , unsigned long * V_21 )
{
struct V_5 * V_20 ;
if ( ( unsigned long long ) V_120 > V_121 )
return NULL ;
F_44 () ;
V_20 = F_7 ( V_120 ) ;
if ( V_20 ) {
F_50 ( & V_20 -> V_22 , * V_21 ) ;
if ( V_20 -> V_10 == V_12 -> signal ) {
F_47 () ;
return V_20 ;
}
F_13 ( & V_20 -> V_22 , * V_21 ) ;
}
F_47 () ;
return NULL ;
}
static void
V_45 ( struct V_5 * V_20 , struct V_122 * V_123 )
{
T_4 V_89 , V_124 , V_125 ;
struct V_63 * V_9 = & V_20 -> V_64 . V_65 . V_9 ;
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_125 = V_20 -> V_64 . V_65 . V_66 ;
if ( V_125 . V_67 )
V_123 -> V_126 = F_29 ( V_125 ) ;
else if ( ! F_74 ( V_9 ) &&
( V_20 -> V_86 & ~ V_87 ) != V_101 )
return;
V_89 = V_9 -> V_69 -> V_70 () ;
if ( V_125 . V_67 && ( V_20 -> V_72 & V_127 ||
( V_20 -> V_86 & ~ V_87 ) == V_101 ) )
V_20 -> V_68 += ( unsigned int ) F_38 ( V_9 , V_89 , V_125 ) ;
V_124 = F_75 ( F_76 ( V_9 ) , V_89 ) ;
if ( V_124 . V_67 <= 0 ) {
if ( ( V_20 -> V_86 & ~ V_87 ) != V_101 )
V_123 -> V_128 . V_129 = 1 ;
} else
V_123 -> V_128 = F_29 ( V_124 ) ;
}
static int
V_43 ( struct V_5 * V_20 , int V_21 ,
struct V_122 * V_130 , struct V_122 * V_131 )
{
struct V_63 * V_9 = & V_20 -> V_64 . V_65 . V_9 ;
enum V_132 V_133 ;
if ( V_131 )
V_45 ( V_20 , V_131 ) ;
V_20 -> V_64 . V_65 . V_66 . V_67 = 0 ;
if ( F_77 ( V_9 ) < 0 )
return V_134 ;
V_20 -> V_72 = ( V_20 -> V_72 + 2 ) &
~ V_127 ;
V_20 -> V_71 = 0 ;
if ( ! V_130 -> V_128 . V_135 && ! V_130 -> V_128 . V_129 )
return 0 ;
V_133 = V_21 & V_136 ? V_137 : V_138 ;
F_72 ( & V_20 -> V_64 . V_65 . V_9 , V_20 -> V_77 , V_133 ) ;
V_20 -> V_64 . V_65 . V_9 . V_139 = F_48 ;
F_78 ( V_9 , F_79 ( V_130 -> V_128 ) ) ;
V_20 -> V_64 . V_65 . V_66 = F_79 ( V_130 -> V_126 ) ;
if ( ( ( V_20 -> V_86 & ~ V_87 ) == V_101 ) ) {
if ( V_133 == V_138 ) {
F_80 ( V_9 , V_9 -> V_69 -> V_70 () ) ;
}
return 0 ;
}
F_81 ( V_9 , V_133 ) ;
return 0 ;
}
static int V_47 ( struct V_5 * V_9 )
{
V_9 -> V_64 . V_65 . V_66 . V_67 = 0 ;
if ( F_77 ( & V_9 -> V_64 . V_65 . V_9 ) < 0 )
return V_134 ;
return 0 ;
}
static inline int F_82 ( struct V_5 * V_9 )
{
struct V_29 * V_140 = F_71 ( V_9 -> V_77 ) ;
if ( F_83 ( ! V_140 || ! V_140 -> V_46 ) )
return - V_141 ;
return V_140 -> V_46 ( V_9 ) ;
}
static void F_84 ( struct V_5 * V_9 )
{
unsigned long V_21 ;
V_142:
F_50 ( & V_9 -> V_22 , V_21 ) ;
if ( F_82 ( V_9 ) == V_134 ) {
F_12 ( V_9 , V_21 ) ;
goto V_142;
}
F_85 ( & V_9 -> V_143 ) ;
V_9 -> V_10 = NULL ;
F_12 ( V_9 , V_21 ) ;
F_66 ( V_9 , V_144 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_109 ;
while ( ! F_87 ( & V_2 -> V_145 ) ) {
V_109 = F_88 ( V_2 -> V_145 . V_146 , struct V_5 , V_143 ) ;
F_84 ( V_109 ) ;
}
}
static int V_37 ( const T_2 V_23 , int V_21 ,
struct V_24 * V_147 , struct V_24 T_6 * V_148 )
{
return F_89 ( V_147 , V_148 , V_21 & V_136 ?
V_137 : V_138 ,
V_23 ) ;
}
long F_90 ( struct V_149 * V_149 )
{
T_2 V_23 = V_149 -> V_150 . V_151 ;
struct V_29 * V_140 = F_71 ( V_23 ) ;
if ( F_83 ( ! V_140 || ! V_140 -> V_38 ) )
return - V_141 ;
return V_140 -> V_38 ( V_149 ) ;
}
