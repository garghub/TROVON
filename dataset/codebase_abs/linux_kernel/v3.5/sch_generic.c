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
F_13 ( L_1 ,
V_14 -> V_10 -> V_17 ) ;
V_15 = F_14 ( V_4 ) ;
} else {
F_15 ( V_18 . V_19 ) ;
V_15 = F_1 ( V_2 , V_4 ) ;
}
return V_15 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 * V_20 )
{
int V_15 = V_21 ;
F_17 ( V_20 ) ;
F_18 ( V_10 , V_12 , F_11 () ) ;
if ( ! F_9 ( V_12 ) )
V_15 = F_19 ( V_2 , V_10 , V_12 ) ;
F_20 ( V_10 , V_12 ) ;
F_21 ( V_20 ) ;
if ( F_22 ( V_15 ) ) {
V_15 = F_14 ( V_4 ) ;
} else if ( V_15 == V_22 ) {
V_15 = F_10 ( V_2 , V_12 , V_4 ) ;
} else {
if ( F_5 ( V_15 != V_21 ) )
F_13 ( L_2 ,
V_10 -> V_17 , V_15 , V_4 -> V_4 . V_8 ) ;
V_15 = F_1 ( V_2 , V_4 ) ;
}
if ( V_15 && F_9 ( V_12 ) )
V_15 = 0 ;
return V_15 ;
}
static inline int F_23 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
T_1 * V_20 ;
struct V_1 * V_2 ;
V_2 = F_4 ( V_4 ) ;
if ( F_5 ( ! V_2 ) )
return 0 ;
F_24 ( F_25 ( V_2 ) ) ;
V_20 = F_26 ( V_4 ) ;
V_10 = F_6 ( V_4 ) ;
V_12 = F_7 ( V_10 , F_8 ( V_2 ) ) ;
return F_16 ( V_2 , V_4 , V_10 , V_12 , V_20 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
int V_23 = V_24 ;
while ( F_23 ( V_4 ) ) {
if ( -- V_23 <= 0 || F_28 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_29 ( V_4 ) ;
}
unsigned long F_30 ( struct V_9 * V_10 )
{
unsigned long V_25 , V_26 = V_10 -> V_27 ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
V_25 = F_7 ( V_10 , V_28 ) -> V_27 ;
if ( V_25 && F_31 ( V_25 , V_26 ) )
V_26 = V_25 ;
}
V_10 -> V_27 = V_26 ;
return V_26 ;
}
static void F_32 ( unsigned long V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
F_33 ( V_10 ) ;
if ( ! F_34 ( V_10 ) ) {
if ( F_35 ( V_10 ) &&
F_36 ( V_10 ) &&
F_37 ( V_10 ) ) {
int V_31 = 0 ;
unsigned int V_28 ;
unsigned long V_27 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
struct V_11 * V_12 ;
V_12 = F_7 ( V_10 , V_28 ) ;
V_27 = V_12 -> V_27 ? : V_10 -> V_27 ;
if ( F_38 ( V_12 ) &&
F_31 ( V_32 , ( V_27 +
V_10 -> V_33 ) ) ) {
V_31 = 1 ;
V_12 -> V_34 ++ ;
break;
}
}
if ( V_31 ) {
F_39 ( 1 , V_35 L_3 ,
V_10 -> V_17 , F_40 ( V_10 ) , V_28 ) ;
V_10 -> V_36 -> V_37 ( V_10 ) ;
}
if ( ! F_41 ( & V_10 -> V_38 ,
F_42 ( V_32 +
V_10 -> V_33 ) ) )
F_43 ( V_10 ) ;
}
}
F_44 ( V_10 ) ;
F_45 ( V_10 ) ;
}
void F_46 ( struct V_9 * V_10 )
{
if ( V_10 -> V_36 -> V_37 ) {
if ( V_10 -> V_33 <= 0 )
V_10 -> V_33 = 5 * V_39 ;
if ( ! F_41 ( & V_10 -> V_38 ,
F_42 ( V_32 + V_10 -> V_33 ) ) )
F_43 ( V_10 ) ;
}
}
static void F_47 ( struct V_9 * V_10 )
{
F_46 ( V_10 ) ;
}
static void F_48 ( struct V_9 * V_10 )
{
F_49 ( V_10 ) ;
if ( F_50 ( & V_10 -> V_38 ) )
F_45 ( V_10 ) ;
F_51 ( V_10 ) ;
}
void F_52 ( struct V_9 * V_10 )
{
if ( F_53 ( V_40 , & V_10 -> V_41 ) ) {
if ( V_10 -> V_42 == V_43 )
return;
F_54 ( V_10 ) ;
if ( F_36 ( V_10 ) )
F_46 ( V_10 ) ;
}
}
void F_55 ( struct V_9 * V_10 )
{
if ( ! F_56 ( V_40 , & V_10 -> V_41 ) ) {
if ( V_10 -> V_42 == V_43 )
return;
F_54 ( V_10 ) ;
}
}
void F_57 ( struct V_9 * V_10 )
{
F_58 () ;
F_59 ( V_44 , V_10 ) ;
F_60 () ;
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_45 )
{
F_12 ( V_2 ) ;
return V_46 ;
}
static struct V_1 * F_62 ( struct V_3 * V_45 )
{
return NULL ;
}
static inline struct V_47 * F_63 ( struct V_48 * V_49 ,
int V_50 )
{
return V_49 -> V_4 + V_50 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_3 * V_45 )
{
if ( F_65 ( & V_45 -> V_4 ) < F_6 ( V_45 ) -> V_51 ) {
int V_50 = V_52 [ V_2 -> V_53 & V_54 ] ;
struct V_48 * V_49 = F_66 ( V_45 ) ;
struct V_47 * V_55 = F_63 ( V_49 , V_50 ) ;
V_49 -> V_56 |= ( 1 << V_50 ) ;
V_45 -> V_4 . V_8 ++ ;
return F_67 ( V_2 , V_45 , V_55 ) ;
}
return F_68 ( V_2 , V_45 ) ;
}
static struct V_1 * F_69 ( struct V_3 * V_45 )
{
struct V_48 * V_49 = F_66 ( V_45 ) ;
int V_50 = V_57 [ V_49 -> V_56 ] ;
if ( F_70 ( V_50 >= 0 ) ) {
struct V_47 * V_55 = F_63 ( V_49 , V_50 ) ;
struct V_1 * V_2 = F_71 ( V_45 , V_55 ) ;
V_45 -> V_4 . V_8 -- ;
if ( F_72 ( V_55 ) )
V_49 -> V_56 &= ~ ( 1 << V_50 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_73 ( struct V_3 * V_45 )
{
struct V_48 * V_49 = F_66 ( V_45 ) ;
int V_50 = V_57 [ V_49 -> V_56 ] ;
if ( V_50 >= 0 ) {
struct V_47 * V_55 = F_63 ( V_49 , V_50 ) ;
return F_74 ( V_55 ) ;
}
return NULL ;
}
static void F_75 ( struct V_3 * V_45 )
{
int V_58 ;
struct V_48 * V_49 = F_66 ( V_45 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_76 ( V_45 , F_63 ( V_49 , V_58 ) ) ;
V_49 -> V_56 = 0 ;
V_45 -> V_6 . V_60 = 0 ;
V_45 -> V_4 . V_8 = 0 ;
}
static int F_77 ( struct V_3 * V_45 , struct V_1 * V_2 )
{
struct V_61 V_62 = { . V_63 = V_59 } ;
memcpy ( & V_62 . V_64 , V_52 , V_54 + 1 ) ;
if ( F_78 ( V_2 , V_65 , sizeof( V_62 ) , & V_62 ) )
goto V_66;
return V_2 -> V_67 ;
V_66:
return - 1 ;
}
static int F_79 ( struct V_3 * V_45 , struct V_68 * V_62 )
{
int V_58 ;
struct V_48 * V_49 = F_66 ( V_45 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_80 ( F_63 ( V_49 , V_58 ) ) ;
V_45 -> V_69 |= V_70 ;
return 0 ;
}
struct V_3 * F_81 ( struct V_11 * V_14 ,
struct V_71 * V_72 )
{
void * V_73 ;
struct V_3 * V_74 ;
unsigned int V_75 = F_82 ( sizeof( * V_74 ) ) + V_72 -> V_76 ;
int V_77 = - V_78 ;
V_73 = F_83 ( V_75 , V_79 ,
F_84 ( V_14 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_82 ( ( unsigned long ) V_73 ) ;
if ( V_74 != V_73 ) {
F_85 ( V_73 ) ;
V_73 = F_83 ( V_75 + V_81 - 1 , V_79 ,
F_84 ( V_14 ) ) ;
if ( ! V_73 )
goto V_80;
V_74 = (struct V_3 * ) F_82 ( ( unsigned long ) V_73 ) ;
V_74 -> V_82 = ( char * ) V_74 - ( char * ) V_73 ;
}
F_86 ( & V_74 -> V_55 ) ;
F_80 ( & V_74 -> V_4 ) ;
F_87 ( & V_74 -> V_83 ) ;
V_74 -> V_72 = V_72 ;
V_74 -> V_84 = V_72 -> V_84 ;
V_74 -> V_13 = V_72 -> V_13 ;
V_74 -> V_14 = V_14 ;
F_43 ( F_6 ( V_74 ) ) ;
F_88 ( & V_74 -> V_85 , 1 ) ;
return V_74 ;
V_80:
return F_89 ( V_77 ) ;
}
struct V_3 * F_90 ( struct V_11 * V_14 ,
struct V_71 * V_72 , unsigned int V_86 )
{
struct V_3 * V_74 ;
V_74 = F_81 ( V_14 , V_72 ) ;
if ( F_91 ( V_74 ) )
goto V_80;
V_74 -> V_87 = V_86 ;
if ( ! V_72 -> V_88 || V_72 -> V_88 ( V_74 , NULL ) == 0 )
return V_74 ;
F_92 ( V_74 ) ;
V_80:
return NULL ;
}
void F_93 ( struct V_3 * V_45 )
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
static void F_94 ( struct V_90 * V_91 )
{
struct V_3 * V_45 = F_95 ( V_91 , struct V_3 , V_90 ) ;
F_85 ( ( char * ) V_45 - V_45 -> V_82 ) ;
}
void F_92 ( struct V_3 * V_45 )
{
const struct V_71 * V_72 = V_45 -> V_72 ;
if ( V_45 -> V_69 & V_92 ||
! F_96 ( & V_45 -> V_85 ) )
return;
#ifdef F_97
F_98 ( V_45 ) ;
F_99 ( F_100 ( V_45 -> V_93 ) ) ;
#endif
F_101 ( & V_45 -> V_94 , & V_45 -> V_95 ) ;
if ( V_72 -> V_89 )
V_72 -> V_89 ( V_45 ) ;
if ( V_72 -> V_96 )
V_72 -> V_96 ( V_45 ) ;
F_102 ( V_72 -> V_97 ) ;
F_45 ( F_6 ( V_45 ) ) ;
F_12 ( V_45 -> V_5 ) ;
F_103 ( & V_45 -> V_90 , F_94 ) ;
}
struct V_3 * F_104 ( struct V_11 * V_14 ,
struct V_3 * V_45 )
{
struct V_3 * V_98 = V_14 -> V_99 ;
T_1 * V_20 ;
V_20 = F_26 ( V_98 ) ;
F_105 ( V_20 ) ;
if ( V_98 && F_106 ( & V_98 -> V_85 ) <= 1 )
F_93 ( V_98 ) ;
if ( V_45 == NULL )
V_45 = & V_100 ;
V_14 -> V_99 = V_45 ;
F_107 ( V_14 -> V_45 , & V_100 ) ;
F_108 ( V_20 ) ;
return V_98 ;
}
static void F_109 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_101 )
{
struct V_3 * V_45 = & V_102 ;
if ( V_10 -> V_51 ) {
V_45 = F_90 ( V_14 ,
& V_103 , V_104 ) ;
if ( ! V_45 ) {
F_110 ( V_10 , L_4 ) ;
return;
}
}
V_14 -> V_99 = V_45 ;
}
static void F_111 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_45 ;
V_12 = F_7 ( V_10 , 0 ) ;
if ( ! F_112 ( V_10 ) || V_10 -> V_51 == 0 ) {
F_113 ( V_10 , F_109 , NULL ) ;
V_10 -> V_45 = V_12 -> V_99 ;
F_114 ( & V_10 -> V_45 -> V_85 ) ;
} else {
V_45 = F_90 ( V_12 , & V_105 , V_104 ) ;
if ( V_45 ) {
V_45 -> V_72 -> V_106 ( V_45 ) ;
V_10 -> V_45 = V_45 ;
}
}
}
static void F_115 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_107 )
{
struct V_3 * V_108 = V_14 -> V_99 ;
int * V_109 = V_107 ;
if ( ! ( V_108 -> V_69 & V_92 ) )
F_116 ( V_110 , & V_108 -> V_41 ) ;
F_107 ( V_14 -> V_45 , V_108 ) ;
if ( V_109 && V_108 != & V_102 ) {
V_14 -> V_27 = 0 ;
* V_109 = 1 ;
}
}
void F_117 ( struct V_9 * V_10 )
{
int V_111 ;
if ( V_10 -> V_45 == & V_100 )
F_111 ( V_10 ) ;
if ( ! F_37 ( V_10 ) )
return;
V_111 = 0 ;
F_113 ( V_10 , F_115 , & V_111 ) ;
if ( F_118 ( V_10 ) )
F_115 ( V_10 , F_118 ( V_10 ) , NULL ) ;
if ( V_111 ) {
V_10 -> V_27 = V_32 ;
F_47 ( V_10 ) ;
}
}
static void F_119 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_113 = V_112 ;
struct V_3 * V_45 ;
V_45 = V_14 -> V_45 ;
if ( V_45 ) {
F_105 ( F_26 ( V_45 ) ) ;
if ( ! ( V_45 -> V_69 & V_92 ) )
F_120 ( V_110 , & V_45 -> V_41 ) ;
F_107 ( V_14 -> V_45 , V_113 ) ;
F_93 ( V_45 ) ;
F_108 ( F_26 ( V_45 ) ) ;
}
}
static bool F_121 ( struct V_9 * V_10 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_29 ; V_28 ++ ) {
struct V_11 * V_14 ;
T_1 * V_20 ;
struct V_3 * V_4 ;
int V_25 ;
V_14 = F_7 ( V_10 , V_28 ) ;
V_4 = V_14 -> V_99 ;
V_20 = F_26 ( V_4 ) ;
F_105 ( V_20 ) ;
V_25 = ( F_122 ( V_4 ) ||
F_123 ( V_114 , & V_4 -> V_41 ) ) ;
F_108 ( V_20 ) ;
if ( V_25 )
return true ;
}
return false ;
}
void F_124 ( struct V_115 * V_91 )
{
struct V_9 * V_10 ;
bool V_116 = false ;
F_125 (dev, head, unreg_list) {
F_113 ( V_10 , F_119 ,
& V_100 ) ;
if ( F_118 ( V_10 ) )
F_119 ( V_10 , F_118 ( V_10 ) ,
& V_100 ) ;
F_48 ( V_10 ) ;
V_116 |= ! V_10 -> V_117 ;
}
if ( V_116 )
F_126 () ;
F_125 (dev, head, unreg_list)
while ( F_121 ( V_10 ) )
F_127 () ;
}
void F_128 ( struct V_9 * V_10 )
{
F_129 ( V_118 ) ;
F_130 ( & V_10 -> V_119 , & V_118 ) ;
F_124 ( & V_118 ) ;
F_131 ( & V_118 ) ;
}
static void F_132 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_120 )
{
struct V_3 * V_45 = V_120 ;
V_14 -> V_45 = V_45 ;
V_14 -> V_99 = V_45 ;
}
void F_133 ( struct V_9 * V_10 )
{
V_10 -> V_45 = & V_100 ;
F_113 ( V_10 , F_132 , & V_100 ) ;
if ( F_118 ( V_10 ) )
F_132 ( V_10 , F_118 ( V_10 ) , & V_100 ) ;
F_134 ( & V_10 -> V_38 , F_32 , ( unsigned long ) V_10 ) ;
}
static void F_135 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_45 = V_14 -> V_99 ;
struct V_3 * V_113 = V_112 ;
if ( V_45 ) {
F_107 ( V_14 -> V_45 , V_113 ) ;
V_14 -> V_99 = V_113 ;
F_92 ( V_45 ) ;
}
}
void F_136 ( struct V_9 * V_10 )
{
F_113 ( V_10 , F_135 , & V_100 ) ;
if ( F_118 ( V_10 ) )
F_135 ( V_10 , F_118 ( V_10 ) , & V_100 ) ;
F_92 ( V_10 -> V_45 ) ;
V_10 -> V_45 = & V_100 ;
F_137 ( F_138 ( & V_10 -> V_38 ) ) ;
}
