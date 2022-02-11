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
unsigned long V_23 = V_24 ;
while ( F_24 ( V_4 ) ) {
if ( F_29 () || V_24 != V_23 ) {
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
F_32 ( V_24 , ( V_27 +
V_10 -> V_32 ) ) ) {
V_31 = 1 ;
break;
}
}
if ( V_31 ) {
F_40 ( 1 , V_33 L_3 ,
V_10 -> V_17 , F_41 ( V_10 ) , V_28 ) ;
V_10 -> V_34 -> V_35 ( V_10 ) ;
}
if ( ! F_42 ( & V_10 -> V_36 ,
F_43 ( V_24 +
V_10 -> V_32 ) ) )
F_44 ( V_10 ) ;
}
}
F_45 ( V_10 ) ;
F_46 ( V_10 ) ;
}
void F_47 ( struct V_9 * V_10 )
{
if ( V_10 -> V_34 -> V_35 ) {
if ( V_10 -> V_32 <= 0 )
V_10 -> V_32 = 5 * V_37 ;
if ( ! F_42 ( & V_10 -> V_36 ,
F_43 ( V_24 + V_10 -> V_32 ) ) )
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
if ( F_51 ( & V_10 -> V_36 ) )
F_46 ( V_10 ) ;
F_52 ( V_10 ) ;
}
void F_53 ( struct V_9 * V_10 )
{
if ( F_54 ( V_38 , & V_10 -> V_39 ) ) {
if ( V_10 -> V_40 == V_41 )
return;
F_55 ( V_10 ) ;
if ( F_37 ( V_10 ) )
F_47 ( V_10 ) ;
}
}
void F_56 ( struct V_9 * V_10 )
{
if ( ! F_57 ( V_38 , & V_10 -> V_39 ) ) {
if ( V_10 -> V_40 == V_41 )
return;
F_55 ( V_10 ) ;
}
}
void F_58 ( struct V_9 * V_10 )
{
F_59 () ;
F_60 ( V_42 , V_10 ) ;
F_61 () ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_43 )
{
F_12 ( V_2 ) ;
return V_44 ;
}
static struct V_1 * F_63 ( struct V_3 * V_43 )
{
return NULL ;
}
static inline struct V_45 * F_64 ( struct V_46 * V_47 ,
int V_48 )
{
return V_47 -> V_4 + V_48 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_3 * V_43 )
{
if ( F_66 ( & V_43 -> V_4 ) < F_6 ( V_43 ) -> V_49 ) {
int V_48 = V_50 [ V_2 -> V_51 & V_52 ] ;
struct V_46 * V_47 = F_67 ( V_43 ) ;
struct V_45 * V_53 = F_64 ( V_47 , V_48 ) ;
V_47 -> V_54 |= ( 1 << V_48 ) ;
V_43 -> V_4 . V_8 ++ ;
return F_68 ( V_2 , V_43 , V_53 ) ;
}
return F_69 ( V_2 , V_43 ) ;
}
static struct V_1 * F_70 ( struct V_3 * V_43 )
{
struct V_46 * V_47 = F_67 ( V_43 ) ;
int V_48 = V_55 [ V_47 -> V_54 ] ;
if ( F_71 ( V_48 >= 0 ) ) {
struct V_45 * V_53 = F_64 ( V_47 , V_48 ) ;
struct V_1 * V_2 = F_72 ( V_43 , V_53 ) ;
V_43 -> V_4 . V_8 -- ;
if ( F_73 ( V_53 ) )
V_47 -> V_54 &= ~ ( 1 << V_48 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_74 ( struct V_3 * V_43 )
{
struct V_46 * V_47 = F_67 ( V_43 ) ;
int V_48 = V_55 [ V_47 -> V_54 ] ;
if ( V_48 >= 0 ) {
struct V_45 * V_53 = F_64 ( V_47 , V_48 ) ;
return F_75 ( V_53 ) ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_43 )
{
int V_56 ;
struct V_46 * V_47 = F_67 ( V_43 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ )
F_77 ( V_43 , F_64 ( V_47 , V_56 ) ) ;
V_47 -> V_54 = 0 ;
V_43 -> V_6 . V_58 = 0 ;
V_43 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_43 , struct V_1 * V_2 )
{
struct V_59 V_60 = { . V_61 = V_57 } ;
memcpy ( & V_60 . V_62 , V_50 , V_52 + 1 ) ;
F_79 ( V_2 , V_63 , sizeof( V_60 ) , & V_60 ) ;
return V_2 -> V_64 ;
V_65:
return - 1 ;
}
static int F_80 ( struct V_3 * V_43 , struct V_66 * V_60 )
{
int V_56 ;
struct V_46 * V_47 = F_67 ( V_43 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ )
F_81 ( F_64 ( V_47 , V_56 ) ) ;
V_43 -> V_67 |= V_68 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_11 * V_14 ,
struct V_69 * V_70 )
{
void * V_71 ;
struct V_3 * V_72 ;
unsigned int V_73 = F_83 ( sizeof( * V_72 ) ) + V_70 -> V_74 ;
int V_75 = - V_76 ;
V_71 = F_84 ( V_73 , V_77 ,
F_85 ( V_14 ) ) ;
if ( ! V_71 )
goto V_78;
V_72 = (struct V_3 * ) F_83 ( ( unsigned long ) V_71 ) ;
if ( V_72 != V_71 ) {
F_86 ( V_71 ) ;
V_71 = F_84 ( V_73 + V_79 - 1 , V_77 ,
F_85 ( V_14 ) ) ;
if ( ! V_71 )
goto V_78;
V_72 = (struct V_3 * ) F_83 ( ( unsigned long ) V_71 ) ;
V_72 -> V_80 = ( char * ) V_72 - ( char * ) V_71 ;
}
F_87 ( & V_72 -> V_53 ) ;
F_81 ( & V_72 -> V_4 ) ;
F_88 ( & V_72 -> V_81 ) ;
V_72 -> V_70 = V_70 ;
V_72 -> V_82 = V_70 -> V_82 ;
V_72 -> V_13 = V_70 -> V_13 ;
V_72 -> V_14 = V_14 ;
F_44 ( F_6 ( V_72 ) ) ;
F_89 ( & V_72 -> V_83 , 1 ) ;
return V_72 ;
V_78:
return F_90 ( V_75 ) ;
}
struct V_3 * F_91 ( struct V_11 * V_14 ,
struct V_69 * V_70 , unsigned int V_84 )
{
struct V_3 * V_72 ;
V_72 = F_82 ( V_14 , V_70 ) ;
if ( F_92 ( V_72 ) )
goto V_78;
V_72 -> V_85 = V_84 ;
if ( ! V_70 -> V_86 || V_70 -> V_86 ( V_72 , NULL ) == 0 )
return V_72 ;
F_93 ( V_72 ) ;
V_78:
return NULL ;
}
void F_94 ( struct V_3 * V_43 )
{
const struct V_69 * V_70 = V_43 -> V_70 ;
if ( V_70 -> V_87 )
V_70 -> V_87 ( V_43 ) ;
if ( V_43 -> V_5 ) {
F_12 ( V_43 -> V_5 ) ;
V_43 -> V_5 = NULL ;
V_43 -> V_4 . V_8 = 0 ;
}
}
static void F_95 ( struct V_88 * V_89 )
{
struct V_3 * V_43 = F_96 ( V_89 , struct V_3 , V_88 ) ;
F_86 ( ( char * ) V_43 - V_43 -> V_80 ) ;
}
void F_93 ( struct V_3 * V_43 )
{
const struct V_69 * V_70 = V_43 -> V_70 ;
if ( V_43 -> V_67 & V_90 ||
! F_97 ( & V_43 -> V_83 ) )
return;
#ifdef F_98
F_99 ( V_43 ) ;
F_100 ( F_101 ( V_43 -> V_91 ) ) ;
#endif
F_102 ( & V_43 -> V_92 , & V_43 -> V_93 ) ;
if ( V_70 -> V_87 )
V_70 -> V_87 ( V_43 ) ;
if ( V_70 -> V_94 )
V_70 -> V_94 ( V_43 ) ;
F_103 ( V_70 -> V_95 ) ;
F_46 ( F_6 ( V_43 ) ) ;
F_12 ( V_43 -> V_5 ) ;
F_104 ( & V_43 -> V_88 , F_95 ) ;
}
struct V_3 * F_105 ( struct V_11 * V_14 ,
struct V_3 * V_43 )
{
struct V_3 * V_96 = V_14 -> V_97 ;
T_1 * V_20 ;
V_20 = F_27 ( V_96 ) ;
F_106 ( V_20 ) ;
if ( V_96 && F_107 ( & V_96 -> V_83 ) <= 1 )
F_94 ( V_96 ) ;
if ( V_43 == NULL )
V_43 = & V_98 ;
V_14 -> V_97 = V_43 ;
F_108 ( V_14 -> V_43 , & V_98 ) ;
F_109 ( V_20 ) ;
return V_96 ;
}
static void F_110 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_99 )
{
struct V_3 * V_43 = & V_100 ;
if ( V_10 -> V_49 ) {
V_43 = F_91 ( V_14 ,
& V_101 , V_102 ) ;
if ( ! V_43 ) {
F_111 ( V_10 , L_4 ) ;
return;
}
}
V_14 -> V_97 = V_43 ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_43 ;
V_12 = F_7 ( V_10 , 0 ) ;
if ( ! F_113 ( V_10 ) || V_10 -> V_49 == 0 ) {
F_114 ( V_10 , F_110 , NULL ) ;
V_10 -> V_43 = V_12 -> V_97 ;
F_115 ( & V_10 -> V_43 -> V_83 ) ;
} else {
V_43 = F_91 ( V_12 , & V_103 , V_102 ) ;
if ( V_43 ) {
V_43 -> V_70 -> V_104 ( V_43 ) ;
V_10 -> V_43 = V_43 ;
}
}
}
static void F_116 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_105 )
{
struct V_3 * V_106 = V_14 -> V_97 ;
int * V_107 = V_105 ;
if ( ! ( V_106 -> V_67 & V_90 ) )
F_117 ( V_108 , & V_106 -> V_39 ) ;
F_108 ( V_14 -> V_43 , V_106 ) ;
if ( V_107 && V_106 != & V_100 ) {
V_14 -> V_27 = 0 ;
* V_107 = 1 ;
}
}
void F_118 ( struct V_9 * V_10 )
{
int V_109 ;
if ( V_10 -> V_43 == & V_98 )
F_112 ( V_10 ) ;
if ( ! F_38 ( V_10 ) )
return;
V_109 = 0 ;
F_114 ( V_10 , F_116 , & V_109 ) ;
if ( F_119 ( V_10 ) )
F_116 ( V_10 , F_119 ( V_10 ) , NULL ) ;
if ( V_109 ) {
V_10 -> V_27 = V_24 ;
F_48 ( V_10 ) ;
}
}
static void F_120 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_110 )
{
struct V_3 * V_111 = V_110 ;
struct V_3 * V_43 ;
V_43 = V_14 -> V_43 ;
if ( V_43 ) {
F_106 ( F_27 ( V_43 ) ) ;
if ( ! ( V_43 -> V_67 & V_90 ) )
F_121 ( V_108 , & V_43 -> V_39 ) ;
F_108 ( V_14 -> V_43 , V_111 ) ;
F_94 ( V_43 ) ;
F_109 ( F_27 ( V_43 ) ) ;
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
V_4 = V_14 -> V_97 ;
V_20 = F_27 ( V_4 ) ;
F_106 ( V_20 ) ;
V_25 = ( F_123 ( V_4 ) ||
F_124 ( V_112 , & V_4 -> V_39 ) ) ;
F_109 ( V_20 ) ;
if ( V_25 )
return true ;
}
return false ;
}
void F_125 ( struct V_113 * V_89 )
{
struct V_9 * V_10 ;
bool V_114 = false ;
F_126 (dev, head, unreg_list) {
F_114 ( V_10 , F_120 ,
& V_98 ) ;
if ( F_119 ( V_10 ) )
F_120 ( V_10 , F_119 ( V_10 ) ,
& V_98 ) ;
F_49 ( V_10 ) ;
V_114 |= ! V_10 -> V_115 ;
}
if ( V_114 )
F_127 () ;
F_126 (dev, head, unreg_list)
while ( F_122 ( V_10 ) )
F_128 () ;
}
void F_129 ( struct V_9 * V_10 )
{
F_130 ( V_116 ) ;
F_131 ( & V_10 -> V_117 , & V_116 ) ;
F_125 ( & V_116 ) ;
F_132 ( & V_116 ) ;
}
static void F_133 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_118 )
{
struct V_3 * V_43 = V_118 ;
V_14 -> V_43 = V_43 ;
V_14 -> V_97 = V_43 ;
}
void F_134 ( struct V_9 * V_10 )
{
V_10 -> V_43 = & V_98 ;
F_114 ( V_10 , F_133 , & V_98 ) ;
if ( F_119 ( V_10 ) )
F_133 ( V_10 , F_119 ( V_10 ) , & V_98 ) ;
F_135 ( & V_10 -> V_36 , F_33 , ( unsigned long ) V_10 ) ;
}
static void F_136 ( struct V_9 * V_10 ,
struct V_11 * V_14 ,
void * V_110 )
{
struct V_3 * V_43 = V_14 -> V_97 ;
struct V_3 * V_111 = V_110 ;
if ( V_43 ) {
F_108 ( V_14 -> V_43 , V_111 ) ;
V_14 -> V_97 = V_111 ;
F_93 ( V_43 ) ;
}
}
void F_137 ( struct V_9 * V_10 )
{
F_114 ( V_10 , F_136 , & V_98 ) ;
if ( F_119 ( V_10 ) )
F_136 ( V_10 , F_119 ( V_10 ) , & V_98 ) ;
F_93 ( V_10 -> V_43 ) ;
V_10 -> V_43 = & V_98 ;
F_138 ( F_139 ( & V_10 -> V_36 ) ) ;
}
