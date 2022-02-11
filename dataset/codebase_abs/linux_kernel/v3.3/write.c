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
F_12 ( V_12 -> V_13 ) ;
F_13 ( V_12 -> args . V_14 ) ;
F_10 ( V_12 ) ;
}
static void F_14 ( struct V_15 * V_16 , int error )
{
V_16 -> error = error ;
F_15 () ;
F_16 ( V_17 , & V_16 -> V_18 ) ;
}
static struct V_19 * F_17 ( struct V_11 * V_11 )
{
struct V_19 * V_20 = NULL ;
if ( F_18 ( V_11 ) ) {
V_20 = (struct V_19 * ) F_19 ( V_11 ) ;
if ( V_20 != NULL )
F_20 ( & V_20 -> V_21 ) ;
}
return V_20 ;
}
static struct V_19 * F_21 ( struct V_11 * V_11 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_19 * V_20 = NULL ;
F_22 ( & V_22 -> V_25 ) ;
V_20 = F_17 ( V_11 ) ;
F_23 ( & V_22 -> V_25 ) ;
return V_20 ;
}
static void F_24 ( struct V_11 * V_11 , unsigned int V_26 , unsigned int V_27 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
T_1 V_28 , V_29 ;
T_2 V_30 ;
F_22 ( & V_22 -> V_25 ) ;
V_29 = F_25 ( V_22 ) ;
V_30 = ( V_29 - 1 ) >> V_31 ;
if ( V_29 > 0 && V_11 -> V_32 < V_30 )
goto V_33;
V_28 = ( ( T_1 ) V_11 -> V_32 << V_31 ) + ( ( T_1 ) V_26 + V_27 ) ;
if ( V_29 >= V_28 )
goto V_33;
F_26 ( V_22 , V_28 ) ;
F_27 ( V_22 , V_34 ) ;
V_33:
F_23 ( & V_22 -> V_25 ) ;
}
static void F_28 ( struct V_11 * V_11 )
{
F_29 ( V_11 ) ;
F_30 ( V_11 -> V_23 -> V_24 , V_11 -> V_23 ) ;
}
static void F_31 ( struct V_11 * V_11 , unsigned int V_35 , unsigned int V_27 )
{
if ( F_32 ( V_11 ) )
return;
if ( V_35 != 0 )
return;
if ( V_27 != F_33 ( V_11 ) )
return;
F_34 ( V_11 ) ;
}
static int F_35 ( struct V_36 * V_37 )
{
if ( V_37 -> V_38 )
return V_39 | V_40 ;
if ( V_37 -> V_41 || V_37 -> V_42 )
return V_43 | V_44 ;
return V_44 ;
}
static int F_36 ( struct V_11 * V_11 )
{
int V_45 = F_37 ( V_11 ) ;
if ( ! V_45 ) {
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_46 * V_47 = F_38 ( V_22 ) ;
F_39 ( V_11 ) ;
if ( F_40 ( & V_47 -> V_48 ) >
V_49 ) {
F_41 ( & V_47 -> V_50 ,
V_51 ) ;
}
}
return V_45 ;
}
static void F_42 ( struct V_11 * V_11 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_46 * V_47 = F_38 ( V_22 ) ;
F_43 ( V_11 ) ;
F_44 ( V_11 ) ;
if ( F_45 ( & V_47 -> V_48 ) < V_52 )
F_46 ( & V_47 -> V_50 , V_51 ) ;
}
static struct V_19 * F_47 ( struct V_11 * V_11 , bool V_53 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_19 * V_20 ;
int V_45 ;
F_22 ( & V_22 -> V_25 ) ;
for (; ; ) {
V_20 = F_17 ( V_11 ) ;
if ( V_20 == NULL )
break;
if ( F_48 ( V_20 ) )
break;
F_23 ( & V_22 -> V_25 ) ;
if ( ! V_53 )
V_45 = F_49 ( V_20 ) ;
else
V_45 = - V_54 ;
F_50 ( V_20 ) ;
if ( V_45 != 0 )
return F_51 ( V_45 ) ;
F_22 ( & V_22 -> V_25 ) ;
}
F_23 ( & V_22 -> V_25 ) ;
return V_20 ;
}
static int F_52 ( struct V_55 * V_56 ,
struct V_11 * V_11 , bool V_53 )
{
struct V_19 * V_20 ;
int V_45 = 0 ;
V_20 = F_47 ( V_11 , V_53 ) ;
if ( ! V_20 )
goto V_33;
V_45 = F_53 ( V_20 ) ;
if ( F_54 ( V_20 ) )
goto V_33;
V_45 = F_36 ( V_11 ) ;
F_55 ( V_45 != 0 ) ;
F_55 ( F_56 ( V_57 , & V_20 -> V_58 ) ) ;
if ( ! F_57 ( V_56 , V_20 ) ) {
F_58 ( V_20 ) ;
V_45 = V_56 -> V_59 ;
}
V_33:
return V_45 ;
}
static int F_59 ( struct V_11 * V_11 , struct V_36 * V_37 , struct V_55 * V_56 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
int V_45 ;
F_27 ( V_22 , V_60 ) ;
F_60 ( V_22 , V_61 , 1 ) ;
F_61 ( V_56 , V_11 -> V_32 ) ;
V_45 = F_52 ( V_56 , V_11 , V_37 -> V_62 == V_63 ) ;
if ( V_45 == - V_54 ) {
F_62 ( V_37 , V_11 ) ;
V_45 = 0 ;
}
return V_45 ;
}
static int F_63 ( struct V_11 * V_11 , struct V_36 * V_37 )
{
struct V_55 V_56 ;
int V_64 ;
F_64 ( & V_56 , V_11 -> V_23 -> V_24 , F_35 ( V_37 ) ) ;
V_64 = F_59 ( V_11 , V_37 , & V_56 ) ;
F_65 ( & V_56 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_56 . V_59 < 0 )
return V_56 . V_59 ;
return 0 ;
}
int F_66 ( struct V_11 * V_11 , struct V_36 * V_37 )
{
int V_45 ;
V_45 = F_63 ( V_11 , V_37 ) ;
F_67 ( V_11 ) ;
return V_45 ;
}
static int F_68 ( struct V_11 * V_11 , struct V_36 * V_37 , void * V_65 )
{
int V_45 ;
V_45 = F_59 ( V_11 , V_37 , V_65 ) ;
F_67 ( V_11 ) ;
return V_45 ;
}
int F_69 ( struct V_66 * V_23 , struct V_36 * V_37 )
{
struct V_22 * V_22 = V_23 -> V_24 ;
unsigned long * V_67 = & F_70 ( V_22 ) -> V_18 ;
struct V_55 V_56 ;
int V_64 ;
V_64 = F_71 ( V_67 , V_68 ,
V_69 , V_70 ) ;
if ( V_64 )
goto V_71;
F_27 ( V_22 , V_72 ) ;
F_64 ( & V_56 , V_22 , F_35 ( V_37 ) ) ;
V_64 = F_72 ( V_23 , V_37 , F_68 , & V_56 ) ;
F_65 ( & V_56 ) ;
F_73 ( V_68 , V_67 ) ;
F_74 () ;
F_75 ( V_67 , V_68 ) ;
if ( V_64 < 0 )
goto V_71;
V_64 = V_56 . V_59 ;
if ( V_64 < 0 )
goto V_71;
return 0 ;
V_71:
return V_64 ;
}
static int F_76 ( struct V_22 * V_22 , struct V_19 * V_20 )
{
struct V_73 * V_74 = F_70 ( V_22 ) ;
int error ;
error = F_77 ( V_4 ) ;
if ( error != 0 )
goto V_33;
F_78 ( V_20 ) ;
F_22 ( & V_22 -> V_25 ) ;
error = F_79 ( & V_74 -> V_75 , V_20 -> V_76 , V_20 ) ;
F_55 ( error ) ;
if ( ! V_74 -> V_10 && F_80 ( V_22 , V_77 ) )
V_22 -> V_78 ++ ;
F_16 ( V_79 , & V_20 -> V_58 ) ;
F_81 ( V_20 -> V_80 ) ;
F_82 ( V_20 -> V_80 , ( unsigned long ) V_20 ) ;
V_74 -> V_10 ++ ;
F_20 ( & V_20 -> V_21 ) ;
F_83 ( & V_74 -> V_75 , V_20 -> V_76 ,
V_81 ) ;
F_23 ( & V_22 -> V_25 ) ;
F_84 () ;
V_33:
return error ;
}
static void F_85 ( struct V_19 * V_20 )
{
struct V_22 * V_22 = V_20 -> V_82 -> V_83 -> V_84 ;
struct V_73 * V_74 = F_70 ( V_22 ) ;
F_55 ( ! F_86 ( V_20 ) ) ;
F_22 ( & V_22 -> V_25 ) ;
F_82 ( V_20 -> V_80 , 0 ) ;
F_87 ( V_20 -> V_80 ) ;
F_88 ( V_79 , & V_20 -> V_58 ) ;
F_89 ( & V_74 -> V_75 , V_20 -> V_76 ) ;
V_74 -> V_10 -- ;
F_23 ( & V_22 -> V_25 ) ;
F_50 ( V_20 ) ;
}
static void
F_90 ( struct V_19 * V_20 )
{
F_91 ( V_20 -> V_80 ) ;
}
static void
F_92 ( struct V_19 * V_20 , struct V_85 * V_13 )
{
struct V_22 * V_22 = V_20 -> V_82 -> V_83 -> V_84 ;
struct V_73 * V_74 = F_70 ( V_22 ) ;
F_22 ( & V_22 -> V_25 ) ;
F_16 ( V_57 , & ( V_20 ) -> V_58 ) ;
F_83 ( & V_74 -> V_75 ,
V_20 -> V_76 ,
V_86 ) ;
V_74 -> V_87 ++ ;
F_23 ( & V_22 -> V_25 ) ;
F_93 ( V_20 , V_13 ) ;
F_94 ( V_20 -> V_80 , V_88 ) ;
F_95 ( V_20 -> V_80 -> V_23 -> V_50 , V_89 ) ;
F_96 ( V_22 , V_90 ) ;
}
static int
F_97 ( struct V_19 * V_20 )
{
struct V_11 * V_11 = V_20 -> V_80 ;
if ( F_98 ( V_57 , & ( V_20 ) -> V_58 ) ) {
F_99 ( V_11 , V_88 ) ;
F_100 ( V_11 -> V_23 -> V_50 , V_89 ) ;
return 1 ;
}
return 0 ;
}
static inline
int F_101 ( struct V_1 * V_65 )
{
if ( V_65 -> V_91 . V_92 == V_93 )
return V_65 -> V_13 == NULL ;
else
return V_65 -> V_91 . V_92 != V_94 ;
}
static inline
int F_102 ( struct V_19 * V_20 ,
struct V_1 * V_65 )
{
if ( F_98 ( V_95 , & V_20 -> V_58 ) ) {
F_92 ( V_20 , V_65 -> V_13 ) ;
return 1 ;
}
if ( F_98 ( V_96 , & V_20 -> V_58 ) ) {
F_90 ( V_20 ) ;
return 1 ;
}
return 0 ;
}
static inline void
F_92 ( struct V_19 * V_20 , struct V_85 * V_13 )
{
}
static inline int
F_97 ( struct V_19 * V_20 )
{
return 0 ;
}
static inline
int F_101 ( struct V_1 * V_65 )
{
return 0 ;
}
static inline
int F_102 ( struct V_19 * V_20 ,
struct V_1 * V_65 )
{
return 0 ;
}
static int
F_103 ( struct V_73 * V_74 )
{
return F_104 ( & V_74 -> V_75 , V_86 ) ;
}
static int
F_105 ( struct V_22 * V_22 , struct V_97 * V_98 , T_2 V_99 , unsigned int V_10 )
{
struct V_73 * V_74 = F_70 ( V_22 ) ;
int V_45 ;
if ( ! F_103 ( V_74 ) )
return 0 ;
F_22 ( & V_22 -> V_25 ) ;
V_45 = F_106 ( V_74 , V_98 , V_99 , V_10 , V_86 ) ;
if ( V_45 > 0 )
V_74 -> V_87 -= V_45 ;
F_23 ( & V_22 -> V_25 ) ;
if ( F_103 ( F_70 ( V_22 ) ) )
F_96 ( V_22 , V_90 ) ;
return V_45 ;
}
static inline int F_103 ( struct V_73 * V_74 )
{
return 0 ;
}
static inline int F_105 ( struct V_22 * V_22 , struct V_97 * V_98 , T_2 V_99 , unsigned int V_10 )
{
return 0 ;
}
static struct V_19 * F_107 ( struct V_22 * V_22 ,
struct V_11 * V_11 ,
unsigned int V_26 ,
unsigned int V_100 )
{
struct V_19 * V_20 ;
unsigned int V_101 ;
unsigned int V_28 ;
int error ;
if ( ! F_18 ( V_11 ) )
return NULL ;
V_28 = V_26 + V_100 ;
F_22 ( & V_22 -> V_25 ) ;
for (; ; ) {
V_20 = F_17 ( V_11 ) ;
if ( V_20 == NULL )
goto V_102;
V_101 = V_20 -> V_103 + V_20 -> V_104 ;
if ( V_26 > V_101
|| V_28 < V_20 -> V_103 )
goto V_105;
if ( F_48 ( V_20 ) )
break;
F_23 ( & V_22 -> V_25 ) ;
error = F_49 ( V_20 ) ;
F_50 ( V_20 ) ;
if ( error != 0 )
goto V_71;
F_22 ( & V_22 -> V_25 ) ;
}
if ( F_97 ( V_20 ) &&
F_108 ( & F_70 ( V_22 ) -> V_75 ,
V_20 -> V_76 , V_86 ) != NULL ) {
F_70 ( V_22 ) -> V_87 -- ;
F_109 ( V_20 ) ;
}
if ( V_26 < V_20 -> V_103 ) {
V_20 -> V_103 = V_26 ;
V_20 -> V_106 = V_26 ;
}
if ( V_28 > V_101 )
V_20 -> V_104 = V_28 - V_20 -> V_103 ;
else
V_20 -> V_104 = V_101 - V_20 -> V_103 ;
V_102:
F_23 ( & V_22 -> V_25 ) ;
return V_20 ;
V_105:
F_23 ( & V_22 -> V_25 ) ;
F_50 ( V_20 ) ;
error = F_110 ( V_22 , V_11 ) ;
V_71:
return F_51 ( error ) ;
}
static struct V_19 * F_111 ( struct V_15 * V_16 ,
struct V_11 * V_11 , unsigned int V_26 , unsigned int V_100 )
{
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_19 * V_20 ;
int error ;
V_20 = F_107 ( V_22 , V_11 , V_26 , V_100 ) ;
if ( V_20 != NULL )
goto V_33;
V_20 = F_112 ( V_16 , V_22 , V_11 , V_26 , V_100 ) ;
if ( F_54 ( V_20 ) )
goto V_33;
error = F_76 ( V_22 , V_20 ) ;
if ( error != 0 ) {
F_50 ( V_20 ) ;
V_20 = F_51 ( error ) ;
}
V_33:
return V_20 ;
}
static int F_113 ( struct V_15 * V_16 , struct V_11 * V_11 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_19 * V_20 ;
V_20 = F_111 ( V_16 , V_11 , V_26 , V_27 ) ;
if ( F_54 ( V_20 ) )
return F_53 ( V_20 ) ;
F_24 ( V_11 , V_26 , V_27 ) ;
F_31 ( V_11 , V_20 -> V_106 , V_20 -> V_104 ) ;
F_90 ( V_20 ) ;
F_114 ( V_20 ) ;
return 0 ;
}
int F_115 ( struct V_107 * V_107 , struct V_11 * V_11 )
{
struct V_15 * V_16 = F_116 ( V_107 ) ;
struct V_19 * V_20 ;
int V_108 , V_109 ;
do {
V_20 = F_21 ( V_11 ) ;
if ( V_20 == NULL )
return 0 ;
V_108 = V_20 -> V_80 != V_11 || V_20 -> V_82 != V_16 ||
V_20 -> V_110 -> V_111 != V_112 -> V_113 ||
V_20 -> V_110 -> V_114 != V_112 -> V_115 ;
F_50 ( V_20 ) ;
if ( ! V_108 )
return 0 ;
V_109 = F_110 ( V_11 -> V_23 -> V_24 , V_11 ) ;
} while ( V_109 == 0 );
return V_109 ;
}
static int F_117 ( struct V_11 * V_11 , struct V_22 * V_22 )
{
return F_32 ( V_11 ) &&
! ( F_70 ( V_22 ) -> V_116 & ( V_117 | V_118 ) ) ;
}
int F_118 ( struct V_107 * V_107 , struct V_11 * V_11 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_15 * V_16 = F_116 ( V_107 ) ;
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
int V_109 = 0 ;
F_27 ( V_22 , V_119 ) ;
F_119 ( L_1 ,
V_107 -> V_120 . V_83 -> V_121 -> V_122 . V_123 ,
V_107 -> V_120 . V_83 -> V_122 . V_123 , V_27 ,
( long long ) ( F_120 ( V_11 ) + V_26 ) ) ;
if ( F_117 ( V_11 , V_22 ) &&
V_22 -> V_124 == NULL &&
! ( V_107 -> V_125 & V_126 ) ) {
V_27 = F_121 ( V_27 + V_26 , F_33 ( V_11 ) ) ;
V_26 = 0 ;
}
V_109 = F_113 ( V_16 , V_11 , V_26 , V_27 ) ;
if ( V_109 < 0 )
F_28 ( V_11 ) ;
else
F_91 ( V_11 ) ;
F_119 ( L_2 ,
V_109 , ( long long ) F_25 ( V_22 ) ) ;
return V_109 ;
}
static void F_122 ( struct V_19 * V_20 ,
struct V_1 * V_65 )
{
struct V_11 * V_11 = V_20 -> V_80 ;
if ( F_123 ( V_20 -> V_80 ) || ! F_102 ( V_20 , V_65 ) )
F_85 ( V_20 ) ;
F_114 ( V_20 ) ;
F_42 ( V_11 ) ;
}
static int F_124 ( int V_127 )
{
switch ( V_127 & ( V_39 | V_43 ) ) {
case V_39 :
return V_128 ;
case V_43 :
return V_129 ;
}
return V_130 ;
}
int F_125 ( struct V_1 * V_65 ,
struct V_131 * V_132 ,
const struct V_133 * V_134 ,
int V_127 )
{
struct V_22 * V_22 = V_65 -> V_22 ;
int V_135 = F_124 ( V_127 ) ;
struct V_136 * V_137 ;
struct V_138 V_139 = {
. V_140 = & V_65 -> args ,
. V_141 = & V_65 -> V_142 ,
. V_143 = V_65 -> V_144 ,
} ;
struct V_145 V_146 = {
. V_147 = V_132 ,
. V_137 = & V_65 -> V_137 ,
. V_138 = & V_139 ,
. V_148 = V_134 ,
. V_149 = V_65 ,
. V_150 = V_151 ,
. V_18 = V_152 ,
. V_135 = V_135 ,
} ;
int V_45 = 0 ;
F_126 ( V_22 ) -> F_127 ( V_65 , & V_139 ) ;
F_119 ( L_3
L_4 ,
V_65 -> V_137 . V_153 ,
V_22 -> V_154 -> V_155 ,
( long long ) F_128 ( V_22 ) ,
V_65 -> args . V_27 ,
( unsigned long long ) V_65 -> args . V_26 ) ;
V_137 = F_129 ( & V_146 ) ;
if ( F_54 ( V_137 ) ) {
V_45 = F_53 ( V_137 ) ;
goto V_33;
}
if ( V_127 & V_156 ) {
V_45 = F_130 ( V_137 ) ;
if ( V_45 == 0 )
V_45 = V_137 -> V_157 ;
}
F_131 ( V_137 ) ;
V_33:
return V_45 ;
}
static void F_132 ( struct V_19 * V_20 ,
struct V_1 * V_65 ,
unsigned int V_27 , unsigned int V_26 ,
int V_127 )
{
struct V_22 * V_22 = V_20 -> V_82 -> V_83 -> V_84 ;
V_65 -> V_20 = V_20 ;
V_65 -> V_22 = V_22 = V_20 -> V_82 -> V_83 -> V_84 ;
V_65 -> V_144 = V_20 -> V_82 -> V_144 ;
V_65 -> args . V_158 = F_133 ( V_22 ) ;
V_65 -> args . V_26 = F_134 ( V_20 ) + V_26 ;
V_65 -> V_159 = V_65 -> args . V_26 ;
V_65 -> args . V_160 = V_20 -> V_106 + V_26 ;
V_65 -> args . V_5 = V_65 -> V_6 ;
V_65 -> args . V_27 = V_27 ;
V_65 -> args . V_14 = F_135 ( V_20 -> V_82 ) ;
V_65 -> args . V_161 = V_20 -> V_110 ;
V_65 -> args . V_162 = V_163 ;
switch ( V_127 & ( V_40 | V_44 ) ) {
case 0 :
break;
case V_44 :
if ( F_103 ( F_70 ( V_22 ) ) )
break;
default:
V_65 -> args . V_162 = V_94 ;
}
V_65 -> V_142 . V_164 = & V_65 -> V_164 ;
V_65 -> V_142 . V_27 = V_27 ;
V_65 -> V_142 . V_91 = & V_65 -> V_91 ;
F_136 ( & V_65 -> V_164 ) ;
}
static int F_137 ( struct V_1 * V_65 ,
const struct V_133 * V_134 ,
int V_127 )
{
struct V_22 * V_22 = V_65 -> args . V_14 -> V_83 -> V_84 ;
return F_125 ( V_65 , F_138 ( V_22 ) , V_134 , V_127 ) ;
}
static int F_139 ( struct V_97 * V_165 ,
const struct V_133 * V_134 ,
int V_127 )
{
struct V_1 * V_65 ;
int V_45 = 0 ;
while ( ! F_140 ( V_165 ) ) {
int V_166 ;
V_65 = F_141 ( V_165 -> V_167 , struct V_1 , V_168 ) ;
F_142 ( & V_65 -> V_168 ) ;
V_166 = F_137 ( V_65 , V_134 , V_127 ) ;
if ( V_45 == 0 )
V_45 = V_166 ;
}
return V_45 ;
}
static void F_58 ( struct V_19 * V_20 )
{
struct V_11 * V_11 = V_20 -> V_80 ;
F_90 ( V_20 ) ;
F_114 ( V_20 ) ;
F_42 ( V_11 ) ;
}
static int F_143 ( struct V_55 * V_169 , struct V_97 * V_142 )
{
struct V_19 * V_20 = F_144 ( V_169 -> V_170 . V_167 ) ;
struct V_11 * V_11 = V_20 -> V_80 ;
struct V_1 * V_65 ;
T_3 V_171 = V_169 -> V_172 , V_173 ;
unsigned int V_26 ;
int V_174 = 0 ;
int V_45 = 0 ;
F_145 ( V_20 ) ;
if ( ( V_169 -> V_175 & V_44 ) &&
( V_169 -> V_176 || F_70 ( V_169 -> V_177 ) -> V_87 ||
V_169 -> V_178 > V_171 ) )
V_169 -> V_175 &= ~ V_44 ;
V_26 = 0 ;
V_173 = V_169 -> V_178 ;
do {
T_3 V_179 = F_146 ( V_173 , V_171 ) ;
V_65 = F_7 ( 1 ) ;
if ( ! V_65 )
goto V_180;
V_65 -> V_6 [ 0 ] = V_11 ;
F_132 ( V_20 , V_65 , V_179 , V_26 , V_169 -> V_175 ) ;
F_147 ( & V_65 -> V_168 , V_142 ) ;
V_174 ++ ;
V_173 -= V_179 ;
V_26 += V_179 ;
} while ( V_173 != 0 );
F_148 ( & V_20 -> V_181 , V_174 ) ;
V_169 -> V_182 = & V_183 ;
return V_45 ;
V_180:
while ( ! F_140 ( V_142 ) ) {
V_65 = F_141 ( V_142 -> V_167 , struct V_1 , V_168 ) ;
F_149 ( & V_65 -> V_168 ) ;
F_10 ( V_65 ) ;
}
F_58 ( V_20 ) ;
return - V_184 ;
}
static int F_150 ( struct V_55 * V_169 , struct V_97 * V_142 )
{
struct V_19 * V_20 ;
struct V_11 * * V_5 ;
struct V_1 * V_65 ;
struct V_97 * V_165 = & V_169 -> V_170 ;
int V_45 = 0 ;
V_65 = F_7 ( F_151 ( V_169 -> V_185 ,
V_169 -> V_178 ) ) ;
if ( ! V_65 ) {
while ( ! F_140 ( V_165 ) ) {
V_20 = F_144 ( V_165 -> V_167 ) ;
F_145 ( V_20 ) ;
F_58 ( V_20 ) ;
}
V_45 = - V_184 ;
goto V_33;
}
V_5 = V_65 -> V_6 ;
while ( ! F_140 ( V_165 ) ) {
V_20 = F_144 ( V_165 -> V_167 ) ;
F_145 ( V_20 ) ;
F_152 ( V_20 , & V_65 -> V_5 ) ;
* V_5 ++ = V_20 -> V_80 ;
}
V_20 = F_144 ( V_65 -> V_5 . V_167 ) ;
if ( ( V_169 -> V_175 & V_44 ) &&
( V_169 -> V_176 || F_70 ( V_169 -> V_177 ) -> V_87 ) )
V_169 -> V_175 &= ~ V_44 ;
F_132 ( V_20 , V_65 , V_169 -> V_178 , 0 , V_169 -> V_175 ) ;
F_147 ( & V_65 -> V_168 , V_142 ) ;
V_169 -> V_182 = & V_186 ;
V_33:
return V_45 ;
}
int F_153 ( struct V_55 * V_169 , struct V_97 * V_165 )
{
if ( V_169 -> V_172 < V_187 )
return F_143 ( V_169 , V_165 ) ;
return F_150 ( V_169 , V_165 ) ;
}
static int F_154 ( struct V_55 * V_169 )
{
F_155 ( V_165 ) ;
int V_45 ;
V_45 = F_153 ( V_169 , & V_165 ) ;
if ( V_45 == 0 )
V_45 = F_139 ( & V_165 , V_169 -> V_182 ,
V_169 -> V_175 ) ;
return V_45 ;
}
void F_156 ( struct V_55 * V_56 ,
struct V_22 * V_22 , int V_188 )
{
F_157 ( V_56 , V_22 , & V_189 ,
F_38 ( V_22 ) -> V_171 , V_188 ) ;
}
void F_158 ( struct V_55 * V_56 )
{
V_56 -> V_190 = & V_189 ;
V_56 -> V_172 = F_38 ( V_56 -> V_177 ) -> V_171 ;
}
static void F_64 ( struct V_55 * V_56 ,
struct V_22 * V_22 , int V_188 )
{
if ( ! F_159 ( V_56 , V_22 , V_188 ) )
F_156 ( V_56 , V_22 , V_188 ) ;
}
static void F_160 ( struct V_136 * V_137 , void * V_191 )
{
struct V_1 * V_65 = V_191 ;
F_119 ( L_5 ,
V_137 -> V_153 ,
V_65 -> V_20 -> V_82 -> V_83 -> V_84 -> V_154 -> V_155 ,
( long long )
F_128 ( V_65 -> V_20 -> V_82 -> V_83 -> V_84 ) ,
V_65 -> V_20 -> V_104 , ( long long ) F_134 ( V_65 -> V_20 ) ) ;
F_161 ( V_137 , V_65 ) ;
}
static void F_162 ( void * V_191 )
{
struct V_1 * V_65 = V_191 ;
struct V_19 * V_20 = V_65 -> V_20 ;
struct V_11 * V_11 = V_20 -> V_80 ;
int V_109 = V_65 -> V_137 . V_157 ;
if ( V_109 < 0 ) {
F_28 ( V_11 ) ;
F_14 ( V_20 -> V_82 , V_109 ) ;
F_119 ( L_6 , V_109 ) ;
goto V_33;
}
if ( F_101 ( V_65 ) ) {
struct V_22 * V_22 = V_11 -> V_23 -> V_24 ;
F_22 ( & V_22 -> V_25 ) ;
if ( F_56 ( V_96 , & V_20 -> V_58 ) ) {
} else if ( ! F_163 ( V_95 , & V_20 -> V_58 ) ) {
memcpy ( & V_20 -> V_192 , & V_65 -> V_91 , sizeof( V_20 -> V_192 ) ) ;
F_119 ( L_7 ) ;
} else if ( memcmp ( & V_20 -> V_192 , & V_65 -> V_91 , sizeof( V_20 -> V_192 ) ) ) {
F_16 ( V_96 , & V_20 -> V_58 ) ;
F_88 ( V_95 , & V_20 -> V_58 ) ;
F_119 ( L_8 ) ;
}
F_23 ( & V_22 -> V_25 ) ;
} else
F_119 ( L_9 ) ;
V_33:
if ( F_164 ( & V_20 -> V_181 ) )
F_122 ( V_20 , V_65 ) ;
F_11 ( V_191 ) ;
}
void F_165 ( struct V_136 * V_137 , void * V_191 )
{
struct V_1 * V_65 = V_191 ;
if ( F_166 ( F_38 ( V_65 -> V_22 ) ,
& V_65 -> args . V_193 ,
& V_65 -> V_142 . V_194 , 1 , V_137 ) )
return;
F_167 ( V_137 ) ;
}
static void F_168 ( struct V_136 * V_137 , void * V_191 )
{
struct V_1 * V_65 = V_191 ;
F_161 ( V_137 , V_65 ) ;
}
static void F_169 ( void * V_191 )
{
struct V_1 * V_65 = V_191 ;
int V_109 = V_65 -> V_137 . V_157 ;
while ( ! F_140 ( & V_65 -> V_5 ) ) {
struct V_19 * V_20 = F_144 ( V_65 -> V_5 . V_167 ) ;
struct V_11 * V_11 = V_20 -> V_80 ;
F_145 ( V_20 ) ;
F_119 ( L_10 ,
V_65 -> V_137 . V_153 ,
V_20 -> V_82 -> V_83 -> V_84 -> V_154 -> V_155 ,
( long long ) F_128 ( V_20 -> V_82 -> V_83 -> V_84 ) ,
V_20 -> V_104 ,
( long long ) F_134 ( V_20 ) ) ;
if ( V_109 < 0 ) {
F_28 ( V_11 ) ;
F_14 ( V_20 -> V_82 , V_109 ) ;
F_119 ( L_6 , V_109 ) ;
goto V_195;
}
if ( F_101 ( V_65 ) ) {
memcpy ( & V_20 -> V_192 , & V_65 -> V_91 , sizeof( V_20 -> V_192 ) ) ;
F_92 ( V_20 , V_65 -> V_13 ) ;
F_119 ( L_11 ) ;
goto V_167;
}
F_119 ( L_9 ) ;
V_195:
F_85 ( V_20 ) ;
V_167:
F_114 ( V_20 ) ;
F_42 ( V_11 ) ;
}
F_11 ( V_191 ) ;
}
void F_161 ( struct V_136 * V_137 , struct V_1 * V_65 )
{
struct V_196 * V_197 = & V_65 -> args ;
struct V_198 * V_199 = & V_65 -> V_142 ;
int V_109 ;
F_119 ( L_12 ,
V_137 -> V_153 , V_137 -> V_157 ) ;
V_109 = F_126 ( V_65 -> V_22 ) -> F_170 ( V_137 , V_65 ) ;
if ( V_109 != 0 )
return;
F_60 ( V_65 -> V_22 , V_200 , V_199 -> V_27 ) ;
#if F_171 ( V_201 ) || F_171 ( V_202 )
if ( V_199 -> V_91 -> V_92 < V_197 -> V_162 && V_137 -> V_157 >= 0 ) {
static unsigned long V_203 ;
if ( F_172 ( V_203 , V_204 ) ) {
F_119 ( L_13
L_14 ,
F_38 ( V_65 -> V_22 ) -> V_205 -> V_206 ,
V_199 -> V_91 -> V_92 , V_197 -> V_162 ) ;
V_203 = V_204 + 300 * V_207 ;
}
}
#endif
if ( V_137 -> V_157 >= 0 && V_199 -> V_27 < V_197 -> V_27 ) {
static unsigned long V_203 ;
F_27 ( V_65 -> V_22 , V_208 ) ;
if ( V_199 -> V_27 != 0 ) {
if ( V_199 -> V_91 -> V_92 != V_163 ) {
V_65 -> V_159 += V_199 -> V_27 ;
V_197 -> V_26 += V_199 -> V_27 ;
V_197 -> V_160 += V_199 -> V_27 ;
V_197 -> V_27 -= V_199 -> V_27 ;
} else {
V_197 -> V_162 = V_94 ;
}
F_173 ( V_137 ) ;
return;
}
if ( F_172 ( V_203 , V_204 ) ) {
F_174 ( V_209
L_15 ,
V_197 -> V_27 ) ;
V_203 = V_204 + 300 * V_207 ;
}
V_137 -> V_157 = - V_210 ;
}
return;
}
static int F_175 ( struct V_73 * V_74 , int V_211 )
{
int V_45 ;
if ( ! F_163 ( V_212 , & V_74 -> V_18 ) )
return 1 ;
if ( ! V_211 )
return 0 ;
V_45 = F_176 ( & V_74 -> V_18 ,
V_212 ,
V_69 ,
V_70 ) ;
return ( V_45 < 0 ) ? V_45 : 1 ;
}
void F_177 ( struct V_73 * V_74 )
{
F_88 ( V_212 , & V_74 -> V_18 ) ;
F_74 () ;
F_75 ( & V_74 -> V_18 , V_212 ) ;
}
void F_178 ( void * V_65 )
{
struct V_1 * V_12 = V_65 ;
F_12 ( V_12 -> V_13 ) ;
F_13 ( V_12 -> args . V_14 ) ;
F_4 ( V_12 ) ;
}
int F_179 ( struct V_1 * V_65 , struct V_131 * V_132 ,
const struct V_133 * V_134 ,
int V_127 )
{
struct V_136 * V_137 ;
int V_135 = F_124 ( V_127 ) ;
struct V_138 V_139 = {
. V_140 = & V_65 -> args ,
. V_141 = & V_65 -> V_142 ,
. V_143 = V_65 -> V_144 ,
} ;
struct V_145 V_146 = {
. V_137 = & V_65 -> V_137 ,
. V_147 = V_132 ,
. V_138 = & V_139 ,
. V_148 = V_134 ,
. V_149 = V_65 ,
. V_150 = V_151 ,
. V_18 = V_152 ,
. V_135 = V_135 ,
} ;
F_126 ( V_65 -> V_22 ) -> F_180 ( V_65 , & V_139 ) ;
F_119 ( L_16 , V_65 -> V_137 . V_153 ) ;
V_137 = F_129 ( & V_146 ) ;
if ( F_54 ( V_137 ) )
return F_53 ( V_137 ) ;
if ( V_127 & V_156 )
F_130 ( V_137 ) ;
F_131 ( V_137 ) ;
return 0 ;
}
void F_181 ( struct V_1 * V_65 ,
struct V_97 * V_165 ,
struct V_85 * V_13 )
{
struct V_19 * V_213 = F_144 ( V_165 -> V_167 ) ;
struct V_22 * V_22 = V_213 -> V_82 -> V_83 -> V_84 ;
F_182 ( V_165 , & V_65 -> V_5 ) ;
V_65 -> V_22 = V_22 ;
V_65 -> V_144 = V_213 -> V_82 -> V_144 ;
V_65 -> V_13 = V_13 ;
V_65 -> V_214 = & V_215 ;
V_65 -> args . V_158 = F_133 ( V_65 -> V_22 ) ;
V_65 -> args . V_26 = 0 ;
V_65 -> args . V_27 = 0 ;
V_65 -> args . V_14 = F_135 ( V_213 -> V_82 ) ;
V_65 -> V_142 . V_27 = 0 ;
V_65 -> V_142 . V_164 = & V_65 -> V_164 ;
V_65 -> V_142 . V_91 = & V_65 -> V_91 ;
F_136 ( & V_65 -> V_164 ) ;
}
void F_183 ( struct V_97 * V_216 ,
struct V_85 * V_13 )
{
struct V_19 * V_20 ;
while ( ! F_140 ( V_216 ) ) {
V_20 = F_144 ( V_216 -> V_167 ) ;
F_145 ( V_20 ) ;
F_92 ( V_20 , V_13 ) ;
F_99 ( V_20 -> V_80 , V_88 ) ;
F_100 ( V_20 -> V_80 -> V_23 -> V_50 ,
V_89 ) ;
F_114 ( V_20 ) ;
}
}
static int
F_184 ( struct V_22 * V_22 , struct V_97 * V_165 , int V_127 )
{
struct V_1 * V_65 ;
V_65 = F_1 () ;
if ( ! V_65 )
goto V_180;
F_181 ( V_65 , V_165 , NULL ) ;
return F_179 ( V_65 , F_138 ( V_22 ) , V_65 -> V_214 , V_127 ) ;
V_180:
F_183 ( V_165 , NULL ) ;
F_177 ( F_70 ( V_22 ) ) ;
return - V_184 ;
}
static void F_185 ( struct V_136 * V_137 , void * V_191 )
{
struct V_1 * V_65 = V_191 ;
F_119 ( L_17 ,
V_137 -> V_153 , V_137 -> V_157 ) ;
F_126 ( V_65 -> V_22 ) -> F_186 ( V_137 , V_65 ) ;
}
void F_187 ( struct V_1 * V_65 )
{
struct V_19 * V_20 ;
int V_109 = V_65 -> V_137 . V_157 ;
while ( ! F_140 ( & V_65 -> V_5 ) ) {
V_20 = F_144 ( V_65 -> V_5 . V_167 ) ;
F_145 ( V_20 ) ;
F_97 ( V_20 ) ;
F_119 ( L_18 ,
V_20 -> V_82 -> V_83 -> V_217 -> V_155 ,
( long long ) F_128 ( V_20 -> V_82 -> V_83 -> V_84 ) ,
V_20 -> V_104 ,
( long long ) F_134 ( V_20 ) ) ;
if ( V_109 < 0 ) {
F_14 ( V_20 -> V_82 , V_109 ) ;
F_85 ( V_20 ) ;
F_119 ( L_6 , V_109 ) ;
goto V_167;
}
if ( ! memcmp ( V_20 -> V_192 . V_218 , V_65 -> V_91 . V_218 , sizeof( V_65 -> V_91 . V_218 ) ) ) {
F_85 ( V_20 ) ;
F_119 ( L_9 ) ;
goto V_167;
}
F_119 ( L_19 ) ;
F_90 ( V_20 ) ;
V_167:
F_114 ( V_20 ) ;
}
}
static void F_188 ( void * V_191 )
{
struct V_1 * V_65 = V_191 ;
F_187 ( V_65 ) ;
F_177 ( F_70 ( V_65 -> V_22 ) ) ;
F_178 ( V_191 ) ;
}
int F_189 ( struct V_22 * V_22 , int V_127 )
{
F_155 ( V_165 ) ;
int V_211 = V_127 & V_156 ;
int V_142 ;
V_142 = F_175 ( F_70 ( V_22 ) , V_211 ) ;
if ( V_142 <= 0 )
goto V_219;
V_142 = F_105 ( V_22 , & V_165 , 0 , 0 ) ;
if ( V_142 ) {
int error ;
error = F_190 ( V_22 , & V_165 , V_127 ) ;
if ( error == V_220 )
error = F_184 ( V_22 , & V_165 , V_127 ) ;
if ( error < 0 )
return error ;
if ( ! V_211 )
goto V_219;
error = F_191 ( & F_70 ( V_22 ) -> V_18 ,
V_212 ,
V_69 ,
V_70 ) ;
if ( error < 0 )
return error ;
} else
F_177 ( F_70 ( V_22 ) ) ;
return V_142 ;
V_219:
F_96 ( V_22 , V_90 ) ;
return V_142 ;
}
static int F_192 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
struct V_73 * V_74 = F_70 ( V_22 ) ;
int V_18 = V_156 ;
int V_45 = 0 ;
if ( ! V_74 -> V_87 )
return V_45 ;
if ( V_37 -> V_62 == V_63 ) {
if ( V_74 -> V_87 <= ( V_74 -> V_10 >> 1 ) )
goto V_219;
V_18 = 0 ;
}
V_45 = F_189 ( V_22 , V_18 ) ;
if ( V_45 >= 0 ) {
if ( V_37 -> V_62 == V_63 ) {
if ( V_45 < V_37 -> V_221 )
V_37 -> V_221 -= V_45 ;
else
V_37 -> V_221 = 0 ;
}
return 0 ;
}
V_219:
F_96 ( V_22 , V_90 ) ;
return V_45 ;
}
static int F_192 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
return 0 ;
}
int F_193 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
int V_45 ;
V_45 = F_192 ( V_22 , V_37 ) ;
if ( V_45 >= 0 && F_56 ( V_222 , & F_70 ( V_22 ) -> V_18 ) ) {
int V_109 ;
bool V_223 = true ;
if ( V_37 -> V_62 == V_63 )
V_223 = false ;
V_109 = F_194 ( V_22 , V_223 ) ;
if ( V_109 < 0 )
return V_109 ;
}
return V_45 ;
}
int F_195 ( struct V_22 * V_22 )
{
struct V_36 V_37 = {
. V_62 = V_224 ,
. V_221 = V_225 ,
. V_226 = 0 ,
. V_227 = V_228 ,
} ;
return F_196 ( V_22 , & V_37 ) ;
}
int F_197 ( struct V_22 * V_22 , struct V_11 * V_11 )
{
struct V_19 * V_20 ;
int V_45 = 0 ;
F_55 ( ! F_198 ( V_11 ) ) ;
for (; ; ) {
F_199 ( V_11 ) ;
V_20 = F_21 ( V_11 ) ;
if ( V_20 == NULL )
break;
if ( F_78 ( V_20 ) ) {
F_85 ( V_20 ) ;
F_200 ( V_11 , V_187 ) ;
F_201 ( V_20 ) ;
break;
}
V_45 = F_49 ( V_20 ) ;
F_50 ( V_20 ) ;
if ( V_45 < 0 )
break;
}
return V_45 ;
}
int F_110 ( struct V_22 * V_22 , struct V_11 * V_11 )
{
T_1 V_226 = F_120 ( V_11 ) ;
T_1 V_227 = V_226 + ( T_1 ) ( V_187 - 1 ) ;
struct V_36 V_37 = {
. V_62 = V_224 ,
. V_221 = 0 ,
. V_226 = V_226 ,
. V_227 = V_227 ,
} ;
int V_45 ;
for (; ; ) {
F_199 ( V_11 ) ;
if ( F_202 ( V_11 ) ) {
V_45 = F_63 ( V_11 , & V_37 ) ;
if ( V_45 < 0 )
goto V_229;
continue;
}
if ( ! F_18 ( V_11 ) )
break;
V_45 = F_189 ( V_22 , V_156 ) ;
if ( V_45 < 0 )
goto V_229;
}
return 0 ;
V_229:
return V_45 ;
}
int F_203 ( struct V_66 * V_23 , struct V_11 * V_230 ,
struct V_11 * V_11 , enum V_231 V_232 )
{
if ( F_18 ( V_11 ) )
return - V_233 ;
F_204 ( V_11 , V_234 ) ;
return F_205 ( V_23 , V_230 , V_11 , V_232 ) ;
}
int T_4 F_206 ( void )
{
V_235 = F_207 ( L_20 ,
sizeof( struct V_1 ) ,
0 , V_236 ,
NULL ) ;
if ( V_235 == NULL )
return - V_184 ;
V_9 = F_208 ( V_237 ,
V_235 ) ;
if ( V_9 == NULL )
return - V_184 ;
V_3 = F_208 ( V_238 ,
V_235 ) ;
if ( V_3 == NULL )
return - V_184 ;
V_239 = ( 16 * F_209 ( V_240 ) ) << ( V_241 - 10 ) ;
if ( V_239 > 256 * 1024 )
V_239 = 256 * 1024 ;
return 0 ;
}
void F_210 ( void )
{
F_211 ( V_3 ) ;
F_211 ( V_9 ) ;
F_212 ( V_235 ) ;
}
