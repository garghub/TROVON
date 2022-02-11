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
static struct V_1 * F_6 ( struct V_3 * V_4 , bool * V_17 ,
int * V_11 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_4 -> V_18 ;
* V_11 = 1 ;
* V_17 = true ;
if ( F_7 ( V_2 ) ) {
V_10 = F_8 ( V_10 -> V_19 , V_2 ) ;
if ( ! F_9 ( V_10 ) ) {
V_4 -> V_5 = NULL ;
F_10 ( V_4 , V_2 ) ;
V_4 -> V_4 . V_8 -- ;
} else
V_2 = NULL ;
* V_17 = false ;
} else {
if ( ! ( V_4 -> V_20 & V_21 ) ||
! F_9 ( V_10 ) ) {
V_2 = V_4 -> V_15 ( V_4 ) ;
if ( V_2 && F_11 ( V_4 ) )
F_4 ( V_4 , V_2 , V_10 , V_11 ) ;
}
}
return V_2 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_22 * V_19 , struct V_9 * V_10 ,
T_1 * V_23 , bool V_17 )
{
int V_24 = V_25 ;
F_13 ( V_23 ) ;
if ( V_17 )
V_2 = F_14 ( V_2 , V_19 ) ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_19 , V_10 , F_17 () ) ;
if ( ! F_9 ( V_10 ) )
V_2 = F_18 ( V_2 , V_19 , V_10 , & V_24 ) ;
F_19 ( V_19 , V_10 ) ;
} else {
F_20 ( V_23 ) ;
return F_21 ( V_4 ) ;
}
F_20 ( V_23 ) ;
if ( F_22 ( V_24 ) ) {
V_24 = F_21 ( V_4 ) ;
} else {
if ( F_7 ( V_24 != V_25 ) )
F_23 ( L_1 ,
V_19 -> V_26 , V_24 , V_4 -> V_4 . V_8 ) ;
V_24 = F_1 ( V_2 , V_4 ) ;
}
if ( V_24 && F_9 ( V_10 ) )
V_24 = 0 ;
return V_24 ;
}
static inline int F_24 ( struct V_3 * V_4 , int * V_11 )
{
struct V_9 * V_10 ;
struct V_22 * V_19 ;
T_1 * V_23 ;
struct V_1 * V_2 ;
bool V_17 ;
V_2 = F_6 ( V_4 , & V_17 , V_11 ) ;
if ( F_7 ( ! V_2 ) )
return 0 ;
V_23 = F_25 ( V_4 ) ;
V_19 = F_26 ( V_4 ) ;
V_10 = F_8 ( V_19 , V_2 ) ;
return F_12 ( V_2 , V_4 , V_19 , V_10 , V_23 , V_17 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
int V_27 = V_28 ;
int V_11 ;
while ( F_24 ( V_4 , & V_11 ) ) {
V_27 -= V_11 ;
if ( V_27 <= 0 || F_28 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_29 ( V_4 ) ;
}
unsigned long F_30 ( struct V_22 * V_19 )
{
unsigned long V_29 , V_30 ;
unsigned int V_31 ;
if ( F_31 ( V_19 ) )
V_19 = F_32 ( V_19 ) ;
V_30 = F_33 ( V_19 , 0 ) -> V_32 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_33 ; V_31 ++ ) {
V_29 = F_33 ( V_19 , V_31 ) -> V_32 ;
if ( V_29 && F_34 ( V_29 , V_30 ) )
V_30 = V_29 ;
}
return V_30 ;
}
static void F_35 ( unsigned long V_34 )
{
struct V_22 * V_19 = (struct V_22 * ) V_34 ;
F_36 ( V_19 ) ;
if ( ! F_37 ( V_19 ) ) {
if ( F_38 ( V_19 ) &&
F_39 ( V_19 ) &&
F_40 ( V_19 ) ) {
int V_35 = 0 ;
unsigned int V_31 ;
unsigned long V_32 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_33 ; V_31 ++ ) {
struct V_9 * V_10 ;
V_10 = F_33 ( V_19 , V_31 ) ;
V_32 = V_10 -> V_32 ;
if ( F_41 ( V_10 ) &&
F_34 ( V_36 , ( V_32 +
V_19 -> V_37 ) ) ) {
V_35 = 1 ;
V_10 -> V_38 ++ ;
break;
}
}
if ( V_35 ) {
F_42 ( 1 , V_39 L_2 ,
V_19 -> V_26 , F_43 ( V_19 ) , V_31 ) ;
V_19 -> V_40 -> V_41 ( V_19 ) ;
}
if ( ! F_44 ( & V_19 -> V_42 ,
F_45 ( V_36 +
V_19 -> V_37 ) ) )
F_46 ( V_19 ) ;
}
}
F_47 ( V_19 ) ;
F_48 ( V_19 ) ;
}
void F_49 ( struct V_22 * V_19 )
{
if ( V_19 -> V_40 -> V_41 ) {
if ( V_19 -> V_37 <= 0 )
V_19 -> V_37 = 5 * V_43 ;
if ( ! F_44 ( & V_19 -> V_42 ,
F_45 ( V_36 + V_19 -> V_37 ) ) )
F_46 ( V_19 ) ;
}
}
static void F_50 ( struct V_22 * V_19 )
{
F_49 ( V_19 ) ;
}
static void F_51 ( struct V_22 * V_19 )
{
F_52 ( V_19 ) ;
if ( F_53 ( & V_19 -> V_42 ) )
F_48 ( V_19 ) ;
F_54 ( V_19 ) ;
}
void F_55 ( struct V_22 * V_19 )
{
if ( F_56 ( V_44 , & V_19 -> V_45 ) ) {
if ( V_19 -> V_46 == V_47 )
return;
F_57 ( & V_19 -> V_48 ) ;
F_58 ( V_19 ) ;
if ( F_39 ( V_19 ) )
F_49 ( V_19 ) ;
}
}
void F_59 ( struct V_22 * V_19 )
{
if ( ! F_60 ( V_44 , & V_19 -> V_45 ) ) {
if ( V_19 -> V_46 == V_47 )
return;
F_57 ( & V_19 -> V_48 ) ;
F_58 ( V_19 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_49 )
{
F_62 ( V_2 ) ;
return V_50 ;
}
static struct V_1 * F_63 ( struct V_3 * V_49 )
{
return NULL ;
}
static int F_64 ( struct V_3 * V_49 , struct V_51 * V_52 )
{
V_49 -> V_53 = NULL ;
return 0 ;
}
static inline struct V_54 * F_65 ( struct V_55 * V_56 ,
int V_57 )
{
return V_56 -> V_4 + V_57 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_49 )
{
if ( F_67 ( & V_49 -> V_4 ) < F_26 ( V_49 ) -> V_58 ) {
int V_57 = V_59 [ V_2 -> V_60 & V_61 ] ;
struct V_55 * V_56 = F_68 ( V_49 ) ;
struct V_54 * V_62 = F_65 ( V_56 , V_57 ) ;
V_56 -> V_63 |= ( 1 << V_57 ) ;
V_49 -> V_4 . V_8 ++ ;
return F_69 ( V_2 , V_49 , V_62 ) ;
}
return F_70 ( V_2 , V_49 ) ;
}
static struct V_1 * F_71 ( struct V_3 * V_49 )
{
struct V_55 * V_56 = F_68 ( V_49 ) ;
int V_57 = V_64 [ V_56 -> V_63 ] ;
if ( F_15 ( V_57 >= 0 ) ) {
struct V_54 * V_62 = F_65 ( V_56 , V_57 ) ;
struct V_1 * V_2 = F_72 ( V_49 , V_62 ) ;
V_49 -> V_4 . V_8 -- ;
if ( F_73 ( V_62 ) )
V_56 -> V_63 &= ~ ( 1 << V_57 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_74 ( struct V_3 * V_49 )
{
struct V_55 * V_56 = F_68 ( V_49 ) ;
int V_57 = V_64 [ V_56 -> V_63 ] ;
if ( V_57 >= 0 ) {
struct V_54 * V_62 = F_65 ( V_56 , V_57 ) ;
return F_75 ( V_62 ) ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_49 )
{
int V_65 ;
struct V_55 * V_56 = F_68 ( V_49 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ )
F_77 ( V_49 , F_65 ( V_56 , V_65 ) ) ;
V_56 -> V_63 = 0 ;
V_49 -> V_6 . V_67 = 0 ;
V_49 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_49 , struct V_1 * V_2 )
{
struct V_68 V_52 = { . V_69 = V_66 } ;
memcpy ( & V_52 . V_70 , V_59 , V_61 + 1 ) ;
if ( F_79 ( V_2 , V_71 , sizeof( V_52 ) , & V_52 ) )
goto V_72;
return V_2 -> V_13 ;
V_72:
return - 1 ;
}
static int F_80 ( struct V_3 * V_49 , struct V_51 * V_52 )
{
int V_65 ;
struct V_55 * V_56 = F_68 ( V_49 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ )
F_81 ( F_65 ( V_56 , V_65 ) ) ;
V_49 -> V_20 |= V_73 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_9 * V_18 ,
const struct V_74 * V_75 )
{
void * V_76 ;
struct V_3 * V_77 ;
unsigned int V_78 = F_83 ( sizeof( * V_77 ) ) + V_75 -> V_79 ;
int V_80 = - V_81 ;
struct V_22 * V_19 = V_18 -> V_19 ;
V_76 = F_84 ( V_78 , V_82 ,
F_85 ( V_18 ) ) ;
if ( ! V_76 )
goto V_83;
V_77 = (struct V_3 * ) F_83 ( ( unsigned long ) V_76 ) ;
if ( V_77 != V_76 ) {
F_86 ( V_76 ) ;
V_76 = F_84 ( V_78 + V_84 - 1 , V_82 ,
F_85 ( V_18 ) ) ;
if ( ! V_76 )
goto V_83;
V_77 = (struct V_3 * ) F_83 ( ( unsigned long ) V_76 ) ;
V_77 -> V_85 = ( char * ) V_77 - ( char * ) V_76 ;
}
F_87 ( & V_77 -> V_62 ) ;
F_88 ( & V_77 -> V_4 ) ;
F_89 ( & V_77 -> V_86 ) ;
F_90 ( & V_77 -> V_86 ,
V_19 -> V_87 ? : & V_87 ) ;
V_77 -> V_75 = V_75 ;
V_77 -> V_53 = V_75 -> V_53 ;
V_77 -> V_15 = V_75 -> V_15 ;
V_77 -> V_18 = V_18 ;
F_46 ( V_19 ) ;
F_91 ( & V_77 -> V_88 , 1 ) ;
return V_77 ;
V_83:
return F_92 ( V_80 ) ;
}
struct V_3 * F_93 ( struct V_9 * V_18 ,
const struct V_74 * V_75 ,
unsigned int V_89 )
{
struct V_3 * V_77 ;
if ( ! F_94 ( V_75 -> V_90 ) )
goto V_83;
V_77 = F_82 ( V_18 , V_75 ) ;
if ( F_95 ( V_77 ) )
goto V_83;
V_77 -> V_91 = V_89 ;
if ( ! V_75 -> V_92 || V_75 -> V_92 ( V_77 , NULL ) == 0 )
return V_77 ;
F_96 ( V_77 ) ;
V_83:
return NULL ;
}
void F_97 ( struct V_3 * V_49 )
{
const struct V_74 * V_75 = V_49 -> V_75 ;
if ( V_75 -> V_93 )
V_75 -> V_93 ( V_49 ) ;
if ( V_49 -> V_5 ) {
F_98 ( V_49 -> V_5 ) ;
V_49 -> V_5 = NULL ;
V_49 -> V_4 . V_8 = 0 ;
}
}
static void F_99 ( struct V_94 * V_95 )
{
struct V_3 * V_49 = F_100 ( V_95 , struct V_3 , V_94 ) ;
if ( F_101 ( V_49 ) ) {
F_102 ( V_49 -> V_96 ) ;
F_102 ( V_49 -> V_97 ) ;
}
F_86 ( ( char * ) V_49 - V_49 -> V_85 ) ;
}
void F_96 ( struct V_3 * V_49 )
{
const struct V_74 * V_75 = V_49 -> V_75 ;
if ( V_49 -> V_20 & V_98 ||
! F_103 ( & V_49 -> V_88 ) )
return;
#ifdef F_104
F_105 ( V_49 ) ;
F_106 ( F_107 ( V_49 -> V_99 ) ) ;
#endif
F_108 ( & V_49 -> V_100 , & V_49 -> V_101 ) ;
if ( V_75 -> V_93 )
V_75 -> V_93 ( V_49 ) ;
if ( V_75 -> V_102 )
V_75 -> V_102 ( V_49 ) ;
F_109 ( V_75 -> V_90 ) ;
F_48 ( F_26 ( V_49 ) ) ;
F_98 ( V_49 -> V_5 ) ;
F_110 ( & V_49 -> V_94 , F_99 ) ;
}
struct V_3 * F_111 ( struct V_9 * V_18 ,
struct V_3 * V_49 )
{
struct V_3 * V_103 = V_18 -> V_104 ;
T_1 * V_23 ;
V_23 = F_25 ( V_103 ) ;
F_112 ( V_23 ) ;
if ( V_103 && F_113 ( & V_103 -> V_88 ) <= 1 )
F_97 ( V_103 ) ;
if ( V_49 == NULL )
V_49 = & V_105 ;
V_18 -> V_104 = V_49 ;
F_114 ( V_18 -> V_49 , & V_105 ) ;
F_115 ( V_23 ) ;
return V_103 ;
}
static void F_116 ( struct V_22 * V_19 ,
struct V_9 * V_18 ,
void * V_106 )
{
struct V_3 * V_49 ;
const struct V_74 * V_75 = V_107 ;
if ( V_19 -> V_108 & V_109 )
V_75 = & V_110 ;
V_49 = F_93 ( V_18 , V_75 , V_111 ) ;
if ( ! V_49 ) {
F_117 ( V_19 , L_3 ) ;
return;
}
if ( ! F_118 ( V_19 ) )
V_49 -> V_20 |= V_21 | V_112 ;
V_18 -> V_104 = V_49 ;
}
static void F_119 ( struct V_22 * V_19 )
{
struct V_9 * V_10 ;
struct V_3 * V_49 ;
V_10 = F_33 ( V_19 , 0 ) ;
if ( ! F_118 ( V_19 ) ||
V_19 -> V_108 & V_109 ) {
F_120 ( V_19 , F_116 , NULL ) ;
V_19 -> V_49 = V_10 -> V_104 ;
F_57 ( & V_19 -> V_49 -> V_88 ) ;
} else {
V_49 = F_93 ( V_10 , & V_113 , V_111 ) ;
if ( V_49 ) {
V_19 -> V_49 = V_49 ;
V_49 -> V_75 -> V_114 ( V_49 ) ;
}
}
}
static void F_121 ( struct V_22 * V_19 ,
struct V_9 * V_18 ,
void * V_115 )
{
struct V_3 * V_116 = V_18 -> V_104 ;
int * V_117 = V_115 ;
if ( ! ( V_116 -> V_20 & V_98 ) )
F_122 ( V_118 , & V_116 -> V_45 ) ;
F_114 ( V_18 -> V_49 , V_116 ) ;
if ( V_117 ) {
V_18 -> V_32 = 0 ;
* V_117 = 1 ;
}
}
void F_123 ( struct V_22 * V_19 )
{
int V_119 ;
if ( V_19 -> V_49 == & V_105 )
F_119 ( V_19 ) ;
if ( ! F_40 ( V_19 ) )
return;
V_119 = 0 ;
F_120 ( V_19 , F_121 , & V_119 ) ;
if ( F_124 ( V_19 ) )
F_121 ( V_19 , F_124 ( V_19 ) , NULL ) ;
if ( V_119 ) {
F_125 ( V_19 ) ;
F_50 ( V_19 ) ;
}
}
static void F_126 ( struct V_22 * V_19 ,
struct V_9 * V_18 ,
void * V_120 )
{
struct V_3 * V_121 = V_120 ;
struct V_3 * V_49 ;
V_49 = F_107 ( V_18 -> V_49 ) ;
if ( V_49 ) {
F_112 ( F_25 ( V_49 ) ) ;
if ( ! ( V_49 -> V_20 & V_98 ) )
F_127 ( V_118 , & V_49 -> V_45 ) ;
F_114 ( V_18 -> V_49 , V_121 ) ;
F_97 ( V_49 ) ;
F_115 ( F_25 ( V_49 ) ) ;
}
}
static bool F_128 ( struct V_22 * V_19 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_33 ; V_31 ++ ) {
struct V_9 * V_18 ;
T_1 * V_23 ;
struct V_3 * V_4 ;
int V_29 ;
V_18 = F_33 ( V_19 , V_31 ) ;
V_4 = V_18 -> V_104 ;
V_23 = F_25 ( V_4 ) ;
F_112 ( V_23 ) ;
V_29 = ( F_129 ( V_4 ) ||
F_130 ( V_122 , & V_4 -> V_45 ) ) ;
F_115 ( V_23 ) ;
if ( V_29 )
return true ;
}
return false ;
}
void F_131 ( struct V_123 * V_95 )
{
struct V_22 * V_19 ;
bool V_124 = false ;
F_132 (dev, head, close_list) {
F_120 ( V_19 , F_126 ,
& V_105 ) ;
if ( F_124 ( V_19 ) )
F_126 ( V_19 , F_124 ( V_19 ) ,
& V_105 ) ;
F_51 ( V_19 ) ;
V_124 |= ! V_19 -> V_125 ;
}
if ( V_124 )
F_133 () ;
F_132 (dev, head, close_list)
while ( F_128 ( V_19 ) )
F_134 () ;
}
void F_135 ( struct V_22 * V_19 )
{
F_136 ( V_126 ) ;
F_137 ( & V_19 -> V_127 , & V_126 ) ;
F_131 ( & V_126 ) ;
F_138 ( & V_126 ) ;
}
static void F_139 ( struct V_22 * V_19 ,
struct V_9 * V_18 ,
void * V_128 )
{
struct V_3 * V_49 = V_128 ;
F_114 ( V_18 -> V_49 , V_49 ) ;
V_18 -> V_104 = V_49 ;
}
void F_140 ( struct V_22 * V_19 )
{
V_19 -> V_49 = & V_105 ;
F_120 ( V_19 , F_139 , & V_105 ) ;
if ( F_124 ( V_19 ) )
F_139 ( V_19 , F_124 ( V_19 ) , & V_105 ) ;
F_141 ( & V_19 -> V_42 , F_35 , ( unsigned long ) V_19 ) ;
}
static void F_142 ( struct V_22 * V_19 ,
struct V_9 * V_18 ,
void * V_120 )
{
struct V_3 * V_49 = V_18 -> V_104 ;
struct V_3 * V_121 = V_120 ;
if ( V_49 ) {
F_114 ( V_18 -> V_49 , V_121 ) ;
V_18 -> V_104 = V_121 ;
F_96 ( V_49 ) ;
}
}
void F_143 ( struct V_22 * V_19 )
{
F_120 ( V_19 , F_142 , & V_105 ) ;
if ( F_124 ( V_19 ) )
F_142 ( V_19 , F_124 ( V_19 ) , & V_105 ) ;
F_96 ( V_19 -> V_49 ) ;
V_19 -> V_49 = & V_105 ;
F_144 ( F_145 ( & V_19 -> V_42 ) ) ;
}
void F_146 ( struct V_129 * V_130 ,
const struct V_131 * V_132 ,
T_2 V_133 )
{
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_134 = V_132 -> V_134 ;
V_130 -> V_135 = F_147 ( T_2 , V_132 -> V_136 , V_133 ) ;
V_130 -> V_137 = ( V_132 -> V_137 & V_138 ) ;
V_130 -> V_139 = 1 ;
if ( V_130 -> V_135 > 0 ) {
T_2 V_140 = V_141 ;
for (; ; ) {
V_130 -> V_139 = F_148 ( V_140 , V_130 -> V_135 ) ;
if ( V_130 -> V_139 & ( 1U << 31 ) || V_140 & ( 1ULL << 63 ) )
break;
V_140 <<= 1 ;
V_130 -> V_142 ++ ;
}
}
}
