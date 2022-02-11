static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
V_4 -> V_5 = V_2 ;
V_4 -> V_6 . V_7 ++ ;
V_4 -> V_4 . V_8 ++ ;
F_3 ( V_4 ) ;
return 0 ;
}
static inline struct V_1 * F_4 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_4 -> V_11 ;
if ( F_5 ( V_2 ) ) {
V_10 = F_6 ( V_10 -> V_12 , F_7 ( V_2 ) ) ;
if ( ! F_8 ( V_10 ) ) {
V_4 -> V_5 = NULL ;
V_4 -> V_4 . V_8 -- ;
} else
V_2 = NULL ;
} else {
if ( ! ( V_4 -> V_13 & V_14 ) || ! F_8 ( V_10 ) )
V_2 = V_4 -> V_15 ( V_4 ) ;
}
return V_2 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_11 ,
struct V_3 * V_4 )
{
int V_16 ;
if ( F_5 ( V_11 -> V_17 == F_10 () ) ) {
F_11 ( V_2 ) ;
F_12 ( L_1 ,
V_11 -> V_12 -> V_18 ) ;
V_16 = F_13 ( V_4 ) ;
} else {
F_14 ( V_19 . V_20 ) ;
V_16 = F_1 ( V_2 , V_4 ) ;
}
return V_16 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_21 * V_12 , struct V_9 * V_10 ,
T_1 * V_22 )
{
int V_16 = V_23 ;
F_16 ( V_22 ) ;
F_17 ( V_12 , V_10 , F_10 () ) ;
if ( ! F_8 ( V_10 ) )
V_16 = F_18 ( V_2 , V_12 , V_10 ) ;
F_19 ( V_12 , V_10 ) ;
F_20 ( V_22 ) ;
if ( F_21 ( V_16 ) ) {
V_16 = F_13 ( V_4 ) ;
} else if ( V_16 == V_24 ) {
V_16 = F_9 ( V_2 , V_10 , V_4 ) ;
} else {
if ( F_5 ( V_16 != V_23 ) )
F_12 ( L_2 ,
V_12 -> V_18 , V_16 , V_4 -> V_4 . V_8 ) ;
V_16 = F_1 ( V_2 , V_4 ) ;
}
if ( V_16 && F_8 ( V_10 ) )
V_16 = 0 ;
return V_16 ;
}
static inline int F_22 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_21 * V_12 ;
T_1 * V_22 ;
struct V_1 * V_2 ;
V_2 = F_4 ( V_4 ) ;
if ( F_5 ( ! V_2 ) )
return 0 ;
F_23 ( F_24 ( V_2 ) ) ;
V_22 = F_25 ( V_4 ) ;
V_12 = F_26 ( V_4 ) ;
V_10 = F_6 ( V_12 , F_7 ( V_2 ) ) ;
return F_15 ( V_2 , V_4 , V_12 , V_10 , V_22 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
int V_25 = V_26 ;
while ( F_22 ( V_4 ) ) {
if ( -- V_25 <= 0 || F_28 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_29 ( V_4 ) ;
}
unsigned long F_30 ( struct V_21 * V_12 )
{
unsigned long V_27 , V_28 ;
unsigned int V_29 ;
if ( F_31 ( V_12 ) )
V_12 = F_32 ( V_12 ) ;
V_28 = V_12 -> V_30 ;
for ( V_29 = 0 ; V_29 < V_12 -> V_31 ; V_29 ++ ) {
V_27 = F_6 ( V_12 , V_29 ) -> V_30 ;
if ( V_27 && F_33 ( V_27 , V_28 ) )
V_28 = V_27 ;
}
V_12 -> V_30 = V_28 ;
return V_28 ;
}
static void F_34 ( unsigned long V_32 )
{
struct V_21 * V_12 = (struct V_21 * ) V_32 ;
F_35 ( V_12 ) ;
if ( ! F_36 ( V_12 ) ) {
if ( F_37 ( V_12 ) &&
F_38 ( V_12 ) &&
F_39 ( V_12 ) ) {
int V_33 = 0 ;
unsigned int V_29 ;
unsigned long V_30 ;
for ( V_29 = 0 ; V_29 < V_12 -> V_31 ; V_29 ++ ) {
struct V_9 * V_10 ;
V_10 = F_6 ( V_12 , V_29 ) ;
V_30 = V_10 -> V_30 ? : V_12 -> V_30 ;
if ( F_40 ( V_10 ) &&
F_33 ( V_34 , ( V_30 +
V_12 -> V_35 ) ) ) {
V_33 = 1 ;
V_10 -> V_36 ++ ;
break;
}
}
if ( V_33 ) {
F_41 ( 1 , V_37 L_3 ,
V_12 -> V_18 , F_42 ( V_12 ) , V_29 ) ;
V_12 -> V_38 -> V_39 ( V_12 ) ;
}
if ( ! F_43 ( & V_12 -> V_40 ,
F_44 ( V_34 +
V_12 -> V_35 ) ) )
F_45 ( V_12 ) ;
}
}
F_46 ( V_12 ) ;
F_47 ( V_12 ) ;
}
void F_48 ( struct V_21 * V_12 )
{
if ( V_12 -> V_38 -> V_39 ) {
if ( V_12 -> V_35 <= 0 )
V_12 -> V_35 = 5 * V_41 ;
if ( ! F_43 ( & V_12 -> V_40 ,
F_44 ( V_34 + V_12 -> V_35 ) ) )
F_45 ( V_12 ) ;
}
}
static void F_49 ( struct V_21 * V_12 )
{
F_48 ( V_12 ) ;
}
static void F_50 ( struct V_21 * V_12 )
{
F_51 ( V_12 ) ;
if ( F_52 ( & V_12 -> V_40 ) )
F_47 ( V_12 ) ;
F_53 ( V_12 ) ;
}
void F_54 ( struct V_21 * V_12 )
{
if ( F_55 ( V_42 , & V_12 -> V_43 ) ) {
if ( V_12 -> V_44 == V_45 )
return;
F_56 ( & V_12 -> V_46 ) ;
F_57 ( V_12 ) ;
if ( F_38 ( V_12 ) )
F_48 ( V_12 ) ;
}
}
void F_58 ( struct V_21 * V_12 )
{
if ( ! F_59 ( V_42 , & V_12 -> V_43 ) ) {
if ( V_12 -> V_44 == V_45 )
return;
F_56 ( & V_12 -> V_46 ) ;
F_57 ( V_12 ) ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_3 * V_47 )
{
F_11 ( V_2 ) ;
return V_48 ;
}
static struct V_1 * F_61 ( struct V_3 * V_47 )
{
return NULL ;
}
static inline struct V_49 * F_62 ( struct V_50 * V_51 ,
int V_52 )
{
return V_51 -> V_4 + V_52 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_3 * V_47 )
{
if ( F_64 ( & V_47 -> V_4 ) < F_26 ( V_47 ) -> V_53 ) {
int V_52 = V_54 [ V_2 -> V_55 & V_56 ] ;
struct V_50 * V_51 = F_65 ( V_47 ) ;
struct V_49 * V_57 = F_62 ( V_51 , V_52 ) ;
V_51 -> V_58 |= ( 1 << V_52 ) ;
V_47 -> V_4 . V_8 ++ ;
return F_66 ( V_2 , V_47 , V_57 ) ;
}
return F_67 ( V_2 , V_47 ) ;
}
static struct V_1 * F_68 ( struct V_3 * V_47 )
{
struct V_50 * V_51 = F_65 ( V_47 ) ;
int V_52 = V_59 [ V_51 -> V_58 ] ;
if ( F_69 ( V_52 >= 0 ) ) {
struct V_49 * V_57 = F_62 ( V_51 , V_52 ) ;
struct V_1 * V_2 = F_70 ( V_47 , V_57 ) ;
V_47 -> V_4 . V_8 -- ;
if ( F_71 ( V_57 ) )
V_51 -> V_58 &= ~ ( 1 << V_52 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_72 ( struct V_3 * V_47 )
{
struct V_50 * V_51 = F_65 ( V_47 ) ;
int V_52 = V_59 [ V_51 -> V_58 ] ;
if ( V_52 >= 0 ) {
struct V_49 * V_57 = F_62 ( V_51 , V_52 ) ;
return F_73 ( V_57 ) ;
}
return NULL ;
}
static void F_74 ( struct V_3 * V_47 )
{
int V_60 ;
struct V_50 * V_51 = F_65 ( V_47 ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
F_75 ( V_47 , F_62 ( V_51 , V_60 ) ) ;
V_51 -> V_58 = 0 ;
V_47 -> V_6 . V_62 = 0 ;
V_47 -> V_4 . V_8 = 0 ;
}
static int F_76 ( struct V_3 * V_47 , struct V_1 * V_2 )
{
struct V_63 V_64 = { . V_65 = V_61 } ;
memcpy ( & V_64 . V_66 , V_54 , V_56 + 1 ) ;
if ( F_77 ( V_2 , V_67 , sizeof( V_64 ) , & V_64 ) )
goto V_68;
return V_2 -> V_69 ;
V_68:
return - 1 ;
}
static int F_78 ( struct V_3 * V_47 , struct V_70 * V_64 )
{
int V_60 ;
struct V_50 * V_51 = F_65 ( V_47 ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
F_79 ( F_62 ( V_51 , V_60 ) ) ;
V_47 -> V_13 |= V_71 ;
return 0 ;
}
struct V_3 * F_80 ( struct V_9 * V_11 ,
const struct V_72 * V_73 )
{
void * V_74 ;
struct V_3 * V_75 ;
unsigned int V_76 = F_81 ( sizeof( * V_75 ) ) + V_73 -> V_77 ;
int V_78 = - V_79 ;
struct V_21 * V_12 = V_11 -> V_12 ;
V_74 = F_82 ( V_76 , V_80 ,
F_83 ( V_11 ) ) ;
if ( ! V_74 )
goto V_81;
V_75 = (struct V_3 * ) F_81 ( ( unsigned long ) V_74 ) ;
if ( V_75 != V_74 ) {
F_84 ( V_74 ) ;
V_74 = F_82 ( V_76 + V_82 - 1 , V_80 ,
F_83 ( V_11 ) ) ;
if ( ! V_74 )
goto V_81;
V_75 = (struct V_3 * ) F_81 ( ( unsigned long ) V_74 ) ;
V_75 -> V_83 = ( char * ) V_75 - ( char * ) V_74 ;
}
F_85 ( & V_75 -> V_57 ) ;
F_79 ( & V_75 -> V_4 ) ;
F_86 ( & V_75 -> V_84 ) ;
F_87 ( & V_75 -> V_84 ,
V_12 -> V_85 ? : & V_85 ) ;
V_75 -> V_73 = V_73 ;
V_75 -> V_86 = V_73 -> V_86 ;
V_75 -> V_15 = V_73 -> V_15 ;
V_75 -> V_11 = V_11 ;
F_45 ( V_12 ) ;
F_88 ( & V_75 -> V_87 , 1 ) ;
return V_75 ;
V_81:
return F_89 ( V_78 ) ;
}
struct V_3 * F_90 ( struct V_9 * V_11 ,
const struct V_72 * V_73 ,
unsigned int V_88 )
{
struct V_3 * V_75 ;
if ( ! F_91 ( V_73 -> V_89 ) )
goto V_81;
V_75 = F_80 ( V_11 , V_73 ) ;
if ( F_92 ( V_75 ) )
goto V_81;
V_75 -> V_90 = V_88 ;
if ( ! V_73 -> V_91 || V_73 -> V_91 ( V_75 , NULL ) == 0 )
return V_75 ;
F_93 ( V_75 ) ;
V_81:
return NULL ;
}
void F_94 ( struct V_3 * V_47 )
{
const struct V_72 * V_73 = V_47 -> V_73 ;
if ( V_73 -> V_92 )
V_73 -> V_92 ( V_47 ) ;
if ( V_47 -> V_5 ) {
F_11 ( V_47 -> V_5 ) ;
V_47 -> V_5 = NULL ;
V_47 -> V_4 . V_8 = 0 ;
}
}
static void F_95 ( struct V_93 * V_94 )
{
struct V_3 * V_47 = F_96 ( V_94 , struct V_3 , V_93 ) ;
F_84 ( ( char * ) V_47 - V_47 -> V_83 ) ;
}
void F_93 ( struct V_3 * V_47 )
{
const struct V_72 * V_73 = V_47 -> V_73 ;
if ( V_47 -> V_13 & V_95 ||
! F_97 ( & V_47 -> V_87 ) )
return;
#ifdef F_98
F_99 ( V_47 ) ;
F_100 ( F_101 ( V_47 -> V_96 ) ) ;
#endif
F_102 ( & V_47 -> V_97 , & V_47 -> V_98 ) ;
if ( V_73 -> V_92 )
V_73 -> V_92 ( V_47 ) ;
if ( V_73 -> V_99 )
V_73 -> V_99 ( V_47 ) ;
F_103 ( V_73 -> V_89 ) ;
F_47 ( F_26 ( V_47 ) ) ;
F_11 ( V_47 -> V_5 ) ;
F_104 ( & V_47 -> V_93 , F_95 ) ;
}
struct V_3 * F_105 ( struct V_9 * V_11 ,
struct V_3 * V_47 )
{
struct V_3 * V_100 = V_11 -> V_101 ;
T_1 * V_22 ;
V_22 = F_25 ( V_100 ) ;
F_106 ( V_22 ) ;
if ( V_100 && F_107 ( & V_100 -> V_87 ) <= 1 )
F_94 ( V_100 ) ;
if ( V_47 == NULL )
V_47 = & V_102 ;
V_11 -> V_101 = V_47 ;
F_108 ( V_11 -> V_47 , & V_102 ) ;
F_109 ( V_22 ) ;
return V_100 ;
}
static void F_110 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_103 )
{
struct V_3 * V_47 = & V_104 ;
if ( V_12 -> V_53 ) {
V_47 = F_90 ( V_11 ,
V_105 , V_106 ) ;
if ( ! V_47 ) {
F_111 ( V_12 , L_4 ) ;
return;
}
if ( ! F_112 ( V_12 ) )
V_47 -> V_13 |= V_14 ;
}
V_11 -> V_101 = V_47 ;
}
static void F_113 ( struct V_21 * V_12 )
{
struct V_9 * V_10 ;
struct V_3 * V_47 ;
V_10 = F_6 ( V_12 , 0 ) ;
if ( ! F_112 ( V_12 ) || V_12 -> V_53 == 0 ) {
F_114 ( V_12 , F_110 , NULL ) ;
V_12 -> V_47 = V_10 -> V_101 ;
F_56 ( & V_12 -> V_47 -> V_87 ) ;
} else {
V_47 = F_90 ( V_10 , & V_107 , V_106 ) ;
if ( V_47 ) {
V_12 -> V_47 = V_47 ;
V_47 -> V_73 -> V_108 ( V_47 ) ;
}
}
}
static void F_115 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_109 )
{
struct V_3 * V_110 = V_11 -> V_101 ;
int * V_111 = V_109 ;
if ( ! ( V_110 -> V_13 & V_95 ) )
F_116 ( V_112 , & V_110 -> V_43 ) ;
F_108 ( V_11 -> V_47 , V_110 ) ;
if ( V_111 && V_110 != & V_104 ) {
V_11 -> V_30 = 0 ;
* V_111 = 1 ;
}
}
void F_117 ( struct V_21 * V_12 )
{
int V_113 ;
if ( V_12 -> V_47 == & V_102 )
F_113 ( V_12 ) ;
if ( ! F_39 ( V_12 ) )
return;
V_113 = 0 ;
F_114 ( V_12 , F_115 , & V_113 ) ;
if ( F_118 ( V_12 ) )
F_115 ( V_12 , F_118 ( V_12 ) , NULL ) ;
if ( V_113 ) {
V_12 -> V_30 = V_34 ;
F_49 ( V_12 ) ;
}
}
static void F_119 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_114 )
{
struct V_3 * V_115 = V_114 ;
struct V_3 * V_47 ;
V_47 = V_11 -> V_47 ;
if ( V_47 ) {
F_106 ( F_25 ( V_47 ) ) ;
if ( ! ( V_47 -> V_13 & V_95 ) )
F_120 ( V_112 , & V_47 -> V_43 ) ;
F_108 ( V_11 -> V_47 , V_115 ) ;
F_94 ( V_47 ) ;
F_109 ( F_25 ( V_47 ) ) ;
}
}
static bool F_121 ( struct V_21 * V_12 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_12 -> V_31 ; V_29 ++ ) {
struct V_9 * V_11 ;
T_1 * V_22 ;
struct V_3 * V_4 ;
int V_27 ;
V_11 = F_6 ( V_12 , V_29 ) ;
V_4 = V_11 -> V_101 ;
V_22 = F_25 ( V_4 ) ;
F_106 ( V_22 ) ;
V_27 = ( F_122 ( V_4 ) ||
F_123 ( V_116 , & V_4 -> V_43 ) ) ;
F_109 ( V_22 ) ;
if ( V_27 )
return true ;
}
return false ;
}
void F_124 ( struct V_117 * V_94 )
{
struct V_21 * V_12 ;
bool V_118 = false ;
F_125 (dev, head, close_list) {
F_114 ( V_12 , F_119 ,
& V_102 ) ;
if ( F_118 ( V_12 ) )
F_119 ( V_12 , F_118 ( V_12 ) ,
& V_102 ) ;
F_50 ( V_12 ) ;
V_118 |= ! V_12 -> V_119 ;
}
if ( V_118 )
F_126 () ;
F_125 (dev, head, close_list)
while ( F_121 ( V_12 ) )
F_127 () ;
}
void F_128 ( struct V_21 * V_12 )
{
F_129 ( V_120 ) ;
F_130 ( & V_12 -> V_121 , & V_120 ) ;
F_124 ( & V_120 ) ;
F_131 ( & V_120 ) ;
}
static void F_132 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_122 )
{
struct V_3 * V_47 = V_122 ;
V_11 -> V_47 = V_47 ;
V_11 -> V_101 = V_47 ;
}
void F_133 ( struct V_21 * V_12 )
{
V_12 -> V_47 = & V_102 ;
F_114 ( V_12 , F_132 , & V_102 ) ;
if ( F_118 ( V_12 ) )
F_132 ( V_12 , F_118 ( V_12 ) , & V_102 ) ;
F_134 ( & V_12 -> V_40 , F_34 , ( unsigned long ) V_12 ) ;
}
static void F_135 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_114 )
{
struct V_3 * V_47 = V_11 -> V_101 ;
struct V_3 * V_115 = V_114 ;
if ( V_47 ) {
F_108 ( V_11 -> V_47 , V_115 ) ;
V_11 -> V_101 = V_115 ;
F_93 ( V_47 ) ;
}
}
void F_136 ( struct V_21 * V_12 )
{
F_114 ( V_12 , F_135 , & V_102 ) ;
if ( F_118 ( V_12 ) )
F_135 ( V_12 , F_118 ( V_12 ) , & V_102 ) ;
F_93 ( V_12 -> V_47 ) ;
V_12 -> V_47 = & V_102 ;
F_137 ( F_138 ( & V_12 -> V_40 ) ) ;
}
void F_139 ( struct V_123 * V_124 ,
const struct V_125 * V_126 ,
T_2 V_127 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_128 = V_126 -> V_128 ;
V_124 -> V_129 = F_140 ( T_2 , V_126 -> V_130 , V_127 ) ;
V_124 -> V_131 = ( V_126 -> V_131 & V_132 ) ;
V_124 -> V_133 = 1 ;
if ( V_124 -> V_129 > 0 ) {
T_2 V_134 = V_135 ;
for (; ; ) {
V_124 -> V_133 = F_141 ( V_134 , V_124 -> V_129 ) ;
if ( V_124 -> V_133 & ( 1U << 31 ) || V_134 & ( 1ULL << 63 ) )
break;
V_134 <<= 1 ;
V_124 -> V_136 ++ ;
}
}
}
