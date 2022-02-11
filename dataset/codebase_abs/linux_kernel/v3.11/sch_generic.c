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
F_56 ( V_12 ) ;
if ( F_38 ( V_12 ) )
F_48 ( V_12 ) ;
}
}
void F_57 ( struct V_21 * V_12 )
{
if ( ! F_58 ( V_42 , & V_12 -> V_43 ) ) {
if ( V_12 -> V_44 == V_45 )
return;
F_56 ( V_12 ) ;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_3 * V_46 )
{
F_11 ( V_2 ) ;
return V_47 ;
}
static struct V_1 * F_60 ( struct V_3 * V_46 )
{
return NULL ;
}
static inline struct V_48 * F_61 ( struct V_49 * V_50 ,
int V_51 )
{
return V_50 -> V_4 + V_51 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_46 )
{
if ( F_63 ( & V_46 -> V_4 ) < F_26 ( V_46 ) -> V_52 ) {
int V_51 = V_53 [ V_2 -> V_54 & V_55 ] ;
struct V_49 * V_50 = F_64 ( V_46 ) ;
struct V_48 * V_56 = F_61 ( V_50 , V_51 ) ;
V_50 -> V_57 |= ( 1 << V_51 ) ;
V_46 -> V_4 . V_8 ++ ;
return F_65 ( V_2 , V_46 , V_56 ) ;
}
return F_66 ( V_2 , V_46 ) ;
}
static struct V_1 * F_67 ( struct V_3 * V_46 )
{
struct V_49 * V_50 = F_64 ( V_46 ) ;
int V_51 = V_58 [ V_50 -> V_57 ] ;
if ( F_68 ( V_51 >= 0 ) ) {
struct V_48 * V_56 = F_61 ( V_50 , V_51 ) ;
struct V_1 * V_2 = F_69 ( V_46 , V_56 ) ;
V_46 -> V_4 . V_8 -- ;
if ( F_70 ( V_56 ) )
V_50 -> V_57 &= ~ ( 1 << V_51 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_71 ( struct V_3 * V_46 )
{
struct V_49 * V_50 = F_64 ( V_46 ) ;
int V_51 = V_58 [ V_50 -> V_57 ] ;
if ( V_51 >= 0 ) {
struct V_48 * V_56 = F_61 ( V_50 , V_51 ) ;
return F_72 ( V_56 ) ;
}
return NULL ;
}
static void F_73 ( struct V_3 * V_46 )
{
int V_59 ;
struct V_49 * V_50 = F_64 ( V_46 ) ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ )
F_74 ( V_46 , F_61 ( V_50 , V_59 ) ) ;
V_50 -> V_57 = 0 ;
V_46 -> V_6 . V_61 = 0 ;
V_46 -> V_4 . V_8 = 0 ;
}
static int F_75 ( struct V_3 * V_46 , struct V_1 * V_2 )
{
struct V_62 V_63 = { . V_64 = V_60 } ;
memcpy ( & V_63 . V_65 , V_53 , V_55 + 1 ) ;
if ( F_76 ( V_2 , V_66 , sizeof( V_63 ) , & V_63 ) )
goto V_67;
return V_2 -> V_68 ;
V_67:
return - 1 ;
}
static int F_77 ( struct V_3 * V_46 , struct V_69 * V_63 )
{
int V_59 ;
struct V_49 * V_50 = F_64 ( V_46 ) ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ )
F_78 ( F_61 ( V_50 , V_59 ) ) ;
V_46 -> V_13 |= V_70 ;
return 0 ;
}
struct V_3 * F_79 ( struct V_9 * V_11 ,
struct V_71 * V_72 )
{
void * V_73 ;
struct V_3 * V_74 ;
unsigned int V_75 = F_80 ( sizeof( * V_74 ) ) + V_72 -> V_76 ;
int V_77 = - V_78 ;
struct V_21 * V_12 = V_11 -> V_12 ;
V_73 = F_81 ( V_75 , V_79 ,
F_82 ( V_11 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_80 ( ( unsigned long ) V_73 ) ;
if ( V_74 != V_73 ) {
F_83 ( V_73 ) ;
V_73 = F_81 ( V_75 + V_81 - 1 , V_79 ,
F_82 ( V_11 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_80 ( ( unsigned long ) V_73 ) ;
V_74 -> V_82 = ( char * ) V_74 - ( char * ) V_73 ;
}
F_84 ( & V_74 -> V_56 ) ;
F_78 ( & V_74 -> V_4 ) ;
F_85 ( & V_74 -> V_83 ) ;
F_86 ( & V_74 -> V_83 ,
V_12 -> V_84 ? : & V_84 ) ;
V_74 -> V_72 = V_72 ;
V_74 -> V_85 = V_72 -> V_85 ;
V_74 -> V_15 = V_72 -> V_15 ;
V_74 -> V_11 = V_11 ;
F_45 ( V_12 ) ;
F_87 ( & V_74 -> V_86 , 1 ) ;
return V_74 ;
V_80:
return F_88 ( V_77 ) ;
}
struct V_3 * F_89 ( struct V_9 * V_11 ,
struct V_71 * V_72 , unsigned int V_87 )
{
struct V_3 * V_74 ;
V_74 = F_79 ( V_11 , V_72 ) ;
if ( F_90 ( V_74 ) )
goto V_80;
V_74 -> V_88 = V_87 ;
if ( ! V_72 -> V_89 || V_72 -> V_89 ( V_74 , NULL ) == 0 )
return V_74 ;
F_91 ( V_74 ) ;
V_80:
return NULL ;
}
void F_92 ( struct V_3 * V_46 )
{
const struct V_71 * V_72 = V_46 -> V_72 ;
if ( V_72 -> V_90 )
V_72 -> V_90 ( V_46 ) ;
if ( V_46 -> V_5 ) {
F_11 ( V_46 -> V_5 ) ;
V_46 -> V_5 = NULL ;
V_46 -> V_4 . V_8 = 0 ;
}
}
static void F_93 ( struct V_91 * V_92 )
{
struct V_3 * V_46 = F_94 ( V_92 , struct V_3 , V_91 ) ;
F_83 ( ( char * ) V_46 - V_46 -> V_82 ) ;
}
void F_91 ( struct V_3 * V_46 )
{
const struct V_71 * V_72 = V_46 -> V_72 ;
if ( V_46 -> V_13 & V_93 ||
! F_95 ( & V_46 -> V_86 ) )
return;
#ifdef F_96
F_97 ( V_46 ) ;
F_98 ( F_99 ( V_46 -> V_94 ) ) ;
#endif
F_100 ( & V_46 -> V_95 , & V_46 -> V_96 ) ;
if ( V_72 -> V_90 )
V_72 -> V_90 ( V_46 ) ;
if ( V_72 -> V_97 )
V_72 -> V_97 ( V_46 ) ;
F_101 ( V_72 -> V_98 ) ;
F_47 ( F_26 ( V_46 ) ) ;
F_11 ( V_46 -> V_5 ) ;
F_102 ( & V_46 -> V_91 , F_93 ) ;
}
struct V_3 * F_103 ( struct V_9 * V_11 ,
struct V_3 * V_46 )
{
struct V_3 * V_99 = V_11 -> V_100 ;
T_1 * V_22 ;
V_22 = F_25 ( V_99 ) ;
F_104 ( V_22 ) ;
if ( V_99 && F_105 ( & V_99 -> V_86 ) <= 1 )
F_92 ( V_99 ) ;
if ( V_46 == NULL )
V_46 = & V_101 ;
V_11 -> V_100 = V_46 ;
F_106 ( V_11 -> V_46 , & V_101 ) ;
F_107 ( V_22 ) ;
return V_99 ;
}
static void F_108 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_102 )
{
struct V_3 * V_46 = & V_103 ;
if ( V_12 -> V_52 ) {
V_46 = F_89 ( V_11 ,
& V_104 , V_105 ) ;
if ( ! V_46 ) {
F_109 ( V_12 , L_4 ) ;
return;
}
if ( ! F_110 ( V_12 ) )
V_46 -> V_13 |= V_14 ;
}
V_11 -> V_100 = V_46 ;
}
static void F_111 ( struct V_21 * V_12 )
{
struct V_9 * V_10 ;
struct V_3 * V_46 ;
V_10 = F_6 ( V_12 , 0 ) ;
if ( ! F_110 ( V_12 ) || V_12 -> V_52 == 0 ) {
F_112 ( V_12 , F_108 , NULL ) ;
V_12 -> V_46 = V_10 -> V_100 ;
F_113 ( & V_12 -> V_46 -> V_86 ) ;
} else {
V_46 = F_89 ( V_10 , & V_106 , V_105 ) ;
if ( V_46 ) {
V_46 -> V_72 -> V_107 ( V_46 ) ;
V_12 -> V_46 = V_46 ;
}
}
}
static void F_114 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_108 )
{
struct V_3 * V_109 = V_11 -> V_100 ;
int * V_110 = V_108 ;
if ( ! ( V_109 -> V_13 & V_93 ) )
F_115 ( V_111 , & V_109 -> V_43 ) ;
F_106 ( V_11 -> V_46 , V_109 ) ;
if ( V_110 && V_109 != & V_103 ) {
V_11 -> V_30 = 0 ;
* V_110 = 1 ;
}
}
void F_116 ( struct V_21 * V_12 )
{
int V_112 ;
if ( V_12 -> V_46 == & V_101 )
F_111 ( V_12 ) ;
if ( ! F_39 ( V_12 ) )
return;
V_112 = 0 ;
F_112 ( V_12 , F_114 , & V_112 ) ;
if ( F_117 ( V_12 ) )
F_114 ( V_12 , F_117 ( V_12 ) , NULL ) ;
if ( V_112 ) {
V_12 -> V_30 = V_34 ;
F_49 ( V_12 ) ;
}
}
static void F_118 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_113 )
{
struct V_3 * V_114 = V_113 ;
struct V_3 * V_46 ;
V_46 = V_11 -> V_46 ;
if ( V_46 ) {
F_104 ( F_25 ( V_46 ) ) ;
if ( ! ( V_46 -> V_13 & V_93 ) )
F_119 ( V_111 , & V_46 -> V_43 ) ;
F_106 ( V_11 -> V_46 , V_114 ) ;
F_92 ( V_46 ) ;
F_107 ( F_25 ( V_46 ) ) ;
}
}
static bool F_120 ( struct V_21 * V_12 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_12 -> V_31 ; V_29 ++ ) {
struct V_9 * V_11 ;
T_1 * V_22 ;
struct V_3 * V_4 ;
int V_27 ;
V_11 = F_6 ( V_12 , V_29 ) ;
V_4 = V_11 -> V_100 ;
V_22 = F_25 ( V_4 ) ;
F_104 ( V_22 ) ;
V_27 = ( F_121 ( V_4 ) ||
F_122 ( V_115 , & V_4 -> V_43 ) ) ;
F_107 ( V_22 ) ;
if ( V_27 )
return true ;
}
return false ;
}
void F_123 ( struct V_116 * V_92 )
{
struct V_21 * V_12 ;
bool V_117 = false ;
F_124 (dev, head, unreg_list) {
F_112 ( V_12 , F_118 ,
& V_101 ) ;
if ( F_117 ( V_12 ) )
F_118 ( V_12 , F_117 ( V_12 ) ,
& V_101 ) ;
F_50 ( V_12 ) ;
V_117 |= ! V_12 -> V_118 ;
}
if ( V_117 )
F_125 () ;
F_124 (dev, head, unreg_list)
while ( F_120 ( V_12 ) )
F_126 () ;
}
void F_127 ( struct V_21 * V_12 )
{
F_128 ( V_119 ) ;
F_129 ( & V_12 -> V_120 , & V_119 ) ;
F_123 ( & V_119 ) ;
F_130 ( & V_119 ) ;
}
static void F_131 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_121 )
{
struct V_3 * V_46 = V_121 ;
V_11 -> V_46 = V_46 ;
V_11 -> V_100 = V_46 ;
}
void F_132 ( struct V_21 * V_12 )
{
V_12 -> V_46 = & V_101 ;
F_112 ( V_12 , F_131 , & V_101 ) ;
if ( F_117 ( V_12 ) )
F_131 ( V_12 , F_117 ( V_12 ) , & V_101 ) ;
F_133 ( & V_12 -> V_40 , F_34 , ( unsigned long ) V_12 ) ;
}
static void F_134 ( struct V_21 * V_12 ,
struct V_9 * V_11 ,
void * V_113 )
{
struct V_3 * V_46 = V_11 -> V_100 ;
struct V_3 * V_114 = V_113 ;
if ( V_46 ) {
F_106 ( V_11 -> V_46 , V_114 ) ;
V_11 -> V_100 = V_114 ;
F_91 ( V_46 ) ;
}
}
void F_135 ( struct V_21 * V_12 )
{
F_112 ( V_12 , F_134 , & V_101 ) ;
if ( F_117 ( V_12 ) )
F_134 ( V_12 , F_117 ( V_12 ) , & V_101 ) ;
F_91 ( V_12 -> V_46 ) ;
V_12 -> V_46 = & V_101 ;
F_136 ( F_137 ( & V_12 -> V_40 ) ) ;
}
void F_138 ( struct V_122 * V_123 ,
const struct V_124 * V_125 )
{
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_126 = V_125 -> V_126 ;
V_123 -> V_127 = V_125 -> V_128 ;
V_123 -> V_129 = ( V_125 -> V_129 & V_130 ) ;
V_123 -> V_131 = 1 ;
if ( V_123 -> V_127 > 0 ) {
T_2 V_132 = V_133 ;
for (; ; ) {
V_123 -> V_131 = F_139 ( V_132 , V_123 -> V_127 ) ;
if ( V_123 -> V_131 & ( 1U << 31 ) || V_132 & ( 1ULL << 63 ) )
break;
V_132 <<= 1 ;
V_123 -> V_134 ++ ;
}
}
}
