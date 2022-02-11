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
return F_6 ( ( V_11 V_12 ) V_7 << 16 | V_10 ,
( V_11 V_12 ) V_8 , ( V_11 V_12 ) V_9 ,
V_13 . V_14 ) & ( V_15 - 1 ) ;
}
static unsigned int F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_18 ;
V_18 = F_8 ( V_17 , struct V_18 , V_17 ) ;
return F_5 ( V_18 -> V_7 , V_18 -> V_8 , V_18 -> V_9 , V_18 -> V_19 ) ;
}
static bool F_9 ( struct V_16 * V_17 , void * V_20 )
{
struct V_18 * V_21 ;
struct V_22 * V_23 = V_20 ;
V_21 = F_8 ( V_17 , struct V_18 , V_17 ) ;
return V_21 -> V_7 == V_23 -> V_24 -> V_7 &&
V_21 -> V_8 == V_23 -> V_24 -> V_8 &&
V_21 -> V_9 == V_23 -> V_24 -> V_9 &&
V_21 -> V_19 == V_23 -> V_24 -> V_19 &&
V_21 -> V_25 == V_23 -> V_25 ;
}
static void F_10 ( struct V_16 * V_17 , void * V_20 )
{
struct V_18 * V_21 = F_8 ( V_17 , struct V_18 , V_17 ) ;
struct V_26 * V_4 = F_8 ( V_17 -> V_3 , struct V_26 ,
V_5 ) ;
struct V_3 * V_3 = F_8 ( V_4 , struct V_3 , V_4 ) ;
struct V_22 * V_23 = V_20 ;
V_21 -> V_19 = V_23 -> V_24 -> V_19 ;
V_21 -> V_7 = V_23 -> V_24 -> V_7 ;
V_21 -> V_27 = F_1 ( V_23 -> V_24 -> V_1 ) ;
V_21 -> V_8 = V_23 -> V_24 -> V_8 ;
V_21 -> V_9 = V_23 -> V_24 -> V_9 ;
V_21 -> V_25 = V_23 -> V_25 ;
V_21 -> V_28 = V_29 ?
F_11 ( V_3 -> V_4 . V_30 , V_23 -> V_24 -> V_8 , 1 ) : NULL ;
}
static T_4 void F_12 ( struct V_16 * V_17 )
{
struct V_18 * V_21 ;
V_21 = F_8 ( V_17 , struct V_18 , V_17 ) ;
if ( V_21 -> V_28 )
F_13 ( V_21 -> V_28 ) ;
}
static T_4 void F_14 ( struct V_18 * V_18 )
{
F_15 ( & V_18 -> V_17 , & V_13 ) ;
}
static void F_16 ( struct V_18 * V_18 )
{
F_17 ( & V_18 -> V_17 , & V_13 ) ;
}
static void F_18 ( struct V_3 * V_3 )
{
int V_31 ;
V_31 = F_19 ( & V_3 -> V_4 . V_5 , & V_13 , false ) ;
if ( V_31 )
F_20 ( V_3 , V_32 , V_31 ) ;
}
static void F_21 ( unsigned long V_23 )
{
struct V_18 * V_21 ;
struct V_3 * V_3 ;
V_21 = F_8 ( (struct V_16 * ) V_23 , struct V_18 , V_17 ) ;
V_3 = F_8 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_22 ( & V_21 -> V_17 . V_33 ) ;
if ( V_21 -> V_17 . V_34 & V_35 )
goto V_36;
F_16 ( V_21 ) ;
F_23 ( V_3 , V_37 ) ;
F_23 ( V_3 , V_32 ) ;
if ( ( V_21 -> V_17 . V_34 & V_38 ) && V_21 -> V_17 . V_39 != NULL ) {
struct V_40 * V_41 = V_21 -> V_17 . V_39 ;
const struct V_42 * V_24 ;
int V_43 ;
F_24 () ;
V_41 -> V_44 = F_25 ( V_3 , V_21 -> V_45 ) ;
if ( ! V_41 -> V_44 )
goto V_46;
V_24 = F_26 ( V_41 ) ;
V_43 = F_27 ( V_41 , V_24 -> V_9 , V_24 -> V_8 ,
V_24 -> V_1 , V_41 -> V_44 ) ;
if ( V_43 )
goto V_46;
if ( V_21 -> V_25 == V_47 ||
( V_21 -> V_25 == V_48 &&
F_28 ( V_41 ) -> V_49 != V_50 ) )
goto V_46;
F_29 ( V_41 , V_51 , V_52 , 0 ) ;
V_46:
F_30 () ;
}
V_36:
F_31 ( & V_21 -> V_17 . V_33 ) ;
F_14 ( V_21 ) ;
}
static inline struct V_18 * F_32 ( struct V_3 * V_3 , struct V_42 * V_24 , V_12 V_25 )
{
struct V_16 * V_17 ;
struct V_22 V_23 ;
unsigned int V_53 ;
V_23 . V_24 = V_24 ;
V_23 . V_25 = V_25 ;
F_33 ( & V_13 . V_33 ) ;
V_53 = F_5 ( V_24 -> V_7 , V_24 -> V_8 , V_24 -> V_9 , V_24 -> V_19 ) ;
V_17 = F_34 ( & V_3 -> V_4 . V_5 , & V_13 , & V_23 , V_53 ) ;
if ( F_35 ( V_17 ) ) {
F_36 ( V_17 , F_37 () ) ;
return NULL ;
}
return F_8 ( V_17 , struct V_18 , V_17 ) ;
}
static inline int F_38 ( struct V_18 * V_21 )
{
struct V_54 * V_28 = V_21 -> V_28 ;
unsigned int V_55 = V_29 ;
unsigned int V_56 , V_57 ;
int V_58 ;
if ( ! V_28 || ! V_55 )
return 0 ;
V_56 = V_21 -> V_59 ;
V_57 = F_39 ( & V_28 -> V_59 ) ;
V_21 -> V_59 = V_57 ;
V_58 = V_21 -> V_17 . V_39 && ( V_57 - V_56 ) > V_55 ;
if ( V_58 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_23 ( V_3 , V_32 ) ;
}
return V_58 ;
}
static int F_40 ( struct V_18 * V_21 )
{
struct V_40 * V_60 ;
unsigned int V_61 = 0 ;
if ( ! F_41 ( & V_21 -> V_17 . V_62 , V_63 + V_21 -> V_17 . V_3 -> V_64 ) ) {
F_42 ( & V_21 -> V_17 . V_65 ) ;
return - V_66 ;
}
V_60 = V_21 -> V_17 . V_39 ;
do {
struct V_40 * V_67 = V_60 -> V_68 ;
V_61 += V_60 -> V_69 ;
F_43 ( V_60 ) ;
V_60 = V_67 ;
} while ( V_60 );
F_44 ( & V_21 -> V_17 , V_61 ) ;
V_21 -> V_17 . V_34 = 0 ;
V_21 -> V_17 . V_70 = 0 ;
V_21 -> V_17 . V_71 = 0 ;
V_21 -> V_17 . V_39 = NULL ;
V_21 -> V_17 . V_72 = NULL ;
V_21 -> V_45 = 0 ;
V_21 -> V_27 = 0 ;
return 0 ;
}
static int F_45 ( struct V_18 * V_21 , struct V_40 * V_73 )
{
struct V_40 * V_74 , * V_68 ;
struct V_75 * V_44 ;
int V_76 , V_77 ;
int V_78 , V_57 ;
int V_43 = - V_79 ;
T_1 V_27 ;
if ( V_21 -> V_17 . V_34 & V_35 )
goto V_43;
if ( ! ( F_46 ( V_73 ) -> V_76 & V_80 ) &&
F_47 ( F_38 ( V_21 ) ) &&
F_47 ( V_43 = F_40 ( V_21 ) ) ) {
F_16 ( V_21 ) ;
goto V_43;
}
V_27 = F_1 ( F_26 ( V_73 ) -> V_1 ) ;
V_77 = F_48 ( F_26 ( V_73 ) -> V_81 ) ;
V_76 = V_77 & ~ V_82 ;
V_77 &= V_82 ;
V_77 <<= 3 ;
V_78 = F_49 ( V_73 ) ;
V_57 = V_77 + V_73 -> V_70 - V_78 ;
V_43 = - V_83 ;
if ( ( V_76 & V_84 ) == 0 ) {
if ( V_57 < V_21 -> V_17 . V_70 ||
( ( V_21 -> V_17 . V_34 & V_85 ) && V_57 != V_21 -> V_17 . V_70 ) )
goto V_43;
V_21 -> V_17 . V_34 |= V_85 ;
V_21 -> V_17 . V_70 = V_57 ;
} else {
if ( V_57 & 7 ) {
V_57 &= ~ 7 ;
if ( V_73 -> V_86 != V_87 )
V_73 -> V_86 = V_88 ;
}
if ( V_57 > V_21 -> V_17 . V_70 ) {
if ( V_21 -> V_17 . V_34 & V_85 )
goto V_43;
V_21 -> V_17 . V_70 = V_57 ;
}
}
if ( V_57 == V_77 )
goto V_43;
V_43 = - V_89 ;
if ( F_50 ( V_73 , V_78 ) == NULL )
goto V_43;
V_43 = F_51 ( V_73 , V_57 - V_77 ) ;
if ( V_43 )
goto V_43;
V_74 = V_21 -> V_17 . V_72 ;
if ( ! V_74 || F_52 ( V_74 ) -> V_77 < V_77 ) {
V_68 = NULL ;
goto V_90;
}
V_74 = NULL ;
for ( V_68 = V_21 -> V_17 . V_39 ; V_68 != NULL ; V_68 = V_68 -> V_68 ) {
if ( F_52 ( V_68 ) -> V_77 >= V_77 )
break;
V_74 = V_68 ;
}
V_90:
if ( V_74 ) {
int V_91 = ( F_52 ( V_74 ) -> V_77 + V_74 -> V_70 ) - V_77 ;
if ( V_91 > 0 ) {
V_77 += V_91 ;
V_43 = - V_83 ;
if ( V_57 <= V_77 )
goto V_43;
V_43 = - V_89 ;
if ( ! F_50 ( V_73 , V_91 ) )
goto V_43;
if ( V_73 -> V_86 != V_87 )
V_73 -> V_86 = V_88 ;
}
}
V_43 = - V_89 ;
while ( V_68 && F_52 ( V_68 ) -> V_77 < V_57 ) {
int V_91 = V_57 - F_52 ( V_68 ) -> V_77 ;
if ( V_91 < V_68 -> V_70 ) {
if ( ! F_50 ( V_68 , V_91 ) )
goto V_43;
F_52 ( V_68 ) -> V_77 += V_91 ;
V_21 -> V_17 . V_71 -= V_91 ;
if ( V_68 -> V_86 != V_87 )
V_68 -> V_86 = V_88 ;
break;
} else {
struct V_40 * V_92 = V_68 ;
V_68 = V_68 -> V_68 ;
if ( V_74 )
V_74 -> V_68 = V_68 ;
else
V_21 -> V_17 . V_39 = V_68 ;
V_21 -> V_17 . V_71 -= V_92 -> V_70 ;
F_44 ( & V_21 -> V_17 , V_92 -> V_69 ) ;
F_43 ( V_92 ) ;
}
}
F_52 ( V_73 ) -> V_77 = V_77 ;
V_73 -> V_68 = V_68 ;
if ( ! V_68 )
V_21 -> V_17 . V_72 = V_73 ;
if ( V_74 )
V_74 -> V_68 = V_73 ;
else
V_21 -> V_17 . V_39 = V_73 ;
V_44 = V_73 -> V_44 ;
if ( V_44 ) {
V_21 -> V_45 = V_44 -> V_93 ;
V_73 -> V_44 = NULL ;
}
V_21 -> V_17 . V_94 = V_73 -> V_95 ;
V_21 -> V_17 . V_71 += V_73 -> V_70 ;
V_21 -> V_27 |= V_27 ;
F_53 ( & V_21 -> V_17 , V_73 -> V_69 ) ;
if ( V_77 == 0 )
V_21 -> V_17 . V_34 |= V_38 ;
if ( F_26 ( V_73 ) -> V_81 & F_54 ( V_96 ) &&
V_73 -> V_70 + V_78 > V_21 -> V_17 . V_97 )
V_21 -> V_17 . V_97 = V_73 -> V_70 + V_78 ;
if ( V_21 -> V_17 . V_34 == ( V_38 | V_85 ) &&
V_21 -> V_17 . V_71 == V_21 -> V_17 . V_70 ) {
unsigned long V_98 = V_73 -> V_99 ;
V_73 -> V_99 = 0UL ;
V_43 = F_55 ( V_21 , V_74 , V_44 ) ;
V_73 -> V_99 = V_98 ;
return V_43 ;
}
F_56 ( V_73 ) ;
F_57 ( & V_21 -> V_17 ) ;
return - V_100 ;
V_43:
F_43 ( V_73 ) ;
return V_43 ;
}
static int F_55 ( struct V_18 * V_21 , struct V_40 * V_74 ,
struct V_75 * V_44 )
{
struct V_3 * V_3 = F_8 ( V_21 -> V_17 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_42 * V_24 ;
struct V_40 * V_60 , * V_41 = V_21 -> V_17 . V_39 ;
int V_70 ;
int V_101 ;
int V_43 ;
int V_61 ;
T_1 V_27 ;
F_16 ( V_21 ) ;
V_27 = V_102 [ V_21 -> V_27 ] ;
if ( F_47 ( V_27 == 0xff ) ) {
V_43 = - V_83 ;
goto V_103;
}
if ( V_74 ) {
V_41 = V_74 -> V_68 ;
V_60 = F_58 ( V_41 , V_104 ) ;
if ( ! V_60 )
goto V_105;
V_60 -> V_68 = V_41 -> V_68 ;
if ( ! V_60 -> V_68 )
V_21 -> V_17 . V_72 = V_60 ;
V_74 -> V_68 = V_60 ;
F_59 ( V_41 , V_21 -> V_17 . V_39 ) ;
V_41 -> V_68 = V_21 -> V_17 . V_39 -> V_68 ;
F_60 ( V_21 -> V_17 . V_39 ) ;
V_21 -> V_17 . V_39 = V_41 ;
}
F_61 ( V_41 == NULL ) ;
F_61 ( F_52 ( V_41 ) -> V_77 != 0 ) ;
V_101 = F_49 ( V_41 ) ;
V_70 = V_101 + V_21 -> V_17 . V_70 ;
V_43 = - V_106 ;
if ( V_70 > 65535 )
goto V_107;
if ( F_62 ( V_41 , V_104 ) )
goto V_105;
if ( F_63 ( V_41 ) ) {
struct V_40 * V_108 ;
int V_91 , V_109 = 0 ;
if ( ( V_108 = F_64 ( 0 , V_104 ) ) == NULL )
goto V_105;
V_108 -> V_68 = V_41 -> V_68 ;
V_41 -> V_68 = V_108 ;
F_65 ( V_108 ) -> V_110 = F_65 ( V_41 ) -> V_110 ;
F_66 ( V_41 ) ;
for ( V_91 = 0 ; V_91 < F_65 ( V_41 ) -> V_111 ; V_91 ++ )
V_109 += F_67 ( & F_65 ( V_41 ) -> V_5 [ V_91 ] ) ;
V_108 -> V_70 = V_108 -> V_112 = V_41 -> V_112 - V_109 ;
V_41 -> V_112 -= V_108 -> V_70 ;
V_41 -> V_70 -= V_108 -> V_70 ;
V_108 -> V_113 = 0 ;
V_108 -> V_86 = V_41 -> V_86 ;
F_53 ( & V_21 -> V_17 , V_108 -> V_69 ) ;
}
F_68 ( V_41 , V_41 -> V_114 - F_69 ( V_41 ) ) ;
V_61 = V_41 -> V_69 ;
for ( V_60 = V_41 -> V_68 ; V_60 ; ) {
bool V_115 ;
int V_116 ;
struct V_40 * V_68 = V_60 -> V_68 ;
V_61 += V_60 -> V_69 ;
if ( V_41 -> V_86 != V_60 -> V_86 )
V_41 -> V_86 = V_88 ;
else if ( V_41 -> V_86 == V_117 )
V_41 -> V_113 = F_70 ( V_41 -> V_113 , V_60 -> V_113 ) ;
if ( F_71 ( V_41 , V_60 , & V_115 , & V_116 ) ) {
F_72 ( V_60 , V_115 ) ;
} else {
if ( ! F_65 ( V_41 ) -> V_110 )
F_65 ( V_41 ) -> V_110 = V_60 ;
V_41 -> V_112 += V_60 -> V_70 ;
V_41 -> V_70 += V_60 -> V_70 ;
V_41 -> V_69 += V_60 -> V_69 ;
}
V_60 = V_68 ;
}
F_44 ( & V_21 -> V_17 , V_61 ) ;
V_41 -> V_68 = NULL ;
V_41 -> V_44 = V_44 ;
V_41 -> V_95 = V_21 -> V_17 . V_94 ;
F_46 ( V_41 ) -> V_118 = V_21 -> V_17 . V_97 ;
V_24 = F_26 ( V_41 ) ;
V_24 -> V_81 = V_21 -> V_17 . V_97 ? F_54 ( V_96 ) : 0 ;
V_24 -> V_119 = F_54 ( V_70 ) ;
V_24 -> V_1 |= V_27 ;
F_23 ( V_3 , V_120 ) ;
V_21 -> V_17 . V_39 = NULL ;
V_21 -> V_17 . V_72 = NULL ;
return 0 ;
V_105:
F_73 (KERN_ERR pr_fmt(L_1),
qp) ;
V_43 = - V_89 ;
goto V_103;
V_107:
F_74 ( L_2 , & V_21 -> V_8 ) ;
V_103:
F_23 ( V_3 , V_32 ) ;
return V_43 ;
}
int F_75 ( struct V_40 * V_73 , V_12 V_25 )
{
struct V_18 * V_21 ;
struct V_3 * V_3 ;
V_3 = V_73 -> V_44 ? F_76 ( V_73 -> V_44 ) : F_76 ( F_77 ( V_73 ) -> V_44 ) ;
F_23 ( V_3 , V_121 ) ;
F_18 ( V_3 ) ;
if ( ( V_21 = F_32 ( V_3 , F_26 ( V_73 ) , V_25 ) ) != NULL ) {
int V_122 ;
F_22 ( & V_21 -> V_17 . V_33 ) ;
V_122 = F_45 ( V_21 , V_73 ) ;
F_31 ( & V_21 -> V_17 . V_33 ) ;
F_14 ( V_21 ) ;
return V_122 ;
}
F_23 ( V_3 , V_32 ) ;
F_43 ( V_73 ) ;
return - V_89 ;
}
struct V_40 * F_78 ( struct V_40 * V_73 , V_12 V_25 )
{
struct V_42 V_24 ;
V_12 V_70 ;
if ( V_73 -> V_19 != F_54 ( V_123 ) )
return V_73 ;
if ( ! F_79 ( V_73 , 0 , & V_24 , sizeof( V_24 ) ) )
return V_73 ;
if ( V_24 . V_78 < 5 || V_24 . V_124 != 4 )
return V_73 ;
V_70 = F_48 ( V_24 . V_119 ) ;
if ( V_73 -> V_70 < V_70 || V_70 < ( V_24 . V_78 * 4 ) )
return V_73 ;
if ( F_80 ( & V_24 ) ) {
V_73 = F_81 ( V_73 , V_104 ) ;
if ( V_73 ) {
if ( ! F_82 ( V_73 , V_24 . V_78 * 4 ) )
return V_73 ;
if ( F_51 ( V_73 , V_70 ) )
return V_73 ;
memset ( F_46 ( V_73 ) , 0 , sizeof( struct V_125 ) ) ;
if ( F_75 ( V_73 , V_25 ) )
return NULL ;
V_73 -> V_126 = 0 ;
}
}
return V_73 ;
}
static int T_5 F_83 ( struct V_3 * V_3 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
V_128 = V_131 ;
if ( ! F_84 ( V_3 , & V_132 ) ) {
V_128 = F_85 ( V_128 , sizeof( V_131 ) , V_133 ) ;
if ( V_128 == NULL )
goto V_134;
V_128 [ 0 ] . V_114 = & V_3 -> V_4 . V_5 . V_135 ;
V_128 [ 1 ] . V_114 = & V_3 -> V_4 . V_5 . V_136 ;
V_128 [ 2 ] . V_114 = & V_3 -> V_4 . V_5 . V_64 ;
if ( V_3 -> V_137 != & V_138 )
V_128 [ 0 ] . V_139 = NULL ;
}
V_130 = F_86 ( V_3 , L_3 , V_128 ) ;
if ( V_130 == NULL )
goto V_140;
V_3 -> V_4 . V_141 = V_130 ;
return 0 ;
V_140:
if ( ! F_84 ( V_3 , & V_132 ) )
F_87 ( V_128 ) ;
V_134:
return - V_89 ;
}
static void T_6 F_88 ( struct V_3 * V_3 )
{
struct V_127 * V_128 ;
V_128 = V_3 -> V_4 . V_141 -> V_142 ;
F_89 ( V_3 -> V_4 . V_141 ) ;
F_87 ( V_128 ) ;
}
static void F_90 ( void )
{
F_86 ( & V_132 , L_3 , V_143 ) ;
}
static inline int F_83 ( struct V_3 * V_3 )
{
return 0 ;
}
static inline void F_88 ( struct V_3 * V_3 )
{
}
static inline void F_90 ( void )
{
}
static int T_5 F_91 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_135 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_136 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_64 = V_144 ;
F_92 ( & V_3 -> V_4 . V_5 ) ;
return F_83 ( V_3 ) ;
}
static void T_6 F_93 ( struct V_3 * V_3 )
{
F_88 ( V_3 ) ;
F_94 ( & V_3 -> V_4 . V_5 , & V_13 ) ;
}
void T_7 F_95 ( void )
{
F_90 () ;
F_96 ( & V_145 ) ;
V_13 . V_146 = F_7 ;
V_13 . V_147 = F_10 ;
V_13 . V_148 = F_12 ;
V_13 . V_149 = NULL ;
V_13 . V_150 = sizeof( struct V_18 ) ;
V_13 . V_151 = F_9 ;
V_13 . V_152 = F_21 ;
V_13 . V_153 = 10 * 60 * V_154 ;
F_97 ( & V_13 ) ;
}
