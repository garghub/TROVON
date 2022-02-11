static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 ;
V_4 -> V_6 . V_7 ++ ;
V_4 -> V_4 . V_8 ++ ;
F_2 ( V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
const struct V_9 * V_10 ,
int * V_11 )
{
int V_12 = F_4 ( V_10 ) - V_2 -> V_13 ;
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
static struct V_1 * F_5 ( struct V_3 * V_4 , bool * V_17 ,
int * V_11 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_4 -> V_18 ;
* V_11 = 1 ;
* V_17 = true ;
if ( F_6 ( V_2 ) ) {
V_10 = F_7 ( V_10 -> V_19 , V_2 ) ;
if ( ! F_8 ( V_10 ) ) {
V_4 -> V_5 = NULL ;
V_4 -> V_4 . V_8 -- ;
} else
V_2 = NULL ;
* V_17 = false ;
} else {
if ( ! ( V_4 -> V_20 & V_21 ) ||
! F_8 ( V_10 ) ) {
V_2 = V_4 -> V_15 ( V_4 ) ;
if ( V_2 && F_9 ( V_4 ) )
F_3 ( V_4 , V_2 , V_10 , V_11 ) ;
}
}
return V_2 ;
}
static inline int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_18 ,
struct V_3 * V_4 )
{
int V_22 ;
if ( F_6 ( V_18 -> V_23 == F_11 () ) ) {
F_12 ( V_2 ) ;
F_13 ( L_1 ,
V_18 -> V_19 -> V_24 ) ;
V_22 = F_14 ( V_4 ) ;
} else {
F_15 ( V_25 . V_26 ) ;
V_22 = F_1 ( V_2 , V_4 ) ;
}
return V_22 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_27 * V_19 , struct V_9 * V_10 ,
T_1 * V_28 , bool V_17 )
{
int V_22 = V_29 ;
F_17 ( V_28 ) ;
if ( V_17 )
V_2 = F_18 ( V_2 , V_19 ) ;
if ( V_2 ) {
F_19 ( V_19 , V_10 , F_11 () ) ;
if ( ! F_8 ( V_10 ) )
V_2 = F_20 ( V_2 , V_19 , V_10 , & V_22 ) ;
F_21 ( V_19 , V_10 ) ;
}
F_22 ( V_28 ) ;
if ( F_23 ( V_22 ) ) {
V_22 = F_14 ( V_4 ) ;
} else if ( V_22 == V_30 ) {
V_22 = F_10 ( V_2 , V_10 , V_4 ) ;
} else {
if ( F_6 ( V_22 != V_29 ) )
F_13 ( L_2 ,
V_19 -> V_24 , V_22 , V_4 -> V_4 . V_8 ) ;
V_22 = F_1 ( V_2 , V_4 ) ;
}
if ( V_22 && F_8 ( V_10 ) )
V_22 = 0 ;
return V_22 ;
}
static inline int F_24 ( struct V_3 * V_4 , int * V_11 )
{
struct V_9 * V_10 ;
struct V_27 * V_19 ;
T_1 * V_28 ;
struct V_1 * V_2 ;
bool V_17 ;
V_2 = F_5 ( V_4 , & V_17 , V_11 ) ;
if ( F_6 ( ! V_2 ) )
return 0 ;
V_28 = F_25 ( V_4 ) ;
V_19 = F_26 ( V_4 ) ;
V_10 = F_7 ( V_19 , V_2 ) ;
return F_16 ( V_2 , V_4 , V_19 , V_10 , V_28 , V_17 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
int V_31 = V_32 ;
int V_11 ;
while ( F_24 ( V_4 , & V_11 ) ) {
V_31 -= V_11 ;
if ( V_31 <= 0 || F_28 () ) {
F_2 ( V_4 ) ;
break;
}
}
F_29 ( V_4 ) ;
}
unsigned long F_30 ( struct V_27 * V_19 )
{
unsigned long V_33 , V_34 ;
unsigned int V_35 ;
if ( F_31 ( V_19 ) )
V_19 = F_32 ( V_19 ) ;
V_34 = V_19 -> V_36 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
V_33 = F_33 ( V_19 , V_35 ) -> V_36 ;
if ( V_33 && F_34 ( V_33 , V_34 ) )
V_34 = V_33 ;
}
V_19 -> V_36 = V_34 ;
return V_34 ;
}
static void F_35 ( unsigned long V_38 )
{
struct V_27 * V_19 = (struct V_27 * ) V_38 ;
F_36 ( V_19 ) ;
if ( ! F_37 ( V_19 ) ) {
if ( F_38 ( V_19 ) &&
F_39 ( V_19 ) &&
F_40 ( V_19 ) ) {
int V_39 = 0 ;
unsigned int V_35 ;
unsigned long V_36 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
struct V_9 * V_10 ;
V_10 = F_33 ( V_19 , V_35 ) ;
V_36 = V_10 -> V_36 ? : V_19 -> V_36 ;
if ( F_41 ( V_10 ) &&
F_34 ( V_40 , ( V_36 +
V_19 -> V_41 ) ) ) {
V_39 = 1 ;
V_10 -> V_42 ++ ;
break;
}
}
if ( V_39 ) {
F_42 ( 1 , V_43 L_3 ,
V_19 -> V_24 , F_43 ( V_19 ) , V_35 ) ;
V_19 -> V_44 -> V_45 ( V_19 ) ;
}
if ( ! F_44 ( & V_19 -> V_46 ,
F_45 ( V_40 +
V_19 -> V_41 ) ) )
F_46 ( V_19 ) ;
}
}
F_47 ( V_19 ) ;
F_48 ( V_19 ) ;
}
void F_49 ( struct V_27 * V_19 )
{
if ( V_19 -> V_44 -> V_45 ) {
if ( V_19 -> V_41 <= 0 )
V_19 -> V_41 = 5 * V_47 ;
if ( ! F_44 ( & V_19 -> V_46 ,
F_45 ( V_40 + V_19 -> V_41 ) ) )
F_46 ( V_19 ) ;
}
}
static void F_50 ( struct V_27 * V_19 )
{
F_49 ( V_19 ) ;
}
static void F_51 ( struct V_27 * V_19 )
{
F_52 ( V_19 ) ;
if ( F_53 ( & V_19 -> V_46 ) )
F_48 ( V_19 ) ;
F_54 ( V_19 ) ;
}
void F_55 ( struct V_27 * V_19 )
{
if ( F_56 ( V_48 , & V_19 -> V_49 ) ) {
if ( V_19 -> V_50 == V_51 )
return;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( V_19 ) ;
if ( F_39 ( V_19 ) )
F_49 ( V_19 ) ;
}
}
void F_59 ( struct V_27 * V_19 )
{
if ( ! F_60 ( V_48 , & V_19 -> V_49 ) ) {
if ( V_19 -> V_50 == V_51 )
return;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( V_19 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_53 )
{
F_62 ( V_2 ) ;
return V_54 ;
}
static struct V_1 * F_63 ( struct V_3 * V_53 )
{
return NULL ;
}
static inline struct V_55 * F_64 ( struct V_56 * V_57 ,
int V_58 )
{
return V_57 -> V_4 + V_58 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_3 * V_53 )
{
if ( F_66 ( & V_53 -> V_4 ) < F_26 ( V_53 ) -> V_59 ) {
int V_58 = V_60 [ V_2 -> V_61 & V_62 ] ;
struct V_56 * V_57 = F_67 ( V_53 ) ;
struct V_55 * V_63 = F_64 ( V_57 , V_58 ) ;
V_57 -> V_64 |= ( 1 << V_58 ) ;
V_53 -> V_4 . V_8 ++ ;
return F_68 ( V_2 , V_53 , V_63 ) ;
}
return F_69 ( V_2 , V_53 ) ;
}
static struct V_1 * F_70 ( struct V_3 * V_53 )
{
struct V_56 * V_57 = F_67 ( V_53 ) ;
int V_58 = V_65 [ V_57 -> V_64 ] ;
if ( F_71 ( V_58 >= 0 ) ) {
struct V_55 * V_63 = F_64 ( V_57 , V_58 ) ;
struct V_1 * V_2 = F_72 ( V_53 , V_63 ) ;
V_53 -> V_4 . V_8 -- ;
if ( F_73 ( V_63 ) )
V_57 -> V_64 &= ~ ( 1 << V_58 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_74 ( struct V_3 * V_53 )
{
struct V_56 * V_57 = F_67 ( V_53 ) ;
int V_58 = V_65 [ V_57 -> V_64 ] ;
if ( V_58 >= 0 ) {
struct V_55 * V_63 = F_64 ( V_57 , V_58 ) ;
return F_75 ( V_63 ) ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_53 )
{
int V_66 ;
struct V_56 * V_57 = F_67 ( V_53 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ )
F_77 ( V_53 , F_64 ( V_57 , V_66 ) ) ;
V_57 -> V_64 = 0 ;
V_53 -> V_6 . V_68 = 0 ;
V_53 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_53 , struct V_1 * V_2 )
{
struct V_69 V_70 = { . V_71 = V_67 } ;
memcpy ( & V_70 . V_72 , V_60 , V_62 + 1 ) ;
if ( F_79 ( V_2 , V_73 , sizeof( V_70 ) , & V_70 ) )
goto V_74;
return V_2 -> V_13 ;
V_74:
return - 1 ;
}
static int F_80 ( struct V_3 * V_53 , struct V_75 * V_70 )
{
int V_66 ;
struct V_56 * V_57 = F_67 ( V_53 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ )
F_81 ( F_64 ( V_57 , V_66 ) ) ;
V_53 -> V_20 |= V_76 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_9 * V_18 ,
const struct V_77 * V_78 )
{
void * V_79 ;
struct V_3 * V_80 ;
unsigned int V_81 = F_83 ( sizeof( * V_80 ) ) + V_78 -> V_82 ;
int V_83 = - V_84 ;
struct V_27 * V_19 = V_18 -> V_19 ;
V_79 = F_84 ( V_81 , V_85 ,
F_85 ( V_18 ) ) ;
if ( ! V_79 )
goto V_86;
V_80 = (struct V_3 * ) F_83 ( ( unsigned long ) V_79 ) ;
if ( V_80 != V_79 ) {
F_86 ( V_79 ) ;
V_79 = F_84 ( V_81 + V_87 - 1 , V_85 ,
F_85 ( V_18 ) ) ;
if ( ! V_79 )
goto V_86;
V_80 = (struct V_3 * ) F_83 ( ( unsigned long ) V_79 ) ;
V_80 -> V_88 = ( char * ) V_80 - ( char * ) V_79 ;
}
F_87 ( & V_80 -> V_63 ) ;
F_88 ( & V_80 -> V_4 ) ;
F_89 ( & V_80 -> V_89 ) ;
F_90 ( & V_80 -> V_89 ,
V_19 -> V_90 ? : & V_90 ) ;
V_80 -> V_78 = V_78 ;
V_80 -> V_91 = V_78 -> V_91 ;
V_80 -> V_15 = V_78 -> V_15 ;
V_80 -> V_18 = V_18 ;
F_46 ( V_19 ) ;
F_91 ( & V_80 -> V_92 , 1 ) ;
return V_80 ;
V_86:
return F_92 ( V_83 ) ;
}
struct V_3 * F_93 ( struct V_9 * V_18 ,
const struct V_77 * V_78 ,
unsigned int V_93 )
{
struct V_3 * V_80 ;
if ( ! F_94 ( V_78 -> V_94 ) )
goto V_86;
V_80 = F_82 ( V_18 , V_78 ) ;
if ( F_95 ( V_80 ) )
goto V_86;
V_80 -> V_95 = V_93 ;
if ( ! V_78 -> V_96 || V_78 -> V_96 ( V_80 , NULL ) == 0 )
return V_80 ;
F_96 ( V_80 ) ;
V_86:
return NULL ;
}
void F_97 ( struct V_3 * V_53 )
{
const struct V_77 * V_78 = V_53 -> V_78 ;
if ( V_78 -> V_97 )
V_78 -> V_97 ( V_53 ) ;
if ( V_53 -> V_5 ) {
F_12 ( V_53 -> V_5 ) ;
V_53 -> V_5 = NULL ;
V_53 -> V_4 . V_8 = 0 ;
}
}
static void F_98 ( struct V_98 * V_99 )
{
struct V_3 * V_53 = F_99 ( V_99 , struct V_3 , V_98 ) ;
if ( F_100 ( V_53 ) )
F_101 ( V_53 -> V_100 ) ;
F_86 ( ( char * ) V_53 - V_53 -> V_88 ) ;
}
void F_96 ( struct V_3 * V_53 )
{
const struct V_77 * V_78 = V_53 -> V_78 ;
if ( V_53 -> V_20 & V_101 ||
! F_102 ( & V_53 -> V_92 ) )
return;
#ifdef F_103
F_104 ( V_53 ) ;
F_105 ( F_106 ( V_53 -> V_102 ) ) ;
#endif
F_107 ( & V_53 -> V_103 , & V_53 -> V_104 ) ;
if ( V_78 -> V_97 )
V_78 -> V_97 ( V_53 ) ;
if ( V_78 -> V_105 )
V_78 -> V_105 ( V_53 ) ;
F_108 ( V_78 -> V_94 ) ;
F_48 ( F_26 ( V_53 ) ) ;
F_12 ( V_53 -> V_5 ) ;
F_109 ( & V_53 -> V_98 , F_98 ) ;
}
struct V_3 * F_110 ( struct V_9 * V_18 ,
struct V_3 * V_53 )
{
struct V_3 * V_106 = V_18 -> V_107 ;
T_1 * V_28 ;
V_28 = F_25 ( V_106 ) ;
F_111 ( V_28 ) ;
if ( V_106 && F_112 ( & V_106 -> V_92 ) <= 1 )
F_97 ( V_106 ) ;
if ( V_53 == NULL )
V_53 = & V_108 ;
V_18 -> V_107 = V_53 ;
F_113 ( V_18 -> V_53 , & V_108 ) ;
F_114 ( V_28 ) ;
return V_106 ;
}
static void F_115 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_109 )
{
struct V_3 * V_53 = & V_110 ;
if ( V_19 -> V_59 ) {
V_53 = F_93 ( V_18 ,
V_111 , V_112 ) ;
if ( ! V_53 ) {
F_116 ( V_19 , L_4 ) ;
return;
}
if ( ! F_117 ( V_19 ) )
V_53 -> V_20 |= V_21 ;
}
V_18 -> V_107 = V_53 ;
}
static void F_118 ( struct V_27 * V_19 )
{
struct V_9 * V_10 ;
struct V_3 * V_53 ;
V_10 = F_33 ( V_19 , 0 ) ;
if ( ! F_117 ( V_19 ) || V_19 -> V_59 == 0 ) {
F_119 ( V_19 , F_115 , NULL ) ;
V_19 -> V_53 = V_10 -> V_107 ;
F_57 ( & V_19 -> V_53 -> V_92 ) ;
} else {
V_53 = F_93 ( V_10 , & V_113 , V_112 ) ;
if ( V_53 ) {
V_19 -> V_53 = V_53 ;
V_53 -> V_78 -> V_114 ( V_53 ) ;
}
}
}
static void F_120 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_115 )
{
struct V_3 * V_116 = V_18 -> V_107 ;
int * V_117 = V_115 ;
if ( ! ( V_116 -> V_20 & V_101 ) )
F_121 ( V_118 , & V_116 -> V_49 ) ;
F_113 ( V_18 -> V_53 , V_116 ) ;
if ( V_117 && V_116 != & V_110 ) {
V_18 -> V_36 = 0 ;
* V_117 = 1 ;
}
}
void F_122 ( struct V_27 * V_19 )
{
int V_119 ;
if ( V_19 -> V_53 == & V_108 )
F_118 ( V_19 ) ;
if ( ! F_40 ( V_19 ) )
return;
V_119 = 0 ;
F_119 ( V_19 , F_120 , & V_119 ) ;
if ( F_123 ( V_19 ) )
F_120 ( V_19 , F_123 ( V_19 ) , NULL ) ;
if ( V_119 ) {
V_19 -> V_36 = V_40 ;
F_50 ( V_19 ) ;
}
}
static void F_124 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_120 )
{
struct V_3 * V_121 = V_120 ;
struct V_3 * V_53 ;
V_53 = F_106 ( V_18 -> V_53 ) ;
if ( V_53 ) {
F_111 ( F_25 ( V_53 ) ) ;
if ( ! ( V_53 -> V_20 & V_101 ) )
F_125 ( V_118 , & V_53 -> V_49 ) ;
F_113 ( V_18 -> V_53 , V_121 ) ;
F_97 ( V_53 ) ;
F_114 ( F_25 ( V_53 ) ) ;
}
}
static bool F_126 ( struct V_27 * V_19 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
struct V_9 * V_18 ;
T_1 * V_28 ;
struct V_3 * V_4 ;
int V_33 ;
V_18 = F_33 ( V_19 , V_35 ) ;
V_4 = V_18 -> V_107 ;
V_28 = F_25 ( V_4 ) ;
F_111 ( V_28 ) ;
V_33 = ( F_127 ( V_4 ) ||
F_128 ( V_122 , & V_4 -> V_49 ) ) ;
F_114 ( V_28 ) ;
if ( V_33 )
return true ;
}
return false ;
}
void F_129 ( struct V_123 * V_99 )
{
struct V_27 * V_19 ;
bool V_124 = false ;
F_130 (dev, head, close_list) {
F_119 ( V_19 , F_124 ,
& V_108 ) ;
if ( F_123 ( V_19 ) )
F_124 ( V_19 , F_123 ( V_19 ) ,
& V_108 ) ;
F_51 ( V_19 ) ;
V_124 |= ! V_19 -> V_125 ;
}
if ( V_124 )
F_131 () ;
F_130 (dev, head, close_list)
while ( F_126 ( V_19 ) )
F_132 () ;
}
void F_133 ( struct V_27 * V_19 )
{
F_134 ( V_126 ) ;
F_135 ( & V_19 -> V_127 , & V_126 ) ;
F_129 ( & V_126 ) ;
F_136 ( & V_126 ) ;
}
static void F_137 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_128 )
{
struct V_3 * V_53 = V_128 ;
F_113 ( V_18 -> V_53 , V_53 ) ;
V_18 -> V_107 = V_53 ;
}
void F_138 ( struct V_27 * V_19 )
{
V_19 -> V_53 = & V_108 ;
F_119 ( V_19 , F_137 , & V_108 ) ;
if ( F_123 ( V_19 ) )
F_137 ( V_19 , F_123 ( V_19 ) , & V_108 ) ;
F_139 ( & V_19 -> V_46 , F_35 , ( unsigned long ) V_19 ) ;
}
static void F_140 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_120 )
{
struct V_3 * V_53 = V_18 -> V_107 ;
struct V_3 * V_121 = V_120 ;
if ( V_53 ) {
F_113 ( V_18 -> V_53 , V_121 ) ;
V_18 -> V_107 = V_121 ;
F_96 ( V_53 ) ;
}
}
void F_141 ( struct V_27 * V_19 )
{
F_119 ( V_19 , F_140 , & V_108 ) ;
if ( F_123 ( V_19 ) )
F_140 ( V_19 , F_123 ( V_19 ) , & V_108 ) ;
F_96 ( V_19 -> V_53 ) ;
V_19 -> V_53 = & V_108 ;
F_142 ( F_143 ( & V_19 -> V_46 ) ) ;
}
void F_144 ( struct V_129 * V_130 ,
const struct V_131 * V_132 ,
T_2 V_133 )
{
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_134 = V_132 -> V_134 ;
V_130 -> V_135 = F_145 ( T_2 , V_132 -> V_136 , V_133 ) ;
V_130 -> V_137 = ( V_132 -> V_137 & V_138 ) ;
V_130 -> V_139 = 1 ;
if ( V_130 -> V_135 > 0 ) {
T_2 V_140 = V_141 ;
for (; ; ) {
V_130 -> V_139 = F_146 ( V_140 , V_130 -> V_135 ) ;
if ( V_130 -> V_139 & ( 1U << 31 ) || V_140 & ( 1ULL << 63 ) )
break;
V_140 <<= 1 ;
V_130 -> V_142 ++ ;
}
}
}
