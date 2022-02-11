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
if ( V_53 -> V_4 . V_8 < F_28 ( V_53 ) -> V_63 ) {
int V_62 = V_64 [ V_2 -> V_65 & V_66 ] ;
struct V_60 * V_61 = F_69 ( V_53 ) ;
struct V_59 * V_67 = F_67 ( V_61 , V_62 ) ;
V_61 -> V_68 |= ( 1 << V_62 ) ;
V_53 -> V_4 . V_8 ++ ;
return F_70 ( V_2 , V_53 , V_67 ) ;
}
return F_71 ( V_2 , V_53 , V_54 ) ;
}
static struct V_1 * F_72 ( struct V_3 * V_53 )
{
struct V_60 * V_61 = F_69 ( V_53 ) ;
int V_62 = V_69 [ V_61 -> V_68 ] ;
if ( F_17 ( V_62 >= 0 ) ) {
struct V_59 * V_70 = F_67 ( V_61 , V_62 ) ;
struct V_1 * V_2 = F_73 ( V_70 ) ;
if ( F_17 ( V_2 != NULL ) ) {
F_12 ( V_53 , V_2 ) ;
F_74 ( V_53 , V_2 ) ;
}
V_53 -> V_4 . V_8 -- ;
if ( V_70 -> V_8 == 0 )
V_61 -> V_68 &= ~ ( 1 << V_62 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_75 ( struct V_3 * V_53 )
{
struct V_60 * V_61 = F_69 ( V_53 ) ;
int V_62 = V_69 [ V_61 -> V_68 ] ;
if ( V_62 >= 0 ) {
struct V_59 * V_70 = F_67 ( V_61 , V_62 ) ;
return V_70 -> V_71 ;
}
return NULL ;
}
static void F_76 ( struct V_3 * V_53 )
{
int V_72 ;
struct V_60 * V_61 = F_69 ( V_53 ) ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
F_77 ( F_67 ( V_61 , V_72 ) ) ;
V_61 -> V_68 = 0 ;
V_53 -> V_6 . V_74 = 0 ;
V_53 -> V_4 . V_8 = 0 ;
}
static int F_78 ( struct V_3 * V_53 , struct V_1 * V_2 )
{
struct V_75 V_57 = { . V_76 = V_73 } ;
memcpy ( & V_57 . V_77 , V_64 , V_66 + 1 ) ;
if ( F_79 ( V_2 , V_78 , sizeof( V_57 ) , & V_57 ) )
goto V_79;
return V_2 -> V_13 ;
V_79:
return - 1 ;
}
static int F_80 ( struct V_3 * V_53 , struct V_56 * V_57 )
{
int V_72 ;
struct V_60 * V_61 = F_69 ( V_53 ) ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
F_81 ( F_67 ( V_61 , V_72 ) ) ;
V_53 -> V_24 |= V_80 ;
return 0 ;
}
struct V_3 * F_82 ( struct V_9 * V_21 ,
const struct V_81 * V_82 )
{
void * V_83 ;
struct V_3 * V_84 ;
unsigned int V_85 = F_83 ( sizeof( * V_84 ) ) + V_82 -> V_86 ;
int V_87 = - V_88 ;
struct V_26 * V_22 = V_21 -> V_22 ;
V_83 = F_84 ( V_85 , V_89 ,
F_85 ( V_21 ) ) ;
if ( ! V_83 )
goto V_90;
V_84 = (struct V_3 * ) F_83 ( ( unsigned long ) V_83 ) ;
if ( V_84 != V_83 ) {
F_86 ( V_83 ) ;
V_83 = F_84 ( V_85 + V_91 - 1 , V_89 ,
F_85 ( V_21 ) ) ;
if ( ! V_83 )
goto V_90;
V_84 = (struct V_3 * ) F_83 ( ( unsigned long ) V_83 ) ;
V_84 -> V_92 = ( char * ) V_84 - ( char * ) V_83 ;
}
F_81 ( & V_84 -> V_4 ) ;
F_87 ( & V_84 -> V_4 . V_93 ) ;
F_87 ( & V_84 -> V_94 ) ;
F_88 ( & V_84 -> V_94 ,
V_22 -> V_95 ? : & V_95 ) ;
F_89 ( & V_84 -> V_96 ) ;
F_88 ( & V_84 -> V_96 ,
V_22 -> V_97 ? : & V_97 ) ;
V_84 -> V_82 = V_82 ;
V_84 -> V_58 = V_82 -> V_58 ;
V_84 -> V_15 = V_82 -> V_15 ;
V_84 -> V_21 = V_21 ;
F_48 ( V_22 ) ;
F_90 ( & V_84 -> V_98 , 1 ) ;
return V_84 ;
V_90:
return F_91 ( V_87 ) ;
}
struct V_3 * F_92 ( struct V_9 * V_21 ,
const struct V_81 * V_82 ,
unsigned int V_99 )
{
struct V_3 * V_84 ;
if ( ! F_93 ( V_82 -> V_100 ) )
return NULL ;
V_84 = F_82 ( V_21 , V_82 ) ;
if ( F_94 ( V_84 ) ) {
F_95 ( V_82 -> V_100 ) ;
return NULL ;
}
V_84 -> V_101 = V_99 ;
if ( ! V_82 -> V_102 || V_82 -> V_102 ( V_84 , NULL ) == 0 )
return V_84 ;
F_96 ( V_84 ) ;
return NULL ;
}
void F_97 ( struct V_3 * V_53 )
{
const struct V_81 * V_82 = V_53 -> V_82 ;
if ( V_82 -> V_103 )
V_82 -> V_103 ( V_53 ) ;
F_98 ( V_53 -> V_19 ) ;
V_53 -> V_19 = NULL ;
if ( V_53 -> V_5 ) {
F_99 ( V_53 -> V_5 ) ;
V_53 -> V_5 = NULL ;
}
V_53 -> V_4 . V_8 = 0 ;
}
static void F_100 ( struct V_104 * V_71 )
{
struct V_3 * V_53 = F_101 ( V_71 , struct V_3 , V_104 ) ;
if ( F_102 ( V_53 ) ) {
F_103 ( V_53 -> V_105 ) ;
F_103 ( V_53 -> V_106 ) ;
}
F_86 ( ( char * ) V_53 - V_53 -> V_92 ) ;
}
void F_96 ( struct V_3 * V_53 )
{
const struct V_81 * V_82 = V_53 -> V_82 ;
if ( V_53 -> V_24 & V_107 ||
! F_104 ( & V_53 -> V_98 ) )
return;
#ifdef F_105
F_106 ( V_53 ) ;
F_107 ( F_108 ( V_53 -> V_108 ) ) ;
#endif
F_109 ( & V_53 -> V_109 ) ;
if ( V_82 -> V_103 )
V_82 -> V_103 ( V_53 ) ;
if ( V_82 -> V_110 )
V_82 -> V_110 ( V_53 ) ;
F_95 ( V_82 -> V_100 ) ;
F_50 ( F_28 ( V_53 ) ) ;
F_99 ( V_53 -> V_5 ) ;
F_98 ( V_53 -> V_19 ) ;
F_110 ( & V_53 -> V_104 , F_100 ) ;
}
struct V_3 * F_111 ( struct V_9 * V_21 ,
struct V_3 * V_53 )
{
struct V_3 * V_111 = V_21 -> V_112 ;
T_1 * V_27 ;
V_27 = F_27 ( V_111 ) ;
F_112 ( V_27 ) ;
if ( V_111 && F_113 ( & V_111 -> V_98 ) <= 1 )
F_97 ( V_111 ) ;
if ( V_53 == NULL )
V_53 = & V_113 ;
V_21 -> V_112 = V_53 ;
F_114 ( V_21 -> V_53 , & V_113 ) ;
F_115 ( V_27 ) ;
return V_111 ;
}
static void F_116 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_114 )
{
struct V_3 * V_53 ;
const struct V_81 * V_82 = V_115 ;
if ( V_22 -> V_116 & V_117 )
V_82 = & V_118 ;
V_53 = F_92 ( V_21 , V_82 , V_119 ) ;
if ( ! V_53 ) {
F_117 ( V_22 , L_3 ) ;
return;
}
if ( ! F_118 ( V_22 ) )
V_53 -> V_24 |= V_25 | V_120 ;
V_21 -> V_112 = V_53 ;
}
static void F_119 ( struct V_26 * V_22 )
{
struct V_9 * V_10 ;
struct V_3 * V_53 ;
V_10 = F_35 ( V_22 , 0 ) ;
if ( ! F_118 ( V_22 ) ||
V_22 -> V_116 & V_117 ) {
F_120 ( V_22 , F_116 , NULL ) ;
V_22 -> V_53 = V_10 -> V_112 ;
F_121 ( V_22 -> V_53 ) ;
} else {
V_53 = F_92 ( V_10 , & V_121 , V_119 ) ;
if ( V_53 ) {
V_22 -> V_53 = V_53 ;
V_53 -> V_82 -> V_122 ( V_53 ) ;
}
}
#ifdef F_105
if ( V_22 -> V_53 != & V_113 )
F_122 ( V_22 -> V_53 , false ) ;
#endif
}
static void F_123 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_123 )
{
struct V_3 * V_124 = V_21 -> V_112 ;
int * V_125 = V_123 ;
if ( ! ( V_124 -> V_24 & V_107 ) )
F_124 ( V_126 , & V_124 -> V_49 ) ;
F_114 ( V_21 -> V_53 , V_124 ) ;
if ( V_125 ) {
V_21 -> V_36 = 0 ;
* V_125 = 1 ;
}
}
void F_125 ( struct V_26 * V_22 )
{
int V_127 ;
if ( V_22 -> V_53 == & V_113 )
F_119 ( V_22 ) ;
if ( ! F_42 ( V_22 ) )
return;
V_127 = 0 ;
F_120 ( V_22 , F_123 , & V_127 ) ;
if ( F_126 ( V_22 ) )
F_123 ( V_22 , F_126 ( V_22 ) , NULL ) ;
if ( V_127 ) {
F_127 ( V_22 ) ;
F_52 ( V_22 ) ;
}
}
static void F_128 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_128 )
{
struct V_3 * V_129 = V_128 ;
struct V_3 * V_53 ;
V_53 = F_108 ( V_21 -> V_53 ) ;
if ( V_53 ) {
F_112 ( F_27 ( V_53 ) ) ;
if ( ! ( V_53 -> V_24 & V_107 ) )
F_129 ( V_126 , & V_53 -> V_49 ) ;
F_114 ( V_21 -> V_53 , V_129 ) ;
F_97 ( V_53 ) ;
F_115 ( F_27 ( V_53 ) ) ;
}
}
static bool F_130 ( struct V_26 * V_22 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_22 -> V_37 ; V_35 ++ ) {
struct V_9 * V_21 ;
T_1 * V_27 ;
struct V_3 * V_4 ;
int V_33 ;
V_21 = F_35 ( V_22 , V_35 ) ;
V_4 = V_21 -> V_112 ;
V_27 = F_27 ( V_4 ) ;
F_112 ( V_27 ) ;
V_33 = ( F_131 ( V_4 ) ||
F_132 ( V_130 , & V_4 -> V_49 ) ) ;
F_115 ( V_27 ) ;
if ( V_33 )
return true ;
}
return false ;
}
void F_133 ( struct V_131 * V_71 )
{
struct V_26 * V_22 ;
bool V_132 = false ;
F_134 (dev, head, close_list) {
F_120 ( V_22 , F_128 ,
& V_113 ) ;
if ( F_126 ( V_22 ) )
F_128 ( V_22 , F_126 ( V_22 ) ,
& V_113 ) ;
F_53 ( V_22 ) ;
V_132 |= ! V_22 -> V_133 ;
}
if ( V_132 )
F_135 () ;
F_134 (dev, head, close_list)
while ( F_130 ( V_22 ) )
F_136 () ;
}
void F_137 ( struct V_26 * V_22 )
{
F_138 ( V_134 ) ;
F_139 ( & V_22 -> V_135 , & V_134 ) ;
F_133 ( & V_134 ) ;
F_140 ( & V_134 ) ;
}
static void F_141 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_136 )
{
struct V_3 * V_53 = V_136 ;
F_114 ( V_21 -> V_53 , V_53 ) ;
V_21 -> V_112 = V_53 ;
}
void F_142 ( struct V_26 * V_22 )
{
V_22 -> V_53 = & V_113 ;
F_120 ( V_22 , F_141 , & V_113 ) ;
if ( F_126 ( V_22 ) )
F_141 ( V_22 , F_126 ( V_22 ) , & V_113 ) ;
F_143 ( & V_22 -> V_46 , F_37 , ( unsigned long ) V_22 ) ;
}
static void F_144 ( struct V_26 * V_22 ,
struct V_9 * V_21 ,
void * V_128 )
{
struct V_3 * V_53 = V_21 -> V_112 ;
struct V_3 * V_129 = V_128 ;
if ( V_53 ) {
F_114 ( V_21 -> V_53 , V_129 ) ;
V_21 -> V_112 = V_129 ;
F_96 ( V_53 ) ;
}
}
void F_145 ( struct V_26 * V_22 )
{
F_120 ( V_22 , F_144 , & V_113 ) ;
if ( F_126 ( V_22 ) )
F_144 ( V_22 , F_126 ( V_22 ) , & V_113 ) ;
F_96 ( V_22 -> V_53 ) ;
V_22 -> V_53 = & V_113 ;
F_146 ( F_147 ( & V_22 -> V_46 ) ) ;
}
void F_148 ( struct V_137 * V_138 ,
const struct V_139 * V_140 ,
T_2 V_141 )
{
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_138 -> V_142 = V_140 -> V_142 ;
V_138 -> V_143 = F_149 ( T_2 , V_140 -> V_144 , V_141 ) ;
V_138 -> V_145 = ( V_140 -> V_145 & V_146 ) ;
V_138 -> V_147 = 1 ;
if ( V_138 -> V_143 > 0 ) {
T_2 V_148 = V_149 ;
for (; ; ) {
V_138 -> V_147 = F_150 ( V_148 , V_138 -> V_143 ) ;
if ( V_138 -> V_147 & ( 1U << 31 ) || V_148 & ( 1ULL << 63 ) )
break;
V_148 <<= 1 ;
V_138 -> V_150 ++ ;
}
}
}
