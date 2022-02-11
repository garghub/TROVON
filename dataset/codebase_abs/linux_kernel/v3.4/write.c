struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_2 && ( V_2 -> V_6 != & V_2 -> V_7 [ 0 ] ) )
F_5 ( V_2 -> V_6 ) ;
F_6 ( V_2 , V_3 ) ;
}
struct V_1 * F_7 ( unsigned int V_8 )
{
struct V_1 * V_2 = F_2 ( V_9 , V_4 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
V_2 -> V_10 = V_8 ;
if ( V_8 <= F_8 ( V_2 -> V_7 ) )
V_2 -> V_6 = V_2 -> V_7 ;
else {
V_2 -> V_6 = F_9 ( V_8 , sizeof( struct V_11 * ) , V_4 ) ;
if ( ! V_2 -> V_6 ) {
F_6 ( V_2 , V_9 ) ;
V_2 = NULL ;
}
}
}
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 && ( V_2 -> V_6 != & V_2 -> V_7 [ 0 ] ) )
F_5 ( V_2 -> V_6 ) ;
F_6 ( V_2 , V_9 ) ;
}
void F_11 ( struct V_1 * V_12 )
{
F_12 ( V_12 -> args . V_13 ) ;
F_10 ( V_12 ) ;
}
static void F_13 ( struct V_14 * V_15 , int error )
{
V_15 -> error = error ;
F_14 () ;
F_15 ( V_16 , & V_15 -> V_17 ) ;
}
static struct V_18 * F_16 ( struct V_11 * V_11 )
{
struct V_18 * V_19 = NULL ;
if ( F_17 ( V_11 ) ) {
V_19 = (struct V_18 * ) F_18 ( V_11 ) ;
if ( V_19 != NULL )
F_19 ( & V_19 -> V_20 ) ;
}
return V_19 ;
}
static struct V_18 * F_20 ( struct V_11 * V_11 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
struct V_18 * V_19 = NULL ;
F_21 ( & V_21 -> V_24 ) ;
V_19 = F_16 ( V_11 ) ;
F_22 ( & V_21 -> V_24 ) ;
return V_19 ;
}
static void F_23 ( struct V_11 * V_11 , unsigned int V_25 , unsigned int V_26 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
T_1 V_27 , V_28 ;
T_2 V_29 ;
F_21 ( & V_21 -> V_24 ) ;
V_28 = F_24 ( V_21 ) ;
V_29 = ( V_28 - 1 ) >> V_30 ;
if ( V_28 > 0 && V_11 -> V_31 < V_29 )
goto V_32;
V_27 = ( ( T_1 ) V_11 -> V_31 << V_30 ) + ( ( T_1 ) V_25 + V_26 ) ;
if ( V_28 >= V_27 )
goto V_32;
F_25 ( V_21 , V_27 ) ;
F_26 ( V_21 , V_33 ) ;
V_32:
F_22 ( & V_21 -> V_24 ) ;
}
static void F_27 ( struct V_11 * V_11 )
{
F_28 ( V_11 ) ;
F_29 ( V_11 -> V_22 -> V_23 , V_11 -> V_22 ) ;
}
static void F_30 ( struct V_11 * V_11 , unsigned int V_34 , unsigned int V_26 )
{
if ( F_31 ( V_11 ) )
return;
if ( V_34 != 0 )
return;
if ( V_26 != F_32 ( V_11 ) )
return;
F_33 ( V_11 ) ;
}
static int F_34 ( struct V_35 * V_36 )
{
if ( V_36 -> V_37 )
return V_38 | V_39 ;
if ( V_36 -> V_40 || V_36 -> V_41 )
return V_42 | V_43 ;
return V_43 ;
}
static int F_35 ( struct V_11 * V_11 )
{
int V_44 = F_36 ( V_11 ) ;
if ( ! V_44 ) {
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
struct V_45 * V_46 = F_37 ( V_21 ) ;
F_38 ( V_11 ) ;
if ( F_39 ( & V_46 -> V_47 ) >
V_48 ) {
F_40 ( & V_46 -> V_49 ,
V_50 ) ;
}
}
return V_44 ;
}
static void F_41 ( struct V_11 * V_11 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
struct V_45 * V_46 = F_37 ( V_21 ) ;
F_42 ( V_11 ) ;
F_43 ( V_11 ) ;
if ( F_44 ( & V_46 -> V_47 ) < V_51 )
F_45 ( & V_46 -> V_49 , V_50 ) ;
}
static struct V_18 * F_46 ( struct V_11 * V_11 , bool V_52 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
struct V_18 * V_19 ;
int V_44 ;
F_21 ( & V_21 -> V_24 ) ;
for (; ; ) {
V_19 = F_16 ( V_11 ) ;
if ( V_19 == NULL )
break;
if ( F_47 ( V_19 ) )
break;
F_22 ( & V_21 -> V_24 ) ;
if ( ! V_52 )
V_44 = F_48 ( V_19 ) ;
else
V_44 = - V_53 ;
F_49 ( V_19 ) ;
if ( V_44 != 0 )
return F_50 ( V_44 ) ;
F_21 ( & V_21 -> V_24 ) ;
}
F_22 ( & V_21 -> V_24 ) ;
return V_19 ;
}
static int F_51 ( struct V_54 * V_55 ,
struct V_11 * V_11 , bool V_52 )
{
struct V_18 * V_19 ;
int V_44 = 0 ;
V_19 = F_46 ( V_11 , V_52 ) ;
if ( ! V_19 )
goto V_32;
V_44 = F_52 ( V_19 ) ;
if ( F_53 ( V_19 ) )
goto V_32;
V_44 = F_35 ( V_11 ) ;
F_54 ( V_44 != 0 ) ;
F_54 ( F_55 ( V_56 , & V_19 -> V_57 ) ) ;
if ( ! F_56 ( V_55 , V_19 ) ) {
F_57 ( V_19 ) ;
V_44 = V_55 -> V_58 ;
}
V_32:
return V_44 ;
}
static int F_58 ( struct V_11 * V_11 , struct V_35 * V_36 , struct V_54 * V_55 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
int V_44 ;
F_26 ( V_21 , V_59 ) ;
F_59 ( V_21 , V_60 , 1 ) ;
F_60 ( V_55 , V_11 -> V_31 ) ;
V_44 = F_51 ( V_55 , V_11 , V_36 -> V_61 == V_62 ) ;
if ( V_44 == - V_53 ) {
F_61 ( V_36 , V_11 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_62 ( struct V_11 * V_11 , struct V_35 * V_36 )
{
struct V_54 V_55 ;
int V_63 ;
F_63 ( & V_55 , V_11 -> V_22 -> V_23 , F_34 ( V_36 ) ) ;
V_63 = F_58 ( V_11 , V_36 , & V_55 ) ;
F_64 ( & V_55 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_55 . V_58 < 0 )
return V_55 . V_58 ;
return 0 ;
}
int F_65 ( struct V_11 * V_11 , struct V_35 * V_36 )
{
int V_44 ;
V_44 = F_62 ( V_11 , V_36 ) ;
F_66 ( V_11 ) ;
return V_44 ;
}
static int F_67 ( struct V_11 * V_11 , struct V_35 * V_36 , void * V_64 )
{
int V_44 ;
V_44 = F_58 ( V_11 , V_36 , V_64 ) ;
F_66 ( V_11 ) ;
return V_44 ;
}
int F_68 ( struct V_65 * V_22 , struct V_35 * V_36 )
{
struct V_21 * V_21 = V_22 -> V_23 ;
unsigned long * V_66 = & F_69 ( V_21 ) -> V_17 ;
struct V_54 V_55 ;
int V_63 ;
V_63 = F_70 ( V_66 , V_67 ,
V_68 , V_69 ) ;
if ( V_63 )
goto V_70;
F_26 ( V_21 , V_71 ) ;
F_63 ( & V_55 , V_21 , F_34 ( V_36 ) ) ;
V_63 = F_71 ( V_22 , V_36 , F_67 , & V_55 ) ;
F_64 ( & V_55 ) ;
F_72 ( V_67 , V_66 ) ;
F_73 () ;
F_74 ( V_66 , V_67 ) ;
if ( V_63 < 0 )
goto V_70;
V_63 = V_55 . V_58 ;
if ( V_63 < 0 )
goto V_70;
return 0 ;
V_70:
return V_63 ;
}
static void F_75 ( struct V_21 * V_21 , struct V_18 * V_19 )
{
struct V_72 * V_73 = F_69 ( V_21 ) ;
F_47 ( V_19 ) ;
F_21 ( & V_21 -> V_24 ) ;
if ( ! V_73 -> V_10 && F_76 ( V_21 , V_74 ) )
V_21 -> V_75 ++ ;
F_15 ( V_76 , & V_19 -> V_57 ) ;
F_77 ( V_19 -> V_77 ) ;
F_78 ( V_19 -> V_77 , ( unsigned long ) V_19 ) ;
V_73 -> V_10 ++ ;
F_19 ( & V_19 -> V_20 ) ;
F_22 ( & V_21 -> V_24 ) ;
}
static void F_79 ( struct V_18 * V_19 )
{
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
struct V_72 * V_73 = F_69 ( V_21 ) ;
F_54 ( ! F_80 ( V_19 ) ) ;
F_21 ( & V_21 -> V_24 ) ;
F_78 ( V_19 -> V_77 , 0 ) ;
F_81 ( V_19 -> V_77 ) ;
F_82 ( V_76 , & V_19 -> V_57 ) ;
V_73 -> V_10 -- ;
F_22 ( & V_21 -> V_24 ) ;
F_49 ( V_19 ) ;
}
static void
F_83 ( struct V_18 * V_19 )
{
F_84 ( V_19 -> V_77 ) ;
}
void
F_85 ( struct V_18 * V_19 , struct V_81 * V_82 )
{
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
F_15 ( V_56 , & ( V_19 ) -> V_57 ) ;
F_21 ( & V_21 -> V_24 ) ;
F_86 ( V_19 , V_82 ) ;
F_69 ( V_21 ) -> V_83 ++ ;
F_22 ( & V_21 -> V_24 ) ;
F_87 ( V_19 -> V_77 , V_84 ) ;
F_88 ( V_19 -> V_77 -> V_22 -> V_49 , V_85 ) ;
F_89 ( V_21 , V_86 ) ;
}
void
F_90 ( struct V_18 * V_19 )
{
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
if ( ! F_91 ( V_56 , & ( V_19 ) -> V_57 ) )
return;
F_92 ( V_19 ) ;
F_69 ( V_21 ) -> V_83 -- ;
}
static void
F_93 ( struct V_18 * V_19 , struct V_87 * V_88 )
{
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
if ( F_94 ( V_19 , V_88 ) )
return;
F_85 ( V_19 , & F_69 ( V_21 ) -> V_89 ) ;
}
static void
F_95 ( struct V_11 * V_11 )
{
F_96 ( V_11 , V_84 ) ;
F_97 ( V_11 -> V_22 -> V_49 , V_85 ) ;
}
static void
F_98 ( struct V_18 * V_19 )
{
if ( F_55 ( V_56 , & V_19 -> V_57 ) ) {
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
if ( ! F_99 ( V_19 ) ) {
F_21 ( & V_21 -> V_24 ) ;
F_90 ( V_19 ) ;
F_22 ( & V_21 -> V_24 ) ;
}
F_95 ( V_19 -> V_77 ) ;
}
}
static inline
int F_100 ( struct V_1 * V_64 )
{
if ( V_64 -> V_90 . V_91 == V_92 )
return V_64 -> V_88 == NULL ;
else
return V_64 -> V_90 . V_91 != V_93 ;
}
static inline
int F_101 ( struct V_18 * V_19 ,
struct V_1 * V_64 )
{
if ( F_91 ( V_94 , & V_19 -> V_57 ) ) {
F_93 ( V_19 , V_64 -> V_88 ) ;
return 1 ;
}
if ( F_91 ( V_95 , & V_19 -> V_57 ) ) {
F_83 ( V_19 ) ;
return 1 ;
}
return 0 ;
}
static void
F_93 ( struct V_18 * V_19 , struct V_87 * V_88 )
{
}
static void
F_98 ( struct V_18 * V_19 )
{
}
static inline
int F_100 ( struct V_1 * V_64 )
{
return 0 ;
}
static inline
int F_101 ( struct V_18 * V_19 ,
struct V_1 * V_64 )
{
return 0 ;
}
static int
F_102 ( struct V_72 * V_73 )
{
return V_73 -> V_83 > 0 ;
}
static int
F_103 ( struct V_81 * V_96 , struct V_81 * V_97 , int V_98 ,
T_3 * V_99 )
{
struct V_18 * V_19 , * V_100 ;
int V_44 = 0 ;
F_104 (req, tmp, src, wb_list) {
if ( ! F_105 ( V_19 ) )
continue;
if ( F_106 ( V_99 ) )
F_107 ( V_19 , V_100 , V_101 ) ;
F_90 ( V_19 ) ;
F_86 ( V_19 , V_97 ) ;
V_44 ++ ;
if ( V_44 == V_98 )
break;
}
return V_44 ;
}
static int
F_108 ( struct V_21 * V_21 , struct V_81 * V_97 )
{
struct V_72 * V_73 = F_69 ( V_21 ) ;
int V_44 = 0 ;
F_21 ( & V_21 -> V_24 ) ;
if ( V_73 -> V_83 > 0 ) {
const int V_98 = V_102 ;
V_44 = F_103 ( & V_73 -> V_89 , V_97 , V_98 ,
& V_21 -> V_24 ) ;
V_44 += F_109 ( V_21 , V_98 - V_44 ,
& V_21 -> V_24 ) ;
}
F_22 ( & V_21 -> V_24 ) ;
return V_44 ;
}
static inline int F_102 ( struct V_72 * V_73 )
{
return 0 ;
}
static inline int F_108 ( struct V_21 * V_21 , struct V_81 * V_97 )
{
return 0 ;
}
static struct V_18 * F_110 ( struct V_21 * V_21 ,
struct V_11 * V_11 ,
unsigned int V_25 ,
unsigned int V_103 )
{
struct V_18 * V_19 ;
unsigned int V_104 ;
unsigned int V_27 ;
int error ;
if ( ! F_17 ( V_11 ) )
return NULL ;
V_27 = V_25 + V_103 ;
F_21 ( & V_21 -> V_24 ) ;
for (; ; ) {
V_19 = F_16 ( V_11 ) ;
if ( V_19 == NULL )
goto V_105;
V_104 = V_19 -> V_106 + V_19 -> V_107 ;
if ( V_25 > V_104
|| V_27 < V_19 -> V_106 )
goto V_108;
if ( F_47 ( V_19 ) )
break;
F_22 ( & V_21 -> V_24 ) ;
error = F_48 ( V_19 ) ;
F_49 ( V_19 ) ;
if ( error != 0 )
goto V_70;
F_21 ( & V_21 -> V_24 ) ;
}
if ( V_25 < V_19 -> V_106 ) {
V_19 -> V_106 = V_25 ;
V_19 -> V_109 = V_25 ;
}
if ( V_27 > V_104 )
V_19 -> V_107 = V_27 - V_19 -> V_106 ;
else
V_19 -> V_107 = V_104 - V_19 -> V_106 ;
V_105:
F_22 ( & V_21 -> V_24 ) ;
if ( V_19 )
F_98 ( V_19 ) ;
return V_19 ;
V_108:
F_22 ( & V_21 -> V_24 ) ;
F_49 ( V_19 ) ;
error = F_111 ( V_21 , V_11 ) ;
V_70:
return F_50 ( error ) ;
}
static struct V_18 * F_112 ( struct V_14 * V_15 ,
struct V_11 * V_11 , unsigned int V_25 , unsigned int V_103 )
{
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
struct V_18 * V_19 ;
V_19 = F_110 ( V_21 , V_11 , V_25 , V_103 ) ;
if ( V_19 != NULL )
goto V_32;
V_19 = F_113 ( V_15 , V_21 , V_11 , V_25 , V_103 ) ;
if ( F_53 ( V_19 ) )
goto V_32;
F_75 ( V_21 , V_19 ) ;
V_32:
return V_19 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_11 * V_11 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_18 * V_19 ;
V_19 = F_112 ( V_15 , V_11 , V_25 , V_26 ) ;
if ( F_53 ( V_19 ) )
return F_52 ( V_19 ) ;
F_23 ( V_11 , V_25 , V_26 ) ;
F_30 ( V_11 , V_19 -> V_109 , V_19 -> V_107 ) ;
F_83 ( V_19 ) ;
F_115 ( V_19 ) ;
return 0 ;
}
int F_116 ( struct V_110 * V_110 , struct V_11 * V_11 )
{
struct V_14 * V_15 = F_117 ( V_110 ) ;
struct V_18 * V_19 ;
int V_111 , V_112 ;
do {
V_19 = F_20 ( V_11 ) ;
if ( V_19 == NULL )
return 0 ;
V_111 = V_19 -> V_77 != V_11 || V_19 -> V_78 != V_15 ||
V_19 -> V_113 -> V_114 != V_115 -> V_116 ||
V_19 -> V_113 -> V_117 != V_115 -> V_118 ;
F_49 ( V_19 ) ;
if ( ! V_111 )
return 0 ;
V_112 = F_111 ( V_11 -> V_22 -> V_23 , V_11 ) ;
} while ( V_112 == 0 );
return V_112 ;
}
static int F_118 ( struct V_11 * V_11 , struct V_21 * V_21 )
{
return F_31 ( V_11 ) &&
! ( F_69 ( V_21 ) -> V_119 & ( V_120 | V_121 ) ) ;
}
int F_119 ( struct V_110 * V_110 , struct V_11 * V_11 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_14 * V_15 = F_117 ( V_110 ) ;
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
int V_112 = 0 ;
F_26 ( V_21 , V_122 ) ;
F_120 ( L_1 ,
V_110 -> V_123 . V_79 -> V_124 -> V_125 . V_126 ,
V_110 -> V_123 . V_79 -> V_125 . V_126 , V_26 ,
( long long ) ( F_121 ( V_11 ) + V_25 ) ) ;
if ( F_118 ( V_11 , V_21 ) &&
V_21 -> V_127 == NULL &&
! ( V_110 -> V_128 & V_129 ) ) {
V_26 = V_98 ( V_26 + V_25 , F_32 ( V_11 ) ) ;
V_25 = 0 ;
}
V_112 = F_114 ( V_15 , V_11 , V_25 , V_26 ) ;
if ( V_112 < 0 )
F_27 ( V_11 ) ;
else
F_84 ( V_11 ) ;
F_120 ( L_2 ,
V_112 , ( long long ) F_24 ( V_21 ) ) ;
return V_112 ;
}
static void F_122 ( struct V_18 * V_19 ,
struct V_1 * V_64 )
{
struct V_11 * V_11 = V_19 -> V_77 ;
if ( F_123 ( V_19 -> V_77 ) || ! F_101 ( V_19 , V_64 ) )
F_79 ( V_19 ) ;
F_115 ( V_19 ) ;
F_41 ( V_11 ) ;
}
static int F_124 ( int V_130 )
{
switch ( V_130 & ( V_38 | V_42 ) ) {
case V_38 :
return V_131 ;
case V_42 :
return V_132 ;
}
return V_133 ;
}
int F_125 ( struct V_1 * V_64 ,
struct V_134 * V_135 ,
const struct V_136 * V_137 ,
int V_130 )
{
struct V_21 * V_21 = V_64 -> V_21 ;
int V_138 = F_124 ( V_130 ) ;
struct V_139 * V_140 ;
struct V_141 V_142 = {
. V_143 = & V_64 -> args ,
. V_144 = & V_64 -> V_145 ,
. V_146 = V_64 -> V_147 ,
} ;
struct V_148 V_149 = {
. V_150 = V_135 ,
. V_140 = & V_64 -> V_140 ,
. V_141 = & V_142 ,
. V_151 = V_137 ,
. V_152 = V_64 ,
. V_153 = V_154 ,
. V_17 = V_155 ,
. V_138 = V_138 ,
} ;
int V_44 = 0 ;
F_126 ( V_21 ) -> F_127 ( V_64 , & V_142 ) ;
F_120 ( L_3
L_4 ,
V_64 -> V_140 . V_156 ,
V_21 -> V_157 -> V_158 ,
( long long ) F_128 ( V_21 ) ,
V_64 -> args . V_26 ,
( unsigned long long ) V_64 -> args . V_25 ) ;
V_140 = F_129 ( & V_149 ) ;
if ( F_53 ( V_140 ) ) {
V_44 = F_52 ( V_140 ) ;
goto V_32;
}
if ( V_130 & V_159 ) {
V_44 = F_130 ( V_140 ) ;
if ( V_44 == 0 )
V_44 = V_140 -> V_160 ;
}
F_131 ( V_140 ) ;
V_32:
return V_44 ;
}
static void F_132 ( struct V_18 * V_19 ,
struct V_1 * V_64 ,
unsigned int V_26 , unsigned int V_25 ,
int V_130 )
{
struct V_21 * V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
V_64 -> V_19 = V_19 ;
V_64 -> V_21 = V_21 = V_19 -> V_78 -> V_79 -> V_80 ;
V_64 -> V_147 = V_19 -> V_78 -> V_147 ;
V_64 -> args . V_161 = F_133 ( V_21 ) ;
V_64 -> args . V_25 = F_134 ( V_19 ) + V_25 ;
V_64 -> V_162 = V_64 -> args . V_25 ;
V_64 -> args . V_163 = V_19 -> V_109 + V_25 ;
V_64 -> args . V_5 = V_64 -> V_6 ;
V_64 -> args . V_26 = V_26 ;
V_64 -> args . V_13 = F_135 ( V_19 -> V_78 ) ;
V_64 -> args . V_164 = V_19 -> V_113 ;
V_64 -> args . V_165 = V_166 ;
switch ( V_130 & ( V_39 | V_43 ) ) {
case 0 :
break;
case V_43 :
if ( F_102 ( F_69 ( V_21 ) ) )
break;
default:
V_64 -> args . V_165 = V_93 ;
}
V_64 -> V_145 . V_167 = & V_64 -> V_167 ;
V_64 -> V_145 . V_26 = V_26 ;
V_64 -> V_145 . V_90 = & V_64 -> V_90 ;
F_136 ( & V_64 -> V_167 ) ;
}
static int F_137 ( struct V_1 * V_64 ,
const struct V_136 * V_137 ,
int V_130 )
{
struct V_21 * V_21 = V_64 -> args . V_13 -> V_79 -> V_80 ;
return F_125 ( V_64 , F_138 ( V_21 ) , V_137 , V_130 ) ;
}
static int F_139 ( struct V_81 * V_82 ,
const struct V_136 * V_137 ,
int V_130 )
{
struct V_1 * V_64 ;
int V_44 = 0 ;
while ( ! F_140 ( V_82 ) ) {
int V_168 ;
V_64 = F_141 ( V_82 -> V_169 , struct V_1 , V_170 ) ;
F_142 ( & V_64 -> V_170 ) ;
V_168 = F_137 ( V_64 , V_137 , V_130 ) ;
if ( V_44 == 0 )
V_44 = V_168 ;
}
return V_44 ;
}
static void F_57 ( struct V_18 * V_19 )
{
struct V_11 * V_11 = V_19 -> V_77 ;
F_83 ( V_19 ) ;
F_115 ( V_19 ) ;
F_41 ( V_11 ) ;
}
static int F_143 ( struct V_54 * V_171 , struct V_81 * V_145 )
{
struct V_18 * V_19 = F_144 ( V_171 -> V_172 . V_169 ) ;
struct V_11 * V_11 = V_19 -> V_77 ;
struct V_1 * V_64 ;
T_4 V_173 = V_171 -> V_174 , V_175 ;
unsigned int V_25 ;
int V_176 = 0 ;
int V_44 = 0 ;
F_92 ( V_19 ) ;
if ( ( V_171 -> V_177 & V_43 ) &&
( V_171 -> V_178 || F_69 ( V_171 -> V_179 ) -> V_83 ||
V_171 -> V_180 > V_173 ) )
V_171 -> V_177 &= ~ V_43 ;
V_25 = 0 ;
V_175 = V_171 -> V_180 ;
do {
T_4 V_181 = F_145 ( V_175 , V_173 ) ;
V_64 = F_7 ( 1 ) ;
if ( ! V_64 )
goto V_182;
V_64 -> V_6 [ 0 ] = V_11 ;
F_132 ( V_19 , V_64 , V_181 , V_25 , V_171 -> V_177 ) ;
F_146 ( & V_64 -> V_170 , V_145 ) ;
V_176 ++ ;
V_175 -= V_181 ;
V_25 += V_181 ;
} while ( V_175 != 0 );
F_147 ( & V_19 -> V_183 , V_176 ) ;
V_171 -> V_184 = & V_185 ;
return V_44 ;
V_182:
while ( ! F_140 ( V_145 ) ) {
V_64 = F_141 ( V_145 -> V_169 , struct V_1 , V_170 ) ;
F_148 ( & V_64 -> V_170 ) ;
F_11 ( V_64 ) ;
}
F_57 ( V_19 ) ;
return - V_186 ;
}
static int F_149 ( struct V_54 * V_171 , struct V_81 * V_145 )
{
struct V_18 * V_19 ;
struct V_11 * * V_5 ;
struct V_1 * V_64 ;
struct V_81 * V_82 = & V_171 -> V_172 ;
int V_44 = 0 ;
V_64 = F_7 ( F_150 ( V_171 -> V_187 ,
V_171 -> V_180 ) ) ;
if ( ! V_64 ) {
while ( ! F_140 ( V_82 ) ) {
V_19 = F_144 ( V_82 -> V_169 ) ;
F_92 ( V_19 ) ;
F_57 ( V_19 ) ;
}
V_44 = - V_186 ;
goto V_32;
}
V_5 = V_64 -> V_6 ;
while ( ! F_140 ( V_82 ) ) {
V_19 = F_144 ( V_82 -> V_169 ) ;
F_92 ( V_19 ) ;
F_86 ( V_19 , & V_64 -> V_5 ) ;
* V_5 ++ = V_19 -> V_77 ;
}
V_19 = F_144 ( V_64 -> V_5 . V_169 ) ;
if ( ( V_171 -> V_177 & V_43 ) &&
( V_171 -> V_178 || F_69 ( V_171 -> V_179 ) -> V_83 ) )
V_171 -> V_177 &= ~ V_43 ;
F_132 ( V_19 , V_64 , V_171 -> V_180 , 0 , V_171 -> V_177 ) ;
F_146 ( & V_64 -> V_170 , V_145 ) ;
V_171 -> V_184 = & V_188 ;
V_32:
return V_44 ;
}
int F_151 ( struct V_54 * V_171 , struct V_81 * V_82 )
{
if ( V_171 -> V_174 < V_189 )
return F_143 ( V_171 , V_82 ) ;
return F_149 ( V_171 , V_82 ) ;
}
static int F_152 ( struct V_54 * V_171 )
{
F_153 ( V_82 ) ;
int V_44 ;
V_44 = F_151 ( V_171 , & V_82 ) ;
if ( V_44 == 0 )
V_44 = F_139 ( & V_82 , V_171 -> V_184 ,
V_171 -> V_177 ) ;
return V_44 ;
}
void F_154 ( struct V_54 * V_55 ,
struct V_21 * V_21 , int V_190 )
{
F_155 ( V_55 , V_21 , & V_191 ,
F_37 ( V_21 ) -> V_173 , V_190 ) ;
}
void F_156 ( struct V_54 * V_55 )
{
V_55 -> V_192 = & V_191 ;
V_55 -> V_174 = F_37 ( V_55 -> V_179 ) -> V_173 ;
}
static void F_63 ( struct V_54 * V_55 ,
struct V_21 * V_21 , int V_190 )
{
if ( ! F_157 ( V_55 , V_21 , V_190 ) )
F_154 ( V_55 , V_21 , V_190 ) ;
}
static void F_158 ( struct V_139 * V_140 , void * V_193 )
{
struct V_1 * V_64 = V_193 ;
F_120 ( L_5 ,
V_140 -> V_156 ,
V_64 -> V_19 -> V_78 -> V_79 -> V_80 -> V_157 -> V_158 ,
( long long )
F_128 ( V_64 -> V_19 -> V_78 -> V_79 -> V_80 ) ,
V_64 -> V_19 -> V_107 , ( long long ) F_134 ( V_64 -> V_19 ) ) ;
F_159 ( V_140 , V_64 ) ;
}
static void F_160 ( void * V_193 )
{
struct V_1 * V_64 = V_193 ;
struct V_18 * V_19 = V_64 -> V_19 ;
struct V_11 * V_11 = V_19 -> V_77 ;
int V_112 = V_64 -> V_140 . V_160 ;
if ( V_112 < 0 ) {
F_27 ( V_11 ) ;
F_13 ( V_19 -> V_78 , V_112 ) ;
F_120 ( L_6 , V_112 ) ;
goto V_32;
}
if ( F_100 ( V_64 ) ) {
struct V_21 * V_21 = V_11 -> V_22 -> V_23 ;
F_21 ( & V_21 -> V_24 ) ;
if ( F_55 ( V_95 , & V_19 -> V_57 ) ) {
} else if ( ! F_161 ( V_94 , & V_19 -> V_57 ) ) {
memcpy ( & V_19 -> V_194 , & V_64 -> V_90 , sizeof( V_19 -> V_194 ) ) ;
F_120 ( L_7 ) ;
} else if ( memcmp ( & V_19 -> V_194 , & V_64 -> V_90 , sizeof( V_19 -> V_194 ) ) ) {
F_15 ( V_95 , & V_19 -> V_57 ) ;
F_82 ( V_94 , & V_19 -> V_57 ) ;
F_120 ( L_8 ) ;
}
F_22 ( & V_21 -> V_24 ) ;
} else
F_120 ( L_9 ) ;
V_32:
if ( F_162 ( & V_19 -> V_183 ) )
F_122 ( V_19 , V_64 ) ;
F_11 ( V_193 ) ;
}
void F_163 ( struct V_139 * V_140 , void * V_193 )
{
struct V_1 * V_64 = V_193 ;
F_126 ( V_64 -> V_21 ) -> F_164 ( V_140 , V_64 ) ;
}
static void F_165 ( struct V_139 * V_140 , void * V_193 )
{
struct V_1 * V_64 = V_193 ;
F_159 ( V_140 , V_64 ) ;
}
static void F_166 ( void * V_193 )
{
struct V_1 * V_64 = V_193 ;
int V_112 = V_64 -> V_140 . V_160 ;
while ( ! F_140 ( & V_64 -> V_5 ) ) {
struct V_18 * V_19 = F_144 ( V_64 -> V_5 . V_169 ) ;
struct V_11 * V_11 = V_19 -> V_77 ;
F_92 ( V_19 ) ;
F_120 ( L_10 ,
V_64 -> V_140 . V_156 ,
V_19 -> V_78 -> V_79 -> V_80 -> V_157 -> V_158 ,
( long long ) F_128 ( V_19 -> V_78 -> V_79 -> V_80 ) ,
V_19 -> V_107 ,
( long long ) F_134 ( V_19 ) ) ;
if ( V_112 < 0 ) {
F_27 ( V_11 ) ;
F_13 ( V_19 -> V_78 , V_112 ) ;
F_120 ( L_6 , V_112 ) ;
goto V_195;
}
if ( F_100 ( V_64 ) ) {
memcpy ( & V_19 -> V_194 , & V_64 -> V_90 , sizeof( V_19 -> V_194 ) ) ;
F_93 ( V_19 , V_64 -> V_88 ) ;
F_120 ( L_11 ) ;
goto V_169;
}
F_120 ( L_9 ) ;
V_195:
F_79 ( V_19 ) ;
V_169:
F_115 ( V_19 ) ;
F_41 ( V_11 ) ;
}
F_11 ( V_193 ) ;
}
void F_159 ( struct V_139 * V_140 , struct V_1 * V_64 )
{
struct V_196 * V_197 = & V_64 -> args ;
struct V_198 * V_199 = & V_64 -> V_145 ;
int V_112 ;
F_120 ( L_12 ,
V_140 -> V_156 , V_140 -> V_160 ) ;
V_112 = F_126 ( V_64 -> V_21 ) -> F_167 ( V_140 , V_64 ) ;
if ( V_112 != 0 )
return;
F_59 ( V_64 -> V_21 , V_200 , V_199 -> V_26 ) ;
#if F_168 ( V_201 ) || F_168 ( V_202 )
if ( V_199 -> V_90 -> V_91 < V_197 -> V_165 && V_140 -> V_160 >= 0 ) {
static unsigned long V_203 ;
if ( F_169 ( V_203 , V_204 ) ) {
F_120 ( L_13
L_14 ,
F_37 ( V_64 -> V_21 ) -> V_205 -> V_206 ,
V_199 -> V_90 -> V_91 , V_197 -> V_165 ) ;
V_203 = V_204 + 300 * V_207 ;
}
}
#endif
if ( V_140 -> V_160 >= 0 && V_199 -> V_26 < V_197 -> V_26 ) {
static unsigned long V_203 ;
F_26 ( V_64 -> V_21 , V_208 ) ;
if ( V_199 -> V_26 != 0 ) {
if ( V_199 -> V_90 -> V_91 != V_166 ) {
V_64 -> V_162 += V_199 -> V_26 ;
V_197 -> V_25 += V_199 -> V_26 ;
V_197 -> V_163 += V_199 -> V_26 ;
V_197 -> V_26 -= V_199 -> V_26 ;
} else {
V_197 -> V_165 = V_93 ;
}
F_170 ( V_140 ) ;
return;
}
if ( F_169 ( V_203 , V_204 ) ) {
F_171 ( V_209
L_15 ,
V_197 -> V_26 ) ;
V_203 = V_204 + 300 * V_207 ;
}
V_140 -> V_160 = - V_210 ;
}
return;
}
static int F_172 ( struct V_72 * V_73 , int V_211 )
{
int V_44 ;
if ( ! F_161 ( V_212 , & V_73 -> V_17 ) )
return 1 ;
if ( ! V_211 )
return 0 ;
V_44 = F_173 ( & V_73 -> V_17 ,
V_212 ,
V_68 ,
V_69 ) ;
return ( V_44 < 0 ) ? V_44 : 1 ;
}
void F_174 ( struct V_72 * V_73 )
{
F_82 ( V_212 , & V_73 -> V_17 ) ;
F_73 () ;
F_74 ( & V_73 -> V_17 , V_212 ) ;
}
void F_175 ( void * V_64 )
{
struct V_1 * V_12 = V_64 ;
F_12 ( V_12 -> args . V_13 ) ;
F_4 ( V_12 ) ;
}
int F_176 ( struct V_1 * V_64 , struct V_134 * V_135 ,
const struct V_136 * V_137 ,
int V_130 )
{
struct V_139 * V_140 ;
int V_138 = F_124 ( V_130 ) ;
struct V_141 V_142 = {
. V_143 = & V_64 -> args ,
. V_144 = & V_64 -> V_145 ,
. V_146 = V_64 -> V_147 ,
} ;
struct V_148 V_149 = {
. V_140 = & V_64 -> V_140 ,
. V_150 = V_135 ,
. V_141 = & V_142 ,
. V_151 = V_137 ,
. V_152 = V_64 ,
. V_153 = V_154 ,
. V_17 = V_155 ,
. V_138 = V_138 ,
} ;
F_126 ( V_64 -> V_21 ) -> F_177 ( V_64 , & V_142 ) ;
F_120 ( L_16 , V_64 -> V_140 . V_156 ) ;
V_140 = F_129 ( & V_149 ) ;
if ( F_53 ( V_140 ) )
return F_52 ( V_140 ) ;
if ( V_130 & V_159 )
F_130 ( V_140 ) ;
F_131 ( V_140 ) ;
return 0 ;
}
void F_178 ( struct V_1 * V_64 ,
struct V_81 * V_82 ,
struct V_87 * V_88 )
{
struct V_18 * V_213 = F_144 ( V_82 -> V_169 ) ;
struct V_21 * V_21 = V_213 -> V_78 -> V_79 -> V_80 ;
F_179 ( V_82 , & V_64 -> V_5 ) ;
V_64 -> V_21 = V_21 ;
V_64 -> V_147 = V_213 -> V_78 -> V_147 ;
V_64 -> V_88 = V_88 ;
V_64 -> V_214 = & V_215 ;
V_64 -> args . V_161 = F_133 ( V_64 -> V_21 ) ;
V_64 -> args . V_25 = 0 ;
V_64 -> args . V_26 = 0 ;
V_64 -> args . V_13 = F_135 ( V_213 -> V_78 ) ;
V_64 -> V_145 . V_26 = 0 ;
V_64 -> V_145 . V_167 = & V_64 -> V_167 ;
V_64 -> V_145 . V_90 = & V_64 -> V_90 ;
F_136 ( & V_64 -> V_167 ) ;
}
void F_180 ( struct V_81 * V_216 ,
struct V_87 * V_88 )
{
struct V_18 * V_19 ;
while ( ! F_140 ( V_216 ) ) {
V_19 = F_144 ( V_216 -> V_169 ) ;
F_92 ( V_19 ) ;
F_93 ( V_19 , V_88 ) ;
F_96 ( V_19 -> V_77 , V_84 ) ;
F_97 ( V_19 -> V_77 -> V_22 -> V_49 ,
V_85 ) ;
F_115 ( V_19 ) ;
}
}
static int
F_181 ( struct V_21 * V_21 , struct V_81 * V_82 , int V_130 )
{
struct V_1 * V_64 ;
V_64 = F_1 () ;
if ( ! V_64 )
goto V_182;
F_178 ( V_64 , V_82 , NULL ) ;
return F_176 ( V_64 , F_138 ( V_21 ) , V_64 -> V_214 , V_130 ) ;
V_182:
F_180 ( V_82 , NULL ) ;
F_174 ( F_69 ( V_21 ) ) ;
return - V_186 ;
}
static void F_182 ( struct V_139 * V_140 , void * V_193 )
{
struct V_1 * V_64 = V_193 ;
F_120 ( L_17 ,
V_140 -> V_156 , V_140 -> V_160 ) ;
F_126 ( V_64 -> V_21 ) -> F_183 ( V_140 , V_64 ) ;
}
void F_184 ( struct V_1 * V_64 )
{
struct V_18 * V_19 ;
int V_112 = V_64 -> V_140 . V_160 ;
while ( ! F_140 ( & V_64 -> V_5 ) ) {
V_19 = F_144 ( V_64 -> V_5 . V_169 ) ;
F_92 ( V_19 ) ;
F_95 ( V_19 -> V_77 ) ;
F_120 ( L_18 ,
V_19 -> V_78 -> V_79 -> V_217 -> V_158 ,
( long long ) F_128 ( V_19 -> V_78 -> V_79 -> V_80 ) ,
V_19 -> V_107 ,
( long long ) F_134 ( V_19 ) ) ;
if ( V_112 < 0 ) {
F_13 ( V_19 -> V_78 , V_112 ) ;
F_79 ( V_19 ) ;
F_120 ( L_6 , V_112 ) ;
goto V_169;
}
if ( ! memcmp ( V_19 -> V_194 . V_218 , V_64 -> V_90 . V_218 , sizeof( V_64 -> V_90 . V_218 ) ) ) {
F_79 ( V_19 ) ;
F_120 ( L_9 ) ;
goto V_169;
}
F_120 ( L_19 ) ;
F_83 ( V_19 ) ;
V_169:
F_115 ( V_19 ) ;
}
}
static void F_185 ( void * V_193 )
{
struct V_1 * V_64 = V_193 ;
F_184 ( V_64 ) ;
F_174 ( F_69 ( V_64 -> V_21 ) ) ;
F_175 ( V_193 ) ;
}
int F_186 ( struct V_21 * V_21 , int V_130 )
{
F_153 ( V_82 ) ;
int V_211 = V_130 & V_159 ;
int V_145 ;
V_145 = F_172 ( F_69 ( V_21 ) , V_211 ) ;
if ( V_145 <= 0 )
goto V_219;
V_145 = F_108 ( V_21 , & V_82 ) ;
if ( V_145 ) {
int error ;
error = F_187 ( V_21 , & V_82 , V_130 ) ;
if ( error == V_220 )
error = F_181 ( V_21 , & V_82 , V_130 ) ;
if ( error < 0 )
return error ;
if ( ! V_211 )
goto V_219;
error = F_188 ( & F_69 ( V_21 ) -> V_17 ,
V_212 ,
V_68 ,
V_69 ) ;
if ( error < 0 )
return error ;
} else
F_174 ( F_69 ( V_21 ) ) ;
return V_145 ;
V_219:
F_89 ( V_21 , V_86 ) ;
return V_145 ;
}
static int F_189 ( struct V_21 * V_21 , struct V_35 * V_36 )
{
struct V_72 * V_73 = F_69 ( V_21 ) ;
int V_17 = V_159 ;
int V_44 = 0 ;
if ( ! V_73 -> V_83 )
return V_44 ;
if ( V_36 -> V_61 == V_62 ) {
if ( V_73 -> V_83 <= ( V_73 -> V_10 >> 1 ) )
goto V_219;
V_17 = 0 ;
}
V_44 = F_186 ( V_21 , V_17 ) ;
if ( V_44 >= 0 ) {
if ( V_36 -> V_61 == V_62 ) {
if ( V_44 < V_36 -> V_221 )
V_36 -> V_221 -= V_44 ;
else
V_36 -> V_221 = 0 ;
}
return 0 ;
}
V_219:
F_89 ( V_21 , V_86 ) ;
return V_44 ;
}
static int F_189 ( struct V_21 * V_21 , struct V_35 * V_36 )
{
return 0 ;
}
int F_190 ( struct V_21 * V_21 , struct V_35 * V_36 )
{
int V_44 ;
V_44 = F_189 ( V_21 , V_36 ) ;
if ( V_44 >= 0 && F_55 ( V_222 , & F_69 ( V_21 ) -> V_17 ) ) {
int V_112 ;
bool V_223 = true ;
if ( V_36 -> V_61 == V_62 )
V_223 = false ;
V_112 = F_191 ( V_21 , V_223 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return V_44 ;
}
int F_192 ( struct V_21 * V_21 )
{
struct V_35 V_36 = {
. V_61 = V_224 ,
. V_221 = V_225 ,
. V_226 = 0 ,
. V_227 = V_228 ,
} ;
return F_193 ( V_21 , & V_36 ) ;
}
int F_194 ( struct V_21 * V_21 , struct V_11 * V_11 )
{
struct V_18 * V_19 ;
int V_44 = 0 ;
F_54 ( ! F_195 ( V_11 ) ) ;
for (; ; ) {
F_196 ( V_11 ) ;
V_19 = F_20 ( V_11 ) ;
if ( V_19 == NULL )
break;
if ( F_47 ( V_19 ) ) {
F_98 ( V_19 ) ;
F_79 ( V_19 ) ;
F_197 ( V_11 , V_189 ) ;
F_115 ( V_19 ) ;
break;
}
V_44 = F_48 ( V_19 ) ;
F_49 ( V_19 ) ;
if ( V_44 < 0 )
break;
}
return V_44 ;
}
int F_111 ( struct V_21 * V_21 , struct V_11 * V_11 )
{
T_1 V_226 = F_121 ( V_11 ) ;
T_1 V_227 = V_226 + ( T_1 ) ( V_189 - 1 ) ;
struct V_35 V_36 = {
. V_61 = V_224 ,
. V_221 = 0 ,
. V_226 = V_226 ,
. V_227 = V_227 ,
} ;
int V_44 ;
for (; ; ) {
F_196 ( V_11 ) ;
if ( F_198 ( V_11 ) ) {
V_44 = F_62 ( V_11 , & V_36 ) ;
if ( V_44 < 0 )
goto V_229;
continue;
}
if ( ! F_17 ( V_11 ) )
break;
V_44 = F_186 ( V_21 , V_159 ) ;
if ( V_44 < 0 )
goto V_229;
}
return 0 ;
V_229:
return V_44 ;
}
int F_199 ( struct V_65 * V_22 , struct V_11 * V_230 ,
struct V_11 * V_11 , enum V_231 V_232 )
{
if ( F_17 ( V_11 ) )
return - V_233 ;
F_200 ( V_11 , V_234 ) ;
return F_201 ( V_22 , V_230 , V_11 , V_232 ) ;
}
int T_5 F_202 ( void )
{
V_235 = F_203 ( L_20 ,
sizeof( struct V_1 ) ,
0 , V_236 ,
NULL ) ;
if ( V_235 == NULL )
return - V_186 ;
V_9 = F_204 ( V_237 ,
V_235 ) ;
if ( V_9 == NULL )
return - V_186 ;
V_3 = F_204 ( V_238 ,
V_235 ) ;
if ( V_3 == NULL )
return - V_186 ;
V_239 = ( 16 * F_205 ( V_240 ) ) << ( V_241 - 10 ) ;
if ( V_239 > 256 * 1024 )
V_239 = 256 * 1024 ;
return 0 ;
}
void F_206 ( void )
{
F_207 ( V_3 ) ;
F_207 ( V_9 ) ;
F_208 ( V_235 ) ;
}
