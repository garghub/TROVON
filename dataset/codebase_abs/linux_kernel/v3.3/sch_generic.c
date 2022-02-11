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
if ( F_5 ( V_2 ) ) {
struct V_9 * V_10 = F_6 ( V_4 ) ;
struct V_11 * V_12 ;
V_12 = F_7 ( V_10 , F_8 ( V_2 ) ) ;
if ( ! F_9 ( V_12 ) ) {
V_4 -> V_5 = NULL ;
V_4 -> V_4 . V_8 -- ;
} else
V_2 = NULL ;
} else {
V_2 = V_4 -> V_13 ( V_4 ) ;
}
return V_2 ;
}
static inline int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_14 ,
struct V_3 * V_4 )
{
int V_15 ;
if ( F_5 ( V_14 -> V_16 == F_11 () ) ) {
F_12 ( V_2 ) ;
if ( F_13 () )
F_14 ( L_1 ,
V_14 -> V_10 -> V_17 ) ;
V_15 = F_15 ( V_4 ) ;
} else {
F_16 ( V_18 . V_19 ) ;
V_15 = F_1 ( V_2 , V_4 ) ;
}
return V_15 ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 * V_20 )
{
int V_15 = V_21 ;
F_18 ( V_20 ) ;
F_19 ( V_10 , V_12 , F_11 () ) ;
if ( ! F_9 ( V_12 ) )
V_15 = F_20 ( V_2 , V_10 , V_12 ) ;
F_21 ( V_10 , V_12 ) ;
F_22 ( V_20 ) ;
if ( F_23 ( V_15 ) ) {
V_15 = F_15 ( V_4 ) ;
} else if ( V_15 == V_22 ) {
V_15 = F_10 ( V_2 , V_12 , V_4 ) ;
} else {
if ( F_5 ( V_15 != V_21 && F_13 () ) )
F_14 ( L_2 ,
V_10 -> V_17 , V_15 , V_4 -> V_4 . V_8 ) ;
V_15 = F_1 ( V_2 , V_4 ) ;
}
if ( V_15 && F_9 ( V_12 ) )
V_15 = 0 ;
return V_15 ;
}
static inline int F_24 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
T_1 * V_20 ;
struct V_1 * V_2 ;
V_2 = F_4 ( V_4 ) ;
if ( F_5 ( ! V_2 ) )
return 0 ;
F_25 ( F_26 ( V_2 ) ) ;
V_20 = F_27 ( V_4 ) ;
V_10 = F_6 ( V_4 ) ;
V_12 = F_7 ( V_10 , F_8 ( V_2 ) ) ;
return F_17 ( V_2 , V_4 , V_10 , V_12 , V_20 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
int V_23 = V_24 ;
while ( F_24 ( V_4 ) ) {
if ( -- V_23 <= 0 || F_29 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_30 ( V_4 ) ;
}
unsigned long F_31 ( struct V_9 * V_10 )
{
unsigned long V_25 , V_26 = V_10 -> V_27 ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
V_25 = F_7 ( V_10 , V_28 ) -> V_27 ;
if ( V_25 && F_32 ( V_25 , V_26 ) )
V_26 = V_25 ;
}
V_10 -> V_27 = V_26 ;
return V_26 ;
}
static void F_33 ( unsigned long V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
F_34 ( V_10 ) ;
if ( ! F_35 ( V_10 ) ) {
if ( F_36 ( V_10 ) &&
F_37 ( V_10 ) &&
F_38 ( V_10 ) ) {
int V_31 = 0 ;
unsigned int V_28 ;
unsigned long V_27 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
struct V_11 * V_12 ;
V_12 = F_7 ( V_10 , V_28 ) ;
V_27 = V_12 -> V_27 ? : V_10 -> V_27 ;
if ( F_39 ( V_12 ) &&
F_32 ( V_32 , ( V_27 +
V_10 -> V_33 ) ) ) {
V_31 = 1 ;
V_12 -> V_34 ++ ;
break;
}
}
if ( V_31 ) {
F_40 ( 1 , V_35 L_3 ,
V_10 -> V_17 , F_41 ( V_10 ) , V_28 ) ;
V_10 -> V_36 -> V_37 ( V_10 ) ;
}
if ( ! F_42 ( & V_10 -> V_38 ,
F_43 ( V_32 +
V_10 -> V_33 ) ) )
F_44 ( V_10 ) ;
}
}
F_45 ( V_10 ) ;
F_46 ( V_10 ) ;
}
void F_47 ( struct V_9 * V_10 )
{
if ( V_10 -> V_36 -> V_37 ) {
if ( V_10 -> V_33 <= 0 )
V_10 -> V_33 = 5 * V_39 ;
if ( ! F_42 ( & V_10 -> V_38 ,
F_43 ( V_32 + V_10 -> V_33 ) ) )
F_44 ( V_10 ) ;
}
}
static void F_48 ( struct V_9 * V_10 )
{
F_47 ( V_10 ) ;
}
static void F_49 ( struct V_9 * V_10 )
{
F_50 ( V_10 ) ;
if ( F_51 ( & V_10 -> V_38 ) )
F_46 ( V_10 ) ;
F_52 ( V_10 ) ;
}
void F_53 ( struct V_9 * V_10 )
{
if ( F_54 ( V_40 , & V_10 -> V_41 ) ) {
if ( V_10 -> V_42 == V_43 )
return;
F_55 ( V_10 ) ;
if ( F_37 ( V_10 ) )
F_47 ( V_10 ) ;
}
}
void F_56 ( struct V_9 * V_10 )
{
if ( ! F_57 ( V_40 , & V_10 -> V_41 ) ) {
if ( V_10 -> V_42 == V_43 )
return;
F_55 ( V_10 ) ;
}
}
void F_58 ( struct V_9 * V_10 )
{
F_59 () ;
F_60 ( V_44 , V_10 ) ;
F_61 () ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_45 )
{
F_12 ( V_2 ) ;
return V_46 ;
}
static struct V_1 * F_63 ( struct V_3 * V_45 )
{
return NULL ;
}
static inline struct V_47 * F_64 ( struct V_48 * V_49 ,
int V_50 )
{
return V_49 -> V_4 + V_50 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_3 * V_45 )
{
if ( F_66 ( & V_45 -> V_4 ) < F_6 ( V_45 ) -> V_51 ) {
int V_50 = V_52 [ V_2 -> V_53 & V_54 ] ;
struct V_48 * V_49 = F_67 ( V_45 ) ;
struct V_47 * V_55 = F_64 ( V_49 , V_50 ) ;
V_49 -> V_56 |= ( 1 << V_50 ) ;
V_45 -> V_4 . V_8 ++ ;
return F_68 ( V_2 , V_45 , V_55 ) ;
}
return F_69 ( V_2 , V_45 ) ;
}
static struct V_1 * F_70 ( struct V_3 * V_45 )
{
struct V_48 * V_49 = F_67 ( V_45 ) ;
int V_50 = V_57 [ V_49 -> V_56 ] ;
if ( F_71 ( V_50 >= 0 ) ) {
struct V_47 * V_55 = F_64 ( V_49 , V_50 ) ;
struct V_1 * V_2 = F_72 ( V_45 , V_55 ) ;
V_45 -> V_4 . V_8 -- ;
if ( F_73 ( V_55 ) )
V_49 -> V_56 &= ~ ( 1 << V_50 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_74 ( struct V_3 * V_45 )
{
struct V_48 * V_49 = F_67 ( V_45 ) ;
int V_50 = V_57 [ V_49 -> V_56 ] ;
if ( V_50 >= 0 ) {
struct V_47 * V_55 = F_64 ( V_49 , V_50 ) ;
return F_75 ( V_55 ) ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_45 )
{
int V_58 ;
struct V_48 * V_49 = F_67 ( V_45 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_77 ( V_45 , F_64 ( V_49 , V_58 ) ) ;
V_49 -> V_56 = 0 ;
V_45 -> V_6 . V_60 = 0 ;
V_45 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_45 , struct V_1 * V_2 )
{
struct V_61 V_62 = { . V_63 = V_59 } ;
memcpy ( & V_62 . V_64 , V_52 , V_54 + 1 ) ;
F_79 ( V_2 , V_65 , sizeof( V_62 ) , & V_62 ) ;
return V_2 -> V_66 ;
V_67:
return - 1 ;
}
static int F_80 ( struct V_3 * V_45 , struct V_68 * V_62 )
{
int V_58 ;
struct V_48 * V_49 = F_67 ( V_45 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_81 ( F_64 ( V_49 , V_58 ) ) ;
V_45 -> V_69 |= V_70 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_11 * V_14 ,
struct V_71 * V_72 )
{
void * V_73 ;
struct V_3 * V_74 ;
unsigned int V_75 = F_83 ( sizeof( * V_74 ) ) + V_72 -> V_76 ;
int V_77 = - V_78 ;
V_73 = F_84 ( V_75 , V_79 ,
F_85 ( V_14 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_83 ( ( unsigned long ) V_73 ) ;
if ( V_74 != V_73 ) {
F_86 ( V_73 ) ;
V_73 = F_84 ( V_75 + V_81 - 1 , V_79 ,
F_85 ( V_14 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_83 ( ( unsigned long ) V_73 ) ;
V_74 -> V_82 = ( char * ) V_74 - ( char * ) V_73 ;
}
F_87 ( & V_74 -> V_55 ) ;
F_81 ( & V_74 -> V_4 ) ;
F_88 ( & V_74 -> V_83 ) ;
V_74 -> V_72 = V_72 ;
V_74 -> V_84 = V_72 -> V_84 ;
V_74 -> V_13 = V_72 -> V_13 ;
V_74 -> V_14 = V_14 ;
F_44 ( F_6 ( V_74 ) ) ;
F_89 ( & V_74 -> V_85 , 1 ) ;
return V_74 ;
V_80:
return F_90 ( V_77 ) ;
}
struct V_3 * F_91 ( struct V_11 * V_14 ,
struct V_71 * V_72 , unsigned int V_86 )
{
struct V_3 * V_74 ;
V_74 = F_82 ( V_14 , V_72 ) ;
if ( F_92 ( V_74 ) )
goto V_80;
V_74 -> V_87 = V_86 ;
if ( ! V_72 -> V_88 || V_72 -> V_88 ( V_74 , NULL ) == 0 )
return V_74 ;
F_93 ( V_74 ) ;
V_80:
return NULL ;
}
void F_94 ( struct V_3 * V_45 )
{
const struct V_71 * V_72 = V_45 -> V_72 ;
if ( V_72 -> V_89 )
V_72 -> V_89 ( V_45 ) ;
if ( V_45 -> V_5 ) {
F_12 ( V_45 -> V_5 ) ;
V_45 -> V_5 = NULL ;
V_45 -> V_4 . V_8 = 0 ;
}
}
static void F_95 ( struct V_90 * V_91 )
{
struct V_3 * V_45 = F_96 ( V_91 , struct V_3 , V_90 ) ;
F_86 ( ( char * ) V_45 - V_45 -> V_82 ) ;
}
void F_93 ( struct V_3 * V_45 )
{
const struct V_71 * V_72 = V_45 -> V_72 ;
if ( V_45 -> V_69 & V_92 ||
! F_97 ( & V_45 -> V_85 ) )
return;
#ifdef F_98
F_99 ( V_45 ) ;
F_100 ( F_101 ( V_45 -> V_93 ) ) ;
#endif
F_102 ( & V_45 -> V_94 , & V_45 -> V_95 ) ;
if ( V_72 -> V_89 )
V_72 -> V_89 ( V_45 ) ;
if ( V_72 -> V_96 )
V_72 -> V_96 ( V_45 ) ;
F_103 ( V_72 -> V_97 ) ;
F_46 ( F_6 ( V_45 ) ) ;
F_12 ( V_45 -> V_5 ) ;
F_104 ( & V_45 -> V_90 , F_95 ) ;
}
struct V_3 * F_105 ( struct V_11 * V_14 ,
struct V_3 * V_45 )
{
struct V_3 * V_98 = V_14 -> V_99 ;
T_1 * V_20 ;
V_20 = F_27 ( V_98 ) ;
F_106 ( V_20 ) ;
if ( V_98 && F_107 ( & V_98 -> V_85 ) <= 1 )
F_94 ( V_98 ) ;
if ( V_45 == NULL )
V_45 = & V_100 ;
V_14 -> V_99 = V_45 ;
F_108 ( V_14 -> V_45 , & V_100 ) ;
F_109 ( V_20 ) ;
return V_98 ;
}
static void F_110 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_101 )
{
struct V_3 * V_45 = & V_102 ;
if ( V_10 -> V_51 ) {
V_45 = F_91 ( V_14 ,
& V_103 , V_104 ) ;
if ( ! V_45 ) {
F_111 ( V_10 , L_4 ) ;
return;
}
}
V_14 -> V_99 = V_45 ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_45 ;
V_12 = F_7 ( V_10 , 0 ) ;
if ( ! F_113 ( V_10 ) || V_10 -> V_51 == 0 ) {
F_114 ( V_10 , F_110 , NULL ) ;
V_10 -> V_45 = V_12 -> V_99 ;
F_115 ( & V_10 -> V_45 -> V_85 ) ;
} else {
V_45 = F_91 ( V_12 , & V_105 , V_104 ) ;
if ( V_45 ) {
V_45 -> V_72 -> V_106 ( V_45 ) ;
V_10 -> V_45 = V_45 ;
}
}
}
static void F_116 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_107 )
{
struct V_3 * V_108 = V_14 -> V_99 ;
int * V_109 = V_107 ;
if ( ! ( V_108 -> V_69 & V_92 ) )
F_117 ( V_110 , & V_108 -> V_41 ) ;
F_108 ( V_14 -> V_45 , V_108 ) ;
if ( V_109 && V_108 != & V_102 ) {
V_14 -> V_27 = 0 ;
* V_109 = 1 ;
}
}
void F_118 ( struct V_9 * V_10 )
{
int V_111 ;
if ( V_10 -> V_45 == & V_100 )
F_112 ( V_10 ) ;
if ( ! F_38 ( V_10 ) )
return;
V_111 = 0 ;
F_114 ( V_10 , F_116 , & V_111 ) ;
if ( F_119 ( V_10 ) )
F_116 ( V_10 , F_119 ( V_10 ) , NULL ) ;
if ( V_111 ) {
V_10 -> V_27 = V_32 ;
F_48 ( V_10 ) ;
}
}
static void F_120 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_113 = V_112 ;
struct V_3 * V_45 ;
V_45 = V_14 -> V_45 ;
if ( V_45 ) {
F_106 ( F_27 ( V_45 ) ) ;
if ( ! ( V_45 -> V_69 & V_92 ) )
F_121 ( V_110 , & V_45 -> V_41 ) ;
F_108 ( V_14 -> V_45 , V_113 ) ;
F_94 ( V_45 ) ;
F_109 ( F_27 ( V_45 ) ) ;
}
}
static bool F_122 ( struct V_9 * V_10 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
struct V_11 * V_14 ;
T_1 * V_20 ;
struct V_3 * V_4 ;
int V_25 ;
V_14 = F_7 ( V_10 , V_28 ) ;
V_4 = V_14 -> V_99 ;
V_20 = F_27 ( V_4 ) ;
F_106 ( V_20 ) ;
V_25 = ( F_123 ( V_4 ) ||
F_124 ( V_114 , & V_4 -> V_41 ) ) ;
F_109 ( V_20 ) ;
if ( V_25 )
return true ;
}
return false ;
}
void F_125 ( struct V_115 * V_91 )
{
struct V_9 * V_10 ;
bool V_116 = false ;
F_126 (dev, head, unreg_list) {
F_114 ( V_10 , F_120 ,
& V_100 ) ;
if ( F_119 ( V_10 ) )
F_120 ( V_10 , F_119 ( V_10 ) ,
& V_100 ) ;
F_49 ( V_10 ) ;
V_116 |= ! V_10 -> V_117 ;
}
if ( V_116 )
F_127 () ;
F_126 (dev, head, unreg_list)
while ( F_122 ( V_10 ) )
F_128 () ;
}
void F_129 ( struct V_9 * V_10 )
{
F_130 ( V_118 ) ;
F_131 ( & V_10 -> V_119 , & V_118 ) ;
F_125 ( & V_118 ) ;
F_132 ( & V_118 ) ;
}
static void F_133 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_120 )
{
struct V_3 * V_45 = V_120 ;
V_14 -> V_45 = V_45 ;
V_14 -> V_99 = V_45 ;
}
void F_134 ( struct V_9 * V_10 )
{
V_10 -> V_45 = & V_100 ;
F_114 ( V_10 , F_133 , & V_100 ) ;
if ( F_119 ( V_10 ) )
F_133 ( V_10 , F_119 ( V_10 ) , & V_100 ) ;
F_135 ( & V_10 -> V_38 , F_33 , ( unsigned long ) V_10 ) ;
}
static void F_136 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_45 = V_14 -> V_99 ;
struct V_3 * V_113 = V_112 ;
if ( V_45 ) {
F_108 ( V_14 -> V_45 , V_113 ) ;
V_14 -> V_99 = V_113 ;
F_93 ( V_45 ) ;
}
}
void F_137 ( struct V_9 * V_10 )
{
F_114 ( V_10 , F_136 , & V_100 ) ;
if ( F_119 ( V_10 ) )
F_136 ( V_10 , F_119 ( V_10 ) , & V_100 ) ;
F_93 ( V_10 -> V_45 ) ;
V_10 -> V_45 = & V_100 ;
F_138 ( F_139 ( & V_10 -> V_38 ) ) ;
}
