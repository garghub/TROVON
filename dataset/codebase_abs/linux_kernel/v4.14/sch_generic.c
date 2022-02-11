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
goto V_23;
}
* V_20 = true ;
V_2 = V_4 -> V_19 ;
if ( F_8 ( V_2 ) ) {
V_10 = F_10 ( V_10 -> V_22 , V_2 ) ;
if ( ! F_11 ( V_10 ) ) {
V_4 -> V_19 = NULL ;
F_12 ( V_4 , V_2 ) ;
V_4 -> V_4 . V_8 -- ;
goto V_24;
}
V_2 = NULL ;
goto V_23;
}
if ( ! ( V_4 -> V_25 & V_26 ) ||
! F_11 ( V_10 ) )
V_2 = V_4 -> V_15 ( V_4 ) ;
if ( V_2 ) {
V_24:
if ( F_13 ( V_4 ) )
F_4 ( V_4 , V_2 , V_10 , V_11 ) ;
else
F_6 ( V_4 , V_2 , V_11 ) ;
}
V_23:
F_14 ( V_4 , V_10 , * V_11 , V_2 ) ;
return V_2 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_27 * V_22 , struct V_9 * V_10 ,
T_1 * V_28 , bool V_20 )
{
int V_29 = V_30 ;
F_16 ( V_28 ) ;
if ( V_20 )
V_2 = F_17 ( V_2 , V_22 ) ;
if ( F_18 ( V_2 ) ) {
F_19 ( V_22 , V_10 , F_20 () ) ;
if ( ! F_11 ( V_10 ) )
V_2 = F_21 ( V_2 , V_22 , V_10 , & V_29 ) ;
F_22 ( V_22 , V_10 ) ;
} else {
F_23 ( V_28 ) ;
return F_24 ( V_4 ) ;
}
F_23 ( V_28 ) ;
if ( F_25 ( V_29 ) ) {
V_29 = F_24 ( V_4 ) ;
} else {
if ( F_8 ( V_29 != V_30 ) )
F_26 ( L_1 ,
V_22 -> V_31 , V_29 , V_4 -> V_4 . V_8 ) ;
V_29 = F_1 ( V_2 , V_4 ) ;
}
if ( V_29 && F_11 ( V_10 ) )
V_29 = 0 ;
return V_29 ;
}
static inline int F_27 ( struct V_3 * V_4 , int * V_11 )
{
struct V_9 * V_10 ;
struct V_27 * V_22 ;
T_1 * V_28 ;
struct V_1 * V_2 ;
bool V_20 ;
V_2 = F_9 ( V_4 , & V_20 , V_11 ) ;
if ( F_8 ( ! V_2 ) )
return 0 ;
V_28 = F_28 ( V_4 ) ;
V_22 = F_29 ( V_4 ) ;
V_10 = F_10 ( V_22 , V_2 ) ;
return F_15 ( V_2 , V_4 , V_22 , V_10 , V_28 , V_20 ) ;
}
void F_30 ( struct V_3 * V_4 )
{
int V_32 = V_33 ;
int V_11 ;
while ( F_27 ( V_4 , & V_11 ) ) {
V_32 -= V_11 ;
if ( V_32 <= 0 || F_31 () ) {
F_3 ( V_4 ) ;
break;
}
}
F_32 ( V_4 ) ;
}
unsigned long F_33 ( struct V_27 * V_22 )
{
unsigned long V_34 , V_35 ;
unsigned int V_36 ;
if ( F_34 ( V_22 ) )
V_22 = F_35 ( V_22 ) ;
V_35 = F_36 ( V_22 , 0 ) -> V_37 ;
for ( V_36 = 1 ; V_36 < V_22 -> V_38 ; V_36 ++ ) {
V_34 = F_36 ( V_22 , V_36 ) -> V_37 ;
if ( V_34 && F_37 ( V_34 , V_35 ) )
V_35 = V_34 ;
}
return V_35 ;
}
static void F_38 ( unsigned long V_39 )
{
struct V_27 * V_22 = (struct V_27 * ) V_39 ;
F_39 ( V_22 ) ;
if ( ! F_40 ( V_22 ) ) {
if ( F_41 ( V_22 ) &&
F_42 ( V_22 ) &&
F_43 ( V_22 ) ) {
int V_40 = 0 ;
unsigned int V_36 ;
unsigned long V_37 ;
for ( V_36 = 0 ; V_36 < V_22 -> V_38 ; V_36 ++ ) {
struct V_9 * V_10 ;
V_10 = F_36 ( V_22 , V_36 ) ;
V_37 = V_10 -> V_37 ;
if ( F_44 ( V_10 ) &&
F_37 ( V_41 , ( V_37 +
V_22 -> V_42 ) ) ) {
V_40 = 1 ;
V_10 -> V_43 ++ ;
break;
}
}
if ( V_40 ) {
F_45 ( 1 , V_44 L_2 ,
V_22 -> V_31 , F_46 ( V_22 ) , V_36 ) ;
V_22 -> V_45 -> V_46 ( V_22 ) ;
}
if ( ! F_47 ( & V_22 -> V_47 ,
F_48 ( V_41 +
V_22 -> V_42 ) ) )
F_49 ( V_22 ) ;
}
}
F_50 ( V_22 ) ;
F_51 ( V_22 ) ;
}
void F_52 ( struct V_27 * V_22 )
{
if ( V_22 -> V_45 -> V_46 ) {
if ( V_22 -> V_42 <= 0 )
V_22 -> V_42 = 5 * V_48 ;
if ( ! F_47 ( & V_22 -> V_47 ,
F_48 ( V_41 + V_22 -> V_42 ) ) )
F_49 ( V_22 ) ;
}
}
static void F_53 ( struct V_27 * V_22 )
{
F_52 ( V_22 ) ;
}
static void F_54 ( struct V_27 * V_22 )
{
F_55 ( V_22 ) ;
if ( F_56 ( & V_22 -> V_47 ) )
F_51 ( V_22 ) ;
F_57 ( V_22 ) ;
}
void F_58 ( struct V_27 * V_22 )
{
if ( F_59 ( V_49 , & V_22 -> V_50 ) ) {
if ( V_22 -> V_51 == V_52 )
return;
F_60 ( & V_22 -> V_53 ) ;
F_61 ( V_22 ) ;
if ( F_42 ( V_22 ) )
F_52 ( V_22 ) ;
}
}
void F_62 ( struct V_27 * V_22 )
{
if ( ! F_63 ( V_49 , & V_22 -> V_50 ) ) {
if ( V_22 -> V_51 == V_52 )
return;
F_60 ( & V_22 -> V_53 ) ;
F_61 ( V_22 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_3 * V_54 ,
struct V_1 * * V_55 )
{
F_65 ( V_2 , V_55 ) ;
return V_56 ;
}
static struct V_1 * F_66 ( struct V_3 * V_54 )
{
return NULL ;
}
static int F_67 ( struct V_3 * V_54 , struct V_57 * V_58 )
{
V_54 -> V_59 = NULL ;
return 0 ;
}
static inline struct V_60 * F_68 ( struct V_61 * V_62 ,
int V_63 )
{
return V_62 -> V_4 + V_63 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_54 ,
struct V_1 * * V_55 )
{
if ( V_54 -> V_4 . V_8 < F_29 ( V_54 ) -> V_64 ) {
int V_63 = V_65 [ V_2 -> V_66 & V_67 ] ;
struct V_61 * V_62 = F_70 ( V_54 ) ;
struct V_60 * V_68 = F_68 ( V_62 , V_63 ) ;
V_62 -> V_69 |= ( 1 << V_63 ) ;
V_54 -> V_4 . V_8 ++ ;
return F_71 ( V_2 , V_54 , V_68 ) ;
}
return F_72 ( V_2 , V_54 , V_55 ) ;
}
static struct V_1 * F_73 ( struct V_3 * V_54 )
{
struct V_61 * V_62 = F_70 ( V_54 ) ;
int V_63 = V_70 [ V_62 -> V_69 ] ;
if ( F_18 ( V_63 >= 0 ) ) {
struct V_60 * V_71 = F_68 ( V_62 , V_63 ) ;
struct V_1 * V_2 = F_74 ( V_71 ) ;
if ( F_18 ( V_2 != NULL ) ) {
F_12 ( V_54 , V_2 ) ;
F_75 ( V_54 , V_2 ) ;
}
V_54 -> V_4 . V_8 -- ;
if ( V_71 -> V_8 == 0 )
V_62 -> V_69 &= ~ ( 1 << V_63 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_76 ( struct V_3 * V_54 )
{
struct V_61 * V_62 = F_70 ( V_54 ) ;
int V_63 = V_70 [ V_62 -> V_69 ] ;
if ( V_63 >= 0 ) {
struct V_60 * V_71 = F_68 ( V_62 , V_63 ) ;
return V_71 -> V_72 ;
}
return NULL ;
}
static void F_77 ( struct V_3 * V_54 )
{
int V_73 ;
struct V_61 * V_62 = F_70 ( V_54 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_78 ( F_68 ( V_62 , V_73 ) ) ;
V_62 -> V_69 = 0 ;
V_54 -> V_6 . V_75 = 0 ;
V_54 -> V_4 . V_8 = 0 ;
}
static int F_79 ( struct V_3 * V_54 , struct V_1 * V_2 )
{
struct V_76 V_58 = { . V_77 = V_74 } ;
memcpy ( & V_58 . V_78 , V_65 , V_67 + 1 ) ;
if ( F_80 ( V_2 , V_79 , sizeof( V_58 ) , & V_58 ) )
goto V_80;
return V_2 -> V_13 ;
V_80:
return - 1 ;
}
static int F_81 ( struct V_3 * V_54 , struct V_57 * V_58 )
{
int V_73 ;
struct V_61 * V_62 = F_70 ( V_54 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_82 ( F_68 ( V_62 , V_73 ) ) ;
V_54 -> V_25 |= V_81 ;
return 0 ;
}
struct V_3 * F_83 ( struct V_9 * V_21 ,
const struct V_82 * V_83 )
{
void * V_84 ;
struct V_3 * V_85 ;
unsigned int V_86 = F_84 ( sizeof( * V_85 ) ) + V_83 -> V_87 ;
int V_88 = - V_89 ;
struct V_27 * V_22 = V_21 -> V_22 ;
V_84 = F_85 ( V_86 , V_90 ,
F_86 ( V_21 ) ) ;
if ( ! V_84 )
goto V_91;
V_85 = (struct V_3 * ) F_84 ( ( unsigned long ) V_84 ) ;
if ( V_85 != V_84 ) {
F_87 ( V_84 ) ;
V_84 = F_85 ( V_86 + V_92 - 1 , V_90 ,
F_86 ( V_21 ) ) ;
if ( ! V_84 )
goto V_91;
V_85 = (struct V_3 * ) F_84 ( ( unsigned long ) V_84 ) ;
V_85 -> V_93 = ( char * ) V_85 - ( char * ) V_84 ;
}
F_82 ( & V_85 -> V_4 ) ;
F_88 ( & V_85 -> V_4 . V_94 ) ;
F_88 ( & V_85 -> V_95 ) ;
F_89 ( & V_85 -> V_95 ,
V_22 -> V_96 ? : & V_96 ) ;
F_90 ( & V_85 -> V_97 ) ;
F_89 ( & V_85 -> V_97 ,
V_22 -> V_98 ? : & V_98 ) ;
V_85 -> V_83 = V_83 ;
V_85 -> V_59 = V_83 -> V_59 ;
V_85 -> V_15 = V_83 -> V_15 ;
V_85 -> V_21 = V_21 ;
F_49 ( V_22 ) ;
F_91 ( & V_85 -> V_99 , 1 ) ;
return V_85 ;
V_91:
return F_92 ( V_88 ) ;
}
struct V_3 * F_93 ( struct V_9 * V_21 ,
const struct V_82 * V_83 ,
unsigned int V_100 )
{
struct V_3 * V_85 ;
if ( ! F_94 ( V_83 -> V_101 ) )
return NULL ;
V_85 = F_83 ( V_21 , V_83 ) ;
if ( F_95 ( V_85 ) ) {
F_96 ( V_83 -> V_101 ) ;
return NULL ;
}
V_85 -> V_102 = V_100 ;
if ( ! V_83 -> V_103 || V_83 -> V_103 ( V_85 , NULL ) == 0 )
return V_85 ;
F_97 ( V_85 ) ;
return NULL ;
}
void F_98 ( struct V_3 * V_54 )
{
const struct V_82 * V_83 = V_54 -> V_83 ;
if ( V_83 -> V_104 )
V_83 -> V_104 ( V_54 ) ;
F_99 ( V_54 -> V_19 ) ;
V_54 -> V_19 = NULL ;
if ( V_54 -> V_5 ) {
F_100 ( V_54 -> V_5 ) ;
V_54 -> V_5 = NULL ;
}
V_54 -> V_4 . V_8 = 0 ;
V_54 -> V_6 . V_75 = 0 ;
}
static void F_101 ( struct V_105 * V_72 )
{
struct V_3 * V_54 = F_102 ( V_72 , struct V_3 , V_105 ) ;
if ( F_103 ( V_54 ) ) {
F_104 ( V_54 -> V_106 ) ;
F_104 ( V_54 -> V_107 ) ;
}
F_87 ( ( char * ) V_54 - V_54 -> V_93 ) ;
}
void F_97 ( struct V_3 * V_54 )
{
const struct V_82 * V_83 = V_54 -> V_83 ;
if ( V_54 -> V_25 & V_108 ||
! F_105 ( & V_54 -> V_99 ) )
return;
#ifdef F_106
F_107 ( V_54 ) ;
F_108 ( F_109 ( V_54 -> V_109 ) ) ;
#endif
F_110 ( & V_54 -> V_110 ) ;
if ( V_83 -> V_104 )
V_83 -> V_104 ( V_54 ) ;
if ( V_83 -> V_111 )
V_83 -> V_111 ( V_54 ) ;
F_96 ( V_83 -> V_101 ) ;
F_51 ( F_29 ( V_54 ) ) ;
F_100 ( V_54 -> V_5 ) ;
F_99 ( V_54 -> V_19 ) ;
F_111 ( & V_54 -> V_105 , F_101 ) ;
}
struct V_3 * F_112 ( struct V_9 * V_21 ,
struct V_3 * V_54 )
{
struct V_3 * V_112 = V_21 -> V_113 ;
T_1 * V_28 ;
V_28 = F_28 ( V_112 ) ;
F_113 ( V_28 ) ;
if ( V_112 && F_114 ( & V_112 -> V_99 ) <= 1 )
F_98 ( V_112 ) ;
if ( V_54 == NULL )
V_54 = & V_114 ;
V_21 -> V_113 = V_54 ;
F_115 ( V_21 -> V_54 , & V_114 ) ;
F_116 ( V_28 ) ;
return V_112 ;
}
static void F_117 ( struct V_27 * V_22 ,
struct V_9 * V_21 ,
void * V_115 )
{
struct V_3 * V_54 ;
const struct V_82 * V_83 = V_116 ;
if ( V_22 -> V_117 & V_118 )
V_83 = & V_119 ;
V_54 = F_93 ( V_21 , V_83 , V_120 ) ;
if ( ! V_54 ) {
F_118 ( V_22 , L_3 ) ;
return;
}
if ( ! F_119 ( V_22 ) )
V_54 -> V_25 |= V_26 | V_121 ;
V_21 -> V_113 = V_54 ;
}
static void F_120 ( struct V_27 * V_22 )
{
struct V_9 * V_10 ;
struct V_3 * V_54 ;
V_10 = F_36 ( V_22 , 0 ) ;
if ( ! F_119 ( V_22 ) ||
V_22 -> V_117 & V_118 ) {
F_121 ( V_22 , F_117 , NULL ) ;
V_22 -> V_54 = V_10 -> V_113 ;
F_122 ( V_22 -> V_54 ) ;
} else {
V_54 = F_93 ( V_10 , & V_122 , V_120 ) ;
if ( V_54 ) {
V_22 -> V_54 = V_54 ;
V_54 -> V_83 -> V_123 ( V_54 ) ;
}
}
#ifdef F_106
if ( V_22 -> V_54 != & V_114 )
F_123 ( V_22 -> V_54 , false ) ;
#endif
}
static void F_124 ( struct V_27 * V_22 ,
struct V_9 * V_21 ,
void * V_124 )
{
struct V_3 * V_125 = V_21 -> V_113 ;
int * V_126 = V_124 ;
if ( ! ( V_125 -> V_25 & V_108 ) )
F_125 ( V_127 , & V_125 -> V_50 ) ;
F_115 ( V_21 -> V_54 , V_125 ) ;
if ( V_126 ) {
V_21 -> V_37 = 0 ;
* V_126 = 1 ;
}
}
void F_126 ( struct V_27 * V_22 )
{
int V_128 ;
if ( V_22 -> V_54 == & V_114 )
F_120 ( V_22 ) ;
if ( ! F_43 ( V_22 ) )
return;
V_128 = 0 ;
F_121 ( V_22 , F_124 , & V_128 ) ;
if ( F_127 ( V_22 ) )
F_124 ( V_22 , F_127 ( V_22 ) , NULL ) ;
if ( V_128 ) {
F_128 ( V_22 ) ;
F_53 ( V_22 ) ;
}
}
static void F_129 ( struct V_27 * V_22 ,
struct V_9 * V_21 ,
void * V_129 )
{
struct V_3 * V_130 = V_129 ;
struct V_3 * V_54 ;
V_54 = F_109 ( V_21 -> V_54 ) ;
if ( V_54 ) {
F_113 ( F_28 ( V_54 ) ) ;
if ( ! ( V_54 -> V_25 & V_108 ) )
F_130 ( V_127 , & V_54 -> V_50 ) ;
F_115 ( V_21 -> V_54 , V_130 ) ;
F_98 ( V_54 ) ;
F_116 ( F_28 ( V_54 ) ) ;
}
}
static bool F_131 ( struct V_27 * V_22 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_22 -> V_38 ; V_36 ++ ) {
struct V_9 * V_21 ;
T_1 * V_28 ;
struct V_3 * V_4 ;
int V_34 ;
V_21 = F_36 ( V_22 , V_36 ) ;
V_4 = V_21 -> V_113 ;
V_28 = F_28 ( V_4 ) ;
F_113 ( V_28 ) ;
V_34 = ( F_132 ( V_4 ) ||
F_133 ( V_131 , & V_4 -> V_50 ) ) ;
F_116 ( V_28 ) ;
if ( V_34 )
return true ;
}
return false ;
}
void F_134 ( struct V_132 * V_72 )
{
struct V_27 * V_22 ;
bool V_133 = false ;
F_135 (dev, head, close_list) {
F_121 ( V_22 , F_129 ,
& V_114 ) ;
if ( F_127 ( V_22 ) )
F_129 ( V_22 , F_127 ( V_22 ) ,
& V_114 ) ;
F_54 ( V_22 ) ;
V_133 |= ! V_22 -> V_134 ;
}
if ( V_133 )
F_136 () ;
F_135 (dev, head, close_list)
while ( F_131 ( V_22 ) )
F_137 () ;
}
void F_138 ( struct V_27 * V_22 )
{
F_139 ( V_135 ) ;
F_140 ( & V_22 -> V_136 , & V_135 ) ;
F_134 ( & V_135 ) ;
F_141 ( & V_135 ) ;
}
static void F_142 ( struct V_27 * V_22 ,
struct V_9 * V_21 ,
void * V_137 )
{
struct V_3 * V_54 = V_137 ;
F_115 ( V_21 -> V_54 , V_54 ) ;
V_21 -> V_113 = V_54 ;
}
void F_143 ( struct V_27 * V_22 )
{
V_22 -> V_54 = & V_114 ;
F_121 ( V_22 , F_142 , & V_114 ) ;
if ( F_127 ( V_22 ) )
F_142 ( V_22 , F_127 ( V_22 ) , & V_114 ) ;
F_144 ( & V_22 -> V_47 , F_38 , ( unsigned long ) V_22 ) ;
}
static void F_145 ( struct V_27 * V_22 ,
struct V_9 * V_21 ,
void * V_129 )
{
struct V_3 * V_54 = V_21 -> V_113 ;
struct V_3 * V_130 = V_129 ;
if ( V_54 ) {
F_115 ( V_21 -> V_54 , V_130 ) ;
V_21 -> V_113 = V_130 ;
F_97 ( V_54 ) ;
}
}
void F_146 ( struct V_27 * V_22 )
{
F_121 ( V_22 , F_145 , & V_114 ) ;
if ( F_127 ( V_22 ) )
F_145 ( V_22 , F_127 ( V_22 ) , & V_114 ) ;
F_97 ( V_22 -> V_54 ) ;
V_22 -> V_54 = & V_114 ;
F_147 ( F_148 ( & V_22 -> V_47 ) ) ;
}
void F_149 ( struct V_138 * V_139 ,
const struct V_140 * V_141 ,
T_2 V_142 )
{
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> V_143 = V_141 -> V_143 ;
V_139 -> V_144 = F_150 ( T_2 , V_141 -> V_145 , V_142 ) ;
V_139 -> V_146 = ( V_141 -> V_146 & V_147 ) ;
V_139 -> V_148 = 1 ;
if ( V_139 -> V_144 > 0 ) {
T_2 V_149 = V_150 ;
for (; ; ) {
V_139 -> V_148 = F_151 ( V_149 , V_139 -> V_144 ) ;
if ( V_139 -> V_148 & ( 1U << 31 ) || V_149 & ( 1ULL << 63 ) )
break;
V_149 <<= 1 ;
V_139 -> V_151 ++ ;
}
}
}
