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
static int F_57 ( struct V_1 * V_2 , struct V_3 * V_44 )
{
F_12 ( V_2 ) ;
return V_45 ;
}
static struct V_1 * F_58 ( struct V_3 * V_44 )
{
return NULL ;
}
static inline struct V_46 * F_59 ( struct V_47 * V_48 ,
int V_49 )
{
return V_48 -> V_4 + V_49 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_3 * V_44 )
{
if ( F_61 ( & V_44 -> V_4 ) < F_6 ( V_44 ) -> V_50 ) {
int V_49 = V_51 [ V_2 -> V_52 & V_53 ] ;
struct V_47 * V_48 = F_62 ( V_44 ) ;
struct V_46 * V_54 = F_59 ( V_48 , V_49 ) ;
V_48 -> V_55 |= ( 1 << V_49 ) ;
V_44 -> V_4 . V_8 ++ ;
return F_63 ( V_2 , V_44 , V_54 ) ;
}
return F_64 ( V_2 , V_44 ) ;
}
static struct V_1 * F_65 ( struct V_3 * V_44 )
{
struct V_47 * V_48 = F_62 ( V_44 ) ;
int V_49 = V_56 [ V_48 -> V_55 ] ;
if ( F_66 ( V_49 >= 0 ) ) {
struct V_46 * V_54 = F_59 ( V_48 , V_49 ) ;
struct V_1 * V_2 = F_67 ( V_44 , V_54 ) ;
V_44 -> V_4 . V_8 -- ;
if ( F_68 ( V_54 ) )
V_48 -> V_55 &= ~ ( 1 << V_49 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_69 ( struct V_3 * V_44 )
{
struct V_47 * V_48 = F_62 ( V_44 ) ;
int V_49 = V_56 [ V_48 -> V_55 ] ;
if ( V_49 >= 0 ) {
struct V_46 * V_54 = F_59 ( V_48 , V_49 ) ;
return F_70 ( V_54 ) ;
}
return NULL ;
}
static void F_71 ( struct V_3 * V_44 )
{
int V_57 ;
struct V_47 * V_48 = F_62 ( V_44 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_72 ( V_44 , F_59 ( V_48 , V_57 ) ) ;
V_48 -> V_55 = 0 ;
V_44 -> V_6 . V_59 = 0 ;
V_44 -> V_4 . V_8 = 0 ;
}
static int F_73 ( struct V_3 * V_44 , struct V_1 * V_2 )
{
struct V_60 V_61 = { . V_62 = V_58 } ;
memcpy ( & V_61 . V_63 , V_51 , V_53 + 1 ) ;
if ( F_74 ( V_2 , V_64 , sizeof( V_61 ) , & V_61 ) )
goto V_65;
return V_2 -> V_66 ;
V_65:
return - 1 ;
}
static int F_75 ( struct V_3 * V_44 , struct V_67 * V_61 )
{
int V_57 ;
struct V_47 * V_48 = F_62 ( V_44 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_76 ( F_59 ( V_48 , V_57 ) ) ;
V_44 -> V_68 |= V_69 ;
return 0 ;
}
struct V_3 * F_77 ( struct V_11 * V_14 ,
struct V_70 * V_71 )
{
void * V_72 ;
struct V_3 * V_73 ;
unsigned int V_74 = F_78 ( sizeof( * V_73 ) ) + V_71 -> V_75 ;
int V_76 = - V_77 ;
struct V_9 * V_10 = V_14 -> V_10 ;
V_72 = F_79 ( V_74 , V_78 ,
F_80 ( V_14 ) ) ;
if ( ! V_72 )
goto V_79;
V_73 = (struct V_3 * ) F_78 ( ( unsigned long ) V_72 ) ;
if ( V_73 != V_72 ) {
F_81 ( V_72 ) ;
V_72 = F_79 ( V_74 + V_80 - 1 , V_78 ,
F_80 ( V_14 ) ) ;
if ( ! V_72 )
goto V_79;
V_73 = (struct V_3 * ) F_78 ( ( unsigned long ) V_72 ) ;
V_73 -> V_81 = ( char * ) V_73 - ( char * ) V_72 ;
}
F_82 ( & V_73 -> V_54 ) ;
F_76 ( & V_73 -> V_4 ) ;
F_83 ( & V_73 -> V_82 ) ;
F_84 ( & V_73 -> V_82 ,
V_10 -> V_83 ? : & V_83 ) ;
V_73 -> V_71 = V_71 ;
V_73 -> V_84 = V_71 -> V_84 ;
V_73 -> V_13 = V_71 -> V_13 ;
V_73 -> V_14 = V_14 ;
F_43 ( V_10 ) ;
F_85 ( & V_73 -> V_85 , 1 ) ;
return V_73 ;
V_79:
return F_86 ( V_76 ) ;
}
struct V_3 * F_87 ( struct V_11 * V_14 ,
struct V_70 * V_71 , unsigned int V_86 )
{
struct V_3 * V_73 ;
V_73 = F_77 ( V_14 , V_71 ) ;
if ( F_88 ( V_73 ) )
goto V_79;
V_73 -> V_87 = V_86 ;
if ( ! V_71 -> V_88 || V_71 -> V_88 ( V_73 , NULL ) == 0 )
return V_73 ;
F_89 ( V_73 ) ;
V_79:
return NULL ;
}
void F_90 ( struct V_3 * V_44 )
{
const struct V_70 * V_71 = V_44 -> V_71 ;
if ( V_71 -> V_89 )
V_71 -> V_89 ( V_44 ) ;
if ( V_44 -> V_5 ) {
F_12 ( V_44 -> V_5 ) ;
V_44 -> V_5 = NULL ;
V_44 -> V_4 . V_8 = 0 ;
}
}
static void F_91 ( struct V_90 * V_91 )
{
struct V_3 * V_44 = F_92 ( V_91 , struct V_3 , V_90 ) ;
F_81 ( ( char * ) V_44 - V_44 -> V_81 ) ;
}
void F_89 ( struct V_3 * V_44 )
{
const struct V_70 * V_71 = V_44 -> V_71 ;
if ( V_44 -> V_68 & V_92 ||
! F_93 ( & V_44 -> V_85 ) )
return;
#ifdef F_94
F_95 ( V_44 ) ;
F_96 ( F_97 ( V_44 -> V_93 ) ) ;
#endif
F_98 ( & V_44 -> V_94 , & V_44 -> V_95 ) ;
if ( V_71 -> V_89 )
V_71 -> V_89 ( V_44 ) ;
if ( V_71 -> V_96 )
V_71 -> V_96 ( V_44 ) ;
F_99 ( V_71 -> V_97 ) ;
F_45 ( F_6 ( V_44 ) ) ;
F_12 ( V_44 -> V_5 ) ;
F_100 ( & V_44 -> V_90 , F_91 ) ;
}
struct V_3 * F_101 ( struct V_11 * V_14 ,
struct V_3 * V_44 )
{
struct V_3 * V_98 = V_14 -> V_99 ;
T_1 * V_20 ;
V_20 = F_26 ( V_98 ) ;
F_102 ( V_20 ) ;
if ( V_98 && F_103 ( & V_98 -> V_85 ) <= 1 )
F_90 ( V_98 ) ;
if ( V_44 == NULL )
V_44 = & V_100 ;
V_14 -> V_99 = V_44 ;
F_104 ( V_14 -> V_44 , & V_100 ) ;
F_105 ( V_20 ) ;
return V_98 ;
}
static void F_106 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_101 )
{
struct V_3 * V_44 = & V_102 ;
if ( V_10 -> V_50 ) {
V_44 = F_87 ( V_14 ,
& V_103 , V_104 ) ;
if ( ! V_44 ) {
F_107 ( V_10 , L_4 ) ;
return;
}
}
V_14 -> V_99 = V_44 ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_44 ;
V_12 = F_7 ( V_10 , 0 ) ;
if ( ! F_109 ( V_10 ) || V_10 -> V_50 == 0 ) {
F_110 ( V_10 , F_106 , NULL ) ;
V_10 -> V_44 = V_12 -> V_99 ;
F_111 ( & V_10 -> V_44 -> V_85 ) ;
} else {
V_44 = F_87 ( V_12 , & V_105 , V_104 ) ;
if ( V_44 ) {
V_44 -> V_71 -> V_106 ( V_44 ) ;
V_10 -> V_44 = V_44 ;
}
}
}
static void F_112 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_107 )
{
struct V_3 * V_108 = V_14 -> V_99 ;
int * V_109 = V_107 ;
if ( ! ( V_108 -> V_68 & V_92 ) )
F_113 ( V_110 , & V_108 -> V_41 ) ;
F_104 ( V_14 -> V_44 , V_108 ) ;
if ( V_109 && V_108 != & V_102 ) {
V_14 -> V_27 = 0 ;
* V_109 = 1 ;
}
}
void F_114 ( struct V_9 * V_10 )
{
int V_111 ;
if ( V_10 -> V_44 == & V_100 )
F_108 ( V_10 ) ;
if ( ! F_37 ( V_10 ) )
return;
V_111 = 0 ;
F_110 ( V_10 , F_112 , & V_111 ) ;
if ( F_115 ( V_10 ) )
F_112 ( V_10 , F_115 ( V_10 ) , NULL ) ;
if ( V_111 ) {
V_10 -> V_27 = V_32 ;
F_47 ( V_10 ) ;
}
}
static void F_116 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_113 = V_112 ;
struct V_3 * V_44 ;
V_44 = V_14 -> V_44 ;
if ( V_44 ) {
F_102 ( F_26 ( V_44 ) ) ;
if ( ! ( V_44 -> V_68 & V_92 ) )
F_117 ( V_110 , & V_44 -> V_41 ) ;
F_104 ( V_14 -> V_44 , V_113 ) ;
F_90 ( V_44 ) ;
F_105 ( F_26 ( V_44 ) ) ;
}
}
static bool F_118 ( struct V_9 * V_10 )
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
F_102 ( V_20 ) ;
V_25 = ( F_119 ( V_4 ) ||
F_120 ( V_114 , & V_4 -> V_41 ) ) ;
F_105 ( V_20 ) ;
if ( V_25 )
return true ;
}
return false ;
}
void F_121 ( struct V_115 * V_91 )
{
struct V_9 * V_10 ;
bool V_116 = false ;
F_122 (dev, head, unreg_list) {
F_110 ( V_10 , F_116 ,
& V_100 ) ;
if ( F_115 ( V_10 ) )
F_116 ( V_10 , F_115 ( V_10 ) ,
& V_100 ) ;
F_48 ( V_10 ) ;
V_116 |= ! V_10 -> V_117 ;
}
if ( V_116 )
F_123 () ;
F_122 (dev, head, unreg_list)
while ( F_118 ( V_10 ) )
F_124 () ;
}
void F_125 ( struct V_9 * V_10 )
{
F_126 ( V_118 ) ;
F_127 ( & V_10 -> V_119 , & V_118 ) ;
F_121 ( & V_118 ) ;
F_128 ( & V_118 ) ;
}
static void F_129 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_120 )
{
struct V_3 * V_44 = V_120 ;
V_14 -> V_44 = V_44 ;
V_14 -> V_99 = V_44 ;
}
void F_130 ( struct V_9 * V_10 )
{
V_10 -> V_44 = & V_100 ;
F_110 ( V_10 , F_129 , & V_100 ) ;
if ( F_115 ( V_10 ) )
F_129 ( V_10 , F_115 ( V_10 ) , & V_100 ) ;
F_131 ( & V_10 -> V_38 , F_32 , ( unsigned long ) V_10 ) ;
}
static void F_132 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_112 )
{
struct V_3 * V_44 = V_14 -> V_99 ;
struct V_3 * V_113 = V_112 ;
if ( V_44 ) {
F_104 ( V_14 -> V_44 , V_113 ) ;
V_14 -> V_99 = V_113 ;
F_89 ( V_44 ) ;
}
}
void F_133 ( struct V_9 * V_10 )
{
F_110 ( V_10 , F_132 , & V_100 ) ;
if ( F_115 ( V_10 ) )
F_132 ( V_10 , F_115 ( V_10 ) , & V_100 ) ;
F_89 ( V_10 -> V_44 ) ;
V_10 -> V_44 = & V_100 ;
F_134 ( F_135 ( & V_10 -> V_38 ) ) ;
}
