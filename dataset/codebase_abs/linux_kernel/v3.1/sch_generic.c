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
break;
}
}
if ( V_31 ) {
F_40 ( 1 , V_34 L_3 ,
V_10 -> V_17 , F_41 ( V_10 ) , V_28 ) ;
V_10 -> V_35 -> V_36 ( V_10 ) ;
}
if ( ! F_42 ( & V_10 -> V_37 ,
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
if ( V_10 -> V_35 -> V_36 ) {
if ( V_10 -> V_33 <= 0 )
V_10 -> V_33 = 5 * V_38 ;
if ( ! F_42 ( & V_10 -> V_37 ,
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
if ( F_51 ( & V_10 -> V_37 ) )
F_46 ( V_10 ) ;
F_52 ( V_10 ) ;
}
void F_53 ( struct V_9 * V_10 )
{
if ( F_54 ( V_39 , & V_10 -> V_40 ) ) {
if ( V_10 -> V_41 == V_42 )
return;
F_55 ( V_10 ) ;
if ( F_37 ( V_10 ) )
F_47 ( V_10 ) ;
}
}
void F_56 ( struct V_9 * V_10 )
{
if ( ! F_57 ( V_39 , & V_10 -> V_40 ) ) {
if ( V_10 -> V_41 == V_42 )
return;
F_55 ( V_10 ) ;
}
}
void F_58 ( struct V_9 * V_10 )
{
F_59 () ;
F_60 ( V_43 , V_10 ) ;
F_61 () ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_44 )
{
F_12 ( V_2 ) ;
return V_45 ;
}
static struct V_1 * F_63 ( struct V_3 * V_44 )
{
return NULL ;
}
static inline struct V_46 * F_64 ( struct V_47 * V_48 ,
int V_49 )
{
return V_48 -> V_4 + V_49 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_3 * V_44 )
{
if ( F_66 ( & V_44 -> V_4 ) < F_6 ( V_44 ) -> V_50 ) {
int V_49 = V_51 [ V_2 -> V_52 & V_53 ] ;
struct V_47 * V_48 = F_67 ( V_44 ) ;
struct V_46 * V_54 = F_64 ( V_48 , V_49 ) ;
V_48 -> V_55 |= ( 1 << V_49 ) ;
V_44 -> V_4 . V_8 ++ ;
return F_68 ( V_2 , V_44 , V_54 ) ;
}
return F_69 ( V_2 , V_44 ) ;
}
static struct V_1 * F_70 ( struct V_3 * V_44 )
{
struct V_47 * V_48 = F_67 ( V_44 ) ;
int V_49 = V_56 [ V_48 -> V_55 ] ;
if ( F_71 ( V_49 >= 0 ) ) {
struct V_46 * V_54 = F_64 ( V_48 , V_49 ) ;
struct V_1 * V_2 = F_72 ( V_44 , V_54 ) ;
V_44 -> V_4 . V_8 -- ;
if ( F_73 ( V_54 ) )
V_48 -> V_55 &= ~ ( 1 << V_49 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_74 ( struct V_3 * V_44 )
{
struct V_47 * V_48 = F_67 ( V_44 ) ;
int V_49 = V_56 [ V_48 -> V_55 ] ;
if ( V_49 >= 0 ) {
struct V_46 * V_54 = F_64 ( V_48 , V_49 ) ;
return F_75 ( V_54 ) ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_44 )
{
int V_57 ;
struct V_47 * V_48 = F_67 ( V_44 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_77 ( V_44 , F_64 ( V_48 , V_57 ) ) ;
V_48 -> V_55 = 0 ;
V_44 -> V_6 . V_59 = 0 ;
V_44 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_44 , struct V_1 * V_2 )
{
struct V_60 V_61 = { . V_62 = V_58 } ;
memcpy ( & V_61 . V_63 , V_51 , V_53 + 1 ) ;
F_79 ( V_2 , V_64 , sizeof( V_61 ) , & V_61 ) ;
return V_2 -> V_65 ;
V_66:
return - 1 ;
}
static int F_80 ( struct V_3 * V_44 , struct V_67 * V_61 )
{
int V_57 ;
struct V_47 * V_48 = F_67 ( V_44 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_81 ( F_64 ( V_48 , V_57 ) ) ;
V_44 -> V_68 |= V_69 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_11 * V_14 ,
struct V_70 * V_71 )
{
void * V_72 ;
struct V_3 * V_73 ;
unsigned int V_74 = F_83 ( sizeof( * V_73 ) ) + V_71 -> V_75 ;
int V_76 = - V_77 ;
V_72 = F_84 ( V_74 , V_78 ,
F_85 ( V_14 ) ) ;
if ( ! V_72 )
goto V_79;
V_73 = (struct V_3 * ) F_83 ( ( unsigned long ) V_72 ) ;
if ( V_73 != V_72 ) {
F_86 ( V_72 ) ;
V_72 = F_84 ( V_74 + V_80 - 1 , V_78 ,
F_85 ( V_14 ) ) ;
if ( ! V_72 )
goto V_79;
V_73 = (struct V_3 * ) F_83 ( ( unsigned long ) V_72 ) ;
V_73 -> V_81 = ( char * ) V_73 - ( char * ) V_72 ;
}
F_87 ( & V_73 -> V_54 ) ;
F_81 ( & V_73 -> V_4 ) ;
F_88 ( & V_73 -> V_82 ) ;
V_73 -> V_71 = V_71 ;
V_73 -> V_83 = V_71 -> V_83 ;
V_73 -> V_13 = V_71 -> V_13 ;
V_73 -> V_14 = V_14 ;
F_44 ( F_6 ( V_73 ) ) ;
F_89 ( & V_73 -> V_84 , 1 ) ;
return V_73 ;
V_79:
return F_90 ( V_76 ) ;
}
struct V_3 * F_91 ( struct V_11 * V_14 ,
struct V_70 * V_71 , unsigned int V_85 )
{
struct V_3 * V_73 ;
V_73 = F_82 ( V_14 , V_71 ) ;
if ( F_92 ( V_73 ) )
goto V_79;
V_73 -> V_86 = V_85 ;
if ( ! V_71 -> V_87 || V_71 -> V_87 ( V_73 , NULL ) == 0 )
return V_73 ;
F_93 ( V_73 ) ;
V_79:
return NULL ;
}
void F_94 ( struct V_3 * V_44 )
{
const struct V_70 * V_71 = V_44 -> V_71 ;
if ( V_71 -> V_88 )
V_71 -> V_88 ( V_44 ) ;
if ( V_44 -> V_5 ) {
F_12 ( V_44 -> V_5 ) ;
V_44 -> V_5 = NULL ;
V_44 -> V_4 . V_8 = 0 ;
}
}
static void F_95 ( struct V_89 * V_90 )
{
struct V_3 * V_44 = F_96 ( V_90 , struct V_3 , V_89 ) ;
F_86 ( ( char * ) V_44 - V_44 -> V_81 ) ;
}
void F_93 ( struct V_3 * V_44 )
{
const struct V_70 * V_71 = V_44 -> V_71 ;
if ( V_44 -> V_68 & V_91 ||
! F_97 ( & V_44 -> V_84 ) )
return;
#ifdef F_98
F_99 ( V_44 ) ;
F_100 ( F_101 ( V_44 -> V_92 ) ) ;
#endif
F_102 ( & V_44 -> V_93 , & V_44 -> V_94 ) ;
if ( V_71 -> V_88 )
V_71 -> V_88 ( V_44 ) ;
if ( V_71 -> V_95 )
V_71 -> V_95 ( V_44 ) ;
F_103 ( V_71 -> V_96 ) ;
F_46 ( F_6 ( V_44 ) ) ;
F_12 ( V_44 -> V_5 ) ;
F_104 ( & V_44 -> V_89 , F_95 ) ;
}
struct V_3 * F_105 ( struct V_11 * V_14 ,
struct V_3 * V_44 )
{
struct V_3 * V_97 = V_14 -> V_98 ;
T_1 * V_20 ;
V_20 = F_27 ( V_97 ) ;
F_106 ( V_20 ) ;
if ( V_97 && F_107 ( & V_97 -> V_84 ) <= 1 )
F_94 ( V_97 ) ;
if ( V_44 == NULL )
V_44 = & V_99 ;
V_14 -> V_98 = V_44 ;
F_108 ( V_14 -> V_44 , & V_99 ) ;
F_109 ( V_20 ) ;
return V_97 ;
}
static void F_110 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_100 )
{
struct V_3 * V_44 = & V_101 ;
if ( V_10 -> V_50 ) {
V_44 = F_91 ( V_14 ,
& V_102 , V_103 ) ;
if ( ! V_44 ) {
F_111 ( V_10 , L_4 ) ;
return;
}
}
V_14 -> V_98 = V_44 ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_44 ;
V_12 = F_7 ( V_10 , 0 ) ;
if ( ! F_113 ( V_10 ) || V_10 -> V_50 == 0 ) {
F_114 ( V_10 , F_110 , NULL ) ;
V_10 -> V_44 = V_12 -> V_98 ;
F_115 ( & V_10 -> V_44 -> V_84 ) ;
} else {
V_44 = F_91 ( V_12 , & V_104 , V_103 ) ;
if ( V_44 ) {
V_44 -> V_71 -> V_105 ( V_44 ) ;
V_10 -> V_44 = V_44 ;
}
}
}
static void F_116 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_106 )
{
struct V_3 * V_107 = V_14 -> V_98 ;
int * V_108 = V_106 ;
if ( ! ( V_107 -> V_68 & V_91 ) )
F_117 ( V_109 , & V_107 -> V_40 ) ;
F_108 ( V_14 -> V_44 , V_107 ) ;
if ( V_108 && V_107 != & V_101 ) {
V_14 -> V_27 = 0 ;
* V_108 = 1 ;
}
}
void F_118 ( struct V_9 * V_10 )
{
int V_110 ;
if ( V_10 -> V_44 == & V_99 )
F_112 ( V_10 ) ;
if ( ! F_38 ( V_10 ) )
return;
V_110 = 0 ;
F_114 ( V_10 , F_116 , & V_110 ) ;
if ( F_119 ( V_10 ) )
F_116 ( V_10 , F_119 ( V_10 ) , NULL ) ;
if ( V_110 ) {
V_10 -> V_27 = V_32 ;
F_48 ( V_10 ) ;
}
}
static void F_120 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_111 )
{
struct V_3 * V_112 = V_111 ;
struct V_3 * V_44 ;
V_44 = V_14 -> V_44 ;
if ( V_44 ) {
F_106 ( F_27 ( V_44 ) ) ;
if ( ! ( V_44 -> V_68 & V_91 ) )
F_121 ( V_109 , & V_44 -> V_40 ) ;
F_108 ( V_14 -> V_44 , V_112 ) ;
F_94 ( V_44 ) ;
F_109 ( F_27 ( V_44 ) ) ;
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
V_4 = V_14 -> V_98 ;
V_20 = F_27 ( V_4 ) ;
F_106 ( V_20 ) ;
V_25 = ( F_123 ( V_4 ) ||
F_124 ( V_113 , & V_4 -> V_40 ) ) ;
F_109 ( V_20 ) ;
if ( V_25 )
return true ;
}
return false ;
}
void F_125 ( struct V_114 * V_90 )
{
struct V_9 * V_10 ;
bool V_115 = false ;
F_126 (dev, head, unreg_list) {
F_114 ( V_10 , F_120 ,
& V_99 ) ;
if ( F_119 ( V_10 ) )
F_120 ( V_10 , F_119 ( V_10 ) ,
& V_99 ) ;
F_49 ( V_10 ) ;
V_115 |= ! V_10 -> V_116 ;
}
if ( V_115 )
F_127 () ;
F_126 (dev, head, unreg_list)
while ( F_122 ( V_10 ) )
F_128 () ;
}
void F_129 ( struct V_9 * V_10 )
{
F_130 ( V_117 ) ;
F_131 ( & V_10 -> V_118 , & V_117 ) ;
F_125 ( & V_117 ) ;
F_132 ( & V_117 ) ;
}
static void F_133 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_119 )
{
struct V_3 * V_44 = V_119 ;
V_14 -> V_44 = V_44 ;
V_14 -> V_98 = V_44 ;
}
void F_134 ( struct V_9 * V_10 )
{
V_10 -> V_44 = & V_99 ;
F_114 ( V_10 , F_133 , & V_99 ) ;
if ( F_119 ( V_10 ) )
F_133 ( V_10 , F_119 ( V_10 ) , & V_99 ) ;
F_135 ( & V_10 -> V_37 , F_33 , ( unsigned long ) V_10 ) ;
}
static void F_136 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_111 )
{
struct V_3 * V_44 = V_14 -> V_98 ;
struct V_3 * V_112 = V_111 ;
if ( V_44 ) {
F_108 ( V_14 -> V_44 , V_112 ) ;
V_14 -> V_98 = V_112 ;
F_93 ( V_44 ) ;
}
}
void F_137 ( struct V_9 * V_10 )
{
F_114 ( V_10 , F_136 , & V_99 ) ;
if ( F_119 ( V_10 ) )
F_136 ( V_10 , F_119 ( V_10 ) , & V_99 ) ;
F_93 ( V_10 -> V_44 ) ;
V_10 -> V_44 = & V_99 ;
F_138 ( F_139 ( & V_10 -> V_37 ) ) ;
}
