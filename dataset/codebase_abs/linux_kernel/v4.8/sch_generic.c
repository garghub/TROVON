static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 ;
V_4 -> V_6 . V_7 ++ ;
F_2 ( V_4 , V_2 ) ;
V_4 -> V_4 . V_8 ++ ;
F_3 ( V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
const struct V_9 * V_10 ,
int * V_11 )
{
int V_12 = F_5 ( V_10 ) - V_2 -> V_13 ;
while ( V_12 > 0 ) {
struct V_1 * V_14 = V_4 -> V_15 ( V_4 ) ;
if ( ! V_14 )
break;
V_12 -= V_14 -> V_13 ;
V_2 -> V_16 = V_14 ;
V_2 = V_14 ;
( * V_11 ) ++ ;
}
V_2 -> V_16 = NULL ;
}
static void F_6 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int * V_11 )
{
int V_17 = F_7 ( V_2 ) ;
struct V_1 * V_14 ;
int V_18 = 0 ;
do {
V_14 = V_4 -> V_15 ( V_4 ) ;
if ( ! V_14 )
break;
if ( F_8 ( F_7 ( V_14 ) != V_17 ) ) {
V_4 -> V_19 = V_14 ;
F_2 ( V_4 , V_14 ) ;
V_4 -> V_4 . V_8 ++ ;
break;
}
V_2 -> V_16 = V_14 ;
V_2 = V_14 ;
} while ( ++ V_18 < 8 );
( * V_11 ) += V_18 ;
V_2 -> V_16 = NULL ;
}
static struct V_1 * F_9 ( struct V_3 * V_4 , bool * V_20 ,
int * V_11 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_4 -> V_21 ;
* V_11 = 1 ;
if ( F_8 ( V_2 ) ) {
* V_20 = false ;
V_10 = F_10 ( V_10 -> V_22 , V_2 ) ;
if ( ! F_11 ( V_10 ) ) {
V_4 -> V_5 = NULL ;
F_12 ( V_4 , V_2 ) ;
V_4 -> V_4 . V_8 -- ;
} else
V_2 = NULL ;
return V_2 ;
}
* V_20 = true ;
V_2 = V_4 -> V_19 ;
if ( F_8 ( V_2 ) ) {
V_10 = F_10 ( V_10 -> V_22 , V_2 ) ;
if ( ! F_11 ( V_10 ) ) {
V_4 -> V_19 = NULL ;
F_12 ( V_4 , V_2 ) ;
V_4 -> V_4 . V_8 -- ;
goto V_23;
}
return NULL ;
}
if ( ! ( V_4 -> V_24 & V_25 ) ||
! F_11 ( V_10 ) )
V_2 = V_4 -> V_15 ( V_4 ) ;
if ( V_2 ) {
V_23:
if ( F_13 ( V_4 ) )
F_4 ( V_4 , V_2 , V_10 , V_11 ) ;
else
F_6 ( V_4 , V_2 , V_11 ) ;
}
return V_2 ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_26 * V_22 , struct V_9 * V_10 ,
T_1 * V_27 , bool V_20 )
{
int V_28 = V_29 ;
F_15 ( V_27 ) ;
if ( V_20 )
V_2 = F_16 ( V_2 , V_22 ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( V_22 , V_10 , F_19 () ) ;
if ( ! F_11 ( V_10 ) )
V_2 = F_20 ( V_2 , V_22 , V_10 , & V_28 ) ;
F_21 ( V_22 , V_10 ) ;
} else {
F_22 ( V_27 ) ;
return F_23 ( V_4 ) ;
}
F_22 ( V_27 ) ;
if ( F_24 ( V_28 ) ) {
V_28 = F_23 ( V_4 ) ;
} else {
if ( F_8 ( V_28 != V_29 ) )
F_25 ( L_1 ,
V_22 -> V_30 , V_28 , V_4 -> V_4 . V_8 ) ;
V_28 = F_1 ( V_2 , V_4 ) ;
}
if ( V_28 && F_11 ( V_10 ) )
V_28 = 0 ;
return V_28 ;
}
static inline int F_26 ( struct V_3 * V_4 , int * V_11 )
{
struct V_9 * V_10 ;
struct V_26 * V_22 ;
T_1 * V_27 ;
struct V_1 * V_2 ;
bool V_20 ;
V_2 = F_9 ( V_4 , & V_20 , V_11 ) ;
if ( F_8 ( ! V_2 ) )
return 0 ;
V_27 = F_27 ( V_4 ) ;
V_22 = F_28 ( V_4 ) ;
V_10 = F_10 ( V_22 , V_2 ) ;
return F_14 ( V_2 , V_4 , V_22 , V_10 , V_27 , V_20 ) ;
}
void F_29 ( struct V_3 * V_4 )
{
int V_31 = V_32 ;
int V_11 ;
while ( F_26 ( V_4 , & V_11 ) ) {
V_31 -= V_11 ;
if ( V_31 <= 0 || F_30 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_31 ( V_4 ) ;
}
unsigned long F_32 ( struct V_26 * V_22 )
{
unsigned long V_33 , V_34 ;
unsigned int V_35 ;
if ( F_33 ( V_22 ) )
V_22 = F_34 ( V_22 ) ;
V_34 = F_35 ( V_22 , 0 ) -> V_36 ;
for ( V_35 = 1 ; V_35 < V_22 -> V_37 ; V_35 ++ ) {
V_33 = F_35 ( V_22 , V_35 ) -> V_36 ;
if ( V_33 && F_36 ( V_33 , V_34 ) )
V_34 = V_33 ;
}
return V_34 ;
}
static void F_37 ( unsigned long V_38 )
{
struct V_26 * V_22 = (struct V_26 * ) V_38 ;
F_38 ( V_22 ) ;
if ( ! F_39 ( V_22 ) ) {
if ( F_40 ( V_22 ) &&
F_41 ( V_22 ) &&
F_42 ( V_22 ) ) {
int V_39 = 0 ;
unsigned int V_35 ;
unsigned long V_36 ;
for ( V_35 = 0 ; V_35 < V_22 -> V_37 ; V_35 ++ ) {
struct V_9 * V_10 ;
V_10 = F_35 ( V_22 , V_35 ) ;
V_36 = V_10 -> V_36 ;
if ( F_43 ( V_10 ) &&
F_36 ( V_40 , ( V_36 +
V_22 -> V_41 ) ) ) {
V_39 = 1 ;
V_10 -> V_42 ++ ;
break;
}
}
if ( V_39 ) {
F_44 ( 1 , V_43 L_2 ,
V_22 -> V_30 , F_45 ( V_22 ) , V_35 ) ;
V_22 -> V_44 -> V_45 ( V_22 ) ;
}
if ( ! F_46 ( & V_22 -> V_46 ,
F_47 ( V_40 +
V_22 -> V_41 ) ) )
F_48 ( V_22 ) ;
}
}
F_49 ( V_22 ) ;
F_50 ( V_22 ) ;
}
void F_51 ( struct V_26 * V_22 )
{
if ( V_22 -> V_44 -> V_45 ) {
if ( V_22 -> V_41 <= 0 )
V_22 -> V_41 = 5 * V_47 ;
if ( ! F_46 ( & V_22 -> V_46 ,
F_47 ( V_40 + V_22 -> V_41 ) ) )
F_48 ( V_22 ) ;
}
}
static void F_52 ( struct V_26 * V_22 )
{
F_51 ( V_22 ) ;
}
static void F_53 ( struct V_26 * V_22 )
{
F_54 ( V_22 ) ;
if ( F_55 ( & V_22 -> V_46 ) )
F_50 ( V_22 ) ;
F_56 ( V_22 ) ;
}
void F_57 ( struct V_26 * V_22 )
{
if ( F_58 ( V_48 , & V_22 -> V_49 ) ) {
if ( V_22 -> V_50 == V_51 )
return;
F_59 ( & V_22 -> V_52 ) ;
F_60 ( V_22 ) ;
if ( F_41 ( V_22 ) )
F_51 ( V_22 ) ;
}
}
void F_61 ( struct V_26 * V_22 )
{
if ( ! F_62 ( V_48 , & V_22 -> V_49 ) ) {
if ( V_22 -> V_50 == V_51 )
return;
F_59 ( & V_22 -> V_52 ) ;
F_60 ( V_22 ) ;
}
}
static int F_63 ( struct V_1 * V_2 , struct V_3 * V_53 ,
struct V_1 * * V_54 )
{
F_64 ( V_2 , V_54 ) ;
return V_55 ;
}
static struct V_1 * F_65 ( struct V_3 * V_53 )
{
return NULL ;
}
static int F_66 ( struct V_3 * V_53 , struct V_56 * V_57 )
{
V_53 -> V_58 = NULL ;
return 0 ;
}
static inline struct V_59 * F_67 ( struct V_60 * V_61 ,
int V_62 )
{
return V_61 -> V_4 + V_62 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_3 * V_53 ,
struct V_1 * * V_54 )
{
if ( F_69 ( & V_53 -> V_4 ) < F_28 ( V_53 ) -> V_63 ) {
int V_62 = V_64 [ V_2 -> V_65 & V_66 ] ;
struct V_60 * V_61 = F_70 ( V_53 ) ;
struct V_59 * V_67 = F_67 ( V_61 , V_62 ) ;
V_61 -> V_68 |= ( 1 << V_62 ) ;
V_53 -> V_4 . V_8 ++ ;
return F_71 ( V_2 , V_53 , V_67 ) ;
}
return F_72 ( V_2 , V_53 , V_54 ) ;
}
static struct V_1 * F_73 ( struct V_3 * V_53 )
{
struct V_60 * V_61 = F_70 ( V_53 ) ;
int V_62 = V_69 [ V_61 -> V_68 ] ;
if ( F_17 ( V_62 >= 0 ) ) {
struct V_59 * V_67 = F_67 ( V_61 , V_62 ) ;
struct V_1 * V_2 = F_74 ( V_53 , V_67 ) ;
V_53 -> V_4 . V_8 -- ;
if ( F_75 ( V_67 ) )
V_61 -> V_68 &= ~ ( 1 << V_62 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_76 ( struct V_3 * V_53 )
{
struct V_60 * V_61 = F_70 ( V_53 ) ;
int V_62 = V_69 [ V_61 -> V_68 ] ;
if ( V_62 >= 0 ) {
struct V_59 * V_67 = F_67 ( V_61 , V_62 ) ;
return F_77 ( V_67 ) ;
}
return NULL ;
}
static void F_78 ( struct V_3 * V_53 )
{
int V_70 ;
struct V_60 * V_61 = F_70 ( V_53 ) ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_79 ( F_67 ( V_61 , V_70 ) ) ;
V_61 -> V_68 = 0 ;
V_53 -> V_6 . V_72 = 0 ;
V_53 -> V_4 . V_8 = 0 ;
}
static int F_80 ( struct V_3 * V_53 , struct V_1 * V_2 )
{
struct V_73 V_57 = { . V_74 = V_71 } ;
memcpy ( & V_57 . V_75 , V_64 , V_66 + 1 ) ;
if ( F_81 ( V_2 , V_76 , sizeof( V_57 ) , & V_57 ) )
goto V_77;
return V_2 -> V_13 ;
V_77:
return - 1 ;
}
static int F_82 ( struct V_3 * V_53 , struct V_56 * V_57 )
{
int V_70 ;
struct V_60 * V_61 = F_70 ( V_53 ) ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_83 ( F_67 ( V_61 , V_70 ) ) ;
V_53 -> V_24 |= V_78 ;
return 0 ;
}
struct V_3 * F_84 ( struct V_9 * V_21 ,
const struct V_79 * V_80 )
{
void * V_81 ;
struct V_3 * V_82 ;
unsigned int V_83 = F_85 ( sizeof( * V_82 ) ) + V_80 -> V_84 ;
int V_85 = - V_86 ;
struct V_26 * V_22 = V_21 -> V_22 ;
V_81 = F_86 ( V_83 , V_87 ,
F_87 ( V_21 ) ) ;
if ( ! V_81 )
goto V_88;
V_82 = (struct V_3 * ) F_85 ( ( unsigned long ) V_81 ) ;
if ( V_82 != V_81 ) {
F_88 ( V_81 ) ;
V_81 = F_86 ( V_83 + V_89 - 1 , V_87 ,
F_87 ( V_21 ) ) ;
if ( ! V_81 )
goto V_88;
V_82 = (struct V_3 * ) F_85 ( ( unsigned long ) V_81 ) ;
V_82 -> V_90 = ( char * ) V_82 - ( char * ) V_81 ;
}
F_89 ( & V_82 -> V_67 ) ;
F_90 ( & V_82 -> V_4 ) ;
F_91 ( & V_82 -> V_91 ) ;
F_92 ( & V_82 -> V_91 ,
V_22 -> V_92 ? : & V_92 ) ;
F_93 ( & V_82 -> V_93 ) ;
F_92 ( & V_82 -> V_93 ,
V_22 -> V_94 ? : & V_94 ) ;
V_82 -> V_80 = V_80 ;
V_82 -> V_58 = V_80 -> V_58 ;
V_82 -> V_15 = V_80 -> V_15 ;
V_82 -> V_21 = V_21 ;
F_48 ( V_22 ) ;
F_94 ( & V_82 -> V_95 , 1 ) ;
return V_82 ;
V_88:
return F_95 ( V_85 ) ;
}
struct V_3 * F_96 ( struct V_9 * V_21 ,
const struct V_79 * V_80 ,
unsigned int V_96 )
{
struct V_3 * V_82 ;
if ( ! F_97 ( V_80 -> V_97 ) )
return NULL ;
V_82 = F_84 ( V_21 , V_80 ) ;
if ( F_98 ( V_82 ) ) {
F_99 ( V_80 -> V_97 ) ;
return NULL ;
}
V_82 -> V_98 = V_96 ;
if ( ! V_80 -> V_99 || V_80 -> V_99 ( V_82 , NULL ) == 0 )
return V_82 ;
F_100 ( V_82 ) ;
return NULL ;
}
void F_101 ( struct V_3 * V_53 )
{
const struct V_79 * V_80 = V_53 -> V_80 ;
if ( V_80 -> V_100 )
V_80 -> V_100 ( V_53 ) ;
F_102 ( V_53 -> V_19 ) ;
V_53 -> V_19 = NULL ;
if ( V_53 -> V_5 ) {
F_103 ( V_53 -> V_5 ) ;
V_53 -> V_5 = NULL ;
}
V_53 -> V_4 . V_8 = 0 ;
}
static void F_104 ( struct V_101 * V_102 )
{
struct V_3 * V_53 = F_105 ( V_102 , struct V_3 , V_101 ) ;
if ( F_106 ( V_53 ) ) {
F_107 ( V_53 -> V_103 ) ;
F_107 ( V_53 -> V_104 ) ;
}
F_88 ( ( char * ) V_53 - V_53 -> V_90 ) ;
}
void F_100 ( struct V_3 * V_53 )
{
const struct V_79 * V_80 = V_53 -> V_80 ;
if ( V_53 -> V_24 & V_105 ||
! F_108 ( & V_53 -> V_95 ) )
return;
#ifdef F_109
F_110 ( V_53 ) ;
F_111 ( F_112 ( V_53 -> V_106 ) ) ;
#endif
F_113 ( & V_53 -> V_107 , & V_53 -> V_108 ) ;
if ( V_80 -> V_100 )
V_80 -> V_100 ( V_53 ) ;
if ( V_80 -> V_109 )
V_80 -> V_109 ( V_53 ) ;
F_99 ( V_80 -> V_97 ) ;
F_50 ( F_28 ( V_53 ) ) ;
F_103 ( V_53 -> V_5 ) ;
F_102 ( V_53 -> V_19 ) ;
F_114 ( & V_53 -> V_101 , F_104 ) ;
}
struct V_3 * F_115 ( struct V_9 * V_21 ,
struct V_3 * V_53 )
{
struct V_3 * V_110 = V_21 -> V_111 ;
T_1 * V_27 ;
V_27 = F_27 ( V_110 ) ;
F_116 ( V_27 ) ;
if ( V_110 && F_117 ( & V_110 -> V_95 ) <= 1 )
F_101 ( V_110 ) ;
if ( V_53 == NULL )
V_53 = & V_112 ;
V_21 -> V_111 = V_53 ;
F_118 ( V_21 -> V_53 , & V_112 ) ;
F_119 ( V_27 ) ;
return V_110 ;
}
static void F_120 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_113 )
{
struct V_3 * V_53 ;
const struct V_79 * V_80 = V_114 ;
if ( V_22 -> V_115 & V_116 )
V_80 = & V_117 ;
V_53 = F_96 ( V_21 , V_80 , V_118 ) ;
if ( ! V_53 ) {
F_121 ( V_22 , L_3 ) ;
return;
}
if ( ! F_122 ( V_22 ) )
V_53 -> V_24 |= V_25 | V_119 ;
V_21 -> V_111 = V_53 ;
}
static void F_123 ( struct V_26 * V_22 )
{
struct V_9 * V_10 ;
struct V_3 * V_53 ;
V_10 = F_35 ( V_22 , 0 ) ;
if ( ! F_122 ( V_22 ) ||
V_22 -> V_115 & V_116 ) {
F_124 ( V_22 , F_120 , NULL ) ;
V_22 -> V_53 = V_10 -> V_111 ;
F_59 ( & V_22 -> V_53 -> V_95 ) ;
} else {
V_53 = F_96 ( V_10 , & V_120 , V_118 ) ;
if ( V_53 ) {
V_22 -> V_53 = V_53 ;
V_53 -> V_80 -> V_121 ( V_53 ) ;
}
}
}
static void F_125 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_122 )
{
struct V_3 * V_123 = V_21 -> V_111 ;
int * V_124 = V_122 ;
if ( ! ( V_123 -> V_24 & V_105 ) )
F_126 ( V_125 , & V_123 -> V_49 ) ;
F_118 ( V_21 -> V_53 , V_123 ) ;
if ( V_124 ) {
V_21 -> V_36 = 0 ;
* V_124 = 1 ;
}
}
void F_127 ( struct V_26 * V_22 )
{
int V_126 ;
if ( V_22 -> V_53 == & V_112 )
F_123 ( V_22 ) ;
if ( ! F_42 ( V_22 ) )
return;
V_126 = 0 ;
F_124 ( V_22 , F_125 , & V_126 ) ;
if ( F_128 ( V_22 ) )
F_125 ( V_22 , F_128 ( V_22 ) , NULL ) ;
if ( V_126 ) {
F_129 ( V_22 ) ;
F_52 ( V_22 ) ;
}
}
static void F_130 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_127 )
{
struct V_3 * V_128 = V_127 ;
struct V_3 * V_53 ;
V_53 = F_112 ( V_21 -> V_53 ) ;
if ( V_53 ) {
F_116 ( F_27 ( V_53 ) ) ;
if ( ! ( V_53 -> V_24 & V_105 ) )
F_131 ( V_125 , & V_53 -> V_49 ) ;
F_118 ( V_21 -> V_53 , V_128 ) ;
F_101 ( V_53 ) ;
F_119 ( F_27 ( V_53 ) ) ;
}
}
static bool F_132 ( struct V_26 * V_22 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_22 -> V_37 ; V_35 ++ ) {
struct V_9 * V_21 ;
T_1 * V_27 ;
struct V_3 * V_4 ;
int V_33 ;
V_21 = F_35 ( V_22 , V_35 ) ;
V_4 = V_21 -> V_111 ;
V_27 = F_27 ( V_4 ) ;
F_116 ( V_27 ) ;
V_33 = ( F_133 ( V_4 ) ||
F_134 ( V_129 , & V_4 -> V_49 ) ) ;
F_119 ( V_27 ) ;
if ( V_33 )
return true ;
}
return false ;
}
void F_135 ( struct V_130 * V_102 )
{
struct V_26 * V_22 ;
bool V_131 = false ;
F_136 (dev, head, close_list) {
F_124 ( V_22 , F_130 ,
& V_112 ) ;
if ( F_128 ( V_22 ) )
F_130 ( V_22 , F_128 ( V_22 ) ,
& V_112 ) ;
F_53 ( V_22 ) ;
V_131 |= ! V_22 -> V_132 ;
}
if ( V_131 )
F_137 () ;
F_136 (dev, head, close_list)
while ( F_132 ( V_22 ) )
F_138 () ;
}
void F_139 ( struct V_26 * V_22 )
{
F_140 ( V_133 ) ;
F_141 ( & V_22 -> V_134 , & V_133 ) ;
F_135 ( & V_133 ) ;
F_142 ( & V_133 ) ;
}
static void F_143 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_135 )
{
struct V_3 * V_53 = V_135 ;
F_118 ( V_21 -> V_53 , V_53 ) ;
V_21 -> V_111 = V_53 ;
}
void F_144 ( struct V_26 * V_22 )
{
V_22 -> V_53 = & V_112 ;
F_124 ( V_22 , F_143 , & V_112 ) ;
if ( F_128 ( V_22 ) )
F_143 ( V_22 , F_128 ( V_22 ) , & V_112 ) ;
F_145 ( & V_22 -> V_46 , F_37 , ( unsigned long ) V_22 ) ;
}
static void F_146 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_127 )
{
struct V_3 * V_53 = V_21 -> V_111 ;
struct V_3 * V_128 = V_127 ;
if ( V_53 ) {
F_118 ( V_21 -> V_53 , V_128 ) ;
V_21 -> V_111 = V_128 ;
F_100 ( V_53 ) ;
}
}
void F_147 ( struct V_26 * V_22 )
{
F_124 ( V_22 , F_146 , & V_112 ) ;
if ( F_128 ( V_22 ) )
F_146 ( V_22 , F_128 ( V_22 ) , & V_112 ) ;
F_100 ( V_22 -> V_53 ) ;
V_22 -> V_53 = & V_112 ;
F_148 ( F_149 ( & V_22 -> V_46 ) ) ;
}
void F_150 ( struct V_136 * V_137 ,
const struct V_138 * V_139 ,
T_2 V_140 )
{
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
V_137 -> V_141 = V_139 -> V_141 ;
V_137 -> V_142 = F_151 ( T_2 , V_139 -> V_143 , V_140 ) ;
V_137 -> V_144 = ( V_139 -> V_144 & V_145 ) ;
V_137 -> V_146 = 1 ;
if ( V_137 -> V_142 > 0 ) {
T_2 V_147 = V_148 ;
for (; ; ) {
V_137 -> V_146 = F_152 ( V_147 , V_137 -> V_142 ) ;
if ( V_137 -> V_146 & ( 1U << 31 ) || V_147 & ( 1ULL << 63 ) )
break;
V_147 <<= 1 ;
V_137 -> V_149 ++ ;
}
}
}
