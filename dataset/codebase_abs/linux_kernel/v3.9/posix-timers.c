static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( & V_2 -> V_4 , V_3 ) ;
}
static int F_3 ( T_1 V_5 , struct V_6 * V_7 )
{
F_4 ( V_7 ) ;
return 0 ;
}
static int F_5 ( const T_1 V_5 ,
const struct V_6 * V_7 )
{
return F_6 ( V_7 , NULL ) ;
}
static int F_7 ( const T_1 V_5 ,
struct V_8 * V_9 )
{
return F_8 ( V_9 ) ;
}
static int F_9 ( T_1 V_5 , struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
return 0 ;
}
static int F_11 ( T_1 V_5 , struct V_6 * V_7 )
{
F_12 ( V_7 ) ;
return 0 ;
}
static int F_13 ( T_1 V_5 , struct V_6 * V_7 )
{
* V_7 = F_14 () ;
return 0 ;
}
static int F_15 ( T_1 V_5 ,
struct V_6 * V_7 )
{
* V_7 = F_16 () ;
return 0 ;
}
static int F_17 ( const T_1 V_5 , struct V_6 * V_7 )
{
* V_7 = F_18 ( V_10 ) ;
return 0 ;
}
static int F_19 ( const T_1 V_5 , struct V_6 * V_7 )
{
F_20 ( V_7 ) ;
return 0 ;
}
static T_2 int F_21 ( void )
{
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = F_3 ,
. V_16 = F_5 ,
. V_17 = F_7 ,
. V_18 = V_19 ,
. V_20 = V_21 ,
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
. V_28 = V_29 ,
} ;
struct V_11 V_30 = {
. V_13 = V_14 ,
. V_15 = F_9 ,
. V_18 = V_19 ,
. V_20 = V_21 ,
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
. V_28 = V_29 ,
} ;
struct V_11 V_31 = {
. V_13 = V_14 ,
. V_15 = F_11 ,
} ;
struct V_11 V_32 = {
. V_13 = F_17 ,
. V_15 = F_13 ,
} ;
struct V_11 V_33 = {
. V_13 = F_17 ,
. V_15 = F_15 ,
} ;
struct V_11 V_34 = {
. V_13 = V_14 ,
. V_15 = F_19 ,
. V_18 = V_19 ,
. V_20 = V_21 ,
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
. V_28 = V_29 ,
} ;
F_22 ( V_35 , & V_12 ) ;
F_22 ( V_36 , & V_30 ) ;
F_22 ( V_37 , & V_31 ) ;
F_22 ( V_38 , & V_32 ) ;
F_22 ( V_39 , & V_33 ) ;
F_22 ( V_40 , & V_34 ) ;
V_41 = F_23 ( L_1 ,
sizeof ( struct V_1 ) , 0 , V_42 ,
NULL ) ;
F_24 ( & V_43 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = & V_2 -> V_46 . V_47 . V_45 ;
if ( V_2 -> V_46 . V_47 . V_48 . V_49 == 0 )
return;
V_2 -> V_50 += ( unsigned int ) F_26 ( V_45 ,
V_45 -> V_51 -> V_52 () ,
V_2 -> V_46 . V_47 . V_48 ) ;
V_2 -> V_53 = V_2 -> V_50 ;
V_2 -> V_50 = - 1 ;
++ V_2 -> V_54 ;
F_27 ( V_45 ) ;
}
void F_28 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = F_29 ( V_56 -> V_57 , & V_3 ) ;
if ( V_2 && V_2 -> V_54 == V_56 -> V_58 ) {
if ( V_2 -> V_59 < 0 )
F_30 ( V_2 ) ;
else
F_25 ( V_2 ) ;
V_56 -> V_60 += V_2 -> V_53 ;
}
if ( V_2 )
F_1 ( V_2 , V_3 ) ;
}
int F_31 ( struct V_1 * V_2 , int V_61 )
{
struct V_62 * V_63 ;
int V_64 , V_65 = - 1 ;
V_2 -> V_66 -> V_56 . V_58 = V_61 ;
F_32 () ;
V_63 = F_33 ( V_2 -> V_67 , V_68 ) ;
if ( V_63 ) {
V_64 = ! ( V_2 -> V_69 & V_70 ) ;
V_65 = F_34 ( V_2 -> V_66 , V_63 , V_64 ) ;
}
F_35 () ;
return V_65 > 0 ;
}
static enum F_27 F_36 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_61 = 0 ;
enum F_27 V_65 = V_71 ;
V_2 = F_37 ( V_45 , struct V_1 , V_46 . V_47 . V_45 ) ;
F_38 ( & V_2 -> V_4 , V_3 ) ;
if ( V_2 -> V_46 . V_47 . V_48 . V_49 != 0 )
V_61 = ++ V_2 -> V_54 ;
if ( F_31 ( V_2 , V_61 ) ) {
if ( V_2 -> V_46 . V_47 . V_48 . V_49 != 0 ) {
T_3 V_72 = F_39 ( V_45 ) ;
#ifdef F_40
{
T_3 V_73 = F_41 ( 0 , V_74 / V_75 ) ;
if ( V_2 -> V_46 . V_47 . V_48 . V_49 < V_73 . V_49 )
V_72 = F_42 ( V_72 , V_73 ) ;
}
#endif
V_2 -> V_50 += ( unsigned int )
F_26 ( V_45 , V_72 ,
V_2 -> V_46 . V_47 . V_48 ) ;
V_65 = V_76 ;
++ V_2 -> V_54 ;
}
}
F_1 ( V_2 , V_3 ) ;
return V_65 ;
}
static struct V_77 * F_43 ( T_4 * V_78 )
{
struct V_62 * V_79 = V_80 -> V_81 ;
if ( ( V_78 -> V_82 & V_70 ) &&
( ! ( V_79 = F_44 ( V_78 -> V_83 ) ) ||
! F_45 ( V_79 , V_80 ) ||
( V_78 -> V_82 & ~ V_70 ) != V_84 ) )
return NULL ;
if ( ( ( V_78 -> V_82 & ~ V_70 ) != V_85 ) &&
( ( V_78 -> V_86 <= 0 ) || ( V_78 -> V_86 > V_87 ) ) )
return NULL ;
return F_46 ( V_79 ) ;
}
void F_22 ( const T_1 V_88 ,
struct V_11 * V_89 )
{
if ( ( unsigned ) V_88 >= V_90 ) {
F_47 ( V_91 L_2 ,
V_88 ) ;
return;
}
if ( ! V_89 -> V_15 ) {
F_47 ( V_91 L_3 ,
V_88 ) ;
return;
}
if ( ! V_89 -> V_13 ) {
F_47 ( V_91 L_4 ,
V_88 ) ;
return;
}
V_92 [ V_88 ] = * V_89 ;
}
static struct V_1 * F_48 ( void )
{
struct V_1 * V_93 ;
V_93 = F_49 ( V_41 , V_94 ) ;
if ( ! V_93 )
return V_93 ;
if ( F_50 ( ! ( V_93 -> V_66 = F_51 () ) ) ) {
F_52 ( V_41 , V_93 ) ;
return NULL ;
}
memset ( & V_93 -> V_66 -> V_56 , 0 , sizeof( V_95 ) ) ;
return V_93 ;
}
static void F_53 ( struct V_96 * V_97 )
{
struct V_1 * V_93 = F_37 ( V_97 , struct V_1 , V_46 . V_98 ) ;
F_52 ( V_41 , V_93 ) ;
}
static void F_54 ( struct V_1 * V_93 , int V_99 )
{
if ( V_99 ) {
unsigned long V_3 ;
F_38 ( & V_100 , V_3 ) ;
F_55 ( & V_43 , V_93 -> V_101 ) ;
F_2 ( & V_100 , V_3 ) ;
}
F_56 ( V_93 -> V_67 ) ;
F_57 ( V_93 -> V_66 ) ;
F_58 ( & V_93 -> V_46 . V_98 , F_53 ) ;
}
static struct V_11 * F_59 ( const T_1 V_102 )
{
if ( V_102 < 0 )
return ( V_102 & V_103 ) == V_104 ?
& V_105 : & V_106 ;
if ( V_102 >= V_90 || ! V_92 [ V_102 ] . V_13 )
return NULL ;
return & V_92 [ V_102 ] ;
}
static int V_23 ( struct V_1 * V_107 )
{
F_60 ( & V_107 -> V_46 . V_47 . V_45 , V_107 -> V_59 , 0 ) ;
return 0 ;
}
static struct V_1 * F_61 ( T_5 V_108 , unsigned long * V_3 )
{
struct V_1 * V_2 ;
if ( ( unsigned long long ) V_108 > V_109 )
return NULL ;
F_32 () ;
V_2 = F_62 ( & V_43 , ( int ) V_108 ) ;
if ( V_2 ) {
F_38 ( & V_2 -> V_4 , * V_3 ) ;
if ( V_2 -> V_110 == V_80 -> signal ) {
F_35 () ;
return V_2 ;
}
F_2 ( & V_2 -> V_4 , * V_3 ) ;
}
F_35 () ;
return NULL ;
}
static void
V_27 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
T_3 V_72 , V_113 , V_114 ;
struct V_44 * V_45 = & V_2 -> V_46 . V_47 . V_45 ;
memset ( V_112 , 0 , sizeof( struct V_111 ) ) ;
V_114 = V_2 -> V_46 . V_47 . V_48 ;
if ( V_114 . V_49 )
V_112 -> V_115 = F_18 ( V_114 ) ;
else if ( ! F_63 ( V_45 ) &&
( V_2 -> V_69 & ~ V_70 ) != V_85 )
return;
V_72 = V_45 -> V_51 -> V_52 () ;
if ( V_114 . V_49 && ( V_2 -> V_54 & V_116 ||
( V_2 -> V_69 & ~ V_70 ) == V_85 ) )
V_2 -> V_50 += ( unsigned int ) F_26 ( V_45 , V_72 , V_114 ) ;
V_113 = F_64 ( F_65 ( V_45 ) , V_72 ) ;
if ( V_113 . V_49 <= 0 ) {
if ( ( V_2 -> V_69 & ~ V_70 ) != V_85 )
V_112 -> V_117 . V_118 = 1 ;
} else
V_112 -> V_117 = F_18 ( V_113 ) ;
}
static int
V_25 ( struct V_1 * V_2 , int V_3 ,
struct V_111 * V_119 , struct V_111 * V_120 )
{
struct V_44 * V_45 = & V_2 -> V_46 . V_47 . V_45 ;
enum V_121 V_122 ;
if ( V_120 )
V_27 ( V_2 , V_120 ) ;
V_2 -> V_46 . V_47 . V_48 . V_49 = 0 ;
if ( F_66 ( V_45 ) < 0 )
return V_123 ;
V_2 -> V_54 = ( V_2 -> V_54 + 2 ) &
~ V_116 ;
V_2 -> V_53 = 0 ;
if ( ! V_119 -> V_117 . V_124 && ! V_119 -> V_117 . V_118 )
return 0 ;
V_122 = V_3 & V_125 ? V_126 : V_127 ;
F_60 ( & V_2 -> V_46 . V_47 . V_45 , V_2 -> V_59 , V_122 ) ;
V_2 -> V_46 . V_47 . V_45 . V_128 = F_36 ;
F_67 ( V_45 , F_68 ( V_119 -> V_117 ) ) ;
V_2 -> V_46 . V_47 . V_48 = F_68 ( V_119 -> V_115 ) ;
if ( ( ( V_2 -> V_69 & ~ V_70 ) == V_85 ) ) {
if ( V_122 == V_127 ) {
F_69 ( V_45 , V_45 -> V_51 -> V_52 () ) ;
}
return 0 ;
}
F_70 ( V_45 , V_122 ) ;
return 0 ;
}
static int V_29 ( struct V_1 * V_45 )
{
V_45 -> V_46 . V_47 . V_48 . V_49 = 0 ;
if ( F_66 ( & V_45 -> V_46 . V_47 . V_45 ) < 0 )
return V_123 ;
return 0 ;
}
static inline int F_71 ( struct V_1 * V_45 )
{
struct V_11 * V_129 = F_59 ( V_45 -> V_59 ) ;
if ( F_72 ( ! V_129 || ! V_129 -> V_28 ) )
return - V_130 ;
return V_129 -> V_28 ( V_45 ) ;
}
static void F_73 ( struct V_1 * V_45 )
{
unsigned long V_3 ;
V_131:
F_38 ( & V_45 -> V_4 , V_3 ) ;
if ( F_71 ( V_45 ) == V_123 ) {
F_1 ( V_45 , V_3 ) ;
goto V_131;
}
F_74 ( & V_45 -> V_132 ) ;
V_45 -> V_110 = NULL ;
F_1 ( V_45 , V_3 ) ;
F_54 ( V_45 , V_133 ) ;
}
void F_75 ( struct V_134 * V_135 )
{
struct V_1 * V_93 ;
while ( ! F_76 ( & V_135 -> V_136 ) ) {
V_93 = F_77 ( V_135 -> V_136 . V_137 , struct V_1 , V_132 ) ;
F_73 ( V_93 ) ;
}
}
static int V_19 ( const T_1 V_5 , int V_3 ,
struct V_6 * V_138 , struct V_6 T_6 * V_139 )
{
return F_78 ( V_138 , V_139 , V_3 & V_125 ?
V_126 : V_127 ,
V_5 ) ;
}
long F_79 ( struct V_140 * V_140 )
{
T_1 V_5 = V_140 -> V_141 . V_142 ;
struct V_11 * V_129 = F_59 ( V_5 ) ;
if ( F_72 ( ! V_129 || ! V_129 -> V_20 ) )
return - V_130 ;
return V_129 -> V_20 ( V_140 ) ;
}
