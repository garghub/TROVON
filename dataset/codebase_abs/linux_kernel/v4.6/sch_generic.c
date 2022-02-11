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
if ( F_19 ( V_2 ) ) {
F_20 ( V_19 , V_10 , F_11 () ) ;
if ( ! F_8 ( V_10 ) )
V_2 = F_21 ( V_2 , V_19 , V_10 , & V_22 ) ;
F_22 ( V_19 , V_10 ) ;
} else {
F_23 ( V_28 ) ;
return F_14 ( V_4 ) ;
}
F_23 ( V_28 ) ;
if ( F_24 ( V_22 ) ) {
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
static inline int F_25 ( struct V_3 * V_4 , int * V_11 )
{
struct V_9 * V_10 ;
struct V_27 * V_19 ;
T_1 * V_28 ;
struct V_1 * V_2 ;
bool V_17 ;
V_2 = F_5 ( V_4 , & V_17 , V_11 ) ;
if ( F_6 ( ! V_2 ) )
return 0 ;
V_28 = F_26 ( V_4 ) ;
V_19 = F_27 ( V_4 ) ;
V_10 = F_7 ( V_19 , V_2 ) ;
return F_16 ( V_2 , V_4 , V_19 , V_10 , V_28 , V_17 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
int V_31 = V_32 ;
int V_11 ;
while ( F_25 ( V_4 , & V_11 ) ) {
V_31 -= V_11 ;
if ( V_31 <= 0 || F_29 () ) {
F_2 ( V_4 ) ;
break;
}
}
F_30 ( V_4 ) ;
}
unsigned long F_31 ( struct V_27 * V_19 )
{
unsigned long V_33 , V_34 ;
unsigned int V_35 ;
if ( F_32 ( V_19 ) )
V_19 = F_33 ( V_19 ) ;
V_34 = V_19 -> V_36 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
V_33 = F_34 ( V_19 , V_35 ) -> V_36 ;
if ( V_33 && F_35 ( V_33 , V_34 ) )
V_34 = V_33 ;
}
V_19 -> V_36 = V_34 ;
return V_34 ;
}
static void F_36 ( unsigned long V_38 )
{
struct V_27 * V_19 = (struct V_27 * ) V_38 ;
F_37 ( V_19 ) ;
if ( ! F_38 ( V_19 ) ) {
if ( F_39 ( V_19 ) &&
F_40 ( V_19 ) &&
F_41 ( V_19 ) ) {
int V_39 = 0 ;
unsigned int V_35 ;
unsigned long V_36 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
struct V_9 * V_10 ;
V_10 = F_34 ( V_19 , V_35 ) ;
V_36 = V_10 -> V_36 ? : V_19 -> V_36 ;
if ( F_42 ( V_10 ) &&
F_35 ( V_40 , ( V_36 +
V_19 -> V_41 ) ) ) {
V_39 = 1 ;
V_10 -> V_42 ++ ;
break;
}
}
if ( V_39 ) {
F_43 ( 1 , V_43 L_3 ,
V_19 -> V_24 , F_44 ( V_19 ) , V_35 ) ;
V_19 -> V_44 -> V_45 ( V_19 ) ;
}
if ( ! F_45 ( & V_19 -> V_46 ,
F_46 ( V_40 +
V_19 -> V_41 ) ) )
F_47 ( V_19 ) ;
}
}
F_48 ( V_19 ) ;
F_49 ( V_19 ) ;
}
void F_50 ( struct V_27 * V_19 )
{
if ( V_19 -> V_44 -> V_45 ) {
if ( V_19 -> V_41 <= 0 )
V_19 -> V_41 = 5 * V_47 ;
if ( ! F_45 ( & V_19 -> V_46 ,
F_46 ( V_40 + V_19 -> V_41 ) ) )
F_47 ( V_19 ) ;
}
}
static void F_51 ( struct V_27 * V_19 )
{
F_50 ( V_19 ) ;
}
static void F_52 ( struct V_27 * V_19 )
{
F_53 ( V_19 ) ;
if ( F_54 ( & V_19 -> V_46 ) )
F_49 ( V_19 ) ;
F_55 ( V_19 ) ;
}
void F_56 ( struct V_27 * V_19 )
{
if ( F_57 ( V_48 , & V_19 -> V_49 ) ) {
if ( V_19 -> V_50 == V_51 )
return;
F_58 ( & V_19 -> V_52 ) ;
F_59 ( V_19 ) ;
if ( F_40 ( V_19 ) )
F_50 ( V_19 ) ;
}
}
void F_60 ( struct V_27 * V_19 )
{
if ( ! F_61 ( V_48 , & V_19 -> V_49 ) ) {
if ( V_19 -> V_50 == V_51 )
return;
F_58 ( & V_19 -> V_52 ) ;
F_59 ( V_19 ) ;
}
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_53 )
{
F_63 ( V_2 ) ;
return V_54 ;
}
static struct V_1 * F_64 ( struct V_3 * V_53 )
{
return NULL ;
}
static int F_65 ( struct V_3 * V_53 , struct V_55 * V_56 )
{
V_53 -> V_57 = NULL ;
return 0 ;
}
static inline struct V_58 * F_66 ( struct V_59 * V_60 ,
int V_61 )
{
return V_60 -> V_4 + V_61 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_3 * V_53 )
{
if ( F_68 ( & V_53 -> V_4 ) < F_27 ( V_53 ) -> V_62 ) {
int V_61 = V_63 [ V_2 -> V_64 & V_65 ] ;
struct V_59 * V_60 = F_69 ( V_53 ) ;
struct V_58 * V_66 = F_66 ( V_60 , V_61 ) ;
V_60 -> V_67 |= ( 1 << V_61 ) ;
V_53 -> V_4 . V_8 ++ ;
return F_70 ( V_2 , V_53 , V_66 ) ;
}
return F_71 ( V_2 , V_53 ) ;
}
static struct V_1 * F_72 ( struct V_3 * V_53 )
{
struct V_59 * V_60 = F_69 ( V_53 ) ;
int V_61 = V_68 [ V_60 -> V_67 ] ;
if ( F_19 ( V_61 >= 0 ) ) {
struct V_58 * V_66 = F_66 ( V_60 , V_61 ) ;
struct V_1 * V_2 = F_73 ( V_53 , V_66 ) ;
V_53 -> V_4 . V_8 -- ;
if ( F_74 ( V_66 ) )
V_60 -> V_67 &= ~ ( 1 << V_61 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_75 ( struct V_3 * V_53 )
{
struct V_59 * V_60 = F_69 ( V_53 ) ;
int V_61 = V_68 [ V_60 -> V_67 ] ;
if ( V_61 >= 0 ) {
struct V_58 * V_66 = F_66 ( V_60 , V_61 ) ;
return F_76 ( V_66 ) ;
}
return NULL ;
}
static void F_77 ( struct V_3 * V_53 )
{
int V_69 ;
struct V_59 * V_60 = F_69 ( V_53 ) ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_78 ( V_53 , F_66 ( V_60 , V_69 ) ) ;
V_60 -> V_67 = 0 ;
V_53 -> V_6 . V_71 = 0 ;
V_53 -> V_4 . V_8 = 0 ;
}
static int F_79 ( struct V_3 * V_53 , struct V_1 * V_2 )
{
struct V_72 V_56 = { . V_73 = V_70 } ;
memcpy ( & V_56 . V_74 , V_63 , V_65 + 1 ) ;
if ( F_80 ( V_2 , V_75 , sizeof( V_56 ) , & V_56 ) )
goto V_76;
return V_2 -> V_13 ;
V_76:
return - 1 ;
}
static int F_81 ( struct V_3 * V_53 , struct V_55 * V_56 )
{
int V_69 ;
struct V_59 * V_60 = F_69 ( V_53 ) ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_82 ( F_66 ( V_60 , V_69 ) ) ;
V_53 -> V_20 |= V_77 ;
return 0 ;
}
struct V_3 * F_83 ( struct V_9 * V_18 ,
const struct V_78 * V_79 )
{
void * V_80 ;
struct V_3 * V_81 ;
unsigned int V_82 = F_84 ( sizeof( * V_81 ) ) + V_79 -> V_83 ;
int V_84 = - V_85 ;
struct V_27 * V_19 = V_18 -> V_19 ;
V_80 = F_85 ( V_82 , V_86 ,
F_86 ( V_18 ) ) ;
if ( ! V_80 )
goto V_87;
V_81 = (struct V_3 * ) F_84 ( ( unsigned long ) V_80 ) ;
if ( V_81 != V_80 ) {
F_87 ( V_80 ) ;
V_80 = F_85 ( V_82 + V_88 - 1 , V_86 ,
F_86 ( V_18 ) ) ;
if ( ! V_80 )
goto V_87;
V_81 = (struct V_3 * ) F_84 ( ( unsigned long ) V_80 ) ;
V_81 -> V_89 = ( char * ) V_81 - ( char * ) V_80 ;
}
F_88 ( & V_81 -> V_66 ) ;
F_89 ( & V_81 -> V_4 ) ;
F_90 ( & V_81 -> V_90 ) ;
F_91 ( & V_81 -> V_90 ,
V_19 -> V_91 ? : & V_91 ) ;
V_81 -> V_79 = V_79 ;
V_81 -> V_57 = V_79 -> V_57 ;
V_81 -> V_15 = V_79 -> V_15 ;
V_81 -> V_18 = V_18 ;
F_47 ( V_19 ) ;
F_92 ( & V_81 -> V_92 , 1 ) ;
return V_81 ;
V_87:
return F_93 ( V_84 ) ;
}
struct V_3 * F_94 ( struct V_9 * V_18 ,
const struct V_78 * V_79 ,
unsigned int V_93 )
{
struct V_3 * V_81 ;
if ( ! F_95 ( V_79 -> V_94 ) )
goto V_87;
V_81 = F_83 ( V_18 , V_79 ) ;
if ( F_96 ( V_81 ) )
goto V_87;
V_81 -> V_95 = V_93 ;
if ( ! V_79 -> V_96 || V_79 -> V_96 ( V_81 , NULL ) == 0 )
return V_81 ;
F_97 ( V_81 ) ;
V_87:
return NULL ;
}
void F_98 ( struct V_3 * V_53 )
{
const struct V_78 * V_79 = V_53 -> V_79 ;
if ( V_79 -> V_97 )
V_79 -> V_97 ( V_53 ) ;
if ( V_53 -> V_5 ) {
F_12 ( V_53 -> V_5 ) ;
V_53 -> V_5 = NULL ;
V_53 -> V_4 . V_8 = 0 ;
}
}
static void F_99 ( struct V_98 * V_99 )
{
struct V_3 * V_53 = F_100 ( V_99 , struct V_3 , V_98 ) ;
if ( F_101 ( V_53 ) ) {
F_102 ( V_53 -> V_100 ) ;
F_102 ( V_53 -> V_101 ) ;
}
F_87 ( ( char * ) V_53 - V_53 -> V_89 ) ;
}
void F_97 ( struct V_3 * V_53 )
{
const struct V_78 * V_79 = V_53 -> V_79 ;
if ( V_53 -> V_20 & V_102 ||
! F_103 ( & V_53 -> V_92 ) )
return;
#ifdef F_104
F_105 ( V_53 ) ;
F_106 ( F_107 ( V_53 -> V_103 ) ) ;
#endif
F_108 ( & V_53 -> V_104 , & V_53 -> V_105 ) ;
if ( V_79 -> V_97 )
V_79 -> V_97 ( V_53 ) ;
if ( V_79 -> V_106 )
V_79 -> V_106 ( V_53 ) ;
F_109 ( V_79 -> V_94 ) ;
F_49 ( F_27 ( V_53 ) ) ;
F_12 ( V_53 -> V_5 ) ;
F_110 ( & V_53 -> V_98 , F_99 ) ;
}
struct V_3 * F_111 ( struct V_9 * V_18 ,
struct V_3 * V_53 )
{
struct V_3 * V_107 = V_18 -> V_108 ;
T_1 * V_28 ;
V_28 = F_26 ( V_107 ) ;
F_112 ( V_28 ) ;
if ( V_107 && F_113 ( & V_107 -> V_92 ) <= 1 )
F_98 ( V_107 ) ;
if ( V_53 == NULL )
V_53 = & V_109 ;
V_18 -> V_108 = V_53 ;
F_114 ( V_18 -> V_53 , & V_109 ) ;
F_115 ( V_28 ) ;
return V_107 ;
}
static void F_116 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_110 )
{
struct V_3 * V_53 ;
const struct V_78 * V_79 = V_111 ;
if ( V_19 -> V_112 & V_113 )
V_79 = & V_114 ;
V_53 = F_94 ( V_18 , V_79 , V_115 ) ;
if ( ! V_53 ) {
F_117 ( V_19 , L_4 ) ;
return;
}
if ( ! F_118 ( V_19 ) )
V_53 -> V_20 |= V_21 | V_116 ;
V_18 -> V_108 = V_53 ;
}
static void F_119 ( struct V_27 * V_19 )
{
struct V_9 * V_10 ;
struct V_3 * V_53 ;
V_10 = F_34 ( V_19 , 0 ) ;
if ( ! F_118 ( V_19 ) ||
V_19 -> V_112 & V_113 ) {
F_120 ( V_19 , F_116 , NULL ) ;
V_19 -> V_53 = V_10 -> V_108 ;
F_58 ( & V_19 -> V_53 -> V_92 ) ;
} else {
V_53 = F_94 ( V_10 , & V_117 , V_115 ) ;
if ( V_53 ) {
V_19 -> V_53 = V_53 ;
V_53 -> V_79 -> V_118 ( V_53 ) ;
}
}
}
static void F_121 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_119 )
{
struct V_3 * V_120 = V_18 -> V_108 ;
int * V_121 = V_119 ;
if ( ! ( V_120 -> V_20 & V_102 ) )
F_122 ( V_122 , & V_120 -> V_49 ) ;
F_114 ( V_18 -> V_53 , V_120 ) ;
if ( V_121 ) {
V_18 -> V_36 = 0 ;
* V_121 = 1 ;
}
}
void F_123 ( struct V_27 * V_19 )
{
int V_123 ;
if ( V_19 -> V_53 == & V_109 )
F_119 ( V_19 ) ;
if ( ! F_41 ( V_19 ) )
return;
V_123 = 0 ;
F_120 ( V_19 , F_121 , & V_123 ) ;
if ( F_124 ( V_19 ) )
F_121 ( V_19 , F_124 ( V_19 ) , NULL ) ;
if ( V_123 ) {
V_19 -> V_36 = V_40 ;
F_51 ( V_19 ) ;
}
}
static void F_125 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_124 )
{
struct V_3 * V_125 = V_124 ;
struct V_3 * V_53 ;
V_53 = F_107 ( V_18 -> V_53 ) ;
if ( V_53 ) {
F_112 ( F_26 ( V_53 ) ) ;
if ( ! ( V_53 -> V_20 & V_102 ) )
F_126 ( V_122 , & V_53 -> V_49 ) ;
F_114 ( V_18 -> V_53 , V_125 ) ;
F_98 ( V_53 ) ;
F_115 ( F_26 ( V_53 ) ) ;
}
}
static bool F_127 ( struct V_27 * V_19 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_37 ; V_35 ++ ) {
struct V_9 * V_18 ;
T_1 * V_28 ;
struct V_3 * V_4 ;
int V_33 ;
V_18 = F_34 ( V_19 , V_35 ) ;
V_4 = V_18 -> V_108 ;
V_28 = F_26 ( V_4 ) ;
F_112 ( V_28 ) ;
V_33 = ( F_128 ( V_4 ) ||
F_129 ( V_126 , & V_4 -> V_49 ) ) ;
F_115 ( V_28 ) ;
if ( V_33 )
return true ;
}
return false ;
}
void F_130 ( struct V_127 * V_99 )
{
struct V_27 * V_19 ;
bool V_128 = false ;
F_131 (dev, head, close_list) {
F_120 ( V_19 , F_125 ,
& V_109 ) ;
if ( F_124 ( V_19 ) )
F_125 ( V_19 , F_124 ( V_19 ) ,
& V_109 ) ;
F_52 ( V_19 ) ;
V_128 |= ! V_19 -> V_129 ;
}
if ( V_128 )
F_132 () ;
F_131 (dev, head, close_list)
while ( F_127 ( V_19 ) )
F_133 () ;
}
void F_134 ( struct V_27 * V_19 )
{
F_135 ( V_130 ) ;
F_136 ( & V_19 -> V_131 , & V_130 ) ;
F_130 ( & V_130 ) ;
F_137 ( & V_130 ) ;
}
static void F_138 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_132 )
{
struct V_3 * V_53 = V_132 ;
F_114 ( V_18 -> V_53 , V_53 ) ;
V_18 -> V_108 = V_53 ;
}
void F_139 ( struct V_27 * V_19 )
{
V_19 -> V_53 = & V_109 ;
F_120 ( V_19 , F_138 , & V_109 ) ;
if ( F_124 ( V_19 ) )
F_138 ( V_19 , F_124 ( V_19 ) , & V_109 ) ;
F_140 ( & V_19 -> V_46 , F_36 , ( unsigned long ) V_19 ) ;
}
static void F_141 ( struct V_27 * V_19 ,
struct V_9 * V_18 ,
void * V_124 )
{
struct V_3 * V_53 = V_18 -> V_108 ;
struct V_3 * V_125 = V_124 ;
if ( V_53 ) {
F_114 ( V_18 -> V_53 , V_125 ) ;
V_18 -> V_108 = V_125 ;
F_97 ( V_53 ) ;
}
}
void F_142 ( struct V_27 * V_19 )
{
F_120 ( V_19 , F_141 , & V_109 ) ;
if ( F_124 ( V_19 ) )
F_141 ( V_19 , F_124 ( V_19 ) , & V_109 ) ;
F_97 ( V_19 -> V_53 ) ;
V_19 -> V_53 = & V_109 ;
F_143 ( F_144 ( & V_19 -> V_46 ) ) ;
}
void F_145 ( struct V_133 * V_134 ,
const struct V_135 * V_136 ,
T_2 V_137 )
{
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
V_134 -> V_138 = V_136 -> V_138 ;
V_134 -> V_139 = F_146 ( T_2 , V_136 -> V_140 , V_137 ) ;
V_134 -> V_141 = ( V_136 -> V_141 & V_142 ) ;
V_134 -> V_143 = 1 ;
if ( V_134 -> V_139 > 0 ) {
T_2 V_144 = V_145 ;
for (; ; ) {
V_134 -> V_143 = F_147 ( V_144 , V_134 -> V_139 ) ;
if ( V_134 -> V_143 & ( 1U << 31 ) || V_144 & ( 1ULL << 63 ) )
break;
V_144 <<= 1 ;
V_134 -> V_146 ++ ;
}
}
}
