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
if ( V_20 -> V_66 . V_67 . V_68 == 0 )
return;
V_20 -> V_69 += ( unsigned int ) F_39 ( V_9 ,
V_9 -> V_70 -> V_71 () ,
V_20 -> V_66 . V_67 . V_68 ) ;
V_20 -> V_72 = V_20 -> V_69 ;
V_20 -> V_69 = - 1 ;
++ V_20 -> V_73 ;
F_40 ( V_9 ) ;
}
void F_41 ( struct V_74 * V_75 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
V_20 = F_42 ( V_75 -> V_76 , & V_21 ) ;
if ( V_20 && V_20 -> V_73 == V_75 -> V_77 ) {
if ( V_20 -> V_78 < 0 )
F_43 ( V_20 ) ;
else
F_38 ( V_20 ) ;
V_75 -> V_79 += V_20 -> V_72 ;
}
if ( V_20 )
F_12 ( V_20 , V_21 ) ;
}
int F_44 ( struct V_5 * V_20 , int V_80 )
{
struct V_81 * V_82 ;
int V_83 , V_15 = - 1 ;
V_20 -> V_84 -> V_75 . V_77 = V_80 ;
F_45 () ;
V_82 = F_46 ( V_20 -> V_85 , V_86 ) ;
if ( V_82 ) {
V_83 = ! ( V_20 -> V_87 & V_88 ) ;
V_15 = F_47 ( V_20 -> V_84 , V_82 , V_83 ) ;
}
F_48 () ;
return V_15 > 0 ;
}
static enum F_40 F_49 ( struct V_65 * V_9 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
int V_80 = 0 ;
enum F_40 V_15 = V_89 ;
V_20 = F_50 ( V_9 , struct V_5 , V_66 . V_67 . V_9 ) ;
F_51 ( & V_20 -> V_22 , V_21 ) ;
if ( V_20 -> V_66 . V_67 . V_68 != 0 )
V_80 = ++ V_20 -> V_73 ;
if ( F_44 ( V_20 , V_80 ) ) {
if ( V_20 -> V_66 . V_67 . V_68 != 0 ) {
T_4 V_90 = F_52 ( V_9 ) ;
#ifdef F_53
{
T_4 V_91 = V_92 / V_93 ;
if ( V_20 -> V_66 . V_67 . V_68 < V_91 )
V_90 = F_54 ( V_90 , V_91 ) ;
}
#endif
V_20 -> V_69 += ( unsigned int )
F_39 ( V_9 , V_90 ,
V_20 -> V_66 . V_67 . V_68 ) ;
V_15 = V_94 ;
++ V_20 -> V_73 ;
}
}
F_12 ( V_20 , V_21 ) ;
return V_15 ;
}
static struct V_95 * F_55 ( T_5 * V_96 )
{
struct V_81 * V_97 = V_12 -> V_98 ;
if ( ( V_96 -> V_99 & V_88 ) &&
( ! ( V_97 = F_56 ( V_96 -> V_100 ) ) ||
! F_57 ( V_97 , V_12 ) ||
( V_96 -> V_99 & ~ V_88 ) != V_101 ) )
return NULL ;
if ( ( ( V_96 -> V_99 & ~ V_88 ) != V_102 ) &&
( ( V_96 -> V_103 <= 0 ) || ( V_96 -> V_103 > V_104 ) ) )
return NULL ;
return F_58 ( V_97 ) ;
}
void F_36 ( const T_2 V_105 ,
struct V_32 * V_106 )
{
if ( ( unsigned ) V_105 >= V_107 ) {
F_59 ( V_108 L_2 ,
V_105 ) ;
return;
}
if ( ! V_106 -> V_35 ) {
F_59 ( V_108 L_3 ,
V_105 ) ;
return;
}
if ( ! V_106 -> V_34 ) {
F_59 ( V_108 L_4 ,
V_105 ) ;
return;
}
V_109 [ V_105 ] = * V_106 ;
}
static struct V_5 * F_60 ( void )
{
struct V_5 * V_110 ;
V_110 = F_61 ( V_63 , V_111 ) ;
if ( ! V_110 )
return V_110 ;
if ( F_62 ( ! ( V_110 -> V_84 = F_63 () ) ) ) {
F_64 ( V_63 , V_110 ) ;
return NULL ;
}
memset ( & V_110 -> V_84 -> V_75 , 0 , sizeof( V_112 ) ) ;
return V_110 ;
}
static void F_65 ( struct V_113 * V_7 )
{
struct V_5 * V_110 = F_50 ( V_7 , struct V_5 , V_66 . V_114 ) ;
F_64 ( V_63 , V_110 ) ;
}
static void F_66 ( struct V_5 * V_110 , int V_115 )
{
if ( V_115 ) {
unsigned long V_21 ;
F_51 ( & V_17 , V_21 ) ;
F_67 ( & V_110 -> V_18 ) ;
F_13 ( & V_17 , V_21 ) ;
}
F_68 ( V_110 -> V_85 ) ;
F_69 ( V_110 -> V_84 ) ;
F_70 ( & V_110 -> V_66 . V_114 , F_65 ) ;
}
static struct V_32 * F_71 ( const T_2 V_8 )
{
if ( V_8 < 0 )
return ( V_8 & V_116 ) == V_117 ?
& V_118 : & V_119 ;
if ( V_8 >= V_107 || ! V_109 [ V_8 ] . V_34 )
return NULL ;
return & V_109 [ V_8 ] ;
}
static int V_43 ( struct V_5 * V_120 )
{
F_72 ( & V_120 -> V_66 . V_67 . V_9 , V_120 -> V_78 , 0 ) ;
return 0 ;
}
static struct V_5 * F_73 ( T_1 V_121 , unsigned long * V_21 )
{
struct V_5 * V_20 ;
if ( ( unsigned long long ) V_121 > V_122 )
return NULL ;
F_45 () ;
V_20 = F_7 ( V_121 ) ;
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
V_47 ( struct V_5 * V_20 , struct V_123 * V_124 )
{
T_4 V_90 , V_125 , V_126 ;
struct V_65 * V_9 = & V_20 -> V_66 . V_67 . V_9 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_126 = V_20 -> V_66 . V_67 . V_68 ;
if ( V_126 )
V_124 -> V_127 = F_29 ( V_126 ) ;
else if ( ! F_74 ( V_9 ) &&
( V_20 -> V_87 & ~ V_88 ) != V_102 )
return;
V_90 = V_9 -> V_70 -> V_71 () ;
if ( V_126 && ( V_20 -> V_73 & V_128 ||
( V_20 -> V_87 & ~ V_88 ) == V_102 ) )
V_20 -> V_69 += ( unsigned int ) F_39 ( V_9 , V_90 , V_126 ) ;
V_125 = F_75 ( V_9 , V_90 ) ;
if ( V_125 <= 0 ) {
if ( ( V_20 -> V_87 & ~ V_88 ) != V_102 )
V_124 -> V_129 . V_30 = 1 ;
} else
V_124 -> V_129 = F_29 ( V_125 ) ;
}
static int
V_45 ( struct V_5 * V_20 , int V_21 ,
struct V_123 * V_130 , struct V_123 * V_131 )
{
struct V_65 * V_9 = & V_20 -> V_66 . V_67 . V_9 ;
enum V_132 V_133 ;
if ( V_131 )
V_47 ( V_20 , V_131 ) ;
V_20 -> V_66 . V_67 . V_68 = 0 ;
if ( F_76 ( V_9 ) < 0 )
return V_134 ;
V_20 -> V_73 = ( V_20 -> V_73 + 2 ) &
~ V_128 ;
V_20 -> V_72 = 0 ;
if ( ! V_130 -> V_129 . V_29 && ! V_130 -> V_129 . V_30 )
return 0 ;
V_133 = V_21 & V_135 ? V_136 : V_137 ;
F_72 ( & V_20 -> V_66 . V_67 . V_9 , V_20 -> V_78 , V_133 ) ;
V_20 -> V_66 . V_67 . V_9 . V_138 = F_49 ;
F_77 ( V_9 , F_78 ( V_130 -> V_129 ) ) ;
V_20 -> V_66 . V_67 . V_68 = F_78 ( V_130 -> V_127 ) ;
if ( ( ( V_20 -> V_87 & ~ V_88 ) == V_102 ) ) {
if ( V_133 == V_137 ) {
F_79 ( V_9 , V_9 -> V_70 -> V_71 () ) ;
}
return 0 ;
}
F_80 ( V_9 , V_133 ) ;
return 0 ;
}
static int V_49 ( struct V_5 * V_9 )
{
V_9 -> V_66 . V_67 . V_68 = 0 ;
if ( F_76 ( & V_9 -> V_66 . V_67 . V_9 ) < 0 )
return V_134 ;
return 0 ;
}
static inline int F_81 ( struct V_5 * V_9 )
{
struct V_32 * V_139 = F_71 ( V_9 -> V_78 ) ;
if ( F_82 ( ! V_139 || ! V_139 -> V_48 ) )
return - V_140 ;
return V_139 -> V_48 ( V_9 ) ;
}
static void F_83 ( struct V_5 * V_9 )
{
unsigned long V_21 ;
V_141:
F_51 ( & V_9 -> V_22 , V_21 ) ;
if ( F_81 ( V_9 ) == V_134 ) {
F_12 ( V_9 , V_21 ) ;
goto V_141;
}
F_84 ( & V_9 -> V_142 ) ;
V_9 -> V_10 = NULL ;
F_12 ( V_9 , V_21 ) ;
F_66 ( V_9 , V_143 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_5 * V_110 ;
while ( ! F_86 ( & V_2 -> V_144 ) ) {
V_110 = F_87 ( V_2 -> V_144 . V_145 , struct V_5 , V_142 ) ;
F_83 ( V_110 ) ;
}
}
static int V_39 ( const T_2 V_23 , int V_21 ,
struct V_24 * V_146 , struct V_147 T_6 * V_148 )
{
return F_88 ( V_146 , V_148 , V_21 & V_135 ?
V_136 : V_137 ,
V_23 ) ;
}
long F_89 ( struct V_149 * V_149 )
{
T_2 V_23 = V_149 -> V_150 . V_151 ;
struct V_32 * V_139 = F_71 ( V_23 ) ;
if ( F_82 ( ! V_139 || ! V_139 -> V_40 ) )
return - V_140 ;
return V_139 -> V_40 ( V_149 ) ;
}
