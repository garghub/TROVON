static inline T_1 F_1 ( T_1 V_1 )
{
return 1 << ( V_1 & V_2 ) ;
}
int F_2 ( struct V_3 * V_3 )
{
return V_3 -> V_4 . V_5 . V_6 ;
}
int F_3 ( struct V_3 * V_3 )
{
return F_4 ( & V_3 -> V_4 . V_5 ) ;
}
static unsigned int F_5 ( T_2 V_7 , T_3 V_8 , T_3 V_9 , T_1 V_10 )
{
F_6 ( & V_11 . V_12 , sizeof( V_11 . V_12 ) ) ;
return F_7 ( ( V_13 V_14 ) V_7 << 16 | V_10 ,
( V_13 V_14 ) V_8 , ( V_13 V_14 ) V_9 ,
V_11 . V_12 ) & ( V_15 - 1 ) ;
}
static unsigned int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_18 ;
V_18 = F_9 ( V_17 , struct V_18 , V_17 ) ;
return F_5 ( V_18 -> V_7 , V_18 -> V_8 , V_18 -> V_9 , V_18 -> V_19 ) ;
}
static bool F_10 ( struct V_16 * V_17 , void * V_20 )
{
struct V_18 * V_21 ;
struct V_22 * V_23 = V_20 ;
V_21 = F_9 ( V_17 , struct V_18 , V_17 ) ;
return V_21 -> V_7 == V_23 -> V_24 -> V_7 &&
V_21 -> V_8 == V_23 -> V_24 -> V_8 &&
V_21 -> V_9 == V_23 -> V_24 -> V_9 &&
V_21 -> V_19 == V_23 -> V_24 -> V_19 &&
V_21 -> V_25 == V_23 -> V_25 ;
}
static void F_11 ( struct V_16 * V_17 , void * V_20 )
{
struct V_18 * V_21 = F_9 ( V_17 , struct V_18 , V_17 ) ;
struct V_26 * V_4 = F_9 ( V_17 -> V_3 , struct V_26 ,
V_5 ) ;
struct V_3 * V_3 = F_9 ( V_4 , struct V_3 , V_4 ) ;
struct V_22 * V_23 = V_20 ;
V_21 -> V_19 = V_23 -> V_24 -> V_19 ;
V_21 -> V_7 = V_23 -> V_24 -> V_7 ;
V_21 -> V_27 = F_1 ( V_23 -> V_24 -> V_1 ) ;
V_21 -> V_8 = V_23 -> V_24 -> V_8 ;
V_21 -> V_9 = V_23 -> V_24 -> V_9 ;
V_21 -> V_25 = V_23 -> V_25 ;
V_21 -> V_28 = V_29 ?
F_12 ( V_3 -> V_4 . V_30 , V_23 -> V_24 -> V_8 , 1 ) : NULL ;
}
static T_4 void F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_21 ;
V_21 = F_9 ( V_17 , struct V_18 , V_17 ) ;
if ( V_21 -> V_28 )
F_14 ( V_21 -> V_28 ) ;
}
static T_4 void F_15 ( struct V_18 * V_18 )
{
F_16 ( & V_18 -> V_17 , & V_11 ) ;
}
static void F_17 ( struct V_18 * V_18 )
{
F_18 ( & V_18 -> V_17 , & V_11 ) ;
}
static void F_19 ( struct V_3 * V_3 )
{
int V_31 ;
V_31 = F_20 ( & V_3 -> V_4 . V_5 , & V_11 , false ) ;
if ( V_31 )
F_21 ( V_3 , V_32 , V_31 ) ;
}
static void F_22 ( unsigned long V_23 )
{
struct V_18 * V_21 ;
struct V_3 * V_3 ;
V_21 = F_9 ( (struct V_16 * ) V_23 , struct V_18 , V_17 ) ;
V_3 = F_9 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_23 ( & V_21 -> V_17 . V_33 ) ;
if ( V_21 -> V_17 . V_34 & V_35 )
goto V_36;
F_17 ( V_21 ) ;
F_24 ( V_3 , V_37 ) ;
F_24 ( V_3 , V_32 ) ;
if ( ( V_21 -> V_17 . V_34 & V_38 ) && V_21 -> V_17 . V_39 != NULL ) {
struct V_40 * V_41 = V_21 -> V_17 . V_39 ;
const struct V_42 * V_24 ;
int V_43 ;
F_25 () ;
V_41 -> V_44 = F_26 ( V_3 , V_21 -> V_45 ) ;
if ( ! V_41 -> V_44 )
goto V_46;
V_24 = F_27 ( V_41 ) ;
V_43 = F_28 ( V_41 , V_24 -> V_9 , V_24 -> V_8 ,
V_24 -> V_1 , V_41 -> V_44 ) ;
if ( V_43 )
goto V_46;
if ( V_21 -> V_25 == V_47 ||
( ( V_21 -> V_25 >= V_48 ) &&
( V_21 -> V_25 <= V_49 ) &&
( F_29 ( V_41 ) -> V_50 != V_51 ) ) )
goto V_46;
F_30 ( V_41 , V_52 , V_53 , 0 ) ;
V_46:
F_31 () ;
}
V_36:
F_32 ( & V_21 -> V_17 . V_33 ) ;
F_15 ( V_21 ) ;
}
static inline struct V_18 * F_33 ( struct V_3 * V_3 , struct V_42 * V_24 , V_14 V_25 )
{
struct V_16 * V_17 ;
struct V_22 V_23 ;
unsigned int V_54 ;
V_23 . V_24 = V_24 ;
V_23 . V_25 = V_25 ;
F_34 ( & V_11 . V_33 ) ;
V_54 = F_5 ( V_24 -> V_7 , V_24 -> V_8 , V_24 -> V_9 , V_24 -> V_19 ) ;
V_17 = F_35 ( & V_3 -> V_4 . V_5 , & V_11 , & V_23 , V_54 ) ;
if ( F_36 ( V_17 ) ) {
F_37 ( V_17 , F_38 () ) ;
return NULL ;
}
return F_9 ( V_17 , struct V_18 , V_17 ) ;
}
static inline int F_39 ( struct V_18 * V_21 )
{
struct V_55 * V_28 = V_21 -> V_28 ;
unsigned int V_56 = V_29 ;
unsigned int V_57 , V_58 ;
int V_59 ;
if ( ! V_28 || ! V_56 )
return 0 ;
V_57 = V_21 -> V_60 ;
V_58 = F_40 ( & V_28 -> V_60 ) ;
V_21 -> V_60 = V_58 ;
V_59 = V_21 -> V_17 . V_39 && ( V_58 - V_57 ) > V_56 ;
if ( V_59 ) {
struct V_3 * V_3 ;
V_3 = F_9 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_24 ( V_3 , V_32 ) ;
}
return V_59 ;
}
static int F_41 ( struct V_18 * V_21 )
{
struct V_40 * V_61 ;
unsigned int V_62 = 0 ;
if ( ! F_42 ( & V_21 -> V_17 . V_63 , V_64 + V_21 -> V_17 . V_3 -> V_65 ) ) {
F_43 ( & V_21 -> V_17 . V_66 ) ;
return - V_67 ;
}
V_61 = V_21 -> V_17 . V_39 ;
do {
struct V_40 * V_68 = V_61 -> V_69 ;
V_62 += V_61 -> V_70 ;
F_44 ( V_61 ) ;
V_61 = V_68 ;
} while ( V_61 );
F_45 ( & V_21 -> V_17 , V_62 ) ;
V_21 -> V_17 . V_34 = 0 ;
V_21 -> V_17 . V_71 = 0 ;
V_21 -> V_17 . V_72 = 0 ;
V_21 -> V_17 . V_39 = NULL ;
V_21 -> V_17 . V_73 = NULL ;
V_21 -> V_45 = 0 ;
V_21 -> V_27 = 0 ;
return 0 ;
}
static int F_46 ( struct V_18 * V_21 , struct V_40 * V_74 )
{
struct V_40 * V_75 , * V_69 ;
struct V_76 * V_44 ;
int V_77 , V_78 ;
int V_79 , V_58 ;
int V_43 = - V_80 ;
T_1 V_27 ;
if ( V_21 -> V_17 . V_34 & V_35 )
goto V_43;
if ( ! ( F_47 ( V_74 ) -> V_77 & V_81 ) &&
F_48 ( F_39 ( V_21 ) ) &&
F_48 ( V_43 = F_41 ( V_21 ) ) ) {
F_17 ( V_21 ) ;
goto V_43;
}
V_27 = F_1 ( F_27 ( V_74 ) -> V_1 ) ;
V_78 = F_49 ( F_27 ( V_74 ) -> V_82 ) ;
V_77 = V_78 & ~ V_83 ;
V_78 &= V_83 ;
V_78 <<= 3 ;
V_79 = F_50 ( V_74 ) ;
V_58 = V_78 + V_74 -> V_71 - V_79 ;
V_43 = - V_84 ;
if ( ( V_77 & V_85 ) == 0 ) {
if ( V_58 < V_21 -> V_17 . V_71 ||
( ( V_21 -> V_17 . V_34 & V_86 ) && V_58 != V_21 -> V_17 . V_71 ) )
goto V_43;
V_21 -> V_17 . V_34 |= V_86 ;
V_21 -> V_17 . V_71 = V_58 ;
} else {
if ( V_58 & 7 ) {
V_58 &= ~ 7 ;
if ( V_74 -> V_87 != V_88 )
V_74 -> V_87 = V_89 ;
}
if ( V_58 > V_21 -> V_17 . V_71 ) {
if ( V_21 -> V_17 . V_34 & V_86 )
goto V_43;
V_21 -> V_17 . V_71 = V_58 ;
}
}
if ( V_58 == V_78 )
goto V_43;
V_43 = - V_90 ;
if ( F_51 ( V_74 , V_79 ) == NULL )
goto V_43;
V_43 = F_52 ( V_74 , V_58 - V_78 ) ;
if ( V_43 )
goto V_43;
V_75 = V_21 -> V_17 . V_73 ;
if ( ! V_75 || F_53 ( V_75 ) -> V_78 < V_78 ) {
V_69 = NULL ;
goto V_91;
}
V_75 = NULL ;
for ( V_69 = V_21 -> V_17 . V_39 ; V_69 != NULL ; V_69 = V_69 -> V_69 ) {
if ( F_53 ( V_69 ) -> V_78 >= V_78 )
break;
V_75 = V_69 ;
}
V_91:
if ( V_75 ) {
int V_92 = ( F_53 ( V_75 ) -> V_78 + V_75 -> V_71 ) - V_78 ;
if ( V_92 > 0 ) {
V_78 += V_92 ;
V_43 = - V_84 ;
if ( V_58 <= V_78 )
goto V_43;
V_43 = - V_90 ;
if ( ! F_51 ( V_74 , V_92 ) )
goto V_43;
if ( V_74 -> V_87 != V_88 )
V_74 -> V_87 = V_89 ;
}
}
V_43 = - V_90 ;
while ( V_69 && F_53 ( V_69 ) -> V_78 < V_58 ) {
int V_92 = V_58 - F_53 ( V_69 ) -> V_78 ;
if ( V_92 < V_69 -> V_71 ) {
if ( ! F_51 ( V_69 , V_92 ) )
goto V_43;
F_53 ( V_69 ) -> V_78 += V_92 ;
V_21 -> V_17 . V_72 -= V_92 ;
if ( V_69 -> V_87 != V_88 )
V_69 -> V_87 = V_89 ;
break;
} else {
struct V_40 * V_93 = V_69 ;
V_69 = V_69 -> V_69 ;
if ( V_75 )
V_75 -> V_69 = V_69 ;
else
V_21 -> V_17 . V_39 = V_69 ;
V_21 -> V_17 . V_72 -= V_93 -> V_71 ;
F_45 ( & V_21 -> V_17 , V_93 -> V_70 ) ;
F_44 ( V_93 ) ;
}
}
F_53 ( V_74 ) -> V_78 = V_78 ;
V_74 -> V_69 = V_69 ;
if ( ! V_69 )
V_21 -> V_17 . V_73 = V_74 ;
if ( V_75 )
V_75 -> V_69 = V_74 ;
else
V_21 -> V_17 . V_39 = V_74 ;
V_44 = V_74 -> V_44 ;
if ( V_44 ) {
V_21 -> V_45 = V_44 -> V_94 ;
V_74 -> V_44 = NULL ;
}
V_21 -> V_17 . V_95 = V_74 -> V_96 ;
V_21 -> V_17 . V_72 += V_74 -> V_71 ;
V_21 -> V_27 |= V_27 ;
F_54 ( & V_21 -> V_17 , V_74 -> V_70 ) ;
if ( V_78 == 0 )
V_21 -> V_17 . V_34 |= V_38 ;
if ( F_27 ( V_74 ) -> V_82 & F_55 ( V_97 ) &&
V_74 -> V_71 + V_79 > V_21 -> V_17 . V_98 )
V_21 -> V_17 . V_98 = V_74 -> V_71 + V_79 ;
if ( V_21 -> V_17 . V_34 == ( V_38 | V_86 ) &&
V_21 -> V_17 . V_72 == V_21 -> V_17 . V_71 ) {
unsigned long V_99 = V_74 -> V_100 ;
V_74 -> V_100 = 0UL ;
V_43 = F_56 ( V_21 , V_75 , V_44 ) ;
V_74 -> V_100 = V_99 ;
return V_43 ;
}
F_57 ( V_74 ) ;
F_58 ( & V_21 -> V_17 ) ;
return - V_101 ;
V_43:
F_44 ( V_74 ) ;
return V_43 ;
}
static int F_56 ( struct V_18 * V_21 , struct V_40 * V_75 ,
struct V_76 * V_44 )
{
struct V_3 * V_3 = F_9 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_42 * V_24 ;
struct V_40 * V_61 , * V_41 = V_21 -> V_17 . V_39 ;
int V_71 ;
int V_102 ;
int V_43 ;
int V_62 ;
T_1 V_27 ;
F_17 ( V_21 ) ;
V_27 = V_103 [ V_21 -> V_27 ] ;
if ( F_48 ( V_27 == 0xff ) ) {
V_43 = - V_84 ;
goto V_104;
}
if ( V_75 ) {
V_41 = V_75 -> V_69 ;
V_61 = F_59 ( V_41 , V_105 ) ;
if ( ! V_61 )
goto V_106;
V_61 -> V_69 = V_41 -> V_69 ;
if ( ! V_61 -> V_69 )
V_21 -> V_17 . V_73 = V_61 ;
V_75 -> V_69 = V_61 ;
F_60 ( V_41 , V_21 -> V_17 . V_39 ) ;
V_41 -> V_69 = V_21 -> V_17 . V_39 -> V_69 ;
F_61 ( V_21 -> V_17 . V_39 ) ;
V_21 -> V_17 . V_39 = V_41 ;
}
F_62 ( V_41 == NULL ) ;
F_62 ( F_53 ( V_41 ) -> V_78 != 0 ) ;
V_102 = F_50 ( V_41 ) ;
V_71 = V_102 + V_21 -> V_17 . V_71 ;
V_43 = - V_107 ;
if ( V_71 > 65535 )
goto V_108;
if ( F_63 ( V_41 , V_105 ) )
goto V_106;
if ( F_64 ( V_41 ) ) {
struct V_40 * V_109 ;
int V_92 , V_110 = 0 ;
if ( ( V_109 = F_65 ( 0 , V_105 ) ) == NULL )
goto V_106;
V_109 -> V_69 = V_41 -> V_69 ;
V_41 -> V_69 = V_109 ;
F_66 ( V_109 ) -> V_111 = F_66 ( V_41 ) -> V_111 ;
F_67 ( V_41 ) ;
for ( V_92 = 0 ; V_92 < F_66 ( V_41 ) -> V_112 ; V_92 ++ )
V_110 += F_68 ( & F_66 ( V_41 ) -> V_5 [ V_92 ] ) ;
V_109 -> V_71 = V_109 -> V_113 = V_41 -> V_113 - V_110 ;
V_41 -> V_113 -= V_109 -> V_71 ;
V_41 -> V_71 -= V_109 -> V_71 ;
V_109 -> V_114 = 0 ;
V_109 -> V_87 = V_41 -> V_87 ;
F_54 ( & V_21 -> V_17 , V_109 -> V_70 ) ;
}
F_69 ( V_41 , V_41 -> V_115 - F_70 ( V_41 ) ) ;
V_62 = V_41 -> V_70 ;
for ( V_61 = V_41 -> V_69 ; V_61 ; ) {
bool V_116 ;
int V_117 ;
struct V_40 * V_69 = V_61 -> V_69 ;
V_62 += V_61 -> V_70 ;
if ( V_41 -> V_87 != V_61 -> V_87 )
V_41 -> V_87 = V_89 ;
else if ( V_41 -> V_87 == V_118 )
V_41 -> V_114 = F_71 ( V_41 -> V_114 , V_61 -> V_114 ) ;
if ( F_72 ( V_41 , V_61 , & V_116 , & V_117 ) ) {
F_73 ( V_61 , V_116 ) ;
} else {
if ( ! F_66 ( V_41 ) -> V_111 )
F_66 ( V_41 ) -> V_111 = V_61 ;
V_41 -> V_113 += V_61 -> V_71 ;
V_41 -> V_71 += V_61 -> V_71 ;
V_41 -> V_70 += V_61 -> V_70 ;
}
V_61 = V_69 ;
}
F_45 ( & V_21 -> V_17 , V_62 ) ;
V_41 -> V_69 = NULL ;
V_41 -> V_44 = V_44 ;
V_41 -> V_96 = V_21 -> V_17 . V_95 ;
F_47 ( V_41 ) -> V_119 = V_21 -> V_17 . V_98 ;
V_24 = F_27 ( V_41 ) ;
V_24 -> V_82 = V_21 -> V_17 . V_98 ? F_55 ( V_97 ) : 0 ;
V_24 -> V_120 = F_55 ( V_71 ) ;
V_24 -> V_1 |= V_27 ;
F_24 ( V_3 , V_121 ) ;
V_21 -> V_17 . V_39 = NULL ;
V_21 -> V_17 . V_73 = NULL ;
return 0 ;
V_106:
F_74 (KERN_ERR pr_fmt(L_1),
qp) ;
V_43 = - V_90 ;
goto V_104;
V_108:
F_75 ( L_2 , & V_21 -> V_8 ) ;
V_104:
F_24 ( V_3 , V_32 ) ;
return V_43 ;
}
int F_76 ( struct V_40 * V_74 , V_14 V_25 )
{
struct V_18 * V_21 ;
struct V_3 * V_3 ;
V_3 = V_74 -> V_44 ? F_77 ( V_74 -> V_44 ) : F_77 ( F_78 ( V_74 ) -> V_44 ) ;
F_24 ( V_3 , V_122 ) ;
F_19 ( V_3 ) ;
if ( ( V_21 = F_33 ( V_3 , F_27 ( V_74 ) , V_25 ) ) != NULL ) {
int V_123 ;
F_23 ( & V_21 -> V_17 . V_33 ) ;
V_123 = F_46 ( V_21 , V_74 ) ;
F_32 ( & V_21 -> V_17 . V_33 ) ;
F_15 ( V_21 ) ;
return V_123 ;
}
F_24 ( V_3 , V_32 ) ;
F_44 ( V_74 ) ;
return - V_90 ;
}
struct V_40 * F_79 ( struct V_40 * V_74 , V_14 V_25 )
{
struct V_42 V_24 ;
V_14 V_71 ;
if ( V_74 -> V_19 != F_55 ( V_124 ) )
return V_74 ;
if ( ! F_80 ( V_74 , 0 , & V_24 , sizeof( V_24 ) ) )
return V_74 ;
if ( V_24 . V_79 < 5 || V_24 . V_125 != 4 )
return V_74 ;
V_71 = F_49 ( V_24 . V_120 ) ;
if ( V_74 -> V_71 < V_71 || V_71 < ( V_24 . V_79 * 4 ) )
return V_74 ;
if ( F_81 ( & V_24 ) ) {
V_74 = F_82 ( V_74 , V_105 ) ;
if ( V_74 ) {
if ( ! F_83 ( V_74 , V_24 . V_79 * 4 ) )
return V_74 ;
if ( F_52 ( V_74 , V_71 ) )
return V_74 ;
memset ( F_47 ( V_74 ) , 0 , sizeof( struct V_126 ) ) ;
if ( F_76 ( V_74 , V_25 ) )
return NULL ;
F_84 ( V_74 ) ;
}
}
return V_74 ;
}
static int T_5 F_85 ( struct V_3 * V_3 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
V_128 = V_131 ;
if ( ! F_86 ( V_3 , & V_132 ) ) {
V_128 = F_87 ( V_128 , sizeof( V_131 ) , V_133 ) ;
if ( V_128 == NULL )
goto V_134;
V_128 [ 0 ] . V_115 = & V_3 -> V_4 . V_5 . V_135 ;
V_128 [ 1 ] . V_115 = & V_3 -> V_4 . V_5 . V_136 ;
V_128 [ 2 ] . V_115 = & V_3 -> V_4 . V_5 . V_65 ;
if ( V_3 -> V_137 != & V_138 )
V_128 [ 0 ] . V_139 = NULL ;
}
V_130 = F_88 ( V_3 , L_3 , V_128 ) ;
if ( V_130 == NULL )
goto V_140;
V_3 -> V_4 . V_141 = V_130 ;
return 0 ;
V_140:
if ( ! F_86 ( V_3 , & V_132 ) )
F_89 ( V_128 ) ;
V_134:
return - V_90 ;
}
static void T_6 F_90 ( struct V_3 * V_3 )
{
struct V_127 * V_128 ;
V_128 = V_3 -> V_4 . V_141 -> V_142 ;
F_91 ( V_3 -> V_4 . V_141 ) ;
F_89 ( V_128 ) ;
}
static void F_92 ( void )
{
F_88 ( & V_132 , L_3 , V_143 ) ;
}
static inline int F_85 ( struct V_3 * V_3 )
{
return 0 ;
}
static inline void F_90 ( struct V_3 * V_3 )
{
}
static inline void F_92 ( void )
{
}
static int T_5 F_93 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_135 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_136 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_65 = V_144 ;
F_94 ( & V_3 -> V_4 . V_5 ) ;
return F_85 ( V_3 ) ;
}
static void T_6 F_95 ( struct V_3 * V_3 )
{
F_90 ( V_3 ) ;
F_96 ( & V_3 -> V_4 . V_5 , & V_11 ) ;
}
void T_7 F_97 ( void )
{
F_92 () ;
F_98 ( & V_145 ) ;
V_11 . V_146 = F_8 ;
V_11 . V_147 = F_11 ;
V_11 . V_148 = F_13 ;
V_11 . V_149 = NULL ;
V_11 . V_150 = sizeof( struct V_18 ) ;
V_11 . V_151 = F_10 ;
V_11 . V_152 = F_22 ;
V_11 . V_153 = 10 * 60 * V_154 ;
F_99 ( & V_11 ) ;
}
